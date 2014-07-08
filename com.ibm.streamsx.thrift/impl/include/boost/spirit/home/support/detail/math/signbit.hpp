// signbit.hpp

#ifndef STREAMS_BOOST_SPIRIT_MATH_SIGNBIT_HPP
#define STREAMS_BOOST_SPIRIT_MATH_SIGNBIT_HPP

// Copyright (c) 2006 Johan Rade

// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt
// or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#if defined(_MSC_VER)
#pragma once
#endif

#include <streams_boost/spirit/home/support/detail/math/detail/fp_traits.hpp>

namespace streams_boost {
namespace spirit {
namespace math {

//------------------------------------------------------------------------------

template<class T> bool (signbit)(T x)
{
    typedef STREAMS_BOOST_DEDUCED_TYPENAME detail::fp_traits<T>::type traits;
    traits::init();

    STREAMS_BOOST_DEDUCED_TYPENAME traits::bits a;
    traits::get_bits(x,a);
    a &= traits::sign;
    return a != 0;
}

//------------------------------------------------------------------------------

namespace detail {

    template<class T> T copysign_impl(T x, T y)
    {
        typedef STREAMS_BOOST_DEDUCED_TYPENAME fp_traits<T>::type traits;
        traits::init();

        STREAMS_BOOST_DEDUCED_TYPENAME traits::bits a;
        traits::get_bits(x,a);
        a &= ~traits::sign;

        STREAMS_BOOST_DEDUCED_TYPENAME traits::bits b;
        traits::get_bits(y,b);
        b &= traits::sign;

        traits::set_bits(x,a|b);
        return x;
    }
}

inline float (copysign)(float x, float y)      // magnitude of x and sign of y
{
    return detail::copysign_impl(x,y);
}

inline double (copysign)(double x, double y)
{
    return detail::copysign_impl(x,y);
}

inline long double (copysign)(long double x, long double y)
{
    return detail::copysign_impl(x,y);
}

//------------------------------------------------------------------------------

template<class T> T (changesign)(T x)
{
    typedef STREAMS_BOOST_DEDUCED_TYPENAME detail::fp_traits<T>::type traits;
    traits::init();

    STREAMS_BOOST_DEDUCED_TYPENAME traits::bits a;
    traits::get_bits(x,a);
    a ^= traits::sign;
    traits::set_bits(x,a);
    return x;
}

//------------------------------------------------------------------------------

}   // namespace math
}   // namespace spirit
}   // namespace streams_boost

#endif
