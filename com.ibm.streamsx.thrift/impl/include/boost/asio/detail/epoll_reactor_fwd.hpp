//
// epoll_reactor_fwd.hpp
// ~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2010 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//

#ifndef STREAMS_BOOST_ASIO_DETAIL_EPOLL_REACTOR_FWD_HPP
#define STREAMS_BOOST_ASIO_DETAIL_EPOLL_REACTOR_FWD_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <streams_boost/asio/detail/push_options.hpp>

#if !defined(STREAMS_BOOST_ASIO_DISABLE_EPOLL)
#if defined(__linux__) // This service is only supported on Linux.

#include <streams_boost/asio/detail/push_options.hpp>
#include <linux/version.h>
#include <streams_boost/asio/detail/pop_options.hpp>

#if LINUX_VERSION_CODE >= KERNEL_VERSION (2,5,45) // Only kernels >= 2.5.45.

// Define this to indicate that epoll is supported on the target platform.
#define STREAMS_BOOST_ASIO_HAS_EPOLL 1

namespace streams_boost {
namespace asio {
namespace detail {

template <bool Own_Thread>
class epoll_reactor;

} // namespace detail
} // namespace asio
} // namespace streams_boost

#endif // LINUX_VERSION_CODE >= KERNEL_VERSION (2,5,45)
#endif // defined(__linux__)
#endif // !defined(STREAMS_BOOST_ASIO_DISABLE_EPOLL)

#include <streams_boost/asio/detail/pop_options.hpp>

#endif // STREAMS_BOOST_ASIO_DETAIL_EPOLL_REACTOR_FWD_HPP
