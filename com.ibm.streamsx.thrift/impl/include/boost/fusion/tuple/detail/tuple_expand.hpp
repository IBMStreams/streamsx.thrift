/*=============================================================================
    Copyright (c) 2001-2006 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef STREAMS_BOOST_PP_IS_ITERATING
#if !defined(FUSION_TUPLE_EXPAND_10032005_0815)
#define FUSION_TUPLE_EXPAND_10032005_0815

#include <streams_boost/preprocessor/iterate.hpp>
#include <streams_boost/preprocessor/repetition/enum_params.hpp>
#include <streams_boost/preprocessor/repetition/enum_binary_params.hpp>

#define STREAMS_BOOST_PP_FILENAME_1 \
    <streams_boost/fusion/tuple/detail/tuple_expand.hpp>
#define STREAMS_BOOST_PP_ITERATION_LIMITS (1, FUSION_MAX_VECTOR_SIZE)
#include STREAMS_BOOST_PP_ITERATE()

#endif
#else // defined(STREAMS_BOOST_PP_IS_ITERATING)
///////////////////////////////////////////////////////////////////////////////
//
//  Preprocessor vertical repetition code
//
///////////////////////////////////////////////////////////////////////////////

#define N STREAMS_BOOST_PP_ITERATION()

#if N == 1
    explicit
#endif
    tuple(STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(
        N, typename detail::call_param<T, >::type _))
        : base_type(STREAMS_BOOST_PP_ENUM_PARAMS(N, _)) {}

    template <STREAMS_BOOST_PP_ENUM_PARAMS(N, typename U)>
    tuple(tuple<STREAMS_BOOST_PP_ENUM_PARAMS(N, U)> const& rhs)
        : base_type(rhs) {}

    template <STREAMS_BOOST_PP_ENUM_PARAMS(N, typename U)>
    tuple& operator=(tuple<STREAMS_BOOST_PP_ENUM_PARAMS(N, U)> const& rhs)
    {
        base_type::operator=(rhs);
        return *this;
    }

#undef N
#endif // defined(STREAMS_BOOST_PP_IS_ITERATING)

