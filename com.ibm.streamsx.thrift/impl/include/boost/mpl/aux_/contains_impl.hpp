
#ifndef STREAMS_BOOST_MPL_AUX_CONTAINS_IMPL_HPP_INCLUDED
#define STREAMS_BOOST_MPL_AUX_CONTAINS_IMPL_HPP_INCLUDED

// Copyright Eric Friedman 2002
// Copyright Aleksey Gurtovoy 2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: contains_impl.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/contains_fwd.hpp>
#include <streams_boost/mpl/begin_end.hpp>
#include <streams_boost/mpl/find.hpp>
#include <streams_boost/mpl/not.hpp>
#include <streams_boost/mpl/aux_/traits_lambda_spec.hpp>
#include <streams_boost/mpl/aux_/config/forwarding.hpp>
#include <streams_boost/mpl/aux_/config/static_constant.hpp>

#include <streams_boost/type_traits/is_same.hpp>

namespace streams_boost { namespace mpl {

template< typename Tag >
struct contains_impl
{
    template< typename Sequence, typename T > struct apply
#if !defined(STREAMS_BOOST_MPL_CFG_NO_NESTED_FORWARDING)
        : not_< is_same<
              typename find<Sequence,T>::type
            , typename end<Sequence>::type
            > >
    {
#else
    {
        typedef not_< is_same<
              typename find<Sequence,T>::type
            , typename end<Sequence>::type
            > > type;

        STREAMS_BOOST_STATIC_CONSTANT(bool, value = 
              (not_< is_same<
                  typename find<Sequence,T>::type
                , typename end<Sequence>::type
                > >::value)
            );
#endif
    };
};

STREAMS_BOOST_MPL_ALGORITM_TRAITS_LAMBDA_SPEC(2,contains_impl)

}}

#endif // STREAMS_BOOST_MPL_AUX_CONTAINS_IMPL_HPP_INCLUDED
