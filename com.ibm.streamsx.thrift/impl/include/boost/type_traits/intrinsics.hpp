
//  (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt).
//
//  See http://www.streams_boost.org/libs/type_traits for most recent version including documentation.

#ifndef STREAMS_BOOST_TT_INTRINSICS_HPP_INCLUDED
#define STREAMS_BOOST_TT_INTRINSICS_HPP_INCLUDED

#ifndef STREAMS_BOOST_TT_CONFIG_HPP_INCLUDED
#include <streams_boost/type_traits/config.hpp>
#endif

//
// Helper macros for builtin compiler support.
// If your compiler has builtin support for any of the following
// traits concepts, then redefine the appropriate macros to pick
// up on the compiler support:
//
// (these should largely ignore cv-qualifiers)
// STREAMS_BOOST_IS_UNION(T) should evaluate to true if T is a union type
// STREAMS_BOOST_IS_POD(T) should evaluate to true if T is a POD type
// STREAMS_BOOST_IS_EMPTY(T) should evaluate to true if T is an empty struct or union
// STREAMS_BOOST_HAS_TRIVIAL_CONSTRUCTOR(T) should evaluate to true if "T x;" has no effect
// STREAMS_BOOST_HAS_TRIVIAL_COPY(T) should evaluate to true if T(t) <==> memcpy
// STREAMS_BOOST_HAS_TRIVIAL_ASSIGN(T) should evaluate to true if t = u <==> memcpy
// STREAMS_BOOST_HAS_TRIVIAL_DESTRUCTOR(T) should evaluate to true if ~T() has no effect
// STREAMS_BOOST_HAS_NOTHROW_CONSTRUCTOR(T) should evaluate to true if "T x;" can not throw
// STREAMS_BOOST_HAS_NOTHROW_COPY(T) should evaluate to true if T(t) can not throw
// STREAMS_BOOST_HAS_NOTHROW_ASSIGN(T) should evaluate to true if t = u can not throw
// STREAMS_BOOST_HAS_VIRTUAL_DESTRUCTOR(T) should evaluate to true T has a virtual destructor
//
// The following can also be defined: when detected our implementation is greatly simplified.
// Note that unlike the macros above these do not have default definitions, so we can use
// #ifdef MACRONAME to detect when these are available.
//
// STREAMS_BOOST_IS_ABSTRACT(T) true if T is an abstract type
// STREAMS_BOOST_IS_BASE_OF(T,U) true if T is a base class of U
// STREAMS_BOOST_IS_CLASS(T) true if T is a class type
// STREAMS_BOOST_IS_CONVERTIBLE(T,U) true if T is convertible to U
// STREAMS_BOOST_IS_ENUM(T) true is T is an enum
// STREAMS_BOOST_IS_POLYMORPHIC(T) true if T is a polymorphic type
// STREAMS_BOOST_ALIGNMENT_OF(T) should evaluate to the alignment requirements of type T.

#ifdef STREAMS_BOOST_HAS_SGI_TYPE_TRAITS
    // Hook into SGI's __type_traits class, this will pick up user supplied
    // specializations as well as SGI - compiler supplied specializations.
#   include <streams_boost/type_traits/is_same.hpp>
#   ifdef __NetBSD__
      // There are two different versions of type_traits.h on NetBSD on Spark
      // use an implicit include via algorithm instead, to make sure we get
      // the same version as the std lib:
#     include <algorithm>
#   else
#    include <type_traits.h>
#   endif
#   define STREAMS_BOOST_IS_POD(T) ::streams_boost::is_same< typename ::__type_traits<T>::is_POD_type, ::__true_type>::value
#   define STREAMS_BOOST_HAS_TRIVIAL_CONSTRUCTOR(T) ::streams_boost::is_same< typename ::__type_traits<T>::has_trivial_default_constructor, ::__true_type>::value
#   define STREAMS_BOOST_HAS_TRIVIAL_COPY(T) ::streams_boost::is_same< typename ::__type_traits<T>::has_trivial_copy_constructor, ::__true_type>::value
#   define STREAMS_BOOST_HAS_TRIVIAL_ASSIGN(T) ::streams_boost::is_same< typename ::__type_traits<T>::has_trivial_assignment_operator, ::__true_type>::value
#   define STREAMS_BOOST_HAS_TRIVIAL_DESTRUCTOR(T) ::streams_boost::is_same< typename ::__type_traits<T>::has_trivial_destructor, ::__true_type>::value

