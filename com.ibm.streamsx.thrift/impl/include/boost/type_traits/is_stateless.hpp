
//  (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt).
//
//  See http://www.streams_boost.org/libs/type_traits for most recent version including documentation.

#ifndef STREAMS_BOOST_TT_IS_STATELESS_HPP_INCLUDED
#define STREAMS_BOOST_TT_IS_STATELESS_HPP_INCLUDED

#include <streams_boost/type_traits/has_trivial_constructor.hpp>
#include <streams_boost/type_traits/has_trivial_copy.hpp>
#include <streams_boost/type_traits/has_trivial_destructor.hpp>
#include <streams_boost/type_traits/is_class.hpp>
#include <streams_boost/type_traits/is_empty.hpp>
#include <streams_boost/type_traits/detail/ice_and.hpp>
#include <streams_boost/config.hpp>

// should be the last #include
#include <streams_boost/type_traits/detail/bool_trait_def.hpp>

namespace streams_boost {

namespace detail {

template <typename T>
struct is_stateless_impl
{
  STREAMS_BOOST_STATIC_CONSTANT(bool, value = 
    (::streams_boost::type_traits::ice_and<
       ::streams_boost::has_trivial_constructor<T>::value,
       ::streams_boost::has_trivial_copy<T>::value,
       ::streams_boost::has_trivial_destructor<T>::value,
       ::streams_boost::is_class<T>::value,
       ::streams_boost::is_empty<T>::value
     >::value));
};

} // namespace detail

STREAMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_stateless,T,::streams_boost::detail::is_stateless_impl<T>::value)

} // namespace streams_boost

#include <streams_boost/type_traits/detail/bool_trait_undef.hpp>

#endif // STREAMS_BOOST_TT_IS_STATELESS_HPP_INCLUDED
