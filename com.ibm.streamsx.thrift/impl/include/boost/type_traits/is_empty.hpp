
// (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt).
//
//  See http://www.streams_boost.org/libs/type_traits for most recent version including documentation.

#ifndef STREAMS_BOOST_TT_IS_EMPTY_HPP_INCLUDED
#define STREAMS_BOOST_TT_IS_EMPTY_HPP_INCLUDED

#include <streams_boost/type_traits/is_convertible.hpp>
#include <streams_boost/type_traits/detail/ice_or.hpp>
#include <streams_boost/type_traits/config.hpp>
#include <streams_boost/type_traits/intrinsics.hpp>

#ifndef STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
#   include <streams_boost/type_traits/remove_cv.hpp>
#   include <streams_boost/type_traits/is_class.hpp>
#   include <streams_boost/type_traits/add_reference.hpp>
#else
#   include <streams_boost/type_traits/is_reference.hpp>
#   include <streams_boost/type_traits/is_pointer.hpp>
#   include <streams_boost/type_traits/is_member_pointer.hpp>
#   include <streams_boost/type_traits/is_array.hpp>
#   include <streams_boost/type_traits/is_void.hpp>
#   include <streams_boost/type_traits/detail/ice_and.hpp>
#   include <streams_boost/type_traits/detail/ice_not.hpp>
#endif

// should be always the last #include directive
#include <streams_boost/type_traits/detail/bool_trait_def.hpp>

namespace streams_boost {

namespace detail {

#ifndef STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
template <typename T>
struct empty_helper_t1 : public T
{
    empty_helper_t1();  // hh compiler bug workaround
    int i[256];
private:
   // suppress compiler warnings:
   empty_helper_t1(const empty_helper_t1&);
   empty_helper_t1& operator=(const empty_helper_t1&);
};

struct empty_helper_t2 { int i[256]; };

#if !STREAMS_BOOST_WORKAROUND(__BORLANDC__, < 0x600)

template <typename T, bool is_a_class = false>
struct empty_helper
{
    STREAMS_BOOST_STATIC_CONSTANT(bool, value = false);
};

template <typename T>
struct empty_helper<T, true>
{
    STREAMS_BOOST_STATIC_CONSTANT(
        bool, value = (sizeof(empty_helper_t1<T>) == sizeof(empty_helper_t2))
        );
};

template <typename T>
struct is_empty_impl
{
    typedef typename remove_cv<T>::type cvt;
    STREAMS_BOOST_STATIC_CONSTANT(
        bool, value = (
            ::streams_boost::type_traits::ice_or<
              ::streams_boost::detail::empty_helper<cvt,::streams_boost::is_class<T>::value>::value
              , STREAMS_BOOST_IS_EMPTY(cvt)
            >::value
            ));
};

#else // __BORLANDC__

template <typename T, bool is_a_class, bool convertible_to_int>
struct empty_helper
{
    STREAMS_BOOST_STATIC_CONSTANT(bool, value = false);
};

template <typename T>
struct empty_helper<T, true, false>
{
    STREAMS_BOOST_STATIC_CONSTANT(bool, value = (
        sizeof(empty_helper_t1<T>) == sizeof(empty_helper_t2)
        ));
};

template <typename T>
struct is_empty_impl
{
   typedef typename remove_cv<T>::type cvt;
   typedef typename add_reference<T>::type r_type;

   STREAMS_BOOST_STATIC_CONSTANT(
       bool, value = (
           ::streams_boost::type_traits::ice_or<
              ::streams_boost::detail::empty_helper<
                  cvt
                , ::streams_boost::is_class<T>::value
                , ::streams_boost::is_convertible< r_type,int>::value
              >::value
              , STREAMS_BOOST_IS_EMPTY(cvt)
           >::value));
};

#endif // __BORLANDC__

#else // STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

#ifdef STREAMS_BOOST_MSVC6_MEMBER_TEMPLATES

template <typename T>
struct empty_helper_t1 : public T
{
   empty_helper_t1();
   int i[256];
};

struct empty_helper_t2 { int i[256]; };

template <typename T>
struct empty_helper_base
{
   enum { value = (sizeof(empty_helper_t1<T>) == sizeof(empty_helper_t2)) };
};

template <typename T>
struct empty_helper_nonbase
{
   enum { value = false };
};

template <bool base>
struct empty_helper_chooser
{
   template <typename T> struct result_
   {
      typedef empty_helper_nonbase<T> type;
   };
};

template <>
struct empty_helper_chooser<true>
{
   template <typename T> struct result_
   {
      typedef empty_helper_base<T> type;
   };
};

template <typename T>
struct is_empty_impl
{
   typedef ::streams_boost::detail::empty_helper_chooser<
      ::streams_boost::type_traits::ice_and<
         ::streams_boost::type_traits::ice_not< ::streams_boost::is_reference<T>::value >::value,
         ::streams_boost::type_traits::ice_not< ::streams_boost::is_convertible<T,double>::value >::value,
         ::streams_boost::type_traits::ice_not< ::streams_boost::is_pointer<T>::value >::value,
         ::streams_boost::type_traits::ice_not< ::streams_boost::is_member_pointer<T>::value >::value,
         ::streams_boost::type_traits::ice_not< ::streams_boost::is_array<T>::value >::value,
         ::streams_boost::type_traits::ice_not< ::streams_boost::is_void<T>::value >::value,
         ::streams_boost::type_traits::ice_not<
            ::streams_boost::is_convertible<T,void const volatile*>::value
            >::value
      >::value > chooser;

   typedef typename chooser::template result_<T> result;
   typedef typename result::type eh_type;

   STREAMS_BOOST_STATIC_CONSTANT(bool, value =
      (::streams_boost::type_traits::ice_or<eh_type::value, STREAMS_BOOST_IS_EMPTY(T)>::value));
};

#else

template <typename T> struct is_empty_impl
{
    STREAMS_BOOST_STATIC_CONSTANT(bool, value = STREAMS_BOOST_IS_EMPTY(T));
};

#endif  // STREAMS_BOOST_MSVC6_MEMBER_TEMPLATES

#endif  // STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

// these help when the compiler has no partial specialization support:
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_empty,void,false)
#ifndef STREAMS_BOOST_NO_CV_VOID_SPECIALIZATIONS
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_empty,void const,false)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_empty,void volatile,false)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_empty,void const volatile,false)
#endif

} // namespace detail

STREAMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_empty,T,::streams_boost::detail::is_empty_impl<T>::value)

} // namespace streams_boost

#include <streams_boost/type_traits/detail/bool_trait_undef.hpp>

#endif // STREAMS_BOOST_TT_IS_EMPTY_HPP_INCLUDED

