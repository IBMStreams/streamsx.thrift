
//  (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000-2005.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt).
//
//  See http://www.streams_boost.org/libs/type_traits for most recent version including documentation.

#ifndef STREAMS_BOOST_TYPE_TRAITS_IS_FLOATING_HPP_INCLUDED
#define STREAMS_BOOST_TYPE_TRAITS_IS_FLOATING_HPP_INCLUDED

// should be the last #include
#include <streams_boost/type_traits/detail/bool_trait_def.hpp>

namespace streams_boost {

//* is a type T a floating-point type described in the standard (3.9.1p8)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_floating_point,T,false)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_floating_point,float,true)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_floating_point,double,true)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_floating_point,long double,true)

} // namespace streams_boost

#include <streams_boost/type_traits/detail/bool_trait_undef.hpp>

#endif // STREAMS_BOOST_TYPE_TRAITS_IS_FLOAT_HPP_INCLUDED
