//
// error.hpp
// ~~~~~~~~~
//
// Copyright (c) 2003-2010 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//

#ifndef STREAMS_BOOST_ASIO_ERROR_HPP
#define STREAMS_BOOST_ASIO_ERROR_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <streams_boost/asio/detail/push_options.hpp>

#include <streams_boost/asio/detail/push_options.hpp>
#include <streams_boost/config.hpp>
#include <streams_boost/cerrno.hpp>
#include <streams_boost/system/error_code.hpp>
#include <streams_boost/asio/detail/pop_options.hpp>

#include <streams_boost/asio/detail/socket_types.hpp>

#if defined(GENERATING_DOCUMENTATION)
/// INTERNAL ONLY.
# define STREAMS_BOOST_ASIO_NATIVE_ERROR(e) implementation_defined
/// INTERNAL ONLY.
# define STREAMS_BOOST_ASIO_SOCKET_ERROR(e) implementation_defined
/// INTERNAL ONLY.
# define STREAMS_BOOST_ASIO_NETDB_ERROR(e) implementation_defined
/// INTERNAL ONLY.
# define STREAMS_BOOST_ASIO_GETADDRINFO_ERROR(e) implementation_defined
/// INTERNAL ONLY.
# define STREAMS_BOOST_ASIO_WIN_OR_POSIX(e_win, e_posix) implementation_defined
#elif defined(STREAMS_BOOST_WINDOWS) || defined(__CYGWIN__)
# define STREAMS_BOOST_ASIO_NATIVE_ERROR(e) e
# define STREAMS_BOOST_ASIO_SOCKET_ERROR(e) WSA ## e
# define STREAMS_BOOST_ASIO_NETDB_ERROR(e) WSA ## e
# define STREAMS_BOOST_ASIO_GETADDRINFO_ERROR(e) WSA ## e
# define STREAMS_BOOST_ASIO_WIN_OR_POSIX(e_win, e_posix) e_win
#else
# define STREAMS_BOOST_ASIO_NATIVE_ERROR(e) e
# define STREAMS_BOOST_ASIO_SOCKET_ERROR(e) e
# define STREAMS_BOOST_ASIO_NETDB_ERROR(e) e
# define STREAMS_BOOST_ASIO_GETADDRINFO_ERROR(e) e
# define STREAMS_BOOST_ASIO_WIN_OR_POSIX(e_win, e_posix) e_posix
#endif

namespace streams_boost {
namespace asio {
namespace error {

enum basic_errors
{
  /// Permission denied.
  access_denied = STREAMS_BOOST_ASIO_SOCKET_ERROR(EACCES),

  /// Address family not supported by protocol.
  address_family_not_supported = STREAMS_BOOST_ASIO_SOCKET_ERROR(EAFNOSUPPORT),

  /// Address already in use.
  address_in_use = STREAMS_BOOST_ASIO_SOCKET_ERROR(EADDRINUSE),

  /// Transport endpoint is already connected.
  already_connected = STREAMS_BOOST_ASIO_SOCKET_ERROR(EISCONN),

  /// Operation already in progress.
  already_started = STREAMS_BOOST_ASIO_SOCKET_ERROR(EALREADY),

  /// Broken pipe.
  broken_pipe = STREAMS_BOOST_ASIO_WIN_OR_POSIX(
      STREAMS_BOOST_ASIO_NATIVE_ERROR(ERROR_BROKEN_PIPE),
      STREAMS_BOOST_ASIO_NATIVE_ERROR(EPIPE)),

  /// A connection has been aborted.
  connection_aborted = STREAMS_BOOST_ASIO_SOCKET_ERROR(ECONNABORTED),

  /// Connection refused.
  connection_refused = STREAMS_BOOST_ASIO_SOCKET_ERROR(ECONNREFUSED),

  /// Connection reset by peer.
  connection_reset = STREAMS_BOOST_ASIO_SOCKET_ERROR(ECONNRESET),

  /// Bad file descriptor.
  bad_descriptor = STREAMS_BOOST_ASIO_SOCKET_ERROR(EBADF),

  /// Bad address.
  fault = STREAMS_BOOST_ASIO_SOCKET_ERROR(EFAULT),

  /// No route to host.
  host_unreachable = STREAMS_BOOST_ASIO_SOCKET_ERROR(EHOSTUNREACH),

  /// Operation now in progress.
  in_progress = STREAMS_BOOST_ASIO_SOCKET_ERROR(EINPROGRESS),

  /// Interrupted system call.
  interrupted = STREAMS_BOOST_ASIO_SOCKET_ERROR(EINTR),

  /// Invalid argument.
  invalid_argument = STREAMS_BOOST_ASIO_SOCKET_ERROR(EINVAL),

  /// Message too long.
  message_size = STREAMS_BOOST_ASIO_SOCKET_ERROR(EMSGSIZE),

  /// The name was too long.
  name_too_long = STREAMS_BOOST_ASIO_SOCKET_ERROR(ENAMETOOLONG),

