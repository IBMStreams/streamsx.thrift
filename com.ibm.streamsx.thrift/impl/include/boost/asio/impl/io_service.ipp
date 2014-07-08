//
// io_service.ipp
// ~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2010 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//

#ifndef STREAMS_BOOST_ASIO_IO_SERVICE_IPP
#define STREAMS_BOOST_ASIO_IO_SERVICE_IPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <streams_boost/asio/detail/push_options.hpp>

#include <streams_boost/asio/detail/push_options.hpp>
#include <streams_boost/limits.hpp>
#include <streams_boost/asio/detail/pop_options.hpp>

#include <streams_boost/asio/detail/service_registry.hpp>
#include <streams_boost/asio/detail/throw_error.hpp>

#if defined(STREAMS_BOOST_ASIO_HAS_IOCP)
# include <streams_boost/asio/detail/win_iocp_io_service.hpp>
#elif defined(STREAMS_BOOST_ASIO_HAS_EPOLL)
# include <streams_boost/asio/detail/epoll_reactor.hpp>
# include <streams_boost/asio/detail/task_io_service.hpp>
#elif defined(STREAMS_BOOST_ASIO_HAS_KQUEUE)
# include <streams_boost/asio/detail/kqueue_reactor.hpp>
# include <streams_boost/asio/detail/task_io_service.hpp>
#elif defined(STREAMS_BOOST_ASIO_HAS_DEV_POLL)
# include <streams_boost/asio/detail/dev_poll_reactor.hpp>
# include <streams_boost/asio/detail/task_io_service.hpp>
#else
# include <streams_boost/asio/detail/select_reactor.hpp>
# include <streams_boost/asio/detail/task_io_service.hpp>
#endif

namespace streams_boost {
namespace asio {

inline io_service::io_service()
  : service_registry_(new streams_boost::asio::detail::service_registry(*this)),
    impl_(service_registry_->use_service<impl_type>())
{
  impl_.init((std::numeric_limits<std::size_t>::max)());
}

inline io_service::io_service(std::size_t concurrency_hint)
  : service_registry_(new streams_boost::asio::detail::service_registry(*this)),
    impl_(service_registry_->use_service<impl_type>())
{
  impl_.init(concurrency_hint);
}

inline io_service::~io_service()
{
  delete service_registry_;
}

inline std::size_t io_service::run()
{
  streams_boost::system::error_code ec;
  std::size_t s = impl_.run(ec);
  streams_boost::asio::detail::throw_error(ec);
  return s;
}

inline std::size_t io_service::run(streams_boost::system::error_code& ec)
{
  return impl_.run(ec);
}

inline std::size_t io_service::run_one()
{
  streams_boost::system::error_code ec;
  std::size_t s = impl_.run_one(ec);
  streams_boost::asio::detail::throw_error(ec);
  return s;
}

inline std::size_t io_service::run_one(streams_boost::system::error_code& ec)
{
  return impl_.run_one(ec);
}

inline std::size_t io_service::poll()
{
  streams_boost::system::error_code ec;
  std::size_t s = impl_.poll(ec);
  streams_boost::asio::detail::throw_error(ec);
  return s;
}

inline std::size_t io_service::poll(streams_boost::system::error_code& ec)
{
  return impl_.poll(ec);
}

inline std::size_t io_service::poll_one()
{
  streams_boost::system::error_code ec;
  std::size_t s = impl_.poll_one(ec);
  streams_boost::asio::detail::throw_error(ec);
  return s;
}

inline std::size_t io_service::poll_one(streams_boost::system::error_code& ec)
{
  return impl_.poll_one(ec);
}

inline void io_service::stop()
{
  impl_.stop();
}

inline void io_service::reset()
{
  impl_.reset();
}

template <typename Handler>
inline void io_service::dispatch(Handler handler)
{
  impl_.dispatch(handler);
}

template <typename Handler>
inline void io_service::post(Handler handler)
{
  impl_.post(handler);
}

template <typename Handler>
#if defined(GENERATING_DOCUMENTATION)
unspecified
#else
inline detail::wrapped_handler<io_service&, Handler>
#endif
io_service::wrap(Handler handler)
{
  return detail::wrapped_handler<io_service&, Handler>(*this, handler);
}

inline io_service::work::work(streams_boost::asio::io_service& io_service)
  : io_service_(io_service)
{
  io_service_.impl_.work_started();
}

inline io_service::work::work(const work& other)
  : io_service_(other.io_service_)
{
  io_service_.impl_.work_started();
}

inline io_service::work::~work()
{
  io_service_.impl_.work_finished();
}

inline streams_boost::asio::io_service& io_service::work::io_service()
{
  return io_service_;
}

inline streams_boost::asio::io_service& io_service::work::get_io_service()
{
  return io_service_;
}

inline io_service::service::service(streams_boost::asio::io_service& owner)
  : owner_(owner),
    type_info_(0),
    next_(0)
{
}

inline io_service::service::~service()
{
}

inline streams_boost::asio::io_service& io_service::service::io_service()
{
  return owner_;
}

inline streams_boost::asio::io_service& io_service::service::get_io_service()
{
  return owner_;
}

template <typename Service>
inline Service& use_service(io_service& ios)
{
  // Check that Service meets the necessary type requirements.
  (void)static_cast<io_service::service*>(static_cast<Service*>(0));
  (void)static_cast<const io_service::id*>(&Service::id);

  return ios.service_registry_->template use_service<Service>();
}

template <typename Service>
void add_service(io_service& ios, Service* svc)
{
  // Check that Service meets the necessary type requirements.
  (void)static_cast<io_service::service*>(static_cast<Service*>(0));
  (void)static_cast<const io_service::id*>(&Service::id);

  if (&ios != &svc->io_service())
    streams_boost::throw_exception(invalid_service_owner());
  if (!ios.service_registry_->template add_service<Service>(svc))
    streams_boost::throw_exception(service_already_exists());
}

template <typename Service>
bool has_service(io_service& ios)
{
  // Check that Service meets the necessary type requirements.
  (void)static_cast<io_service::service*>(static_cast<Service*>(0));
  (void)static_cast<const io_service::id*>(&Service::id);

  return ios.service_registry_->template has_service<Service>();
}

} // namespace asio
} // namespace streams_boost

#include <streams_boost/asio/detail/pop_options.hpp>

#endif // STREAMS_BOOST_ASIO_IO_SERVICE_IPP
