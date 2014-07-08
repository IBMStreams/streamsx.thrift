
#ifndef STREAMS_BOOST_MPL_AUX_SIZE_IMPL_HPP_INCLUDED
#define STREAMS_BOOST_MPL_AUX_SIZE_IMPL_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: size_impl.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/size_fwd.hpp>
#include <streams_boost/mpl/begin_end.hpp>
#include <streams_boost/mpl/distance.hpp>
#include <streams_boost/mpl/aux_/traits_lambda_spec.hpp>
#include <streams_boost/mpl/aux_/config/workaround.hpp>

namespace streams_boost { namespace mpl {

// default implementation; conrete sequences might override it by 
// specializing either the 'size_impl' or the primary 'size' template

template< typename Tag >
struct size_impl
{
    template< typename Sequence > struct apply
#if !STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x561))
        : distance<
              typename begin<Sequence>::type
            , typename end<Sequence>::type
            >
    {
#else
    {
        typedef typename distance<
              typename begin<Sequence>::type
            , typename end<Sequence>::type
            >::type type;
#endif
    };
};

STREAMS_BOOST_MPL_ALGORITM_TRAITS_LAMBDA_SPEC(1, size_impl)

}}

#endif // STREAMS_BOOST_MPL_AUX_SIZE_IMPL_HPP_INCLUDED