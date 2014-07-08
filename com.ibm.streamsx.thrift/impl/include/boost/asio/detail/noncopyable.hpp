//
// noncopyable.hpp
// ~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2010 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//

#ifndef STREAMS_BOOST_ASIO_DETAIL_NONCOPYABLE_HPP
#define STREAMS_BOOST_ASIO_DETAIL_NONCOPYABLE_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <streams_boost/asio/detail/push_options.hpp>

#include <streams_boost/asio/detail/push_options.hpp>
#include <streams_boost/config.hpp>
#include <streams_boost/noncopyable.hpp>
#include <streams_boost/detail/workaround.hpp>
#include <streams_boost/asio/detail/pop_options.hpp>

namespace streams_boost {
namespace asio {
namespace detail {

#if STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x564))
// Redefine the noncopyable class for Borland C++ since that compiler does not
// apply the empty base optimisation unless the base class contains a dummy
// char data member.
class noncopyable
{
protected:
  noncopyable() {}
  ~noncopyable() {}
private:
  noncopyable(const noncopyable&);
  const noncopyable& operator=(const noncopyable&);
  char dummy_;
};
#else
using streams_boost::noncopyable;
#endif

} // namespace detail

using streams_boost::asio::detail::noncopyable;

} // namespace asio
} // namespace streams_boost

#include <streams_boost/asio/detail/pop_options.hpp>

#endif // STREAMS_BOOST_ASIO_DETAIL_NONCOPYABLE_HPP
