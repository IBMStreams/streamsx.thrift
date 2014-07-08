//
// service_base.hpp
// ~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2010 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//

#ifndef STREAMS_BOOST_ASIO_DETAIL_SERVICE_BASE_HPP
#define STREAMS_BOOST_ASIO_DETAIL_SERVICE_BASE_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <streams_boost/asio/detail/push_options.hpp>

#include <streams_boost/asio/io_service.hpp>
#include <streams_boost/asio/detail/service_id.hpp>

namespace streams_boost {
namespace asio {
namespace detail {

// Special service base class to keep classes header-file only.
template <typename Type>
class service_base
  : public streams_boost::asio::io_service::service
{
public:
  static streams_boost::asio::detail::service_id<Type> id;

  // Constructor.
  service_base(streams_boost::asio::io_service& io_service)
    : streams_boost::asio::io_service::service(io_service)
  {
  }
};

template <typename Type>
streams_boost::asio::detail::service_id<Type> service_base<Type>::id;

} // namespace detail
} // namespace asio
} // namespace streams_boost

#include <streams_boost/asio/detail/pop_options.hpp>

#endif // STREAMS_BOOST_ASIO_DETAIL_SERVICE_BASE_HPP
