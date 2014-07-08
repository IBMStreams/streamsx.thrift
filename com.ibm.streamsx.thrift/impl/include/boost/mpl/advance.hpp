
#ifndef STREAMS_BOOST_MPL_ADVANCE_HPP_INCLUDED
#define STREAMS_BOOST_MPL_ADVANCE_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: advance.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/advance_fwd.hpp>
#include <streams_boost/mpl/less.hpp>
#include <streams_boost/mpl/negate.hpp>
#include <streams_boost/mpl/long.hpp>
#include <streams_boost/mpl/if.hpp>
#include <streams_boost/mpl/tag.hpp>
#include <streams_boost/mpl/apply_wrap.hpp>
#include <streams_boost/mpl/aux_/advance_forward.hpp>
#include <streams_boost/mpl/aux_/advance_backward.hpp>
#include <streams_boost/mpl/aux_/value_wknd.hpp>
#include <streams_boost/mpl/aux_/na_spec.hpp>
#include <streams_boost/mpl/aux_/nttp_decl.hpp>

namespace streams_boost { namespace mpl {

// default implementation for forward/bidirectional iterators
template< typename Tag >
struct advance_impl
{
    template< typename Iterator, typename N > struct apply
    {
        typedef typename less< N,long_<0> >::type backward_;
        typedef typename if_< backward_, negate<N>, N >::type offset_;

        typedef typename if_<
              backward_
            , aux::advance_backward< STREAMS_BOOST_MPL_AUX_VALUE_WKND(offset_)::value >
            , aux::advance_forward< STREAMS_BOOST_MPL_AUX_VALUE_WKND(offset_)::value >
            >::type f_;

        typedef typename apply_wrap1<f_,Iterator>::type type;
    };
};


template<
      typename STREAMS_BOOST_MPL_AUX_NA_PARAM(Iterator)
    , typename STREAMS_BOOST_MPL_AUX_NA_PARAM(N)
    >
struct advance
    : advance_impl< typename tag<Iterator>::type >
        ::template apply<Iterator,N>
{
};

template<
      typename Iterator
    , STREAMS_BOOST_MPL_AUX_NTTP_DECL(long, N)
    >
struct advance_c
    : advance_impl< typename tag<Iterator>::type >
        ::template apply<Iterator,long_<N> >
{
};

STREAMS_BOOST_MPL_AUX_NA_SPEC(2, advance)

}}

#endif // STREAMS_BOOST_MPL_ADVANCE_HPP_INCLUDED
