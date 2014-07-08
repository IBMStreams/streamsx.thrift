/* Copyright 2003-2008 Joaquin M Lopez Munoz.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.streams_boost.org/LICENSE_1_0.txt)
 *
 * See http://www.streams_boost.org/libs/multi_index for library home page.
 */

#ifndef STREAMS_BOOST_MULTI_INDEX_DETAIL_PREVENT_ETI_HPP
#define STREAMS_BOOST_MULTI_INDEX_DETAIL_PREVENT_ETI_HPP

#if defined(_MSC_VER)&&(_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/config.hpp> /* keep it first to prevent nasty warns in MSVC */
#include <streams_boost/detail/workaround.hpp>

#if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC,<1300)
#include <streams_boost/mpl/if.hpp>
#include <streams_boost/mpl/integral_c.hpp>
#include <streams_boost/mpl/aux_/msvc_never_true.hpp>
#endif

namespace streams_boost{

namespace multi_index{

namespace detail{

#if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC,<1300)
/* See
 * http://www.crystalclearsoftware.com/cgi-bin/streams_boost_wiki/wiki.pl?Effective_MPL
 * Item 5.6, Beware of the 'early template instantiation' trap.
 */

template<typename Type,typename Construct>
struct prevent_eti
{
  typedef typename mpl::if_<
    mpl::aux::msvc_never_true<Type>,
    mpl::integral_c<int,0>,
    Construct
  >::type type;
};
#else
template<typename Type,typename Construct>
struct prevent_eti
{
  typedef Construct type;
};
#endif

} /* namespace multi_index::detail */

} /* namespace multi_index */

} /* namespace streams_boost */

#endif
