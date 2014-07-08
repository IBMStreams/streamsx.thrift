//  (C) Copyright Dave Abrahams, Steve Cleary, Beman Dawes, Howard
//  Hinnant & John Maddock 2000-2003.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt).
//
//  See http://www.streams_boost.org/libs/type_traits for most recent version including documentation.


#ifndef STREAMS_BOOST_TT_IS_CLASS_HPP_INCLUDED
#define STREAMS_BOOST_TT_IS_CLASS_HPP_INCLUDED

#include <streams_boost/type_traits/config.hpp>
#include <streams_boost/type_traits/intrinsics.hpp>
#ifndef STREAMS_BOOST_IS_CLASS
#   include <streams_boost/type_traits/is_union.hpp>
#   include <streams_boost/type_traits/detail/ice_and.hpp>
#   include <streams_boost/type_traits/detail/ice_not.hpp>

#ifdef STREAMS_BOOST_TT_HAS_CONFORMING_IS_CLASS_IMPLEMENTATION
#   include <streams_boost/type_traits/detail/yes_no_type.hpp>
#else
#   include <streams_boost/type_traits/is_scalar.hpp>
#   include <streams_boost/type_traits/is_array.hpp>
#   include <streams_boost/type_traits/is_reference.hpp>
#   include <streams_boost/type_traits/is_void.hpp>
#   include <streams_boost/type_traits/is_function.hpp>
#endif

#endif // STREAMS_BOOST_IS_CLASS

#ifdef __EDG_VERSION__
#   include <streams_boost/type_traits/remove_cv.hpp>
#endif

// should be the last #include
#include <streams_boost/type_traits/detail/bool_trait_def.hpp>

namespace streams_boost {

namespace detail {

#ifndef STREAMS_BOOST_IS_CLASS
#ifdef STREAMS_BOOST_TT_HAS_CONFORMING_IS_CLASS_IMPLEMENTATION

// This is actually the conforming implementation which works with
// abstract classes.  However, enough compilers have trouble with
// it that most will use the one in
// streams_boost/type_traits/object_traits.hpp. This implementation
// actually works with VC7.0, but other interactions seem to fail
// when we use it.

// is_class<> metafunction due to Paul Mensonides
// (leavings@attbi.com). For more details:
// http://groups.google.com/groups?hl=en&selm=000001c1cc83%24e154d5e0%247772e50c%40c161550a&rnum=1
#if defined(__GNUC__)  && !defined(__EDG_VERSION__)

template <class U> ::streams_boost::type_traits::yes_type is_class_tester(void(U::*)(void));
template <class U> ::streams_boost::type_traits::no_type is_class_tester(...);

template <typename T>
struct is_class_impl
{

    STREAMS_BOOST_STATIC_CONSTANT(bool, value =
        (::streams_boost::type_traits::ice_and<
            sizeof(is_class_tester<T>(0)) == sizeof(::streams_boost::type_traits::yes_type),
            ::streams_boost::type_traits::ice_not< ::streams_boost::is_union<T>::value >::value
        >::value)
        );
};

#else

template <typename T>
struct is_class_impl
{
    template <class U> static ::streams_boost::type_traits::yes_type is_class_tester(void(U::*)(void));
    template <class U> static ::streams_boost::type_traits::no_type is_class_tester(...);

    STREAMS_BOOST_STATIC_CONSTANT(bool, value =
        (::streams_boost::type_traits::ice_and<
            sizeof(is_class_tester<T>(0)) == sizeof(::streams_boost::type_traits::yes_type),
            ::streams_boost::type_traits::ice_not< ::streams_boost::is_union<T>::value >::value
        >::value)
        );
};

#endif

#else

template <typename T>
struct is_class_impl
{
#   ifndef STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
    STREAMS_BOOST_STATIC_CONSTANT(bool, value =
    (::streams_boost::type_traits::ice_and<
        ::streams_boost::type_traits::ice_not< ::streams_boost::is_union<T>::value >::value,
        ::streams_boost::type_traits::ice_not< ::streams_boost::is_scalar<T>::value >::value,
        ::streams_boost::type_traits::ice_not< ::streams_boost::is_array<T>::value >::value,
        ::streams_boost::type_traits::ice_not< ::streams_boost::is_reference<T>::value>::value,
        ::streams_boost::type_traits::ice_not< ::streams_boost::is_void<T>::value >::value,
        ::streams_boost::type_traits::ice_not< ::streams_boost::is_function<T>::value >::value
        >::value));
#   else
    STREAMS_BOOST_STATIC_CONSTANT(bool, value =
    (::streams_boost::type_traits::ice_and<
        ::streams_boost::type_traits::ice_not< ::streams_boost::is_union<T>::value >::value,
        ::streams_boost::type_traits::ice_not< ::streams_boost::is_scalar<T>::value >::value,
        ::streams_boost::type_traits::ice_not< ::streams_boost::is_array<T>::value >::value,
        ::streams_boost::type_traits::ice_not< ::streams_boost::is_reference<T>::value>::value,
        ::streams_boost::type_traits::ice_not< ::streams_boost::is_void<T>::value >::value
        >::value));
#   endif
};

# endif // STREAMS_BOOST_TT_HAS_CONFORMING_IS_CLASS_IMPLEMENTATION
# else // STREAMS_BOOST_IS_CLASS
template <typename T>
struct is_class_impl
{
    STREAMS_BOOST_STATIC_CONSTANT(bool, value = STREAMS_BOOST_IS_CLASS(T));
};
# endif // STREAMS_BOOST_IS_CLASS

} // namespace detail

# ifdef __EDG_VERSION__
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(
   is_class,T, streams_boost::detail::is_class_impl<typename streams_boost::remove_cv<T>::type>::value)
# else 
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_class,T,::streams_boost::detail::is_class_impl<T>::value)
# endif
    
} // namespace streams_boost

#include <streams_boost/type_traits/detail/bool_trait_undef.hpp>

#endif // STREAMS_BOOST_TT_IS_CLASS_HPP_INCLUDED
