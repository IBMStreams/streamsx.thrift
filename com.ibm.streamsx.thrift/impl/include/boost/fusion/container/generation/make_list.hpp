/*=============================================================================
    Copyright (c) 2001-2006 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef STREAMS_BOOST_PP_IS_ITERATING
#if !defined(FUSION_MAKE_LIST_07192005_1239)
#define FUSION_MAKE_LIST_07192005_1239

#include <streams_boost/preprocessor/iterate.hpp>
#include <streams_boost/preprocessor/repetition/enum_params.hpp>
#include <streams_boost/preprocessor/repetition/enum_binary_params.hpp>
#include <streams_boost/preprocessor/repetition/enum_params_with_a_default.hpp>
#include <streams_boost/preprocessor/repetition/repeat_from_to.hpp>
#include <streams_boost/fusion/container/list/list.hpp>
#include <streams_boost/fusion/support/detail/as_fusion_element.hpp>

namespace streams_boost { namespace fusion
{
    struct void_;
        
    namespace result_of
    {
        template <
            STREAMS_BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
                FUSION_MAX_LIST_SIZE, typename T, void_)
          , typename Extra = void_
        >
        struct make_list;
            
        template <>
        struct make_list<>
        {
            typedef list<> type;
        };
    }
    
    inline list<>
    make_list()
    {
        return list<>();
    }

#define STREAMS_BOOST_FUSION_AS_FUSION_ELEMENT(z, n, data)                               \
    typename detail::as_fusion_element<STREAMS_BOOST_PP_CAT(T, n)>::type

#define STREAMS_BOOST_PP_FILENAME_1 <streams_boost/fusion/container/generation/make_list.hpp>
#define STREAMS_BOOST_PP_ITERATION_LIMITS (1, FUSION_MAX_LIST_SIZE)
#include STREAMS_BOOST_PP_ITERATE()

#undef STREAMS_BOOST_FUSION_AS_FUSION_ELEMENT

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
        struct make_list< STREAMS_BOOST_PP_ENUM_PARAMS(N, T) STREAMS_BOOST_PP_REPEAT_FROM_TO(STREAMS_BOOST_PP_DEC(N), FUSION_MAX_LIST_SIZE, TEXT, void_) >
        #undef TEXT
#else
        struct make_list<STREAMS_BOOST_PP_ENUM_PARAMS(N, T)>
#endif
        {
            typedef list<STREAMS_BOOST_PP_ENUM(N, STREAMS_BOOST_FUSION_AS_FUSION_ELEMENT, _)> type;
        };
    }

    template <STREAMS_BOOST_PP_ENUM_PARAMS(N, typename T)>
    inline list<STREAMS_BOOST_PP_ENUM(N, STREAMS_BOOST_FUSION_AS_FUSION_ELEMENT, _)>
    make_list(STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N, T, const& _))
    {
        return list<STREAMS_BOOST_PP_ENUM(N, STREAMS_BOOST_FUSION_AS_FUSION_ELEMENT, _)>(
            STREAMS_BOOST_PP_ENUM_PARAMS(N, _));
    }

#undef N
#endif // defined(STREAMS_BOOST_PP_IS_ITERATING)

