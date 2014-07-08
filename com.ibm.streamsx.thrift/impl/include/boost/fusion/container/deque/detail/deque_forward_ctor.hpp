/*=============================================================================
    Copyright (c) 2001-2006 Joel de Guzman
    Copyright (c) 2005-2006 Dan Marsden

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(STREAMS_BOOST_PP_IS_ITERATING)
#if !defined(STREAMS_BOOST_FUSION_SEQUENCE_DEQUE_DETAIL_DEQUE_FORWARD_CTOR_04122006_2212)
#define STREAMS_BOOST_FUSION_SEQUENCE_DEQUE_DETAIL_DEQUE_FORWARD_CTOR_04122006_2212

#include <streams_boost/preprocessor/iterate.hpp>
#include <streams_boost/preprocessor/repetition/enum_shifted_params.hpp>
#include <streams_boost/preprocessor/repetition/enum_binary_params.hpp>

#define STREAMS_BOOST_PP_FILENAME_1 \
    <streams_boost/fusion/container/deque/detail/deque_forward_ctor.hpp>
#define STREAMS_BOOST_PP_ITERATION_LIMITS (2, FUSION_MAX_DEQUE_SIZE)
#include STREAMS_BOOST_PP_ITERATE()

#endif
#else

#define N STREAMS_BOOST_PP_ITERATION()

deque(STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N, typename add_reference<typename add_const<T, >::type>::type t))
    : base(detail::deque_keyed_values<STREAMS_BOOST_PP_ENUM_PARAMS(N, T)>::call(STREAMS_BOOST_PP_ENUM_PARAMS(N, t)))
{}

#undef N
#endif
