
#ifndef STREAMS_BOOST_MPL_AUX_CONFIG_PP_COUNTER_HPP_INCLUDED
#define STREAMS_BOOST_MPL_AUX_CONFIG_PP_COUNTER_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2006
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: pp_counter.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#if !defined(STREAMS_BOOST_MPL_AUX_PP_COUNTER)
#   include <streams_boost/mpl/aux_/config/msvc.hpp>
#   if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, >= 1300)
#       define STREAMS_BOOST_MPL_AUX_PP_COUNTER() __COUNTER__
#   else
#       define STREAMS_BOOST_MPL_AUX_PP_COUNTER() __LINE__
#   endif
#endif

#endif // STREAMS_BOOST_MPL_AUX_CONFIG_PP_COUNTER_HPP_INCLUDED
