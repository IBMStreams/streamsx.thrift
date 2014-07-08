
//  (C) Copyright Dave Abrahams, Steve Cleary, Beman Dawes, Howard
//  Hinnant & John Maddock 2000.  
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt).
//
//  See http://www.streams_boost.org/libs/type_traits for most recent version including documentation.


#ifndef STREAMS_BOOST_TT_ADD_CV_HPP_INCLUDED
#define STREAMS_BOOST_TT_ADD_CV_HPP_INCLUDED

#include <streams_boost/config.hpp>

// should be the last #include
#include <streams_boost/type_traits/detail/type_trait_def.hpp>

namespace streams_boost {

// * convert a type T to a const volatile type - add_cv<T>
// this is not required since the result is always
// the same as "T const volatile", but it does suppress warnings
// from some compilers:

#if defined(STREAMS_BOOST_MSVC)
// This bogus warning will appear when add_volatile is applied to a
// const volatile reference because we can't detect const volatile
// references with MSVC6.
#   pragma warning(push)
#   pragma warning(disable:4181) // warning C4181: qualifier applied to reference type ignored
#endif 

STREAMS_BOOST_TT_AUX_TYPE_TRAIT_DEF1(add_cv,T,T const volatile)

#if defined(STREAMS_BOOST_MSVC)
#   pragma warning(pop)
#endif 

#ifndef STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
STREAMS_BOOST_TT_AUX_TYPE_TRAIT_PARTIAL_SPEC1_1(typename T,add_cv,T&,T&)
#endif

} // namespace streams_boost

#include <streams_boost/type_traits/detail/type_trait_undef.hpp>

#endif // STREAMS_BOOST_TT_ADD_CV_HPP_INCLUDED
