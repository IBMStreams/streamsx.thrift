
// Copyright 2005-2008 Daniel James.
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#if !defined(STREAMS_BOOST_DETAIL_CONTAINER_FWD_HPP)
#define STREAMS_BOOST_DETAIL_CONTAINER_FWD_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

#include <streams_boost/config.hpp>
#include <streams_boost/detail/workaround.hpp>

#if ((defined(__GLIBCPP__) || defined(__GLIBCXX__)) && defined(_GLIBCXX_DEBUG)) \
    || STREAMS_BOOST_WORKAROUND(__BORLANDC__, > 0x551) \
    || STREAMS_BOOST_WORKAROUND(__DMC__, STREAMS_BOOST_TESTED_AT(0x842)) \
    || (defined(__SGI_STL_PORT) || defined(_STLPORT_VERSION))

#include <deque>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <complex>

#else

#include <cstddef>

#if !defined(__SGI_STL_PORT) && !defined(_STLPORT_VERSION) && \
        defined(__STL_CONFIG_H)

#define STREAMS_BOOST_CONTAINER_FWD_BAD_BITSET

#if !defined(__STL_NON_TYPE_TMPL_PARAM_BUG)
#define STREAMS_BOOST_CONTAINER_FWD_BAD_DEQUE
#endif

#endif

#if defined(STREAMS_BOOST_CONTAINER_FWD_BAD_DEQUE)
#include <deque>
#endif

#if defined(STREAMS_BOOST_CONTAINER_FWD_BAD_BITSET)
#include <bitset>
#endif

#if defined(STREAMS_BOOST_MSVC)
#pragma warning(push)
#pragma warning(disable:4099) // struct/class mismatch in fwd declarations
#endif

namespace std
{
    template <class T> class allocator;
    template <class charT, class traits, class Allocator> class basic_string;

#if STREAMS_BOOST_WORKAROUND(__GNUC__, < 3) && !defined(__SGI_STL_PORT) && !defined(_STLPORT_VERSION)
    template <class charT> struct string_char_traits;
#else
    template <class charT> struct char_traits;
#endif

    template <class T> class complex;
}

// gcc 3.4 and greater
namespace std
{
#if !defined(STREAMS_BOOST_CONTAINER_FWD_BAD_DEQUE)
    template <class T, class Allocator> class deque;
#endif

    template <class T, class Allocator> class list;
    template <class T, class Allocator> class vector;
    template <class Key, class T, class Compare, class Allocator> class map;
    template <class Key, class T, class Compare, class Allocator>
    class multimap;
    template <class Key, class Compare, class Allocator> class set;
    template <class Key, class Compare, class Allocator> class multiset;

#if !defined(STREAMS_BOOST_CONTAINER_FWD_BAD_BITSET)
    template <size_t N> class bitset;
#endif
    template <class T1, class T2> struct pair;
}

#if defined(STREAMS_BOOST_MSVC)
#pragma warning(pop)
#endif

#endif

#endif
