//
// posix_mutex.hpp
// ~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2010 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//

#ifndef STREAMS_BOOST_ASIO_DETAIL_POSIX_MUTEX_STREAMS_HPP
#define STREAMS_BOOST_ASIO_DETAIL_POSIX_MUTEX_STREAMS_HPP

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
#include <streams_boost/throw_exception.hpp>
#include <pthread.h>
#include <streams_boost/asio/detail/pop_options.hpp>

#include <streams_boost/asio/error.hpp>
#include <streams_boost/asio/detail/noncopyable.hpp>
#include <streams_boost/asio/detail/scoped_lock.hpp>

namespace streams_boost {
namespace asio {
namespace detail {

class posix_event;

class posix_mutex
  : private noncopyable
{
public:
  typedef streams_boost::asio::detail::scoped_lock<posix_mutex> scoped_lock;

  // Constructor.
  posix_mutex()
  {
    int error = ::pthread_mutex_init(&mutex_, 0);
    if (error != 0)
    {
      streams_boost::system::system_error e(
          streams_boost::system::error_code(error,
            streams_boost::asio::error::get_system_category()),
          "mutex");
      streams_boost::throw_exception(e);
    }
  }

  // Destructor.
  ~posix_mutex()
  {
    ::pthread_mutex_destroy(&mutex_);
  }

  // Lock the mutex.
  void lock()
  {
    int error = ::pthread_mutex_lock(&mutex_);
    if (error != 0)
    {
      streams_boost::system::system_error e(
          streams_boost::system::error_code(error,
            streams_boost::asio::error::get_system_category()),
          "mutex");
      streams_boost::throw_exception(e);
    }
  }

  // Unlock the mutex.
  void unlock()
  {
    int error = ::pthread_mutex_unlock(&mutex_);
    if (error != 0)
    {
      streams_boost::system::system_error e(
          streams_boost::system::error_code(error,
            streams_boost::asio::error::get_system_category()),
          "mutex");
      streams_boost::throw_exception(e);
    }
  }

private:
  friend class posix_event;
  ::pthread_mutex_t mutex_;
};

} // namespace detail
} // namespace asio
} // namespace streams_boost

#endif // defined(STREAMS_BOOST_HAS_PTHREADS)

#include <streams_boost/asio/detail/pop_options.hpp>

#endif // STREAMS_BOOST_ASIO_DETAIL_POSIX_MUTEX_STREAMS_HPP