  /// Network is down.
  network_down = STREAMS_BOOST_ASIO_SOCKET_ERROR(ENETDOWN),

  /// Network dropped connection on reset.
  network_reset = STREAMS_BOOST_ASIO_SOCKET_ERROR(ENETRESET),

  /// Network is unreachable.
  network_unreachable = STREAMS_BOOST_ASIO_SOCKET_ERROR(ENETUNREACH),

  /// Too many open files.
  no_descriptors = STREAMS_BOOST_ASIO_SOCKET_ERROR(EMFILE),

  /// No buffer space available.
  no_buffer_space = STREAMS_BOOST_ASIO_SOCKET_ERROR(ENOBUFS),

  /// Cannot allocate memory.
  no_memory = STREAMS_BOOST_ASIO_WIN_OR_POSIX(
      STREAMS_BOOST_ASIO_NATIVE_ERROR(ERROR_OUTOFMEMORY),
      STREAMS_BOOST_ASIO_NATIVE_ERROR(ENOMEM)),

  /// Operation not permitted.
  no_permission = STREAMS_BOOST_ASIO_WIN_OR_POSIX(
      STREAMS_BOOST_ASIO_NATIVE_ERROR(ERROR_ACCESS_DENIED),
      STREAMS_BOOST_ASIO_NATIVE_ERROR(EPERM)),

  /// Protocol not available.
  no_protocol_option = STREAMS_BOOST_ASIO_SOCKET_ERROR(ENOPROTOOPT),

  /// Transport endpoint is not connected.
  not_connected = STREAMS_BOOST_ASIO_SOCKET_ERROR(ENOTCONN),

  /// Socket operation on non-socket.
  not_socket = STREAMS_BOOST_ASIO_SOCKET_ERROR(ENOTSOCK),

  /// Operation cancelled.
  operation_aborted = STREAMS_BOOST_ASIO_WIN_OR_POSIX(
      STREAMS_BOOST_ASIO_NATIVE_ERROR(ERROR_OPERATION_ABORTED),
      STREAMS_BOOST_ASIO_NATIVE_ERROR(ECANCELED)),

  /// Operation not supported.
  operation_not_supported = STREAMS_BOOST_ASIO_SOCKET_ERROR(EOPNOTSUPP),

  /// Cannot send after transport endpoint shutdown.
  shut_down = STREAMS_BOOST_ASIO_SOCKET_ERROR(ESHUTDOWN),

  /// Connection timed out.
  timed_out = STREAMS_BOOST_ASIO_SOCKET_ERROR(ETIMEDOUT),

  /// Resource temporarily unavailable.
  try_again = STREAMS_BOOST_ASIO_WIN_OR_POSIX(
      STREAMS_BOOST_ASIO_NATIVE_ERROR(ERROR_RETRY),
      STREAMS_BOOST_ASIO_NATIVE_ERROR(EAGAIN)),

  /// The socket is marked non-blocking and the requested operation would block.
  would_block = STREAMS_BOOST_ASIO_SOCKET_ERROR(EWOULDBLOCK)
};

enum netdb_errors
{
  /// Host not found (authoritative).
  host_not_found = STREAMS_BOOST_ASIO_NETDB_ERROR(HOST_NOT_FOUND),

  /// Host not found (non-authoritative).
  host_not_found_try_again = STREAMS_BOOST_ASIO_NETDB_ERROR(TRY_AGAIN),

  /// The query is valid but does not have associated address data.
  no_data = STREAMS_BOOST_ASIO_NETDB_ERROR(NO_DATA),

  /// A non-recoverable error occurred.
  no_recovery = STREAMS_BOOST_ASIO_NETDB_ERROR(NO_RECOVERY)
};

enum addrinfo_errors
{
  /// The service is not supported for the given socket type.
  service_not_found = STREAMS_BOOST_ASIO_WIN_OR_POSIX(
      STREAMS_BOOST_ASIO_NATIVE_ERROR(WSATYPE_NOT_FOUND),
      STREAMS_BOOST_ASIO_GETADDRINFO_ERROR(EAI_SERVICE)),

  /// The socket type is not supported.
  socket_type_not_supported = STREAMS_BOOST_ASIO_WIN_OR_POSIX(
      STREAMS_BOOST_ASIO_NATIVE_ERROR(WSAESOCKTNOSUPPORT),
      STREAMS_BOOST_ASIO_GETADDRINFO_ERROR(EAI_SOCKTYPE))
};

enum misc_errors
{
  /// Already open.
  already_open = 1,

  /// End of file or stream.
  eof,

  /// Element not found.
  not_found,

  /// The descriptor cannot fit into the select system call's fd_set.
  fd_set_failure
};

enum ssl_errors
{
};

inline const streams_boost::system::error_category& get_system_category()
{
  return streams_boost::system::get_system_category();
}

#if !defined(STREAMS_BOOST_WINDOWS) && !defined(__CYGWIN__)

namespace detail {

class netdb_category : public streams_boost::system::error_category
{
public:
  const char* name() const
  {
    return "asio.netdb";
  }

