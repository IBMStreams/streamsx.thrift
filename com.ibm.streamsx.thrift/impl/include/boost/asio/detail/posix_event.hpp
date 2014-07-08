//
// posix_event.hpp
// ~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2010 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//

#ifndef STREAMS_BOOST_ASIO_DETAIL_POSIX_EVENT_STREAMS_HPP
#define STREAMS_BOOST_ASIO_DETAIL_POSIX_EVENT_STREAMS_HPP

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
#include <streams_boost/assert.hpp>
#include <streams_boost/throw_exception.hpp>
#include <pthread.h>
#include <streams_boost/asio/detail/pop_options.hpp>

#include <streams_boost/asio/error.hpp>
#include <streams_boost/asio/detail/noncopyable.hpp>

namespace streams_boost {
namespace asio {
namespace detail {

class posix_event
  : private noncopyable
{
public:
  // Constructor.
  posix_event()
    : signalled_(false)
  {
    int error = ::pthread_cond_init(&cond_, 0);
    if (error != 0)
    {
      streams_boost::system::system_error e(
          streams_boost::system::error_code(error,
            streams_boost::asio::error::get_system_category()),
          "event");
      streams_boost::throw_exception(e);
    }
  }

  // Destructor.
  ~posix_event()
  {
    ::pthread_cond_destroy(&cond_);
  }

  // Signal the event.
  template <typename Lock>
  void signal(Lock& lock)
  {
    STREAMS_BOOST_ASSERT(lock.locked());
    (void)lock;
    signalled_ = true;
    ::pthread_cond_signal(&cond_); // Ignore EINVAL.
  }

  // Reset the event.
  template <typename Lock>
  void clear(Lock& lock)
  {
    STREAMS_BOOST_ASSERT(lock.locked());
    (void)lock;
    signalled_ = false;
  }

  // Wait for the event to become signalled.
  template <typename Lock>
  void wait(Lock& lock)
  {
    STREAMS_BOOST_ASSERT(lock.locked());
    while (!signalled_)
      ::pthread_cond_wait(&cond_, &lock.mutex().mutex_); // Ignore EINVAL.
  }

private:
  ::pthread_cond_t cond_;
  bool signalled_;
};

} // namespace detail
} // namespace asio
} // namespace streams_boost

#endif // defined(STREAMS_BOOST_HAS_PTHREADS)

#include <streams_boost/asio/detail/pop_options.hpp>

#endif // STREAMS_BOOST_ASIO_DETAIL_POSIX_EVENT_STREAMS_HPP
