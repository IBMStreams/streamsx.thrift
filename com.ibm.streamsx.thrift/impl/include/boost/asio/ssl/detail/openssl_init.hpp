//
// openssl_init.hpp
// ~~~~~~~~~~~~~~~~
//
// Copyright (c) 2005 Voipster / Indrek dot Juhani at voipster dot com
// Copyright (c) 2005-2010 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//

#ifndef STREAMS_BOOST_ASIO_SSL_DETAIL_OPENSSL_INIT_HPP
#define STREAMS_BOOST_ASIO_SSL_DETAIL_OPENSSL_INIT_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <streams_boost/asio/detail/push_options.hpp>

#include <streams_boost/asio/detail/push_options.hpp>
#include <cstring>
#include <vector>
#include <streams_boost/assert.hpp>
#include <streams_boost/config.hpp>
#include <streams_boost/shared_ptr.hpp>
#include <streams_boost/asio/detail/pop_options.hpp>

#include <streams_boost/asio/detail/mutex.hpp>
#include <streams_boost/asio/detail/tss_ptr.hpp>
#include <streams_boost/asio/ssl/detail/openssl_types.hpp>

namespace streams_boost {
namespace asio {
namespace ssl {
namespace detail {

template <bool Do_Init = true>
class openssl_init
  : private streams_boost::noncopyable
{
private:
  // Structure to perform the actual initialisation.
  class do_init
  {
  public:
    do_init()
    {
      if (Do_Init)
      {
        ::SSL_library_init();
        ::SSL_load_error_strings();        
        ::OpenSSL_add_ssl_algorithms();

        mutexes_.resize(::CRYPTO_num_locks());
        for (size_t i = 0; i < mutexes_.size(); ++i)
          mutexes_[i].reset(new streams_boost::asio::detail::mutex);
        ::CRYPTO_set_locking_callback(&do_init::openssl_locking_func);
        ::CRYPTO_set_id_callback(&do_init::openssl_id_func);
      }
    }

    ~do_init()
    {
      if (Do_Init)
      {
        ::CRYPTO_set_id_callback(0);
        ::CRYPTO_set_locking_callback(0);
        ::ERR_free_strings();
        ::ERR_remove_state(0);
        ::EVP_cleanup();
        ::CRYPTO_cleanup_all_ex_data();
        ::CONF_modules_unload(1);
        ::ENGINE_cleanup();
      }
    }

    // Helper function to manage a do_init singleton. The static instance of the
    // openssl_init object ensures that this function is always called before
    // main, and therefore before any other threads can get started. The do_init
    // instance must be static in this function to ensure that it gets
    // initialised before any other global objects try to use it.
    static streams_boost::shared_ptr<do_init> instance()
    {
      static streams_boost::shared_ptr<do_init> init(new do_init);
      return init;
    }

  private:
    static unsigned long openssl_id_func()
    {
#if defined(STREAMS_BOOST_WINDOWS) || defined(__CYGWIN__)
      return ::GetCurrentThreadId();
#else // defined(STREAMS_BOOST_WINDOWS) || defined(__CYGWIN__)
      void* id = instance()->thread_id_;
      if (id == 0)
        instance()->thread_id_ = id = &id; // Ugh.
      STREAMS_BOOST_ASSERT(sizeof(unsigned long) >= sizeof(void*));
      return reinterpret_cast<unsigned long>(id);
#endif // defined(STREAMS_BOOST_WINDOWS) || defined(__CYGWIN__)
    }

    static void openssl_locking_func(int mode, int n, 
      const char* /*file*/, int /*line*/)
    {
      if (mode & CRYPTO_LOCK)
        instance()->mutexes_[n]->lock();
      else
        instance()->mutexes_[n]->unlock();
    }

    // Mutexes to be used in locking callbacks.
    std::vector<streams_boost::shared_ptr<streams_boost::asio::detail::mutex> > mutexes_;

#if !defined(STREAMS_BOOST_WINDOWS) && !defined(__CYGWIN__)
    // The thread identifiers to be used by openssl.
    streams_boost::asio::detail::tss_ptr<void> thread_id_;
#endif // !defined(STREAMS_BOOST_WINDOWS) && !defined(__CYGWIN__)
  };

public:
  // Constructor.
  openssl_init()
    : ref_(do_init::instance())
  {
    using namespace std; // For memmove.

    // Ensure openssl_init::instance_ is linked in.
    openssl_init* tmp = &instance_;
    memmove(&tmp, &tmp, sizeof(openssl_init*));
  }

  // Destructor.
  ~openssl_init()
  {
  }

private:
  // Instance to force initialisation of openssl at global scope.
  static openssl_init instance_;

  // Reference to singleton do_init object to ensure that openssl does not get
  // cleaned up until the last user has finished with it.
  streams_boost::shared_ptr<do_init> ref_;
};

template <bool Do_Init>
openssl_init<Do_Init> openssl_init<Do_Init>::instance_;

} // namespace detail
} // namespace ssl
} // namespace asio
} // namespace streams_boost

#include <streams_boost/asio/detail/pop_options.hpp>

#endif // STREAMS_BOOST_ASIO_SSL_DETAIL_OPENSSL_INIT_HPP
