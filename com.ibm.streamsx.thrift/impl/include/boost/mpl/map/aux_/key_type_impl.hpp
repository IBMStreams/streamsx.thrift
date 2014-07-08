
#ifndef STREAMS_BOOST_MPL_MAP_AUX_KEY_TYPE_IMPL_HPP_INCLUDED
#define STREAMS_BOOST_MPL_MAP_AUX_KEY_TYPE_IMPL_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2003-2004
// Copyright David Abrahams 2003-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: key_type_impl.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/key_type_fwd.hpp>
#include <streams_boost/mpl/pair.hpp>
#include <streams_boost/mpl/map/aux_/tag.hpp>

namespace streams_boost {
namespace mpl {

template<>
struct key_type_impl< aux::map_tag >
{
    template< typename Map, typename T > struct apply
        : first<T>
    {
    };
};

}}

#endif // STREAMS_BOOST_MPL_MAP_AUX_KEY_TYPE_IMPL_HPP_INCLUDED
