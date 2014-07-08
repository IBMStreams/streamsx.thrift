//
// resolver_service.hpp
// ~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2010 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//

#ifndef STREAMS_BOOST_ASIO_DETAIL_RESOLVER_SERVICE_HPP
#define STREAMS_BOOST_ASIO_DETAIL_RESOLVER_SERVICE_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <streams_boost/asio/detail/push_options.hpp>

#include <streams_boost/asio/detail/push_options.hpp>
#include <cstring>
#include <streams_boost/scoped_ptr.hpp>
#include <streams_boost/shared_ptr.hpp>
#include <streams_boost/weak_ptr.hpp>
#include <streams_boost/asio/detail/pop_options.hpp>

#include <streams_boost/asio/error.hpp>
#include <streams_boost/asio/io_service.hpp>
#include <streams_boost/asio/detail/bind_handler.hpp>
#include <streams_boost/asio/detail/mutex.hpp>
#include <streams_boost/asio/detail/noncopyable.hpp>
#include <streams_boost/asio/detail/service_base.hpp>
#include <streams_boost/asio/detail/socket_ops.hpp>
#include <streams_boost/asio/detail/socket_types.hpp>
#include <streams_boost/asio/detail/thread.hpp>

namespace streams_boost {
namespace asio {
namespace detail {

template <typename Protocol>
class resolver_service
  : public streams_boost::asio::detail::service_base<resolver_service<Protocol> >
{
private:
  // Helper class to perform exception-safe cleanup of addrinfo objects.
  class auto_addrinfo
    : private streams_boost::asio::detail::noncopyable
  {
  public:
    explicit auto_addrinfo(streams_boost::asio::detail::addrinfo_type* ai)
      : ai_(ai)
    {
    }

    ~auto_addrinfo()
    {
      if (ai_)
        socket_ops::freeaddrinfo(ai_);
    }

    operator streams_boost::asio::detail::addrinfo_type*()
    {
      return ai_;
    }

  private:
    streams_boost::asio::detail::addrinfo_type* ai_;
  };

public:
  // The implementation type of the resolver. The shared pointer is used as a
  // cancellation token to indicate to the background thread that the operation
  // has been cancelled.
  typedef streams_boost::shared_ptr<void> implementation_type;
  struct noop_deleter { void operator()(void*) {} };

  // The endpoint type.
  typedef typename Protocol::endpoint endpoint_type;

  // The query type.
  typedef typename Protocol::resolver_query query_type;

  // The iterator type.
  typedef typename Protocol::resolver_iterator iterator_type;

  // Constructor.
  resolver_service(streams_boost::asio::io_service& io_service)
    : streams_boost::asio::detail::service_base<
        resolver_service<Protocol> >(io_service),
      mutex_(),
      work_io_service_(new streams_boost::asio::io_service),
      work_(new streams_boost::asio::io_service::work(*work_io_service_)),
      work_thread_(0)
  {
  }

  // Destructor.
  ~resolver_service()
  {
    shutdown_service();
  }

  // Destroy all user-defined handler objects owned by the service.
  void shutdown_service()
  {
    work_.reset();
    if (work_io_service_)
    {
      work_io_service_->stop();
      if (work_thread_)
      {
        work_thread_->join();
        work_thread_.reset();
      }
      work_io_service_.reset();
    }
  }

  // Construct a new resolver implementation.
  void construct(implementation_type& impl)
  {
    impl.reset(static_cast<void*>(0), noop_deleter());
  }

  // Destroy a resolver implementation.
  void destroy(implementation_type&)
  {
  }

  // Cancel pending asynchronous operations.
  void cancel(implementation_type& impl)
  {
    impl.reset(static_cast<void*>(0), noop_deleter());
  }

  // Resolve a query to a list of entries.
  iterator_type resolve(implementation_type&, const query_type& query,
      streams_boost::system::error_code& ec)
  {
    streams_boost::asio::detail::addrinfo_type* address_info = 0;
    std::string host_name = query.host_name();
    std::string service_name = query.service_name();
    streams_boost::asio::detail::addrinfo_type hints = query.hints();

    socket_ops::getaddrinfo(host_name.length() ? host_name.c_str() : 0,
        service_name.c_str(), &hints, &address_info, ec);
    auto_addrinfo auto_address_info(address_info);

    if (ec)
      return iterator_type();

    return iterator_type::create(address_info, host_name, service_name);
  }

  template <typename Handler>
  class resolve_query_handler
  {
  public:
    resolve_query_handler(implementation_type impl, const query_type& query,
        streams_boost::asio::io_service& io_service, Handler handler)
      : impl_(impl),
        query_(query),
        io_service_(io_service),
        work_(io_service),
        handler_(handler)
    {
    }

    void operator()()
    {
      // Check if the operation has been cancelled.
      if (impl_.expired())
      {
        iterator_type iterator;
        io_service_.post(streams_boost::asio::detail::bind_handler(handler_,
              streams_boost::asio::error::operation_aborted, iterator));
        return;
      }

      // Perform the blocking host resolution operation.
      streams_boost::asio::detail::addrinfo_type* address_info = 0;
      std::string host_name = query_.host_name();
      std::string service_name = query_.service_name();
      streams_boost::asio::detail::addrinfo_type hints = query_.hints();
      streams_boost::system::error_code ec;
      socket_ops::getaddrinfo(host_name.length() ? host_name.c_str() : 0,
          service_name.c_str(), &hints, &address_info, ec);
      auto_addrinfo auto_address_info(address_info);

      // Invoke the handler and pass the result.
      iterator_type iterator;
      if (!ec)
        iterator = iterator_type::create(address_info, host_name, service_name);
      io_service_.post(streams_boost::asio::detail::bind_handler(
            handler_, ec, iterator));
    }

  private:
    streams_boost::weak_ptr<void> impl_;
    query_type query_;
    streams_boost::asio::io_service& io_service_;
    streams_boost::asio::io_service::work work_;
    Handler handler_;
  };

  // Asynchronously resolve a query to a list of entries.
  template <typename Handler>
  void async_resolve(implementation_type& impl, const query_type& query,
      Handler handler)
  {
    if (work_io_service_)
    {
      start_work_thread();
      work_io_service_->post(
          resolve_query_handler<Handler>(
            impl, query, this->get_io_service(), handler));
    }
  }

  // Resolve an endpoint to a list of entries.
  iterator_type resolve(implementation_type&,
      const endpoint_type& endpoint, streams_boost::system::error_code& ec)
  {
    // First try resolving with the service name. If that fails try resolving
    // but allow the service to be returned as a number.
    char host_name[NI_MAXHOST];
    char service_name[NI_MAXSERV];
    int flags = endpoint.protocol().type() == SOCK_DGRAM ? NI_DGRAM : 0;
    socket_ops::getnameinfo(endpoint.data(), endpoint.size(),
        host_name, NI_MAXHOST, service_name, NI_MAXSERV, flags, ec);
    if (ec)
    {
      flags |= NI_NUMERICSERV;
      socket_ops::getnameinfo(endpoint.data(), endpoint.size(),
          host_name, NI_MAXHOST, service_name, NI_MAXSERV, flags, ec);
    }

    if (ec)
      return iterator_type();

    return iterator_type::create(endpoint, host_name, service_name);
  }

  template <typename Handler>
  class resolve_endpoint_handler
  {
  public:
    resolve_endpoint_handler(implementation_type impl,
        const endpoint_type& endpoint, streams_boost::asio::io_service& io_service,
        Handler handler)
      : impl_(impl),
        endpoint_(endpoint),
        io_service_(io_service),
        work_(io_service),
        handler_(handler)
    {
    }

    void operator()()
    {
      // Check if the operation has been cancelled.
      if (impl_.expired())
      {
        iterator_type iterator;
        io_service_.post(streams_boost::asio::detail::bind_handler(handler_,
              streams_boost::asio::error::operation_aborted, iterator));
        return;
      }


      // First try resolving with the service name. If that fails try resolving
      // but allow the service to be returned as a number.
      char host_name[NI_MAXHOST];
      char service_name[NI_MAXSERV];
      int flags = endpoint_.protocol().type() == SOCK_DGRAM ? NI_DGRAM : 0;
      streams_boost::system::error_code ec;
      socket_ops::getnameinfo(endpoint_.data(), endpoint_.size(),
          host_name, NI_MAXHOST, service_name, NI_MAXSERV, flags, ec);
      if (ec)
      {
        flags |= NI_NUMERICSERV;
        socket_ops::getnameinfo(endpoint_.data(), endpoint_.size(),
            host_name, NI_MAXHOST, service_name, NI_MAXSERV, flags, ec);
      }

      // Invoke the handler and pass the result.
      iterator_type iterator;
      if (!ec)
        iterator = iterator_type::create(endpoint_, host_name, service_name);
      io_service_.post(streams_boost::asio::detail::bind_handler(
            handler_, ec, iterator));
    }

  private:
    streams_boost::weak_ptr<void> impl_;
    endpoint_type endpoint_;
    streams_boost::asio::io_service& io_service_;
    streams_boost::asio::io_service::work work_;
    Handler handler_;
  };

  // Asynchronously resolve an endpoint to a list of entries.
  template <typename Handler>
  void async_resolve(implementation_type& impl, const endpoint_type& endpoint,
      Handler handler)
  {
    if (work_io_service_)
    {
      start_work_thread();
      work_io_service_->post(
          resolve_endpoint_handler<Handler>(
            impl, endpoint, this->get_io_service(), handler));
    }
  }

private:
  // Helper class to run the work io_service in a thread.
  class work_io_service_runner
  {
  public:
    work_io_service_runner(streams_boost::asio::io_service& io_service)
      : io_service_(io_service) {}
    void operator()() { io_service_.run(); }
  private:
    streams_boost::asio::io_service& io_service_;
  };

  // Start the work thread if it's not already running.
  void start_work_thread()
  {
    streams_boost::asio::detail::mutex::scoped_lock lock(mutex_);
    if (!work_thread_)
    {
      work_thread_.reset(new streams_boost::asio::detail::thread(
            work_io_service_runner(*work_io_service_)));
    }
  }

  // Mutex to protect access to internal data.
  streams_boost::asio::detail::mutex mutex_;

  // Private io_service used for performing asynchronous host resolution.
  streams_boost::scoped_ptr<streams_boost::asio::io_service> work_io_service_;

  // Work for the private io_service to perform.
  streams_boost::scoped_ptr<streams_boost::asio::io_service::work> work_;

  // Thread used for running the work io_service's run loop.
  streams_boost::scoped_ptr<streams_boost::asio::detail::thread> work_thread_;
};

} // namespace detail
} // namespace asio
} // namespace streams_boost

#include <streams_boost/asio/detail/pop_options.hpp>

#endif // STREAMS_BOOST_ASIO_DETAIL_RESOLVER_SERVICE_HPP