#   ifdef __sgi
#      define STREAMS_BOOST_HAS_TYPE_TRAITS_INTRINSICS
#   endif
#endif

#if defined(__MSL_CPP__) && (__MSL_CPP__ >= 0x8000)
    // Metrowerks compiler is acquiring intrinsic type traits support
    // post version 8.  We hook into the published interface to pick up
    // user defined specializations as well as compiler intrinsics as 
    // and when they become available:
#   include <msl_utility>
#   define STREAMS_BOOST_IS_UNION(T) STREAMS_BOOST_STD_EXTENSION_NAMESPACE::is_union<T>::value
#   define STREAMS_BOOST_IS_POD(T) STREAMS_BOOST_STD_EXTENSION_NAMESPACE::is_POD<T>::value
#   define STREAMS_BOOST_HAS_TRIVIAL_CONSTRUCTOR(T) STREAMS_BOOST_STD_EXTENSION_NAMESPACE::has_trivial_default_ctor<T>::value
#   define STREAMS_BOOST_HAS_TRIVIAL_COPY(T) STREAMS_BOOST_STD_EXTENSION_NAMESPACE::has_trivial_copy_ctor<T>::value
#   define STREAMS_BOOST_HAS_TRIVIAL_ASSIGN(T) STREAMS_BOOST_STD_EXTENSION_NAMESPACE::has_trivial_assignment<T>::value
#   define STREAMS_BOOST_HAS_TRIVIAL_DESTRUCTOR(T) STREAMS_BOOST_STD_EXTENSION_NAMESPACE::has_trivial_dtor<T>::value
#   define STREAMS_BOOST_HAS_TYPE_TRAITS_INTRINSICS
#endif

#if defined(STREAMS_BOOST_MSVC) && defined(STREAMS_BOOST_MSVC_FULL_VER) && (STREAMS_BOOST_MSVC_FULL_VER >=140050215)
#   include <streams_boost/type_traits/is_same.hpp>

#   define STREAMS_BOOST_IS_UNION(T) __is_union(T)
#   define STREAMS_BOOST_IS_POD(T) (__is_pod(T) && __has_trivial_constructor(T))
#   define STREAMS_BOOST_IS_EMPTY(T) __is_empty(T)
#   define STREAMS_BOOST_HAS_TRIVIAL_CONSTRUCTOR(T) __has_trivial_constructor(T)
#   define STREAMS_BOOST_HAS_TRIVIAL_COPY(T) __has_trivial_copy(T)
#   define STREAMS_BOOST_HAS_TRIVIAL_ASSIGN(T) __has_trivial_assign(T)
#   define STREAMS_BOOST_HAS_TRIVIAL_DESTRUCTOR(T) __has_trivial_destructor(T)
#   define STREAMS_BOOST_HAS_NOTHROW_CONSTRUCTOR(T) __has_nothrow_constructor(T)
#   define STREAMS_BOOST_HAS_NOTHROW_COPY(T) __has_nothrow_copy(T)
#   define STREAMS_BOOST_HAS_NOTHROW_ASSIGN(T) __has_nothrow_assign(T)
#   define STREAMS_BOOST_HAS_VIRTUAL_DESTRUCTOR(T) __has_virtual_destructor(T)

#   define STREAMS_BOOST_IS_ABSTRACT(T) __is_abstract(T)
#   define STREAMS_BOOST_IS_BASE_OF(T,U) (__is_base_of(T,U) && !is_same<T,U>::value)
#   define STREAMS_BOOST_IS_CLASS(T) __is_class(T)
//  This one doesn't quite always do the right thing:
//  #   define STREAMS_BOOST_IS_CONVERTIBLE(T,U) __is_convertible_to(T,U)
#   define STREAMS_BOOST_IS_ENUM(T) __is_enum(T)
//  This one doesn't quite always do the right thing:
//  #   define STREAMS_BOOST_IS_POLYMORPHIC(T) __is_polymorphic(T)
//  This one fails if the default alignment has been changed with /Zp:
//  #   define STREAMS_BOOST_ALIGNMENT_OF(T) __alignof(T)

#   define STREAMS_BOOST_HAS_TYPE_TRAITS_INTRINSICS
#endif

