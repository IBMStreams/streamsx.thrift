
#ifndef STREAMS_BOOST_MPL_AUX_STATIC_CAST_HPP_INCLUDED
#define STREAMS_BOOST_MPL_AUX_STATIC_CAST_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2001-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: static_cast.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/aux_/config/workaround.hpp>

#if STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x561)) \
 || STREAMS_BOOST_WORKAROUND(__GNUC__, < 3) \
 || STREAMS_BOOST_WORKAROUND(__MWERKS__, <= 0x3001)
#   define STREAMS_BOOST_MPL_AUX_STATIC_CAST(T, expr) (T)(expr)
#else
#   define STREAMS_BOOST_MPL_AUX_STATIC_CAST(T, expr) static_cast<T>(expr)
#endif

#endif // STREAMS_BOOST_MPL_AUX_STATIC_CAST_HPP_INCLUDED
