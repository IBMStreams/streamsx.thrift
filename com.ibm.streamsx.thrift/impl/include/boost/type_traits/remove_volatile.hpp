
//  (C) Copyright Dave Abrahams, Steve Cleary, Beman Dawes, Howard
//  Hinnant & John Maddock 2000.  
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt).
//
//  See http://www.streams_boost.org/libs/type_traits for most recent version including documentation.


#ifndef STREAMS_BOOST_TT_REMOVE_VOLATILE_HPP_INCLUDED
#define STREAMS_BOOST_TT_REMOVE_VOLATILE_HPP_INCLUDED

#include <streams_boost/type_traits/is_const.hpp>
#include <streams_boost/type_traits/broken_compiler_spec.hpp>
#include <streams_boost/type_traits/detail/cv_traits_impl.hpp>
#include <streams_boost/config.hpp>
#include <streams_boost/detail/workaround.hpp>

#include <cstddef>

#if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC,<=1300)
#include <streams_boost/type_traits/msvc/remove_volatile.hpp>
#endif

// should be the last #include
#include <streams_boost/type_traits/detail/type_trait_def.hpp>

namespace streams_boost {

#ifndef STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

namespace detail {

template <typename T, bool is_const>
struct remove_volatile_helper
{
    typedef T type;
};

template <typename T>
struct remove_volatile_helper<T,true>
{
    typedef T const type;
};

template <typename T>
struct remove_volatile_impl
{
    typedef typename remove_volatile_helper<
          typename cv_traits_imp<T*>::unqualified_type
        , ::streams_boost::is_const<T>::value
        >::type type;
};

} // namespace detail

// * convert a type T to a non-volatile type - remove_volatile<T>

STREAMS_BOOST_TT_AUX_TYPE_TRAIT_DEF1(remove_volatile,T,typename streams_boost::detail::remove_volatile_impl<T>::type)
STREAMS_BOOST_TT_AUX_TYPE_TRAIT_PARTIAL_SPEC1_1(typename T,remove_volatile,T&,T&)
#if !defined(STREAMS_BOOST_NO_ARRAY_TYPE_SPECIALIZATIONS)
STREAMS_BOOST_TT_AUX_TYPE_TRAIT_PARTIAL_SPEC1_2(typename T,std::size_t N,remove_volatile,T volatile[N],T type[N])
STREAMS_BOOST_TT_AUX_TYPE_TRAIT_PARTIAL_SPEC1_2(typename T,std::size_t N,remove_volatile,T const volatile[N],T const type[N])
#endif

#elif !STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC,<=1300)

STREAMS_BOOST_TT_AUX_TYPE_TRAIT_DEF1(remove_volatile,T,typename streams_boost::detail::remove_volatile_impl<T>::type)

#endif // STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

} // namespace streams_boost

#include <streams_boost/type_traits/detail/type_trait_undef.hpp>

#endif // STREAMS_BOOST_TT_REMOVE_VOLATILE_HPP_INCLUDED
