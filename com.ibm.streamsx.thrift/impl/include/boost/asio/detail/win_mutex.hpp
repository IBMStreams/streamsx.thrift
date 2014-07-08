//
// win_mutex.hpp
// ~~~~~~~~~~~~~
//
// Copyright (c) 2003-2010 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//

#ifndef STREAMS_BOOST_ASIO_DETAIL_WIN_MUTEX_HPP
#define STREAMS_BOOST_ASIO_DETAIL_WIN_MUTEX_HPP

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
#include <streams_boost/asio/detail/scoped_lock.hpp>

#include <streams_boost/asio/detail/push_options.hpp>
#include <streams_boost/throw_exception.hpp>
#include <streams_boost/asio/detail/pop_options.hpp>

namespace streams_boost {
namespace asio {
namespace detail {

class win_mutex
  : private noncopyable
{
public:
  typedef streams_boost::asio::detail::scoped_lock<win_mutex> scoped_lock;

  // Constructor.
  win_mutex()
  {
    int error = do_init();
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
  ~win_mutex()
  {
    ::DeleteCriticalSection(&crit_section_);
  }

  // Lock the mutex.
  void lock()
  {
    int error = do_lock();
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
    ::LeaveCriticalSection(&crit_section_);
  }

private:
  // Initialisation must be performed in a separate function to the constructor
  // since the compiler does not support the use of structured exceptions and
  // C++ exceptions in the same function.
  int do_init()
  {
#if defined(__MINGW32__)
    // Not sure if MinGW supports structured exception handling, so for now
    // we'll just call the Windows API and hope.
    ::InitializeCriticalSection(&crit_section_);
    return 0;
#else
    __try
    {
      ::InitializeCriticalSection(&crit_section_);
    }
    __except(GetExceptionCode() == STATUS_NO_MEMORY
        ? EXCEPTION_EXECUTE_HANDLER : EXCEPTION_CONTINUE_SEARCH)
    {
      return ERROR_OUTOFMEMORY;
    }

    return 0;
#endif
  }

  // Locking must be performed in a separate function to lock() since the
  // compiler does not support the use of structured exceptions and C++
  // exceptions in the same function.
  int do_lock()
  {
#if defined(__MINGW32__)
    // Not sure if MinGW supports structured exception handling, so for now
    // we'll just call the Windows API and hope.
    ::EnterCriticalSection(&crit_section_);
    return 0;
#else
    __try
    {
      ::EnterCriticalSection(&crit_section_);
    }
    __except(GetExceptionCode() == STATUS_INVALID_HANDLE
        || GetExceptionCode() == STATUS_NO_MEMORY
        ? EXCEPTION_EXECUTE_HANDLER : EXCEPTION_CONTINUE_SEARCH)
    {
      if (GetExceptionCode() == STATUS_NO_MEMORY)
        return ERROR_OUTOFMEMORY;
      return ERROR_INVALID_HANDLE;
    }

    return 0;
#endif
  }

  ::CRITICAL_SECTION crit_section_;
};

} // namespace detail
} // namespace asio
} // namespace streams_boost

#endif // defined(STREAMS_BOOST_WINDOWS)

#include <streams_boost/asio/detail/pop_options.hpp>

#endif // STREAMS_BOOST_ASIO_DETAIL_WIN_MUTEX_HPP
