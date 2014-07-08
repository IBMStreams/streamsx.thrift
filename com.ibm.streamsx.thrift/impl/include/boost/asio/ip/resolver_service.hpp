//
// resolver_service.hpp
// ~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2010 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//

#ifndef STREAMS_BOOST_ASIO_IP_RESOLVER_SERVICE_HPP
#define STREAMS_BOOST_ASIO_IP_RESOLVER_SERVICE_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <streams_boost/asio/detail/push_options.hpp>

#include <streams_boost/asio/error.hpp>
#include <streams_boost/asio/io_service.hpp>
#include <streams_boost/asio/detail/resolver_service.hpp>
#include <streams_boost/asio/detail/service_base.hpp>

namespace streams_boost {
namespace asio {
namespace ip {

/// Default service implementation for a resolver.
template <typename InternetProtocol>
class resolver_service
#if defined(GENERATING_DOCUMENTATION)
  : public streams_boost::asio::io_service::service
#else
  : public streams_boost::asio::detail::service_base<
      resolver_service<InternetProtocol> >
#endif
{
public:
#if defined(GENERATING_DOCUMENTATION)
  /// The unique service identifier.
  static streams_boost::asio::io_service::id id;
#endif

  /// The protocol type.
  typedef InternetProtocol protocol_type;

  /// The endpoint type.
  typedef typename InternetProtocol::endpoint endpoint_type;

  /// The query type.
  typedef typename InternetProtocol::resolver_query query_type;

  /// The iterator type.
  typedef typename InternetProtocol::resolver_iterator iterator_type;

private:
  // The type of the platform-specific implementation.
  typedef streams_boost::asio::detail::resolver_service<InternetProtocol>
    service_impl_type;

public:
  /// The type of a resolver implementation.
#if defined(GENERATING_DOCUMENTATION)
  typedef implementation_defined implementation_type;
#else
  typedef typename service_impl_type::implementation_type implementation_type;
#endif

  /// Construct a new resolver service for the specified io_service.
  explicit resolver_service(streams_boost::asio::io_service& io_service)
    : streams_boost::asio::detail::service_base<
        resolver_service<InternetProtocol> >(io_service),
      service_impl_(streams_boost::asio::use_service<service_impl_type>(io_service))
  {
  }

  /// Destroy all user-defined handler objects owned by the service.
  void shutdown_service()
  {
  }

  /// Construct a new resolver implementation.
  void construct(implementation_type& impl)
  {
    service_impl_.construct(impl);
  }

  /// Destroy a resolver implementation.
  void destroy(implementation_type& impl)
  {
    service_impl_.destroy(impl);
  }

  /// Cancel pending asynchronous operations.
  void cancel(implementation_type& impl)
  {
    service_impl_.cancel(impl);
  }

  /// Resolve a query to a list of entries.
  iterator_type resolve(implementation_type& impl, const query_type& query,
      streams_boost::system::error_code& ec)
  {
    return service_impl_.resolve(impl, query, ec);
  }

  /// Asynchronously resolve a query to a list of entries.
  template <typename Handler>
  void async_resolve(implementation_type& impl, const query_type& query,
      Handler handler)
  {
    service_impl_.async_resolve(impl, query, handler);
  }

  /// Resolve an endpoint to a list of entries.
  iterator_type resolve(implementation_type& impl,
      const endpoint_type& endpoint, streams_boost::system::error_code& ec)
  {
    return service_impl_.resolve(impl, endpoint, ec);
  }

  /// Asynchronously resolve an endpoint to a list of entries.
  template <typename ResolveHandler>
  void async_resolve(implementation_type& impl, const endpoint_type& endpoint,
      ResolveHandler handler)
  {
    return service_impl_.async_resolve(impl, endpoint, handler);
  }

private:
  // The service that provides the platform-specific implementation.
  service_impl_type& service_impl_;
};

} // namespace ip
} // namespace asio
} // namespace streams_boost

#include <streams_boost/asio/detail/pop_options.hpp>

#endif // STREAMS_BOOST_ASIO_IP_RESOLVER_SERVICE_HPP
