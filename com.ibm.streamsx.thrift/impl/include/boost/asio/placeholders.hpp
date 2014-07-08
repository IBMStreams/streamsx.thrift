//
// placeholders.hpp
// ~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2010 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//

#ifndef STREAMS_BOOST_ASIO_PLACEHOLDERS_HPP
#define STREAMS_BOOST_ASIO_PLACEHOLDERS_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <streams_boost/asio/detail/push_options.hpp>

#include <streams_boost/asio/detail/push_options.hpp>
#include <streams_boost/bind/arg.hpp>
#include <streams_boost/detail/workaround.hpp>
#include <streams_boost/asio/detail/pop_options.hpp>

namespace streams_boost {
namespace asio {
namespace placeholders {

#if defined(GENERATING_DOCUMENTATION)

/// An argument placeholder, for use with streams_boost::bind(), that corresponds to
/// the error argument of a handler for any of the asynchronous functions.
unspecified error;

/// An argument placeholder, for use with streams_boost::bind(), that corresponds to
/// the bytes_transferred argument of a handler for asynchronous functions such
/// as streams_boost::asio::basic_stream_socket::async_write_some or
/// streams_boost::asio::async_write.
unspecified bytes_transferred;

/// An argument placeholder, for use with streams_boost::bind(), that corresponds to
/// the iterator argument of a handler for asynchronous functions such as
/// streams_boost::asio::basic_resolver::resolve.
unspecified iterator;

#elif defined(__BORLANDC__) || defined(__GNUC__)

inline streams_boost::arg<1> error()
{
  return streams_boost::arg<1>();
}

inline streams_boost::arg<2> bytes_transferred()
{
  return streams_boost::arg<2>();
}

inline streams_boost::arg<2> iterator()
{
  return streams_boost::arg<2>();
}

#else

namespace detail
{
  template <int Number>
  struct placeholder
  {
    static streams_boost::arg<Number>& get()
    {
      static streams_boost::arg<Number> result;
      return result;
    }
  };
}

#if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, < 1400)

static streams_boost::arg<1>& error
  = streams_boost::asio::placeholders::detail::placeholder<1>::get();
static streams_boost::arg<2>& bytes_transferred
  = streams_boost::asio::placeholders::detail::placeholder<2>::get();
static streams_boost::arg<2>& iterator
  = streams_boost::asio::placeholders::detail::placeholder<2>::get();

#else

namespace
{
  streams_boost::arg<1>& error
    = streams_boost::asio::placeholders::detail::placeholder<1>::get();
  streams_boost::arg<2>& bytes_transferred
    = streams_boost::asio::placeholders::detail::placeholder<2>::get();
  streams_boost::arg<2>& iterator
    = streams_boost::asio::placeholders::detail::placeholder<2>::get();
} // namespace

#endif

#endif

} // namespace placeholders
} // namespace asio
} // namespace streams_boost

#include <streams_boost/asio/detail/pop_options.hpp>

#endif // STREAMS_BOOST_ASIO_PLACEHOLDERS_HPP
