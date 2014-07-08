
#ifndef STREAMS_BOOST_MPL_AUX_CONFIG_TYPEOF_HPP_INCLUDED
#define STREAMS_BOOST_MPL_AUX_CONFIG_TYPEOF_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2003-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: typeof.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/aux_/config/gcc.hpp>

#if !defined(STREAMS_BOOST_MPL_CFG_HAS_TYPEOF) \
    && !defined(STREAMS_BOOST_MPL_PREPROCESSING_MODE) \
    && (   defined(STREAMS_BOOST_MPL_CFG_GCC) && STREAMS_BOOST_MPL_CFG_GCC >= 0x0302 \
        || defined(__MWERKS__) && __MWERKS__ >= 0x3000 \
        )

#   define STREAMS_BOOST_MPL_CFG_HAS_TYPEOF

#endif


#if !defined(STREAMS_BOOST_MPL_CFG_TYPEOF_BASED_SEQUENCES) \
    && !defined(STREAMS_BOOST_MPL_PREPROCESSING_MODE) \
    && defined(STREAMS_BOOST_MPL_CFG_HAS_TYPEOF)

#   define STREAMS_BOOST_MPL_CFG_TYPEOF_BASED_SEQUENCES

#endif

#endif // STREAMS_BOOST_MPL_AUX_CONFIG_TYPEOF_HPP_INCLUDED
