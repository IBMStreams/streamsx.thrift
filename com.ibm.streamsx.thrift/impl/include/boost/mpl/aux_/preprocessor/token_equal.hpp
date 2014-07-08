
#ifndef STREAMS_BOOST_MPL_AUX_PREPROCESSOR_TOKEN_EQUAL_HPP_INCLUDED
#define STREAMS_BOOST_MPL_AUX_PREPROCESSOR_TOKEN_EQUAL_HPP_INCLUDED

// Copyright Paul Mensonides 2003
// Copyright Aleksey Gurtovoy 2003-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: token_equal.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/aux_/preprocessor/is_seq.hpp>

#include <streams_boost/preprocessor/if.hpp>
#include <streams_boost/preprocessor/logical/bitand.hpp>
#include <streams_boost/preprocessor/logical/compl.hpp>
#include <streams_boost/preprocessor/tuple/eat.hpp>
#include <streams_boost/preprocessor/cat.hpp>

// compares tokens 'a' and 'b' for equality:
//
//   #define STREAMS_BOOST_MPL_PP_TOKEN_EQUAL_apple(x) x
//   #define STREAMS_BOOST_MPL_PP_TOKEN_EQUAL_orange(x) x
//
//   STREAMS_BOOST_PP_ASSERT( STREAMS_BOOST_PP_NOT( STREAMS_BOOST_MPL_PP_TOKEN_EQUAL(apple, abc) ) )
//   STREAMS_BOOST_PP_ASSERT( STREAMS_BOOST_PP_NOT( STREAMS_BOOST_MPL_PP_TOKEN_EQUAL(abc, apple) ) )
//   STREAMS_BOOST_PP_ASSERT( STREAMS_BOOST_PP_NOT( STREAMS_BOOST_MPL_PP_TOKEN_EQUAL(apple, orange) ) )
//   STREAMS_BOOST_PP_ASSERT( STREAMS_BOOST_MPL_PP_TOKEN_EQUAL(apple, apple) )
//   STREAMS_BOOST_PP_ASSERT( STREAMS_BOOST_MPL_PP_TOKEN_EQUAL(orange, orange) )

#define STREAMS_BOOST_MPL_PP_TOKEN_EQUAL(a, b) \
    STREAMS_BOOST_PP_IIF( \
        STREAMS_BOOST_PP_BITAND( \
              STREAMS_BOOST_MPL_PP_IS_SEQ( STREAMS_BOOST_PP_CAT(STREAMS_BOOST_MPL_PP_TOKEN_EQUAL_, a)((unused)) ) \
            , STREAMS_BOOST_MPL_PP_IS_SEQ( STREAMS_BOOST_PP_CAT(STREAMS_BOOST_MPL_PP_TOKEN_EQUAL_, b)((unused)) ) \
            ) \
        , STREAMS_BOOST_MPL_PP_TOKEN_EQUAL_I \
        , 0 STREAMS_BOOST_PP_TUPLE_EAT(2) \
        )(a, b) \
/**/

#define STREAMS_BOOST_MPL_PP_TOKEN_EQUAL_I(a, b) \
    STREAMS_BOOST_PP_COMPL(STREAMS_BOOST_MPL_PP_IS_SEQ( \
        STREAMS_BOOST_MPL_PP_TOKEN_EQUAL_ ## a( \
            STREAMS_BOOST_MPL_PP_TOKEN_EQUAL_ ## b \
            )((unused)) \
        )) \
/**/

#endif // STREAMS_BOOST_MPL_AUX_PREPROCESSOR_TOKEN_EQUAL_HPP_INCLUDED
