/* Copyright 2006-2009 Joaquin M Lopez Munoz.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.streams_boost.org/LICENSE_1_0.txt)
 *
 * See http://www.streams_boost.org/libs/flyweight for library home page.
 */

#ifndef STREAMS_BOOST_FLYWEIGHT_SET_FACTORY_HPP
#define STREAMS_BOOST_FLYWEIGHT_SET_FACTORY_HPP

#if defined(_MSC_VER)&&(_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/config.hpp> /* keep it first to prevent nasty warns in MSVC */
#include <streams_boost/detail/allocator_utilities.hpp>
#include <streams_boost/flyweight/assoc_container_factory.hpp>
#include <streams_boost/flyweight/factory_tag.hpp>
#include <streams_boost/flyweight/set_factory_fwd.hpp>
#include <streams_boost/mpl/aux_/lambda_support.hpp>
#include <streams_boost/mpl/if.hpp>
#include <set>

/* Particularization of assoc_container_factory_class using a set.
 */

namespace streams_boost{

namespace flyweights{

template<
  typename Entry,typename Key,
  typename Compare,typename Allocator
>
class set_factory_class:
  public assoc_container_factory_class<
    std::set<
      Entry,
      typename streams_boost::mpl::if_<
        mpl::is_na<Compare>,
        std::less<Key>,
        Compare
      >::type,
      typename streams_boost::mpl::if_<
        mpl::is_na<Allocator>,
        std::allocator<Entry>,
        Allocator
      >::type
    >
  >
{
public:
  typedef set_factory_class type;
  STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(
    4,set_factory_class,(Entry,Key,Compare,Allocator))
};

/* set_factory_class specifier */

template<
  typename Compare,typename Allocator
  STREAMS_BOOST_FLYWEIGHT_NOT_A_PLACEHOLDER_EXPRESSION_DEF
>
struct set_factory:factory_marker
{
  template<typename Entry,typename Key>
  struct apply:
    mpl::apply2<
      set_factory_class<
        streams_boost::mpl::_1,streams_boost::mpl::_2,Compare,Allocator
      >,
      Entry,Key
    >
  {};
};

} /* namespace flyweights */

} /* namespace streams_boost */

#endif
