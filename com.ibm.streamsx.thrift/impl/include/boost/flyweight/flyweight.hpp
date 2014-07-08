/* Flyweight class. 
 *
 * Copyright 2006-2009 Joaquin M Lopez Munoz.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.streams_boost.org/LICENSE_1_0.txt)
 *
 * See http://www.streams_boost.org/libs/flyweight for library home page.
 */

#ifndef STREAMS_BOOST_FLYWEIGHT_FLYWEIGHT_HPP
#define STREAMS_BOOST_FLYWEIGHT_FLYWEIGHT_HPP

#if defined(_MSC_VER)&&(_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/config.hpp> /* keep it first to prevent nasty warns in MSVC */
#include <algorithm>
#include <streams_boost/detail/workaround.hpp>
#include <streams_boost/flyweight/detail/default_value_policy.hpp>
#include <streams_boost/flyweight/detail/flyweight_core.hpp>
#include <streams_boost/flyweight/factory_tag.hpp>
#include <streams_boost/flyweight/flyweight_fwd.hpp>
#include <streams_boost/flyweight/locking_tag.hpp>
#include <streams_boost/flyweight/simple_locking_fwd.hpp>
#include <streams_boost/flyweight/static_holder_fwd.hpp>
#include <streams_boost/flyweight/hashed_factory_fwd.hpp>
#include <streams_boost/flyweight/holder_tag.hpp>
#include <streams_boost/flyweight/refcounted_fwd.hpp>
#include <streams_boost/flyweight/tag.hpp>
#include <streams_boost/flyweight/tracking_tag.hpp>
#include <streams_boost/mpl/assert.hpp>
#include <streams_boost/mpl/if.hpp>
#include <streams_boost/mpl/not.hpp>
#include <streams_boost/mpl/or.hpp>
#include <streams_boost/parameter/binding.hpp>
#include <streams_boost/preprocessor/repetition/enum_params.hpp>
#include <streams_boost/type_traits/is_same.hpp>
#include <streams_boost/utility/swap.hpp>

#if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC,STREAMS_BOOST_TESTED_AT(1400))
#pragma warning(push)
#pragma warning(disable:4521)  /* multiple copy ctors */
#endif

namespace streams_boost{
  
namespace flyweights{

namespace detail{

/* Used for the detection of unmatched template args in a
 * flyweight instantiation.
 */

struct unmatched_arg;

/* Boost.Parameter structures for use in flyweight.
 * NB: these types are derived from instead of typedef'd to force their
 * instantiation, which solves http://bugs.sun.com/view_bug.do?bug_id=6782987
 * as found out by Simon Atanasyan.
 */

struct flyweight_signature:
  parameter::parameters<
    parameter::optional<
      parameter::deduced<tag<> >,
      detail::is_tag<streams_boost::mpl::_>
    >,
    parameter::optional<
      parameter::deduced<tracking<> >,
      is_tracking<streams_boost::mpl::_>
    >,
    parameter::optional<
      parameter::deduced<factory<> >,
      is_factory<streams_boost::mpl::_>
    >,
    parameter::optional<
      parameter::deduced<locking<> >,
      is_locking<streams_boost::mpl::_>
    >,
    parameter::optional<
      parameter::deduced<holder<> >,
      is_holder<streams_boost::mpl::_>
    >
  >
{};

struct flyweight_unmatched_signature:
  parameter::parameters<
    parameter::optional<
      parameter::deduced<
        detail::unmatched_arg
      >,
      mpl::not_<
        mpl::or_<
          detail::is_tag<streams_boost::mpl::_>,
          is_tracking<streams_boost::mpl::_>,
          is_factory<streams_boost::mpl::_>,
          is_locking<streams_boost::mpl::_>,
          is_holder<streams_boost::mpl::_>
        >
      >
    >
  >
{};

} /* namespace flyweights::detail */

template<
  typename T,
  typename Arg1,typename Arg2,typename Arg3,typename Arg4,typename Arg5
>
class flyweight
{
private:
  typedef typename mpl::if_<
    detail::is_value<T>,
    T,
    detail::default_value_policy<T>
  >::type                                 value_policy;
  typedef typename detail::
  flyweight_signature::bind<
    Arg1,Arg2,Arg3,Arg4,Arg5
  >::type                                 args;
  typedef typename parameter::binding<
    args,tag<>,mpl::na
  >::type                                 tag_type;
  typedef typename parameter::binding<
    args,tracking<>,refcounted
  >::type                                 tracking_policy;
  typedef typename parameter::binding<
    args,factory<>,hashed_factory<>
  >::type                                 factory_specifier;
  typedef typename parameter::binding<
    args,locking<>,simple_locking
  >::type                                 locking_policy;
  typedef typename parameter::binding<
    args,holder<>,static_holder
  >::type                                 holder_specifier;

  typedef typename detail::
  flyweight_unmatched_signature::bind<
    Arg1,Arg2,Arg3,Arg4,Arg5
  >::type                                 unmatched_args;
  typedef typename parameter::binding<
    unmatched_args,detail::unmatched_arg,
    detail::unmatched_arg
  >::type                                 unmatched_arg_detected;

