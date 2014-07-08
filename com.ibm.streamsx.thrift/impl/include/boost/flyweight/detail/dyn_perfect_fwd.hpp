/* Copyright 2006-2008 Joaquin M Lopez Munoz.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.streams_boost.org/LICENSE_1_0.txt)
 *
 * See http://www.streams_boost.org/libs/flyweight for library home page.
 */

/* no include guards */

#include <streams_boost/preprocessor/arithmetic/add.hpp>
#include <streams_boost/preprocessor/cat.hpp>
#include <streams_boost/preprocessor/repetition/enum.hpp>
#include <streams_boost/preprocessor/repetition/enum_params.hpp>
#include <streams_boost/preprocessor/repetition/repeat.hpp>
#include <streams_boost/preprocessor/repetition/repeat_from_to.hpp>
#include <streams_boost/preprocessor/seq/elem.hpp>
#include <streams_boost/preprocessor/seq/for_each_product.hpp> 
#include <streams_boost/preprocessor/seq/size.hpp>

#define STREAMS_BOOST_FLYWEIGHT_CONST(b) STREAMS_BOOST_PP_CAT(STREAMS_BOOST_FLYWEIGHT_CONST,b)
#define STREAMS_BOOST_FLYWEIGHT_CONST0
#define STREAMS_BOOST_FLYWEIGHT_CONST1 const

/* if mask[n]==0 --> Tn& tn
 * if mask[n]==1 --> const Tn& tn
 */

#define STREAMS_BOOST_FLYWEIGHT_PERFECT_FWD_ARG(z,n,mask)                  \
STREAMS_BOOST_FLYWEIGHT_CONST(STREAMS_BOOST_PP_SEQ_ELEM(n,mask))                   \
STREAMS_BOOST_PP_CAT(T,n)& STREAMS_BOOST_PP_CAT(t,n)

/* overload accepting size(mask) args, where the template args are
 * marked const or not according to the given mask (a seq of 0 or 1)
 */

#define STREAMS_BOOST_FLYWEIGHT_PERFECT_FWD(r,mask)                        \
template<STREAMS_BOOST_PP_ENUM_PARAMS(STREAMS_BOOST_PP_SEQ_SIZE(mask),typename T)> \
STREAMS_BOOST_FLYWEIGHT_PERFECT_FWD_NAME(                                  \
  STREAMS_BOOST_PP_ENUM(                                                   \
    STREAMS_BOOST_PP_SEQ_SIZE(mask),STREAMS_BOOST_FLYWEIGHT_PERFECT_FWD_ARG,mask)) \
STREAMS_BOOST_FLYWEIGHT_PERFECT_FWD_BODY(STREAMS_BOOST_PP_SEQ_SIZE(mask))

#define STREAMS_BOOST_FLYWEIGHT_01(z,n,_) ((0)(1))

/* Perfect forwarding overloads accepting 1 to n args */
 
#define STREAMS_BOOST_FLYWEIGHT_PERFECT_FWDS_N(z,n,_)                      \
STREAMS_BOOST_PP_SEQ_FOR_EACH_PRODUCT(                                     \
  STREAMS_BOOST_FLYWEIGHT_PERFECT_FWD,                                     \
  STREAMS_BOOST_PP_REPEAT(n,STREAMS_BOOST_FLYWEIGHT_01,~))

#define STREAMS_BOOST_FLYWEIGHT_PERFECT_FWD_OVERLOADS                      \
STREAMS_BOOST_PP_REPEAT_FROM_TO(                                           \
  1,STREAMS_BOOST_PP_ADD(STREAMS_BOOST_FLYWEIGHT_LIMIT_PERFECT_FWD_ARGS,1),        \
  STREAMS_BOOST_FLYWEIGHT_PERFECT_FWDS_N,~)

/* generate the overloads */

STREAMS_BOOST_FLYWEIGHT_PERFECT_FWD_OVERLOADS

/* clean up */

#undef STREAMS_BOOST_FLYWEIGHT_PERFECT_FWD_OVERLOADS
#undef STREAMS_BOOST_FLYWEIGHT_01
#undef STREAMS_BOOST_FLYWEIGHT_PERFECT_FWD
#undef STREAMS_BOOST_FLYWEIGHT_PERFECT_FWD_ARG
#undef STREAMS_BOOST_FLYWEIGHT_CONST1 
#undef STREAMS_BOOST_FLYWEIGHT_CONST0
#undef STREAMS_BOOST_FLYWEIGHT_CONST

/* user supplied argument macros */

#undef STREAMS_BOOST_FLYWEIGHT_PERFECT_FWD_BODY
#undef STREAMS_BOOST_FLYWEIGHT_PERFECT_FWD_NAME
