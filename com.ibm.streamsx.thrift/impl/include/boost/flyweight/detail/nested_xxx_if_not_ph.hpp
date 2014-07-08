/* Copyright 2006-2009 Joaquin M Lopez Munoz.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.streams_boost.org/LICENSE_1_0.txt)
 *
 * See http://www.streams_boost.org/libs/flyweight for library home page.
 */

#ifndef STREAMS_BOOST_FLYWEIGHT_DETAIL_NESTED_XXX_IF_NOT_PH_HPP
#define STREAMS_BOOST_FLYWEIGHT_DETAIL_NESTED_XXX_IF_NOT_PH_HPP

#if defined(_MSC_VER)&&(_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/flyweight/detail/is_placeholder_expr.hpp>
#include <streams_boost/mpl/if.hpp>

/* nested_##name##_if_not_placeholder_expression<T>::type is T::name unless
 * T is an MPL placeholder expression, in which case it defaults to int.
 */

#define STREAMS_BOOST_FLYWEIGHT_NESTED_XXX_IF_NOT_PLACEHOLDER_EXPRESSION_DEF(name) \
struct nested_##name##_if_not_placeholder_expression_helper                \
{                                                                          \
  typedef int name;                                                        \
};                                                                         \
                                                                           \
template<typename T>                                                       \
struct nested_##name##_if_not_placeholder_expression                       \
{                                                                          \
  typedef typename streams_boost::mpl::if_<                                        \
    streams_boost::flyweights::detail::is_placeholder_expression<T>,               \
    nested_##name##_if_not_placeholder_expression_helper,                  \
    T                                                                      \
  >::type::name type;                                                      \
};

#endif