  std::string message(int value) const
  {
    if (value == error::host_not_found)
      return "Host not found (authoritative)";
    if (value == error::host_not_found_try_again)
      return "Host not found (non-authoritative), try again later";
    if (value == error::no_data)
      return "The query is valid, but it does not have associated data";
    if (value == error::no_recovery)
      return "A non-recoverable error occurred during database lookup";
    return "asio.netdb error";
  }
};

} // namespace detail

inline const streams_boost::system::error_category& get_netdb_category()
{
  static detail::netdb_category instance;
  return instance;
}

namespace detail {

class addrinfo_category : public streams_boost::system::error_category
{
public:
  const char* name() const
  {
    return "asio.addrinfo";
  }

  std::string message(int value) const
  {
    if (value == error::service_not_found)
      return "Service not found";
    if (value == error::socket_type_not_supported)
      return "Socket type not supported";
    return "asio.addrinfo error";
  }
};

} // namespace detail

inline const streams_boost::system::error_category& get_addrinfo_category()
{
  static detail::addrinfo_category instance;
  return instance;
}

#else // !defined(STREAMS_BOOST_WINDOWS) && !defined(__CYGWIN__)

inline const streams_boost::system::error_category& get_netdb_category()
{
  return get_system_category();
}

inline const streams_boost::system::error_category& get_addrinfo_category()
{
  return get_system_category();
}

#endif // !defined(STREAMS_BOOST_WINDOWS) && !defined(__CYGWIN__)

namespace detail {

class misc_category : public streams_boost::system::error_category
{
public:
  const char* name() const
  {
    return "asio.misc";
  }

  std::string message(int value) const
  {
    if (value == error::already_open)
      return "Already open";
    if (value == error::eof)
      return "End of file";
    if (value == error::not_found)
      return "Element not found";
    if (value == error::fd_set_failure)
      return "The descriptor does not fit into the select call's fd_set";
    return "asio.misc error";
  }
};

} // namespace detail

inline const streams_boost::system::error_category& get_misc_category()
{
  static detail::misc_category instance;
  return instance;
}

namespace detail {

class ssl_category : public streams_boost::system::error_category
{
public:
  const char* name() const
  {
    return "asio.ssl";
  }

  std::string message(int) const
  {
    return "asio.ssl error";
  }
};

} // namespace detail

inline const streams_boost::system::error_category& get_ssl_category()
{
  static detail::ssl_category instance;
  return instance;
}

static const streams_boost::system::error_category& system_category
  = streams_boost::asio::error::get_system_category();
static const streams_boost::system::error_category& netdb_category
  = streams_boost::asio::error::get_netdb_category();
static const streams_boost::system::error_category& addrinfo_category
  = streams_boost::asio::error::get_addrinfo_category();
static const streams_boost::system::error_category& misc_category
  = streams_boost::asio::error::get_misc_category();
static const streams_boost::system::error_category& ssl_category
  = streams_boost::asio::error::get_ssl_category();

} // namespace error
} // namespace asio

namespace system {

template<> struct is_error_code_enum<streams_boost::asio::error::basic_errors>
{
  static const bool value = true;
};

template<> struct is_error_code_enum<streams_boost::asio::error::netdb_errors>
{
  static const bool value = true;
};

template<> struct is_error_code_enum<streams_boost::asio::error::addrinfo_errors>
{
  static const bool value = true;
};

template<> struct is_error_code_enum<streams_boost::asio::error::misc_errors>
{
  static const bool value = true;
};

template<> struct is_error_code_enum<streams_boost::asio::error::ssl_errors>
{
  static const bool value = true;
};

} // namespace system

namespace asio {
namespace error {

inline streams_boost::system::error_code make_error_code(basic_errors e)
{
  return streams_boost::system::error_code(
      static_cast<int>(e), get_system_category());
}

inline streams_boost::system::error_code make_error_code(netdb_errors e)
{
  return streams_boost::system::error_code(
      static_cast<int>(e), get_netdb_category());
}

inline streams_boost::system::error_code make_error_code(addrinfo_errors e)
{
  return streams_boost::system::error_code(
      static_cast<int>(e), get_addrinfo_category());
}

inline streams_boost::system::error_code make_error_code(misc_errors e)
{
  return streams_boost::system::error_code(
      static_cast<int>(e), get_misc_category());
}

inline streams_boost::system::error_code make_error_code(ssl_errors e)
{
  return streams_boost::system::error_code(
      static_cast<int>(e), get_ssl_category());
}

} // namespace error
} // namespace asio
} // namespace streams_boost

#undef STREAMS_BOOST_ASIO_NATIVE_ERROR
#undef STREAMS_BOOST_ASIO_SOCKET_ERROR
#undef STREAMS_BOOST_ASIO_NETDB_ERROR
#undef STREAMS_BOOST_ASIO_GETADDRINFO_ERROR
#undef STREAMS_BOOST_ASIO_WIN_OR_POSIX


#include <streams_boost/asio/detail/pop_options.hpp>

#endif // STREAMS_BOOST_ASIO_ERROR_HPP
