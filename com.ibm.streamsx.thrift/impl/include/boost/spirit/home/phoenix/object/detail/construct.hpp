/*=============================================================================
    Copyright (c) 2001-2007 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef STREAMS_BOOST_PP_IS_ITERATING
#ifndef PHOENIX_OBJECT_DETAIL_CONSTRUCT_HPP
#define PHOENIX_OBJECT_DETAIL_CONSTRUCT_HPP

#include <streams_boost/preprocessor/iterate.hpp>
#include <streams_boost/preprocessor/repetition/enum_params.hpp>
#include <streams_boost/preprocessor/repetition/enum_binary_params.hpp>

#define STREAMS_BOOST_PP_ITERATION_PARAMS_1                                             \
    (3, (3, PHOENIX_COMPOSITE_LIMIT,                                            \
    "streams_boost/spirit/home/phoenix/object/detail/construct.hpp"))
#include STREAMS_BOOST_PP_ITERATE()

#endif

///////////////////////////////////////////////////////////////////////////////
//
//  Preprocessor vertical repetition code
//
///////////////////////////////////////////////////////////////////////////////
#else // defined(STREAMS_BOOST_PP_IS_ITERATING)

#define N STREAMS_BOOST_PP_ITERATION()

    template <typename T, STREAMS_BOOST_PP_ENUM_PARAMS(N, typename A)>
    inline actor<typename as_composite<detail::construct_eval<T>
        , STREAMS_BOOST_PP_ENUM_PARAMS(N, A)>::type>
    construct(STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N, A, const& _))
    {
        return compose<detail::construct_eval<T> >(STREAMS_BOOST_PP_ENUM_PARAMS(N, _));
    }

#undef N
#endif // defined(STREAMS_BOOST_PP_IS_ITERATING)


