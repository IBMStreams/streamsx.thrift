//
// winsock_init.hpp
// ~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2010 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//

#ifndef STREAMS_BOOST_ASIO_DETAIL_WINSOCK_INIT_HPP
#define STREAMS_BOOST_ASIO_DETAIL_WINSOCK_INIT_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <streams_boost/asio/detail/push_options.hpp>

#include <streams_boost/asio/detail/push_options.hpp>
#include <streams_boost/config.hpp>
#include <streams_boost/system/system_error.hpp>
#include <streams_boost/asio/detail/pop_options.hpp>

#if defined(STREAMS_BOOST_WINDOWS) || defined(__CYGWIN__)

#include <streams_boost/asio/detail/push_options.hpp>
#include <streams_boost/shared_ptr.hpp>
#include <streams_boost/throw_exception.hpp>
#include <streams_boost/asio/detail/pop_options.hpp>

#include <streams_boost/asio/error.hpp>
#include <streams_boost/asio/detail/noncopyable.hpp>
#include <streams_boost/asio/detail/socket_types.hpp>

namespace streams_boost {
namespace asio {
namespace detail {

template <int Major = 2, int Minor = 0>
class winsock_init
  : private noncopyable
{
private:
  // Structure to perform the actual initialisation.
  struct do_init
  {
    do_init()
    {
      WSADATA wsa_data;
      result_ = ::WSAStartup(MAKEWORD(Major, Minor), &wsa_data);
    }

    ~do_init()
    {
      ::WSACleanup();
    }

    int result() const
    {
      return result_;
    }

    // Helper function to manage a do_init singleton. The static instance of the
    // winsock_init object ensures that this function is always called before
    // main, and therefore before any other threads can get started. The do_init
    // instance must be static in this function to ensure that it gets
    // initialised before any other global objects try to use it.
    static streams_boost::shared_ptr<do_init> instance()
    {
      static streams_boost::shared_ptr<do_init> init(new do_init);
      return init;
    }

  private:
    int result_;
  };

public:
  // Constructor.
  winsock_init()
    : ref_(do_init::instance())
  {
    // Check whether winsock was successfully initialised. This check is not
    // performed for the global instance since there will be nobody around to
    // catch the exception.
    if (this != &instance_ && ref_->result() != 0)
    {
      streams_boost::system::system_error e(
          streams_boost::system::error_code(ref_->result(),
            streams_boost::asio::error::get_system_category()),
          "winsock");
      streams_boost::throw_exception(e);
    }
  }

  // Destructor.
  ~winsock_init()
  {
  }

private:
  // Instance to force initialisation of winsock at global scope.
  static winsock_init instance_;

  // Reference to singleton do_init object to ensure that winsock does not get
  // cleaned up until the last user has finished with it.
  streams_boost::shared_ptr<do_init> ref_;
};

template <int Major, int Minor>
winsock_init<Major, Minor> winsock_init<Major, Minor>::instance_;

} // namespace detail
} // namespace asio
} // namespace streams_boost

#endif // defined(STREAMS_BOOST_WINDOWS) || defined(__CYGWIN__)

#include <streams_boost/asio/detail/pop_options.hpp>

#endif // STREAMS_BOOST_ASIO_DETAIL_WINSOCK_INIT_HPP
