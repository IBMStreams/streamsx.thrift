/* Copyright 2006-2008 Joaquin M Lopez Munoz.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.streams_boost.org/LICENSE_1_0.txt)
 *
 * See http://www.streams_boost.org/libs/flyweight for library home page.
 */

#ifndef STREAMS_BOOST_FLYWEIGHT_FLYWEIGHT_FWD_HPP
#define STREAMS_BOOST_FLYWEIGHT_FLYWEIGHT_FWD_HPP

#if defined(_MSC_VER)&&(_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/config.hpp> /* keep it first to prevent nasty warns in MSVC */
#include <streams_boost/detail/templated_streams.hpp>
#include <streams_boost/parameter/parameters.hpp>
#include <streams_boost/preprocessor/punctuation/comma.hpp>
#include <iosfwd>

namespace streams_boost{
  
namespace flyweights{

template<
  typename T,
  typename Arg1=parameter::void_,
  typename Arg2=parameter::void_,
  typename Arg3=parameter::void_,
  typename Arg4=parameter::void_,
  typename Arg5=parameter::void_
>
class flyweight;

#define STREAMS_BOOST_FLYWEIGHT_TYPENAME_TEMPL_ARGS(n)            \
typename Arg##n##1,typename Arg##n##2,typename Arg##n##3, \
typename Arg##n##4,typename Arg##n##5
#define STREAMS_BOOST_FLYWEIGHT_TEMPL_ARGS(n) \
Arg##n##1,Arg##n##2,Arg##n##3,Arg##n##4,Arg##n##5

template<
  typename T1,STREAMS_BOOST_FLYWEIGHT_TYPENAME_TEMPL_ARGS(1),
  typename T2,STREAMS_BOOST_FLYWEIGHT_TYPENAME_TEMPL_ARGS(2)
>
bool operator==(
  const flyweight<T1,STREAMS_BOOST_FLYWEIGHT_TEMPL_ARGS(1)>& x,
  const flyweight<T2,STREAMS_BOOST_FLYWEIGHT_TEMPL_ARGS(2)>& y);

template<
  typename T1,STREAMS_BOOST_FLYWEIGHT_TYPENAME_TEMPL_ARGS(1),
  typename T2,STREAMS_BOOST_FLYWEIGHT_TYPENAME_TEMPL_ARGS(2)
>
bool operator<(
  const flyweight<T1,STREAMS_BOOST_FLYWEIGHT_TEMPL_ARGS(1)>& x,
  const flyweight<T2,STREAMS_BOOST_FLYWEIGHT_TEMPL_ARGS(2)>& y);

#if !defined(STREAMS_BOOST_NO_FUNCTION_TEMPLATE_ORDERING)
template<
  typename T1,STREAMS_BOOST_FLYWEIGHT_TYPENAME_TEMPL_ARGS(1),
  typename T2
>
bool operator==(
  const flyweight<T1,STREAMS_BOOST_FLYWEIGHT_TEMPL_ARGS(1)>& x,const T2& y);

template<
  typename T1,
  typename T2,STREAMS_BOOST_FLYWEIGHT_TYPENAME_TEMPL_ARGS(2)
>
bool operator==(
  const T1& x,const flyweight<T2,STREAMS_BOOST_FLYWEIGHT_TEMPL_ARGS(2)>& y);

template<
  typename T1,STREAMS_BOOST_FLYWEIGHT_TYPENAME_TEMPL_ARGS(1),
  typename T2
>
bool operator<(
  const flyweight<T1,STREAMS_BOOST_FLYWEIGHT_TEMPL_ARGS(1)>& x,const T2& y);

template<
  typename T1,
  typename T2,STREAMS_BOOST_FLYWEIGHT_TYPENAME_TEMPL_ARGS(2)
>
bool operator<(
  const T1& x,const flyweight<T2,STREAMS_BOOST_FLYWEIGHT_TEMPL_ARGS(2)>& y);
#endif /* !defined(STREAMS_BOOST_NO_FUNCTION_TEMPLATE_ORDERING) */

#define STREAMS_BOOST_FLYWEIGHT_COMPLETE_COMP_OPS_DECL(t,a1,a2)                       \
template<t>                                                                   \
inline bool operator!=(const a1& x,const a2& y);                              \
                                                                              \
template<t>                                                                   \
inline bool operator>(const a1& x,const a2& y);                               \
                                                                              \
template<t>                                                                   \
inline bool operator>=(const a1& x,const a2& y);                              \
                                                                              \
template<t>                                                                   \
inline bool operator<=(const a1& x,const a2& y);                              \

STREAMS_BOOST_FLYWEIGHT_COMPLETE_COMP_OPS_DECL(
  typename T1 STREAMS_BOOST_PP_COMMA()
  STREAMS_BOOST_FLYWEIGHT_TYPENAME_TEMPL_ARGS(1) STREAMS_BOOST_PP_COMMA()
  typename T2 STREAMS_BOOST_PP_COMMA()
  STREAMS_BOOST_FLYWEIGHT_TYPENAME_TEMPL_ARGS(2),
  flyweight<
    T1 STREAMS_BOOST_PP_COMMA() STREAMS_BOOST_FLYWEIGHT_TEMPL_ARGS(1)
  >,
  flyweight<
    T2 STREAMS_BOOST_PP_COMMA() STREAMS_BOOST_FLYWEIGHT_TEMPL_ARGS(2)
  >)

#if !defined(STREAMS_BOOST_NO_FUNCTION_TEMPLATE_ORDERING)
STREAMS_BOOST_FLYWEIGHT_COMPLETE_COMP_OPS_DECL(
  typename T1 STREAMS_BOOST_PP_COMMA()
  STREAMS_BOOST_FLYWEIGHT_TYPENAME_TEMPL_ARGS(1) STREAMS_BOOST_PP_COMMA()
  typename T2,
  flyweight<
    T1 STREAMS_BOOST_PP_COMMA() STREAMS_BOOST_FLYWEIGHT_TEMPL_ARGS(1)
  >,
  T2)

STREAMS_BOOST_FLYWEIGHT_COMPLETE_COMP_OPS_DECL(
  typename T1 STREAMS_BOOST_PP_COMMA()
  typename T2 STREAMS_BOOST_PP_COMMA()
  STREAMS_BOOST_FLYWEIGHT_TYPENAME_TEMPL_ARGS(2),
  T1,
  flyweight<
    T2 STREAMS_BOOST_PP_COMMA() STREAMS_BOOST_FLYWEIGHT_TEMPL_ARGS(2)
  >)
#endif /* !defined(STREAMS_BOOST_NO_FUNCTION_TEMPLATE_ORDERING) */
  
template<typename T,STREAMS_BOOST_FLYWEIGHT_TYPENAME_TEMPL_ARGS(_)>
inline void swap(
  flyweight<T,STREAMS_BOOST_FLYWEIGHT_TEMPL_ARGS(_)>& x,
  flyweight<T,STREAMS_BOOST_FLYWEIGHT_TEMPL_ARGS(_)>& y);

template<
  STREAMS_BOOST_TEMPLATED_STREAM_ARGS(ElemType,Traits)
  STREAMS_BOOST_TEMPLATED_STREAM_COMMA
  typename T,STREAMS_BOOST_FLYWEIGHT_TYPENAME_TEMPL_ARGS(_)
>
inline STREAMS_BOOST_TEMPLATED_STREAM(ostream,ElemType,Traits)& operator<<(
  STREAMS_BOOST_TEMPLATED_STREAM(ostream,ElemType,Traits)& out,
  const flyweight<T,STREAMS_BOOST_FLYWEIGHT_TEMPL_ARGS(_)>& x);

template<
  STREAMS_BOOST_TEMPLATED_STREAM_ARGS(ElemType,Traits)
  STREAMS_BOOST_TEMPLATED_STREAM_COMMA
  typename T,STREAMS_BOOST_FLYWEIGHT_TYPENAME_TEMPL_ARGS(_)
>
inline STREAMS_BOOST_TEMPLATED_STREAM(istream,ElemType,Traits)& operator>>(
  STREAMS_BOOST_TEMPLATED_STREAM(istream,ElemType,Traits)& in,
  flyweight<T,STREAMS_BOOST_FLYWEIGHT_TEMPL_ARGS(_)>& x);

} /* namespace flyweights */

using flyweights::flyweight;

} /* namespace streams_boost */

#undef STREAMS_BOOST_FLYWEIGHT_COMPLETE_COMP_OPS_DECL
#undef STREAMS_BOOST_FLYWEIGHT_TEMPL_ARGS
#undef STREAMS_BOOST_FLYWEIGHT_TYPENAME_TEMPL_ARGS

#endif
