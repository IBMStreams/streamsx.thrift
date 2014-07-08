
#ifndef STREAMS_BOOST_MPL_AUX_CONFIG_OPERATORS_HPP_INCLUDED
#define STREAMS_BOOST_MPL_AUX_CONFIG_OPERATORS_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2003-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: operators.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/aux_/config/gcc.hpp>
#include <streams_boost/mpl/aux_/config/msvc.hpp>
#include <streams_boost/mpl/aux_/config/workaround.hpp>

#if !defined(STREAMS_BOOST_MPL_CFG_USE_OPERATORS_OVERLOADING) \
    && ( STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, <= 1300) \
        || STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x610)) \
        || STREAMS_BOOST_WORKAROUND(__EDG_VERSION__, <= 245) \
        || STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MPL_CFG_GCC, <= 0x0295) \
        || STREAMS_BOOST_WORKAROUND(__IBMCPP__, STREAMS_BOOST_TESTED_AT(600)) \
        )

#   define STREAMS_BOOST_MPL_CFG_USE_OPERATORS_OVERLOADING

#endif

#endif // STREAMS_BOOST_MPL_AUX_CONFIG_OPERATORS_HPP_INCLUDED
