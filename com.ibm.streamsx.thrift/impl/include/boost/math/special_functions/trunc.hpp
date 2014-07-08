//  Copyright John Maddock 2007.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_MATH_TRUNC_HPP
#define STREAMS_BOOST_MATH_TRUNC_HPP

#ifdef _MSC_VER
#pragma once
#endif

#include <streams_boost/math/tools/config.hpp>
#include <streams_boost/math/policies/error_handling.hpp>
#include <streams_boost/math/special_functions/fpclassify.hpp>

namespace streams_boost{ namespace math{

template <class T, class Policy>
inline T trunc(const T& v, const Policy& pol)
{
   STREAMS_BOOST_MATH_STD_USING
   if(!(streams_boost::math::isfinite)(v))
      return policies::raise_rounding_error("streams_boost::math::trunc<%1%>(%1%)", 0, v, pol);
   return (v >= 0) ? static_cast<T>(floor(v)) : static_cast<T>(ceil(v));
}
template <class T>
inline T trunc(const T& v)
{
   return trunc(v, policies::policy<>());
}
//
// The following functions will not compile unless T has an
// implicit convertion to the integer types.  For user-defined
// number types this will likely not be the case.  In that case
// these functions should either be specialized for the UDT in
// question, or else overloads should be placed in the same 
// namespace as the UDT: these will then be found via argument
// dependent lookup.  See our concept archetypes for examples.
//
template <class T, class Policy>
inline int itrunc(const T& v, const Policy& pol)
{
   STREAMS_BOOST_MATH_STD_USING
   T r = streams_boost::math::trunc(v, pol);
   if(fabs(r) > (std::numeric_limits<int>::max)())
      return static_cast<int>(policies::raise_rounding_error("streams_boost::math::itrunc<%1%>(%1%)", 0, v, pol));
   return static_cast<int>(r);
}
template <class T>
inline int itrunc(const T& v)
{
   return itrunc(v, policies::policy<>());
}

template <class T, class Policy>
inline long ltrunc(const T& v, const Policy& pol)
{
   STREAMS_BOOST_MATH_STD_USING
   T r = streams_boost::math::trunc(v, pol);
   if(fabs(r) > (std::numeric_limits<long>::max)())
      return static_cast<long>(policies::raise_rounding_error("streams_boost::math::ltrunc<%1%>(%1%)", 0, v, pol));
   return static_cast<long>(r);
}
template <class T>
inline long ltrunc(const T& v)
{
   return ltrunc(v, policies::policy<>());
}

#ifdef STREAMS_BOOST_HAS_LONG_LONG

template <class T, class Policy>
inline streams_boost::long_long_type lltrunc(const T& v, const Policy& pol)
{
   STREAMS_BOOST_MATH_STD_USING
   T r = streams_boost::math::trunc(v, pol);
   if(fabs(r) > (std::numeric_limits<streams_boost::long_long_type>::max)())
      return static_cast<streams_boost::long_long_type>(policies::raise_rounding_error("streams_boost::math::lltrunc<%1%>(%1%)", 0, v, pol));
   return static_cast<streams_boost::long_long_type>(r);
}
template <class T>
inline streams_boost::long_long_type lltrunc(const T& v)
{
   return lltrunc(v, policies::policy<>());
}

#endif

}} // namespaces

#endif // STREAMS_BOOST_MATH_TRUNC_HPP
