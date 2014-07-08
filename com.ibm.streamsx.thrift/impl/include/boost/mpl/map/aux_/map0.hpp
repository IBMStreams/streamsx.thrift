
#ifndef STREAMS_BOOST_MPL_MAP_AUX_MAP0_HPP_INCLUDED
#define STREAMS_BOOST_MPL_MAP_AUX_MAP0_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2003-2004
// Copyright David Abrahams 2003-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: map0.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/long.hpp>
#include <streams_boost/mpl/void.hpp>
#include <streams_boost/mpl/map/aux_/tag.hpp>
#include <streams_boost/mpl/aux_/na.hpp>
#include <streams_boost/mpl/aux_/yes_no.hpp>
#include <streams_boost/mpl/aux_/overload_names.hpp>
#include <streams_boost/mpl/aux_/config/operators.hpp>

#include <streams_boost/preprocessor/cat.hpp>

namespace streams_boost { namespace mpl {

#if defined(STREAMS_BOOST_MPL_CFG_USE_OPERATORS_OVERLOADING)

#   define STREAMS_BOOST_MPL_AUX_MAP0_OVERLOAD(R, f, X, T) \
    friend R STREAMS_BOOST_PP_CAT(STREAMS_BOOST_MPL_AUX_OVERLOAD_,f)(X const&, T) \
/**/

#   define STREAMS_BOOST_MPL_AUX_MAP_OVERLOAD(R, f, X, T) \
    STREAMS_BOOST_MPL_AUX_MAP0_OVERLOAD(R, f, X, T) \
/**/

#else

#   define STREAMS_BOOST_MPL_AUX_MAP0_OVERLOAD(R, f, X, T) \
    static R STREAMS_BOOST_PP_CAT(STREAMS_BOOST_MPL_AUX_OVERLOAD_,f)(X const&, T) \
/**/

#   define STREAMS_BOOST_MPL_AUX_MAP_OVERLOAD(R, f, X, T) \
    STREAMS_BOOST_MPL_AUX_MAP0_OVERLOAD(R, f, X, T); \
    using Base::STREAMS_BOOST_PP_CAT(STREAMS_BOOST_MPL_AUX_OVERLOAD_,f) \
/**/

#endif


template< typename Dummy = na > struct map0
{
    typedef map0            type;
    typedef aux::map_tag    tag;
    typedef void_           key_;
    typedef long_<1>        order;
    typedef long_<0>        size;

#if defined(STREAMS_BOOST_MPL_CFG_TYPEOF_BASED_SEQUENCES)
    STREAMS_BOOST_MPL_AUX_MAP0_OVERLOAD( aux::type_wrapper<void_>, VALUE_BY_KEY, map0<>, void const volatile* );
    STREAMS_BOOST_MPL_AUX_MAP0_OVERLOAD( aux::type_wrapper<void_>, ITEM_BY_ORDER, map0<>, long_<1>* );
    STREAMS_BOOST_MPL_AUX_MAP0_OVERLOAD( aux::no_tag, ORDER_BY_KEY, map0<>, void const volatile* );
#else
    STREAMS_BOOST_MPL_AUX_MAP0_OVERLOAD( aux::no_tag, ORDER_BY_KEY, map0<>, void const volatile* );
    STREAMS_BOOST_MPL_AUX_MAP0_OVERLOAD( aux::no_tag, IS_MASKED, map0<>, void const volatile* );
#endif
};

}}

#endif // STREAMS_BOOST_MPL_MAP_AUX_MAP0_HPP_INCLUDED
