
//  (C) Copyright Dave Abrahams, Steve Cleary, Beman Dawes, Howard
//  Hinnant & John Maddock 2000.  
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt).
//
//  See http://www.streams_boost.org/libs/type_traits for most recent version including documentation.


// Some fixes for is_array are based on a newgroup posting by Jonathan Lundquist.


#ifndef STREAMS_BOOST_TT_IS_ARRAY_HPP_INCLUDED
#define STREAMS_BOOST_TT_IS_ARRAY_HPP_INCLUDED

#include <streams_boost/type_traits/config.hpp>

#ifdef STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
#   include <streams_boost/type_traits/detail/yes_no_type.hpp>
#   include <streams_boost/type_traits/detail/wrap.hpp>
#endif

#include <cstddef>

// should be the last #include
#include <streams_boost/type_traits/detail/bool_trait_def.hpp>

namespace streams_boost {

#if defined( __CODEGEARC__ )
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_array,T,__is_array(T))
#elif !defined(STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_array,T,false)
#if !defined(STREAMS_BOOST_NO_ARRAY_TYPE_SPECIALIZATIONS)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_PARTIAL_SPEC1_2(typename T,std::size_t N,is_array,T[N],true)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_PARTIAL_SPEC1_2(typename T,std::size_t N,is_array,T const[N],true)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_PARTIAL_SPEC1_2(typename T,std::size_t N,is_array,T volatile[N],true)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_PARTIAL_SPEC1_2(typename T,std::size_t N,is_array,T const volatile[N],true)
#if !STREAMS_BOOST_WORKAROUND(__BORLANDC__, < 0x600) && !defined(__IBMCPP__) &&  !STREAMS_BOOST_WORKAROUND(__DMC__, STREAMS_BOOST_TESTED_AT(0x840))
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_PARTIAL_SPEC1_1(typename T,is_array,T[],true)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_PARTIAL_SPEC1_1(typename T,is_array,T const[],true)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_PARTIAL_SPEC1_1(typename T,is_array,T volatile[],true)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_PARTIAL_SPEC1_1(typename T,is_array,T const volatile[],true)
#endif
#endif

#else // STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

namespace detail {

using ::streams_boost::type_traits::yes_type;
using ::streams_boost::type_traits::no_type;
using ::streams_boost::type_traits::wrap;

template< typename T > T(* is_array_tester1(wrap<T>) )(wrap<T>);
char STREAMS_BOOST_TT_DECL is_array_tester1(...);

template< typename T> no_type is_array_tester2(T(*)(wrap<T>));
yes_type STREAMS_BOOST_TT_DECL is_array_tester2(...);

template< typename T >
struct is_array_impl
{ 
    STREAMS_BOOST_STATIC_CONSTANT(bool, value = 
        sizeof(::streams_boost::detail::is_array_tester2(
            ::streams_boost::detail::is_array_tester1(
                ::streams_boost::type_traits::wrap<T>()
                )
        )) == 1
    );
};

#ifndef STREAMS_BOOST_NO_CV_VOID_SPECIALIZATIONS
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_array,void,false)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_array,void const,false)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_array,void volatile,false)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_array,void const volatile,false)
#endif

} // namespace detail

STREAMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_array,T,::streams_boost::detail::is_array_impl<T>::value)

#endif // STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

} // namespace streams_boost

#include <streams_boost/type_traits/detail/bool_trait_undef.hpp>

#endif // STREAMS_BOOST_TT_IS_ARRAY_HPP_INCLUDED
