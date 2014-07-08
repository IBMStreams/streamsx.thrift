//
// unicast.hpp
// ~~~~~~~~~~~
//
// Copyright (c) 2003-2010 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//

#ifndef STREAMS_BOOST_ASIO_IP_UNICAST_HPP
#define STREAMS_BOOST_ASIO_IP_UNICAST_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <streams_boost/asio/detail/push_options.hpp>

#include <streams_boost/asio/detail/push_options.hpp>
#include <cstddef>
#include <streams_boost/config.hpp>
#include <streams_boost/asio/detail/pop_options.hpp>

#include <streams_boost/asio/ip/detail/socket_option.hpp>

namespace streams_boost {
namespace asio {
namespace ip {
namespace unicast {

/// Socket option for time-to-live associated with outgoing unicast packets.
/**
 * Implements the IPPROTO_IP/IP_UNICAST_TTL socket option.
 *
 * @par Examples
 * Setting the option:
 * @code
 * streams_boost::asio::ip::udp::socket socket(io_service); 
 * ...
 * streams_boost::asio::ip::unicast::hops option(4);
 * socket.set_option(option);
 * @endcode
 *
 * @par
 * Getting the current option value:
 * @code
 * streams_boost::asio::ip::udp::socket socket(io_service); 
 * ...
 * streams_boost::asio::ip::unicast::hops option;
 * socket.get_option(option);
 * int ttl = option.value();
 * @endcode
 *
 * @par Concepts:
 * GettableSocketOption, SettableSocketOption.
 */
#if defined(GENERATING_DOCUMENTATION)
typedef implementation_defined hops;
#else
typedef streams_boost::asio::ip::detail::socket_option::unicast_hops<
  IPPROTO_IP, IP_TTL, IPPROTO_IPV6, IPV6_UNICAST_HOPS> hops;
#endif

} // namespace unicast
} // namespace ip
} // namespace asio
} // namespace streams_boost

#include <streams_boost/asio/detail/pop_options.hpp>

#endif // STREAMS_BOOST_ASIO_IP_UNICAST_HPP
