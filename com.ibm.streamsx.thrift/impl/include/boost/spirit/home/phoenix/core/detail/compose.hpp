/*=============================================================================
    Copyright (c) 2001-2007 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef STREAMS_BOOST_PP_IS_ITERATING
#ifndef PHOENIX_CORE_DETAIL_COMPOSE_DETAIL_HPP
#define PHOENIX_CORE_DETAIL_COMPOSE_DETAIL_HPP

#include <streams_boost/preprocessor/iterate.hpp>
#include <streams_boost/preprocessor/repetition/enum.hpp>

#define PHOENIX_AS_ACTOR_CONVERT(z, n, data)                                    \
    as_actor<STREAMS_BOOST_PP_CAT(T, n)>::convert(STREAMS_BOOST_PP_CAT(_, n))

#define STREAMS_BOOST_PP_ITERATION_PARAMS_1                                             \
    (3, (3, PHOENIX_COMPOSITE_LIMIT,                                            \
    "streams_boost/spirit/home/phoenix/core/detail/compose.hpp"))
#include STREAMS_BOOST_PP_ITERATE()

#undef PHOENIX_AS_ACTOR_CONVERT
#endif

///////////////////////////////////////////////////////////////////////////////
//
//  Preprocessor vertical repetition code
//
///////////////////////////////////////////////////////////////////////////////
#else // defined(STREAMS_BOOST_PP_IS_ITERATING)

#define N STREAMS_BOOST_PP_ITERATION()

    template <typename EvalPolicy, STREAMS_BOOST_PP_ENUM_PARAMS(N, typename T)>
    inline actor<
        typename as_composite<EvalPolicy, STREAMS_BOOST_PP_ENUM_PARAMS(N, T)>::type>
    compose(STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N, T, const& _))
    {
        return actor<
            typename as_composite<EvalPolicy, STREAMS_BOOST_PP_ENUM_PARAMS(N, T)>::type>(
                STREAMS_BOOST_PP_ENUM(N, PHOENIX_AS_ACTOR_CONVERT, _));
    }

#undef N
#endif // defined(STREAMS_BOOST_PP_IS_ITERATING)


