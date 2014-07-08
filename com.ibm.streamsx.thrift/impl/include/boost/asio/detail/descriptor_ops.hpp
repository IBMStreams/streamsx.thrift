//
// descriptor_ops.hpp
// ~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2010 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//

#ifndef STREAMS_BOOST_ASIO_DETAIL_DESCRIPTOR_OPS_HPP
#define STREAMS_BOOST_ASIO_DETAIL_DESCRIPTOR_OPS_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <streams_boost/asio/detail/push_options.hpp>

#include <streams_boost/asio/detail/push_options.hpp>
#include <streams_boost/config.hpp>
#include <cerrno>
#include <streams_boost/asio/detail/pop_options.hpp>

#include <streams_boost/asio/error.hpp>
#include <streams_boost/asio/detail/socket_types.hpp>

#if !defined(STREAMS_BOOST_WINDOWS) && !defined(__CYGWIN__)

namespace streams_boost {
namespace asio {
namespace detail {
namespace descriptor_ops {

inline void clear_error(streams_boost::system::error_code& ec)
{
  errno = 0;
  ec = streams_boost::system::error_code();
}

template <typename ReturnType>
inline ReturnType error_wrapper(ReturnType return_value,
    streams_boost::system::error_code& ec)
{
  ec = streams_boost::system::error_code(errno,
      streams_boost::asio::error::get_system_category());
  return return_value;
}

inline int open(const char* path, int flags, streams_boost::system::error_code& ec)
{
  clear_error(ec);
  int result = error_wrapper(::open(path, flags), ec);
  if (result >= 0)
    clear_error(ec);
  return result;
}

inline int close(int d, streams_boost::system::error_code& ec)
{
  clear_error(ec);
  int result = error_wrapper(::close(d), ec);
  if (result == 0)
    clear_error(ec);
  return result;
}

inline void init_buf_iov_base(void*& base, void* addr)
{
  base = addr;
}

template <typename T>
inline void init_buf_iov_base(T& base, void* addr)
{
  base = static_cast<T>(addr);
}

typedef iovec buf;

inline void init_buf(buf& b, void* data, size_t size)
{
  init_buf_iov_base(b.iov_base, data);
  b.iov_len = size;
}

inline void init_buf(buf& b, const void* data, size_t size)
{
  init_buf_iov_base(b.iov_base, const_cast<void*>(data));
  b.iov_len = size;
}

inline int scatter_read(int d, buf* bufs, size_t count,
    streams_boost::system::error_code& ec)
{
  clear_error(ec);
  int result = error_wrapper(::readv(d, bufs, static_cast<int>(count)), ec);
  if (result >= 0)
    clear_error(ec);
  return result;
}

inline int gather_write(int d, const buf* bufs, size_t count,
    streams_boost::system::error_code& ec)
{
  clear_error(ec);
  int result = error_wrapper(::writev(d, bufs, static_cast<int>(count)), ec);
  if (result >= 0)
    clear_error(ec);
  return result;
}

inline int ioctl(int d, long cmd, ioctl_arg_type* arg,
    streams_boost::system::error_code& ec)
{
  clear_error(ec);
  int result = error_wrapper(::ioctl(d, cmd, arg), ec);
  if (result >= 0)
    clear_error(ec);
  return result;
}

inline int fcntl(int d, long cmd, streams_boost::system::error_code& ec)
{
  clear_error(ec);
  int result = error_wrapper(::fcntl(d, cmd), ec);
  if (result != -1)
    clear_error(ec);
  return result;
}

inline int fcntl(int d, long cmd, long arg, streams_boost::system::error_code& ec)
{
  clear_error(ec);
  int result = error_wrapper(::fcntl(d, cmd, arg), ec);
  if (result != -1)
    clear_error(ec);
  return result;
}

inline int poll_read(int d, streams_boost::system::error_code& ec)
{
  clear_error(ec);
  pollfd fds;
  fds.fd = d;
  fds.events = POLLIN;
  fds.revents = 0;
  clear_error(ec);
  int result = error_wrapper(::poll(&fds, 1, -1), ec);
  if (result >= 0)
    clear_error(ec);
  return result;
}

inline int poll_write(int d, streams_boost::system::error_code& ec)
{
  clear_error(ec);
  pollfd fds;
  fds.fd = d;
  fds.events = POLLOUT;
  fds.revents = 0;
  clear_error(ec);
  int result = error_wrapper(::poll(&fds, 1, -1), ec);
  if (result >= 0)
    clear_error(ec);
  return result;
}

} // namespace descriptor_ops
} // namespace detail
} // namespace asio
} // namespace streams_boost

#endif // !defined(STREAMS_BOOST_WINDOWS) && !defined(__CYGWIN__)

#include <streams_boost/asio/detail/pop_options.hpp>

#endif // STREAMS_BOOST_ASIO_DETAIL_DESCRIPTOR_OPS_HPP