  /* You have passed a type in the specification of a flyweight type that
   * could not be interpreted as a valid argument.
   */
  STREAMS_BOOST_MPL_ASSERT_MSG(
  (is_same<unmatched_arg_detected,detail::unmatched_arg>::value),
  INVALID_ARGUMENT_TO_FLYWEIGHT,
  (flyweight));

  typedef detail::flyweight_core<
    value_policy,tag_type,tracking_policy,
    factory_specifier,locking_policy,
    holder_specifier
  >                                            core;
  typedef typename core::handle_type           handle_type;

public:
  typedef typename value_policy::key_type      key_type;
  typedef typename value_policy::value_type    value_type;

  /* static data initialization */

  static bool init(){return core::init();}

  class initializer
  {
  public:
    initializer():b(init()){}
  private:
    bool b;
  };

  /* construct/copy/destroy */
  
  flyweight():h(core::insert(key_type())){}
  flyweight(const flyweight& x):h(x.h){}
  flyweight(flyweight& x):h(x.h){}

  /* template ctors */

#define STREAMS_BOOST_FLYWEIGHT_PERFECT_FWD_NAME explicit flyweight
#define STREAMS_BOOST_FLYWEIGHT_PERFECT_FWD_BODY(n)    \
  :h(core::insert(STREAMS_BOOST_PP_ENUM_PARAMS(n,t))){}
#include <streams_boost/flyweight/detail/perfect_fwd.hpp>

  flyweight& operator=(const flyweight& x){h=x.h;return *this;}
  flyweight& operator=(const value_type& x){return operator=(flyweight(x));}

  /* convertibility to underlying type */
  
  const key_type&   get_key()const{return core::key(h);}
  const value_type& get()const{return core::value(h);}
  operator const    value_type&()const{return get();}
  
  /* exact type equality  */
    
  friend bool operator==(const flyweight& x,const flyweight& y)
  {
    return &x.get()==&y.get();
  }

  /* modifiers */

