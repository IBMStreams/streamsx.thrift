
#ifndef STREAMS_BOOST_MPL_AUX_CONFIG_DEPENDENT_NTTP_HPP_INCLUDED
#define STREAMS_BOOST_MPL_AUX_CONFIG_DEPENDENT_NTTP_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2002-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: dependent_nttp.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/aux_/config/gcc.hpp>
#include <streams_boost/mpl/aux_/config/workaround.hpp>

// GCC and EDG-based compilers incorrectly reject the following code:
//   template< typename T, T n > struct a;
//   template< typename T > struct b;
//   template< typename T, T n > struct b< a<T,n> > {};

#if    !defined(STREAMS_BOOST_MPL_CFG_NO_DEPENDENT_NONTYPE_PARAMETER_IN_PARTIAL_SPEC) \
    && !defined(STREAMS_BOOST_MPL_PREPROCESSING_MODE) \
    && (   STREAMS_BOOST_WORKAROUND(__EDG_VERSION__, STREAMS_BOOST_TESTED_AT(300)) \
        || STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MPL_CFG_GCC, STREAMS_BOOST_TESTED_AT(0x0302)) \
        )

#   define STREAMS_BOOST_MPL_CFG_NO_DEPENDENT_NONTYPE_PARAMETER_IN_PARTIAL_SPEC

#endif

#endif // STREAMS_BOOST_MPL_AUX_CONFIG_DEPENDENT_NTTP_HPP_INCLUDED
