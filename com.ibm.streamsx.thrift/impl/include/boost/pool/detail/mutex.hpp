// Copyright (C) 2000 Stephen Cleary
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org for updates, documentation, and revision history.

#ifndef STREAMS_BOOST_POOL_MUTEX_HPP
#define STREAMS_BOOST_POOL_MUTEX_HPP

#include <streams_boost/config.hpp>  // for workarounds

// Extremely Light-Weight wrapper classes for OS thread synchronization

// Configuration: for now, we just choose between pthread or Win32 mutexes or none

#define STREAMS_BOOST_MUTEX_HELPER_NONE         0
#define STREAMS_BOOST_MUTEX_HELPER_WIN32        1
#define STREAMS_BOOST_MUTEX_HELPER_PTHREAD      2

#if !defined(STREAMS_BOOST_HAS_THREADS) && !defined(STREAMS_BOOST_NO_MT)
# define STREAMS_BOOST_NO_MT
#endif

#ifdef STREAMS_BOOST_NO_MT
  // No multithreading -> make locks into no-ops
  #define STREAMS_BOOST_MUTEX_HELPER STREAMS_BOOST_MUTEX_HELPER_NONE
#else
  #ifdef STREAMS_BOOST_WINDOWS
    #define STREAMS_BOOST_MUTEX_HELPER STREAMS_BOOST_MUTEX_HELPER_WIN32
  #else
    #if defined(STREAMS_BOOST_HAS_UNISTD_H)
      #include <unistd.h>
    #endif
    #if defined(_POSIX_THREADS) || defined(STREAMS_BOOST_HAS_PTHREADS)
      #define STREAMS_BOOST_MUTEX_HELPER STREAMS_BOOST_MUTEX_HELPER_PTHREAD
    #endif
  #endif
#endif

#ifndef STREAMS_BOOST_MUTEX_HELPER
  #error Unable to determine platform mutex type; define STREAMS_BOOST_NO_MT to assume single-threaded
#endif

#ifndef STREAMS_BOOST_NO_MT
# ifdef STREAMS_BOOST_WINDOWS
#  include <windows.h>
# endif
# if defined(_POSIX_THREADS) || defined(STREAMS_BOOST_HAS_PTHREADS)
#  include <pthread.h>
# endif
#endif

namespace streams_boost {

namespace details {
namespace pool {

#ifndef STREAMS_BOOST_NO_MT

#ifdef STREAMS_BOOST_WINDOWS

class win32_mutex
{
  private:
    ::CRITICAL_SECTION mtx;

    win32_mutex(const win32_mutex &);
    void operator=(const win32_mutex &);

  public:
    win32_mutex()
    { ::InitializeCriticalSection(&mtx); }

    ~win32_mutex()
    { ::DeleteCriticalSection(&mtx); }

    void lock()
    { ::EnterCriticalSection(&mtx); }

    void unlock()
    { ::LeaveCriticalSection(&mtx); }
};

#endif // defined(STREAMS_BOOST_WINDOWS)

#if defined(_POSIX_THREADS) || defined(STREAMS_BOOST_HAS_PTHREADS)

class pthread_mutex
{
  private:
    ::pthread_mutex_t mtx;

    pthread_mutex(const pthread_mutex &);
    void operator=(const pthread_mutex &);

  public:
    pthread_mutex()
    { ::pthread_mutex_init(&mtx, 0); }

    ~pthread_mutex()
    { ::pthread_mutex_destroy(&mtx); }

    void lock()
    { ::pthread_mutex_lock(&mtx); }

    void unlock()
    { ::pthread_mutex_unlock(&mtx); }
};

#endif // defined(_POSIX_THREADS) || defined(STREAMS_BOOST_HAS_PTHREADS)

#endif // !defined(STREAMS_BOOST_NO_MT)

class null_mutex
{
  private:
    null_mutex(const null_mutex &);
    void operator=(const null_mutex &);

  public:
    null_mutex() { }

    static void lock() { }
    static void unlock() { }
};

#if STREAMS_BOOST_MUTEX_HELPER == STREAMS_BOOST_MUTEX_HELPER_NONE
  typedef null_mutex default_mutex;
#elif STREAMS_BOOST_MUTEX_HELPER == STREAMS_BOOST_MUTEX_HELPER_WIN32
  typedef win32_mutex default_mutex;
#elif STREAMS_BOOST_MUTEX_HELPER == STREAMS_BOOST_MUTEX_HELPER_PTHREAD
  typedef pthread_mutex default_mutex;
#endif

} // namespace pool
} // namespace details

} // namespace streams_boost

#undef STREAMS_BOOST_MUTEX_HELPER_WIN32
#undef STREAMS_BOOST_MUTEX_HELPER_PTHREAD
#undef STREAMS_BOOST_MUTEX_HELPER_NONE
#undef STREAMS_BOOST_MUTEX_HELPER

#endif
