
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


#ifndef STREAMS_BOOST_TT_IS_SAME_HPP_INCLUDED
#define STREAMS_BOOST_TT_IS_SAME_HPP_INCLUDED

#include <streams_boost/type_traits/config.hpp>
#ifdef STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
#include <streams_boost/type_traits/detail/yes_no_type.hpp>
#include <streams_boost/type_traits/detail/ice_and.hpp>
#include <streams_boost/type_traits/is_reference.hpp>
#endif
// should be the last #include
#include <streams_boost/type_traits/detail/bool_trait_def.hpp>

namespace streams_boost {

#ifndef STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

STREAMS_BOOST_TT_AUX_BOOL_TRAIT_DEF2(is_same,T,U,false)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_PARTIAL_SPEC2_1(typename T,is_same,T,T,true)
#if STREAMS_BOOST_WORKAROUND(__BORLANDC__, < 0x600)
// without this, Borland's compiler gives the wrong answer for
// references to arrays:
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_PARTIAL_SPEC2_1(typename T,is_same,T&,T&,true)
#endif

#else // STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

namespace detail {

#ifdef STREAMS_BOOST_MSVC
// the following VC6 specific implementation is *NOT* legal
// C++, but has the advantage that it works for incomplete
// types.

template< typename T1 >
struct is_same_part_1
{
    template<typename T2>  struct part_2     { enum { value = false }; };
    template<>             struct part_2<T1> { enum { value = true }; };
};

template< typename T1, typename T2 >
struct is_same_impl
{
    enum { value = detail::is_same_part_1<T1>::template part_2<T2>::value };
};

#else // generic "no-partial-specialization" version

template <typename T>
::streams_boost::type_traits::yes_type
STREAMS_BOOST_TT_DECL is_same_tester(T*, T*);

::streams_boost::type_traits::no_type
STREAMS_BOOST_TT_DECL is_same_tester(...);

template <typename T, typename U>
struct is_same_impl
{
   static T t;
   static U u;

   STREAMS_BOOST_STATIC_CONSTANT(bool, value =
      (::streams_boost::type_traits::ice_and<
         (sizeof(type_traits::yes_type) == sizeof(detail::is_same_tester(&t,&u))),
         (::streams_boost::is_reference<T>::value == ::streams_boost::is_reference<U>::value),
         (sizeof(T) == sizeof(U))
        >::value));
};

#endif // STREAMS_BOOST_MSVC

} // namespace detail

STREAMS_BOOST_TT_AUX_BOOL_TRAIT_DEF2(is_same,T,U,(::streams_boost::detail::is_same_impl<T,U>::value))

#endif // STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

} // namespace streams_boost

#include <streams_boost/type_traits/detail/bool_trait_undef.hpp>

#endif  // STREAMS_BOOST_TT_IS_SAME_HPP_INCLUDED

