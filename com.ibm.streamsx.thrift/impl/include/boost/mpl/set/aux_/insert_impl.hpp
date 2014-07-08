
#ifndef STREAMS_BOOST_MPL_SET_AUX_INSERT_IMPL_HPP_INCLUDED
#define STREAMS_BOOST_MPL_SET_AUX_INSERT_IMPL_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2003-2007
// Copyright David Abrahams 2003-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: insert_impl.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/insert_fwd.hpp>
#include <streams_boost/mpl/set/aux_/has_key_impl.hpp>
#include <streams_boost/mpl/set/aux_/item.hpp>
#include <streams_boost/mpl/set/aux_/tag.hpp>
#include <streams_boost/mpl/identity.hpp>
#include <streams_boost/mpl/base.hpp>
#include <streams_boost/mpl/eval_if.hpp>
#include <streams_boost/mpl/aux_/na.hpp>

#include <streams_boost/type_traits/is_same.hpp>

namespace streams_boost { namespace mpl {

namespace aux {
template<  typename Set, typename T > struct set_insert_impl
    : eval_if< 
          has_key_impl<aux::set_tag>::apply<Set,T>
        , identity<Set>
        , eval_if< 
              is_same< T,typename Set::last_masked_ > 
            , base<Set>
            , identity< s_item<T,typename Set::item_> >
            >
        >
{
};
}

template<>
struct insert_impl< aux::set_tag >
{
    template< 
          typename Set
        , typename PosOrKey
        , typename KeyOrNA
        > 
    struct apply
        : aux::set_insert_impl<
              Set
            , typename if_na<KeyOrNA,PosOrKey>::type
            >
    {
    };
};

}}

#endif // STREAMS_BOOST_MPL_SET_AUX_INSERT_IMPL_HPP_INCLUDED
