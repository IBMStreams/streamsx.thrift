/*
 *
 * Copyright (c) 2002
 * John Maddock
 *
 * Use, modification and distribution are subject to the 
 * Boost Software License, Version 1.0. (See accompanying file 
 * LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
 *
 */

 /*
  *   LOCATION:    see http://www.streams_boost.org for most recent version.
  *   FILE         regex_match.hpp
  *   VERSION      see <streams_boost/version.hpp>
  *   DESCRIPTION: Iterator traits for selecting an iterator type as
  *                an integral constant expression.
  */


#ifndef STREAMS_BOOST_REGEX_ITERATOR_CATEGORY_HPP
#define STREAMS_BOOST_REGEX_ITERATOR_CATEGORY_HPP

#include <iterator>
#include <streams_boost/type_traits/is_convertible.hpp>
#include <streams_boost/type_traits/is_pointer.hpp>

namespace streams_boost{
namespace detail{

template <class I>
struct is_random_imp
{
#ifndef STREAMS_BOOST_NO_STD_ITERATOR_TRAITS
private:
   typedef typename std::iterator_traits<I>::iterator_category cat;
public:
   STREAMS_BOOST_STATIC_CONSTANT(bool, value = (::streams_boost::is_convertible<cat*, std::random_access_iterator_tag*>::value));
#else
   STREAMS_BOOST_STATIC_CONSTANT(bool, value = false);
#endif
};

template <class I>
struct is_random_pointer_imp
{
   STREAMS_BOOST_STATIC_CONSTANT(bool, value = true);
};

template <bool is_pointer_type>
struct is_random_imp_selector
{
   template <class I>
   struct rebind
   {
      typedef is_random_imp<I> type;
   };
};

template <>
struct is_random_imp_selector<true>
{
   template <class I>
   struct rebind
   {
      typedef is_random_pointer_imp<I> type;
   };
};

}

template <class I>
struct is_random_access_iterator
{
private:
   typedef detail::is_random_imp_selector< ::streams_boost::is_pointer<I>::value> selector;
   typedef typename selector::template rebind<I> bound_type;
   typedef typename bound_type::type answer;
public:
   STREAMS_BOOST_STATIC_CONSTANT(bool, value = answer::value);
};

#ifndef STREAMS_BOOST_NO_INCLASS_MEMBER_INITIALIZATION
template <class I>
const bool is_random_access_iterator<I>::value;
#endif

}

#endif

