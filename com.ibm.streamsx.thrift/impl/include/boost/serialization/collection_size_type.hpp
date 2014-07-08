#ifndef STREAMS_BOOST_SERIALIZATION_COLLECTION_SIZE_TYPE_HPP
#define STREAMS_BOOST_SERIALIZATION_COLLECTION_SIZE_TYPE_HPP

// (C) Copyright 2005 Matthias Troyer
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#include <streams_boost/serialization/strong_typedef.hpp>
#include <streams_boost/serialization/level.hpp>

namespace streams_boost { namespace serialization {

STREAMS_BOOST_STRONG_TYPEDEF(std::size_t, collection_size_type)

} } // end namespace streams_boost::serialization

STREAMS_BOOST_CLASS_IMPLEMENTATION(streams_boost::serialization::collection_size_type, primitive_type)

#endif //STREAMS_BOOST_SERIALIZATION_COLLECTION_SIZE_TYPE_HPP
