//
// dev_poll_reactor_fwd.hpp
// ~~~~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2010 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//

#ifndef STREAMS_BOOST_ASIO_DETAIL_DEV_POLL_REACTOR_FWD_HPP
#define STREAMS_BOOST_ASIO_DETAIL_DEV_POLL_REACTOR_FWD_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <streams_boost/asio/detail/push_options.hpp>

#if !defined(STREAMS_BOOST_ASIO_DISABLE_DEV_POLL)
#if defined(__sun) // This service is only supported on Solaris.

// Define this to indicate that /dev/poll is supported on the target platform.
#define STREAMS_BOOST_ASIO_HAS_DEV_POLL 1

namespace streams_boost {
namespace asio {
namespace detail {

template <bool Own_Thread>
class dev_poll_reactor;

} // namespace detail
} // namespace asio
} // namespace streams_boost

#endif // defined(__sun)
#endif // !defined(STREAMS_BOOST_ASIO_DISABLE_DEV_POLL)

#include <streams_boost/asio/detail/pop_options.hpp>

#endif // STREAMS_BOOST_ASIO_DETAIL_DEV_POLL_REACTOR_FWD_HPP
