/*=============================================================================
    Copyright (c) 2001-2006 Joel de Guzman
    Copyright (c) 2006 Dan Marsden

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef STREAMS_BOOST_PP_IS_ITERATING
#if !defined(FUSION_MAP_TIE_20060814_1116)
#define FUSION_MAP_TIE_20060814_1116

#include <streams_boost/preprocessor/iterate.hpp>
#include <streams_boost/preprocessor/repetition/enum_params.hpp>
#include <streams_boost/preprocessor/repetition/enum_binary_params.hpp>
#include <streams_boost/preprocessor/repetition/enum_params_with_a_default.hpp>
#include <streams_boost/preprocessor/repetition/repeat_from_to.hpp>
#include <streams_boost/fusion/container/map/map.hpp>
#include <streams_boost/fusion/container/map/limits.hpp>
#include <streams_boost/fusion/support/pair.hpp>
#include <streams_boost/fusion/container/generation/pair_tie.hpp>
#include <streams_boost/type_traits/add_reference.hpp>

namespace streams_boost { namespace fusion
{
    struct void_;
        
    namespace result_of
    {
        template <
            STREAMS_BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
                FUSION_MAX_MAP_SIZE, typename K, void_)
          , STREAMS_BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
                FUSION_MAX_MAP_SIZE, typename D, void_)
          , typename Extra = void_
        >
        struct map_tie;
            
        template <>
        struct map_tie<>
        {
            typedef map<> type;
        };
    }
    
    inline map<>
    map_tie()
    {
        return map<>();
    }

#define STREAMS_BOOST_FUSION_TIED_PAIR(z, n, data)                                                          \
    fusion::pair<                                                                                   \
        STREAMS_BOOST_PP_CAT(K, n)                                                                          \
      , typename add_reference<STREAMS_BOOST_PP_CAT(D, n)>::type>

#define STREAMS_BOOST_FUSION_PAIR_TIE(z, n, data)                                      \
    fusion::pair_tie<STREAMS_BOOST_PP_CAT(K, n)>(STREAMS_BOOST_PP_CAT(_, n))                   \

#define STREAMS_BOOST_PP_FILENAME_1 <streams_boost/fusion/container/generation/map_tie.hpp>
#define STREAMS_BOOST_PP_ITERATION_LIMITS (1, FUSION_MAX_MAP_SIZE)
#include STREAMS_BOOST_PP_ITERATE()

#undef STREAMS_BOOST_FUSION_PAIR
#undef STREAMS_BOOST_FUSION_MAKE_PAIR

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
        template <
            STREAMS_BOOST_PP_ENUM_PARAMS(N, typename K)
          , STREAMS_BOOST_PP_ENUM_PARAMS(N, typename D)
        >
#if defined(STREAMS_BOOST_NO_PARTIAL_SPECIALIZATION_IMPLICIT_DEFAULT_ARGS)
        #define TEXT(z, n, text) , text

        struct map_tie<STREAMS_BOOST_PP_ENUM_PARAMS(N, K), STREAMS_BOOST_PP_ENUM_PARAMS(N, D) STREAMS_BOOST_PP_REPEAT_FROM_TO(N, FUSION_MAX_MAP_SIZE, TEXT, void_) STREAMS_BOOST_PP_REPEAT_FROM_TO(STREAMS_BOOST_PP_DEC(N), FUSION_MAX_MAP_SIZE, TEXT, void_)>
        #undef TEXT
#else
        struct map_tie<STREAMS_BOOST_PP_ENUM_PARAMS(N, K), STREAMS_BOOST_PP_ENUM_PARAMS(N, D)>
#endif
        {
            typedef map<STREAMS_BOOST_PP_ENUM(N, STREAMS_BOOST_FUSION_TIED_PAIR, _)> type;
        };
    }

    template <
        STREAMS_BOOST_PP_ENUM_PARAMS(N, typename K)
      , STREAMS_BOOST_PP_ENUM_PARAMS(N, typename D)
    >
    inline map<STREAMS_BOOST_PP_ENUM(N, STREAMS_BOOST_FUSION_TIED_PAIR, _)>
    map_tie(STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N, D, & _))
    {
        return map<STREAMS_BOOST_PP_ENUM(N, STREAMS_BOOST_FUSION_TIED_PAIR, _)>(
            STREAMS_BOOST_PP_ENUM(N, STREAMS_BOOST_FUSION_PAIR_TIE, _));
    }

#undef N
#endif // defined(STREAMS_BOOST_PP_IS_ITERATING)

