/*=============================================================================
    Copyright (c) 2001-2006 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef STREAMS_BOOST_PP_IS_ITERATING
#if !defined(FUSION_MAKE_MAP_07222005_1247)
#define FUSION_MAKE_MAP_07222005_1247

#include <streams_boost/preprocessor/iterate.hpp>
#include <streams_boost/preprocessor/repetition/enum_params.hpp>
#include <streams_boost/preprocessor/repetition/enum_binary_params.hpp>
#include <streams_boost/preprocessor/repetition/enum_params_with_a_default.hpp>
#include <streams_boost/preprocessor/repetition/repeat_from_to.hpp>
#include <streams_boost/fusion/container/map/map.hpp>
#include <streams_boost/fusion/support/detail/as_fusion_element.hpp>
#include <streams_boost/fusion/support/pair.hpp>

namespace streams_boost { namespace fusion
{
    struct void_;
        
    namespace result_of
    {
        template <
            STREAMS_BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
                FUSION_MAX_VECTOR_SIZE, typename K, void_)
          , STREAMS_BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
                FUSION_MAX_VECTOR_SIZE, typename D, void_)
          , typename Extra = void_
        >
        struct make_map;
            
        template <>
        struct make_map<>
        {
            typedef map<> type;
        };
    }
    
    inline map<>
    make_map()
    {
        return map<>();
    }

#define STREAMS_BOOST_FUSION_PAIR(z, n, data)                                           \
    fusion::pair<                                                               \
        STREAMS_BOOST_PP_CAT(K, n)                                                      \
      , typename detail::as_fusion_element<STREAMS_BOOST_PP_CAT(D, n)>::type>

#define STREAMS_BOOST_FUSION_MAKE_PAIR(z, n, data)                                      \
    fusion::make_pair<STREAMS_BOOST_PP_CAT(K, n)>(STREAMS_BOOST_PP_CAT(_, n))                   \

#define STREAMS_BOOST_PP_FILENAME_1 <streams_boost/fusion/container/generation/make_map.hpp>
#define STREAMS_BOOST_PP_ITERATION_LIMITS (1, FUSION_MAX_VECTOR_SIZE)
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
         struct make_map<STREAMS_BOOST_PP_ENUM_PARAMS(N, K), STREAMS_BOOST_PP_ENUM_PARAMS(N, D) STREAMS_BOOST_PP_REPEAT_FROM_TO(N, FUSION_MAX_VECTOR_SIZE, TEXT, void_) STREAMS_BOOST_PP_REPEAT_FROM_TO(STREAMS_BOOST_PP_DEC(N), FUSION_MAX_VECTOR_SIZE, TEXT, void_)>
         #undef TEXT
#else
        struct make_map<STREAMS_BOOST_PP_ENUM_PARAMS(N, K), STREAMS_BOOST_PP_ENUM_PARAMS(N, D)>
#endif
        {
            typedef map<STREAMS_BOOST_PP_ENUM(N, STREAMS_BOOST_FUSION_PAIR, _)> type;
        };
    }

    template <
        STREAMS_BOOST_PP_ENUM_PARAMS(N, typename K)
      , STREAMS_BOOST_PP_ENUM_PARAMS(N, typename D)
    >
    inline map<STREAMS_BOOST_PP_ENUM(N, STREAMS_BOOST_FUSION_PAIR, _)>
    make_map(STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N, D, const& _))
    {
        return map<STREAMS_BOOST_PP_ENUM(N, STREAMS_BOOST_FUSION_PAIR, _)>(
            STREAMS_BOOST_PP_ENUM(N, STREAMS_BOOST_FUSION_MAKE_PAIR, _));
    }

#undef N
#endif // defined(STREAMS_BOOST_PP_IS_ITERATING)

