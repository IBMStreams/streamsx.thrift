
#ifndef STREAMS_BOOST_MPL_AUX_PREPROCESSOR_DEF_PARAMS_TAIL_HPP_INCLUDED
#define STREAMS_BOOST_MPL_AUX_PREPROCESSOR_DEF_PARAMS_TAIL_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: def_params_tail.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/limits/arity.hpp>
#include <streams_boost/mpl/aux_/config/dtp.hpp>
#include <streams_boost/mpl/aux_/config/preprocessor.hpp>

#include <streams_boost/preprocessor/comma_if.hpp>
#include <streams_boost/preprocessor/logical/and.hpp>
#include <streams_boost/preprocessor/identity.hpp>
#include <streams_boost/preprocessor/empty.hpp>

// STREAMS_BOOST_MPL_PP_DEF_PARAMS_TAIL(1,T,value): , T1 = value, .., Tn = value
// STREAMS_BOOST_MPL_PP_DEF_PARAMS_TAIL(2,T,value): , T2 = value, .., Tn = value
// STREAMS_BOOST_MPL_PP_DEF_PARAMS_TAIL(n,T,value): <nothing>

#if !defined(STREAMS_BOOST_MPL_CFG_NO_OWN_PP_PRIMITIVES)

#   include <streams_boost/mpl/aux_/preprocessor/filter_params.hpp>
#   include <streams_boost/mpl/aux_/preprocessor/sub.hpp>

#   define STREAMS_BOOST_MPL_PP_DEF_PARAMS_TAIL_IMPL(i, param, value_func) \
    STREAMS_BOOST_MPL_PP_DEF_PARAMS_TAIL_DELAY_1( \
          i \
        , STREAMS_BOOST_MPL_PP_SUB(STREAMS_BOOST_MPL_LIMIT_METAFUNCTION_ARITY,i) \
        , param \
        , value_func \
        ) \
    /**/

#   define STREAMS_BOOST_MPL_PP_DEF_PARAMS_TAIL_DELAY_1(i, n, param, value_func) \
    STREAMS_BOOST_MPL_PP_DEF_PARAMS_TAIL_DELAY_2(i,n,param,value_func) \
    /**/

#   define STREAMS_BOOST_MPL_PP_DEF_PARAMS_TAIL_DELAY_2(i, n, param, value_func) \
    STREAMS_BOOST_PP_COMMA_IF(STREAMS_BOOST_PP_AND(i,n)) \
    STREAMS_BOOST_MPL_PP_DEF_PARAMS_TAIL_##i(n,param,value_func) \
    /**/

#   define STREAMS_BOOST_MPL_PP_DEF_PARAMS_TAIL_0(i,p,v) STREAMS_BOOST_MPL_PP_FILTER_PARAMS_##i(p##1 v(),p##2 v(),p##3 v(),p##4 v(),p##5 v(),p##6 v(),p##7 v(),p##8 v(),p##9 v())
#   define STREAMS_BOOST_MPL_PP_DEF_PARAMS_TAIL_1(i,p,v) STREAMS_BOOST_MPL_PP_FILTER_PARAMS_##i(p##2 v(),p##3 v(),p##4 v(),p##5 v(),p##6 v(),p##7 v(),p##8 v(),p##9 v(),p1)
#   define STREAMS_BOOST_MPL_PP_DEF_PARAMS_TAIL_2(i,p,v) STREAMS_BOOST_MPL_PP_FILTER_PARAMS_##i(p##3 v(),p##4 v(),p##5 v(),p##6 v(),p##7 v(),p##8 v(),p##9 v(),p1,p2)
#   define STREAMS_BOOST_MPL_PP_DEF_PARAMS_TAIL_3(i,p,v) STREAMS_BOOST_MPL_PP_FILTER_PARAMS_##i(p##4 v(),p##5 v(),p##6 v(),p##7 v(),p##8 v(),p##9 v(),p1,p2,p3)
#   define STREAMS_BOOST_MPL_PP_DEF_PARAMS_TAIL_4(i,p,v) STREAMS_BOOST_MPL_PP_FILTER_PARAMS_##i(p##5 v(),p##6 v(),p##7 v(),p##8 v(),p##9 v(),p1,p2,p3,p4)
#   define STREAMS_BOOST_MPL_PP_DEF_PARAMS_TAIL_5(i,p,v) STREAMS_BOOST_MPL_PP_FILTER_PARAMS_##i(p##6 v(),p##7 v(),p##8 v(),p##9 v(),p1,p2,p3,p4,p5)
#   define STREAMS_BOOST_MPL_PP_DEF_PARAMS_TAIL_6(i,p,v) STREAMS_BOOST_MPL_PP_FILTER_PARAMS_##i(p##7 v(),p##8 v(),p##9 v(),p1,p2,p3,p4,p5,p6)
#   define STREAMS_BOOST_MPL_PP_DEF_PARAMS_TAIL_7(i,p,v) STREAMS_BOOST_MPL_PP_FILTER_PARAMS_##i(p##8 v(),p##9 v(),p1,p2,p3,p4,p5,p6,p7)
#   define STREAMS_BOOST_MPL_PP_DEF_PARAMS_TAIL_8(i,p,v) STREAMS_BOOST_MPL_PP_FILTER_PARAMS_##i(p##9 v(),p1,p2,p3,p4,p5,p6,p7,p8)
#   define STREAMS_BOOST_MPL_PP_DEF_PARAMS_TAIL_9(i,p,v) STREAMS_BOOST_MPL_PP_FILTER_PARAMS_##i(p1,p2,p3,p4,p5,p6,p7,p8,p9)

