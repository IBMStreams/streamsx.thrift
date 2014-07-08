//  (C) Copyright John Maddock 2005.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_MATH_COMPLEX_ASINH_INCLUDED
#define STREAMS_BOOST_MATH_COMPLEX_ASINH_INCLUDED

#ifndef STREAMS_BOOST_MATH_COMPLEX_DETAILS_INCLUDED
#  include <streams_boost/math/complex/details.hpp>
#endif
#ifndef STREAMS_BOOST_MATH_COMPLEX_ASIN_INCLUDED
#  include <streams_boost/math/complex/asin.hpp>
#endif

namespace streams_boost{ namespace math{

template<class T> 
inline std::complex<T> asinh(const std::complex<T>& x)
{
   //
   // We use asinh(z) = i asin(-i z);
   // Note that C99 defines this the other way around (which is
   // to say asin is specified in terms of asinh), this is consistent
   // with C99 though:
   //
   return ::streams_boost::math::detail::mult_i(::streams_boost::math::asin(::streams_boost::math::detail::mult_minus_i(x)));
}

} } // namespaces

#endif // STREAMS_BOOST_MATH_COMPLEX_ASINH_INCLUDED
