//
// datagram_protocol.hpp
// ~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2010 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//

#ifndef STREAMS_BOOST_ASIO_LOCAL_DATAGRAM_PROTOCOL_HPP
#define STREAMS_BOOST_ASIO_LOCAL_DATAGRAM_PROTOCOL_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <streams_boost/asio/detail/push_options.hpp>

#include <streams_boost/asio/basic_datagram_socket.hpp>
#include <streams_boost/asio/local/basic_endpoint.hpp>
#include <streams_boost/asio/detail/socket_types.hpp>

#if defined(STREAMS_BOOST_ASIO_HAS_LOCAL_SOCKETS) \
  || defined(GENERATING_DOCUMENTATION)

namespace streams_boost {
namespace asio {
namespace local {

/// Encapsulates the flags needed for datagram-oriented UNIX sockets.
/**
 * The streams_boost::asio::local::datagram_protocol class contains flags necessary for
 * datagram-oriented UNIX domain sockets.
 *
 * @par Thread Safety
 * @e Distinct @e objects: Safe.@n
 * @e Shared @e objects: Safe.
 *
 * @par Concepts:
 * Protocol.
 */
class datagram_protocol
{
public:
  /// Obtain an identifier for the type of the protocol.
  int type() const
  {
    return SOCK_DGRAM;
  }

  /// Obtain an identifier for the protocol.
  int protocol() const
  {
    return 0;
  }

  /// Obtain an identifier for the protocol family.
  int family() const
  {
    return AF_UNIX;
  }

  /// The type of a UNIX domain endpoint.
  typedef basic_endpoint<datagram_protocol> endpoint;

  /// The UNIX domain socket type.
  typedef basic_datagram_socket<datagram_protocol> socket;
};

} // namespace local
} // namespace asio
} // namespace streams_boost

#endif // defined(STREAMS_BOOST_ASIO_HAS_LOCAL_SOCKETS)
       //   || defined(GENERATING_DOCUMENTATION)

#include <streams_boost/asio/detail/pop_options.hpp>

#endif // STREAMS_BOOST_ASIO_LOCAL_DATAGRAM_PROTOCOL_HPP
