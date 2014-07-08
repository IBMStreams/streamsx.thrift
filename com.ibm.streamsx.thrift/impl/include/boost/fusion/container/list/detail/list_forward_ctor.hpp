/*=============================================================================
    Copyright (c) 2001-2006 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef STREAMS_BOOST_PP_IS_ITERATING
#if !defined(FUSION_LIST_FORWARD_CTOR_07172005_0113)
#define FUSION_LIST_FORWARD_CTOR_07172005_0113

#include <streams_boost/preprocessor/iterate.hpp>
#include <streams_boost/preprocessor/cat.hpp>
#include <streams_boost/preprocessor/repetition/enum_shifted.hpp>
#include <streams_boost/preprocessor/repetition/enum_binary_params.hpp>
#include <streams_boost/preprocessor/repetition/repeat.hpp>

#define FUSION_LIST_CTOR_MAKE_CONS(z, n, type) tie_cons(STREAMS_BOOST_PP_CAT(_, n)
#define FUSION_LIST_CL_PAREN(z, n, type) )

#define STREAMS_BOOST_PP_FILENAME_1 \
    <streams_boost/fusion/container/list/detail/list_forward_ctor.hpp>
#define STREAMS_BOOST_PP_ITERATION_LIMITS (1, FUSION_MAX_LIST_SIZE)
#include STREAMS_BOOST_PP_ITERATE()

#undef FUSION_LIST_CTOR_MAKE_CONS
#undef FUSION_LIST_CL_PAREN

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
    list(STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(
        N, typename detail::call_param<T, >::type _))
        : inherited_type(list_to_cons::call(STREAMS_BOOST_PP_ENUM_PARAMS(N, _)))
    {}

#undef N
#endif // defined(STREAMS_BOOST_PP_IS_ITERATING)

