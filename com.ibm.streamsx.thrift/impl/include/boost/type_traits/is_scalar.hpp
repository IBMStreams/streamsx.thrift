
//  (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt).
//
//  See http://www.streams_boost.org/libs/type_traits for most recent version including documentation.

#ifndef STREAMS_BOOST_TT_IS_SCALAR_HPP_INCLUDED
#define STREAMS_BOOST_TT_IS_SCALAR_HPP_INCLUDED

#include <streams_boost/type_traits/is_arithmetic.hpp>
#include <streams_boost/type_traits/is_enum.hpp>
#include <streams_boost/type_traits/is_pointer.hpp>
#include <streams_boost/type_traits/is_member_pointer.hpp>
#include <streams_boost/type_traits/detail/ice_or.hpp>
#include <streams_boost/config.hpp>

// should be the last #include
#include <streams_boost/type_traits/detail/bool_trait_def.hpp>

namespace streams_boost {

namespace detail {

template <typename T>
struct is_scalar_impl
{ 
   STREAMS_BOOST_STATIC_CONSTANT(bool, value =
      (::streams_boost::type_traits::ice_or<
         ::streams_boost::is_arithmetic<T>::value,
         ::streams_boost::is_enum<T>::value,
         ::streams_boost::is_pointer<T>::value,
         ::streams_boost::is_member_pointer<T>::value
      >::value));
};

// these specializations are only really needed for compilers 
// without partial specialization support:
template <> struct is_scalar_impl<void>{ STREAMS_BOOST_STATIC_CONSTANT(bool, value = false ); };
#ifndef STREAMS_BOOST_NO_CV_VOID_SPECIALIZATIONS
template <> struct is_scalar_impl<void const>{ STREAMS_BOOST_STATIC_CONSTANT(bool, value = false ); };
template <> struct is_scalar_impl<void volatile>{ STREAMS_BOOST_STATIC_CONSTANT(bool, value = false ); };
template <> struct is_scalar_impl<void const volatile>{ STREAMS_BOOST_STATIC_CONSTANT(bool, value = false ); };
#endif

} // namespace detail

STREAMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_scalar,T,::streams_boost::detail::is_scalar_impl<T>::value)

} // namespace streams_boost

#include <streams_boost/type_traits/detail/bool_trait_undef.hpp>

#endif // STREAMS_BOOST_TT_IS_SCALAR_HPP_INCLUDED
