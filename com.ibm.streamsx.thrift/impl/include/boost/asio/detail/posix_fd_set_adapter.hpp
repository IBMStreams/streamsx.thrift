//
// posix_fd_set_adapter.hpp
// ~~~~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2010 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//

#ifndef STREAMS_BOOST_ASIO_DETAIL_POSIX_FD_SET_ADAPTER_STREAMS_HPP
#define STREAMS_BOOST_ASIO_DETAIL_POSIX_FD_SET_ADAPTER_STREAMS_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <streams_boost/asio/detail/push_options.hpp>

#include <streams_boost/asio/detail/push_options.hpp>
#include <cstring>
#include <streams_boost/asio/detail/pop_options.hpp>

#include <streams_boost/asio/detail/socket_types.hpp>

#if !defined(STREAMS_BOOST_WINDOWS) && !defined(__CYGWIN__)

namespace streams_boost {
namespace asio {
namespace detail {

// Adapts the FD_SET type to meet the Descriptor_Set concept's requirements.
class posix_fd_set_adapter
{
public:
  posix_fd_set_adapter()
    : max_descriptor_(invalid_socket)
  {
    using namespace std; // Needed for memset on Solaris.
    FD_ZERO(&fd_set_);
  }

  bool set(socket_type descriptor)
  {
    if (descriptor < (socket_type)FD_SETSIZE)
    {
      if (max_descriptor_ == invalid_socket || descriptor > max_descriptor_)
        max_descriptor_ = descriptor;
      FD_SET(descriptor, &fd_set_);
      return true;
    }
    return false;
  }

  bool is_set(socket_type descriptor) const
  {
    return FD_ISSET(descriptor, &fd_set_) != 0;
  }

  operator fd_set*()
  {
    return &fd_set_;
  }

  socket_type max_descriptor() const
  {
    return max_descriptor_;
  }

private:
  mutable fd_set fd_set_;
  socket_type max_descriptor_;
};

} // namespace detail
} // namespace asio
} // namespace streams_boost

#endif // !defined(STREAMS_BOOST_WINDOWS) && !defined(__CYGWIN__)

#include <streams_boost/asio/detail/pop_options.hpp>

#endif // STREAMS_BOOST_ASIO_DETAIL_POSIX_FD_SET_ADAPTER_STREAMS_HPP