//
// serial_port_service.hpp
// ~~~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2010 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//

#ifndef STREAMS_BOOST_ASIO_SERIAL_PORT_SERVICE_HPP
#define STREAMS_BOOST_ASIO_SERIAL_PORT_SERVICE_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <streams_boost/asio/detail/push_options.hpp>

#include <streams_boost/asio/detail/push_options.hpp>
#include <cstddef>
#include <streams_boost/config.hpp>
#include <string>
#include <streams_boost/asio/detail/pop_options.hpp>

#include <streams_boost/asio/error.hpp>
#include <streams_boost/asio/io_service.hpp>
#include <streams_boost/asio/serial_port_base.hpp>
#include <streams_boost/asio/detail/service_base.hpp>
#include <streams_boost/asio/detail/reactive_serial_port_service.hpp>
#include <streams_boost/asio/detail/win_iocp_serial_port_service.hpp>

#if defined(STREAMS_BOOST_ASIO_HAS_SERIAL_PORT) \
  || defined(GENERATING_DOCUMENTATION)

namespace streams_boost {
namespace asio {

/// Default service implementation for a serial port.
class serial_port_service
#if defined(GENERATING_DOCUMENTATION)
  : public streams_boost::asio::io_service::service
#else
  : public streams_boost::asio::detail::service_base<serial_port_service>
#endif
{
public:
#if defined(GENERATING_DOCUMENTATION)
  /// The unique service identifier.
  static streams_boost::asio::io_service::id id;
#endif

private:
  // The type of the platform-specific implementation.
#if defined(STREAMS_BOOST_ASIO_HAS_IOCP)
  typedef detail::win_iocp_serial_port_service service_impl_type;
#elif defined(STREAMS_BOOST_ASIO_HAS_EPOLL)
  typedef detail::reactive_serial_port_service<
      detail::epoll_reactor<false> > service_impl_type;
#elif defined(STREAMS_BOOST_ASIO_HAS_KQUEUE)
  typedef detail::reactive_serial_port_service<
      detail::kqueue_reactor<false> > service_impl_type;
#elif defined(STREAMS_BOOST_ASIO_HAS_DEV_POLL)
  typedef detail::reactive_serial_port_service<
      detail::dev_poll_reactor<false> > service_impl_type;
#else
  typedef detail::reactive_serial_port_service<
      detail::select_reactor<false> > service_impl_type;
#endif

public:
  /// The type of a serial port implementation.
#if defined(GENERATING_DOCUMENTATION)
  typedef implementation_defined implementation_type;
#else
  typedef service_impl_type::implementation_type implementation_type;
#endif

  /// The native handle type.
#if defined(GENERATING_DOCUMENTATION)
  typedef implementation_defined native_type;
#else
  typedef service_impl_type::native_type native_type;
#endif

  /// Construct a new serial port service for the specified io_service.
  explicit serial_port_service(streams_boost::asio::io_service& io_service)
    : streams_boost::asio::detail::service_base<serial_port_service>(io_service),
      service_impl_(streams_boost::asio::use_service<service_impl_type>(io_service))
  {
  }

  /// Destroy all user-defined handler objects owned by the service.
  void shutdown_service()
  {
  }

  /// Construct a new serial port implementation.
  void construct(implementation_type& impl)
  {
    service_impl_.construct(impl);
  }

  /// Destroy a serial port implementation.
  void destroy(implementation_type& impl)
  {
    service_impl_.destroy(impl);
  }

  /// Open a serial port.
  streams_boost::system::error_code open(implementation_type& impl,
      const std::string& device, streams_boost::system::error_code& ec)
  {
    return service_impl_.open(impl, device, ec);
  }

  /// Assign an existing native handle to a serial port.
  streams_boost::system::error_code assign(implementation_type& impl,
      const native_type& native_handle, streams_boost::system::error_code& ec)
  {
    return service_impl_.assign(impl, native_handle, ec);
  }

  /// Determine whether the handle is open.
  bool is_open(const implementation_type& impl) const
  {
    return service_impl_.is_open(impl);
  }

  /// Close a serial port implementation.
  streams_boost::system::error_code close(implementation_type& impl,
      streams_boost::system::error_code& ec)
  {
    return service_impl_.close(impl, ec);
  }

  /// Get the native handle implementation.
  native_type native(implementation_type& impl)
  {
    return service_impl_.native(impl);
  }

  /// Cancel all asynchronous operations associated with the handle.
  streams_boost::system::error_code cancel(implementation_type& impl,
      streams_boost::system::error_code& ec)
  {
    return service_impl_.cancel(impl, ec);
  }

  /// Set a serial port option.
  template <typename SettableSerialPortOption>
  streams_boost::system::error_code set_option(implementation_type& impl,
      const SettableSerialPortOption& option, streams_boost::system::error_code& ec)
  {
    return service_impl_.set_option(impl, option, ec);
  }

  /// Get a serial port option.
  template <typename GettableSerialPortOption>
  streams_boost::system::error_code get_option(const implementation_type& impl,
      GettableSerialPortOption& option, streams_boost::system::error_code& ec) const
  {
    return service_impl_.get_option(impl, option, ec);
  }

  /// Send a break sequence to the serial port.
  streams_boost::system::error_code send_break(implementation_type& impl,
      streams_boost::system::error_code& ec)
  {
    return service_impl_.send_break(impl, ec);
  }

  /// Write the given data to the stream.
  template <typename ConstBufferSequence>
  std::size_t write_some(implementation_type& impl,
      const ConstBufferSequence& buffers, streams_boost::system::error_code& ec)
  {
    return service_impl_.write_some(impl, buffers, ec);
  }

  /// Start an asynchronous write.
  template <typename ConstBufferSequence, typename WriteHandler>
  void async_write_some(implementation_type& impl,
      const ConstBufferSequence& buffers, WriteHandler handler)
  {
    service_impl_.async_write_some(impl, buffers, handler);
  }

  /// Read some data from the stream.
  template <typename MutableBufferSequence>
  std::size_t read_some(implementation_type& impl,
      const MutableBufferSequence& buffers, streams_boost::system::error_code& ec)
  {
    return service_impl_.read_some(impl, buffers, ec);
  }

  /// Start an asynchronous read.
  template <typename MutableBufferSequence, typename ReadHandler>
  void async_read_some(implementation_type& impl,
      const MutableBufferSequence& buffers, ReadHandler handler)
  {
    service_impl_.async_read_some(impl, buffers, handler);
  }

private:
  // The service that provides the platform-specific implementation.
  service_impl_type& service_impl_;
};

} // namespace asio
} // namespace streams_boost

#endif // defined(STREAMS_BOOST_ASIO_HAS_SERIAL_PORT)
       //   || defined(GENERATING_DOCUMENTATION)

#include <streams_boost/asio/detail/pop_options.hpp>

#endif // STREAMS_BOOST_ASIO_SERIAL_PORT_SERVICE_HPP
