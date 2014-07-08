//
// asio.hpp
// ~~~~~~~~
//
// Copyright (c) 2003-2010 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//
//  See www.streams_boost.org/libs/asio for documentation.
//

#ifndef STREAMS_BOOST_ASIO_HPP
#define STREAMS_BOOST_ASIO_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <streams_boost/asio/basic_datagram_socket.hpp>
#include <streams_boost/asio/basic_deadline_timer.hpp>
#include <streams_boost/asio/basic_io_object.hpp>
#include <streams_boost/asio/basic_raw_socket.hpp>
#include <streams_boost/asio/basic_serial_port.hpp>
#include <streams_boost/asio/basic_socket_acceptor.hpp>
#include <streams_boost/asio/basic_socket_iostream.hpp>
#include <streams_boost/asio/basic_socket_streambuf.hpp>
#include <streams_boost/asio/basic_stream_socket.hpp>
#include <streams_boost/asio/basic_streambuf.hpp>
#include <streams_boost/asio/buffer.hpp>
#include <streams_boost/asio/buffered_read_stream_fwd.hpp>
#include <streams_boost/asio/buffered_read_stream.hpp>
#include <streams_boost/asio/buffered_stream_fwd.hpp>
#include <streams_boost/asio/buffered_stream.hpp>
#include <streams_boost/asio/buffered_write_stream_fwd.hpp>
#include <streams_boost/asio/buffered_write_stream.hpp>
#include <streams_boost/asio/buffers_iterator.hpp>
#include <streams_boost/asio/completion_condition.hpp>
#include <streams_boost/asio/datagram_socket_service.hpp>
#include <streams_boost/asio/deadline_timer_service.hpp>
#include <streams_boost/asio/deadline_timer.hpp>
#include <streams_boost/asio/error.hpp>
#include <streams_boost/asio/handler_alloc_hook.hpp>
#include <streams_boost/asio/handler_invoke_hook.hpp>
#include <streams_boost/asio/io_service.hpp>
#include <streams_boost/asio/ip/address.hpp>
#include <streams_boost/asio/ip/address_v4.hpp>
#include <streams_boost/asio/ip/address_v6.hpp>
#include <streams_boost/asio/ip/basic_endpoint.hpp>
#include <streams_boost/asio/ip/basic_resolver.hpp>
#include <streams_boost/asio/ip/basic_resolver_entry.hpp>
#include <streams_boost/asio/ip/basic_resolver_iterator.hpp>
#include <streams_boost/asio/ip/basic_resolver_query.hpp>
#include <streams_boost/asio/ip/host_name.hpp>
#include <streams_boost/asio/ip/icmp.hpp>
#include <streams_boost/asio/ip/multicast.hpp>
#include <streams_boost/asio/ip/resolver_query_base.hpp>
#include <streams_boost/asio/ip/resolver_service.hpp>
#include <streams_boost/asio/ip/tcp.hpp>
#include <streams_boost/asio/ip/udp.hpp>
#include <streams_boost/asio/ip/unicast.hpp>
#include <streams_boost/asio/ip/v6_only.hpp>
#include <streams_boost/asio/is_read_buffered.hpp>
#include <streams_boost/asio/is_write_buffered.hpp>
#include <streams_boost/asio/local/basic_endpoint.hpp>
#include <streams_boost/asio/local/connect_pair.hpp>
#include <streams_boost/asio/local/datagram_protocol.hpp>
#include <streams_boost/asio/local/stream_protocol.hpp>
#include <streams_boost/asio/placeholders.hpp>
#include <streams_boost/asio/posix/basic_descriptor.hpp>
#include <streams_boost/asio/posix/basic_stream_descriptor.hpp>
#include <streams_boost/asio/posix/descriptor_base.hpp>
#include <streams_boost/asio/posix/stream_descriptor.hpp>
#include <streams_boost/asio/posix/stream_descriptor_service.hpp>
#include <streams_boost/asio/raw_socket_service.hpp>
#include <streams_boost/asio/read.hpp>
#include <streams_boost/asio/read_at.hpp>
#include <streams_boost/asio/read_until.hpp>
#include <streams_boost/asio/serial_port.hpp>
#include <streams_boost/asio/serial_port_base.hpp>
#include <streams_boost/asio/serial_port_service.hpp>
#include <streams_boost/asio/socket_acceptor_service.hpp>
#include <streams_boost/asio/socket_base.hpp>
#include <streams_boost/asio/strand.hpp>
#include <streams_boost/asio/stream_socket_service.hpp>
#include <streams_boost/asio/streambuf.hpp>
#include <streams_boost/asio/time_traits.hpp>
#include <streams_boost/asio/version.hpp>
#include <streams_boost/asio/windows/basic_handle.hpp>
#include <streams_boost/asio/windows/basic_random_access_handle.hpp>
#include <streams_boost/asio/windows/basic_stream_handle.hpp>
#include <streams_boost/asio/windows/overlapped_ptr.hpp>
#include <streams_boost/asio/windows/random_access_handle.hpp>
#include <streams_boost/asio/windows/random_access_handle_service.hpp>
#include <streams_boost/asio/windows/stream_handle.hpp>
#include <streams_boost/asio/windows/stream_handle_service.hpp>
#include <streams_boost/asio/write.hpp>
#include <streams_boost/asio/write_at.hpp>

#endif // STREAMS_BOOST_ASIO_HPP
