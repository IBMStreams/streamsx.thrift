// Copyright (C) 2004 Arkadiy Vertleyb
// Copyright (C) 2005 Peder Holt
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_TYPEOF_TEMPLATE_ENCODING_HPP_INCLUDED
#define STREAMS_BOOST_TYPEOF_TEMPLATE_ENCODING_HPP_INCLUDED

#include <streams_boost/preprocessor/cat.hpp>
#include <streams_boost/preprocessor/repetition/enum_trailing.hpp>
#include <streams_boost/preprocessor/control/iif.hpp>
#include <streams_boost/preprocessor/detail/is_unary.hpp>
#include <streams_boost/preprocessor/repetition/repeat.hpp>
#include <streams_boost/preprocessor/tuple/eat.hpp>
#include <streams_boost/preprocessor/seq/transform.hpp>
#include <streams_boost/preprocessor/seq/for_each_i.hpp>
#include <streams_boost/preprocessor/seq/cat.hpp>

#include <streams_boost/typeof/encode_decode.hpp>
#include <streams_boost/typeof/int_encoding.hpp>

#include <streams_boost/typeof/type_template_param.hpp>
#include <streams_boost/typeof/integral_template_param.hpp>
#include <streams_boost/typeof/template_template_param.hpp>

#ifdef __BORLANDC__
#define STREAMS_BOOST_TYPEOF_QUALIFY(P) self_t::P
#else
#define STREAMS_BOOST_TYPEOF_QUALIFY(P) P
#endif
// The template parameter description, entered by the user,
// is converted into a polymorphic "object"
// that is used to generate the code responsible for
// encoding/decoding the parameter, etc.

// make sure to cat the sequence first, and only then add the prefix.
#define STREAMS_BOOST_TYPEOF_MAKE_OBJ(elem) STREAMS_BOOST_PP_CAT(\
    STREAMS_BOOST_TYPEOF_MAKE_OBJ,\
    STREAMS_BOOST_PP_SEQ_CAT((_) STREAMS_BOOST_TYPEOF_TO_SEQ(elem))\
    )

#define STREAMS_BOOST_TYPEOF_TO_SEQ(tokens) STREAMS_BOOST_TYPEOF_ ## tokens ## _STREAMS_BOOST_TYPEOF

// STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE

#define STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE_EXPLICIT_ID(Name, Params, Id)\
    STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE_IMPL(\
        Name,\
        STREAMS_BOOST_TYPEOF_MAKE_OBJS(STREAMS_BOOST_TYPEOF_TOSEQ(Params)),\
        STREAMS_BOOST_PP_SEQ_SIZE(STREAMS_BOOST_TYPEOF_TOSEQ(Params)),\
        Id)

#define STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(Name, Params)\
    STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE_EXPLICIT_ID(Name, Params, STREAMS_BOOST_TYPEOF_UNIQUE_ID())

#define STREAMS_BOOST_TYPEOF_OBJECT_MAKER(s, data, elem)\
    STREAMS_BOOST_TYPEOF_MAKE_OBJ(elem)

#define STREAMS_BOOST_TYPEOF_MAKE_OBJS(Params)\
    STREAMS_BOOST_PP_SEQ_TRANSFORM(STREAMS_BOOST_TYPEOF_OBJECT_MAKER, ~, Params)

// As suggested by Paul Mensonides:

#define STREAMS_BOOST_TYPEOF_TOSEQ(x)\
    STREAMS_BOOST_PP_IIF(\
        STREAMS_BOOST_PP_IS_UNARY(x),\
        x STREAMS_BOOST_PP_TUPLE_EAT(3), STREAMS_BOOST_PP_REPEAT\
    )(x, STREAMS_BOOST_TYPEOF_TOSEQ_2, ~)

#define STREAMS_BOOST_TYPEOF_TOSEQ_2(z, n, _) (class)

// STREAMS_BOOST_TYPEOF_VIRTUAL

#define STREAMS_BOOST_TYPEOF_CAT_4(a, b, c, d) STREAMS_BOOST_TYPEOF_CAT_4_I(a, b, c, d)
#define STREAMS_BOOST_TYPEOF_CAT_4_I(a, b, c, d) a ## b ## c ## d

#define STREAMS_BOOST_TYPEOF_VIRTUAL(Fun, Obj)\
    STREAMS_BOOST_TYPEOF_CAT_4(STREAMS_BOOST_TYPEOF_, STREAMS_BOOST_PP_SEQ_HEAD(Obj), _, Fun)

// STREAMS_BOOST_TYPEOF_SEQ_ENUM[_TRAILING][_1]
// Two versions provided due to reentrancy issue

#define STREAMS_BOOST_TYPEOF_SEQ_EXPAND_ELEMENT(z,n,seq)\
   STREAMS_BOOST_PP_SEQ_ELEM(0,seq) (z,n,STREAMS_BOOST_PP_SEQ_ELEM(n,STREAMS_BOOST_PP_SEQ_ELEM(1,seq)))

#define STREAMS_BOOST_TYPEOF_SEQ_ENUM(seq,macro)\
    STREAMS_BOOST_PP_ENUM(STREAMS_BOOST_PP_SEQ_SIZE(seq),STREAMS_BOOST_TYPEOF_SEQ_EXPAND_ELEMENT,(macro)(seq))

#define STREAMS_BOOST_TYPEOF_SEQ_ENUM_TRAILING(seq,macro)\
    STREAMS_BOOST_PP_ENUM_TRAILING(STREAMS_BOOST_PP_SEQ_SIZE(seq),STREAMS_BOOST_TYPEOF_SEQ_EXPAND_ELEMENT,(macro)(seq))

