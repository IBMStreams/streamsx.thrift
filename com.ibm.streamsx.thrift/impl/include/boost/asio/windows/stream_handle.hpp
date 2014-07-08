//
// stream_handle.hpp
// ~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2010 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//

#ifndef STREAMS_BOOST_ASIO_WINDOWS_STREAM_HANDLE_HPP
#define STREAMS_BOOST_ASIO_WINDOWS_STREAM_HANDLE_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <streams_boost/asio/detail/push_options.hpp>

#include <streams_boost/asio/windows/basic_stream_handle.hpp>

#if defined(STREAMS_BOOST_ASIO_HAS_WINDOWS_STREAM_HANDLE) \
  || defined(GENERATING_DOCUMENTATION)

namespace streams_boost {
namespace asio {
namespace windows {

/// Typedef for the typical usage of a stream-oriented handle.
typedef basic_stream_handle<> stream_handle;

} // namespace windows
} // namespace asio
} // namespace streams_boost

#endif // defined(STREAMS_BOOST_ASIO_HAS_WINDOWS_STREAM_HANDLE)
       //   || defined(GENERATING_DOCUMENTATION)

#include <streams_boost/asio/detail/pop_options.hpp>

#endif // STREAMS_BOOST_ASIO_WINDOWS_STREAM_HANDLE_HPP
