
#ifndef STREAMS_BOOST_MPL_AUX_CONFIG_ARRAYS_HPP_INCLUDED
#define STREAMS_BOOST_MPL_AUX_CONFIG_ARRAYS_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2003-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: arrays.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/aux_/config/msvc.hpp>
#include <streams_boost/mpl/aux_/config/workaround.hpp>

#if    !defined(STREAMS_BOOST_MPL_CFG_NO_DEPENDENT_ARRAY_TYPES) \
    && !defined(STREAMS_BOOST_MPL_PREPROCESSING_MODE) \
    && ( STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x610)) \
        || STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, <= 1300) \
        )

#   define STREAMS_BOOST_MPL_CFG_NO_DEPENDENT_ARRAY_TYPES

#endif

#endif // STREAMS_BOOST_MPL_AUX_CONFIG_ARRAYS_HPP_INCLUDED
