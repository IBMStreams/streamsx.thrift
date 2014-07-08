/* Copyright 2003-2008 Joaquin M Lopez Munoz.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.streams_boost.org/LICENSE_1_0.txt)
 *
 * See http://www.streams_boost.org/libs/multi_index for library home page.
 */

#ifndef STREAMS_BOOST_MULTI_INDEX_HASHED_INDEX_FWD_HPP
#define STREAMS_BOOST_MULTI_INDEX_HASHED_INDEX_FWD_HPP

#if defined(_MSC_VER)&&(_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/multi_index/detail/hash_index_args.hpp>

namespace streams_boost{

namespace multi_index{

namespace detail{

template<
  typename KeyFromValue,typename Hash,typename Pred,
  typename SuperMeta,typename TagList,typename Category
>
class hashed_index;

template<
  typename KeyFromValue,typename Hash,typename Pred,
  typename SuperMeta,typename TagList,typename Category
>
void swap(
  hashed_index<KeyFromValue,Hash,Pred,SuperMeta,TagList,Category>& x,
  hashed_index<KeyFromValue,Hash,Pred,SuperMeta,TagList,Category>& y);

} /* namespace multi_index::detail */

/* hashed_index specifiers */

template<
  typename Arg1,typename Arg2=mpl::na,
  typename Arg3=mpl::na,typename Arg4=mpl::na
>
struct hashed_unique;

template<
  typename Arg1,typename Arg2=mpl::na,
  typename Arg3=mpl::na,typename Arg4=mpl::na
>
struct hashed_non_unique;

} /* namespace multi_index */

} /* namespace streams_boost */

#endif
