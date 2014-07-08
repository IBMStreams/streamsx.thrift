
#ifndef STREAMS_BOOST_MPL_AUX_COMMON_NAME_WKND_HPP_INCLUDED
#define STREAMS_BOOST_MPL_AUX_COMMON_NAME_WKND_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2002-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: common_name_wknd.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/aux_/config/workaround.hpp>

#if STREAMS_BOOST_WORKAROUND(__BORLANDC__, < 0x561)
// agurt, 12/nov/02: to suppress the bogus "Cannot have both a template class 
// and function named 'xxx'" diagnostic
#   define STREAMS_BOOST_MPL_AUX_COMMON_NAME_WKND(name) \
namespace name_##wknd { \
template< typename > void name(); \
} \
/**/

#else

#   define STREAMS_BOOST_MPL_AUX_COMMON_NAME_WKND(name) /**/

#endif // __BORLANDC__

#endif // STREAMS_BOOST_MPL_AUX_COMMON_NAME_WKND_HPP_INCLUDED
