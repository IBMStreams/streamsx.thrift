
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


#ifndef STREAMS_BOOST_TT_IS_VOLATILE_HPP_INCLUDED
#define STREAMS_BOOST_TT_IS_VOLATILE_HPP_INCLUDED

#include <streams_boost/config.hpp>
#include <streams_boost/detail/workaround.hpp>

#ifndef STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
#   include <streams_boost/type_traits/detail/cv_traits_impl.hpp>
#   if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, < 1400)
#       include <streams_boost/type_traits/remove_bounds.hpp>
#   endif
#else
#   include <streams_boost/type_traits/is_reference.hpp>
#   include <streams_boost/type_traits/is_array.hpp>
#   include <streams_boost/type_traits/detail/yes_no_type.hpp>
#   include <streams_boost/type_traits/detail/false_result.hpp>
#endif

// should be the last #include
#include <streams_boost/type_traits/detail/bool_trait_def.hpp>

namespace streams_boost {

#if defined( __CODEGEARC__ )
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_volatile,T,__is_volatile(T))
#elif !defined(STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)

//* is a type T declared volatile - is_volatile<T>
#if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, < 1400)
   STREAMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_volatile,T,::streams_boost::detail::cv_traits_imp<typename streams_boost::remove_bounds<T>::type*>::is_volatile)
#else
   STREAMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_volatile,T,::streams_boost::detail::cv_traits_imp<T*>::is_volatile)
#endif
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_PARTIAL_SPEC1_1(typename T,is_volatile,T&,false)

#if  defined(STREAMS_BOOST_ILLEGAL_CV_REFERENCES)
// these are illegal specialisations; cv-qualifies applied to
// references have no effect according to [8.3.2p1],
// C++ Builder requires them though as it treats cv-qualified
// references as distinct types...
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_PARTIAL_SPEC1_1(typename T,is_volatile,T& const,false)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_PARTIAL_SPEC1_1(typename T,is_volatile,T& volatile,false)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_PARTIAL_SPEC1_1(typename T,is_volatile,T& const volatile,false)
#endif

#else

namespace detail {

using ::streams_boost::type_traits::yes_type;
using ::streams_boost::type_traits::no_type;

yes_type is_volatile_tester(void const volatile*);
no_type is_volatile_tester(void const*);

template <bool is_ref, bool array>
struct is_volatile_helper
    : ::streams_boost::type_traits::false_result
{
};

template <>
struct is_volatile_helper<false,false>
{
    template <typename T> struct result_
    {
        static T* t;
        STREAMS_BOOST_STATIC_CONSTANT(bool, value = (
            sizeof(detail::yes_type) == sizeof(detail::is_volatile_tester(t))
            ));
    };
};

template <>
struct is_volatile_helper<false,true>
{
    template <typename T> struct result_
    {
        static T t;
        STREAMS_BOOST_STATIC_CONSTANT(bool, value = (
            sizeof(detail::yes_type) == sizeof(detail::is_volatile_tester(&t))
            ));
    };
};

template <typename T>
struct is_volatile_impl
    : is_volatile_helper<
          is_reference<T>::value
        , is_array<T>::value
        >::template result_<T>
{
};

STREAMS_BOOST_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_volatile,void,false)
#ifndef STREAMS_BOOST_NO_CV_VOID_SPECIALIZATIONS
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_volatile,void const,false)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_volatile,void volatile,true)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_volatile,void const volatile,true)
#endif

} // namespace detail

//* is a type T declared volatile - is_volatile<T>
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_volatile,T,::streams_boost::detail::is_volatile_impl<T>::value)

#endif // STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

} // namespace streams_boost

#include <streams_boost/type_traits/detail/bool_trait_undef.hpp>

#endif // STREAMS_BOOST_TT_IS_VOLATILE_HPP_INCLUDED
