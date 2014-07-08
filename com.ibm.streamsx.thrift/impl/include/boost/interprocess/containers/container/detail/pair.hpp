//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2005-2009.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/container for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef STREAMS_BOOST_CONTAINERS_CONTAINERS_DETAIL_PAIR_HPP
#define STREAMS_BOOST_CONTAINERS_CONTAINERS_DETAIL_PAIR_HPP

#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

#include <streams_boost/interprocess/containers/container/detail/config_begin.hpp>
#include <streams_boost/interprocess/containers/container/detail/workaround.hpp>

#include <streams_boost/interprocess/containers/container/detail/mpl.hpp>
#include <streams_boost/interprocess/containers/container/detail/type_traits.hpp>

#include <utility>   //std::pair

#include <streams_boost/interprocess/detail/move.hpp>

#ifndef STREAMS_BOOST_CONTAINERS_PERFECT_FORWARDING
#include <streams_boost/interprocess/containers/container/detail/preprocessor.hpp>
#endif

namespace streams_boost {
namespace container { 
namespace containers_detail {

template <class T1, class T2>
struct pair
{
   private:
   STREAMS_BOOST_COPYABLE_AND_MOVABLE(pair)

   public:
   typedef T1 first_type;
   typedef T2 second_type;

   T1 first;
   T2 second;

   //std::pair compatibility
   template <class D, class S>
   pair(const std::pair<D, S>& p)
      : first(p.first), second(p.second)
   {}

   //To resolve ambiguity with the variadic constructor of 1 argument
   //and the previous constructor
   pair(std::pair<T1, T2>& x)
      : first(x.first), second(x.second)
   {}

   template <class D, class S>
   pair(STREAMS_BOOST_INTERPROCESS_RV_REF_2_TEMPL_ARGS(std::pair, D, S) p)
      : first(streams_boost::interprocess::move(p.first)), second(streams_boost::interprocess::move(p.second))
   {}

   pair()
      : first(), second()
   {}

   pair(const pair<T1, T2>& x)
      : first(x.first), second(x.second)
   {}

   //To resolve ambiguity with the variadic constructor of 1 argument
   //and the copy constructor
   pair(pair<T1, T2>& x)
      : first(x.first), second(x.second)
   {}

   pair(STREAMS_BOOST_INTERPROCESS_RV_REF(pair) p)
      : first(streams_boost::interprocess::move(p.first)), second(streams_boost::interprocess::move(p.second))
   {}

   template <class D, class S>
   pair(STREAMS_BOOST_INTERPROCESS_RV_REF_2_TEMPL_ARGS(pair, D, S) p)
      : first(streams_boost::interprocess::move(p.first)), second(streams_boost::interprocess::move(p.second))
   {}

   #ifdef STREAMS_BOOST_CONTAINERS_PERFECT_FORWARDING

   template<class U, class ...Args>
   pair(U &&u, Args &&... args)
      : first(streams_boost::interprocess::forward<U>(u))
      , second(streams_boost::interprocess::forward<Args>(args)...)
   {}

   #else

   template<class U>
   pair( STREAMS_BOOST_CONTAINERS_PARAM(U, u)
       #ifndef STREAMS_BOOST_HAS_RVALUE_REFS
       , typename containers_detail::disable_if
          < containers_detail::is_same<U, ::streams_boost::interprocess::rv<pair> > >::type* = 0
       #endif
      )
      : first(streams_boost::interprocess::forward<U>(const_cast<U&>(u)))
   {}

   #define STREAMS_BOOST_PP_LOCAL_MACRO(n)                                                            \
   template<class U, STREAMS_BOOST_PP_ENUM_PARAMS(n, class P)>                                        \
   pair(STREAMS_BOOST_CONTAINERS_PARAM(U, u)                                                          \
       ,STREAMS_BOOST_PP_ENUM(n, STREAMS_BOOST_CONTAINERS_PP_PARAM_LIST, _))                                  \
      : first(streams_boost::interprocess::forward<U>(const_cast<U&>(u)))                             \
      , second(STREAMS_BOOST_PP_ENUM(n, STREAMS_BOOST_CONTAINERS_PP_PARAM_FORWARD, _))                        \
   {}                                                                                         \
   //!
   #define STREAMS_BOOST_PP_LOCAL_LIMITS (1, STREAMS_BOOST_CONTAINERS_MAX_CONSTRUCTOR_PARAMETERS)
   #include STREAMS_BOOST_PP_LOCAL_ITERATE()
   #endif

   pair& operator=(STREAMS_BOOST_INTERPROCESS_COPY_ASSIGN_REF(pair) p)
   {
      first  = p.first;
      second = p.second;
      return *this;
   }

   pair& operator=(STREAMS_BOOST_INTERPROCESS_RV_REF(pair) p)
   {
      first  = streams_boost::interprocess::move(p.first);
      second = streams_boost::interprocess::move(p.second);
      return *this;
   }

   pair& operator=(STREAMS_BOOST_INTERPROCESS_RV_REF_2_TEMPL_ARGS(std::pair, T1, T2) p)
   {
      first  = streams_boost::interprocess::move(p.first);
      second = streams_boost::interprocess::move(p.second);
      return *this;
   }

   template <class D, class S>
   pair& operator=(STREAMS_BOOST_INTERPROCESS_RV_REF_2_TEMPL_ARGS(std::pair, D, S) p)
   {
      first  = streams_boost::interprocess::move(p.first);
      second = streams_boost::interprocess::move(p.second);
      return *this;
   }

   void swap(pair& p)
   {  std::swap(*this, p); }
};

template <class T1, class T2>
inline bool operator==(const pair<T1,T2>& x, const pair<T1,T2>& y)
{  return static_cast<bool>(x.first == y.first && x.second == y.second);  }

template <class T1, class T2>
inline bool operator< (const pair<T1,T2>& x, const pair<T1,T2>& y)
{  return static_cast<bool>(x.first < y.first ||
                         (!(y.first < x.first) && x.second < y.second)); }

template <class T1, class T2>
inline bool operator!=(const pair<T1,T2>& x, const pair<T1,T2>& y)
{  return static_cast<bool>(!(x == y));  }

template <class T1, class T2>
inline bool operator> (const pair<T1,T2>& x, const pair<T1,T2>& y)
{  return y < x;  }

template <class T1, class T2>
inline bool operator>=(const pair<T1,T2>& x, const pair<T1,T2>& y)
{  return static_cast<bool>(!(x < y)); }

template <class T1, class T2>
inline bool operator<=(const pair<T1,T2>& x, const pair<T1,T2>& y)
{  return static_cast<bool>(!(y < x)); }

template <class T1, class T2>
inline pair<T1, T2> make_pair(T1 x, T2 y)
{  return pair<T1, T2>(x, y); }

template <class T1, class T2>
inline void swap(pair<T1, T2>& x, pair<T1, T2>& y)
{
   swap(x.first, y.first);
   swap(x.second, y.second);
}

}  //namespace containers_detail { 
}  //namespace container { 

}  //namespace streams_boost {

#include <streams_boost/interprocess/containers/container/detail/config_end.hpp>

#endif   //#ifndef STREAMS_BOOST_CONTAINERS_DETAIL_PAIR_HPP
