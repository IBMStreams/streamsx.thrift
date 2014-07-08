//
// deadline_timer.hpp
// ~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2010 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//

#ifndef STREAMS_BOOST_ASIO_DEADLINE_TIMER_HPP
#define STREAMS_BOOST_ASIO_DEADLINE_TIMER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <streams_boost/asio/detail/push_options.hpp>

#include <streams_boost/asio/detail/socket_types.hpp> // Must come before posix_time.

#include <streams_boost/asio/detail/push_options.hpp>
#include <streams_boost/date_time/posix_time/posix_time_types.hpp>
#include <streams_boost/asio/detail/pop_options.hpp>

#include <streams_boost/asio/basic_deadline_timer.hpp>

namespace streams_boost {
namespace asio {

/// Typedef for the typical usage of timer. Uses a UTC clock.
typedef basic_deadline_timer<streams_boost::posix_time::ptime> deadline_timer;

} // namespace asio
} // namespace streams_boost

#include <streams_boost/asio/detail/pop_options.hpp>

#endif // STREAMS_BOOST_ASIO_DEADLINE_TIMER_HPP
