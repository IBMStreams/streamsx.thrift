/* Copyright 2003-2008 Joaquin M Lopez Munoz.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.streams_boost.org/LICENSE_1_0.txt)
 *
 * See http://www.streams_boost.org/libs/multi_index for library home page.
 */

#ifndef STREAMS_BOOST_MULTI_INDEX_DETAIL_BASE_TYPE_HPP
#define STREAMS_BOOST_MULTI_INDEX_DETAIL_BASE_TYPE_HPP

#if defined(_MSC_VER)&&(_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/config.hpp> /* keep it first to prevent nasty warns in MSVC */
#include <streams_boost/detail/workaround.hpp>
#include <streams_boost/mpl/at.hpp>
#include <streams_boost/mpl/apply.hpp>
#include <streams_boost/mpl/size.hpp>
#include <streams_boost/multi_index/detail/index_base.hpp>
#include <streams_boost/multi_index/detail/is_index_list.hpp>
#include <streams_boost/multi_index/detail/msvc_index_specifier.hpp>
#include <streams_boost/static_assert.hpp>

namespace streams_boost{

namespace multi_index{

namespace detail{

/* MPL machinery to construct a linear hierarchy of indices out of
 * a index list.
 */

#if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC,<1310)
struct index_applier
{
  template<typename IndexSpecifierMeta,typename SuperMeta>
  struct apply:
    msvc_index_specifier<IndexSpecifierMeta::type>::
      template result_index_class<SuperMeta>
  {
  }; 
};
#else
struct index_applier
{
  template<typename IndexSpecifierMeta,typename SuperMeta>
  struct apply
  {
    typedef typename IndexSpecifierMeta::type            index_specifier;
    typedef typename index_specifier::
      STREAMS_BOOST_NESTED_TEMPLATE index_class<SuperMeta>::type type;
  }; 
};
#endif

template<int N,typename Value,typename IndexSpecifierList,typename Allocator>
struct nth_layer
{
  STREAMS_BOOST_STATIC_CONSTANT(int,length=mpl::size<IndexSpecifierList>::value);

  typedef typename  mpl::eval_if_c<
    N==length,
    mpl::identity<index_base<Value,IndexSpecifierList,Allocator> >,
    mpl::apply2<
      index_applier,
      mpl::at_c<IndexSpecifierList,N>,
      nth_layer<N+1,Value,IndexSpecifierList,Allocator>
    >
  >::type type;
};

template<typename Value,typename IndexSpecifierList,typename Allocator>
struct multi_index_base_type:nth_layer<0,Value,IndexSpecifierList,Allocator>
{
  STREAMS_BOOST_STATIC_ASSERT(detail::is_index_list<IndexSpecifierList>::value);
};

} /* namespace multi_index::detail */

} /* namespace multi_index */

} /* namespace streams_boost */

#endif
