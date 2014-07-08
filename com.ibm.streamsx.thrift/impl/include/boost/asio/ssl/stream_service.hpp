//
// stream_service.hpp
// ~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2005 Voipster / Indrek dot Juhani at voipster dot com
// Copyright (c) 2005-2010 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//

#ifndef STREAMS_BOOST_ASIO_SSL_STREAM_SERVICE_HPP
#define STREAMS_BOOST_ASIO_SSL_STREAM_SERVICE_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <streams_boost/asio/detail/push_options.hpp>

#include <streams_boost/asio/detail/push_options.hpp>
#include <cstddef>
#include <streams_boost/config.hpp>
#include <streams_boost/noncopyable.hpp>
#include <streams_boost/asio/detail/pop_options.hpp>

#include <streams_boost/asio/io_service.hpp>
#include <streams_boost/asio/detail/service_base.hpp>
#include <streams_boost/asio/ssl/basic_context.hpp>
#include <streams_boost/asio/ssl/stream_base.hpp>
#include <streams_boost/asio/ssl/detail/openssl_stream_service.hpp>

namespace streams_boost {
namespace asio {
namespace ssl {

/// Default service implementation for an SSL stream.
class stream_service
#if defined(GENERATING_DOCUMENTATION)
  : public streams_boost::asio::io_service::service
#else
  : public streams_boost::asio::detail::service_base<stream_service>
#endif
{
private:
  // The type of the platform-specific implementation.
  typedef detail::openssl_stream_service service_impl_type;

public:
#if defined(GENERATING_DOCUMENTATION)
  /// The unique service identifier.
  static streams_boost::asio::io_service::id id;
#endif

  /// The type of a stream implementation.
#if defined(GENERATING_DOCUMENTATION)
  typedef implementation_defined impl_type;
#else
  typedef service_impl_type::impl_type impl_type;
#endif

  /// Construct a new stream service for the specified io_service.
  explicit stream_service(streams_boost::asio::io_service& io_service)
    : streams_boost::asio::detail::service_base<stream_service>(io_service),
      service_impl_(streams_boost::asio::use_service<service_impl_type>(io_service))
  {
  }

  /// Destroy all user-defined handler objects owned by the service.
  void shutdown_service()
  {
  }

  /// Return a null stream implementation.
  impl_type null() const
  {
    return service_impl_.null();
  }

  /// Create a new stream implementation.
  template <typename Stream, typename Context_Service>
  void create(impl_type& impl, Stream& next_layer,
      basic_context<Context_Service>& context)
  {
    service_impl_.create(impl, next_layer, context);
  }

  /// Destroy a stream implementation.
  template <typename Stream>
  void destroy(impl_type& impl, Stream& next_layer)
  {
    service_impl_.destroy(impl, next_layer);
  }

  /// Perform SSL handshaking.
  template <typename Stream>
  streams_boost::system::error_code handshake(impl_type& impl, Stream& next_layer,
      stream_base::handshake_type type, streams_boost::system::error_code& ec)
  {
    return service_impl_.handshake(impl, next_layer, type, ec);
  }

  /// Start an asynchronous SSL handshake.
  template <typename Stream, typename HandshakeHandler>
  void async_handshake(impl_type& impl, Stream& next_layer,
      stream_base::handshake_type type, HandshakeHandler handler)
  {
    service_impl_.async_handshake(impl, next_layer, type, handler);
  }

  /// Shut down SSL on the stream.
  template <typename Stream>
  streams_boost::system::error_code shutdown(impl_type& impl, Stream& next_layer,
      streams_boost::system::error_code& ec)
  {
    return service_impl_.shutdown(impl, next_layer, ec);
  }

  /// Asynchronously shut down SSL on the stream.
  template <typename Stream, typename ShutdownHandler>
  void async_shutdown(impl_type& impl, Stream& next_layer,
      ShutdownHandler handler)
  {
    service_impl_.async_shutdown(impl, next_layer, handler);
  }

  /// Write some data to the stream.
  template <typename Stream, typename ConstBufferSequence>
  std::size_t write_some(impl_type& impl, Stream& next_layer,
      const ConstBufferSequence& buffers, streams_boost::system::error_code& ec)
  {
    return service_impl_.write_some(impl, next_layer, buffers, ec);
  }

  /// Start an asynchronous write.
  template <typename Stream, typename ConstBufferSequence,
      typename WriteHandler>
  void async_write_some(impl_type& impl, Stream& next_layer,
      const ConstBufferSequence& buffers, WriteHandler handler)
  {
    service_impl_.async_write_some(impl, next_layer, buffers, handler);
  }

  /// Read some data from the stream.
  template <typename Stream, typename MutableBufferSequence>
  std::size_t read_some(impl_type& impl, Stream& next_layer,
      const MutableBufferSequence& buffers, streams_boost::system::error_code& ec)
  {
    return service_impl_.read_some(impl, next_layer, buffers, ec);
  }

  /// Start an asynchronous read.
  template <typename Stream, typename MutableBufferSequence,
      typename ReadHandler>
  void async_read_some(impl_type& impl, Stream& next_layer,
      const MutableBufferSequence& buffers, ReadHandler handler)
  {
    service_impl_.async_read_some(impl, next_layer, buffers, handler);
  }

  /// Peek at the incoming data on the stream.
  template <typename Stream, typename MutableBufferSequence>
  std::size_t peek(impl_type& impl, Stream& next_layer,
      const MutableBufferSequence& buffers, streams_boost::system::error_code& ec)
  {
    return service_impl_.peek(impl, next_layer, buffers, ec);
  }

  /// Determine the amount of data that may be read without blocking.
  template <typename Stream>
  std::size_t in_avail(impl_type& impl, Stream& next_layer,
      streams_boost::system::error_code& ec)
  {
    return service_impl_.in_avail(impl, next_layer, ec);
  }

private:
  // The service that provides the platform-specific implementation.
  service_impl_type& service_impl_;
};

} // namespace ssl
} // namespace asio
} // namespace streams_boost

#include <streams_boost/asio/detail/pop_options.hpp>

#endif // STREAMS_BOOST_ASIO_SSL_STREAM_SERVICE_HPP
