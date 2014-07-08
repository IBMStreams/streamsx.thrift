//  (C) Copyright Jim Douglas 2005. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org for most recent version.

//  QNX specific config options:

#define STREAMS_BOOST_PLATFORM "QNX"

#define STREAMS_BOOST_HAS_UNISTD_H
#include <streams_boost/config/posix_features.hpp>

// QNX claims XOpen version 5 compatibility, but doesn't have an nl_types.h
// or log1p and expm1:
#undef  STREAMS_BOOST_HAS_NL_TYPES_H
#undef  STREAMS_BOOST_HAS_LOG1P
#undef  STREAMS_BOOST_HAS_EXPM1

#define STREAMS_BOOST_HAS_PTHREADS
#define STREAMS_BOOST_HAS_PTHREAD_MUTEXATTR_SETTYPE

#define STREAMS_BOOST_HAS_GETTIMEOFDAY
#define STREAMS_BOOST_HAS_CLOCK_GETTIME
#define STREAMS_BOOST_HAS_NANOSLEEP





