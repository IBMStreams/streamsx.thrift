//
// host_name.hpp
// ~~~~~~~~~~~~~
//
// Copyright (c) 2003-2010 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//

#ifndef STREAMS_BOOST_ASIO_IP_HOST_NAME_HPP
#define STREAMS_BOOST_ASIO_IP_HOST_NAME_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <streams_boost/asio/detail/push_options.hpp>

#include <streams_boost/asio/detail/push_options.hpp>
#include <string>
#include <streams_boost/asio/detail/pop_options.hpp>

#include <streams_boost/asio/error.hpp>
#include <streams_boost/asio/detail/socket_ops.hpp>
#include <streams_boost/asio/detail/throw_error.hpp>

namespace streams_boost {
namespace asio {
namespace ip {

/// Get the current host name.
std::string host_name();

/// Get the current host name.
std::string host_name(streams_boost::system::error_code& ec);

inline std::string host_name()
{
  char name[1024];
  streams_boost::system::error_code ec;
  if (streams_boost::asio::detail::socket_ops::gethostname(name, sizeof(name), ec) != 0)
  {
    streams_boost::asio::detail::throw_error(ec);
    return std::string();
  }
  return std::string(name);
}

inline std::string host_name(streams_boost::system::error_code& ec)
{
  char name[1024];
  if (streams_boost::asio::detail::socket_ops::gethostname(name, sizeof(name), ec) != 0)
    return std::string();
  return std::string(name);
}

} // namespace ip
} // namespace asio
} // namespace streams_boost

#include <streams_boost/asio/detail/pop_options.hpp>

#endif // STREAMS_BOOST_ASIO_IP_HOST_NAME_HPP
