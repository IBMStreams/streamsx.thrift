//  Boost integer/static_min_max.hpp header file  ----------------------------//

//  (C) Copyright Daryle Walker 2001.
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org for updates, documentation, and revision history. 

#ifndef STREAMS_BOOST_INTEGER_STATIC_MIN_MAX_HPP
#define STREAMS_BOOST_INTEGER_STATIC_MIN_MAX_HPP

#include <streams_boost/integer_fwd.hpp>  // self include

namespace streams_boost
{

//  Compile-time extrema class declarations  ---------------------------------//
//  Get the minimum or maximum of two values, signed or unsigned.

template <static_min_max_signed_type Value1, static_min_max_signed_type Value2>
struct static_signed_min
{
    STREAMS_BOOST_STATIC_CONSTANT(static_min_max_signed_type, value = (Value1 > Value2) ? Value2 : Value1 );
};

template <static_min_max_signed_type Value1, static_min_max_signed_type Value2>
struct static_signed_max
{
    STREAMS_BOOST_STATIC_CONSTANT(static_min_max_signed_type, value = (Value1 < Value2) ? Value2 : Value1 );
};

template <static_min_max_unsigned_type Value1, static_min_max_unsigned_type Value2>
struct static_unsigned_min
{
    STREAMS_BOOST_STATIC_CONSTANT(static_min_max_unsigned_type, value
     = (Value1 > Value2) ? Value2 : Value1 );
};

template <static_min_max_unsigned_type Value1, static_min_max_unsigned_type Value2>
struct static_unsigned_max
{
    STREAMS_BOOST_STATIC_CONSTANT(static_min_max_unsigned_type, value
     = (Value1 < Value2) ? Value2 : Value1 );
};


}  // namespace streams_boost


#endif  // STREAMS_BOOST_INTEGER_STATIC_MIN_MAX_HPP
