
//  (C) Copyright Dave Abrahams, Steve Cleary, Beman Dawes, 
//      Howard Hinnant and John Maddock 2000. 
//  (C) Copyright Mat Marcus, Jesse Jones and Adobe Systems Inc 2001

//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt).
//
//  See http://www.streams_boost.org/libs/type_traits for most recent version including documentation.

//    Fixed is_pointer, is_reference, is_const, is_volatile, is_same, 
//    is_member_pointer based on the Simulated Partial Specialization work 
//    of Mat Marcus and Jesse Jones. See  http://opensource.adobe.com or 
//    http://groups.yahoo.com/group/streams_boost/message/5441 
//    Some workarounds in here use ideas suggested from "Generic<Programming>: 
//    Mappings between Types and Values" 
//    by Andrei Alexandrescu (see http://www.cuj.com/experts/1810/alexandr.html).


#ifndef STREAMS_BOOST_TT_IS_REFERENCE_HPP_INCLUDED
#define STREAMS_BOOST_TT_IS_REFERENCE_HPP_INCLUDED

#include <streams_boost/type_traits/config.hpp>

#ifdef STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
#   include <streams_boost/type_traits/detail/yes_no_type.hpp>
#   include <streams_boost/type_traits/detail/wrap.hpp>
#endif

// should be the last #include
#include <streams_boost/type_traits/detail/bool_trait_def.hpp>

namespace streams_boost {

#if defined( __CODEGEARC__ )
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_reference,T,__is_reference(T))
#elif !defined(STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)

STREAMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_reference,T,false)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_PARTIAL_SPEC1_1(typename T,is_reference,T&,true)

#if  defined(STREAMS_BOOST_ILLEGAL_CV_REFERENCES)
// these are illegal specialisations; cv-qualifies applied to
// references have no effect according to [8.3.2p1],
// C++ Builder requires them though as it treats cv-qualified
// references as distinct types...
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_PARTIAL_SPEC1_1(typename T,is_reference,T& const,true)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_PARTIAL_SPEC1_1(typename T,is_reference,T& volatile,true)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_PARTIAL_SPEC1_1(typename T,is_reference,T& const volatile,true)
#endif

#if defined(__GNUC__) && (__GNUC__ < 3)
// these allow us to work around illegally cv-qualified reference
// types.
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_PARTIAL_SPEC1_1(typename T,is_reference,T const ,::streams_boost::is_reference<T>::value)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_PARTIAL_SPEC1_1(typename T,is_reference,T volatile ,::streams_boost::is_reference<T>::value)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_PARTIAL_SPEC1_1(typename T,is_reference,T const volatile ,::streams_boost::is_reference<T>::value)
// However, the above specializations confuse gcc 2.96 unless we also
// supply these specializations for array types
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_PARTIAL_SPEC1_2(typename T,unsigned long N,is_reference,T[N],false)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_PARTIAL_SPEC1_2(typename T,unsigned long N,is_reference,const T[N],false)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_PARTIAL_SPEC1_2(typename T,unsigned long N,is_reference,volatile T[N],false)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_PARTIAL_SPEC1_2(typename T,unsigned long N,is_reference,const volatile T[N],false)
#endif

#else

#ifdef STREAMS_BOOST_MSVC
#   pragma warning(push)
#   pragma warning(disable: 4181 4097)
#endif

namespace detail {

using ::streams_boost::type_traits::yes_type;
using ::streams_boost::type_traits::no_type;
using ::streams_boost::type_traits::wrap;

template <class T> T&(* is_reference_helper1(wrap<T>) )(wrap<T>);
char is_reference_helper1(...);

template <class T> no_type is_reference_helper2(T&(*)(wrap<T>));
yes_type is_reference_helper2(...);

template <typename T>
struct is_reference_impl
{
    STREAMS_BOOST_STATIC_CONSTANT(
        bool, value = sizeof(
            ::streams_boost::detail::is_reference_helper2(
                ::streams_boost::detail::is_reference_helper1(::streams_boost::type_traits::wrap<T>()))) == 1
        );
};

STREAMS_BOOST_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_reference,void,false)
#ifndef STREAMS_BOOST_NO_CV_VOID_SPECIALIZATIONS
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_reference,void const,false)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_reference,void volatile,false)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_reference,void const volatile,false)
#endif

} // namespace detail

STREAMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_reference,T,::streams_boost::detail::is_reference_impl<T>::value)

#ifdef STREAMS_BOOST_MSVC
#   pragma warning(pop)
#endif

#endif // STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

} // namespace streams_boost

#include <streams_boost/type_traits/detail/bool_trait_undef.hpp>

#endif // STREAMS_BOOST_TT_IS_REFERENCE_HPP_INCLUDED

