
#ifndef STREAMS_BOOST_MPL_AUX_INSERTER_ALGORITHM_HPP_INCLUDED
#define STREAMS_BOOST_MPL_AUX_INSERTER_ALGORITHM_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2003-2004
// Copyright David Abrahams 2003-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: inserter_algorithm.hpp 55648 2009-08-18 05:16:53Z agurtovoy $
// $Date: 2009-08-18 01:16:53 -0400 (Tue, 18 Aug 2009) $
// $Revision: 55648 $

#include <streams_boost/mpl/back_inserter.hpp>
#include <streams_boost/mpl/front_inserter.hpp>
#include <streams_boost/mpl/push_back.hpp>
#include <streams_boost/mpl/push_front.hpp>
#include <streams_boost/mpl/back_inserter.hpp>
#include <streams_boost/mpl/front_inserter.hpp>
#include <streams_boost/mpl/clear.hpp>
#include <streams_boost/mpl/eval_if.hpp>
#include <streams_boost/mpl/if.hpp>
#include <streams_boost/mpl/aux_/na.hpp>
#include <streams_boost/mpl/aux_/common_name_wknd.hpp>
#include <streams_boost/mpl/aux_/na_spec.hpp>
#include <streams_boost/mpl/aux_/preprocessor/params.hpp>
#include <streams_boost/mpl/aux_/preprocessor/default_params.hpp>
#include <streams_boost/mpl/aux_/config/ctps.hpp>

#include <streams_boost/preprocessor/arithmetic/dec.hpp>

#if !defined(STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)

#   define STREAMS_BOOST_MPL_AUX_INSERTER_ALGORITHM_DEF(arity, name) \
STREAMS_BOOST_MPL_AUX_COMMON_NAME_WKND(name) \
template< \
      STREAMS_BOOST_MPL_PP_DEFAULT_PARAMS(arity, typename P, na) \
    > \
struct name \
    : aux::name##_impl<STREAMS_BOOST_MPL_PP_PARAMS(arity, P)> \
{ \
}; \
\
template< \
      STREAMS_BOOST_MPL_PP_PARAMS(STREAMS_BOOST_PP_DEC(arity), typename P) \
    > \
struct name< STREAMS_BOOST_MPL_PP_PARAMS(STREAMS_BOOST_PP_DEC(arity), P),na > \
    : if_< has_push_back< typename clear<P1>::type> \
        , aux::name##_impl< \
              STREAMS_BOOST_MPL_PP_PARAMS(STREAMS_BOOST_PP_DEC(arity), P) \
            , back_inserter< typename clear<P1>::type > \
            > \
        , aux::reverse_##name##_impl< \
              STREAMS_BOOST_MPL_PP_PARAMS(STREAMS_BOOST_PP_DEC(arity), P) \
            , front_inserter< typename clear<P1>::type > \
            > \
        >::type \
{ \
}; \
\
template< \
      STREAMS_BOOST_MPL_PP_DEFAULT_PARAMS(arity, typename P, na) \
    > \
struct reverse_##name \
    : aux::reverse_##name##_impl<STREAMS_BOOST_MPL_PP_PARAMS(arity, P)> \
{ \
}; \
\
template< \
      STREAMS_BOOST_MPL_PP_PARAMS(STREAMS_BOOST_PP_DEC(arity), typename P) \
    > \
struct reverse_##name< STREAMS_BOOST_MPL_PP_PARAMS(STREAMS_BOOST_PP_DEC(arity), P),na > \
    : if_< has_push_back<P1> \
        , aux::reverse_##name##_impl< \
              STREAMS_BOOST_MPL_PP_PARAMS(STREAMS_BOOST_PP_DEC(arity), P) \
            , back_inserter< typename clear<P1>::type > \
            > \
        , aux::name##_impl< \
              STREAMS_BOOST_MPL_PP_PARAMS(STREAMS_BOOST_PP_DEC(arity), P) \
            , front_inserter< typename clear<P1>::type > \
            > \
        >::type \
{ \
}; \
STREAMS_BOOST_MPL_AUX_NA_SPEC(arity, name) \
STREAMS_BOOST_MPL_AUX_NA_SPEC(arity, reverse_##name) \
/**/

#else

#   define STREAMS_BOOST_MPL_AUX_INSERTER_ALGORITHM_DEF(arity, name) \
STREAMS_BOOST_MPL_AUX_COMMON_NAME_WKND(name) \
template< \
      STREAMS_BOOST_MPL_PP_PARAMS(STREAMS_BOOST_PP_DEC(arity), typename P) \
    > \
struct def_##name##_impl \
    : if_< has_push_back<P1> \
        , aux::name##_impl< \
              STREAMS_BOOST_MPL_PP_PARAMS(STREAMS_BOOST_PP_DEC(arity), P) \
            , back_inserter< typename clear<P1>::type > \
            > \
        , aux::reverse_##name##_impl< \
              STREAMS_BOOST_MPL_PP_PARAMS(STREAMS_BOOST_PP_DEC(arity), P) \
            , front_inserter< typename clear<P1>::type > \
            > \
        >::type \
{ \
}; \
\
template< \
      STREAMS_BOOST_MPL_PP_DEFAULT_PARAMS(arity, typename P, na) \
    > \
struct name \
{ \
    typedef typename eval_if< \
          is_na<STREAMS_BOOST_PP_CAT(P, arity)> \
        , def_##name##_impl<STREAMS_BOOST_MPL_PP_PARAMS(STREAMS_BOOST_PP_DEC(arity), P)> \
        , aux::name##_impl<STREAMS_BOOST_MPL_PP_PARAMS(arity, P)> \
        >::type type; \
}; \
\
template< \
      STREAMS_BOOST_MPL_PP_PARAMS(STREAMS_BOOST_PP_DEC(arity), typename P) \
    > \
struct def_reverse_##name##_impl \
    : if_< has_push_back<P1> \
        , aux::reverse_##name##_impl< \
              STREAMS_BOOST_MPL_PP_PARAMS(STREAMS_BOOST_PP_DEC(arity), P) \
            , back_inserter< typename clear<P1>::type > \
            > \
        , aux::name##_impl< \
              STREAMS_BOOST_MPL_PP_PARAMS(STREAMS_BOOST_PP_DEC(arity), P) \
            , front_inserter< typename clear<P1>::type > \
            > \
        >::type \
{ \
}; \
template< \
      STREAMS_BOOST_MPL_PP_DEFAULT_PARAMS(arity, typename P, na) \
    > \
struct reverse_##name \
{ \
    typedef typename eval_if< \
          is_na<STREAMS_BOOST_PP_CAT(P, arity)> \
        , def_reverse_##name##_impl<STREAMS_BOOST_MPL_PP_PARAMS(STREAMS_BOOST_PP_DEC(arity), P)> \
        , aux::reverse_##name##_impl<STREAMS_BOOST_MPL_PP_PARAMS(arity, P)> \
        >::type type; \
}; \
STREAMS_BOOST_MPL_AUX_NA_SPEC(arity, name) \
STREAMS_BOOST_MPL_AUX_NA_SPEC(arity, reverse_##name) \
/**/

#endif // STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

#endif // STREAMS_BOOST_MPL_AUX_INSERTER_ALGORITHM_HPP_INCLUDED
