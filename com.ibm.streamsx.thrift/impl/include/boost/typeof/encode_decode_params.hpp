// Copyright (C) 2005 Arkadiy Vertleyb
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_TYPEOF_ENCODE_DECODE_PARAMS_HPP_INCLUDED
#define STREAMS_BOOST_TYPEOF_ENCODE_DECODE_PARAMS_HPP_INCLUDED

#include <streams_boost/preprocessor/cat.hpp>
#include <streams_boost/preprocessor/repetition/repeat.hpp>

// Assumes iter0 contains initial iterator

#define STREAMS_BOOST_TYPEOF_DECODE_PARAM(z, n, text)   \
    typedef streams_boost::type_of::decode_type<iter##n> decode##n;     \
    typedef typename decode##n::type p##n;      \
    typedef typename decode##n::iter STREAMS_BOOST_PP_CAT(iter, STREAMS_BOOST_PP_INC(n));

#define STREAMS_BOOST_TYPEOF_DECODE_PARAMS(n)\
    STREAMS_BOOST_PP_REPEAT(n, STREAMS_BOOST_TYPEOF_DECODE_PARAM, ~)

// The P0, P1, ... PN are encoded and added to V 

#define STREAMS_BOOST_TYPEOF_ENCODE_PARAMS_BEGIN(z, n, text)\
    typename streams_boost::type_of::encode_type<

#define STREAMS_BOOST_TYPEOF_ENCODE_PARAMS_END(z, n, text)\
    , STREAMS_BOOST_PP_CAT(P, n)>::type

#define STREAMS_BOOST_TYPEOF_ENCODE_PARAMS(n, ID)                   \
    STREAMS_BOOST_PP_REPEAT(n, STREAMS_BOOST_TYPEOF_ENCODE_PARAMS_BEGIN, ~) \
    typename streams_boost::type_of::push_back<V, streams_boost::mpl::size_t<ID> >::type      \
    STREAMS_BOOST_PP_REPEAT(n, STREAMS_BOOST_TYPEOF_ENCODE_PARAMS_END, ~)

#endif//STREAMS_BOOST_TYPEOF_ENCODE_DECODE_PARAMS_HPP_INCLUDED
