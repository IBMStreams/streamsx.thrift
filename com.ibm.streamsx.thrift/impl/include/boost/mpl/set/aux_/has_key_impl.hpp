
#ifndef STREAMS_BOOST_MPL_SET_AUX_HAS_KEY_IMPL_HPP_INCLUDED
#define STREAMS_BOOST_MPL_SET_AUX_HAS_KEY_IMPL_HPP_INCLUDED

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

#include <streams_boost/mpl/set/aux_/tag.hpp>
#include <streams_boost/mpl/has_key_fwd.hpp>
#include <streams_boost/mpl/bool.hpp>
#include <streams_boost/mpl/aux_/overload_names.hpp>
#include <streams_boost/mpl/aux_/static_cast.hpp>
#include <streams_boost/mpl/aux_/yes_no.hpp>
#include <streams_boost/mpl/aux_/type_wrapper.hpp>
#include <streams_boost/mpl/aux_/config/workaround.hpp>
#include <streams_boost/mpl/aux_/config/static_constant.hpp>

namespace streams_boost { namespace mpl {

template<>
struct has_key_impl< aux::set_tag >
{
    template< typename Set, typename T > struct apply
#if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, STREAMS_BOOST_TESTED_AT(1400)) \
    || STREAMS_BOOST_WORKAROUND(__EDG_VERSION__, <= 245)
    {
        STREAMS_BOOST_STATIC_CONSTANT(bool, value = 
              ( sizeof( STREAMS_BOOST_MPL_AUX_OVERLOAD_CALL_IS_MASKED(
                    Set
                  , STREAMS_BOOST_MPL_AUX_STATIC_CAST(aux::type_wrapper<T>*, 0)
                  ) ) == sizeof(aux::no_tag) )
            );

        typedef bool_<value> type;

#else // ISO98 C++
        : bool_< 
              ( sizeof( STREAMS_BOOST_MPL_AUX_OVERLOAD_CALL_IS_MASKED(
                    Set
                  , STREAMS_BOOST_MPL_AUX_STATIC_CAST(aux::type_wrapper<T>*, 0)
                  ) ) == sizeof(aux::no_tag) )
            >
    {
#endif
    };
};

}}

#endif // STREAMS_BOOST_MPL_SET_AUX_HAS_KEY_IMPL_HPP_INCLUDED
