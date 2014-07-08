
//  (C) Copyright John Maddock 2005.  
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt).
//
//  See http://www.streams_boost.org/libs/type_traits for most recent version including documentation.


#ifndef STREAMS_BOOST_TT_HAS_VIRTUAL_DESTRUCTOR_HPP_INCLUDED
#define STREAMS_BOOST_TT_HAS_VIRTUAL_DESTRUCTOR_HPP_INCLUDED

#include <streams_boost/type_traits/intrinsics.hpp>
// should be the last #include
#include <streams_boost/type_traits/detail/bool_trait_def.hpp>

namespace streams_boost {

STREAMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(has_virtual_destructor,T,STREAMS_BOOST_HAS_VIRTUAL_DESTRUCTOR(T))

} // namespace streams_boost

#include <streams_boost/type_traits/detail/bool_trait_undef.hpp>

#endif // STREAMS_BOOST_TT_IS_MEMBER_FUNCTION_POINTER_HPP_INCLUDED
