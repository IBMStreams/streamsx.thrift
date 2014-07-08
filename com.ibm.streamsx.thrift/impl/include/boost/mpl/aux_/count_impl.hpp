
#ifndef STREAMS_BOOST_MPL_AUX_COUNT_IMPL_HPP_INCLUDED
#define STREAMS_BOOST_MPL_AUX_COUNT_IMPL_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: count_impl.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/count_fwd.hpp>
#include <streams_boost/mpl/count_if.hpp>
#include <streams_boost/mpl/same_as.hpp>
#include <streams_boost/mpl/aux_/config/static_constant.hpp>
#include <streams_boost/mpl/aux_/config/workaround.hpp>
#include <streams_boost/mpl/aux_/traits_lambda_spec.hpp>

namespace streams_boost { namespace mpl {

template< typename Tag > struct count_impl
{
    template< typename Sequence, typename T > struct apply
#if STREAMS_BOOST_WORKAROUND(__BORLANDC__,STREAMS_BOOST_TESTED_AT(0x561))
    {
        typedef typename count_if< Sequence,same_as<T> >::type type;
        STREAMS_BOOST_STATIC_CONSTANT(int, value = STREAMS_BOOST_MPL_AUX_VALUE_WKND(type)::value);
#else
        : count_if< Sequence,same_as<T> >
    {
#endif
    };
};

STREAMS_BOOST_MPL_ALGORITM_TRAITS_LAMBDA_SPEC(2,count_impl)

}}

#endif // STREAMS_BOOST_MPL_AUX_COUNT_IMPL_HPP_INCLUDED
