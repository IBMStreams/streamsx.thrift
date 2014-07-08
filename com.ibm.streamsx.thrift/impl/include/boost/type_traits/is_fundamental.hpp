
//  (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt).
//
//  See http://www.streams_boost.org/libs/type_traits for most recent version including documentation.

#ifndef STREAMS_BOOST_TT_IS_FUNDAMENTAL_HPP_INCLUDED
#define STREAMS_BOOST_TT_IS_FUNDAMENTAL_HPP_INCLUDED

#include <streams_boost/type_traits/is_arithmetic.hpp>
#include <streams_boost/type_traits/is_void.hpp>
#include <streams_boost/type_traits/detail/ice_or.hpp>

// should be the last #include
#include <streams_boost/type_traits/detail/bool_trait_def.hpp>

namespace streams_boost {

namespace detail {

template <typename T> 
struct is_fundamental_impl
    : ::streams_boost::type_traits::ice_or< 
          ::streams_boost::is_arithmetic<T>::value
        , ::streams_boost::is_void<T>::value
        >
{ 
};

} // namespace detail

//* is a type T a fundamental type described in the standard (3.9.1)
#if defined( __CODEGEARC__ )
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_fundamental,T,__is_fundamental(T))
#else
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_fundamental,T,::streams_boost::detail::is_fundamental_impl<T>::value)
#endif

} // namespace streams_boost

#include <streams_boost/type_traits/detail/bool_trait_undef.hpp>

#endif // STREAMS_BOOST_TT_IS_FUNDAMENTAL_HPP_INCLUDED
