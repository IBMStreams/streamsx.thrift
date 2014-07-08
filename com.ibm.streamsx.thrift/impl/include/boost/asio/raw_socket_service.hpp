//
// raw_socket_service.hpp
// ~~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2010 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//

#ifndef STREAMS_BOOST_ASIO_RAW_SOCKET_SERVICE_HPP
#define STREAMS_BOOST_ASIO_RAW_SOCKET_SERVICE_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <streams_boost/asio/detail/push_options.hpp>

#include <streams_boost/asio/detail/push_options.hpp>
#include <cstddef>
#include <streams_boost/config.hpp>
#include <streams_boost/asio/detail/pop_options.hpp>

#include <streams_boost/asio/error.hpp>
#include <streams_boost/asio/io_service.hpp>
#include <streams_boost/asio/detail/service_base.hpp>

#if defined(STREAMS_BOOST_ASIO_HAS_IOCP)
# include <streams_boost/asio/detail/win_iocp_socket_service.hpp>
#elif defined(STREAMS_BOOST_ASIO_HAS_EPOLL)
# include <streams_boost/asio/detail/epoll_reactor.hpp>
# include <streams_boost/asio/detail/reactive_socket_service.hpp>
#elif defined(STREAMS_BOOST_ASIO_HAS_KQUEUE)
# include <streams_boost/asio/detail/kqueue_reactor.hpp>
# include <streams_boost/asio/detail/reactive_socket_service.hpp>
#elif defined(STREAMS_BOOST_ASIO_HAS_DEV_POLL)
# include <streams_boost/asio/detail/dev_poll_reactor.hpp>
# include <streams_boost/asio/detail/reactive_socket_service.hpp>
#else
# include <streams_boost/asio/detail/select_reactor.hpp>
# include <streams_boost/asio/detail/reactive_socket_service.hpp>
#endif

