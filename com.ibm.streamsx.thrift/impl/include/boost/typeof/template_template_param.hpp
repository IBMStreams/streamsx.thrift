// Copyright (C) 2005 Peder Holt
// Copyright (C) 2005 Arkadiy Vertleyb
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_TYPEOF_TEMPLATE_TEMPLATE_PARAM_HPP_INCLUDED
#define STREAMS_BOOST_TYPEOF_TEMPLATE_TEMPLATE_PARAM_HPP_INCLUDED

#include <streams_boost/preprocessor/logical/or.hpp>
#include <streams_boost/preprocessor/seq/fold_left.hpp>
#include <streams_boost/preprocessor/seq/enum.hpp>

#define STREAMS_BOOST_TYPEOF_MAKE_OBJ_template(x)   STREAMS_BOOST_TYPEOF_TEMPLATE_PARAM(x)
#define STREAMS_BOOST_TYPEOF_TEMPLATE(X) template(X) STREAMS_BOOST_TYPEOF_EAT
#define STREAMS_BOOST_TYPEOF_template(X) (template(X))

#define STREAMS_BOOST_TYPEOF_TEMPLATE_PARAM(Params)\
    (TEMPLATE_PARAM)\
    (Params)

#define STREAMS_BOOST_TYPEOF_TEMPLATE_PARAM_GETPARAMS(This)\
    STREAMS_BOOST_TYPEOF_TOSEQ(STREAMS_BOOST_PP_SEQ_ELEM(1, This))

//Encode / decode this
#define STREAMS_BOOST_TYPEOF_TEMPLATE_PARAM_ENCODE(This, n)\
   typedef typename streams_boost::type_of::encode_template<STREAMS_BOOST_PP_CAT(V, n),\
       STREAMS_BOOST_PP_CAT(P, n)<STREAMS_BOOST_TYPEOF_SEQ_ENUM(STREAMS_BOOST_TYPEOF_MAKE_OBJS(STREAMS_BOOST_TYPEOF_TEMPLATE_PARAM_GETPARAMS(This)),STREAMS_BOOST_TYPEOF_PLACEHOLDER) >\
   >::type STREAMS_BOOST_PP_CAT(V, STREAMS_BOOST_PP_INC(n));

#define STREAMS_BOOST_TYPEOF_TEMPLATE_PARAM_DECODE(This, n)\
   typedef streams_boost::type_of::decode_template< STREAMS_BOOST_PP_CAT(iter, n) > STREAMS_BOOST_PP_CAT(d, n);\
   typedef typename STREAMS_BOOST_PP_CAT(d, n)::type STREAMS_BOOST_PP_CAT(P, n);\
   typedef typename STREAMS_BOOST_PP_CAT(d, n)::iter STREAMS_BOOST_PP_CAT(iter,STREAMS_BOOST_PP_INC(n));

// template<class, unsigned int, ...> class
#define STREAMS_BOOST_TYPEOF_TEMPLATE_PARAM_EXPANDTYPE(This) \
    template <STREAMS_BOOST_PP_SEQ_ENUM(STREAMS_BOOST_TYPEOF_TEMPLATE_PARAM_GETPARAMS(This)) > class

#define STREAMS_BOOST_TYPEOF_TEMPLATE_PARAM_PLACEHOLDER(Param)\
    Nested_Template_Template_Arguments_Not_Supported

//'template<class,int> class' is reduced to 'class'
#define STREAMS_BOOST_TYPEOF_TEMPLATE_PARAM_DECLARATION_TYPE(Param) class

// T3<int, (unsigned int)0, ...>
#define STREAMS_BOOST_TYPEOF_TEMPLATE_PARAM_PLACEHOLDER_TYPES(Param, n)\
    STREAMS_BOOST_PP_CAT(T,n)<STREAMS_BOOST_TYPEOF_SEQ_ENUM_1(STREAMS_BOOST_TYPEOF_MAKE_OBJS(STREAMS_BOOST_TYPEOF_TEMPLATE_PARAM_GETPARAMS(Param)),STREAMS_BOOST_TYPEOF_PLACEHOLDER) >

#define STREAMS_BOOST_TYPEOF_TEMPLATE_PARAM_ISTEMPLATE 1

////////////////////////////
// move to encode_decode?

STREAMS_BOOST_TYPEOF_BEGIN_ENCODE_NS

template<class V, class Type_Not_Registered_With_Typeof_System> struct encode_template_impl;
template<class T, class Iter> struct decode_template_impl;

STREAMS_BOOST_TYPEOF_END_ENCODE_NS

namespace streams_boost { namespace type_of {

    template<class V, class T> struct encode_template
        : STREAMS_BOOST_TYPEOF_ENCODE_NS_QUALIFIER::encode_template_impl<V, T>
    {};

    template<class Iter> struct decode_template
        : STREAMS_BOOST_TYPEOF_ENCODE_NS_QUALIFIER::decode_template_impl<typename Iter::type, typename Iter::next>
    {};
}}

////////////////////////////
// move to template_encoding.hpp?

//Template template registration
#define STREAMS_BOOST_TYPEOF_REGISTER_TYPE_FOR_TEMPLATE_TEMPLATE(Name,Params,ID)\
    template<class V\
        STREAMS_BOOST_TYPEOF_SEQ_ENUM_TRAILING(Params,STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE_PARAM_PAIR)\
    >\
    struct encode_template_impl<V,Name<\
        STREAMS_BOOST_PP_ENUM_PARAMS(\
        STREAMS_BOOST_PP_SEQ_SIZE(Params),\
        P)> >\
        : streams_boost::type_of::push_back<V, streams_boost::mpl::size_t<ID> >\
    {\
    };\
    template<class Iter> struct decode_template_impl<streams_boost::mpl::size_t<ID>, Iter>\
    {\
        STREAMS_BOOST_PP_REPEAT(STREAMS_BOOST_PP_SEQ_SIZE(Params),STREAMS_BOOST_TYPEOF_TYPEDEF_INT_PN,_)\
        typedef Name<STREAMS_BOOST_TYPEOF_SEQ_ENUM(Params,STREAMS_BOOST_TYPEOF_PLACEHOLDER) > type;\
        typedef Iter iter;\
    };

