
#ifndef STREAMS_BOOST_MPL_SET_AUX_ITEM_HPP_INCLUDED
#define STREAMS_BOOST_MPL_SET_AUX_ITEM_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2003-2007
// Copyright David Abrahams 2003-2004
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
#include <streams_boost/mpl/next.hpp>
#include <streams_boost/mpl/prior.hpp>
#include <streams_boost/mpl/set/aux_/set0.hpp>
#include <streams_boost/mpl/aux_/type_wrapper.hpp>
#include <streams_boost/mpl/aux_/config/arrays.hpp>

namespace streams_boost { namespace mpl {

template< typename T, typename Base >
struct s_item
    : Base
{
    typedef s_item<T,Base> item_;
    typedef void_       last_masked_;
    typedef T           item_type_;
    typedef Base        base;
    
    typedef typename next< typename Base::size >::type  size;
    typedef typename next< typename Base::order >::type order;

#if defined(STREAMS_BOOST_MPL_CFG_NO_DEPENDENT_ARRAY_TYPES)
    typedef typename aux::weighted_tag<STREAMS_BOOST_MPL_AUX_MSVC_VALUE_WKND(order)::value>::type order_tag_;
#else
    typedef char (&order_tag_)[STREAMS_BOOST_MPL_AUX_MSVC_VALUE_WKND(order)::value];
#endif

    STREAMS_BOOST_MPL_AUX_SET_OVERLOAD( order_tag_, ORDER_BY_KEY, s_item, aux::type_wrapper<T>* );
    STREAMS_BOOST_MPL_AUX_SET_OVERLOAD( aux::no_tag, IS_MASKED, s_item, aux::type_wrapper<T>* );
};


template< typename T, typename Base >
struct s_mask
    : Base
{
    typedef s_mask<T,Base> item_;
    typedef T       last_masked_;
    typedef void_   item_type_;
    typedef Base    base;
    typedef typename prior< typename Base::size >::type  size;

    STREAMS_BOOST_MPL_AUX_SET_OVERLOAD( aux::yes_tag, IS_MASKED, s_mask, aux::type_wrapper<T>* );
};


template< typename T, typename Base >
struct s_unmask
    : Base
{
    typedef s_unmask<T,Base> item_;
    typedef void_   last_masked_;
    typedef T       item_type_;
    typedef Base    base;
    typedef typename next< typename Base::size >::type  size;

    STREAMS_BOOST_MPL_AUX_SET_OVERLOAD( aux::no_tag, IS_MASKED, s_unmask, aux::type_wrapper<T>* );
};

}}

#endif // STREAMS_BOOST_MPL_SET_AUX_ITEM_HPP_INCLUDED
