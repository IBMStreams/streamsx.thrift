
// Copyright (C) 2008-2009 Daniel James.
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_UNORDERED_MAP_FWD_HPP_INCLUDED
#define STREAMS_BOOST_UNORDERED_MAP_FWD_HPP_INCLUDED

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

#include <streams_boost/config.hpp>
#include <memory>
#include <functional>
#include <streams_boost/functional/hash_fwd.hpp>

namespace streams_boost
{
    template <class K,
        class T,
        class H = hash<K>,
        class P = std::equal_to<K>,
        class A = std::allocator<std::pair<const K, T> > >
    class unordered_map;
    template <class K, class T, class H, class P, class A>
    bool operator==(unordered_map<K, T, H, P, A> const&,
        unordered_map<K, T, H, P, A> const&);
    template <class K, class T, class H, class P, class A>
    bool operator!=(unordered_map<K, T, H, P, A> const&,
        unordered_map<K, T, H, P, A> const&);
    template <class K, class T, class H, class P, class A>
    void swap(unordered_map<K, T, H, P, A>&,
            unordered_map<K, T, H, P, A>&);

    template <class K,
        class T,
        class H = hash<K>,
        class P = std::equal_to<K>,
        class A = std::allocator<std::pair<const K, T> > >
    class unordered_multimap;
    template <class K, class T, class H, class P, class A>
    bool operator==(unordered_multimap<K, T, H, P, A> const&,
        unordered_multimap<K, T, H, P, A> const&);
    template <class K, class T, class H, class P, class A>
    bool operator!=(unordered_multimap<K, T, H, P, A> const&,
        unordered_multimap<K, T, H, P, A> const&);
    template <class K, class T, class H, class P, class A>
    void swap(unordered_multimap<K, T, H, P, A>&,
            unordered_multimap<K, T, H, P, A>&);
}

#endif
