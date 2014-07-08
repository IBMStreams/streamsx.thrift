/*=============================================================================
    Copyright (c) 2001-2006 Joel de Guzman
    Copyright (c) 2006 Dan Marsden

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef STREAMS_BOOST_PP_IS_ITERATING
#if !defined(FUSION_DEQUE_TIE_07192005_1242)
#define FUSION_DEQUE_TIE_07192005_1242

#include <streams_boost/preprocessor/iterate.hpp>
#include <streams_boost/preprocessor/cat.hpp>
#include <streams_boost/preprocessor/repetition/enum_params.hpp>
#include <streams_boost/preprocessor/repetition/enum_binary_params.hpp>
#include <streams_boost/preprocessor/repetition/enum_params_with_a_default.hpp>
#include <streams_boost/preprocessor/repetition/repeat_from_to.hpp>
#include <streams_boost/fusion/container/deque/deque.hpp>

namespace streams_boost { namespace fusion
{
    struct void_;
        
    namespace result_of
    {
        template <
            STREAMS_BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
                FUSION_MAX_DEQUE_SIZE, typename T, void_)
          , typename Extra = void_
        >
        struct deque_tie;
    }

#define STREAMS_BOOST_FUSION_REF(z, n, data) STREAMS_BOOST_PP_CAT(T, n)&

#define STREAMS_BOOST_PP_FILENAME_1 <streams_boost/fusion/container/generation/deque_tie.hpp>
#define STREAMS_BOOST_PP_ITERATION_LIMITS (1, FUSION_MAX_DEQUE_SIZE)
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

    namespace result_of
    {
        template <STREAMS_BOOST_PP_ENUM_PARAMS(N, typename T)>
#if defined(STREAMS_BOOST_NO_PARTIAL_SPECIALIZATION_IMPLICIT_DEFAULT_ARGS)
        #define TEXT(z, n, text) , text
        struct deque_tie< STREAMS_BOOST_PP_ENUM_PARAMS(N, T) STREAMS_BOOST_PP_REPEAT_FROM_TO(STREAMS_BOOST_PP_DEC(N), FUSION_MAX_DEQUE_SIZE, TEXT, void_) >
        #undef TEXT
#else
        struct deque_tie<STREAMS_BOOST_PP_ENUM_PARAMS(N, T)>
#endif
        {
            typedef deque<STREAMS_BOOST_PP_ENUM(N, STREAMS_BOOST_FUSION_REF, _)> type;
        };
    }

    template <STREAMS_BOOST_PP_ENUM_PARAMS(N, typename T)>
    inline deque<STREAMS_BOOST_PP_ENUM(N, STREAMS_BOOST_FUSION_REF, _)>
    deque_tie(STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N, T, & _))
    {
        return deque<STREAMS_BOOST_PP_ENUM(N, STREAMS_BOOST_FUSION_REF, _)>(
            STREAMS_BOOST_PP_ENUM_PARAMS(N, _));
    }

#undef N
#endif // defined(STREAMS_BOOST_PP_IS_ITERATING)

