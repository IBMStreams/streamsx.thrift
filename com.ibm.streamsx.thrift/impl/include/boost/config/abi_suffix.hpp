//  abi_sufffix header  -------------------------------------------------------//

// (c) Copyright John Maddock 2003
   
// Use, modification and distribution are subject to the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt).

// This header should be #included AFTER code that was preceded by a #include
// <streams_boost/config/abi_prefix.hpp>.

#ifndef STREAMS_BOOST_CONFIG_ABI_PREFIX_HPP
# error Header streams_boost/config/abi_suffix.hpp must only be used after streams_boost/config/abi_prefix.hpp
#else
# undef STREAMS_BOOST_CONFIG_ABI_PREFIX_HPP
#endif

// the suffix header occurs after all of our code:
#ifdef STREAMS_BOOST_HAS_ABI_HEADERS
#  include STREAMS_BOOST_ABI_SUFFIX
#endif

#if defined( __BORLANDC__ )
#pragma nopushoptwarn
#endif


