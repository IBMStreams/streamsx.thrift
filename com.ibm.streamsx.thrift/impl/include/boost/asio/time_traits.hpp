//
// time_traits.hpp
// ~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2010 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//

#ifndef STREAMS_BOOST_ASIO_TIME_TRAITS_HPP
#define STREAMS_BOOST_ASIO_TIME_TRAITS_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <streams_boost/asio/detail/push_options.hpp>

#include <streams_boost/asio/detail/socket_types.hpp> // Must come before posix_time.

#include <streams_boost/asio/detail/push_options.hpp>
#include <streams_boost/date_time/posix_time/posix_time_types.hpp>
#include <streams_boost/asio/detail/pop_options.hpp>

namespace streams_boost {
namespace asio {

/// Time traits suitable for use with the deadline timer.
template <typename Time>
struct time_traits;

/// Time traits specialised for posix_time.
template <>
struct time_traits<streams_boost::posix_time::ptime>
{
  /// The time type.
  typedef streams_boost::posix_time::ptime time_type;

  /// The duration type.
  typedef streams_boost::posix_time::time_duration duration_type;

  /// Get the current time.
  static time_type now()
  {
#if defined(STREAMS_BOOST_DATE_TIME_HAS_HIGH_PRECISION_CLOCK)
    return streams_boost::posix_time::microsec_clock::universal_time();
#else // defined(STREAMS_BOOST_DATE_TIME_HAS_HIGH_PRECISION_CLOCK)
    return streams_boost::posix_time::second_clock::universal_time();
#endif // defined(STREAMS_BOOST_DATE_TIME_HAS_HIGH_PRECISION_CLOCK)
  }

  /// Add a duration to a time.
  static time_type add(const time_type& t, const duration_type& d)
  {
    return t + d;
  }

  /// Subtract one time from another.
  static duration_type subtract(const time_type& t1, const time_type& t2)
  {
    return t1 - t2;
  }

  /// Test whether one time is less than another.
  static bool less_than(const time_type& t1, const time_type& t2)
  {
    return t1 < t2;
  }

  /// Convert to POSIX duration type.
  static streams_boost::posix_time::time_duration to_posix_duration(
      const duration_type& d)
  {
    return d;
  }
};

} // namespace asio
} // namespace streams_boost

#include <streams_boost/asio/detail/pop_options.hpp>

#endif // STREAMS_BOOST_ASIO_TIME_TRAITS_HPP
