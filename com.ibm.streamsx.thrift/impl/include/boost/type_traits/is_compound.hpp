
//  (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt).
//
//  See http://www.streams_boost.org/libs/type_traits for most recent version including documentation.

#ifndef STREAMS_BOOST_TT_IS_COMPOUND_HPP_INCLUDED
#define STREAMS_BOOST_TT_IS_COMPOUND_HPP_INCLUDED

#include <streams_boost/config.hpp>
#include <streams_boost/type_traits/is_fundamental.hpp>
#include <streams_boost/type_traits/detail/ice_not.hpp>

// should be the last #include
#include <streams_boost/type_traits/detail/bool_trait_def.hpp>

namespace streams_boost {

#if !defined( __CODEGEARC__ )
namespace detail {

template <typename T>
struct is_compound_impl
{
   STREAMS_BOOST_STATIC_CONSTANT(bool, value =
      (::streams_boost::type_traits::ice_not<
         ::streams_boost::is_fundamental<T>::value
       >::value));
};

} // namespace detail
#endif // !defined( __CODEGEARC__ )

#if defined( __CODEGEARC__ )
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_compound,T,__is_compound(T))
#else
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_compound,T,::streams_boost::detail::is_compound_impl<T>::value)
#endif

} // namespace streams_boost

#include <streams_boost/type_traits/detail/bool_trait_undef.hpp>

#endif // STREAMS_BOOST_TT_IS_COMPOUND_HPP_INCLUDED
