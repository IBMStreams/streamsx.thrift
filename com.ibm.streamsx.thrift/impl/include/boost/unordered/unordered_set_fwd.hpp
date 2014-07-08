
// Copyright (C) 2008-2009 Daniel James.
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_UNORDERED_SET_FWD_HPP_INCLUDED
#define STREAMS_BOOST_UNORDERED_SET_FWD_HPP_INCLUDED

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

#include <streams_boost/config.hpp>
#include <memory>
#include <functional>
#include <streams_boost/functional/hash_fwd.hpp>

namespace streams_boost
{
    template <class T,
        class H = hash<T>,
        class P = std::equal_to<T>,
        class A = std::allocator<T> >
    class unordered_set;
    template <class T, class H, class P, class A>
    bool operator==(unordered_set<T, H, P, A> const&,
        unordered_set<T, H, P, A> const&);
    template <class T, class H, class P, class A>
    bool operator!=(unordered_set<T, H, P, A> const&,
        unordered_set<T, H, P, A> const&);
    template <class T, class H, class P, class A>
    void swap(unordered_set<T, H, P, A> &m1,
            unordered_set<T, H, P, A> &m2);

    template <class T,
        class H = hash<T>,
        class P = std::equal_to<T>,
        class A = std::allocator<T> >
    class unordered_multiset;
    template <class T, class H, class P, class A>
    bool operator==(unordered_multiset<T, H, P, A> const&,
        unordered_multiset<T, H, P, A> const&);
    template <class T, class H, class P, class A>
    bool operator!=(unordered_multiset<T, H, P, A> const&,
        unordered_multiset<T, H, P, A> const&);
    template <class T, class H, class P, class A>
    void swap(unordered_multiset<T, H, P, A> &m1,
            unordered_multiset<T, H, P, A> &m2);
}

#endif
