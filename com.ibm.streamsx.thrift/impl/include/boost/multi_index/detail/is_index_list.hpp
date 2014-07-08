/* Copyright 2003-2008 Joaquin M Lopez Munoz.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.streams_boost.org/LICENSE_1_0.txt)
 *
 * See http://www.streams_boost.org/libs/multi_index for library home page.
 */

#ifndef STREAMS_BOOST_MULTI_INDEX_DETAIL_IS_INDEX_LIST_HPP
#define STREAMS_BOOST_MULTI_INDEX_DETAIL_IS_INDEX_LIST_HPP

#if defined(_MSC_VER)&&(_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/config.hpp> /* keep it first to prevent nasty warns in MSVC */
#include <streams_boost/mpl/empty.hpp>
#include <streams_boost/mpl/is_sequence.hpp>

namespace streams_boost{

namespace multi_index{

namespace detail{

template<typename T>
struct is_index_list
{
  STREAMS_BOOST_STATIC_CONSTANT(bool,mpl_sequence=mpl::is_sequence<T>::value);
  STREAMS_BOOST_STATIC_CONSTANT(bool,non_empty=!mpl::empty<T>::value);
  STREAMS_BOOST_STATIC_CONSTANT(bool,value=mpl_sequence&&non_empty);
};

} /* namespace multi_index::detail */

} /* namespace multi_index */

} /* namespace streams_boost */

#endif
