
//  (C) Copyright John Maddock 2005.  
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt).
//
//  See http://www.streams_boost.org/libs/type_traits for most recent version including documentation.


#ifndef STREAMS_BOOST_TT_IS_MEMBER_OBJECT_POINTER_HPP_INCLUDED
#define STREAMS_BOOST_TT_IS_MEMBER_OBJECT_POINTER_HPP_INCLUDED

#include <streams_boost/type_traits/config.hpp>
#include <streams_boost/type_traits/is_member_pointer.hpp>
#include <streams_boost/type_traits/is_member_function_pointer.hpp>
#include <streams_boost/type_traits/detail/ice_and.hpp>
#include <streams_boost/type_traits/detail/ice_not.hpp>

// should be the last #include
#include <streams_boost/type_traits/detail/bool_trait_def.hpp>

namespace streams_boost {

namespace detail{

template <typename T>
struct is_member_object_pointer_impl
{
   STREAMS_BOOST_STATIC_CONSTANT(
      bool, value = (::streams_boost::type_traits::ice_and<
         ::streams_boost::is_member_pointer<T>::value,
         ::streams_boost::type_traits::ice_not<
            ::streams_boost::is_member_function_pointer<T>::value
         >::value
      >::value ));
};

} // namespace detail

STREAMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_member_object_pointer,T,::streams_boost::detail::is_member_object_pointer_impl<T>::value)

} // namespace streams_boost

#include <streams_boost/type_traits/detail/bool_trait_undef.hpp>

#endif // STREAMS_BOOST_TT_IS_MEMBER_FUNCTION_POINTER_HPP_INCLUDED
