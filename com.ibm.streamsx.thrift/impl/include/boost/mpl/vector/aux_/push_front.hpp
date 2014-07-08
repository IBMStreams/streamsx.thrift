
#ifndef STREAMS_BOOST_MPL_VECTOR_AUX_PUSH_FRONT_HPP_INCLUDED
#define STREAMS_BOOST_MPL_VECTOR_AUX_PUSH_FRONT_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: push_front.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/push_front_fwd.hpp>
#include <streams_boost/mpl/aux_/config/typeof.hpp>

#if defined(STREAMS_BOOST_MPL_CFG_TYPEOF_BASED_SEQUENCES)

#   include <streams_boost/mpl/vector/aux_/item.hpp>
#   include <streams_boost/mpl/vector/aux_/tag.hpp>

namespace streams_boost { namespace mpl {

template<>
struct push_front_impl< aux::vector_tag >
{
    template< typename Vector, typename T > struct apply
    {
        typedef v_item<T,Vector,1> type;
    };
};

}}

#endif // STREAMS_BOOST_MPL_CFG_TYPEOF_BASED_SEQUENCES

#endif // STREAMS_BOOST_MPL_VECTOR_AUX_PUSH_FRONT_HPP_INCLUDED
