
#ifndef STREAMS_BOOST_MPL_AUX_HAS_REBIND_HPP_INCLUDED
#define STREAMS_BOOST_MPL_AUX_HAS_REBIND_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2002-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: has_rebind.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/aux_/config/msvc.hpp>
#include <streams_boost/mpl/aux_/config/intel.hpp>
#include <streams_boost/mpl/aux_/config/workaround.hpp>

#if STREAMS_BOOST_WORKAROUND(__EDG_VERSION__, <= 244) && !defined(STREAMS_BOOST_INTEL_CXX_VERSION)
#   include <streams_boost/mpl/has_xxx.hpp>
#elif STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, < 1300)
#   include <streams_boost/mpl/has_xxx.hpp>
#   include <streams_boost/mpl/if.hpp>
#   include <streams_boost/mpl/bool.hpp>
#   include <streams_boost/mpl/aux_/msvc_is_class.hpp>
#elif STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x610))
#   include <streams_boost/mpl/if.hpp>
#   include <streams_boost/mpl/bool.hpp>
#   include <streams_boost/mpl/aux_/yes_no.hpp>
#   include <streams_boost/mpl/aux_/config/static_constant.hpp>
#   include <streams_boost/type_traits/is_class.hpp>
#else
#   include <streams_boost/mpl/aux_/type_wrapper.hpp>
#   include <streams_boost/mpl/aux_/yes_no.hpp>
#   include <streams_boost/mpl/aux_/config/static_constant.hpp>
#endif

namespace streams_boost { namespace mpl { namespace aux {

#if STREAMS_BOOST_WORKAROUND(__EDG_VERSION__, <= 244) && !defined(STREAMS_BOOST_INTEL_CXX_VERSION)

STREAMS_BOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF(has_rebind, rebind, false)

#elif STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, < 1300)

STREAMS_BOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF(has_rebind_impl, rebind, false)

template< typename T >
struct has_rebind
    : if_< 
          msvc_is_class<T>
        , has_rebind_impl<T>
        , bool_<false>
        >::type
{
};

#else // the rest

template< typename T > struct has_rebind_tag {};
no_tag operator|(has_rebind_tag<int>, void const volatile*);

#   if !STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x610))
template< typename T >
struct has_rebind
{
    static has_rebind_tag<T>* get();
    STREAMS_BOOST_STATIC_CONSTANT(bool, value = 
          sizeof(has_rebind_tag<int>() | get()) == sizeof(yes_tag)
        );
};
#   else // __BORLANDC__
template< typename T >
struct has_rebind_impl
{
    static T* get();
    STREAMS_BOOST_STATIC_CONSTANT(bool, value = 
          sizeof(has_rebind_tag<int>() | get()) == sizeof(yes_tag)
        );
};

template< typename T >
struct has_rebind
    : if_< 
          is_class<T>
        , has_rebind_impl<T>
        , bool_<false>
        >::type
{
};
#   endif // __BORLANDC__

#endif

}}}

#endif // STREAMS_BOOST_MPL_AUX_HAS_REBIND_HPP_INCLUDED
