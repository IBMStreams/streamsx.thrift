//
// null_thread.hpp
// ~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2010 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//

#ifndef STREAMS_BOOST_ASIO_DETAIL_NULL_THREAD_HPP
#define STREAMS_BOOST_ASIO_DETAIL_NULL_THREAD_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <streams_boost/asio/detail/push_options.hpp>

#include <streams_boost/asio/detail/push_options.hpp>
#include <streams_boost/config.hpp>
#include <streams_boost/system/system_error.hpp>
#include <streams_boost/asio/detail/pop_options.hpp>

#if !defined(STREAMS_BOOST_HAS_THREADS)

#include <streams_boost/asio/detail/push_options.hpp>
#include <streams_boost/throw_exception.hpp>
#include <streams_boost/asio/detail/pop_options.hpp>

#include <streams_boost/asio/error.hpp>
#include <streams_boost/asio/detail/noncopyable.hpp>

namespace streams_boost {
namespace asio {
namespace detail {

class null_thread
  : private noncopyable
{
public:
  // Constructor.
  template <typename Function>
  null_thread(Function f)
  {
    streams_boost::system::system_error e(
        streams_boost::asio::error::operation_not_supported, "thread");
    streams_boost::throw_exception(e);
  }

  // Destructor.
  ~null_thread()
  {
  }

  // Wait for the thread to exit.
  void join()
  {
  }
};

} // namespace detail
} // namespace asio
} // namespace streams_boost

#endif // !defined(STREAMS_BOOST_HAS_THREADS)

#include <streams_boost/asio/detail/pop_options.hpp>

#endif // STREAMS_BOOST_ASIO_DETAIL_NULL_THREAD_HPP
