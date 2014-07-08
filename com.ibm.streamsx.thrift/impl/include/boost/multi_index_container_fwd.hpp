/* Copyright 2003-2008 Joaquin M Lopez Munoz.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.streams_boost.org/LICENSE_1_0.txt)
 *
 * See http://www.streams_boost.org/libs/multi_index for library home page.
 */

#ifndef STREAMS_BOOST_MULTI_INDEX_FWD_HPP
#define STREAMS_BOOST_MULTI_INDEX_FWD_HPP

#if defined(_MSC_VER)&&(_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/config.hpp> /* keep it first to prevent nasty warns in MSVC */
#include <streams_boost/multi_index/identity.hpp>
#include <streams_boost/multi_index/indexed_by.hpp>
#include <streams_boost/multi_index/ordered_index_fwd.hpp>
#include <memory>

namespace streams_boost{

namespace multi_index{

/* Default value for IndexSpecifierList specifies a container
 * equivalent to std::set<Value>.
 */

template<
  typename Value,
  typename IndexSpecifierList=indexed_by<ordered_unique<identity<Value> > >,
  typename Allocator=std::allocator<Value> >
class multi_index_container;

template<typename MultiIndexContainer,int N>
struct nth_index;

template<typename MultiIndexContainer,typename Tag>
struct index;

template<typename MultiIndexContainer,int N>
struct nth_index_iterator;

template<typename MultiIndexContainer,int N>
struct nth_index_const_iterator;

template<typename MultiIndexContainer,typename Tag>
struct index_iterator;

template<typename MultiIndexContainer,typename Tag>
struct index_const_iterator;

/* get and project functions not fwd declared due to problems
 * with dependent typenames
 */

template<
  typename Value1,typename IndexSpecifierList1,typename Allocator1,
  typename Value2,typename IndexSpecifierList2,typename Allocator2
>
bool operator==(
  const multi_index_container<Value1,IndexSpecifierList1,Allocator1>& x,
  const multi_index_container<Value2,IndexSpecifierList2,Allocator2>& y);

template<
  typename Value1,typename IndexSpecifierList1,typename Allocator1,
  typename Value2,typename IndexSpecifierList2,typename Allocator2
>
bool operator<(
  const multi_index_container<Value1,IndexSpecifierList1,Allocator1>& x,
  const multi_index_container<Value2,IndexSpecifierList2,Allocator2>& y);

template<
  typename Value1,typename IndexSpecifierList1,typename Allocator1,
  typename Value2,typename IndexSpecifierList2,typename Allocator2
>
bool operator!=(
  const multi_index_container<Value1,IndexSpecifierList1,Allocator1>& x,
  const multi_index_container<Value2,IndexSpecifierList2,Allocator2>& y);

template<
  typename Value1,typename IndexSpecifierList1,typename Allocator1,
  typename Value2,typename IndexSpecifierList2,typename Allocator2
>
bool operator>(
  const multi_index_container<Value1,IndexSpecifierList1,Allocator1>& x,
  const multi_index_container<Value2,IndexSpecifierList2,Allocator2>& y);

template<
  typename Value1,typename IndexSpecifierList1,typename Allocator1,
  typename Value2,typename IndexSpecifierList2,typename Allocator2
>
bool operator>=(
  const multi_index_container<Value1,IndexSpecifierList1,Allocator1>& x,
  const multi_index_container<Value2,IndexSpecifierList2,Allocator2>& y);

template<
  typename Value1,typename IndexSpecifierList1,typename Allocator1,
  typename Value2,typename IndexSpecifierList2,typename Allocator2
>
bool operator<=(
  const multi_index_container<Value1,IndexSpecifierList1,Allocator1>& x,
  const multi_index_container<Value2,IndexSpecifierList2,Allocator2>& y);

template<typename Value,typename IndexSpecifierList,typename Allocator>
void swap(
  multi_index_container<Value,IndexSpecifierList,Allocator>& x,
  multi_index_container<Value,IndexSpecifierList,Allocator>& y);

} /* namespace multi_index */

/* multi_index_container, being the main type of this library, is promoted to
 * namespace streams_boost.
 */

using multi_index::multi_index_container;

} /* namespace streams_boost */

#endif
