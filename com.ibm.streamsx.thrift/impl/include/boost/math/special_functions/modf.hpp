//  Copyright John Maddock 2007.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_MATH_MODF_HPP
#define STREAMS_BOOST_MATH_MODF_HPP

#ifdef _MSC_VER
#pragma once
#endif

#include <streams_boost/math/tools/config.hpp>
#include <streams_boost/math/special_functions/trunc.hpp>

namespace streams_boost{ namespace math{

template <class T, class Policy>
inline T modf(const T& v, T* ipart, const Policy& pol)
{
   *ipart = trunc(v, pol);
   return v - *ipart;
}
template <class T>
inline T modf(const T& v, T* ipart)
{
   return modf(v, ipart, policies::policy<>());
}

template <class T, class Policy>
inline T modf(const T& v, int* ipart, const Policy& pol)
{
   *ipart = itrunc(v, pol);
   return v - *ipart;
}
template <class T>
inline T modf(const T& v, int* ipart)
{
   return modf(v, ipart, policies::policy<>());
}

template <class T, class Policy>
inline T modf(const T& v, long* ipart, const Policy& pol)
{
   *ipart = ltrunc(v, pol);
   return v - *ipart;
}
template <class T>
inline T modf(const T& v, long* ipart)
{
   return modf(v, ipart, policies::policy<>());
}

#ifdef STREAMS_BOOST_HAS_LONG_LONG
template <class T, class Policy>
inline T modf(const T& v, streams_boost::long_long_type* ipart, const Policy& pol)
{
   *ipart = lltrunc(v, pol);
   return v - *ipart;
}
template <class T>
inline T modf(const T& v, streams_boost::long_long_type* ipart)
{
   return modf(v, ipart, policies::policy<>());
}
#endif

}} // namespaces

#endif // STREAMS_BOOST_MATH_MODF_HPP
