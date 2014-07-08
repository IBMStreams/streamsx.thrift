
#ifndef STREAMS_BOOST_MPL_SET_SET30_HPP_INCLUDED
#define STREAMS_BOOST_MPL_SET_SET30_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
// Copyright David Abrahams 2003-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: set30.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#if !defined(STREAMS_BOOST_MPL_PREPROCESSING_MODE)
#   include <streams_boost/mpl/set/set20.hpp>
#endif

#include <streams_boost/mpl/aux_/config/use_preprocessed.hpp>

#if !defined(STREAMS_BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS) \
    && !defined(STREAMS_BOOST_MPL_PREPROCESSING_MODE)

#   define STREAMS_BOOST_MPL_PREPROCESSED_HEADER set30.hpp
#   include <streams_boost/mpl/set/aux_/include_preprocessed.hpp>

#else

#   include <streams_boost/preprocessor/iterate.hpp>

namespace streams_boost { namespace mpl {

#   define STREAMS_BOOST_PP_ITERATION_PARAMS_1 \
    (3,(21, 30, <streams_boost/mpl/set/aux_/numbered.hpp>))
#   include STREAMS_BOOST_PP_ITERATE()

}}

#endif // STREAMS_BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS

#endif // STREAMS_BOOST_MPL_SET_SET30_HPP_INCLUDED