// (C) Copyright 2007 Matthias Troyer

// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

//  Authors: Matthias Troyer

/** @file is_bitwise_serializable.hpp
 *
 *  This header provides a traits class for determining whether a class
 * can be serialized (in a non-portable way) just by copying the bits.
 */


#ifndef STREAMS_BOOST_SERIALIZATION_IS_BITWISE_SERIALIZABLE_HPP
#define STREAMS_BOOST_SERIALIZATION_IS_BITWISE_SERIALIZABLE_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

#include <streams_boost/mpl/bool.hpp>
#include <streams_boost/type_traits/is_arithmetic.hpp>

namespace streams_boost {
namespace serialization {
    template<class T>
    struct is_bitwise_serializable
     : public is_arithmetic<T>
    {};
} // namespace serialization
} // namespace streams_boost


// define a macro to make explicit designation of this more transparent
#define STREAMS_BOOST_IS_BITWISE_SERIALIZABLE(T)              \
namespace streams_boost {                                     \
namespace serialization {                             \
template<>                                            \
struct is_bitwise_serializable< T > : mpl::true_ {};  \
}}                                                    \
/**/

#endif //STREAMS_BOOST_SERIALIZATION_IS_BITWISE_SERIALIZABLE_HPP