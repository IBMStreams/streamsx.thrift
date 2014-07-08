/*=============================================================================
    Copyright (c) 2001-2006 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef STREAMS_BOOST_PP_IS_ITERATING
#if !defined(FUSION_TUPLE_TIE_10032005_0846)
#define FUSION_TUPLE_TIE_10032005_0846

#include <streams_boost/preprocessor/iterate.hpp>
#include <streams_boost/preprocessor/cat.hpp>
#include <streams_boost/preprocessor/repetition/enum_params.hpp>
#include <streams_boost/preprocessor/repetition/enum_binary_params.hpp>
#include <streams_boost/fusion/tuple/tuple.hpp>

namespace streams_boost { namespace fusion
{
#define STREAMS_BOOST_FUSION_REF(z, n, data) STREAMS_BOOST_PP_CAT(T, n)&

#define STREAMS_BOOST_PP_FILENAME_1 <streams_boost/fusion/tuple/tuple_tie.hpp>
#define STREAMS_BOOST_PP_ITERATION_LIMITS (1, FUSION_MAX_VECTOR_SIZE)
#include STREAMS_BOOST_PP_ITERATE()
    
#undef STREAMS_BOOST_FUSION_REF

}}

#endif
#else // defined(STREAMS_BOOST_PP_IS_ITERATING)
///////////////////////////////////////////////////////////////////////////////
//
//  Preprocessor vertical repetition code
//
///////////////////////////////////////////////////////////////////////////////

#define N STREAMS_BOOST_PP_ITERATION()

    template <STREAMS_BOOST_PP_ENUM_PARAMS(N, typename T)>
    inline tuple<STREAMS_BOOST_PP_ENUM(N, STREAMS_BOOST_FUSION_REF, _)>
    tie(STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N, T, & _))
    {
        return tuple<STREAMS_BOOST_PP_ENUM(N, STREAMS_BOOST_FUSION_REF, _)>(
            STREAMS_BOOST_PP_ENUM_PARAMS(N, _));
    }

#undef N
#endif // defined(STREAMS_BOOST_PP_IS_ITERATING)

