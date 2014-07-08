//  (C) Copyright John Maddock 2001. 
//  (C) Copyright Darin Adler 2001. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org for most recent version.

//  Metrowerks standard library:

#ifndef __MSL_CPP__
#  include <streams_boost/config/no_tr1/utility.hpp>
#  ifndef __MSL_CPP__
#     error This is not the MSL standard library!
#  endif
#endif

#if __MSL_CPP__ >= 0x6000  // Pro 6
#  define STREAMS_BOOST_HAS_HASH
#  define STREAMS_BOOST_STD_EXTENSION_NAMESPACE Metrowerks
#endif
#define STREAMS_BOOST_HAS_SLIST

#if __MSL_CPP__ < 0x6209
#  define STREAMS_BOOST_NO_STD_MESSAGES
#endif

// check C lib version for <stdint.h>
#include <cstddef>

#if defined(__MSL__) && (__MSL__ >= 0x5000)
#  define STREAMS_BOOST_HAS_STDINT_H
#  if !defined(__PALMOS_TRAPS__)
#    define STREAMS_BOOST_HAS_UNISTD_H
#  endif
   // boilerplate code:
#  include <streams_boost/config/posix_features.hpp>
#endif

#if defined(_MWMT) || _MSL_THREADSAFE
#  define STREAMS_BOOST_HAS_THREADS
#endif

#ifdef _MSL_NO_EXPLICIT_FUNC_TEMPLATE_ARG
#  define STREAMS_BOOST_NO_STD_USE_FACET
#  define STREAMS_BOOST_HAS_TWO_ARG_USE_FACET
#endif

//  C++0x headers not yet implemented
//
#  define STREAMS_BOOST_NO_0X_HDR_ARRAY
#  define STREAMS_BOOST_NO_0X_HDR_CHRONO
#  define STREAMS_BOOST_NO_0X_HDR_CODECVT
#  define STREAMS_BOOST_NO_0X_HDR_CONCEPTS
#  define STREAMS_BOOST_NO_0X_HDR_CONDITION_VARIABLE
#  define STREAMS_BOOST_NO_0X_HDR_CONTAINER_CONCEPTS
#  define STREAMS_BOOST_NO_0X_HDR_FORWARD_LIST
#  define STREAMS_BOOST_NO_0X_HDR_FUTURE
#  define STREAMS_BOOST_NO_0X_HDR_INITIALIZER_LIST
#  define STREAMS_BOOST_NO_0X_HDR_ITERATOR_CONCEPTS
#  define STREAMS_BOOST_NO_0X_HDR_MEMORY_CONCEPTS
#  define STREAMS_BOOST_NO_0X_HDR_MUTEX
#  define STREAMS_BOOST_NO_0X_HDR_RANDOM
#  define STREAMS_BOOST_NO_0X_HDR_RATIO
#  define STREAMS_BOOST_NO_0X_HDR_REGEX
#  define STREAMS_BOOST_NO_0X_HDR_SYSTEM_ERROR
#  define STREAMS_BOOST_NO_0X_HDR_THREAD
#  define STREAMS_BOOST_NO_0X_HDR_TUPLE
#  define STREAMS_BOOST_NO_0X_HDR_TYPE_TRAITS
#  define STREAMS_BOOST_NO_STD_UNORDERED        // deprecated; see following
#  define STREAMS_BOOST_NO_0X_HDR_UNORDERED_MAP
#  define STREAMS_BOOST_NO_0X_HDR_UNORDERED_SET

#define STREAMS_BOOST_STDLIB "Metrowerks Standard Library version " STREAMS_BOOST_STRINGIZE(__MSL_CPP__)









