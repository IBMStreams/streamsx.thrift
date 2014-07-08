/* Copyright 2003-2008 Joaquin M Lopez Munoz.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.streams_boost.org/LICENSE_1_0.txt)
 *
 * See http://www.streams_boost.org/libs/multi_index for library home page.
 */

#ifndef STREAMS_BOOST_MULTI_INDEX_DETAIL_ORD_INDEX_ARGS_HPP
#define STREAMS_BOOST_MULTI_INDEX_DETAIL_ORD_INDEX_ARGS_HPP

#if defined(_MSC_VER)&&(_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/config.hpp> /* keep it first to prevent nasty warns in MSVC */
#include <streams_boost/mpl/aux_/na.hpp>
#include <streams_boost/mpl/eval_if.hpp>
#include <streams_boost/mpl/identity.hpp>
#include <streams_boost/mpl/if.hpp>
#include <streams_boost/multi_index/tag.hpp>
#include <streams_boost/static_assert.hpp>
#include <streams_boost/type_traits/is_same.hpp>
#include <functional>

namespace streams_boost{

namespace multi_index{

namespace detail{

/* Oredered index specifiers can be instantiated in two forms:
 *
 *   (ordered_unique|ordered_non_unique)<
 *     KeyFromValue,Compare=std::less<KeyFromValue::result_type> >
 *   (ordered_unique|ordered_non_unique)<
 *     TagList,KeyFromValue,Compare=std::less<KeyFromValue::result_type> >
 *
 * index_args implements the machinery to accept this argument-dependent
 * polymorphism.
 */

template<typename KeyFromValue>
struct index_args_default_compare
{
  typedef std::less<typename KeyFromValue::result_type> type;
};

template<typename Arg1,typename Arg2,typename Arg3>
struct ordered_index_args
{
  typedef is_tag<Arg1> full_form;

  typedef typename mpl::if_<
    full_form,
    Arg1,
    tag< > >::type                                   tag_list_type;
  typedef typename mpl::if_<
    full_form,
    Arg2,
    Arg1>::type                                      key_from_value_type;
  typedef typename mpl::if_<
    full_form,
    Arg3,
    Arg2>::type                                      supplied_compare_type;
  typedef typename mpl::eval_if<
    mpl::is_na<supplied_compare_type>,
    index_args_default_compare<key_from_value_type>,
    mpl::identity<supplied_compare_type>
  >::type                                            compare_type;

  STREAMS_BOOST_STATIC_ASSERT(is_tag<tag_list_type>::value);
  STREAMS_BOOST_STATIC_ASSERT(!mpl::is_na<key_from_value_type>::value);
  STREAMS_BOOST_STATIC_ASSERT(!mpl::is_na<compare_type>::value);
};

} /* namespace multi_index::detail */

} /* namespace multi_index */

} /* namespace streams_boost */

#endif
