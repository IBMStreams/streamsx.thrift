
#ifndef STREAMS_BOOST_MPL_LIST_C_HPP_INCLUDED
#define STREAMS_BOOST_MPL_LIST_C_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: list_c.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#if !defined(STREAMS_BOOST_MPL_PREPROCESSING_MODE)
#   include <streams_boost/mpl/limits/list.hpp>
#   include <streams_boost/mpl/aux_/nttp_decl.hpp>
#   include <streams_boost/mpl/aux_/config/preprocessor.hpp>

#   include <streams_boost/preprocessor/inc.hpp>
#   include <streams_boost/preprocessor/cat.hpp>
#   include <streams_boost/preprocessor/stringize.hpp>

#if !defined(STREAMS_BOOST_NEEDS_TOKEN_PASTING_OP_FOR_TOKENS_JUXTAPOSING)
#   define AUX778076_LIST_C_HEADER \
    STREAMS_BOOST_PP_CAT(STREAMS_BOOST_PP_CAT(list,STREAMS_BOOST_MPL_LIMIT_LIST_SIZE),_c).hpp \
    /**/
#else
#   define AUX778076_LIST_C_HEADER \
    STREAMS_BOOST_PP_CAT(STREAMS_BOOST_PP_CAT(list,STREAMS_BOOST_MPL_LIMIT_LIST_SIZE),_c)##.hpp \
    /**/
#endif

#   include STREAMS_BOOST_PP_STRINGIZE(streams_boost/mpl/list/AUX778076_LIST_C_HEADER)
#   undef AUX778076_LIST_C_HEADER
#   include <climits>
#endif

#include <streams_boost/mpl/aux_/config/use_preprocessed.hpp>

#if !defined(STREAMS_BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS) \
    && !defined(STREAMS_BOOST_MPL_PREPROCESSING_MODE)

#   define STREAMS_BOOST_MPL_PREPROCESSED_HEADER list_c.hpp
#   include <streams_boost/mpl/aux_/include_preprocessed.hpp>

#else

#   include <streams_boost/mpl/limits/list.hpp>

#   define AUX778076_SEQUENCE_NAME list_c
#   define AUX778076_SEQUENCE_LIMIT STREAMS_BOOST_MPL_LIMIT_LIST_SIZE
#   define AUX778076_SEQUENCE_NAME_N(n) STREAMS_BOOST_PP_CAT(STREAMS_BOOST_PP_CAT(list,n),_c)
#   define AUX778076_SEQUENCE_INTEGRAL_WRAPPER
#   include <streams_boost/mpl/aux_/sequence_wrapper.hpp>

#endif // STREAMS_BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#endif // STREAMS_BOOST_MPL_LIST_C_HPP_INCLUDED
