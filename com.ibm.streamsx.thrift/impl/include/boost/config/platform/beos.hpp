//  (C) Copyright John Maddock 2001. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org for most recent version.

//  BeOS specific config options:

#define STREAMS_BOOST_PLATFORM "BeOS"

#define STREAMS_BOOST_NO_CWCHAR
#define STREAMS_BOOST_NO_CWCTYPE
#define STREAMS_BOOST_HAS_UNISTD_H

#define STREAMS_BOOST_HAS_BETHREADS

#ifndef STREAMS_BOOST_DISABLE_THREADS
#  define STREAMS_BOOST_HAS_THREADS
#endif

// boilerplate code:
#include <streams_boost/config/posix_features.hpp>
 