namespace streams_boost {
namespace asio {

/// Default service implementation for a raw socket.
template <typename Protocol>
class raw_socket_service
#if defined(GENERATING_DOCUMENTATION)
  : public streams_boost::asio::io_service::service
#else
  : public streams_boost::asio::detail::service_base<raw_socket_service<Protocol> >
#endif
{
public:
#if defined(GENERATING_DOCUMENTATION)
  /// The unique service identifier.
  static streams_boost::asio::io_service::id id;
#endif

  /// The protocol type.
  typedef Protocol protocol_type;

  /// The endpoint type.
  typedef typename Protocol::endpoint endpoint_type;

private:
  // The type of the platform-specific implementation.
#if defined(STREAMS_BOOST_ASIO_HAS_IOCP)
  typedef detail::win_iocp_socket_service<Protocol> service_impl_type;
#elif defined(STREAMS_BOOST_ASIO_HAS_EPOLL)
  typedef detail::reactive_socket_service<
      Protocol, detail::epoll_reactor<false> > service_impl_type;
#elif defined(STREAMS_BOOST_ASIO_HAS_KQUEUE)
  typedef detail::reactive_socket_service<
      Protocol, detail::kqueue_reactor<false> > service_impl_type;
#elif defined(STREAMS_BOOST_ASIO_HAS_DEV_POLL)
  typedef detail::reactive_socket_service<
      Protocol, detail::dev_poll_reactor<false> > service_impl_type;
#else
  typedef detail::reactive_socket_service<
      Protocol, detail::select_reactor<false> > service_impl_type;
#endif

public:
  /// The type of a raw socket.
#if defined(GENERATING_DOCUMENTATION)
  typedef implementation_defined implementation_type;
#else
  typedef typename service_impl_type::implementation_type implementation_type;
#endif

  /// The native socket type.
#if defined(GENERATING_DOCUMENTATION)
  typedef implementation_defined native_type;
#else
  typedef typename service_impl_type::native_type native_type;
#endif

  /// Construct a new raw socket service for the specified io_service.
  explicit raw_socket_service(streams_boost::asio::io_service& io_service)
    : streams_boost::asio::detail::service_base<
        raw_socket_service<Protocol> >(io_service),
      service_impl_(streams_boost::asio::use_service<service_impl_type>(io_service))
  {
  }

  /// Destroy all user-defined handler objects owned by the service.
  void shutdown_service()
  {
  }

  /// Construct a new raw socket implementation.
  void construct(implementation_type& impl)
  {
    service_impl_.construct(impl);
  }

  /// Destroy a raw socket implementation.
  void destroy(implementation_type& impl)
  {
    service_impl_.destroy(impl);
  }

  // Open a new raw socket implementation.
  streams_boost::system::error_code open(implementation_type& impl,
      const protocol_type& protocol, streams_boost::system::error_code& ec)
  {
    if (protocol.type() == SOCK_RAW)
      service_impl_.open(impl, protocol, ec);
    else
      ec = streams_boost::asio::error::invalid_argument;
    return ec;
  }

  /// Assign an existing native socket to a raw socket.
  streams_boost::system::error_code assign(implementation_type& impl,
      const protocol_type& protocol, const native_type& native_socket,
      streams_boost::system::error_code& ec)
  {
    return service_impl_.assign(impl, protocol, native_socket, ec);
  }

  /// Determine whether the socket is open.
  bool is_open(const implementation_type& impl) const
  {
    return service_impl_.is_open(impl);
  }

  /// Close a raw socket implementation.
  streams_boost::system::error_code close(implementation_type& impl,
      streams_boost::system::error_code& ec)
  {
    return service_impl_.close(impl, ec);
  }

  /// Get the native socket implementation.
  native_type native(implementation_type& impl)
  {
    return service_impl_.native(impl);
  }

  /// Cancel all asynchronous operations associated with the socket.
  streams_boost::system::error_code cancel(implementation_type& impl,
      streams_boost::system::error_code& ec)
  {
    return service_impl_.cancel(impl, ec);
  }

  /// Determine whether the socket is at the out-of-band data mark.
  bool at_mark(const implementation_type& impl,
      streams_boost::system::error_code& ec) const
  {
    return service_impl_.at_mark(impl, ec);
  }

  /// Determine the number of bytes available for reading.
  std::size_t available(const implementation_type& impl,
      streams_boost::system::error_code& ec) const
  {
    return service_impl_.available(impl, ec);
  }

  // Bind the raw socket to the specified local endpoint.
  streams_boost::system::error_code bind(implementation_type& impl,
      const endpoint_type& endpoint, streams_boost::system::error_code& ec)
  {
    return service_impl_.bind(impl, endpoint, ec);
  }

  /// Connect the raw socket to the specified endpoint.
  streams_boost::system::error_code connect(implementation_type& impl,
      const endpoint_type& peer_endpoint, streams_boost::system::error_code& ec)
  {
    return service_impl_.connect(impl, peer_endpoint, ec);
  }

  /// Start an asynchronous connect.
  template <typename ConnectHandler>
  void async_connect(implementation_type& impl,
      const endpoint_type& peer_endpoint, ConnectHandler handler)
  {
    service_impl_.async_connect(impl, peer_endpoint, handler);
  }

  /// Set a socket option.
  template <typename SettableSocketOption>
  streams_boost::system::error_code set_option(implementation_type& impl,
      const SettableSocketOption& option, streams_boost::system::error_code& ec)
  {
    return service_impl_.set_option(impl, option, ec);
  }

  /// Get a socket option.
  template <typename GettableSocketOption>
  streams_boost::system::error_code get_option(const implementation_type& impl,
      GettableSocketOption& option, streams_boost::system::error_code& ec) const
  {
    return service_impl_.get_option(impl, option, ec);
  }

  /// Perform an IO control command on the socket.
  template <typename IoControlCommand>
  streams_boost::system::error_code io_control(implementation_type& impl,
      IoControlCommand& command, streams_boost::system::error_code& ec)
  {
    return service_impl_.io_control(impl, command, ec);
  }

  /// Get the local endpoint.
  endpoint_type local_endpoint(const implementation_type& impl,
      streams_boost::system::error_code& ec) const
  {
    return service_impl_.local_endpoint(impl, ec);
  }

  /// Get the remote endpoint.
  endpoint_type remote_endpoint(const implementation_type& impl,
      streams_boost::system::error_code& ec) const
  {
    return service_impl_.remote_endpoint(impl, ec);
  }

  /// Disable sends or receives on the socket.
  streams_boost::system::error_code shutdown(implementation_type& impl,
      socket_base::shutdown_type what, streams_boost::system::error_code& ec)
  {
    return service_impl_.shutdown(impl, what, ec);
  }

  /// Send the given data to the peer.
  template <typename ConstBufferSequence>
  std::size_t send(implementation_type& impl,
      const ConstBufferSequence& buffers,
      socket_base::message_flags flags, streams_boost::system::error_code& ec)
  {
    return service_impl_.send(impl, buffers, flags, ec);
  }

  /// Start an asynchronous send.
  template <typename ConstBufferSequence, typename WriteHandler>
  void async_send(implementation_type& impl, const ConstBufferSequence& buffers,
      socket_base::message_flags flags, WriteHandler handler)
  {
    service_impl_.async_send(impl, buffers, flags, handler);
  }

  /// Send raw data to the specified endpoint.
  template <typename ConstBufferSequence>
  std::size_t send_to(implementation_type& impl,
      const ConstBufferSequence& buffers, const endpoint_type& destination,
      socket_base::message_flags flags, streams_boost::system::error_code& ec)
  {
    return service_impl_.send_to(impl, buffers, destination, flags, ec);
  }

  /// Start an asynchronous send.
  template <typename ConstBufferSequence, typename WriteHandler>
  void async_send_to(implementation_type& impl,
      const ConstBufferSequence& buffers, const endpoint_type& destination,
      socket_base::message_flags flags, WriteHandler handler)
  {
    service_impl_.async_send_to(impl, buffers, destination, flags, handler);
  }

  /// Receive some data from the peer.
  template <typename MutableBufferSequence>
  std::size_t receive(implementation_type& impl,
      const MutableBufferSequence& buffers,
      socket_base::message_flags flags, streams_boost::system::error_code& ec)
  {
    return service_impl_.receive(impl, buffers, flags, ec);
  }

  /// Start an asynchronous receive.
  template <typename MutableBufferSequence, typename ReadHandler>
  void async_receive(implementation_type& impl,
      const MutableBufferSequence& buffers,
      socket_base::message_flags flags, ReadHandler handler)
  {
    service_impl_.async_receive(impl, buffers, flags, handler);
  }

  /// Receive raw data with the endpoint of the sender.
  template <typename MutableBufferSequence>
  std::size_t receive_from(implementation_type& impl,
      const MutableBufferSequence& buffers, endpoint_type& sender_endpoint,
      socket_base::message_flags flags, streams_boost::system::error_code& ec)
  {
    return service_impl_.receive_from(impl, buffers, sender_endpoint, flags,
        ec);
  }

  /// Start an asynchronous receive that will get the endpoint of the sender.
  template <typename MutableBufferSequence, typename ReadHandler>
  void async_receive_from(implementation_type& impl,
      const MutableBufferSequence& buffers, endpoint_type& sender_endpoint,
      socket_base::message_flags flags, ReadHandler handler)
  {
    service_impl_.async_receive_from(impl, buffers, sender_endpoint, flags,
        handler);
  }

private:
  // The service that provides the platform-specific implementation.
  service_impl_type& service_impl_;
};

} // namespace asio
} // namespace streams_boost

#include <streams_boost/asio/detail/pop_options.hpp>

#endif // STREAMS_BOOST_ASIO_RAW_SOCKET_SERVICE_HPP
