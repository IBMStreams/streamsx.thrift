//
// local_free_on_block_exit.hpp
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2010 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//

#ifndef STREAMS_BOOST_ASIO_DETAIL_LOCAL_FREE_ON_BLOCK_EXIT_HPP
#define STREAMS_BOOST_ASIO_DETAIL_LOCAL_FREE_ON_BLOCK_EXIT_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <streams_boost/asio/detail/push_options.hpp>

#include <streams_boost/asio/detail/push_options.hpp>
#include <streams_boost/config.hpp>
#include <streams_boost/asio/detail/pop_options.hpp>

#if defined(STREAMS_BOOST_WINDOWS) || defined(__CYGWIN__)

#include <streams_boost/asio/detail/noncopyable.hpp>
#include <streams_boost/asio/detail/socket_types.hpp>

namespace streams_boost {
namespace asio {
namespace detail {

class local_free_on_block_exit
  : private noncopyable
{
public:
  // Constructor blocks all signals for the calling thread.
  explicit local_free_on_block_exit(void* p)
    : p_(p)
  {
  }

  // Destructor restores the previous signal mask.
  ~local_free_on_block_exit()
  {
    ::LocalFree(p_);
  }

private:
  void* p_;
};

} // namespace detail
} // namespace asio
} // namespace streams_boost

#endif // defined(STREAMS_BOOST_WINDOWS) || defined(__CYGWIN__)

#include <streams_boost/asio/detail/pop_options.hpp>

#endif // STREAMS_BOOST_ASIO_DETAIL_LOCAL_FREE_ON_BLOCK_EXIT_HPP