#define STREAMS_BOOST_TYPEOF_SEQ_EXPAND_ELEMENT_1(z,n,seq)\
    STREAMS_BOOST_PP_SEQ_ELEM(0,seq) (z,n,STREAMS_BOOST_PP_SEQ_ELEM(n,STREAMS_BOOST_PP_SEQ_ELEM(1,seq)))

#define STREAMS_BOOST_TYPEOF_SEQ_ENUM_1(seq,macro)\
    STREAMS_BOOST_PP_ENUM(STREAMS_BOOST_PP_SEQ_SIZE(seq),STREAMS_BOOST_TYPEOF_SEQ_EXPAND_ELEMENT_1,(macro)(seq))

#define STREAMS_BOOST_TYPEOF_SEQ_ENUM_TRAILING_1(seq,macro)\
    STREAMS_BOOST_PP_ENUM_TRAILING(STREAMS_BOOST_PP_SEQ_SIZE(seq),STREAMS_BOOST_TYPEOF_SEQ_EXPAND_ELEMENT_1,(macro)(seq))

//

#define STREAMS_BOOST_TYPEOF_PLACEHOLDER(z, n, elem)\
    STREAMS_BOOST_TYPEOF_VIRTUAL(PLACEHOLDER, elem)(elem)

#define STREAMS_BOOST_TYPEOF_PLACEHOLDER_TYPES(z, n, elem)\
    STREAMS_BOOST_TYPEOF_VIRTUAL(PLACEHOLDER_TYPES, elem)(elem, n)

#define STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE_ENCODE_PARAM(r, data, n, elem)\
    STREAMS_BOOST_TYPEOF_VIRTUAL(ENCODE, elem)(elem, n)

#define STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE_DECODE_PARAM(r, data, n, elem)\
    STREAMS_BOOST_TYPEOF_VIRTUAL(DECODE, elem)(elem, n)

#define STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE_PARAM_PAIR(z, n, elem) \
    STREAMS_BOOST_TYPEOF_VIRTUAL(EXPANDTYPE, elem)(elem) STREAMS_BOOST_PP_CAT(P, n)

#define STREAMS_BOOST_TYPEOF_REGISTER_DEFAULT_TEMPLATE_TYPE(Name,Params,ID)\
    Name< STREAMS_BOOST_PP_ENUM_PARAMS(STREAMS_BOOST_PP_SEQ_SIZE(Params), P) >

//Since we are creating an internal decode struct, we need to use different template names, T instead of P.
#define STREAMS_BOOST_TYPEOF_REGISTER_DECODER_TYPE_PARAM_PAIR(z,n,elem) \
    STREAMS_BOOST_TYPEOF_VIRTUAL(EXPANDTYPE, elem)(elem) STREAMS_BOOST_PP_CAT(T, n)

//Default template param decoding

#define STREAMS_BOOST_TYPEOF_TYPEDEF_DECODED_TEMPLATE_TYPE(Name,Params)\
    typedef Name<STREAMS_BOOST_PP_ENUM_PARAMS(STREAMS_BOOST_PP_SEQ_SIZE(Params),STREAMS_BOOST_TYPEOF_QUALIFY(P))> type;

//Branch the decoding
#define STREAMS_BOOST_TYPEOF_TYPEDEF_DECODED_TYPE(Name,Params)\
    STREAMS_BOOST_PP_IF(STREAMS_BOOST_TYPEOF_HAS_TEMPLATES(Params),\
        STREAMS_BOOST_TYPEOF_TYPEDEF_DECODED_TEMPLATE_TEMPLATE_TYPE,\
        STREAMS_BOOST_TYPEOF_TYPEDEF_DECODED_TEMPLATE_TYPE)(Name,Params)

#define STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE_IMPL(Name, Params, Size, ID)\
    STREAMS_BOOST_TYPEOF_BEGIN_ENCODE_NS\
    STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE_TEMPLATE_IMPL(Name, Params, ID)\
    template<class V\
        STREAMS_BOOST_TYPEOF_SEQ_ENUM_TRAILING(Params, STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE_PARAM_PAIR)\
    >\
    struct encode_type_impl<V, Name<STREAMS_BOOST_PP_ENUM_PARAMS(Size, P)> >\
    {\
        typedef typename streams_boost::type_of::push_back<V, streams_boost::mpl::size_t<ID> >::type V0;\
        STREAMS_BOOST_PP_SEQ_FOR_EACH_I(STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE_ENCODE_PARAM, ~, Params)\
        typedef STREAMS_BOOST_PP_CAT(V, Size) type;\
    };\
    template<class Iter>\
    struct decode_type_impl<streams_boost::mpl::size_t<ID>, Iter>\
    {\
        typedef decode_type_impl<streams_boost::mpl::size_t<ID>, Iter> self_t;\
        typedef streams_boost::mpl::size_t<ID> self_id;\
        typedef Iter iter0;\
        STREAMS_BOOST_PP_SEQ_FOR_EACH_I(STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE_DECODE_PARAM, ~, Params)\
        STREAMS_BOOST_TYPEOF_TYPEDEF_DECODED_TYPE(Name, Params)\
        typedef STREAMS_BOOST_PP_CAT(iter, Size) iter;\
    };\
    STREAMS_BOOST_TYPEOF_END_ENCODE_NS

#endif//STREAMS_BOOST_TYPEOF_TEMPLATE_ENCODING_HPP_INCLUDED
