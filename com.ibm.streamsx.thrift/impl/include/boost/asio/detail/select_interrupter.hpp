//
// select_interrupter.hpp
// ~~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2010 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//

#ifndef STREAMS_BOOST_ASIO_DETAIL_SELECT_INTERRUPTER_HPP
#define STREAMS_BOOST_ASIO_DETAIL_SELECT_INTERRUPTER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <streams_boost/asio/detail/push_options.hpp>

#include <streams_boost/asio/detail/push_options.hpp>
#include <streams_boost/config.hpp>
#include <streams_boost/asio/detail/pop_options.hpp>

#if defined(STREAMS_BOOST_WINDOWS) || defined(__CYGWIN__)
# include <streams_boost/asio/detail/socket_select_interrupter.hpp>
#else
# include <streams_boost/asio/detail/eventfd_select_interrupter.hpp>
# include <streams_boost/asio/detail/pipe_select_interrupter.hpp>
#endif

namespace streams_boost {
namespace asio {
namespace detail {

#if defined(STREAMS_BOOST_WINDOWS) || defined(__CYGWIN__)
typedef socket_select_interrupter select_interrupter;
#elif defined(STREAMS_BOOST_ASIO_HAS_EVENTFD)
typedef eventfd_select_interrupter select_interrupter;
#else
typedef pipe_select_interrupter select_interrupter;
#endif

} // namespace detail
} // namespace asio
} // namespace streams_boost

#include <streams_boost/asio/detail/pop_options.hpp>

#endif // STREAMS_BOOST_ASIO_DETAIL_SELECT_INTERRUPTER_HPP
