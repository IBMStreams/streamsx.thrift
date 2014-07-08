
//  (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt).
//
//  See http://www.streams_boost.org/libs/type_traits for most recent version including documentation.

#ifndef STREAMS_BOOST_TT_IS_OBJECT_HPP_INCLUDED
#define STREAMS_BOOST_TT_IS_OBJECT_HPP_INCLUDED

#include <streams_boost/type_traits/is_reference.hpp>
#include <streams_boost/type_traits/is_void.hpp>
#include <streams_boost/type_traits/is_function.hpp>
#include <streams_boost/type_traits/detail/ice_and.hpp>
#include <streams_boost/type_traits/detail/ice_not.hpp>
#include <streams_boost/config.hpp>

// should be the last #include
#include <streams_boost/type_traits/detail/bool_trait_def.hpp>

namespace streams_boost {

namespace detail {

template <typename T>
struct is_object_impl
{
#ifndef STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
   STREAMS_BOOST_STATIC_CONSTANT(bool, value =
      (::streams_boost::type_traits::ice_and<
         ::streams_boost::type_traits::ice_not< ::streams_boost::is_reference<T>::value>::value,
         ::streams_boost::type_traits::ice_not< ::streams_boost::is_void<T>::value>::value,
         ::streams_boost::type_traits::ice_not< ::streams_boost::is_function<T>::value>::value
      >::value));
#else
   STREAMS_BOOST_STATIC_CONSTANT(bool, value =
      (::streams_boost::type_traits::ice_and<
         ::streams_boost::type_traits::ice_not< ::streams_boost::is_reference<T>::value>::value,
         ::streams_boost::type_traits::ice_not< ::streams_boost::is_void<T>::value>::value
      >::value));
#endif
};

} // namespace detail

STREAMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_object,T,::streams_boost::detail::is_object_impl<T>::value)

} // namespace streams_boost

#include <streams_boost/type_traits/detail/bool_trait_undef.hpp>

#endif // STREAMS_BOOST_TT_IS_OBJECT_HPP_INCLUDED
