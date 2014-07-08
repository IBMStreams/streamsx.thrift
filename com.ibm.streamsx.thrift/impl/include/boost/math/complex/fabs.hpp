//  (C) Copyright John Maddock 2005.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_MATH_COMPLEX_FABS_INCLUDED
#define STREAMS_BOOST_MATH_COMPLEX_FABS_INCLUDED

#ifndef STREAMS_BOOST_MATH_HYPOT_INCLUDED
#  include <streams_boost/math/special_functions/hypot.hpp>
#endif

namespace streams_boost{ namespace math{

template<class T> 
inline T fabs(const std::complex<T>& z)
{
   return ::streams_boost::math::hypot(z.real(), z.imag());
}

} } // namespaces

#endif // STREAMS_BOOST_MATH_COMPLEX_FABS_INCLUDED
