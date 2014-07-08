//
// strand_service.hpp
// ~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2010 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//

#ifndef STREAMS_BOOST_ASIO_DETAIL_STRAND_SERVICE_HPP
#define STREAMS_BOOST_ASIO_DETAIL_STRAND_SERVICE_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <streams_boost/asio/detail/push_options.hpp>

#include <streams_boost/asio/detail/push_options.hpp>
#include <streams_boost/aligned_storage.hpp>
#include <streams_boost/assert.hpp>
#include <streams_boost/functional/hash.hpp>
#include <streams_boost/scoped_ptr.hpp>
#include <streams_boost/asio/detail/pop_options.hpp>

#include <streams_boost/asio/io_service.hpp>
#include <streams_boost/asio/detail/bind_handler.hpp>
#include <streams_boost/asio/detail/call_stack.hpp>
#include <streams_boost/asio/detail/handler_alloc_helpers.hpp>
#include <streams_boost/asio/detail/handler_invoke_helpers.hpp>
#include <streams_boost/asio/detail/mutex.hpp>
#include <streams_boost/asio/detail/noncopyable.hpp>
#include <streams_boost/asio/detail/service_base.hpp>

namespace streams_boost {
namespace asio {
namespace detail {

// Default service implementation for a strand.
class strand_service
  : public streams_boost::asio::detail::service_base<strand_service>
{
public:
  class handler_base;
  class invoke_current_handler;
  class post_next_waiter_on_exit;

  // The underlying implementation of a strand.
  class strand_impl
  {
  public:
    strand_impl()
      : current_handler_(0),
        first_waiter_(0),
        last_waiter_(0)
    {
    }

  private:
    // Only this service will have access to the internal values.
    friend class strand_service;
    friend class post_next_waiter_on_exit;
    friend class invoke_current_handler;

    // Mutex to protect access to internal data.
    streams_boost::asio::detail::mutex mutex_;

    // The handler that is ready to execute. If this pointer is non-null then it
    // indicates that a handler holds the lock.
    handler_base* current_handler_;

    // The start of the list of waiting handlers for the strand.
    handler_base* first_waiter_;
    
    // The end of the list of waiting handlers for the strand.
    handler_base* last_waiter_;

    // Storage for posted handlers.
    typedef streams_boost::aligned_storage<128> handler_storage_type;
#if defined(__BORLANDC__)
    streams_boost::aligned_storage<128> handler_storage_;
#else
    handler_storage_type handler_storage_;
#endif
  };

  friend class strand_impl;

  typedef strand_impl* implementation_type;

  // Base class for all handler types.
  class handler_base
  {
  public:
    typedef void (*invoke_func_type)(handler_base*,
        strand_service&, implementation_type&);
    typedef void (*destroy_func_type)(handler_base*);

    handler_base(invoke_func_type invoke_func, destroy_func_type destroy_func)
      : next_(0),
        invoke_func_(invoke_func),
        destroy_func_(destroy_func)
    {
    }

    void invoke(strand_service& service_impl, implementation_type& impl)
    {
      invoke_func_(this, service_impl, impl);
    }

    void destroy()
    {
      destroy_func_(this);
    }

  protected:
    ~handler_base()
    {
    }

  private:
    friend class strand_service;
    friend class strand_impl;
    friend class post_next_waiter_on_exit;
    handler_base* next_;
    invoke_func_type invoke_func_;
    destroy_func_type destroy_func_;
  };

  // Helper class to allow handlers to be dispatched.
  class invoke_current_handler
  {
  public:
    invoke_current_handler(strand_service& service_impl,
        const implementation_type& impl)
      : service_impl_(service_impl),
        impl_(impl)
    {
    }

    void operator()()
    {
      impl_->current_handler_->invoke(service_impl_, impl_);
    }

    friend void* asio_handler_allocate(std::size_t size,
        invoke_current_handler* this_handler)
    {
      return this_handler->do_handler_allocate(size);
    }

    friend void asio_handler_deallocate(void*, std::size_t,
        invoke_current_handler*)
    {
    }

    void* do_handler_allocate(std::size_t size)
    {
#if defined(__BORLANDC__)
      STREAMS_BOOST_ASSERT(size <= streams_boost::aligned_storage<128>::size);
#else
      STREAMS_BOOST_ASSERT(size <= strand_impl::handler_storage_type::size);
#endif
      (void)size;
      return impl_->handler_storage_.address();
    }

    // The asio_handler_invoke hook is not defined here since the default one
    // provides the correct behaviour, and including it here breaks MSVC 7.1
    // in some situations.

  private:
    strand_service& service_impl_;
    implementation_type impl_;
  };

  // Helper class to automatically enqueue next waiter on block exit.
  class post_next_waiter_on_exit
  {
  public:
    post_next_waiter_on_exit(strand_service& service_impl,
        implementation_type& impl)
      : service_impl_(service_impl),
        impl_(impl),
        cancelled_(false)
    {
    }

    ~post_next_waiter_on_exit()
    {
      if (!cancelled_)
      {
        streams_boost::asio::detail::mutex::scoped_lock lock(impl_->mutex_);
        impl_->current_handler_ = impl_->first_waiter_;
        if (impl_->current_handler_)
        {
          impl_->first_waiter_ = impl_->first_waiter_->next_;
          if (impl_->first_waiter_ == 0)
            impl_->last_waiter_ = 0;
          lock.unlock();
          service_impl_.get_io_service().post(
              invoke_current_handler(service_impl_, impl_));
        }
      }
    }

    void cancel()
    {
      cancelled_ = true;
    }

  private:
    strand_service& service_impl_;
    implementation_type& impl_;
    bool cancelled_;
  };

  // Class template for a waiter.
  template <typename Handler>
  class handler_wrapper
    : public handler_base
  {
  public:
    handler_wrapper(Handler handler)
      : handler_base(&handler_wrapper<Handler>::do_invoke,
          &handler_wrapper<Handler>::do_destroy),
        handler_(handler)
    {
    }

    static void do_invoke(handler_base* base,
        strand_service& service_impl, implementation_type& impl)
    {
      // Take ownership of the handler object.
      typedef handler_wrapper<Handler> this_type;
      this_type* h(static_cast<this_type*>(base));
      typedef handler_alloc_traits<Handler, this_type> alloc_traits;
      handler_ptr<alloc_traits> ptr(h->handler_, h);

      post_next_waiter_on_exit p1(service_impl, impl);

      // Make a copy of the handler so that the memory can be deallocated before
      // the upcall is made.
      Handler handler(h->handler_);

      // A handler object must still be valid when the next waiter is posted
      // since destroying the last handler might cause the strand object to be
      // destroyed. Therefore we create a second post_next_waiter_on_exit object
      // that will be destroyed before the handler object.
      p1.cancel();
      post_next_waiter_on_exit p2(service_impl, impl);

      // Free the memory associated with the handler.
      ptr.reset();

      // Indicate that this strand is executing on the current thread.
      call_stack<strand_impl>::context ctx(impl);

      // Make the upcall.
      streams_boost_asio_handler_invoke_helpers::invoke(handler, handler);
    }

    static void do_destroy(handler_base* base)
    {
      // Take ownership of the handler object.
      typedef handler_wrapper<Handler> this_type;
      this_type* h(static_cast<this_type*>(base));
      typedef handler_alloc_traits<Handler, this_type> alloc_traits;
      handler_ptr<alloc_traits> ptr(h->handler_, h);

      // A sub-object of the handler may be the true owner of the memory
      // associated with the handler. Consequently, a local copy of the handler
      // is required to ensure that any owning sub-object remains valid until
      // after we have deallocated the memory here.
      Handler handler(h->handler_);
      (void)handler;

      // Free the memory associated with the handler.
      ptr.reset();
    }

  private:
    Handler handler_;
  };

  // Construct a new strand service for the specified io_service.
  explicit strand_service(streams_boost::asio::io_service& io_service)
    : streams_boost::asio::detail::service_base<strand_service>(io_service),
      mutex_(),
      salt_(0)
  {
  }

  // Destroy all user-defined handler objects owned by the service.
  void shutdown_service()
  {
    // Construct a list of all handlers to be destroyed.
    streams_boost::asio::detail::mutex::scoped_lock lock(mutex_);
    handler_base* first_handler = 0;
    for (std::size_t i = 0; i < num_implementations; ++i)
    {
      if (strand_impl* impl = implementations_[i].get())
      {
        if (impl->current_handler_)
        {
          impl->current_handler_->next_ = first_handler;
          first_handler = impl->current_handler_;
          impl->current_handler_ = 0;
        }
        if (impl->first_waiter_)
        {
          impl->last_waiter_->next_ = first_handler;
          first_handler = impl->first_waiter_;
          impl->first_waiter_ = 0;
          impl->last_waiter_ = 0;
        }
      }
    }

    // Destroy all handlers without holding the lock.
    lock.unlock();
    while (first_handler)
    {
      handler_base* next = first_handler->next_;
      first_handler->destroy();
      first_handler = next;
    }
  }

  // Construct a new strand implementation.
  void construct(implementation_type& impl)
  {
    std::size_t index = streams_boost::hash_value(&impl);
    streams_boost::hash_combine(index, salt_++);
    index = index % num_implementations;

    streams_boost::asio::detail::mutex::scoped_lock lock(mutex_);

    if (!implementations_[index])
      implementations_[index].reset(new strand_impl);
    impl = implementations_[index].get();
  }

  // Destroy a strand implementation.
  void destroy(implementation_type& impl)
  {
    impl = 0;
  }

  // Request the io_service to invoke the given handler.
  template <typename Handler>
  void dispatch(implementation_type& impl, Handler handler)
  {
    if (call_stack<strand_impl>::contains(impl))
    {
      streams_boost_asio_handler_invoke_helpers::invoke(handler, handler);
    }
    else
    {
      // Allocate and construct an object to wrap the handler.
      typedef handler_wrapper<Handler> value_type;
      typedef handler_alloc_traits<Handler, value_type> alloc_traits;
      raw_handler_ptr<alloc_traits> raw_ptr(handler);
      handler_ptr<alloc_traits> ptr(raw_ptr, handler);

      streams_boost::asio::detail::mutex::scoped_lock lock(impl->mutex_);

      if (impl->current_handler_ == 0)
      {
        // This handler now has the lock, so can be dispatched immediately.
        impl->current_handler_ = ptr.release();
        lock.unlock();
        this->get_io_service().dispatch(invoke_current_handler(*this, impl));
      }
      else
      {
        // Another handler already holds the lock, so this handler must join
        // the list of waiters. The handler will be posted automatically when
        // its turn comes.
        if (impl->last_waiter_)
        {
          impl->last_waiter_->next_ = ptr.get();
          impl->last_waiter_ = impl->last_waiter_->next_;
        }
        else
        {
          impl->first_waiter_ = ptr.get();
          impl->last_waiter_ = ptr.get();
        }
        ptr.release();
      }
    }
  }

  // Request the io_service to invoke the given handler and return immediately.
  template <typename Handler>
  void post(implementation_type& impl, Handler handler)
  {
    // Allocate and construct an object to wrap the handler.
    typedef handler_wrapper<Handler> value_type;
    typedef handler_alloc_traits<Handler, value_type> alloc_traits;
    raw_handler_ptr<alloc_traits> raw_ptr(handler);
    handler_ptr<alloc_traits> ptr(raw_ptr, handler);

    streams_boost::asio::detail::mutex::scoped_lock lock(impl->mutex_);

    if (impl->current_handler_ == 0)
    {
      // This handler now has the lock, so can be dispatched immediately.
      impl->current_handler_ = ptr.release();
      lock.unlock();
      this->get_io_service().post(invoke_current_handler(*this, impl));
    }
    else
    {
      // Another handler already holds the lock, so this handler must join the
      // list of waiters. The handler will be posted automatically when its turn
      // comes.
      if (impl->last_waiter_)
      {
        impl->last_waiter_->next_ = ptr.get();
        impl->last_waiter_ = impl->last_waiter_->next_;
      }
      else
      {
        impl->first_waiter_ = ptr.get();
        impl->last_waiter_ = ptr.get();
      }
      ptr.release();
    }
  }

private:
  // Mutex to protect access to the array of implementations.
  streams_boost::asio::detail::mutex mutex_;

  // Number of implementations shared between all strand objects.
  enum { num_implementations = 193 };

  // The head of a linked list of all implementations.
  streams_boost::scoped_ptr<strand_impl> implementations_[num_implementations];

  // Extra value used when hashing to prevent recycled memory locations from
  // getting the same strand implementation.
  std::size_t salt_;
};

} // namespace detail
} // namespace asio
} // namespace streams_boost

#include <streams_boost/asio/detail/pop_options.hpp>

#endif // STREAMS_BOOST_ASIO_DETAIL_STRAND_SERVICE_HPP