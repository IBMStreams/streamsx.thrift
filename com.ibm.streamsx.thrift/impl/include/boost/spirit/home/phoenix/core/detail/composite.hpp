/*=============================================================================
    Copyright (c) 2001-2007 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef STREAMS_BOOST_PP_IS_ITERATING
#ifndef PHOENIX_CORE_DETAIL_COMPOSITE_HPP
#define PHOENIX_CORE_DETAIL_COMPOSITE_HPP

#include <streams_boost/preprocessor/iterate.hpp>

#define STREAMS_BOOST_PP_ITERATION_PARAMS_1                                             \
    (3, (3, PHOENIX_COMPOSITE_LIMIT,                                            \
    "streams_boost/spirit/home/phoenix/core/detail/composite.hpp"))
#include STREAMS_BOOST_PP_ITERATE()

#endif

///////////////////////////////////////////////////////////////////////////////
//
//  Preprocessor vertical repetition code
//
///////////////////////////////////////////////////////////////////////////////
#else // defined(STREAMS_BOOST_PP_IS_ITERATING)

#define N STREAMS_BOOST_PP_ITERATION()

    template <STREAMS_BOOST_PP_ENUM_PARAMS(N, typename U)>
    composite(STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N, U, & _))
        : base_type(STREAMS_BOOST_PP_ENUM_PARAMS(N, _)) {}

#undef N
#endif // defined(STREAMS_BOOST_PP_IS_ITERATING)

