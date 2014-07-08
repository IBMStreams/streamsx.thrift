/* Copyright 2003-2008 Joaquin M Lopez Munoz.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.streams_boost.org/LICENSE_1_0.txt)
 *
 * See http://www.streams_boost.org/libs/multi_index for library home page.
 */

#ifndef STREAMS_BOOST_MULTI_INDEX_TAG_HPP
#define STREAMS_BOOST_MULTI_INDEX_TAG_HPP

#if defined(_MSC_VER)&&(_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/config.hpp> /* keep it first to prevent nasty warns in MSVC */
#include <streams_boost/multi_index/detail/no_duplicate_tags.hpp>
#include <streams_boost/mpl/identity.hpp>
#include <streams_boost/mpl/transform.hpp>
#include <streams_boost/mpl/vector.hpp>
#include <streams_boost/preprocessor/facilities/intercept.hpp> 
#include <streams_boost/preprocessor/repetition/enum_binary_params.hpp> 
#include <streams_boost/preprocessor/repetition/enum_params.hpp> 
#include <streams_boost/static_assert.hpp>
#include <streams_boost/type_traits/is_base_and_derived.hpp>

/* A wrapper of mpl::vector used to hide MPL from the user.
 * tag contains types used as tag names for indices in get() functions.
 */

/* This user_definable macro limits the number of elements of a tag;
 * useful for shortening resulting symbol names (MSVC++ 6.0, for instance,
 * has problems coping with very long symbol names.)
 */

#if !defined(STREAMS_BOOST_MULTI_INDEX_LIMIT_TAG_SIZE)
#if defined(STREAMS_BOOST_MSVC)&&(STREAMS_BOOST_MSVC<1300)
#define STREAMS_BOOST_MULTI_INDEX_LIMIT_TAG_SIZE 3
#else
#define STREAMS_BOOST_MULTI_INDEX_LIMIT_TAG_SIZE STREAMS_BOOST_MPL_LIMIT_VECTOR_SIZE
#endif
#endif

#if STREAMS_BOOST_MULTI_INDEX_LIMIT_TAG_SIZE<STREAMS_BOOST_MPL_LIMIT_VECTOR_SIZE
#define STREAMS_BOOST_MULTI_INDEX_TAG_SIZE STREAMS_BOOST_MULTI_INDEX_LIMIT_TAG_SIZE
#else
#define STREAMS_BOOST_MULTI_INDEX_TAG_SIZE STREAMS_BOOST_MPL_LIMIT_VECTOR_SIZE
#endif

namespace streams_boost{

namespace multi_index{

namespace detail{

struct tag_marker{};

template<typename T>
struct is_tag
{
  STREAMS_BOOST_STATIC_CONSTANT(bool,value=(is_base_and_derived<tag_marker,T>::value));
};

} /* namespace multi_index::detail */

template<
  STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(
    STREAMS_BOOST_MULTI_INDEX_TAG_SIZE,
    typename T,
    =mpl::na STREAMS_BOOST_PP_INTERCEPT) 
>
struct tag:private detail::tag_marker
{
  /* The mpl::transform pass produces shorter symbols (without
   * trailing mpl::na's.)
   */

  typedef typename mpl::transform<
    mpl::vector<STREAMS_BOOST_PP_ENUM_PARAMS(STREAMS_BOOST_MULTI_INDEX_TAG_SIZE,T)>,
    mpl::identity<mpl::_1>
  >::type type;

  STREAMS_BOOST_STATIC_ASSERT(detail::no_duplicate_tags<type>::value);
};

} /* namespace multi_index */

} /* namespace streams_boost */

#undef STREAMS_BOOST_MULTI_INDEX_TAG_SIZE

#endif
