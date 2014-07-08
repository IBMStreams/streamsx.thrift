//  (C) Copyright John Maddock 2006.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_MATH_TOOLS_SIGN_HPP
#define STREAMS_BOOST_MATH_TOOLS_SIGN_HPP

#ifdef _MSC_VER
#pragma once
#endif

#include <streams_boost/math/tools/config.hpp>
#include <streams_boost/math/special_functions/math_fwd.hpp>
#include <streams_boost/math/special_functions/detail/fp_traits.hpp>

namespace streams_boost{ namespace math{ 

namespace detail {

#ifdef STREAMS_BOOST_MATH_USE_STD_FPCLASSIFY
    template<class T> 
    inline int signbit_impl(T x, native_tag const&)
    {
        return (std::signbit)(x);
    }
#endif

    template<class T> 
    inline int signbit_impl(T x, generic_tag<true> const&)
    {
        return x < 0;
    }

    template<class T> 
    inline int signbit_impl(T x, generic_tag<false> const&)
    {
        return x < 0;
    }

    template<class T> 
    inline int signbit_impl(T x, ieee_copy_all_bits_tag const&)
    {
        typedef STREAMS_BOOST_DEDUCED_TYPENAME fp_traits<T>::type traits;

        STREAMS_BOOST_DEDUCED_TYPENAME traits::bits a;
        traits::get_bits(x,a);
        return a & traits::sign ? 1 : 0;
    }

    template<class T> 
    inline int signbit_impl(T x, ieee_copy_leading_bits_tag const&)
    {
        typedef STREAMS_BOOST_DEDUCED_TYPENAME fp_traits<T>::type traits;

        STREAMS_BOOST_DEDUCED_TYPENAME traits::bits a;
        traits::get_bits(x,a);

        return a & traits::sign ? 1 : 0;
    }
}   // namespace detail

template<class T> int (signbit)(T x)
{ //!< \brief return true if floating-point type t is NaN (Not A Number).
   typedef typename detail::fp_traits<T>::type traits;
   typedef typename traits::method method;
   typedef typename streams_boost::is_floating_point<T>::type fp_tag;
   return detail::signbit_impl(x, method());
}

template <class T>
inline int sign STREAMS_BOOST_NO_MACRO_EXPAND(const T& z)
{
   return (z == 0) ? 0 : (streams_boost::math::signbit)(z) ? -1 : 1;
}

template <class T>
inline T copysign STREAMS_BOOST_NO_MACRO_EXPAND(const T& x, const T& y)
{
   STREAMS_BOOST_MATH_STD_USING
      return fabs(x) * ((streams_boost::math::signbit)(y) ? -1 : 1);
}

} // namespace math
} // namespace streams_boost


#endif // STREAMS_BOOST_MATH_TOOLS_SIGN_HPP


