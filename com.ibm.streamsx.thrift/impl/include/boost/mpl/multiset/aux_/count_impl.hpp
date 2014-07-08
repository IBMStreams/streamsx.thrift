
#ifndef STREAMS_BOOST_MPL_MULTISET_AUX_COUNT_IMPL_HPP_INCLUDED
#define STREAMS_BOOST_MPL_MULTISET_AUX_COUNT_IMPL_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2003-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: count_impl.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/multiset/aux_/tag.hpp>
#include <streams_boost/mpl/count_fwd.hpp>
#include <streams_boost/mpl/int.hpp>
#include <streams_boost/mpl/aux_/type_wrapper.hpp>
#include <streams_boost/mpl/aux_/static_cast.hpp>
#include <streams_boost/mpl/aux_/config/static_constant.hpp>
#include <streams_boost/mpl/aux_/config/workaround.hpp>
#include <streams_boost/mpl/aux_/config/msvc.hpp>

#if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, <= 1300)
#   include <streams_boost/mpl/if.hpp>
#   include <streams_boost/type_traits/is_reference.hpp>
#endif

namespace streams_boost { namespace mpl {

#if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, <= 1300)

namespace aux {
template< typename S, typename U >
struct multiset_count_impl
    : int_< sizeof(S::key_count(STREAMS_BOOST_MPL_AUX_STATIC_CAST(U*,0))) - 1 >
{
};

template< typename S, typename U >
struct multiset_count_ref_impl
{
    typedef U (* u_)();
    typedef int_< sizeof(S::ref_key_count(STREAMS_BOOST_MPL_AUX_STATIC_CAST(u_,0))) - 1 > type_;
    STREAMS_BOOST_STATIC_CONSTANT(int, value = type_::value);
    typedef type_ type;
};
}

template<>
struct count_impl< aux::multiset_tag >
{
    template< typename Set, typename Key > struct apply
        : if_< 
              is_reference<Key>
            , aux::multiset_count_ref_impl<Set,Key>
            , aux::multiset_count_impl<Set,Key>
            >::type
    {
    };
};

#else

template<>
struct count_impl< aux::multiset_tag >
{
    template< typename Set, typename Key > struct apply
    {
        enum { msvc71_wknd_ = sizeof(Set::key_count(STREAMS_BOOST_MPL_AUX_STATIC_CAST(aux::type_wrapper<Key>*,0))) - 1 };
        typedef int_< msvc71_wknd_ > type;
        STREAMS_BOOST_STATIC_CONSTANT(int, value = msvc71_wknd_);
    };
};

#endif // STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, <= 1300)

}}

#endif // STREAMS_BOOST_MPL_MULTISET_AUX_COUNT_IMPL_HPP_INCLUDED
