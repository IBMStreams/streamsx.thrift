
//  (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt).
//
//  See http://www.streams_boost.org/libs/type_traits for most recent version including documentation.

#ifndef STREAMS_BOOST_TT_REMOVE_POINTER_HPP_INCLUDED
#define STREAMS_BOOST_TT_REMOVE_POINTER_HPP_INCLUDED

#include <streams_boost/type_traits/broken_compiler_spec.hpp>
#include <streams_boost/config.hpp>
#include <streams_boost/detail/workaround.hpp>

#if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC,<=1300)
#include <streams_boost/type_traits/msvc/remove_pointer.hpp>
#endif

// should be the last #include
#include <streams_boost/type_traits/detail/type_trait_def.hpp>

namespace streams_boost {

#ifndef STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

STREAMS_BOOST_TT_AUX_TYPE_TRAIT_DEF1(remove_pointer,T,T)
STREAMS_BOOST_TT_AUX_TYPE_TRAIT_PARTIAL_SPEC1_1(typename T,remove_pointer,T*,T)
STREAMS_BOOST_TT_AUX_TYPE_TRAIT_PARTIAL_SPEC1_1(typename T,remove_pointer,T* const,T)
STREAMS_BOOST_TT_AUX_TYPE_TRAIT_PARTIAL_SPEC1_1(typename T,remove_pointer,T* volatile,T)
STREAMS_BOOST_TT_AUX_TYPE_TRAIT_PARTIAL_SPEC1_1(typename T,remove_pointer,T* const volatile,T)

#elif !STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC,<=1300)

STREAMS_BOOST_TT_AUX_TYPE_TRAIT_DEF1(remove_pointer,T,typename streams_boost::detail::remove_pointer_impl<T>::type)

#endif

} // namespace streams_boost

#include <streams_boost/type_traits/detail/type_trait_undef.hpp>

#endif // STREAMS_BOOST_TT_REMOVE_POINTER_HPP_INCLUDED
