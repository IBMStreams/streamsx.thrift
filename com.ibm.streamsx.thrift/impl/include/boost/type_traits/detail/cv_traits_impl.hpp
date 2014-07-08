
//  (C) Copyright Dave Abrahams, Steve Cleary, Beman Dawes, Howard
//  Hinnant & John Maddock 2000.  
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt).
//
//  See http://www.streams_boost.org/libs/type_traits for most recent version including documentation.


#ifndef STREAMS_BOOST_TT_DETAIL_CV_TRAITS_IMPL_HPP_INCLUDED
#define STREAMS_BOOST_TT_DETAIL_CV_TRAITS_IMPL_HPP_INCLUDED

#include <streams_boost/config.hpp>
#include <streams_boost/detail/workaround.hpp>

#ifndef STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

// implementation helper:


#if !(STREAMS_BOOST_WORKAROUND(__GNUC__,== 3) && STREAMS_BOOST_WORKAROUND(__GNUC_MINOR__, <= 2))
namespace streams_boost {
namespace detail {
#else
#include <streams_boost/type_traits/detail/yes_no_type.hpp>
namespace streams_boost {
namespace type_traits {
namespace gcc8503 {
#endif

template <typename T> struct cv_traits_imp {};

template <typename T>
struct cv_traits_imp<T*>
{
    STREAMS_BOOST_STATIC_CONSTANT(bool, is_const = false);
    STREAMS_BOOST_STATIC_CONSTANT(bool, is_volatile = false);
    typedef T unqualified_type;
};

template <typename T>
struct cv_traits_imp<const T*>
{
    STREAMS_BOOST_STATIC_CONSTANT(bool, is_const = true);
    STREAMS_BOOST_STATIC_CONSTANT(bool, is_volatile = false);
    typedef T unqualified_type;
};

template <typename T>
struct cv_traits_imp<volatile T*>
{
    STREAMS_BOOST_STATIC_CONSTANT(bool, is_const = false);
    STREAMS_BOOST_STATIC_CONSTANT(bool, is_volatile = true);
    typedef T unqualified_type;
};

template <typename T>
struct cv_traits_imp<const volatile T*>
{
    STREAMS_BOOST_STATIC_CONSTANT(bool, is_const = true);
    STREAMS_BOOST_STATIC_CONSTANT(bool, is_volatile = true);
    typedef T unqualified_type;
};

#if STREAMS_BOOST_WORKAROUND(__GNUC__,== 3) && STREAMS_BOOST_WORKAROUND(__GNUC_MINOR__, <= 2)
// We have to exclude function pointers 
// (see http://gcc.gnu.org/bugzilla/show_bug.cgi?8503)
yes_type mini_funcptr_tester(...);
no_type  mini_funcptr_tester(const volatile void*);

} // namespace gcc8503
} // namespace type_traits

namespace detail {

// Use the implementation above for non function pointers
template <typename T, unsigned Select 
  = (unsigned)sizeof(::streams_boost::type_traits::gcc8503::mini_funcptr_tester((T)0)) >
struct cv_traits_imp : ::streams_boost::type_traits::gcc8503::cv_traits_imp<T> { };

// Functions are never cv-qualified
template <typename T> struct cv_traits_imp<T*,1>
{
    STREAMS_BOOST_STATIC_CONSTANT(bool, is_const = false);
    STREAMS_BOOST_STATIC_CONSTANT(bool, is_volatile = false);
    typedef T unqualified_type;
};

#endif

} // namespace detail
} // namespace streams_boost 

#endif // STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

#endif // STREAMS_BOOST_TT_DETAIL_CV_TRAITS_IMPL_HPP_INCLUDED
