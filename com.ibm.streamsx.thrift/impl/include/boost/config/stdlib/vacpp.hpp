//  (C) Copyright John Maddock 2001 - 2002. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org for most recent version.

#if __IBMCPP__ <= 501
#  define STREAMS_BOOST_NO_STD_ALLOCATOR
#endif

#define STREAMS_BOOST_HAS_MACRO_USE_FACET
#define STREAMS_BOOST_NO_STD_MESSAGES

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

#define STREAMS_BOOST_STDLIB "Visual Age default standard library"



