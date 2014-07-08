
#ifndef STREAMS_BOOST_MPL_EVAL_IF_HPP_INCLUDED
#define STREAMS_BOOST_MPL_EVAL_IF_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: eval_if.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/if.hpp>
#include <streams_boost/mpl/aux_/na_spec.hpp>
#include <streams_boost/mpl/aux_/lambda_support.hpp>
#include <streams_boost/mpl/aux_/config/msvc.hpp>
#include <streams_boost/mpl/aux_/config/gcc.hpp>
#include <streams_boost/mpl/aux_/config/workaround.hpp>

namespace streams_boost { namespace mpl {

template<
      typename STREAMS_BOOST_MPL_AUX_NA_PARAM(C)
    , typename STREAMS_BOOST_MPL_AUX_NA_PARAM(F1)
    , typename STREAMS_BOOST_MPL_AUX_NA_PARAM(F2)
    >
struct eval_if
#if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, <= 1300) \
     || ( STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MPL_CFG_GCC, >= 0x0300) \
        && STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MPL_CFG_GCC, STREAMS_BOOST_TESTED_AT(0x0304)) \
        )
{
    typedef typename if_<C,F1,F2>::type f_;
    typedef typename f_::type type;
#else
    : if_<C,F1,F2>::type
{
#endif
    STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(3,eval_if,(C,F1,F2))
};

// (almost) copy & paste in order to save one more 
// recursively nested template instantiation to user
template<
      bool C
    , typename F1
    , typename F2
    >
struct eval_if_c
#if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, <= 1300) \
     || ( STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MPL_CFG_GCC, >= 0x0300) \
        && STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MPL_CFG_GCC, STREAMS_BOOST_TESTED_AT(0x0304)) \
        )
{
    typedef typename if_c<C,F1,F2>::type f_;
    typedef typename f_::type type;
#else
    : if_c<C,F1,F2>::type
{
#endif
};

STREAMS_BOOST_MPL_AUX_NA_SPEC(3, eval_if)

}}

#endif // STREAMS_BOOST_MPL_EVAL_IF_HPP_INCLUDED
