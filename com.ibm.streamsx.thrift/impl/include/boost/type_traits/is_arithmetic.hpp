
//  (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt).
//
//  See http://www.streams_boost.org/libs/type_traits for most recent version including documentation.

#ifndef STREAMS_BOOST_TT_IS_ARITHMETIC_HPP_INCLUDED
#define STREAMS_BOOST_TT_IS_ARITHMETIC_HPP_INCLUDED

#if !defined( __CODEGEARC__ )
#include <streams_boost/type_traits/is_integral.hpp>
#include <streams_boost/type_traits/is_float.hpp>
#include <streams_boost/type_traits/detail/ice_or.hpp>
#include <streams_boost/config.hpp>
#endif

// should be the last #include
#include <streams_boost/type_traits/detail/bool_trait_def.hpp>

namespace streams_boost {

#if !defined(__CODEGEARC__)
namespace detail {

template< typename T >
struct is_arithmetic_impl
{ 
    STREAMS_BOOST_STATIC_CONSTANT(bool, value = 
        (::streams_boost::type_traits::ice_or< 
            ::streams_boost::is_integral<T>::value,
            ::streams_boost::is_float<T>::value
        >::value)); 
};

} // namespace detail
#endif

//* is a type T an arithmetic type described in the standard (3.9.1p8)
#if defined(__CODEGEARC__)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_arithmetic,T,__is_arithmetic(T))
#else
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_arithmetic,T,::streams_boost::detail::is_arithmetic_impl<T>::value)
#endif

} // namespace streams_boost

#include <streams_boost/type_traits/detail/bool_trait_undef.hpp>

#endif // STREAMS_BOOST_TT_IS_ARITHMETIC_HPP_INCLUDED
