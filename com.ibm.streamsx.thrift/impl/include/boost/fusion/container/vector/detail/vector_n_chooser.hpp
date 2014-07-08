/*=============================================================================
    Copyright (c) 2001-2006 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef STREAMS_BOOST_PP_IS_ITERATING
#if !defined(FUSION_VECTOR_N_CHOOSER_07072005_1248)
#define FUSION_VECTOR_N_CHOOSER_07072005_1248

#include <streams_boost/fusion/container/vector/limits.hpp>

//  include vector0..N where N is FUSION_MAX_VECTOR_SIZE
#include <streams_boost/fusion/container/vector/vector10.hpp>
#if (FUSION_MAX_VECTOR_SIZE > 10)
#include <streams_boost/fusion/container/vector/vector20.hpp>
#endif
#if (FUSION_MAX_VECTOR_SIZE > 20)
#include <streams_boost/fusion/container/vector/vector30.hpp>
#endif
#if (FUSION_MAX_VECTOR_SIZE > 30)
#include <streams_boost/fusion/container/vector/vector40.hpp>
#endif
#if (FUSION_MAX_VECTOR_SIZE > 40)
#include <streams_boost/fusion/container/vector/vector50.hpp>
#endif

#include <streams_boost/preprocessor/cat.hpp>
#include <streams_boost/preprocessor/arithmetic/dec.hpp>
#include <streams_boost/preprocessor/arithmetic/sub.hpp>
#include <streams_boost/preprocessor/facilities/intercept.hpp>
#include <streams_boost/preprocessor/repetition/enum_params.hpp>
#include <streams_boost/preprocessor/repetition/enum_trailing_params.hpp>

namespace streams_boost { namespace fusion
{
    struct void_;
}}

namespace streams_boost { namespace fusion { namespace detail
{
    template <STREAMS_BOOST_PP_ENUM_PARAMS(FUSION_MAX_VECTOR_SIZE, typename T)>
    struct vector_n_chooser
    {
        typedef STREAMS_BOOST_PP_CAT(vector, FUSION_MAX_VECTOR_SIZE)<STREAMS_BOOST_PP_ENUM_PARAMS(FUSION_MAX_VECTOR_SIZE, T)> type;
    };

    template <>
    struct vector_n_chooser<STREAMS_BOOST_PP_ENUM_PARAMS(FUSION_MAX_VECTOR_SIZE, void_ STREAMS_BOOST_PP_INTERCEPT)>
    {
        typedef vector0<> type;
    };

#define STREAMS_BOOST_PP_FILENAME_1 \
    <streams_boost/fusion/container/vector/detail/vector_n_chooser.hpp>
#define STREAMS_BOOST_PP_ITERATION_LIMITS (1, STREAMS_BOOST_PP_DEC(FUSION_MAX_VECTOR_SIZE))
#include STREAMS_BOOST_PP_ITERATE()

}}}

#endif

///////////////////////////////////////////////////////////////////////////////
//
//  Preprocessor vertical repetition code
//
///////////////////////////////////////////////////////////////////////////////
#else // defined(STREAMS_BOOST_PP_IS_ITERATING)

#define N STREAMS_BOOST_PP_ITERATION()

    template <STREAMS_BOOST_PP_ENUM_PARAMS(N, typename T)>
    struct vector_n_chooser<
        STREAMS_BOOST_PP_ENUM_PARAMS(N, T)
        STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(STREAMS_BOOST_PP_SUB(FUSION_MAX_VECTOR_SIZE, N), void_ STREAMS_BOOST_PP_INTERCEPT)>
    {
        typedef STREAMS_BOOST_PP_CAT(vector, N)<STREAMS_BOOST_PP_ENUM_PARAMS(N, T)> type;
    };

#undef N
#endif // defined(STREAMS_BOOST_PP_IS_ITERATING)
