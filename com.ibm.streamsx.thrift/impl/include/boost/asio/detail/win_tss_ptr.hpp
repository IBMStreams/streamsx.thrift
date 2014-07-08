//
// win_tss_ptr.hpp
// ~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2010 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//

#ifndef STREAMS_BOOST_ASIO_DETAIL_WIN_TSS_PTR_HPP
#define STREAMS_BOOST_ASIO_DETAIL_WIN_TSS_PTR_HPP

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
#include <streams_boost/throw_exception.hpp>
#include <streams_boost/asio/detail/pop_options.hpp>

namespace streams_boost {
namespace asio {
namespace detail {

template <typename T>
class win_tss_ptr
  : private noncopyable
{
public:
#if defined(UNDER_CE)
  enum { out_of_indexes = 0xFFFFFFFF };
#else
  enum { out_of_indexes = TLS_OUT_OF_INDEXES };
#endif

  // Constructor.
  win_tss_ptr()
  {
    tss_key_ = ::TlsAlloc();
    if (tss_key_ == out_of_indexes)
    {
      DWORD last_error = ::GetLastError();
      streams_boost::system::system_error e(
          streams_boost::system::error_code(last_error,
            streams_boost::asio::error::get_system_category()),
          "tss");
      streams_boost::throw_exception(e);
    }
  }

  // Destructor.
  ~win_tss_ptr()
  {
    ::TlsFree(tss_key_);
  }

  // Get the value.
  operator T*() const
  {
    return static_cast<T*>(::TlsGetValue(tss_key_));
  }

  // Set the value.
  void operator=(T* value)
  {
    ::TlsSetValue(tss_key_, value);
  }

private:
  // Thread-specific storage to allow unlocked access to determine whether a
  // thread is a member of the pool.
  DWORD tss_key_;
};

} // namespace detail
} // namespace asio
} // namespace streams_boost

#endif // defined(STREAMS_BOOST_WINDOWS)

#include <streams_boost/asio/detail/pop_options.hpp>

#endif // STREAMS_BOOST_ASIO_DETAIL_WIN_TSS_PTR_HPP
