//
// posix_thread.hpp
// ~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2010 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//

#ifndef STREAMS_BOOST_ASIO_DETAIL_POSIX_THREAD_STREAMS_HPP
#define STREAMS_BOOST_ASIO_DETAIL_POSIX_THREAD_STREAMS_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <streams_boost/asio/detail/push_options.hpp>

#include <streams_boost/asio/detail/push_options.hpp>
#include <streams_boost/config.hpp>
#include <streams_boost/system/system_error.hpp>
#include <streams_boost/asio/detail/pop_options.hpp>

#if defined(STREAMS_BOOST_HAS_PTHREADS)

#include <streams_boost/asio/detail/push_options.hpp>
#include <memory>
#include <streams_boost/throw_exception.hpp>
#include <pthread.h>
#include <streams_boost/asio/detail/pop_options.hpp>

#include <streams_boost/asio/error.hpp>
#include <streams_boost/asio/detail/noncopyable.hpp>

namespace streams_boost {
namespace asio {
namespace detail {

extern "C" void* streams_boost_asio_detail_posix_thread_function(void* arg);

class posix_thread
  : private noncopyable
{
public:
  // Constructor.
  template <typename Function>
  posix_thread(Function f)
    : joined_(false)
  {
    std::auto_ptr<func_base> arg(new func<Function>(f));
    int error = ::pthread_create(&thread_, 0,
          streams_boost_asio_detail_posix_thread_function, arg.get());
    if (error != 0)
    {
      streams_boost::system::system_error e(
          streams_boost::system::error_code(error,
            streams_boost::asio::error::get_system_category()),
          "thread");
      streams_boost::throw_exception(e);
    }
    arg.release();
  }

  // Destructor.
  ~posix_thread()
  {
    if (!joined_)
      ::pthread_detach(thread_);
  }

  // Wait for the thread to exit.
  void join()
  {
    if (!joined_)
    {
      ::pthread_join(thread_, 0);
      joined_ = true;
    }
  }

private:
  friend void* streams_boost_asio_detail_posix_thread_function(void* arg);

  class func_base
  {
  public:
    virtual ~func_base() {}
    virtual void run() = 0;
  };

  template <typename Function>
  class func
    : public func_base
  {
  public:
    func(Function f)
      : f_(f)
    {
    }

    virtual void run()
    {
      f_();
    }

  private:
    Function f_;
  };

  ::pthread_t thread_;
  bool joined_;
};

inline void* streams_boost_asio_detail_posix_thread_function(void* arg)
{
  std::auto_ptr<posix_thread::func_base> f(
      static_cast<posix_thread::func_base*>(arg));
  f->run();
  return 0;
}

} // namespace detail
} // namespace asio
} // namespace streams_boost

#endif // defined(STREAMS_BOOST_HAS_PTHREADS)

#include <streams_boost/asio/detail/pop_options.hpp>

#endif // STREAMS_BOOST_ASIO_DETAIL_POSIX_THREAD_STREAMS_HPP
