/*=============================================================================
    Copyright (c) 2001-2006 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef STREAMS_BOOST_PP_IS_ITERATING
#if !defined(FUSION_AS_MAP_0932005_1339)
#define FUSION_AS_MAP_0932005_1339

#include <streams_boost/preprocessor/iterate.hpp>
#include <streams_boost/preprocessor/repetition/enum_params.hpp>
#include <streams_boost/preprocessor/repetition/enum_binary_params.hpp>
#include <streams_boost/preprocessor/repetition/repeat.hpp>
#include <streams_boost/preprocessor/cat.hpp>
#include <streams_boost/preprocessor/inc.hpp>
#include <streams_boost/preprocessor/dec.hpp>
#include <streams_boost/fusion/container/map/map.hpp>
#include <streams_boost/fusion/iterator/value_of.hpp>
#include <streams_boost/fusion/iterator/deref.hpp>
#include <streams_boost/fusion/iterator/next.hpp>

namespace streams_boost { namespace fusion { namespace detail
{
    template <int size>
    struct as_map;

    template <>
    struct as_map<0>
    {
        template <typename Iterator>
        struct apply
        {
            typedef map<> type;
        };

        template <typename Iterator>
        static typename apply<Iterator>::type
        call(Iterator)
        {
            return map<>();
        }
    };

#define STREAMS_BOOST_FUSION_NEXT_ITERATOR(z, n, data)                                  \
    typedef typename fusion::result_of::next<STREAMS_BOOST_PP_CAT(I, n)>::type          \
        STREAMS_BOOST_PP_CAT(I, STREAMS_BOOST_PP_INC(n));

#define STREAMS_BOOST_FUSION_NEXT_CALL_ITERATOR(z, n, data)                             \
    typename gen::STREAMS_BOOST_PP_CAT(I, STREAMS_BOOST_PP_INC(n))                              \
        STREAMS_BOOST_PP_CAT(i, STREAMS_BOOST_PP_INC(n)) = fusion::next(STREAMS_BOOST_PP_CAT(i, n));

#define STREAMS_BOOST_FUSION_VALUE_OF_ITERATOR(z, n, data)                              \
    typedef typename fusion::result_of::value_of<STREAMS_BOOST_PP_CAT(I, n)>::type      \
        STREAMS_BOOST_PP_CAT(T, n);

#define STREAMS_BOOST_PP_FILENAME_1 <streams_boost/fusion/container/map/detail/as_map.hpp>
#define STREAMS_BOOST_PP_ITERATION_LIMITS (1, FUSION_MAX_MAP_SIZE)
#include STREAMS_BOOST_PP_ITERATE()

#undef STREAMS_BOOST_FUSION_NEXT_ITERATOR
#undef STREAMS_BOOST_FUSION_NEXT_CALL_ITERATOR
#undef STREAMS_BOOST_FUSION_VALUE_OF_ITERATOR

}}}

#endif
#else // defined(STREAMS_BOOST_PP_IS_ITERATING)
///////////////////////////////////////////////////////////////////////////////
//
//  Preprocessor vertical repetition code
//
///////////////////////////////////////////////////////////////////////////////

#define N STREAMS_BOOST_PP_ITERATION()

    template <>
    struct as_map<N>
    {
        template <typename I0>
        struct apply
        {
            STREAMS_BOOST_PP_REPEAT(N, STREAMS_BOOST_FUSION_NEXT_ITERATOR, _)
            STREAMS_BOOST_PP_REPEAT(N, STREAMS_BOOST_FUSION_VALUE_OF_ITERATOR, _)
            typedef map<STREAMS_BOOST_PP_ENUM_PARAMS(N, T)> type;
        };

        template <typename Iterator>
        static typename apply<Iterator>::type
        call(Iterator const& i0)
        {
            typedef apply<Iterator> gen;
            typedef typename gen::type result;
            STREAMS_BOOST_PP_REPEAT(STREAMS_BOOST_PP_DEC(N), STREAMS_BOOST_FUSION_NEXT_CALL_ITERATOR, _)
            return result(STREAMS_BOOST_PP_ENUM_PARAMS(N, *i));
        }
    };

#undef N
#endif // defined(STREAMS_BOOST_PP_IS_ITERATING)

