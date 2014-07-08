//
// serial_port_base.hpp
// ~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2010 Christopher M. Kohlhoff (chris at kohlhoff dot com)
// Copyright (c) 2008 Rep Invariant Systems, Inc. (info@repinvariant.com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//

#ifndef STREAMS_BOOST_ASIO_SERIAL_PORT_BASE_HPP
#define STREAMS_BOOST_ASIO_SERIAL_PORT_BASE_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <streams_boost/asio/detail/push_options.hpp>

#include <streams_boost/asio/detail/push_options.hpp>
#include <stdexcept>
#include <streams_boost/config.hpp>
#include <streams_boost/detail/workaround.hpp>
#include <streams_boost/system/error_code.hpp>
#include <streams_boost/asio/detail/pop_options.hpp>

#if !defined(STREAMS_BOOST_ASIO_DISABLE_SERIAL_PORT)
# if defined(STREAMS_BOOST_ASIO_HAS_IOCP) \
    || !defined(STREAMS_BOOST_WINDOWS) && !defined(__CYGWIN__)
#  define STREAMS_BOOST_ASIO_HAS_SERIAL_PORT 1
# endif // defined(STREAMS_BOOST_ASIO_HAS_IOCP)
#endif // !defined(STREAMS_BOOST_ASIO_DISABLE_STREAM_HANDLE)

#if defined(STREAMS_BOOST_ASIO_HAS_SERIAL_PORT) \
  || defined(GENERATING_DOCUMENTATION)

#if !defined(STREAMS_BOOST_WINDOWS) && !defined(__CYGWIN__)
# include <streams_boost/asio/detail/push_options.hpp>
# include <termios.h>
# include <streams_boost/asio/detail/pop_options.hpp>
#endif // !defined(STREAMS_BOOST_WINDOWS) && !defined(__CYGWIN__)

#include <streams_boost/asio/detail/socket_types.hpp>

#if defined(GENERATING_DOCUMENTATION)
# define STREAMS_BOOST_ASIO_OPTION_STORAGE implementation_defined
#elif defined(STREAMS_BOOST_WINDOWS) || defined(__CYGWIN__)
# define STREAMS_BOOST_ASIO_OPTION_STORAGE DCB
#else
# define STREAMS_BOOST_ASIO_OPTION_STORAGE termios
#endif

namespace streams_boost {
namespace asio {

/// The serial_port_base class is used as a base for the basic_serial_port class
/// template so that we have a common place to define the serial port options.
class serial_port_base
{
public:
  /// Serial port option to permit changing the baud rate.
  /**
   * Implements changing the baud rate for a given serial port.
   */
  class baud_rate
  {
  public:
    explicit baud_rate(unsigned int rate = 0);
    unsigned int value() const;
    streams_boost::system::error_code store(STREAMS_BOOST_ASIO_OPTION_STORAGE& storage,
        streams_boost::system::error_code& ec) const;
    streams_boost::system::error_code load(const STREAMS_BOOST_ASIO_OPTION_STORAGE& storage,
        streams_boost::system::error_code& ec);
  private:
    unsigned int value_;
  };

  /// Serial port option to permit changing the flow control.
  /**
   * Implements changing the flow control for a given serial port.
   */
  class flow_control
  {
  public:
    enum type { none, software, hardware };
    explicit flow_control(type t = none);
    type value() const;
    streams_boost::system::error_code store(STREAMS_BOOST_ASIO_OPTION_STORAGE& storage,
        streams_boost::system::error_code& ec) const;
    streams_boost::system::error_code load(const STREAMS_BOOST_ASIO_OPTION_STORAGE& storage,
        streams_boost::system::error_code& ec);
  private:
    type value_;
  };

  /// Serial port option to permit changing the parity.
  /**
   * Implements changing the parity for a given serial port.
   */
  class parity
  {
  public:
    enum type { none, odd, even };
    explicit parity(type t = none);
    type value() const;
    streams_boost::system::error_code store(STREAMS_BOOST_ASIO_OPTION_STORAGE& storage,
        streams_boost::system::error_code& ec) const;
    streams_boost::system::error_code load(const STREAMS_BOOST_ASIO_OPTION_STORAGE& storage,
        streams_boost::system::error_code& ec);
  private:
    type value_;
  };

  /// Serial port option to permit changing the number of stop bits.
  /**
   * Implements changing the number of stop bits for a given serial port.
   */
  class stop_bits
  {
  public:
    enum type { one, onepointfive, two };
    explicit stop_bits(type t = one);
    type value() const;
    streams_boost::system::error_code store(STREAMS_BOOST_ASIO_OPTION_STORAGE& storage,
        streams_boost::system::error_code& ec) const;
    streams_boost::system::error_code load(const STREAMS_BOOST_ASIO_OPTION_STORAGE& storage,
        streams_boost::system::error_code& ec);
  private:
    type value_;
  };

  /// Serial port option to permit changing the character size.
  /**
   * Implements changing the character size for a given serial port.
   */
  class character_size
  {
  public:
    explicit character_size(unsigned int t = 8);
    unsigned int value() const;
    streams_boost::system::error_code store(STREAMS_BOOST_ASIO_OPTION_STORAGE& storage,
        streams_boost::system::error_code& ec) const;
    streams_boost::system::error_code load(const STREAMS_BOOST_ASIO_OPTION_STORAGE& storage,
        streams_boost::system::error_code& ec);
  private:
    unsigned int value_;
  };

protected:
  /// Protected destructor to prevent deletion through this type.
  ~serial_port_base()
  {
  }

#if STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x564))
private:
  // Workaround to enable the empty base optimisation with Borland C++.
  char dummy_;
#endif
};

} // namespace asio
} // namespace streams_boost

#include <streams_boost/asio/impl/serial_port_base.ipp>

#undef STREAMS_BOOST_ASIO_OPTION_STORAGE

#endif // defined(STREAMS_BOOST_ASIO_HAS_SERIAL_PORT)
       //   || defined(GENERATING_DOCUMENTATION)

#include <streams_boost/asio/detail/pop_options.hpp>

#endif // STREAMS_BOOST_ASIO_SERIAL_PORT_BASE_HPP
