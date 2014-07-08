//  (C) Copyright John Maddock and Steve Cleary 2000.
//
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt).
//
//  See http://www.streams_boost.org/libs/type_traits for most recent version including documentation.

#ifndef STREAMS_BOOST_TT_DETAIL_ICE_AND_HPP_INCLUDED
#define STREAMS_BOOST_TT_DETAIL_ICE_AND_HPP_INCLUDED

#include <streams_boost/config.hpp>

namespace streams_boost {
namespace type_traits {

template <bool b1, bool b2, bool b3 = true, bool b4 = true, bool b5 = true, bool b6 = true, bool b7 = true>
struct ice_and;

template <bool b1, bool b2, bool b3, bool b4, bool b5, bool b6, bool b7>
struct ice_and
{
    STREAMS_BOOST_STATIC_CONSTANT(bool, value = false);
};

template <>
struct ice_and<true, true, true, true, true, true, true>
{
    STREAMS_BOOST_STATIC_CONSTANT(bool, value = true);
};

} // namespace type_traits
} // namespace streams_boost

#endif // STREAMS_BOOST_TT_DETAIL_ICE_AND_HPP_INCLUDED
