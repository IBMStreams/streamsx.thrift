//  (C) Copyright John Maddock and Steve Cleary 2000.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt).
//
//  See http://www.streams_boost.org/libs/type_traits for most recent version including documentation.

#ifndef STREAMS_BOOST_TT_DETAIL_ICE_OR_HPP_INCLUDED
#define STREAMS_BOOST_TT_DETAIL_ICE_OR_HPP_INCLUDED

#include <streams_boost/config.hpp>

namespace streams_boost {
namespace type_traits {

template <bool b1, bool b2, bool b3 = false, bool b4 = false, bool b5 = false, bool b6 = false, bool b7 = false>
struct ice_or;

template <bool b1, bool b2, bool b3, bool b4, bool b5, bool b6, bool b7>
struct ice_or
{
    STREAMS_BOOST_STATIC_CONSTANT(bool, value = true);
};

template <>
struct ice_or<false, false, false, false, false, false, false>
{
    STREAMS_BOOST_STATIC_CONSTANT(bool, value = false);
};

} // namespace type_traits
} // namespace streams_boost

#endif // STREAMS_BOOST_TT_DETAIL_ICE_OR_HPP_INCLUDED
