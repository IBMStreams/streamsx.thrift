//
// connect_pair.hpp
// ~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2010 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//

#ifndef STREAMS_BOOST_ASIO_LOCAL_CONNECT_PAIR_HPP
#define STREAMS_BOOST_ASIO_LOCAL_CONNECT_PAIR_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <streams_boost/asio/detail/push_options.hpp>

#include <streams_boost/asio/basic_socket.hpp>
#include <streams_boost/asio/error.hpp>
#include <streams_boost/asio/local/basic_endpoint.hpp>
#include <streams_boost/asio/detail/socket_ops.hpp>
#include <streams_boost/asio/detail/throw_error.hpp>

#if defined(STREAMS_BOOST_ASIO_HAS_LOCAL_SOCKETS) \
  || defined(GENERATING_DOCUMENTATION)

namespace streams_boost {
namespace asio {
namespace local {

/// Create a pair of connected sockets.
template <typename Protocol, typename SocketService1, typename SocketService2>
void connect_pair(
    basic_socket<Protocol, SocketService1>& socket1,
    basic_socket<Protocol, SocketService2>& socket2);

/// Create a pair of connected sockets.
template <typename Protocol, typename SocketService1, typename SocketService2>
streams_boost::system::error_code connect_pair(
    basic_socket<Protocol, SocketService1>& socket1,
    basic_socket<Protocol, SocketService2>& socket2,
    streams_boost::system::error_code& ec);

template <typename Protocol, typename SocketService1, typename SocketService2>
inline void connect_pair(
    basic_socket<Protocol, SocketService1>& socket1,
    basic_socket<Protocol, SocketService2>& socket2)
{
  streams_boost::system::error_code ec;
  connect_pair(socket1, socket2, ec);
  streams_boost::asio::detail::throw_error(ec);
}

template <typename Protocol, typename SocketService1, typename SocketService2>
inline streams_boost::system::error_code connect_pair(
    basic_socket<Protocol, SocketService1>& socket1,
    basic_socket<Protocol, SocketService2>& socket2,
    streams_boost::system::error_code& ec)
{
  // Check that this function is only being used with a UNIX domain socket.
  streams_boost::asio::local::basic_endpoint<Protocol>* tmp
    = static_cast<typename Protocol::endpoint*>(0);
  (void)tmp;

  Protocol protocol;
  streams_boost::asio::detail::socket_type sv[2];
  if (streams_boost::asio::detail::socket_ops::socketpair(protocol.family(),
        protocol.type(), protocol.protocol(), sv, ec)
      == streams_boost::asio::detail::socket_error_retval)
    return ec;

  if (socket1.assign(protocol, sv[0], ec))
  {
    streams_boost::system::error_code temp_ec;
    streams_boost::asio::detail::socket_ops::close(sv[0], temp_ec);
    streams_boost::asio::detail::socket_ops::close(sv[1], temp_ec);
    return ec;
  }

  if (socket2.assign(protocol, sv[1], ec))
  {
    streams_boost::system::error_code temp_ec;
    socket1.close(temp_ec);
    streams_boost::asio::detail::socket_ops::close(sv[1], temp_ec);
    return ec;
  }

  return ec;
}

} // namespace local
} // namespace asio
} // namespace streams_boost

#endif // defined(STREAMS_BOOST_ASIO_HAS_LOCAL_SOCKETS)
       //   || defined(GENERATING_DOCUMENTATION)

#include <streams_boost/asio/detail/pop_options.hpp>

#endif // STREAMS_BOOST_ASIO_LOCAL_CONNECT_PAIR_HPP
