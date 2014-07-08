//
// context_service.hpp
// ~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2005 Voipster / Indrek dot Juhani at voipster dot com
// Copyright (c) 2005-2010 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//

#ifndef STREAMS_BOOST_ASIO_SSL_CONTEXT_SERVICE_HPP
#define STREAMS_BOOST_ASIO_SSL_CONTEXT_SERVICE_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <streams_boost/asio/detail/push_options.hpp>

#include <streams_boost/asio/detail/push_options.hpp>
#include <string>
#include <streams_boost/noncopyable.hpp>
#include <streams_boost/asio/detail/pop_options.hpp>

#include <streams_boost/asio/error.hpp>
#include <streams_boost/asio/io_service.hpp>
#include <streams_boost/asio/detail/service_base.hpp>
#include <streams_boost/asio/ssl/context_base.hpp>
#include <streams_boost/asio/ssl/detail/openssl_context_service.hpp>

namespace streams_boost {
namespace asio {
namespace ssl {

/// Default service implementation for a context.
class context_service
#if defined(GENERATING_DOCUMENTATION)
  : public streams_boost::asio::io_service::service
#else
  : public streams_boost::asio::detail::service_base<context_service>
#endif
{
private:
  // The type of the platform-specific implementation.
  typedef detail::openssl_context_service service_impl_type;

public:
#if defined(GENERATING_DOCUMENTATION)
  /// The unique service identifier.
  static streams_boost::asio::io_service::id id;
#endif

  /// The type of the context.
#if defined(GENERATING_DOCUMENTATION)
  typedef implementation_defined impl_type;
#else
  typedef service_impl_type::impl_type impl_type;
#endif

  /// Constructor.
  explicit context_service(streams_boost::asio::io_service& io_service)
    : streams_boost::asio::detail::service_base<context_service>(io_service),
      service_impl_(streams_boost::asio::use_service<service_impl_type>(io_service))
  {
  }

  /// Destroy all user-defined handler objects owned by the service.
  void shutdown_service()
  {
  }

  /// Return a null context implementation.
  impl_type null() const
  {
    return service_impl_.null();
  }

  /// Create a new context implementation.
  void create(impl_type& impl, context_base::method m)
  {
    service_impl_.create(impl, m);
  }

  /// Destroy a context implementation.
  void destroy(impl_type& impl)
  {
    service_impl_.destroy(impl);
  }

  /// Set options on the context.
  streams_boost::system::error_code set_options(impl_type& impl,
      context_base::options o, streams_boost::system::error_code& ec)
  {
    return service_impl_.set_options(impl, o, ec);
  }

  /// Set peer verification mode.
  streams_boost::system::error_code set_verify_mode(impl_type& impl,
      context_base::verify_mode v, streams_boost::system::error_code& ec)
  {
    return service_impl_.set_verify_mode(impl, v, ec);
  }

  /// Load a certification authority file for performing verification.
  streams_boost::system::error_code load_verify_file(impl_type& impl,
      const std::string& filename, streams_boost::system::error_code& ec)
  {
    return service_impl_.load_verify_file(impl, filename, ec);
  }

  /// Add a directory containing certification authority files to be used for
  /// performing verification.
  streams_boost::system::error_code add_verify_path(impl_type& impl,
      const std::string& path, streams_boost::system::error_code& ec)
  {
    return service_impl_.add_verify_path(impl, path, ec);
  }

  /// Use a certificate from a file.
  streams_boost::system::error_code use_certificate_file(impl_type& impl,
      const std::string& filename, context_base::file_format format,
      streams_boost::system::error_code& ec)
  {
    return service_impl_.use_certificate_file(impl, filename, format, ec);
  }

  /// Use a certificate chain from a file.
  streams_boost::system::error_code use_certificate_chain_file(impl_type& impl,
      const std::string& filename, streams_boost::system::error_code& ec)
  {
    return service_impl_.use_certificate_chain_file(impl, filename, ec);
  }

  /// Use a private key from a file.
  streams_boost::system::error_code use_private_key_file(impl_type& impl,
      const std::string& filename, context_base::file_format format,
      streams_boost::system::error_code& ec)
  {
    return service_impl_.use_private_key_file(impl, filename, format, ec);
  }

  /// Use an RSA private key from a file.
  streams_boost::system::error_code use_rsa_private_key_file(impl_type& impl,
      const std::string& filename, context_base::file_format format,
      streams_boost::system::error_code& ec)
  {
    return service_impl_.use_rsa_private_key_file(impl, filename, format, ec);
  }

  /// Use the specified file to obtain the temporary Diffie-Hellman parameters.
  streams_boost::system::error_code use_tmp_dh_file(impl_type& impl,
      const std::string& filename, streams_boost::system::error_code& ec)
  {
    return service_impl_.use_tmp_dh_file(impl, filename, ec);
  }

  /// Set the password callback.
  template <typename PasswordCallback>
  streams_boost::system::error_code set_password_callback(impl_type& impl,
      PasswordCallback callback, streams_boost::system::error_code& ec)
  {
    return service_impl_.set_password_callback(impl, callback, ec);
  }

private:
  // The service that provides the platform-specific implementation.
  service_impl_type& service_impl_;
};

} // namespace ssl
} // namespace asio
} // namespace streams_boost

#include <streams_boost/asio/detail/pop_options.hpp>

#endif // STREAMS_BOOST_ASIO_SSL_CONTEXT_SERVICE_HPP