  void swap(flyweight& x){streams_boost::swap(h,x.h);}
  
private:
  handle_type h;
};

#define STREAMS_BOOST_FLYWEIGHT_TYPENAME_TEMPL_ARGS(n)            \
typename Arg##n##1,typename Arg##n##2,typename Arg##n##3, \
typename Arg##n##4,typename Arg##n##5
#define STREAMS_BOOST_FLYWEIGHT_TEMPL_ARGS(n) \
Arg##n##1,Arg##n##2,Arg##n##3,Arg##n##4,Arg##n##5

/* Comparison. Unlike exact type comparison defined above, intertype
 * comparison just forwards to the underlying objects.
 */

template<
  typename T1,STREAMS_BOOST_FLYWEIGHT_TYPENAME_TEMPL_ARGS(1),
  typename T2,STREAMS_BOOST_FLYWEIGHT_TYPENAME_TEMPL_ARGS(2)
>
bool operator==(
  const flyweight<T1,STREAMS_BOOST_FLYWEIGHT_TEMPL_ARGS(1)>& x,
  const flyweight<T2,STREAMS_BOOST_FLYWEIGHT_TEMPL_ARGS(2)>& y)
{
  return x.get()==y.get();
}

template<
  typename T1,STREAMS_BOOST_FLYWEIGHT_TYPENAME_TEMPL_ARGS(1),
  typename T2,STREAMS_BOOST_FLYWEIGHT_TYPENAME_TEMPL_ARGS(2)
>
bool operator<(
  const flyweight<T1,STREAMS_BOOST_FLYWEIGHT_TEMPL_ARGS(1)>& x,
  const flyweight<T2,STREAMS_BOOST_FLYWEIGHT_TEMPL_ARGS(2)>& y)
{
  return x.get()<y.get();
}

#if !defined(STREAMS_BOOST_NO_FUNCTION_TEMPLATE_ORDERING)
template<
  typename T1,STREAMS_BOOST_FLYWEIGHT_TYPENAME_TEMPL_ARGS(1),
  typename T2
>
bool operator==(
  const flyweight<T1,STREAMS_BOOST_FLYWEIGHT_TEMPL_ARGS(1)>& x,const T2& y)
{
  return x.get()==y;
}

template<
  typename T1,
  typename T2,STREAMS_BOOST_FLYWEIGHT_TYPENAME_TEMPL_ARGS(2)
>
bool operator==(
  const T1& x,const flyweight<T2,STREAMS_BOOST_FLYWEIGHT_TEMPL_ARGS(2)>& y)
{
  return x==y.get();
}

template<
  typename T1,STREAMS_BOOST_FLYWEIGHT_TYPENAME_TEMPL_ARGS(1),
  typename T2
>
bool operator<(
  const flyweight<T1,STREAMS_BOOST_FLYWEIGHT_TEMPL_ARGS(1)>& x,const T2& y)
{
  return x.get()<y;
}

template<
  typename T1,
  typename T2,STREAMS_BOOST_FLYWEIGHT_TYPENAME_TEMPL_ARGS(2)
>
bool operator<(
  const T1& x,const flyweight<T2,STREAMS_BOOST_FLYWEIGHT_TEMPL_ARGS(2)>& y)
{
  return x<y.get();
}
#endif /* !defined(STREAMS_BOOST_NO_FUNCTION_TEMPLATE_ORDERING) */

/* rest of comparison operators */

#define STREAMS_BOOST_FLYWEIGHT_COMPLETE_COMP_OPS(t,a1,a2)                            \
template<t>                                                                   \
inline bool operator!=(const a1& x,const a2& y)                               \
{                                                                             \
  return !(x==y);                                                             \
}                                                                             \
                                                                              \
template<t>                                                                   \
inline bool operator>(const a1& x,const a2& y)                                \
{                                                                             \
  return y<x;                                                                 \
}                                                                             \
                                                                              \
template<t>                                                                   \
inline bool operator>=(const a1& x,const a2& y)                               \
{                                                                             \
  return !(x<y);                                                              \
}                                                                             \
                                                                              \
template<t>                                                                   \
inline bool operator<=(const a1& x,const a2& y)                               \
{                                                                             \
  return !(y<x);                                                              \
}

STREAMS_BOOST_FLYWEIGHT_COMPLETE_COMP_OPS(
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
STREAMS_BOOST_FLYWEIGHT_COMPLETE_COMP_OPS(
  typename T1 STREAMS_BOOST_PP_COMMA()
  STREAMS_BOOST_FLYWEIGHT_TYPENAME_TEMPL_ARGS(1) STREAMS_BOOST_PP_COMMA()
  typename T2,
  flyweight<
    T1 STREAMS_BOOST_PP_COMMA() STREAMS_BOOST_FLYWEIGHT_TEMPL_ARGS(1)
  >,
  T2)
  
STREAMS_BOOST_FLYWEIGHT_COMPLETE_COMP_OPS(
  typename T1 STREAMS_BOOST_PP_COMMA()
  typename T2 STREAMS_BOOST_PP_COMMA() 
  STREAMS_BOOST_FLYWEIGHT_TYPENAME_TEMPL_ARGS(2),
  T1,
  flyweight<
    T2 STREAMS_BOOST_PP_COMMA() STREAMS_BOOST_FLYWEIGHT_TEMPL_ARGS(2)
  >)
#endif /* !defined(STREAMS_BOOST_NO_FUNCTION_TEMPLATE_ORDERING) */

/* specialized algorithms */

template<typename T,STREAMS_BOOST_FLYWEIGHT_TYPENAME_TEMPL_ARGS(_)>
void swap(
  flyweight<T,STREAMS_BOOST_FLYWEIGHT_TEMPL_ARGS(_)>& x,
  flyweight<T,STREAMS_BOOST_FLYWEIGHT_TEMPL_ARGS(_)>& y)
{
  x.swap(y);
}

template<
  STREAMS_BOOST_TEMPLATED_STREAM_ARGS(ElemType,Traits)
  STREAMS_BOOST_TEMPLATED_STREAM_COMMA
  typename T,STREAMS_BOOST_FLYWEIGHT_TYPENAME_TEMPL_ARGS(_)
>
STREAMS_BOOST_TEMPLATED_STREAM(ostream,ElemType,Traits)& operator<<(
  STREAMS_BOOST_TEMPLATED_STREAM(ostream,ElemType,Traits)& out,
  const flyweight<T,STREAMS_BOOST_FLYWEIGHT_TEMPL_ARGS(_)>& x)
{
  return out<<x.get();
}

template<
  STREAMS_BOOST_TEMPLATED_STREAM_ARGS(ElemType,Traits)
  STREAMS_BOOST_TEMPLATED_STREAM_COMMA
  typename T,STREAMS_BOOST_FLYWEIGHT_TYPENAME_TEMPL_ARGS(_)
>
STREAMS_BOOST_TEMPLATED_STREAM(istream,ElemType,Traits)& operator>>(
  STREAMS_BOOST_TEMPLATED_STREAM(istream,ElemType,Traits)& in,
  flyweight<T,STREAMS_BOOST_FLYWEIGHT_TEMPL_ARGS(_)>& x)
{
  typedef typename flyweight<
    T,STREAMS_BOOST_FLYWEIGHT_TEMPL_ARGS(_)
  >::value_type                     value_type;

  /* value_type need not be default ctble but must be copy ctble */
  value_type t(x.get());
  in>>t;
  x=t;
  return in;
}

} /* namespace flyweights */

} /* namespace streams_boost */

#undef STREAMS_BOOST_FLYWEIGHT_COMPLETE_COMP_OPS
#undef STREAMS_BOOST_FLYWEIGHT_TEMPL_ARGS
#undef STREAMS_BOOST_FLYWEIGHT_TYPENAME_TEMPL_ARGS

#if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC,STREAMS_BOOST_TESTED_AT(1400))
#pragma warning(pop)
#endif

#endif
