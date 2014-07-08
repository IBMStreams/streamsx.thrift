//
// null_mutex.hpp
// ~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2010 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//

#ifndef STREAMS_BOOST_ASIO_DETAIL_NULL_MUTEX_HPP
#define STREAMS_BOOST_ASIO_DETAIL_NULL_MUTEX_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <streams_boost/asio/detail/push_options.hpp>

#include <streams_boost/asio/detail/push_options.hpp>
#include <streams_boost/config.hpp>
#include <streams_boost/asio/detail/pop_options.hpp>

#if !defined(STREAMS_BOOST_HAS_THREADS)

#include <streams_boost/asio/detail/noncopyable.hpp>
#include <streams_boost/asio/detail/scoped_lock.hpp>

namespace streams_boost {
namespace asio {
namespace detail {

class null_mutex
  : private noncopyable
{
public:
  typedef streams_boost::asio::detail::scoped_lock<null_mutex> scoped_lock;

  // Constructor.
  null_mutex()
  {
  }

  // Destructor.
  ~null_mutex()
  {
  }

  // Lock the mutex.
  void lock()
  {
  }

  // Unlock the mutex.
  void unlock()
  {
  }
};

} // namespace detail
} // namespace asio
} // namespace streams_boost

#endif // !defined(STREAMS_BOOST_HAS_THREADS)

#include <streams_boost/asio/detail/pop_options.hpp>

#endif // STREAMS_BOOST_ASIO_DETAIL_NULL_MUTEX_HPP
