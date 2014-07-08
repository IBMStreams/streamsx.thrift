/*=============================================================================
    Copyright (c) 2001-2006 Joel de Guzman
    Copyright (c) 2006 Dan Marsden

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
/*=============================================================================
    Copyright (c) 2001-2006 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef STREAMS_BOOST_PP_IS_ITERATING
#if !defined(FUSION_MAKE_DEQUE_07162005_0243)
#define FUSION_MAKE_DEQUE_07162005_0243

#include <streams_boost/preprocessor/iterate.hpp>
#include <streams_boost/preprocessor/repetition/enum_params.hpp>
#include <streams_boost/preprocessor/repetition/enum_binary_params.hpp>
#include <streams_boost/preprocessor/repetition/enum_params_with_a_default.hpp>
#include <streams_boost/preprocessor/repetition/repeat_from_to.hpp>
#include <streams_boost/fusion/container/deque/deque.hpp>
#include <streams_boost/fusion/support/detail/as_fusion_element.hpp>

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
        struct make_deque;
            
        template <>
        struct make_deque<>
        {
            typedef deque<> type;
        };
    }
    
    inline deque<>
    make_deque()
    {
        return deque<>();
    }

#define STREAMS_BOOST_FUSION_AS_FUSION_ELEMENT(z, n, data)                               \
    typename detail::as_fusion_element<STREAMS_BOOST_PP_CAT(T, n)>::type

#define STREAMS_BOOST_PP_FILENAME_1 <streams_boost/fusion/container/generation/make_deque.hpp>
#define STREAMS_BOOST_PP_ITERATION_LIMITS (1, FUSION_MAX_DEQUE_SIZE)
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
        struct make_deque< STREAMS_BOOST_PP_ENUM_PARAMS(N, T) STREAMS_BOOST_PP_REPEAT_FROM_TO(STREAMS_BOOST_PP_DEC(N), FUSION_MAX_DEQUE_SIZE, TEXT, void_) >
        #undef TEXT
#else
        struct make_deque<STREAMS_BOOST_PP_ENUM_PARAMS(N, T)>
#endif
        {
            typedef deque<STREAMS_BOOST_PP_ENUM(N, STREAMS_BOOST_FUSION_AS_FUSION_ELEMENT, _)> type;
        };
    }

    template <STREAMS_BOOST_PP_ENUM_PARAMS(N, typename T)>
    inline deque<STREAMS_BOOST_PP_ENUM(N, STREAMS_BOOST_FUSION_AS_FUSION_ELEMENT, _)>
    make_deque(STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N, T, const& _))
    {
        return deque<STREAMS_BOOST_PP_ENUM(N, STREAMS_BOOST_FUSION_AS_FUSION_ELEMENT, _)>(
            STREAMS_BOOST_PP_ENUM_PARAMS(N, _));
    }

#undef N
#endif // defined(STREAMS_BOOST_PP_IS_ITERATING)

