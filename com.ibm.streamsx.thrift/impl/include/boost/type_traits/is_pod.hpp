
//  (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt).
//
//  See http://www.streams_boost.org/libs/type_traits for most recent version including documentation.

#ifndef STREAMS_BOOST_TT_IS_POD_HPP_INCLUDED
#define STREAMS_BOOST_TT_IS_POD_HPP_INCLUDED

#include <streams_boost/type_traits/config.hpp>
#include <streams_boost/type_traits/is_void.hpp>
#include <streams_boost/type_traits/is_scalar.hpp>
#include <streams_boost/type_traits/detail/ice_or.hpp>
#include <streams_boost/type_traits/intrinsics.hpp>

#include <cstddef>

// should be the last #include
#include <streams_boost/type_traits/detail/bool_trait_def.hpp>

namespace streams_boost {

// forward declaration, needed by 'is_pod_array_helper' template below
template< typename T > struct is_POD;

namespace detail {

#ifndef STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

template <typename T> struct is_pod_impl
{ 
    STREAMS_BOOST_STATIC_CONSTANT(
        bool, value =
        (::streams_boost::type_traits::ice_or<
            ::streams_boost::is_scalar<T>::value,
            ::streams_boost::is_void<T>::value,
            STREAMS_BOOST_IS_POD(T)
         >::value));
};

#if !defined(STREAMS_BOOST_NO_ARRAY_TYPE_SPECIALIZATIONS)
template <typename T, std::size_t sz>
struct is_pod_impl<T[sz]>
    : is_pod_impl<T>
{
};
#endif

#else

template <bool is_array = false>
struct is_pod_helper
{
    template <typename T> struct result_
    {
        STREAMS_BOOST_STATIC_CONSTANT(
            bool, value =
            (::streams_boost::type_traits::ice_or<
                ::streams_boost::is_scalar<T>::value,
                ::streams_boost::is_void<T>::value,
                STREAMS_BOOST_IS_POD(T)
            >::value));
    };
};

template <bool b>
struct bool_to_yes_no_type
{
    typedef ::streams_boost::type_traits::no_type type;
};

template <>
struct bool_to_yes_no_type<true>
{
    typedef ::streams_boost::type_traits::yes_type type;
};

template <typename ArrayType>
struct is_pod_array_helper
{
    enum { is_pod = ::streams_boost::is_POD<ArrayType>::value }; // MSVC workaround
    typedef typename bool_to_yes_no_type<is_pod>::type type;
    type instance() const;
};

template <typename T>
is_pod_array_helper<T> is_POD_array(T*);

template <>
struct is_pod_helper<true>
{
    template <typename T> struct result_
    {
        static T& help();
        STREAMS_BOOST_STATIC_CONSTANT(bool, value =
            sizeof(is_POD_array(help()).instance()) == sizeof(::streams_boost::type_traits::yes_type)
            );
    };
};


template <typename T> struct is_pod_impl
{ 
   STREAMS_BOOST_STATIC_CONSTANT(
       bool, value = (
           ::streams_boost::detail::is_pod_helper<
              ::streams_boost::is_array<T>::value
           >::template result_<T>::value
           )
       );
};

#endif // STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

// the following help compilers without partial specialization support:
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_pod,void,true)

#ifndef STREAMS_BOOST_NO_CV_VOID_SPECIALIZATIONS
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_pod,void const,true)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_pod,void volatile,true)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_pod,void const volatile,true)
#endif

} // namespace detail

STREAMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_POD,T,::streams_boost::detail::is_pod_impl<T>::value)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_pod,T,::streams_boost::detail::is_pod_impl<T>::value)

} // namespace streams_boost

#include <streams_boost/type_traits/detail/bool_trait_undef.hpp>

#endif // STREAMS_BOOST_TT_IS_POD_HPP_INCLUDED
