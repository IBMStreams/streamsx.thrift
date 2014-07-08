//
// throw_error.hpp
// ~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2010 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//

#ifndef STREAMS_BOOST_ASIO_DETAIL_THROW_ERROR_HPP
#define STREAMS_BOOST_ASIO_DETAIL_THROW_ERROR_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <streams_boost/asio/detail/push_options.hpp>

#include <streams_boost/asio/detail/push_options.hpp>
#include <streams_boost/throw_exception.hpp>
#include <streams_boost/system/error_code.hpp>
#include <streams_boost/system/system_error.hpp>
#include <streams_boost/asio/detail/pop_options.hpp>


namespace streams_boost {
namespace asio {
namespace detail {

inline void throw_error(const streams_boost::system::error_code& err)
{
  if (err)
  {
    streams_boost::system::system_error e(err);
    streams_boost::throw_exception(e);
  }
}

} // namespace detail
} // namespace asio
} // namespace streams_boost

#include <streams_boost/asio/detail/pop_options.hpp>

#endif // STREAMS_BOOST_ASIO_DETAIL_THROW_ERROR_HPP
