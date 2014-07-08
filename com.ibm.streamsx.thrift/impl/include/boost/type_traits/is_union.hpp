
//  (C) Copyright Dave Abrahams, Steve Cleary, Beman Dawes, Howard
//  Hinnant & John Maddock 2000.  
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt).
//
//  See http://www.streams_boost.org/libs/type_traits for most recent version including documentation.


#ifndef STREAMS_BOOST_TT_IS_UNION_HPP_INCLUDED
#define STREAMS_BOOST_TT_IS_UNION_HPP_INCLUDED

#include <streams_boost/type_traits/remove_cv.hpp>
#include <streams_boost/type_traits/config.hpp>
#include <streams_boost/type_traits/intrinsics.hpp>

// should be the last #include
#include <streams_boost/type_traits/detail/bool_trait_def.hpp>

namespace streams_boost {

namespace detail {
#ifndef __GNUC__
template <typename T> struct is_union_impl
{
   typedef typename remove_cv<T>::type cvt;
   STREAMS_BOOST_STATIC_CONSTANT(bool, value = STREAMS_BOOST_IS_UNION(cvt));
};
#else
//
// using remove_cv here generates a whole load of needless
// warnings with gcc, since it doesn't do any good with gcc
// in any case (at least at present), just remove it:
//
template <typename T> struct is_union_impl
{
   STREAMS_BOOST_STATIC_CONSTANT(bool, value = STREAMS_BOOST_IS_UNION(T));
};
#endif
} // namespace detail

STREAMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_union,T,::streams_boost::detail::is_union_impl<T>::value)

} // namespace streams_boost

#include <streams_boost/type_traits/detail/bool_trait_undef.hpp>

#endif // STREAMS_BOOST_TT_IS_UNION_HPP_INCLUDED
