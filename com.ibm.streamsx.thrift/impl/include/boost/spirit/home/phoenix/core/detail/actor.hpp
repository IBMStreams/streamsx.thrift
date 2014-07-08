/*=============================================================================
    Copyright (c) 2001-2007 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef STREAMS_BOOST_PP_IS_ITERATING
#ifndef PHOENIX_CORE_DETAIL_ACTOR_HPP
#define PHOENIX_CORE_DETAIL_ACTOR_HPP

#include <streams_boost/preprocessor/iterate.hpp>
#include <streams_boost/preprocessor/repetition/enum_params.hpp>
#include <streams_boost/preprocessor/repetition/enum_binary_params.hpp>
#include <streams_boost/preprocessor/facilities/intercept.hpp>

#define STREAMS_BOOST_PP_ITERATION_PARAMS_1                                             \
    (3, (3, PHOENIX_ACTOR_LIMIT,                                                \
    "streams_boost/spirit/home/phoenix/core/detail/actor.hpp"))
#include STREAMS_BOOST_PP_ITERATE()

#endif

///////////////////////////////////////////////////////////////////////////////
//
//  Preprocessor vertical repetition code
//
///////////////////////////////////////////////////////////////////////////////
#else // defined(STREAMS_BOOST_PP_IS_ITERATING)

#define N STREAMS_BOOST_PP_ITERATION()

    template <STREAMS_BOOST_PP_ENUM_PARAMS(N, typename T)>
    actor(STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N, T, const& _))
        : Eval(STREAMS_BOOST_PP_ENUM_PARAMS(N, _)) {}

    template <typename F, STREAMS_BOOST_PP_ENUM_PARAMS(N, typename A)>
    struct result<F(STREAMS_BOOST_PP_ENUM_PARAMS(N, A))>
      : eval_result<
            eval_type
          , basic_environment<
                STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(
                    N
                  , typename remove_reference<typename add_const<A
                  , >::type>::type STREAMS_BOOST_PP_INTERCEPT
                )
            >
        >
    {};

    template <STREAMS_BOOST_PP_ENUM_PARAMS(N, typename T)>
    typename result<
        actor(STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N, T, & STREAMS_BOOST_PP_INTERCEPT))
    >::type
    operator()(STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N, T, & _)) const
    {
        return eval_type::eval(
            basic_environment<STREAMS_BOOST_PP_ENUM_PARAMS(N, T)>(
                STREAMS_BOOST_PP_ENUM_PARAMS(N, _))
        );
    }

#undef N
#endif // defined(STREAMS_BOOST_PP_IS_ITERATING)


