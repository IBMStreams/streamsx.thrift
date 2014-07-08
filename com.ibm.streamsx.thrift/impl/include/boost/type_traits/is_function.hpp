
//  Copyright 2000 John Maddock (john@johnmaddock.co.uk)
//  Copyright 2002 Aleksey Gurtovoy (agurtovoy@meta-comm.com)
//
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt).
//
//  See http://www.streams_boost.org/libs/type_traits for most recent version including documentation.

#ifndef STREAMS_BOOST_TT_IS_FUNCTION_HPP_INCLUDED
#define STREAMS_BOOST_TT_IS_FUNCTION_HPP_INCLUDED

#include <streams_boost/type_traits/is_reference.hpp>
#include <streams_boost/type_traits/detail/false_result.hpp>
#include <streams_boost/config.hpp>

#if !defined(STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION) && !defined(STREAMS_BOOST_TT_TEST_MS_FUNC_SIGS)
#   include <streams_boost/type_traits/detail/is_function_ptr_helper.hpp>
#else
#   include <streams_boost/type_traits/detail/is_function_ptr_tester.hpp>
#   include <streams_boost/type_traits/detail/yes_no_type.hpp>
#endif

// should be the last #include
#include <streams_boost/type_traits/detail/bool_trait_def.hpp>

// is a type a function?
// Please note that this implementation is unnecessarily complex:
// we could just use !is_convertible<T*, const volatile void*>::value,
// except that some compilers erroneously allow conversions from
// function pointers to void*.

namespace streams_boost {

#if !defined( __CODEGEARC__ )

namespace detail {

#if !defined(STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION) && !defined(STREAMS_BOOST_TT_TEST_MS_FUNC_SIGS)
template<bool is_ref = true>
struct is_function_chooser
    : ::streams_boost::type_traits::false_result
{
};

template <>
struct is_function_chooser<false>
{
    template< typename T > struct result_
        : ::streams_boost::type_traits::is_function_ptr_helper<T*>
    {
    };
};

template <typename T>
struct is_function_impl
    : is_function_chooser< ::streams_boost::is_reference<T>::value >
        ::STREAMS_BOOST_NESTED_TEMPLATE result_<T>
{
};

#else

template <typename T>
struct is_function_impl
{
#if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC_FULL_VER, >= 140050000)
#pragma warning(push)
#pragma warning(disable:6334)
#endif
    static T* t;
    STREAMS_BOOST_STATIC_CONSTANT(
        bool, value = sizeof(::streams_boost::type_traits::is_function_ptr_tester(t))
        == sizeof(::streams_boost::type_traits::yes_type)
        );
#if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC_FULL_VER, >= 140050000)
#pragma warning(pop)
#endif
};

#if !defined(STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)
template <typename T>
struct is_function_impl<T&> : public false_type
{};
#endif

#endif

} // namespace detail

#endif // !defined( __CODEGEARC__ )

#if defined( __CODEGEARC__ )
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_function,T,__is_function(T))
#else
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_function,T,::streams_boost::detail::is_function_impl<T>::value)
#endif
} // namespace streams_boost

#include <streams_boost/type_traits/detail/bool_trait_undef.hpp>

#endif // STREAMS_BOOST_TT_IS_FUNCTION_HPP_INCLUDED
