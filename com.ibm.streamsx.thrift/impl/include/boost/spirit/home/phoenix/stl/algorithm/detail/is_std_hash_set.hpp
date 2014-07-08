// Copyright 2005 Daniel Wallin.
// Copyright 2005 Joel de Guzman.
//
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// Modeled after range_ex, Copyright 2004 Eric Niebler
///////////////////////////////////////////////////////////////////////////////
//
// is_std_hash_set.hpp
//
/////////////////////////////////////////////////////////////////////////////

#if defined(_MSC_VER) && _MSC_VER >= 1000
# pragma once
#endif

#ifndef IS_STD_HASH_SET_EN_16_12_2004
#define IS_STD_HASH_SET_EN_16_12_2004

#include <streams_boost/mpl/bool.hpp>
#include "./std_hash_set_fwd.hpp"

namespace streams_boost
{
    template<class T>
    struct is_std_hash_set
        : streams_boost::mpl::false_
    {};

    template<class T>
    struct is_std_hash_multiset
        : streams_boost::mpl::false_
    {};

#if defined(STREAMS_BOOST_HAS_HASH)

    template<
        class Kty
      , class Hash
      , class Cmp
      , class Alloc
    >
    struct is_std_hash_set< ::STREAMS_BOOST_STD_EXTENSION_NAMESPACE::hash_set<Kty,Hash,Cmp,Alloc> >
        : streams_boost::mpl::true_
    {};

    template<
        class Kty
      , class Hash
      , class Cmp
      , class Alloc
    >
    struct is_std_hash_multiset< ::STREAMS_BOOST_STD_EXTENSION_NAMESPACE::hash_multiset<Kty,Hash,Cmp,Alloc> >
        : streams_boost::mpl::true_
    {};

#elif defined(STREAMS_BOOST_DINKUMWARE_STDLIB)

    template<
        class Kty
      , class Tr
      , class Alloc
    >
    struct is_std_hash_set< ::STREAMS_BOOST_STD_EXTENSION_NAMESPACE::hash_set<Kty,Tr,Alloc> >
        : streams_boost::mpl::true_
    {};

    template<
        class Kty
      , class Tr
      , class Alloc
    >
    struct is_std_hash_multiset< ::STREAMS_BOOST_STD_EXTENSION_NAMESPACE::hash_multiset<Kty,Tr,Alloc> >
        : streams_boost::mpl::true_
    {};

#endif

}

#endif
