//  (C) Copyright John Maddock 2001 - 2003. 
//  (C) Copyright Jens Maurer 2003. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org for most recent version.

//  sun specific config options:

#define STREAMS_BOOST_PLATFORM "Sun Solaris"

#define STREAMS_BOOST_HAS_GETTIMEOFDAY

// boilerplate code:
#define STREAMS_BOOST_HAS_UNISTD_H
#include <streams_boost/config/posix_features.hpp>

//
// pthreads don't actually work with gcc unless _PTHREADS is defined:
//
#if defined(__GNUC__) && defined(_POSIX_THREADS) && !defined(_PTHREADS)
# undef STREAMS_BOOST_HAS_PTHREADS
#endif




