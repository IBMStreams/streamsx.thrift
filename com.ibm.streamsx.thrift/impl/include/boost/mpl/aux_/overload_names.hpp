
#ifndef STREAMS_BOOST_MPL_AUX_OVERLOAD_NAMES_HPP_INCLUDED
#define STREAMS_BOOST_MPL_AUX_OVERLOAD_NAMES_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: overload_names.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/aux_/ptr_to_ref.hpp>
#include <streams_boost/mpl/aux_/config/operators.hpp>

#if defined(STREAMS_BOOST_MPL_CFG_USE_OPERATORS_OVERLOADING)

#   include <streams_boost/mpl/aux_/static_cast.hpp>

#   define STREAMS_BOOST_MPL_AUX_OVERLOAD_VALUE_BY_KEY  operator/
#   define STREAMS_BOOST_MPL_AUX_OVERLOAD_ITEM_BY_ORDER operator|
#   define STREAMS_BOOST_MPL_AUX_OVERLOAD_ORDER_BY_KEY  operator||
#   define STREAMS_BOOST_MPL_AUX_OVERLOAD_IS_MASKED     operator%

#   define STREAMS_BOOST_MPL_AUX_OVERLOAD_CALL_VALUE_BY_KEY(T, x)   STREAMS_BOOST_MPL_AUX_PTR_TO_REF(T) / x
#   define STREAMS_BOOST_MPL_AUX_OVERLOAD_CALL_ITEM_BY_ORDER(T, x)  STREAMS_BOOST_MPL_AUX_PTR_TO_REF(T) | x
#   define STREAMS_BOOST_MPL_AUX_OVERLOAD_CALL_ORDER_BY_KEY(T, x)   STREAMS_BOOST_MPL_AUX_PTR_TO_REF(T) || x
#   define STREAMS_BOOST_MPL_AUX_OVERLOAD_CALL_IS_MASKED(T, x)      STREAMS_BOOST_MPL_AUX_PTR_TO_REF(T) % x

#else

#   define STREAMS_BOOST_MPL_AUX_OVERLOAD_VALUE_BY_KEY  value_by_key_
#   define STREAMS_BOOST_MPL_AUX_OVERLOAD_ITEM_BY_ORDER item_by_order_
#   define STREAMS_BOOST_MPL_AUX_OVERLOAD_ORDER_BY_KEY  order_by_key_
#   define STREAMS_BOOST_MPL_AUX_OVERLOAD_IS_MASKED     is_masked_

#   define STREAMS_BOOST_MPL_AUX_OVERLOAD_CALL_VALUE_BY_KEY(T, x)   T::STREAMS_BOOST_MPL_AUX_OVERLOAD_VALUE_BY_KEY( STREAMS_BOOST_MPL_AUX_PTR_TO_REF(T), x )
#   define STREAMS_BOOST_MPL_AUX_OVERLOAD_CALL_ITEM_BY_ORDER(T, x)  T::STREAMS_BOOST_MPL_AUX_OVERLOAD_ITEM_BY_ORDER( STREAMS_BOOST_MPL_AUX_PTR_TO_REF(T), x )
#   define STREAMS_BOOST_MPL_AUX_OVERLOAD_CALL_ORDER_BY_KEY(T, x)   T::STREAMS_BOOST_MPL_AUX_OVERLOAD_ORDER_BY_KEY( STREAMS_BOOST_MPL_AUX_PTR_TO_REF(T), x )
#   define STREAMS_BOOST_MPL_AUX_OVERLOAD_CALL_IS_MASKED(T, x)      T::STREAMS_BOOST_MPL_AUX_OVERLOAD_IS_MASKED( STREAMS_BOOST_MPL_AUX_PTR_TO_REF(T), x )

#endif

#endif // STREAMS_BOOST_MPL_AUX_OVERLOAD_NAMES_HPP_INCLUDED