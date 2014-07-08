
//  (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt).
//
//  See http://www.streams_boost.org/libs/type_traits for most recent version including documentation.

#ifndef STREAMS_BOOST_TT_ADD_REFERENCE_HPP_INCLUDED
#define STREAMS_BOOST_TT_ADD_REFERENCE_HPP_INCLUDED

#include <streams_boost/type_traits/is_reference.hpp>
#include <streams_boost/detail/workaround.hpp>
#include <streams_boost/config.hpp>

// should be the last #include
#include <streams_boost/type_traits/detail/type_trait_def.hpp>

namespace streams_boost {

namespace detail {

#if defined(STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION) && defined(STREAMS_BOOST_MSVC6_MEMBER_TEMPLATES)

template <bool x>
struct reference_adder
{
    template <typename T> struct result_
    {
        typedef T& type;
    };
};

template <>
struct reference_adder<true>
{
    template <typename T> struct result_
    {
        typedef T type;
    };
};

template <typename T>
struct add_reference_impl
{
    typedef typename reference_adder<
          ::streams_boost::is_reference<T>::value
        >::template result_<T> result;

    typedef typename result::type type;
};

#else

template <typename T>
struct add_reference_impl
{
    typedef T& type;
};

#ifndef STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
STREAMS_BOOST_TT_AUX_TYPE_TRAIT_IMPL_PARTIAL_SPEC1_1(typename T,add_reference,T&,T&)
#endif

#endif

// these full specialisations are always required:
STREAMS_BOOST_TT_AUX_TYPE_TRAIT_IMPL_SPEC1(add_reference,void,void)
#ifndef STREAMS_BOOST_NO_CV_VOID_SPECIALIZATIONS
STREAMS_BOOST_TT_AUX_TYPE_TRAIT_IMPL_SPEC1(add_reference,void const,void const)
STREAMS_BOOST_TT_AUX_TYPE_TRAIT_IMPL_SPEC1(add_reference,void volatile,void volatile)
STREAMS_BOOST_TT_AUX_TYPE_TRAIT_IMPL_SPEC1(add_reference,void const volatile,void const volatile)
#endif

} // namespace detail

STREAMS_BOOST_TT_AUX_TYPE_TRAIT_DEF1(add_reference,T,typename streams_boost::detail::add_reference_impl<T>::type)

// agurt, 07/mar/03: workaround Borland's ill-formed sensitivity to an additional
// level of indirection, here
#if STREAMS_BOOST_WORKAROUND(__BORLANDC__, < 0x600)
STREAMS_BOOST_TT_AUX_TYPE_TRAIT_PARTIAL_SPEC1_1(typename T,add_reference,T&,T&)
#endif

} // namespace streams_boost

#include <streams_boost/type_traits/detail/type_trait_undef.hpp>

#endif // STREAMS_BOOST_TT_ADD_REFERENCE_HPP_INCLUDED
