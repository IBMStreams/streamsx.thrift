
#ifndef STREAMS_BOOST_MPL_VECTOR_AUX_ITEM_HPP_INCLUDED
#define STREAMS_BOOST_MPL_VECTOR_AUX_ITEM_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: item.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/long.hpp>
#include <streams_boost/mpl/void.hpp>
#include <streams_boost/mpl/next_prior.hpp>
#include <streams_boost/mpl/aux_/type_wrapper.hpp>
#include <streams_boost/mpl/aux_/config/typeof.hpp>
#include <streams_boost/mpl/aux_/config/ctps.hpp>

namespace streams_boost { namespace mpl {

#if defined(STREAMS_BOOST_MPL_CFG_TYPEOF_BASED_SEQUENCES)

template< 
      typename T
    , typename Base
    , int at_front = 0
    >
struct v_item
    : Base
{
    typedef typename Base::upper_bound_ index_;
    typedef typename next<index_>::type upper_bound_;
    typedef typename next<typename Base::size>::type size;
    typedef Base base;
    typedef v_item type;

    // agurt 10/sep/04: MWCW <= 9.3 workaround here and below; the compiler
    // breaks if using declaration comes _before_ the new overload
    static aux::type_wrapper<T> item_(index_);
    using Base::item_;
};

template<
      typename T
    , typename Base
    >
struct v_item<T,Base,1>
    : Base
{
    typedef typename prior<typename Base::lower_bound_>::type index_;
    typedef index_ lower_bound_;
    typedef typename next<typename Base::size>::type size;
    typedef Base base;
    typedef v_item type;

    static aux::type_wrapper<T> item_(index_);
    using Base::item_;
};

// "erasure" item
template< 
      typename Base
    , int at_front
    >
struct v_mask
    : Base
{
    typedef typename prior<typename Base::upper_bound_>::type index_;
    typedef index_ upper_bound_;
    typedef typename prior<typename Base::size>::type size;
    typedef Base base;
    typedef v_mask type;

    static aux::type_wrapper<void_> item_(index_);
    using Base::item_;
};

template< 
      typename Base
    >
struct v_mask<Base,1>
    : Base
{
    typedef typename Base::lower_bound_ index_;
    typedef typename next<index_>::type lower_bound_;
    typedef typename prior<typename Base::size>::type size;
    typedef Base base;
    typedef v_mask type;

    static aux::type_wrapper<void_> item_(index_);
    using Base::item_;
};

#endif // STREAMS_BOOST_MPL_CFG_TYPEOF_BASED_SEQUENCES

}}

#endif // STREAMS_BOOST_MPL_VECTOR_AUX_ITEM_HPP_INCLUDED