#else

#   include <streams_boost/preprocessor/arithmetic/add.hpp>
#   include <streams_boost/preprocessor/arithmetic/sub.hpp>
#   include <streams_boost/preprocessor/inc.hpp>
#   include <streams_boost/preprocessor/tuple/elem.hpp>
#   include <streams_boost/preprocessor/repeat.hpp>
#   include <streams_boost/preprocessor/cat.hpp>

#   define STREAMS_BOOST_MPL_PP_AUX_TAIL_PARAM_FUNC(unused, i, op) \
    , STREAMS_BOOST_PP_CAT( \
          STREAMS_BOOST_PP_TUPLE_ELEM(3, 1, op) \
        , STREAMS_BOOST_PP_ADD_D(1, i, STREAMS_BOOST_PP_INC(STREAMS_BOOST_PP_TUPLE_ELEM(3, 0, op))) \
        ) STREAMS_BOOST_PP_TUPLE_ELEM(3, 2, op)() \
    /**/

#   define STREAMS_BOOST_MPL_PP_DEF_PARAMS_TAIL_IMPL(i, param, value_func) \
    STREAMS_BOOST_PP_REPEAT( \
          STREAMS_BOOST_PP_SUB_D(1, STREAMS_BOOST_MPL_LIMIT_METAFUNCTION_ARITY, i) \
        , STREAMS_BOOST_MPL_PP_AUX_TAIL_PARAM_FUNC \
        , (i, param, value_func) \
        ) \
    /**/


#endif // STREAMS_BOOST_MPL_CFG_NO_OWN_PP_PRIMITIVES

#define STREAMS_BOOST_MPL_PP_DEF_PARAMS_TAIL(i, param, value) \
    STREAMS_BOOST_MPL_PP_DEF_PARAMS_TAIL_IMPL(i, param, STREAMS_BOOST_PP_IDENTITY(=value)) \
    /**/

#if !defined(STREAMS_BOOST_MPL_CFG_NO_DEFAULT_PARAMETERS_IN_NESTED_TEMPLATES)
#   define STREAMS_BOOST_MPL_PP_NESTED_DEF_PARAMS_TAIL(i, param, value) \
    STREAMS_BOOST_MPL_PP_DEF_PARAMS_TAIL_IMPL(i, param, STREAMS_BOOST_PP_IDENTITY(=value)) \
    /**/
#else
#   define STREAMS_BOOST_MPL_PP_NESTED_DEF_PARAMS_TAIL(i, param, value) \
    STREAMS_BOOST_MPL_PP_DEF_PARAMS_TAIL_IMPL(i, param, STREAMS_BOOST_PP_EMPTY) \
    /**/
#endif

#endif // STREAMS_BOOST_MPL_AUX_PREPROCESSOR_DEF_PARAMS_TAIL_HPP_INCLUDED