#if defined(__DMC__) && (__DMC__ >= 0x848)
// For Digital Mars C++, www.digitalmars.com
#   define STREAMS_BOOST_IS_UNION(T) (__typeinfo(T) & 0x400)
#   define STREAMS_BOOST_IS_POD(T) (__typeinfo(T) & 0x800)
#   define STREAMS_BOOST_IS_EMPTY(T) (__typeinfo(T) & 0x1000)
#   define STREAMS_BOOST_HAS_TRIVIAL_CONSTRUCTOR(T) (__typeinfo(T) & 0x10)
#   define STREAMS_BOOST_HAS_TRIVIAL_COPY(T) (__typeinfo(T) & 0x20)
#   define STREAMS_BOOST_HAS_TRIVIAL_ASSIGN(T) (__typeinfo(T) & 0x40)
#   define STREAMS_BOOST_HAS_TRIVIAL_DESTRUCTOR(T) (__typeinfo(T) & 0x8)
#   define STREAMS_BOOST_HAS_NOTHROW_CONSTRUCTOR(T) (__typeinfo(T) & 0x80)
#   define STREAMS_BOOST_HAS_NOTHROW_COPY(T) (__typeinfo(T) & 0x100)
#   define STREAMS_BOOST_HAS_NOTHROW_ASSIGN(T) (__typeinfo(T) & 0x200)
#   define STREAMS_BOOST_HAS_VIRTUAL_DESTRUCTOR(T) (__typeinfo(T) & 0x4)
#   define STREAMS_BOOST_HAS_TYPE_TRAITS_INTRINSICS
#endif

#if defined(__GNUC__) && ((__GNUC__ > 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 3) && !defined(__GCCXML__)))
#   include <streams_boost/type_traits/is_same.hpp>
#   include <streams_boost/type_traits/is_reference.hpp>
#   include <streams_boost/type_traits/is_volatile.hpp>

#   define STREAMS_BOOST_IS_UNION(T) __is_union(T)
#   define STREAMS_BOOST_IS_POD(T) __is_pod(T)
#   define STREAMS_BOOST_IS_EMPTY(T) __is_empty(T)
#   define STREAMS_BOOST_HAS_TRIVIAL_CONSTRUCTOR(T) __has_trivial_constructor(T)
#   define STREAMS_BOOST_HAS_TRIVIAL_COPY(T) (__has_trivial_copy(T) && !is_reference<T>::value)
#   define STREAMS_BOOST_HAS_TRIVIAL_ASSIGN(T) __has_trivial_assign(T)
#   define STREAMS_BOOST_HAS_TRIVIAL_DESTRUCTOR(T) __has_trivial_destructor(T)
#   define STREAMS_BOOST_HAS_NOTHROW_CONSTRUCTOR(T) __has_nothrow_constructor(T)
#   define STREAMS_BOOST_HAS_NOTHROW_COPY(T) (__has_nothrow_copy(T) && !is_volatile<T>::value && !is_reference<T>::value)
#   define STREAMS_BOOST_HAS_NOTHROW_ASSIGN(T) (__has_nothrow_assign(T) && !is_volatile<T>::value)
#   define STREAMS_BOOST_HAS_VIRTUAL_DESTRUCTOR(T) __has_virtual_destructor(T)

#   define STREAMS_BOOST_IS_ABSTRACT(T) __is_abstract(T)
#   define STREAMS_BOOST_IS_BASE_OF(T,U) (__is_base_of(T,U) && !is_same<T,U>::value)
#   define STREAMS_BOOST_IS_CLASS(T) __is_class(T)
#   define STREAMS_BOOST_IS_ENUM(T) __is_enum(T)
#   define STREAMS_BOOST_IS_POLYMORPHIC(T) __is_polymorphic(T)
#   if (!defined(unix) && !defined(__unix__)) || defined(__LP64__)
      // GCC sometimes lies about alignment requirements
      // of type double on 32-bit unix platforms, use the
      // old implementation instead in that case:
#     define STREAMS_BOOST_ALIGNMENT_OF(T) __alignof__(T)
#   endif

#   define STREAMS_BOOST_HAS_TYPE_TRAITS_INTRINSICS
#endif

# if defined(__CODEGEARC__)
#   include <streams_boost/type_traits/is_same.hpp>
#   include <streams_boost/type_traits/is_reference.hpp>
#   include <streams_boost/type_traits/is_volatile.hpp>
#   include <streams_boost/type_traits/is_void.hpp>

