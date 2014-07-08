//  (C) Copyright John Maddock 2001 - 2003. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org for most recent version.

//  cygwin specific config options:

#define STREAMS_BOOST_PLATFORM "Cygwin"
#define STREAMS_BOOST_NO_CWCTYPE
#define STREAMS_BOOST_NO_CWCHAR
#define STREAMS_BOOST_NO_SWPRINTF
#define STREAMS_BOOST_HAS_DIRENT_H
#define STREAMS_BOOST_HAS_LOG1P
#define STREAMS_BOOST_HAS_EXPM1

//
// Threading API:
// See if we have POSIX threads, if we do use them, otherwise
// revert to native Win threads.
#define STREAMS_BOOST_HAS_UNISTD_H
#include <unistd.h>
#if defined(_POSIX_THREADS) && (_POSIX_THREADS+0 >= 0) && !defined(STREAMS_BOOST_HAS_WINTHREADS)
#  define STREAMS_BOOST_HAS_PTHREADS
#  define STREAMS_BOOST_HAS_SCHED_YIELD
#  define STREAMS_BOOST_HAS_GETTIMEOFDAY
#  define STREAMS_BOOST_HAS_PTHREAD_MUTEXATTR_SETTYPE
#  define STREAMS_BOOST_HAS_SIGACTION
#else
#  if !defined(STREAMS_BOOST_HAS_WINTHREADS)
#     define STREAMS_BOOST_HAS_WINTHREADS
#  endif
#  define STREAMS_BOOST_HAS_FTIME
#endif

//
// find out if we have a stdint.h, there should be a better way to do this:
//
#include <sys/types.h>
#ifdef _STDINT_H
#define STREAMS_BOOST_HAS_STDINT_H
#endif

// boilerplate code:
#include <streams_boost/config/posix_features.hpp>
 