#define STREAMS_BOOST_TYPEOF_TYPEDEF_INT_PN(z,n,Params) typedef int STREAMS_BOOST_PP_CAT(P,n);

#ifdef __BORLANDC__
#define STREAMS_BOOST_TYPEOF_DECODE_NESTED_TEMPLATE_HELPER_NAME STREAMS_BOOST_PP_CAT(\
        STREAMS_BOOST_PP_CAT(\
            STREAMS_BOOST_PP_CAT(\
                decode_nested_template_helper,\
                STREAMS_BOOST_TYPEOF_REGISTRATION_GROUP\
            ),0x10000\
        ),__LINE__\
    )
#define STREAMS_BOOST_TYPEOF_REGISTER_DECODE_NESTED_TEMPLATE_HELPER_IMPL(Name,Params,ID)\
    struct STREAMS_BOOST_TYPEOF_DECODE_NESTED_TEMPLATE_HELPER_NAME {\
        template<STREAMS_BOOST_TYPEOF_SEQ_ENUM(Params,STREAMS_BOOST_TYPEOF_REGISTER_DECLARE_DECODER_TYPE_PARAM_PAIR) >\
        struct decode_params;\
        template<STREAMS_BOOST_TYPEOF_SEQ_ENUM(Params,STREAMS_BOOST_TYPEOF_REGISTER_DECODER_TYPE_PARAM_PAIR) >\
        struct decode_params<STREAMS_BOOST_TYPEOF_SEQ_ENUM(Params,STREAMS_BOOST_TYPEOF_PLACEHOLDER_TYPES) >\
        {\
            typedef Name<STREAMS_BOOST_PP_ENUM_PARAMS(STREAMS_BOOST_PP_SEQ_SIZE(Params),T)> type;\
        };\
    };
//Template template param decoding
#define STREAMS_BOOST_TYPEOF_TYPEDEF_DECODED_TEMPLATE_TEMPLATE_TYPE(Name,Params)\
    typedef typename STREAMS_BOOST_TYPEOF_DECODE_NESTED_TEMPLATE_HELPER_NAME::decode_params<STREAMS_BOOST_PP_ENUM_PARAMS(STREAMS_BOOST_PP_SEQ_SIZE(Params),P)>::type type;

#else
#define STREAMS_BOOST_TYPEOF_REGISTER_DECODE_NESTED_TEMPLATE_HELPER_IMPL(Name,Params,ID)

//Template template param decoding
#define STREAMS_BOOST_TYPEOF_TYPEDEF_DECODED_TEMPLATE_TEMPLATE_TYPE(Name,Params)\
    template<STREAMS_BOOST_TYPEOF_SEQ_ENUM(Params,STREAMS_BOOST_TYPEOF_REGISTER_DECLARE_DECODER_TYPE_PARAM_PAIR) >\
    struct decode_params;\
    template<STREAMS_BOOST_TYPEOF_SEQ_ENUM(Params,STREAMS_BOOST_TYPEOF_REGISTER_DECODER_TYPE_PARAM_PAIR) >\
    struct decode_params<STREAMS_BOOST_TYPEOF_SEQ_ENUM(Params,STREAMS_BOOST_TYPEOF_PLACEHOLDER_TYPES) >\
    {\
        typedef Name<STREAMS_BOOST_PP_ENUM_PARAMS(STREAMS_BOOST_PP_SEQ_SIZE(Params),T)> type;\
    };\
    typedef typename decode_params<STREAMS_BOOST_PP_ENUM_PARAMS(STREAMS_BOOST_PP_SEQ_SIZE(Params),P)>::type type;
#endif
#define STREAMS_BOOST_TYPEOF_REGISTER_DECLARE_DECODER_TYPE_PARAM_PAIR(z,n,elem) \
    STREAMS_BOOST_TYPEOF_VIRTUAL(DECLARATION_TYPE, elem)(elem) STREAMS_BOOST_PP_CAT(T, n)

// STREAMS_BOOST_TYPEOF_HAS_TEMPLATES
#define STREAMS_BOOST_TYPEOF_HAS_TEMPLATES(Params)\
    STREAMS_BOOST_PP_SEQ_FOLD_LEFT(STREAMS_BOOST_TYPEOF_HAS_TEMPLATES_OP, 0, Params)

#define STREAMS_BOOST_TYPEOF_HAS_TEMPLATES_OP(s, state, elem)\
    STREAMS_BOOST_PP_OR(state, STREAMS_BOOST_TYPEOF_VIRTUAL(ISTEMPLATE, elem))

//Define template template arguments
#define STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE_TEMPLATE_IMPL(Name,Params,ID)\
    STREAMS_BOOST_PP_IF(STREAMS_BOOST_TYPEOF_HAS_TEMPLATES(Params),\
        STREAMS_BOOST_TYPEOF_REGISTER_DECODE_NESTED_TEMPLATE_HELPER_IMPL,\
        STREAMS_BOOST_TYPEOF_REGISTER_TYPE_FOR_TEMPLATE_TEMPLATE)(Name,Params,ID)

#endif //STREAMS_BOOST_TYPEOF_TEMPLATE_TEMPLATE_PARAM_HPP_INCLUDED
