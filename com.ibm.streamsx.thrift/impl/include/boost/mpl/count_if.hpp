
#ifndef STREAMS_BOOST_MPL_COUNT_IF_HPP_INCLUDED
#define STREAMS_BOOST_MPL_COUNT_IF_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2002
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: count_if.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/fold.hpp>
#include <streams_boost/mpl/next.hpp>
#include <streams_boost/mpl/integral_c.hpp>
#include <streams_boost/mpl/identity.hpp>
#include <streams_boost/mpl/eval_if.hpp>
#include <streams_boost/mpl/apply.hpp>
#include <streams_boost/mpl/aux_/msvc_eti_base.hpp>
#include <streams_boost/mpl/aux_/na_spec.hpp>
#include <streams_boost/mpl/aux_/lambda_support.hpp>
#include <streams_boost/mpl/aux_/config/forwarding.hpp>

namespace streams_boost { namespace mpl {

namespace aux {

template< typename Predicate >
struct next_if
{
    template<
          typename N
        , typename T
        >
    struct apply
#if !defined(STREAMS_BOOST_MPL_CFG_NO_NESTED_FORWARDING)
        : eval_if<
              typename apply1<Predicate,T>::type
            , next<N>
            , identity<N>
            >
    {
#else
    {
        typedef typename eval_if<
              typename apply1<Predicate,T>::type
            , next<N>
            , identity<N>
            >::type type;
#endif
    };
};

} // namespace aux


template<
      typename STREAMS_BOOST_MPL_AUX_NA_PARAM(Sequence)
    , typename STREAMS_BOOST_MPL_AUX_NA_PARAM(Predicate)
    >
struct count_if
    : aux::msvc_eti_base< typename fold<
          Sequence
        , integral_c<unsigned long,0>
        , protect< aux::next_if<Predicate> >
        >::type >
{
    STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(2,count_if,(Sequence,Predicate))
};

STREAMS_BOOST_MPL_AUX_NA_SPEC(2, count_if)

}}

#endif // STREAMS_BOOST_MPL_COUNT_IF_HPP_INCLUDED
