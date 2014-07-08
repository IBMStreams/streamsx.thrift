
#ifndef STREAMS_BOOST_MPL_AUX_BACK_IMPL_HPP_INCLUDED
#define STREAMS_BOOST_MPL_AUX_BACK_IMPL_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: back_impl.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/begin_end.hpp>
#include <streams_boost/mpl/next_prior.hpp>
#include <streams_boost/mpl/deref.hpp>
#include <streams_boost/mpl/aux_/traits_lambda_spec.hpp>

namespace streams_boost { namespace mpl {

// default implementation, requires at least bi-directional iterators;
// conrete sequences might override it by specializing either the 
// 'back_impl' or the primary 'back' template

template< typename Tag >
struct back_impl
{
    template< typename Sequence > struct apply
    {
        typedef typename end<Sequence>::type end_;
        typedef typename prior<end_>::type last_;
        typedef typename deref<last_>::type type;
    };
};

STREAMS_BOOST_MPL_ALGORITM_TRAITS_LAMBDA_SPEC(1, back_impl)

}}

#endif // STREAMS_BOOST_MPL_AUX_BACK_IMPL_HPP_INCLUDED
