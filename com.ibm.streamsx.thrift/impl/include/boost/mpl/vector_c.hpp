
#ifndef STREAMS_BOOST_MPL_VECTOR_C_HPP_INCLUDED
#define STREAMS_BOOST_MPL_VECTOR_C_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2008
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: vector_c.hpp 49271 2008-10-11 06:46:00Z agurtovoy $
// $Date: 2008-10-11 02:46:00 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49271 $

#if !defined(STREAMS_BOOST_MPL_PREPROCESSING_MODE)
#   include <streams_boost/mpl/limits/vector.hpp>
#   include <streams_boost/mpl/aux_/nttp_decl.hpp>
#   include <streams_boost/mpl/aux_/config/preprocessor.hpp>

#   include <streams_boost/preprocessor/inc.hpp>
#   include <streams_boost/preprocessor/cat.hpp>
#   include <streams_boost/preprocessor/stringize.hpp>

#if !defined(STREAMS_BOOST_NEEDS_TOKEN_PASTING_OP_FOR_TOKENS_JUXTAPOSING)
#   define AUX778076_VECTOR_C_HEADER \
    STREAMS_BOOST_PP_CAT(STREAMS_BOOST_PP_CAT(vector,STREAMS_BOOST_MPL_LIMIT_VECTOR_SIZE),_c).hpp \
    /**/
#else
#   define AUX778076_VECTOR_C_HEADER \
    STREAMS_BOOST_PP_CAT(STREAMS_BOOST_PP_CAT(vector,STREAMS_BOOST_MPL_LIMIT_VECTOR_SIZE),_c)##.hpp \
    /**/
#endif

#   include STREAMS_BOOST_PP_STRINGIZE(streams_boost/mpl/vector/AUX778076_VECTOR_C_HEADER)
#   undef AUX778076_VECTOR_C_HEADER
#   include <climits>
#endif

#include <streams_boost/mpl/aux_/config/use_preprocessed.hpp>

#if !defined(STREAMS_BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS) \
    && !defined(STREAMS_BOOST_MPL_PREPROCESSING_MODE)

#   define STREAMS_BOOST_MPL_PREPROCESSED_HEADER vector_c.hpp
#   include <streams_boost/mpl/aux_/include_preprocessed.hpp>

#else

#   include <streams_boost/mpl/limits/vector.hpp>

#   define AUX778076_SEQUENCE_NAME vector_c
#   define AUX778076_SEQUENCE_LIMIT STREAMS_BOOST_MPL_LIMIT_VECTOR_SIZE
#   define AUX778076_SEQUENCE_NAME_N(n) STREAMS_BOOST_PP_CAT(STREAMS_BOOST_PP_CAT(vector,n),_c)
#   define AUX778076_SEQUENCE_CONVERT_CN_TO(z,n,TARGET) TARGET(STREAMS_BOOST_PP_CAT(C,n))
#   define AUX778076_SEQUENCE_INTEGRAL_WRAPPER
#   include <streams_boost/mpl/aux_/sequence_wrapper.hpp>

#endif // STREAMS_BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#endif // STREAMS_BOOST_MPL_VECTOR_C_HPP_INCLUDED
