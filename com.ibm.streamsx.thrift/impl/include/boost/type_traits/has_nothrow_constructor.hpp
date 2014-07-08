
//  (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt).
//
//  See http://www.streams_boost.org/libs/type_traits for most recent version including documentation.

#ifndef STREAMS_BOOST_TT_HAS_NOTHROW_CONSTRUCTOR_HPP_INCLUDED
#define STREAMS_BOOST_TT_HAS_NOTHROW_CONSTRUCTOR_HPP_INCLUDED

#include <streams_boost/type_traits/has_trivial_constructor.hpp>

// should be the last #include
#include <streams_boost/type_traits/detail/bool_trait_def.hpp>

namespace streams_boost {

namespace detail{

template <class T>
struct has_nothrow_constructor_imp{
   STREAMS_BOOST_STATIC_CONSTANT(bool, value = 
      (::streams_boost::type_traits::ice_or<
         ::streams_boost::has_trivial_constructor<T>::value,
         STREAMS_BOOST_HAS_NOTHROW_CONSTRUCTOR(T)
      >::value));
};

}

STREAMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(has_nothrow_constructor,T,::streams_boost::detail::has_nothrow_constructor_imp<T>::value)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(has_nothrow_default_constructor,T,::streams_boost::detail::has_nothrow_constructor_imp<T>::value)

} // namespace streams_boost

#include <streams_boost/type_traits/detail/bool_trait_undef.hpp>

#endif // STREAMS_BOOST_TT_HAS_NOTHROW_CONSTRUCTOR_HPP_INCLUDED
