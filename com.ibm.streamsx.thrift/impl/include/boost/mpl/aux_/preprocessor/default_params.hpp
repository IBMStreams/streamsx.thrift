
#ifndef STREAMS_BOOST_MPL_AUX_PREPROCESSOR_DEFAULT_PARAMS_HPP_INCLUDED
#define STREAMS_BOOST_MPL_AUX_PREPROCESSOR_DEFAULT_PARAMS_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2002-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: default_params.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/aux_/config/preprocessor.hpp>

// STREAMS_BOOST_MPL_PP_DEFAULT_PARAMS(0,T,int): <nothing>
// STREAMS_BOOST_MPL_PP_DEFAULT_PARAMS(1,T,int): T1 = int
// STREAMS_BOOST_MPL_PP_DEFAULT_PARAMS(2,T,int): T1 = int, T2 = int
// STREAMS_BOOST_MPL_PP_DEFAULT_PARAMS(n,T,int): T1 = int, T2 = int, .., Tn = int

#if !defined(STREAMS_BOOST_MPL_CFG_NO_OWN_PP_PRIMITIVES)

#   include <streams_boost/preprocessor/cat.hpp>

#   define STREAMS_BOOST_MPL_PP_DEFAULT_PARAMS(n,p,v) \
    STREAMS_BOOST_PP_CAT(STREAMS_BOOST_MPL_PP_DEFAULT_PARAMS_,n)(p,v) \
    /**/
    
#   define STREAMS_BOOST_MPL_PP_DEFAULT_PARAMS_0(p,v)
#   define STREAMS_BOOST_MPL_PP_DEFAULT_PARAMS_1(p,v) p##1=v
#   define STREAMS_BOOST_MPL_PP_DEFAULT_PARAMS_2(p,v) p##1=v,p##2=v
#   define STREAMS_BOOST_MPL_PP_DEFAULT_PARAMS_3(p,v) p##1=v,p##2=v,p##3=v
#   define STREAMS_BOOST_MPL_PP_DEFAULT_PARAMS_4(p,v) p##1=v,p##2=v,p##3=v,p##4=v
#   define STREAMS_BOOST_MPL_PP_DEFAULT_PARAMS_5(p,v) p##1=v,p##2=v,p##3=v,p##4=v,p##5=v
#   define STREAMS_BOOST_MPL_PP_DEFAULT_PARAMS_6(p,v) p##1=v,p##2=v,p##3=v,p##4=v,p##5=v,p##6=v
#   define STREAMS_BOOST_MPL_PP_DEFAULT_PARAMS_7(p,v) p##1=v,p##2=v,p##3=v,p##4=v,p##5=v,p##6=v,p##7=v
#   define STREAMS_BOOST_MPL_PP_DEFAULT_PARAMS_8(p,v) p##1=v,p##2=v,p##3=v,p##4=v,p##5=v,p##6=v,p##7=v,p##8=v
#   define STREAMS_BOOST_MPL_PP_DEFAULT_PARAMS_9(p,v) p##1=v,p##2=v,p##3=v,p##4=v,p##5=v,p##6=v,p##7=v,p##8=v,p##9=v

#else

#   include <streams_boost/preprocessor/tuple/elem.hpp>
#   include <streams_boost/preprocessor/comma_if.hpp>
#   include <streams_boost/preprocessor/repeat.hpp>
#   include <streams_boost/preprocessor/inc.hpp>
#   include <streams_boost/preprocessor/cat.hpp>

#   define STREAMS_BOOST_MPL_PP_AUX_DEFAULT_PARAM_FUNC(unused, i, pv) \
    STREAMS_BOOST_PP_COMMA_IF(i) \
    STREAMS_BOOST_PP_CAT( STREAMS_BOOST_PP_TUPLE_ELEM(2,0,pv), STREAMS_BOOST_PP_INC(i) ) \
        = STREAMS_BOOST_PP_TUPLE_ELEM(2,1,pv) \
    /**/

#   define STREAMS_BOOST_MPL_PP_DEFAULT_PARAMS(n, param, value) \
    STREAMS_BOOST_PP_REPEAT( \
          n \
        , STREAMS_BOOST_MPL_PP_AUX_DEFAULT_PARAM_FUNC \
        , (param,value) \
        ) \
    /**/

#endif

#endif // STREAMS_BOOST_MPL_AUX_PREPROCESSOR_DEFAULT_PARAMS_HPP_INCLUDED
