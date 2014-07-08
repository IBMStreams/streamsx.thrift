//
// posix_tss_ptr.hpp
// ~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2010 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//

#ifndef STREAMS_BOOST_ASIO_DETAIL_POSIX_TSS_PTR_STREAMS_HPP
#define STREAMS_BOOST_ASIO_DETAIL_POSIX_TSS_PTR_STREAMS_HPP

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

namespace streams_boost {
namespace asio {
namespace detail {

template <typename T>
class posix_tss_ptr
  : private noncopyable
{
public:
  // Constructor.
  posix_tss_ptr()
  {
    int error = ::pthread_key_create(&tss_key_, 0);
    if (error != 0)
    {
      streams_boost::system::system_error e(
          streams_boost::system::error_code(error,
            streams_boost::asio::error::get_system_category()),
          "tss");
      streams_boost::throw_exception(e);
    }
  }

  // Destructor.
  ~posix_tss_ptr()
  {
    ::pthread_key_delete(tss_key_);
  }

  // Get the value.
  operator T*() const
  {
    return static_cast<T*>(::pthread_getspecific(tss_key_));
  }

  // Set the value.
  void operator=(T* value)
  {
    ::pthread_setspecific(tss_key_, value);
  }

private:
  // Thread-specific storage to allow unlocked access to determine whether a
  // thread is a member of the pool.
  pthread_key_t tss_key_;
};

} // namespace detail
} // namespace asio
} // namespace streams_boost

#endif // defined(STREAMS_BOOST_HAS_PTHREADS)

#include <streams_boost/asio/detail/pop_options.hpp>

#endif // STREAMS_BOOST_ASIO_DETAIL_POSIX_TSS_PTR_STREAMS_HPP
