//
// stream_base.hpp
// ~~~~~~~~~~~~~~~
//
// Copyright (c) 2005-2010 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//

#ifndef STREAMS_BOOST_ASIO_SSL_STREAM_BASE_HPP
#define STREAMS_BOOST_ASIO_SSL_STREAM_BASE_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <streams_boost/asio/detail/push_options.hpp>

#include <streams_boost/asio/detail/push_options.hpp>
#include <streams_boost/detail/workaround.hpp>
#include <streams_boost/asio/detail/pop_options.hpp>

namespace streams_boost {
namespace asio {
namespace ssl {

/// The stream_base class is used as a base for the streams_boost::asio::ssl::stream
/// class template so that we have a common place to define various enums.
class stream_base
{
public:
  /// Different handshake types.
  enum handshake_type
  {
    /// Perform handshaking as a client.
    client,

    /// Perform handshaking as a server.
    server
  };

protected:
  /// Protected destructor to prevent deletion through this type.
  ~stream_base()
  {
  }

#if STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x564))
private:
  // Workaround to enable the empty base optimisation with Borland C++.
  char dummy_;
#endif
};

} // namespace ssl
} // namespace asio
} // namespace streams_boost

#include <streams_boost/asio/detail/pop_options.hpp>

#endif // STREAMS_BOOST_ASIO_SSL_STREAM_BASE_HPP
