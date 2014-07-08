
#ifndef STREAMS_BOOST_MPL_SET_AUX_AT_IMPL_HPP_INCLUDED
#define STREAMS_BOOST_MPL_SET_AUX_AT_IMPL_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2003-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: at_impl.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/at_fwd.hpp>
#include <streams_boost/mpl/set/aux_/has_key_impl.hpp>
#include <streams_boost/mpl/set/aux_/tag.hpp>
#include <streams_boost/mpl/if.hpp>
#include <streams_boost/mpl/void.hpp>

namespace streams_boost { namespace mpl {

template<>
struct at_impl< aux::set_tag >
{
    template< typename Set, typename T > struct apply
    {
        typedef typename if_< 
              has_key_impl<aux::set_tag>::apply<Set,T>
            , T
            , void_
            >::type type;            
    };
};

}}

#endif // STREAMS_BOOST_MPL_SET_AUX_AT_IMPL_HPP_INCLUDED