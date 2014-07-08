
//  (C) Copyright Dave Abrahams, Steve Cleary, Beman Dawes, Howard
//  Hinnant & John Maddock 2000.  
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt).
//
//  See http://www.streams_boost.org/libs/type_traits for most recent version including documentation.


#ifndef STREAMS_BOOST_TT_IS_ENUM_HPP_INCLUDED
#define STREAMS_BOOST_TT_IS_ENUM_HPP_INCLUDED

#include <streams_boost/type_traits/intrinsics.hpp>
#ifndef STREAMS_BOOST_IS_ENUM
#include <streams_boost/type_traits/add_reference.hpp>
#include <streams_boost/type_traits/is_arithmetic.hpp>
#include <streams_boost/type_traits/is_reference.hpp>
#include <streams_boost/type_traits/is_convertible.hpp>
#include <streams_boost/type_traits/is_array.hpp>
#ifdef __GNUC__
#include <streams_boost/type_traits/is_function.hpp>
#endif
#include <streams_boost/type_traits/config.hpp>
#if defined(STREAMS_BOOST_TT_HAS_CONFORMING_IS_CLASS_IMPLEMENTATION) 
#  include <streams_boost/type_traits/is_class.hpp>
#  include <streams_boost/type_traits/is_union.hpp>
#endif
#endif

// should be the last #include
#include <streams_boost/type_traits/detail/bool_trait_def.hpp>

namespace streams_boost {

#ifndef STREAMS_BOOST_IS_ENUM
#if !(defined(__BORLANDC__) && (__BORLANDC__ <= 0x551))

namespace detail {

#if defined(STREAMS_BOOST_TT_HAS_CONFORMING_IS_CLASS_IMPLEMENTATION) 

template <typename T>
struct is_class_or_union
{
   STREAMS_BOOST_STATIC_CONSTANT(bool, value =
      (::streams_boost::type_traits::ice_or<
           ::streams_boost::is_class<T>::value
         , ::streams_boost::is_union<T>::value
      >::value));
};

#else

template <typename T>
struct is_class_or_union
{
# if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, < 1300) || STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x581))// we simply can't detect it this way.
    STREAMS_BOOST_STATIC_CONSTANT(bool, value = false);
# else
    template <class U> static ::streams_boost::type_traits::yes_type is_class_or_union_tester(void(U::*)(void));

#  if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, == 1300)                 \
    || STREAMS_BOOST_WORKAROUND(__MWERKS__, <= 0x3000) // no SFINAE
    static ::streams_boost::type_traits::no_type is_class_or_union_tester(...);
    STREAMS_BOOST_STATIC_CONSTANT(
        bool, value = sizeof(is_class_or_union_tester(0)) == sizeof(::streams_boost::type_traits::yes_type));
#  else
    template <class U>
    static ::streams_boost::type_traits::no_type is_class_or_union_tester(...);
    STREAMS_BOOST_STATIC_CONSTANT(
        bool, value = sizeof(is_class_or_union_tester<T>(0)) == sizeof(::streams_boost::type_traits::yes_type));
#  endif
# endif
};
#endif

struct int_convertible
{
    int_convertible(int);
};

// Don't evaluate convertibility to int_convertible unless the type
// is non-arithmetic. This suppresses warnings with GCC.
template <bool is_typename_arithmetic_or_reference = true>
struct is_enum_helper
{
    template <typename T> struct type
    {
        STREAMS_BOOST_STATIC_CONSTANT(bool, value = false);
    };
};

template <>
struct is_enum_helper<false>
{
    template <typename T> struct type
       : ::streams_boost::is_convertible<typename streams_boost::add_reference<T>::type,::streams_boost::detail::int_convertible>
    {
    };
};

template <typename T> struct is_enum_impl
{
   //typedef ::streams_boost::add_reference<T> ar_t;
   //typedef typename ar_t::type r_type;

#if defined(__GNUC__)

#ifdef STREAMS_BOOST_TT_HAS_CONFORMING_IS_CLASS_IMPLEMENTATION
    
   // We MUST check for is_class_or_union on conforming compilers in
   // order to correctly deduce that noncopyable types are not enums
   // (dwa 2002/04/15)...
   STREAMS_BOOST_STATIC_CONSTANT(bool, selector =
      (::streams_boost::type_traits::ice_or<
           ::streams_boost::is_arithmetic<T>::value
         , ::streams_boost::is_reference<T>::value
         , ::streams_boost::is_function<T>::value
         , is_class_or_union<T>::value
         , is_array<T>::value
      >::value));
#else
   // ...however, not checking is_class_or_union on non-conforming
   // compilers prevents a dependency recursion.
   STREAMS_BOOST_STATIC_CONSTANT(bool, selector =
      (::streams_boost::type_traits::ice_or<
           ::streams_boost::is_arithmetic<T>::value
         , ::streams_boost::is_reference<T>::value
         , ::streams_boost::is_function<T>::value
         , is_array<T>::value
      >::value));
#endif // STREAMS_BOOST_TT_HAS_CONFORMING_IS_CLASS_IMPLEMENTATION

#else // !defined(__GNUC__):
    
   STREAMS_BOOST_STATIC_CONSTANT(bool, selector =
      (::streams_boost::type_traits::ice_or<
           ::streams_boost::is_arithmetic<T>::value
         , ::streams_boost::is_reference<T>::value
         , is_class_or_union<T>::value
         , is_array<T>::value
      >::value));
    
#endif

#if STREAMS_BOOST_WORKAROUND(__BORLANDC__, < 0x600)
    typedef ::streams_boost::detail::is_enum_helper<
          ::streams_boost::detail::is_enum_impl<T>::selector
        > se_t;
#else
    typedef ::streams_boost::detail::is_enum_helper<selector> se_t;
#endif

    typedef typename se_t::template type<T> helper;
    STREAMS_BOOST_STATIC_CONSTANT(bool, value = helper::value);
};

// these help on compilers with no partial specialization support:
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_enum,void,false)
#ifndef STREAMS_BOOST_NO_CV_VOID_SPECIALIZATIONS
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_enum,void const,false)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_enum,void volatile,false)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_enum,void const volatile,false)
#endif

} // namespace detail

STREAMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_enum,T,::streams_boost::detail::is_enum_impl<T>::value)

#else // __BORLANDC__
//
// buggy is_convertible prevents working
// implementation of is_enum:
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_enum,T,false)

#endif

#else // STREAMS_BOOST_IS_ENUM

STREAMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_enum,T,STREAMS_BOOST_IS_ENUM(T))

#endif

} // namespace streams_boost

#include <streams_boost/type_traits/detail/bool_trait_undef.hpp>

#endif // STREAMS_BOOST_TT_IS_ENUM_HPP_INCLUDED
