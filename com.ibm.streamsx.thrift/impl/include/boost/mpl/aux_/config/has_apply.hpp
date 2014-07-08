
#ifndef STREAMS_BOOST_MPL_AUX_CONFIG_HAS_APPLY_HPP_INCLUDED
#define STREAMS_BOOST_MPL_AUX_CONFIG_HAS_APPLY_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: has_apply.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/aux_/config/has_xxx.hpp>
#include <streams_boost/mpl/aux_/config/msvc.hpp>
#include <streams_boost/mpl/aux_/config/workaround.hpp>

#if !defined(STREAMS_BOOST_MPL_CFG_NO_HAS_APPLY) \
    && (   defined(STREAMS_BOOST_MPL_CFG_NO_HAS_XXX) \
        || STREAMS_BOOST_WORKAROUND(__EDG_VERSION__, < 300) \
        || STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, <= 1300) \
        || STREAMS_BOOST_WORKAROUND(__MWERKS__, STREAMS_BOOST_TESTED_AT(0x3202)) \
        )

#   define STREAMS_BOOST_MPL_CFG_NO_HAS_APPLY

#endif

#endif // STREAMS_BOOST_MPL_AUX_CONFIG_HAS_APPLY_HPP_INCLUDED
