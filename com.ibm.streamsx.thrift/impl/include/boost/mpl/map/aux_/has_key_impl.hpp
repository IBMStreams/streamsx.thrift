
#ifndef STREAMS_BOOST_MPL_MAP_AUX_HAS_KEY_IMPL_HPP_INCLUDED
#define STREAMS_BOOST_MPL_MAP_AUX_HAS_KEY_IMPL_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2003-2004
// Copyright David Abrahams 2003-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: has_key_impl.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/has_key_fwd.hpp>
#include <streams_boost/mpl/map/aux_/tag.hpp>
#include <streams_boost/mpl/map/aux_/at_impl.hpp>
#include <streams_boost/mpl/void.hpp>
#include <streams_boost/mpl/aux_/config/typeof.hpp>

namespace streams_boost { namespace mpl {

template<>
struct has_key_impl< aux::map_tag >
{
    template< typename Map, typename Key > struct apply
#if defined(STREAMS_BOOST_MPL_CFG_TYPEOF_BASED_SEQUENCES)
        : is_not_void_< 
              typename at_impl<aux::map_tag>
                ::apply<Map,Key>::type
            >
#else
        : bool_< ( x_order_impl<Map,Key>::value > 1 ) >
#endif
    {
    };
};

}}

#endif // STREAMS_BOOST_MPL_MAP_AUX_HAS_KEY_IMPL_HPP_INCLUDED