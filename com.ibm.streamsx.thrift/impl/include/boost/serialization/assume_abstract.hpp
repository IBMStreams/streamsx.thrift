#ifndef STREAMS_BOOST_SERIALIZATION_ASSUME_ABSTRACT_HPP
#define STREAMS_BOOST_SERIALIZATION_ASSUME_ABSTRACT_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// assume_abstract_class.hpp:

// (C) Copyright 2008 Robert Ramey
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org for updates, documentation, and revision history.

// this is useful for compilers which don't support the streams_boost::is_abstract

#include <streams_boost/type_traits/is_abstract.hpp>

#ifndef STREAMS_BOOST_NO_IS_ABSTRACT

// if there is an intrinsic is_abstract defined, we don't have to do anything
#define STREAMS_BOOST_SERIALIZATION_ASSUME_ABSTRACT(T)

// but forward to the "official" is_abstract
namespace streams_boost {
namespace serialization {
    template<class T>
    struct is_abstract : streams_boost::is_abstract<T> {} ;
} // namespace serialization
} // namespace streams_boost

#else
// we have to "make" one

namespace streams_boost {
namespace serialization {
    template<class T>
    struct is_abstract : streams_boost::false_type {};
} // namespace serialization
} // namespace streams_boost

// define a macro to make explicit designation of this more transparent
#define STREAMS_BOOST_SERIALIZATION_ASSUME_ABSTRACT(T)        \
namespace streams_boost {                                     \
namespace serialization {                             \
template<>                                            \
struct is_abstract< T > : streams_boost::true_type {};        \
template<>                                            \
struct is_abstract< const T > : streams_boost::true_type {};  \
}}                                                    \
/**/

#endif // STREAMS_BOOST_NO_IS_ABSTRACT

#endif //STREAMS_BOOST_SERIALIZATION_ASSUME_ABSTRACT_HPP
