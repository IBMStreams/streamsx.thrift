
#ifndef STREAMS_BOOST_MPL_SET_AUX_ERASE_IMPL_HPP_INCLUDED
#define STREAMS_BOOST_MPL_SET_AUX_ERASE_IMPL_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2003-2004
// Copyright David Abrahams 2003-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: erase_impl.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/erase_fwd.hpp>
#include <streams_boost/mpl/set/aux_/erase_key_impl.hpp>
#include <streams_boost/mpl/set/aux_/tag.hpp>

namespace streams_boost { namespace mpl {

template<>
struct erase_impl< aux::set_tag >
{
    template< 
          typename Set
        , typename Pos
        , typename unused_
        > 
    struct apply
        : erase_key_impl<aux::set_tag>
            ::apply<Set,typename Pos::type>
    {
    };
};

}}

#endif // STREAMS_BOOST_MPL_SET_AUX_ERASE_IMPL_HPP_INCLUDED
