
//  Copyright 2001-2003 Aleksey Gurtovoy.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt).
//
//  See http://www.streams_boost.org/libs/type_traits for most recent version including documentation.

#ifndef STREAMS_BOOST_TT_BROKEN_COMPILER_SPEC_HPP_INCLUDED
#define STREAMS_BOOST_TT_BROKEN_COMPILER_SPEC_HPP_INCLUDED

#include <streams_boost/mpl/aux_/lambda_support.hpp>
#include <streams_boost/config.hpp>

// these are needed regardless of STREAMS_BOOST_TT_NO_BROKEN_COMPILER_SPEC 
#if defined(STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)
namespace streams_boost { namespace detail {
template< typename T > struct remove_const_impl     { typedef T type; };
template< typename T > struct remove_volatile_impl  { typedef T type; };
template< typename T > struct remove_pointer_impl   { typedef T type; };
template< typename T > struct remove_reference_impl { typedef T type; };
typedef int invoke_STREAMS_BOOST_TT_BROKEN_COMPILER_SPEC_outside_all_namespaces;
}}
#endif

// agurt, 27/jun/03: disable the workaround if user defined 
// STREAMS_BOOST_TT_NO_BROKEN_COMPILER_SPEC
#if    !defined(STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION) \
    || defined(STREAMS_BOOST_TT_NO_BROKEN_COMPILER_SPEC)

#   define STREAMS_BOOST_TT_BROKEN_COMPILER_SPEC(T) /**/

#else

// same as STREAMS_BOOST_TT_AUX_TYPE_TRAIT_IMPL_SPEC1 macro, except that it
// never gets #undef-ined
#   define STREAMS_BOOST_TT_AUX_BROKEN_TYPE_TRAIT_SPEC1(trait,spec,result) \
template<> struct trait##_impl<spec> \
{ \
    typedef result type; \
}; \
/**/

#   define STREAMS_BOOST_TT_AUX_REMOVE_CONST_VOLATILE_RANK1_SPEC(T)                         \
    STREAMS_BOOST_TT_AUX_BROKEN_TYPE_TRAIT_SPEC1(remove_const,T const,T)                    \
    STREAMS_BOOST_TT_AUX_BROKEN_TYPE_TRAIT_SPEC1(remove_const,T const volatile,T volatile)  \
    STREAMS_BOOST_TT_AUX_BROKEN_TYPE_TRAIT_SPEC1(remove_volatile,T volatile,T)              \
    STREAMS_BOOST_TT_AUX_BROKEN_TYPE_TRAIT_SPEC1(remove_volatile,T const volatile,T const)  \
    /**/

#   define STREAMS_BOOST_TT_AUX_REMOVE_PTR_REF_RANK_1_SPEC(T)                               \
    STREAMS_BOOST_TT_AUX_BROKEN_TYPE_TRAIT_SPEC1(remove_pointer,T*,T)                       \
    STREAMS_BOOST_TT_AUX_BROKEN_TYPE_TRAIT_SPEC1(remove_pointer,T*const,T)                  \
    STREAMS_BOOST_TT_AUX_BROKEN_TYPE_TRAIT_SPEC1(remove_pointer,T*volatile,T)               \
    STREAMS_BOOST_TT_AUX_BROKEN_TYPE_TRAIT_SPEC1(remove_pointer,T*const volatile,T)         \
    STREAMS_BOOST_TT_AUX_BROKEN_TYPE_TRAIT_SPEC1(remove_reference,T&,T)                     \
    /**/

#   define STREAMS_BOOST_TT_AUX_REMOVE_PTR_REF_RANK_2_SPEC(T)                               \
    STREAMS_BOOST_TT_AUX_REMOVE_PTR_REF_RANK_1_SPEC(T)                                      \
    STREAMS_BOOST_TT_AUX_REMOVE_PTR_REF_RANK_1_SPEC(T const)                                \
    STREAMS_BOOST_TT_AUX_REMOVE_PTR_REF_RANK_1_SPEC(T volatile)                             \
    STREAMS_BOOST_TT_AUX_REMOVE_PTR_REF_RANK_1_SPEC(T const volatile)                       \
    /**/

