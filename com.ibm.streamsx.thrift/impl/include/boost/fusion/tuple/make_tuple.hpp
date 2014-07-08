/*=============================================================================
    Copyright (c) 2001-2006 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef STREAMS_BOOST_PP_IS_ITERATING
#if !defined(FUSION_MAKE_TUPLE_10032005_0843)
#define FUSION_MAKE_TUPLE_10032005_0843

#include <streams_boost/preprocessor/iterate.hpp>
#include <streams_boost/preprocessor/repetition/enum_params.hpp>
#include <streams_boost/preprocessor/repetition/enum_binary_params.hpp>
#include <streams_boost/fusion/tuple/tuple.hpp>
#include <streams_boost/fusion/support/detail/as_fusion_element.hpp>

namespace streams_boost { namespace fusion
{
    inline tuple<>
    make_tuple()
    {
        return tuple<>();
    }

#define STREAMS_BOOST_FUSION_AS_FUSION_ELEMENT(z, n, data)                               \
    typename detail::as_fusion_element<STREAMS_BOOST_PP_CAT(T, n)>::type

#define STREAMS_BOOST_PP_FILENAME_1 <streams_boost/fusion/tuple/make_tuple.hpp>
#define STREAMS_BOOST_PP_ITERATION_LIMITS (1, FUSION_MAX_VECTOR_SIZE)
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

    template <STREAMS_BOOST_PP_ENUM_PARAMS(N, typename T)>
    inline tuple<STREAMS_BOOST_PP_ENUM(N, STREAMS_BOOST_FUSION_AS_FUSION_ELEMENT, _)>
    make_tuple(STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N, T, const& _))
    {
        return tuple<STREAMS_BOOST_PP_ENUM(N, STREAMS_BOOST_FUSION_AS_FUSION_ELEMENT, _)>(
            STREAMS_BOOST_PP_ENUM_PARAMS(N, _));
    }

#undef N
#endif // defined(STREAMS_BOOST_PP_IS_ITERATING)