#   define STREAMS_BOOST_IS_UNION(T) __is_union(T)
#   define STREAMS_BOOST_IS_POD(T) __is_pod(T)
#   define STREAMS_BOOST_IS_EMPTY(T) __is_empty(T)
#   define STREAMS_BOOST_HAS_TRIVIAL_CONSTRUCTOR(T) (__has_trivial_default_constructor(T) || is_void<T>::value)
#   define STREAMS_BOOST_HAS_TRIVIAL_COPY(T) (__has_trivial_copy_constructor(T) && !is_volatile<T>::value && !is_reference<T>::value || is_void<T>::value)
#   define STREAMS_BOOST_HAS_TRIVIAL_ASSIGN(T) (__has_trivial_assign(T) && !is_volatile<T>::value || is_void<T>::value)
#   define STREAMS_BOOST_HAS_TRIVIAL_DESTRUCTOR(T) (__has_trivial_destructor(T) || is_void<T>::value)
#   define STREAMS_BOOST_HAS_NOTHROW_CONSTRUCTOR(T) (__has_nothrow_default_constructor(T) || is_void<T>::value)
#   define STREAMS_BOOST_HAS_NOTHROW_COPY(T) (__has_nothrow_copy_constructor(T) && !is_volatile<T>::value && !is_reference<T>::value || is_void<T>::value)
#   define STREAMS_BOOST_HAS_NOTHROW_ASSIGN(T) (__has_nothrow_assign(T) && !is_volatile<T>::value || is_void<T>::value)
#   define STREAMS_BOOST_HAS_VIRTUAL_DESTRUCTOR(T) __has_virtual_destructor(T)

#   define STREAMS_BOOST_IS_ABSTRACT(T) __is_abstract(T)
#   define STREAMS_BOOST_IS_BASE_OF(T,U) (__is_base_of(T,U) && !is_void<T>::value && !is_void<U>::value)
#   define STREAMS_BOOST_IS_CLASS(T) __is_class(T)
#   define STREAMS_BOOST_IS_CONVERTIBLE(T,U) (__is_convertible(T,U) || is_void<U>::value)
#   define STREAMS_BOOST_IS_ENUM(T) __is_enum(T)
#   define STREAMS_BOOST_IS_POLYMORPHIC(T) __is_polymorphic(T)
#   define STREAMS_BOOST_ALIGNMENT_OF(T) alignof(T)

#   define STREAMS_BOOST_HAS_TYPE_TRAITS_INTRINSICS
#endif

#ifndef STREAMS_BOOST_IS_UNION
#   define STREAMS_BOOST_IS_UNION(T) false
#endif

#ifndef STREAMS_BOOST_IS_POD
#   define STREAMS_BOOST_IS_POD(T) false
#endif

#ifndef STREAMS_BOOST_IS_EMPTY
#   define STREAMS_BOOST_IS_EMPTY(T) false
#endif

#ifndef STREAMS_BOOST_HAS_TRIVIAL_CONSTRUCTOR
#   define STREAMS_BOOST_HAS_TRIVIAL_CONSTRUCTOR(T) false
#endif

#ifndef STREAMS_BOOST_HAS_TRIVIAL_COPY
#   define STREAMS_BOOST_HAS_TRIVIAL_COPY(T) false
#endif

#ifndef STREAMS_BOOST_HAS_TRIVIAL_ASSIGN
#   define STREAMS_BOOST_HAS_TRIVIAL_ASSIGN(T) false
#endif

#ifndef STREAMS_BOOST_HAS_TRIVIAL_DESTRUCTOR
#   define STREAMS_BOOST_HAS_TRIVIAL_DESTRUCTOR(T) false
#endif

#ifndef STREAMS_BOOST_HAS_NOTHROW_CONSTRUCTOR
#   define STREAMS_BOOST_HAS_NOTHROW_CONSTRUCTOR(T) false
#endif

#ifndef STREAMS_BOOST_HAS_NOTHROW_COPY
#   define STREAMS_BOOST_HAS_NOTHROW_COPY(T) false
#endif

#ifndef STREAMS_BOOST_HAS_NOTHROW_ASSIGN
#   define STREAMS_BOOST_HAS_NOTHROW_ASSIGN(T) false
#endif

#ifndef STREAMS_BOOST_HAS_VIRTUAL_DESTRUCTOR
#   define STREAMS_BOOST_HAS_VIRTUAL_DESTRUCTOR(T) false
#endif

#endif // STREAMS_BOOST_TT_INTRINSICS_HPP_INCLUDED





