// Boost.Range library
//
//  Copyright Thorsten Ottosen 2003-2004. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.streams_boost.org/libs/range/
//

#ifndef STREAMS_BOOST_RANGE_CONFIG_HPP
#define STREAMS_BOOST_RANGE_CONFIG_HPP

#include <streams_boost/detail/workaround.hpp>

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

#include <streams_boost/config.hpp>

#ifdef STREAMS_BOOST_RANGE_DEDUCED_TYPENAME
#error "macro already defined!"
#endif

#if STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x564))
# define STREAMS_BOOST_RANGE_DEDUCED_TYPENAME typename
#else
# if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, == 1300) && !defined(_MSC_EXTENSIONS)
#  define STREAMS_BOOST_RANGE_DEDUCED_TYPENAME typename
# else
#  define STREAMS_BOOST_RANGE_DEDUCED_TYPENAME STREAMS_BOOST_DEDUCED_TYPENAME
# endif
#endif

#ifdef STREAMS_BOOST_RANGE_NO_ARRAY_SUPPORT
#error "macro already defined!"
#endif

#if STREAMS_BOOST_WORKAROUND( STREAMS_BOOST_MSVC, < 1300 ) || STREAMS_BOOST_WORKAROUND( __MWERKS__, <= 0x3003 )
#define STREAMS_BOOST_RANGE_NO_ARRAY_SUPPORT 1
#endif

#ifdef STREAMS_BOOST_RANGE_NO_ARRAY_SUPPORT
#define STREAMS_BOOST_RANGE_ARRAY_REF() (streams_boost_range_array)
#define STREAMS_BOOST_RANGE_NO_STATIC_ASSERT
#else
#define STREAMS_BOOST_RANGE_ARRAY_REF() (&streams_boost_range_array)
#endif



#endif

