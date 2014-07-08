
#ifndef STREAMS_BOOST_MPL_AUX_FRONT_IMPL_HPP_INCLUDED
#define STREAMS_BOOST_MPL_AUX_FRONT_IMPL_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: front_impl.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/front_fwd.hpp>
#include <streams_boost/mpl/begin_end.hpp>
#include <streams_boost/mpl/deref.hpp>
#include <streams_boost/mpl/aux_/traits_lambda_spec.hpp>

namespace streams_boost { namespace mpl {

// default implementation; conrete sequences might override it by 
// specializing either the 'front_impl' or the primary 'front' template

template< typename Tag >
struct front_impl
{
    template< typename Sequence > struct apply
    {
        typedef typename begin<Sequence>::type iter_;
        typedef typename deref<iter_>::type type;
    };
};

STREAMS_BOOST_MPL_ALGORITM_TRAITS_LAMBDA_SPEC(1,front_impl)

}}

#endif // STREAMS_BOOST_MPL_AUX_FRONT_IMPL_HPP_INCLUDED
