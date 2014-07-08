
//  (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt).
//
//  See http://www.streams_boost.org/libs/type_traits for most recent version including documentation.

#ifndef STREAMS_BOOST_TT_IS_VOID_HPP_INCLUDED
#define STREAMS_BOOST_TT_IS_VOID_HPP_INCLUDED

#include <streams_boost/config.hpp>

// should be the last #include
#include <streams_boost/type_traits/detail/bool_trait_def.hpp>

namespace streams_boost {

//* is a type T void - is_void<T>
#if defined( __CODEGEARC__ )
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_void,T,__is_void(T))
#else
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_void,T,false)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_SPEC1(is_void,void,true)

#ifndef STREAMS_BOOST_NO_CV_VOID_SPECIALIZATIONS
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_SPEC1(is_void,void const,true)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_SPEC1(is_void,void volatile,true)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_SPEC1(is_void,void const volatile,true)
#endif

#endif  // non-CodeGear implementation

} // namespace streams_boost

#include <streams_boost/type_traits/detail/bool_trait_undef.hpp>

#endif // STREAMS_BOOST_TT_IS_VOID_HPP_INCLUDED
