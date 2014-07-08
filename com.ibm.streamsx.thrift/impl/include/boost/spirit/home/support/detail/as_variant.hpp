/*=============================================================================
    Copyright (c) 2001-2010 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef STREAMS_BOOST_PP_IS_ITERATING
#if !defined(STREAMS_BOOST_SPIRIT_AS_VARIANT_NOVEMBER_16_2007_0420PM)
#define STREAMS_BOOST_SPIRIT_AS_VARIANT_NOVEMBER_16_2007_0420PM

#include <streams_boost/preprocessor/iterate.hpp>
#include <streams_boost/preprocessor/repetition/enum_params.hpp>
#include <streams_boost/preprocessor/repetition/enum_binary_params.hpp>
#include <streams_boost/preprocessor/repetition/enum_params_with_a_default.hpp>
#include <streams_boost/preprocessor/repetition/repeat_from_to.hpp>
#include <streams_boost/variant/variant_fwd.hpp>
#include <streams_boost/fusion/include/size.hpp>
#include <streams_boost/fusion/include/begin.hpp>
#include <streams_boost/fusion/include/next.hpp>
#include <streams_boost/fusion/include/value_of.hpp>
#include <streams_boost/mpl/fold.hpp>
#include <streams_boost/mpl/vector.hpp>
#include <streams_boost/mpl/push_back.hpp>
#include <streams_boost/mpl/equal_to.hpp>
#include <streams_boost/mpl/contains.hpp>
#include <streams_boost/type_traits/is_same.hpp>

namespace streams_boost { namespace spirit { namespace detail
{
    template <int size>
    struct as_variant_impl;

    template <>
    struct as_variant_impl<0>
    {
        template <typename Iterator>
        struct apply
        {
            typedef variant<> type;
        };
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

#define STREAMS_BOOST_PP_FILENAME_1 <streams_boost/spirit/home/support/detail/as_variant.hpp>
#define STREAMS_BOOST_PP_ITERATION_LIMITS (1, STREAMS_BOOST_VARIANT_LIMIT_TYPES)
#include STREAMS_BOOST_PP_ITERATE()

#undef STREAMS_BOOST_FUSION_NEXT_ITERATOR
#undef STREAMS_BOOST_FUSION_NEXT_CALL_ITERATOR
#undef STREAMS_BOOST_FUSION_VALUE_OF_ITERATOR

    template <typename Sequence>
    struct as_variant
    {
        // build a variant generator being able to generate a variant holding
        // all of the types as given in the typelist
        typedef typename
            detail::as_variant_impl<fusion::result_of::size<Sequence>::value>
        gen;

        // use this generator to create the actual variant
        typedef typename gen::template apply<
                typename fusion::result_of::begin<Sequence>::type
            >::type
        type;
    };
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
    struct as_variant_impl<N>
    {
        template <typename I0>
        struct apply
        {
            STREAMS_BOOST_PP_REPEAT(N, STREAMS_BOOST_FUSION_NEXT_ITERATOR, _)
            STREAMS_BOOST_PP_REPEAT(N, STREAMS_BOOST_FUSION_VALUE_OF_ITERATOR, _)
            typedef variant<STREAMS_BOOST_PP_ENUM_PARAMS(N, T)> type;
        };
    };

#undef N
#endif // defined(STREAMS_BOOST_PP_IS_ITERATING)

