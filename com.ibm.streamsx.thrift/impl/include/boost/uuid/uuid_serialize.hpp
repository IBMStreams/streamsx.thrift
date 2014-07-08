// Boost uuid_serialize.hpp header file  ----------------------------------------------//

// Copyright 2007 Andy Tompkins.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

// Revision History
//  12 Nov 2007 - Initial Revision
//  25 Feb 2008 - moved to namespace streams_boost::uuids::detail

#ifndef STREAMS_BOOST_UUID_SERIALIZE_HPP
#define STREAMS_BOOST_UUID_SERIALIZE_HPP

#include <streams_boost/uuid/uuid.hpp>
#include <streams_boost/serialization/level.hpp>

STREAMS_BOOST_CLASS_IMPLEMENTATION(streams_boost::uuids::uuid, streams_boost::serialization::primitive_type)

#endif // STREAMS_BOOST_UUID_SERIALIZE_HPP
