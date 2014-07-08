//
// win_event.hpp
// ~~~~~~~~~~~~~
//
// Copyright (c) 2003-2010 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//

#ifndef STREAMS_BOOST_ASIO_DETAIL_WIN_EVENT_HPP
#define STREAMS_BOOST_ASIO_DETAIL_WIN_EVENT_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <streams_boost/asio/detail/push_options.hpp>

#include <streams_boost/asio/detail/push_options.hpp>
#include <streams_boost/config.hpp>
#include <streams_boost/system/system_error.hpp>
#include <streams_boost/asio/detail/pop_options.hpp>

#if defined(STREAMS_BOOST_WINDOWS)

#include <streams_boost/asio/error.hpp>
#include <streams_boost/asio/detail/noncopyable.hpp>
#include <streams_boost/asio/detail/socket_types.hpp>

#include <streams_boost/asio/detail/push_options.hpp>
#include <streams_boost/assert.hpp>
#include <streams_boost/throw_exception.hpp>
#include <streams_boost/asio/detail/pop_options.hpp>

namespace streams_boost {
namespace asio {
namespace detail {

class win_event
  : private noncopyable
{
public:
  // Constructor.
  win_event()
    : event_(::CreateEvent(0, true, false, 0))
  {
    if (!event_)
    {
      DWORD last_error = ::GetLastError();
      streams_boost::system::system_error e(
          streams_boost::system::error_code(last_error,
            streams_boost::asio::error::get_system_category()),
          "event");
      streams_boost::throw_exception(e);
    }
  }

  // Destructor.
  ~win_event()
  {
    ::CloseHandle(event_);
  }

  // Signal the event.
  template <typename Lock>
  void signal(Lock& lock)
  {
    STREAMS_BOOST_ASSERT(lock.locked());
    (void)lock;
    ::SetEvent(event_);
  }

  // Reset the event.
  template <typename Lock>
  void clear(Lock& lock)
  {
    STREAMS_BOOST_ASSERT(lock.locked());
    (void)lock;
    ::ResetEvent(event_);
  }

  // Wait for the event to become signalled.
  template <typename Lock>
  void wait(Lock& lock)
  {
    STREAMS_BOOST_ASSERT(lock.locked());
    lock.unlock();
    ::WaitForSingleObject(event_, INFINITE);
    lock.lock();
  }

private:
  HANDLE event_;
};

} // namespace detail
} // namespace asio
} // namespace streams_boost

#endif // defined(STREAMS_BOOST_WINDOWS)

#include <streams_boost/asio/detail/pop_options.hpp>

#endif // STREAMS_BOOST_ASIO_DETAIL_WIN_EVENT_HPP
