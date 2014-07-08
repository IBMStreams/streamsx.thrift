//
// descriptor_base.hpp
// ~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2010 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//

#ifndef STREAMS_BOOST_ASIO_POSIX_DESCRIPTOR_BASE_STREAMS_HPP
#define STREAMS_BOOST_ASIO_POSIX_DESCRIPTOR_BASE_STREAMS_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <streams_boost/asio/detail/push_options.hpp>

#include <streams_boost/asio/detail/push_options.hpp>
#include <streams_boost/config.hpp>
#include <streams_boost/detail/workaround.hpp>
#include <streams_boost/asio/detail/pop_options.hpp>

#include <streams_boost/asio/detail/io_control.hpp>
#include <streams_boost/asio/detail/socket_option.hpp>

namespace streams_boost {
namespace asio {
namespace posix {

/// The descriptor_base class is used as a base for the basic_stream_descriptor
/// class template so that we have a common place to define the associated
/// IO control commands.
class descriptor_base
{
public:
  /// IO control command to set the blocking mode of the descriptor.
  /**
   * Implements the FIONBIO IO control command.
   *
   * @par Example
   * @code
   * streams_boost::asio::posix::stream_descriptor descriptor(io_service); 
   * ...
   * streams_boost::asio::descriptor_base::non_blocking_io command(true);
   * descriptor.io_control(command);
   * @endcode
   *
   * @par Concepts:
   * IoControlCommand.
   */
#if defined(GENERATING_DOCUMENTATION)
  typedef implementation_defined non_blocking_io;
#else
  typedef streams_boost::asio::detail::io_control::non_blocking_io non_blocking_io;
#endif

  /// IO control command to get the amount of data that can be read without
  /// blocking.
  /**
   * Implements the FIONREAD IO control command.
   *
   * @par Example
   * @code
   * streams_boost::asio::posix::stream_descriptor descriptor(io_service); 
   * ...
   * streams_boost::asio::descriptor_base::bytes_readable command(true);
   * descriptor.io_control(command);
   * std::size_t bytes_readable = command.get();
   * @endcode
   *
   * @par Concepts:
   * IoControlCommand.
   */
#if defined(GENERATING_DOCUMENTATION)
  typedef implementation_defined bytes_readable;
#else
  typedef streams_boost::asio::detail::io_control::bytes_readable bytes_readable;
#endif

protected:
  /// Protected destructor to prevent deletion through this type.
  ~descriptor_base()
  {
  }
};

} // namespace posix
} // namespace asio
} // namespace streams_boost

#include <streams_boost/asio/detail/pop_options.hpp>

#endif // STREAMS_BOOST_ASIO_POSIX_DESCRIPTOR_BASE_STREAMS_HPP
