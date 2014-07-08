// Copyright (C) 2005 Arkadiy Vertleyb
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_TYPEOF_TYPE_TEMPLATE_PARAM_HPP_INCLUDED
#define STREAMS_BOOST_TYPEOF_TYPE_TEMPLATE_PARAM_HPP_INCLUDED

#define STREAMS_BOOST_TYPEOF_class_STREAMS_BOOST_TYPEOF (class)
#define STREAMS_BOOST_TYPEOF_typename_STREAMS_BOOST_TYPEOF (typename)

#define STREAMS_BOOST_TYPEOF_MAKE_OBJ_class STREAMS_BOOST_TYPEOF_TYPE_PARAM
#define STREAMS_BOOST_TYPEOF_MAKE_OBJ_typename STREAMS_BOOST_TYPEOF_TYPE_PARAM

#define STREAMS_BOOST_TYPEOF_TYPE_PARAM\
    (TYPE_PARAM)

#define STREAMS_BOOST_TYPEOF_TYPE_PARAM_EXPANDTYPE(Param) class

// TYPE_PARAM "virtual functions" implementation

#define STREAMS_BOOST_TYPEOF_TYPE_PARAM_ENCODE(This, n)\
    typedef typename streams_boost::type_of::encode_type<\
        STREAMS_BOOST_PP_CAT(V, n),\
        STREAMS_BOOST_PP_CAT(P, n)\
    >::type STREAMS_BOOST_PP_CAT(V, STREAMS_BOOST_PP_INC(n)); 

#define STREAMS_BOOST_TYPEOF_TYPE_PARAM_DECODE(This, n)\
    typedef streams_boost::type_of::decode_type< STREAMS_BOOST_PP_CAT(iter, n) > STREAMS_BOOST_PP_CAT(d, n);\
    typedef typename STREAMS_BOOST_PP_CAT(d, n)::type STREAMS_BOOST_PP_CAT(P, n);\
    typedef typename STREAMS_BOOST_PP_CAT(d, n)::iter STREAMS_BOOST_PP_CAT(iter, STREAMS_BOOST_PP_INC(n));

#define STREAMS_BOOST_TYPEOF_TYPE_PARAM_PLACEHOLDER(Param) int
#define STREAMS_BOOST_TYPEOF_TYPE_PARAM_DECLARATION_TYPE(Param) class
#define STREAMS_BOOST_TYPEOF_TYPE_PARAM_PLACEHOLDER_TYPES(Param, n) STREAMS_BOOST_PP_CAT(T,n)
#define STREAMS_BOOST_TYPEOF_TYPE_PARAM_ISTEMPLATE 0

#endif//STREAMS_BOOST_TYPEOF_TYPE_TEMPLATE_PARAM_HPP_INCLUDED
