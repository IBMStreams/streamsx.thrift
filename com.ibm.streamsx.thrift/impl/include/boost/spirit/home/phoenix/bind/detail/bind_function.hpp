/*=============================================================================
    Copyright (c) 2001-2007 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(STREAMS_BOOST_PP_IS_ITERATING)
#if !defined(PHOENIX_BIND_DETAIL_BIND_FUNCTION_HPP)
#define PHOENIX_BIND_DETAIL_BIND_FUNCTION_HPP

#include <streams_boost/preprocessor/iterate.hpp>
#include <streams_boost/preprocessor/dec.hpp>
#include <streams_boost/preprocessor/repetition/enum_params.hpp>
#include <streams_boost/preprocessor/repetition/enum_binary_params.hpp>

#define STREAMS_BOOST_PP_ITERATION_PARAMS_1                                             \
    (3, (3, STREAMS_BOOST_PP_DEC(PHOENIX_COMPOSITE_LIMIT),                              \
    "streams_boost/spirit/home/phoenix/bind/detail/bind_function.hpp"))
#include STREAMS_BOOST_PP_ITERATE()

#endif

///////////////////////////////////////////////////////////////////////////////
//
//  Preprocessor vertical repetition code
//
///////////////////////////////////////////////////////////////////////////////
#else // defined(STREAMS_BOOST_PP_IS_ITERATING)

#define N STREAMS_BOOST_PP_ITERATION()

    template <typename RT
      , STREAMS_BOOST_PP_ENUM_PARAMS(N, typename T)
      , STREAMS_BOOST_PP_ENUM_PARAMS(N, typename A)>
    inline actor<
        typename as_composite<
            detail::function_eval<N>
          , detail::function_ptr<N, RT, RT(*)(STREAMS_BOOST_PP_ENUM_PARAMS(N, T))>
          , STREAMS_BOOST_PP_ENUM_PARAMS(N, A)
        >::type>
    bind(RT(*f)(STREAMS_BOOST_PP_ENUM_PARAMS(N, T))
      , STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N, A, const& _))
    {
        typedef detail::function_ptr<
            N, RT, RT(*)(STREAMS_BOOST_PP_ENUM_PARAMS(N, T))> fp_type;
        return compose<detail::function_eval<N> >(
            fp_type(f), STREAMS_BOOST_PP_ENUM_PARAMS(N, _));
    }

#undef N
#endif // defined(STREAMS_BOOST_PP_IS_ITERATING)

