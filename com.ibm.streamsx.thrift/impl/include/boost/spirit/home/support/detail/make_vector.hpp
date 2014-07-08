/*=============================================================================
    Copyright (c) 2001-2010 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#include <streams_boost/version.hpp>

// This is the same as the one in fusion in Boost 1.41. This is provided
// for compatibility with Boost 1.40 and below.

#if (STREAMS_BOOST_VERSION > 104000)

#include <streams_boost/fusion/include/make_vector.hpp>

namespace streams_boost { namespace spirit { namespace detail
{
    namespace result_of
    {
        using fusion::result_of::make_vector;
    }
    using fusion::make_vector;
}}}

#else

#ifndef STREAMS_BOOST_PP_IS_ITERATING
#if !defined(SPIRIT_MAKE_VECTOR_07162005_0243)
#define SPIRIT_MAKE_VECTOR_07162005_0243

#include <streams_boost/preprocessor/iterate.hpp>
#include <streams_boost/preprocessor/repetition/enum_params.hpp>
#include <streams_boost/preprocessor/repetition/enum_binary_params.hpp>
#include <streams_boost/preprocessor/repetition/enum_params_with_a_default.hpp>
#include <streams_boost/preprocessor/repetition/repeat_from_to.hpp>
#include <streams_boost/fusion/container/vector/vector.hpp>
#include <streams_boost/fusion/support/detail/as_fusion_element.hpp>

namespace streams_boost { namespace fusion
{
    struct void_;
}}

namespace streams_boost { namespace spirit { namespace detail
{
    namespace result_of
    {
        template <
            STREAMS_BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
                FUSION_MAX_VECTOR_SIZE, typename T, fusion::void_)
          , typename Extra = fusion::void_
        >
        struct make_vector;

        template <>
        struct make_vector<>
        {
            typedef fusion::vector0 type;
        };
    }

    inline fusion::vector0
    make_vector()
    {
        return fusion::vector0();
    }

#define STREAMS_BOOST_FUSION_AS_FUSION_ELEMENT(z, n, data)                               \
    typename fusion::detail::as_fusion_element<STREAMS_BOOST_PP_CAT(T, n)>::type

#define STREAMS_BOOST_PP_FILENAME_1 <streams_boost/spirit/home/support/detail/make_vector.hpp>
#define STREAMS_BOOST_PP_ITERATION_LIMITS (1, FUSION_MAX_VECTOR_SIZE)
#include STREAMS_BOOST_PP_ITERATE()

#undef STREAMS_BOOST_FUSION_AS_FUSION_ELEMENT

}}}

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
        struct make_vector< STREAMS_BOOST_PP_ENUM_PARAMS(N, T) STREAMS_BOOST_PP_REPEAT_FROM_TO(STREAMS_BOOST_PP_DEC(N), FUSION_MAX_VECTOR_SIZE, TEXT, fusion::void_) >
        #undef TEXT
#else
        struct make_vector<STREAMS_BOOST_PP_ENUM_PARAMS(N, T)>
#endif
        {
            typedef STREAMS_BOOST_PP_CAT(fusion::vector, N)<STREAMS_BOOST_PP_ENUM(N, STREAMS_BOOST_FUSION_AS_FUSION_ELEMENT, _)> type;
        };
    }

    template <STREAMS_BOOST_PP_ENUM_PARAMS(N, typename T)>
    inline STREAMS_BOOST_PP_CAT(fusion::vector, N)<STREAMS_BOOST_PP_ENUM(N, STREAMS_BOOST_FUSION_AS_FUSION_ELEMENT, _)>
    make_vector(STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N, T, const& _))
    {
        return STREAMS_BOOST_PP_CAT(fusion::vector, N)<STREAMS_BOOST_PP_ENUM(N, STREAMS_BOOST_FUSION_AS_FUSION_ELEMENT, _)>(
            STREAMS_BOOST_PP_ENUM_PARAMS(N, _));
    }

#undef N
#endif // defined(STREAMS_BOOST_PP_IS_ITERATING)
#endif // (STREAMS_BOOST_VERSION > 103800)
