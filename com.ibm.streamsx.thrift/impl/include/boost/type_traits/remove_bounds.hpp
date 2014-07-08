
//  (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt).
//
//  See http://www.streams_boost.org/libs/type_traits for most recent version including documentation.

#ifndef STREAMS_BOOST_TT_REMOVE_BOUNDS_HPP_INCLUDED
#define STREAMS_BOOST_TT_REMOVE_BOUNDS_HPP_INCLUDED

#include <streams_boost/config.hpp>
#include <cstddef>
#include <streams_boost/detail/workaround.hpp>

#if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC,<=1300)
#include <streams_boost/type_traits/msvc/remove_bounds.hpp>
#endif

// should be the last #include
#include <streams_boost/type_traits/detail/type_trait_def.hpp>

#if !STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC,<=1300)

namespace streams_boost {

STREAMS_BOOST_TT_AUX_TYPE_TRAIT_DEF1(remove_bounds,T,T)

#if !defined(STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION) && !defined(STREAMS_BOOST_NO_ARRAY_TYPE_SPECIALIZATIONS)
STREAMS_BOOST_TT_AUX_TYPE_TRAIT_PARTIAL_SPEC1_2(typename T,std::size_t N,remove_bounds,T[N],T type)
STREAMS_BOOST_TT_AUX_TYPE_TRAIT_PARTIAL_SPEC1_2(typename T,std::size_t N,remove_bounds,T const[N],T const type)
STREAMS_BOOST_TT_AUX_TYPE_TRAIT_PARTIAL_SPEC1_2(typename T,std::size_t N,remove_bounds,T volatile[N],T volatile type)
STREAMS_BOOST_TT_AUX_TYPE_TRAIT_PARTIAL_SPEC1_2(typename T,std::size_t N,remove_bounds,T const volatile[N],T const volatile type)
#if !STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x610)) && !defined(__IBMCPP__) &&  !STREAMS_BOOST_WORKAROUND(__DMC__, STREAMS_BOOST_TESTED_AT(0x840))
STREAMS_BOOST_TT_AUX_TYPE_TRAIT_PARTIAL_SPEC1_1(typename T,remove_bounds,T[],T)
STREAMS_BOOST_TT_AUX_TYPE_TRAIT_PARTIAL_SPEC1_1(typename T,remove_bounds,T const[],T const)
STREAMS_BOOST_TT_AUX_TYPE_TRAIT_PARTIAL_SPEC1_1(typename T,remove_bounds,T volatile[],T volatile)
STREAMS_BOOST_TT_AUX_TYPE_TRAIT_PARTIAL_SPEC1_1(typename T,remove_bounds,T const volatile[],T const volatile)
#endif
#endif

} // namespace streams_boost

#endif

#include <streams_boost/type_traits/detail/type_trait_undef.hpp>

#endif // STREAMS_BOOST_TT_REMOVE_BOUNDS_HPP_INCLUDED
