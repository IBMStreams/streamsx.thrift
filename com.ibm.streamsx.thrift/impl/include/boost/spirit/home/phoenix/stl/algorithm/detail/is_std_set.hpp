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
// is_std_set.hpp
//
/////////////////////////////////////////////////////////////////////////////

#if defined(_MSC_VER) && _MSC_VER >= 1000
# pragma once
#endif

#ifndef IS_STD_SET_EN_16_12_2004
#define IS_STD_SET_EN_16_12_2004

#include <streams_boost/mpl/bool.hpp>
#include <streams_boost/detail/container_fwd.hpp>

namespace streams_boost
{
    template<class T>
    struct is_std_set
        : streams_boost::mpl::false_
    {};

    template<
        class Kty
      , class Pr
      , class Alloc
    >
    struct is_std_set< ::std::set<Kty,Pr,Alloc> >
        : streams_boost::mpl::true_
    {};

    template<class T>
    struct is_std_multiset
        : streams_boost::mpl::false_
    {};

    template<
        class Kty
      , class Pr
      , class Alloc
    >
    struct is_std_multiset< ::std::multiset<Kty,Pr,Alloc> >
        : streams_boost::mpl::true_
    {};
}

#endif
