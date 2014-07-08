//  (C) Copyright John Maddock 2002 - 2003. 
//  (C) Copyright Jens Maurer 2002 - 2003. 
//  (C) Copyright Beman Dawes 2002 - 2003. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org for most recent version.

//  Comeau STL:

#if !defined(__LIBCOMO__)
#  include <streams_boost/config/no_tr1/utility.hpp>
#  if !defined(__LIBCOMO__)
#      error "This is not the Comeau STL!"
#  endif
#endif

//
// std::streambuf<wchar_t> is non-standard
// NOTE: versions of libcomo prior to beta28 have octal version numbering,
// e.g. version 25 is 21 (dec)
#if __LIBCOMO_VERSION__ <= 22
#  define STREAMS_BOOST_NO_STD_WSTREAMBUF
#endif

#if (__LIBCOMO_VERSION__ <= 31) && defined(_WIN32)
#define STREAMS_BOOST_NO_SWPRINTF
#endif

#if __LIBCOMO_VERSION__ >= 31
#  define STREAMS_BOOST_HAS_HASH
#  define STREAMS_BOOST_HAS_SLIST
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

//
// Intrinsic type_traits support.
// The SGI STL has it's own __type_traits class, which
// has intrinsic compiler support with SGI's compilers.
// Whatever map SGI style type traits to streams_boost equivalents:
//
#define STREAMS_BOOST_HAS_SGI_TYPE_TRAITS

#define STREAMS_BOOST_STDLIB "Comeau standard library " STREAMS_BOOST_STRINGIZE(__LIBCOMO_VERSION__)