#   define STREAMS_BOOST_TT_AUX_REMOVE_ALL_RANK_1_SPEC(T)                                   \
    STREAMS_BOOST_TT_AUX_REMOVE_PTR_REF_RANK_2_SPEC(T)                                      \
    STREAMS_BOOST_TT_AUX_REMOVE_CONST_VOLATILE_RANK1_SPEC(T)                                \
    /**/

#   define STREAMS_BOOST_TT_AUX_REMOVE_ALL_RANK_2_SPEC(T)                                   \
    STREAMS_BOOST_TT_AUX_REMOVE_ALL_RANK_1_SPEC(T*)                                         \
    STREAMS_BOOST_TT_AUX_REMOVE_ALL_RANK_1_SPEC(T const*)                                   \
    STREAMS_BOOST_TT_AUX_REMOVE_ALL_RANK_1_SPEC(T volatile*)                                \
    STREAMS_BOOST_TT_AUX_REMOVE_ALL_RANK_1_SPEC(T const volatile*)                          \
    /**/

#   define STREAMS_BOOST_TT_BROKEN_COMPILER_SPEC(T)                                         \
    namespace streams_boost { namespace detail {                                            \
    typedef invoke_STREAMS_BOOST_TT_BROKEN_COMPILER_SPEC_outside_all_namespaces             \
      please_invoke_STREAMS_BOOST_TT_BROKEN_COMPILER_SPEC_outside_all_namespaces;           \
    STREAMS_BOOST_TT_AUX_REMOVE_ALL_RANK_1_SPEC(T)                                          \
    STREAMS_BOOST_TT_AUX_REMOVE_ALL_RANK_2_SPEC(T)                                          \
    STREAMS_BOOST_TT_AUX_REMOVE_ALL_RANK_2_SPEC(T*)                                         \
    STREAMS_BOOST_TT_AUX_REMOVE_ALL_RANK_2_SPEC(T const*)                                   \
    STREAMS_BOOST_TT_AUX_REMOVE_ALL_RANK_2_SPEC(T volatile*)                                \
    STREAMS_BOOST_TT_AUX_REMOVE_ALL_RANK_2_SPEC(T const volatile*)                          \
    }}                                                                              \
    /**/

#   include <streams_boost/type_traits/detail/type_trait_undef.hpp>

#endif // STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

STREAMS_BOOST_TT_BROKEN_COMPILER_SPEC(bool)
STREAMS_BOOST_TT_BROKEN_COMPILER_SPEC(char)
#ifndef STREAMS_BOOST_NO_INTRINSIC_WCHAR_T
STREAMS_BOOST_TT_BROKEN_COMPILER_SPEC(wchar_t)
#endif
STREAMS_BOOST_TT_BROKEN_COMPILER_SPEC(signed char)
STREAMS_BOOST_TT_BROKEN_COMPILER_SPEC(unsigned char)
STREAMS_BOOST_TT_BROKEN_COMPILER_SPEC(signed short)
STREAMS_BOOST_TT_BROKEN_COMPILER_SPEC(unsigned short)
STREAMS_BOOST_TT_BROKEN_COMPILER_SPEC(signed int)
STREAMS_BOOST_TT_BROKEN_COMPILER_SPEC(unsigned int)
STREAMS_BOOST_TT_BROKEN_COMPILER_SPEC(signed long)
STREAMS_BOOST_TT_BROKEN_COMPILER_SPEC(unsigned long)
STREAMS_BOOST_TT_BROKEN_COMPILER_SPEC(float)
STREAMS_BOOST_TT_BROKEN_COMPILER_SPEC(double)
//STREAMS_BOOST_TT_BROKEN_COMPILER_SPEC(long double)

// for backward compatibility
#define STREAMS_BOOST_BROKEN_COMPILER_TYPE_TRAITS_SPECIALIZATION(T) \
    STREAMS_BOOST_TT_BROKEN_COMPILER_SPEC(T) \
/**/

#endif // STREAMS_BOOST_TT_BROKEN_COMPILER_SPEC_HPP_INCLUDED
