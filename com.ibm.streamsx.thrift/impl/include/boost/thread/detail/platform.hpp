// Copyright 2006 Roland Schwarz.
// (C) Copyright 2007 Anthony Williams
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// This work is a reimplementation along the design and ideas
// of William E. Kempf.

#ifndef STREAMS_BOOST_THREAD_RS06040501_HPP
#define STREAMS_BOOST_THREAD_RS06040501_HPP

// fetch compiler and platform configuration
#include <streams_boost/config.hpp>

// insist on threading support being available:
#include <streams_boost/config/requires_threads.hpp>

// choose platform
#if defined(linux) || defined(__linux) || defined(__linux__)
#  define STREAMS_BOOST_THREAD_LINUX
#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
#  define STREAMS_BOOST_THREAD_BSD
#elif defined(sun) || defined(__sun)
#  define STREAMS_BOOST_THREAD_SOLARIS
#elif defined(__sgi)
#  define STREAMS_BOOST_THREAD_IRIX
#elif defined(__hpux)
#  define STREAMS_BOOST_THREAD_HPUX
#elif defined(__CYGWIN__)
#  define STREAMS_BOOST_THREAD_CYGWIN
#elif defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
#  define STREAMS_BOOST_THREAD_WIN32
#elif defined(__BEOS__)
#  define STREAMS_BOOST_THREAD_BEOS
#elif defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__)
#  define STREAMS_BOOST_THREAD_MACOS
#elif defined(__IBMCPP__) || defined(_AIX)
#  define STREAMS_BOOST_THREAD_AIX
#elif defined(__amigaos__)
#  define STREAMS_BOOST_THREAD_AMIGAOS
#elif defined(__QNXNTO__)
#  define STREAMS_BOOST_THREAD_QNXNTO
#elif defined(unix) || defined(__unix) || defined(_XOPEN_SOURCE) || defined(_POSIX_SOURCE)
#       if defined(STREAMS_BOOST_HAS_PTHREADS) && !defined(STREAMS_BOOST_THREAD_POSIX)
#               define STREAMS_BOOST_THREAD_POSIX
#       endif
#endif

// For every supported platform add a new entry into the dispatch table below.
// STREAMS_BOOST_THREAD_POSIX is tested first, so on platforms where posix and native
// threading is available, the user may choose, by defining STREAMS_BOOST_THREAD_POSIX
// in her source. If a platform is known to support pthreads and no native
// port of streams_boost_thread is available just specify "pthread" in the
// dispatcher table. If there is no entry for a platform but pthreads is
// available on the platform, pthread is choosen as default. If nothing is
// available the preprocessor will fail with a diagnostic message.
 
#if defined(STREAMS_BOOST_THREAD_POSIX)
#  define STREAMS_BOOST_THREAD_PLATFORM_PTHREAD
#else
#  if defined(STREAMS_BOOST_THREAD_WIN32)
#       define STREAMS_BOOST_THREAD_PLATFORM_WIN32
#  elif defined(STREAMS_BOOST_HAS_PTHREADS)
#       define STREAMS_BOOST_THREAD_PLATFORM_PTHREAD
#  else
#       error "Sorry, no streams_boost threads are available for this platform."
#  endif
#endif

#endif // STREAMS_BOOST_THREAD_RS06040501_HPP
