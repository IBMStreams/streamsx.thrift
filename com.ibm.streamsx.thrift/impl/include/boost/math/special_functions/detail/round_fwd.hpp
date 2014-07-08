// Copyright John Maddock 2008.

// Use, modification and distribution are subject to the
// Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt
// or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_MATH_SPECIAL_ROUND_FWD_HPP
#define STREAMS_BOOST_MATH_SPECIAL_ROUND_FWD_HPP

#include <streams_boost/config.hpp>

#ifdef _MSC_VER
#pragma once
#endif

namespace streams_boost
{
   namespace math
   { 

   template <class T, class Policy>
   T trunc(const T& v, const Policy& pol);
   template <class T>
   T trunc(const T& v);
   template <class T, class Policy>
   int itrunc(const T& v, const Policy& pol);
   template <class T>
   int itrunc(const T& v);
   template <class T, class Policy>
   long ltrunc(const T& v, const Policy& pol);
   template <class T>
   long ltrunc(const T& v);
#ifdef STREAMS_BOOST_HAS_LONG_LONG
   template <class T, class Policy>
   streams_boost::long_long_type lltrunc(const T& v, const Policy& pol);
   template <class T>
   streams_boost::long_long_type lltrunc(const T& v);
#endif
   template <class T, class Policy>
   T round(const T& v, const Policy& pol);
   template <class T>
   T round(const T& v);
   template <class T, class Policy>
   int iround(const T& v, const Policy& pol);
   template <class T>
   int iround(const T& v);
   template <class T, class Policy>
   long lround(const T& v, const Policy& pol);
   template <class T>
   long lround(const T& v);
#ifdef STREAMS_BOOST_HAS_LONG_LONG
   template <class T, class Policy>
   streams_boost::long_long_type llround(const T& v, const Policy& pol);
   template <class T>
   streams_boost::long_long_type llround(const T& v);
#endif
   template <class T, class Policy>
   T modf(const T& v, T* ipart, const Policy& pol);
   template <class T>
   T modf(const T& v, T* ipart);
   template <class T, class Policy>
   T modf(const T& v, int* ipart, const Policy& pol);
   template <class T>
   T modf(const T& v, int* ipart);
   template <class T, class Policy>
   T modf(const T& v, long* ipart, const Policy& pol);
   template <class T>
   T modf(const T& v, long* ipart);
#ifdef STREAMS_BOOST_HAS_LONG_LONG
   template <class T, class Policy>
   T modf(const T& v, streams_boost::long_long_type* ipart, const Policy& pol);
   template <class T>
   T modf(const T& v, streams_boost::long_long_type* ipart);
#endif

   }
}
#endif // STREAMS_BOOST_MATH_SPECIAL_ROUND_FWD_HPP

