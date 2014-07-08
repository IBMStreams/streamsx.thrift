
#ifndef STREAMS_BOOST_MPL_ORDER_HPP_INCLUDED
#define STREAMS_BOOST_MPL_ORDER_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2003-2004
// Copyright David Abrahams 2003-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: order.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/order_fwd.hpp>
#include <streams_boost/mpl/sequence_tag.hpp>
#include <streams_boost/mpl/aux_/order_impl.hpp>
#include <streams_boost/mpl/aux_/na_spec.hpp>
#include <streams_boost/mpl/aux_/lambda_support.hpp>

namespace streams_boost { namespace mpl {

template<
      typename STREAMS_BOOST_MPL_AUX_NA_PARAM(AssociativeSequence)
    , typename STREAMS_BOOST_MPL_AUX_NA_PARAM(Key)
    >
struct order
    : order_impl< typename sequence_tag<AssociativeSequence>::type >
        ::template apply<AssociativeSequence,Key>
{
    STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(2,order,(AssociativeSequence,Key))
};

STREAMS_BOOST_MPL_AUX_NA_SPEC(2, order)

}}

#endif // STREAMS_BOOST_MPL_ORDER_HPP_INCLUDED
