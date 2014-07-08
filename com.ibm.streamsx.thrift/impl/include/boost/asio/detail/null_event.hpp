//
// null_event.hpp
// ~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2010 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//

#ifndef STREAMS_BOOST_ASIO_DETAIL_NULL_EVENT_HPP
#define STREAMS_BOOST_ASIO_DETAIL_NULL_EVENT_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <streams_boost/asio/detail/push_options.hpp>

#include <streams_boost/asio/detail/push_options.hpp>
#include <streams_boost/config.hpp>
#include <streams_boost/asio/detail/pop_options.hpp>

#if !defined(STREAMS_BOOST_HAS_THREADS)

#include <streams_boost/asio/detail/noncopyable.hpp>

namespace streams_boost {
namespace asio {
namespace detail {

class null_event
  : private noncopyable
{
public:
  // Constructor.
  null_event()
  {
  }

  // Destructor.
  ~null_event()
  {
  }

  // Signal the event.
  template <typename Lock>
  void signal(Lock&)
  {
  }

  // Reset the event.
  template <typename Lock>
  void clear(Lock&)
  {
  }

  // Wait for the event to become signalled.
  template <typename Lock>
  void wait(Lock&)
  {
  }
};

} // namespace detail
} // namespace asio
} // namespace streams_boost

#endif // !defined(STREAMS_BOOST_HAS_THREADS)

#include <streams_boost/asio/detail/pop_options.hpp>

#endif // STREAMS_BOOST_ASIO_DETAIL_NULL_EVENT_HPP
