//  (C) Copyright John Maddock 2005.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_TR1_ARRAY_HPP_INCLUDED
#  define STREAMS_BOOST_TR1_ARRAY_HPP_INCLUDED
#  include <streams_boost/tr1/detail/config.hpp>

#ifdef STREAMS_BOOST_HAS_TR1_ARRAY

#  ifdef STREAMS_BOOST_HAS_INCLUDE_NEXT
#     include_next STREAMS_BOOST_TR1_HEADER(array)
#  else
#     include <streams_boost/tr1/detail/config_all.hpp>
#     include STREAMS_BOOST_TR1_STD_HEADER(STREAMS_BOOST_TR1_PATH(array))
#  endif

#else

#include <streams_boost/array.hpp>
#include <streams_boost/static_assert.hpp>
#include <streams_boost/type_traits/integral_constant.hpp>
#include <streams_boost/detail/workaround.hpp>

namespace std{ namespace tr1{

using ::streams_boost::array;

#if !STREAMS_BOOST_WORKAROUND(__BORLANDC__, < 0x0582)
// [6.1.3.2] Tuple creation functions
using ::streams_boost::swap;
#endif

#if !defined(STREAMS_BOOST_TR1_USE_OLD_TUPLE)
}} namespace streams_boost{ namespace fusion{
#endif

// [6.2.2.5] Tuple interface to class template array
template <class T> struct tuple_size; // forward declaration
template <int I, class T> struct tuple_element; // forward declaration
#ifndef STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
template <class T, size_t N>
struct tuple_size< ::streams_boost::array<T, N> >
   : public ::streams_boost::integral_constant< ::std::size_t, N>{};


template <int I, class T, size_t N>
struct tuple_element<I, ::streams_boost::array<T, N> >
{
#if !STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x570))
   STREAMS_BOOST_STATIC_ASSERT(I < (int)N);
   STREAMS_BOOST_STATIC_ASSERT(I >= 0);
#endif
   typedef T type;
};
#endif
template <int I, class T, size_t N>
T& get( ::streams_boost::array<T, N>& a)
{
   STREAMS_BOOST_STATIC_ASSERT(I < N);
   STREAMS_BOOST_STATIC_ASSERT(I >= 0);
   return a[I];
}

template <int I, class T, size_t N>
const T& get(const array<T, N>& a)
{
   STREAMS_BOOST_STATIC_ASSERT(I < N);
   STREAMS_BOOST_STATIC_ASSERT(I >= 0);
   return a[I];
}

#if !defined(STREAMS_BOOST_TR1_USE_OLD_TUPLE)
}} namespace std{ namespace tr1{

   using ::streams_boost::fusion::tuple_size;
   using ::streams_boost::fusion::tuple_element;
   using ::streams_boost::fusion::get;

#endif


} } // namespaces

#endif

#endif
