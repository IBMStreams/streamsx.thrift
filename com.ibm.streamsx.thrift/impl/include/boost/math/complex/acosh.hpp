//  (C) Copyright John Maddock 2005.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_MATH_COMPLEX_ACOSH_INCLUDED
#define STREAMS_BOOST_MATH_COMPLEX_ACOSH_INCLUDED

#ifndef STREAMS_BOOST_MATH_COMPLEX_DETAILS_INCLUDED
#  include <streams_boost/math/complex/details.hpp>
#endif
#ifndef STREAMS_BOOST_MATH_COMPLEX_ATANH_INCLUDED
#  include <streams_boost/math/complex/acos.hpp>
#endif

namespace streams_boost{ namespace math{

template<class T> 
inline std::complex<T> acosh(const std::complex<T>& z)
{
   //
   // We use the relation acosh(z) = +-i acos(z)
   // Choosing the sign of multiplier to give real(acosh(z)) >= 0
   // as well as compatibility with C99.
   //
   std::complex<T> result = streams_boost::math::acos(z);
   if(!detail::test_is_nan(result.imag()) && result.imag() <= 0)
      return detail::mult_i(result);
   return detail::mult_minus_i(result);
}

} } // namespaces

#endif // STREAMS_BOOST_MATH_COMPLEX_ACOSH_INCLUDED