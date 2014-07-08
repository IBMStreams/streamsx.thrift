#ifndef STREAMS_BOOST_SERIALIZATION_WEAK_PTR_HPP
#define STREAMS_BOOST_SERIALIZATION_WEAK_PTR_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// shared_ptr.hpp: serialization for streams_boost shared pointer

// (C) Copyright 2004 Robert Ramey and Martin Ecker
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org for updates, documentation, and revision history.

#include <streams_boost/weak_ptr.hpp>
#include <streams_boost/serialization/shared_ptr.hpp>

namespace streams_boost {
namespace serialization{

template<class Archive, class T>
inline void save(
    Archive & ar,
    const streams_boost::weak_ptr<T> &t,
    const unsigned int /* file_version */
){
    const streams_boost::shared_ptr<T> sp = t.lock();
    ar << streams_boost::serialization::make_nvp("weak_ptr", sp);
}

template<class Archive, class T>
inline void load(
    Archive & ar,
    streams_boost::weak_ptr<T> &t,
    const unsigned int /* file_version */
){
    streams_boost::shared_ptr<T> sp;
    ar >> streams_boost::serialization::make_nvp("weak_ptr", sp);
    t = sp;
}

template<class Archive, class T>
inline void serialize(
    Archive & ar,
    streams_boost::weak_ptr<T> &t,
    const unsigned int file_version
){
    streams_boost::serialization::split_free(ar, t, file_version);
}

} // namespace serialization
} // namespace streams_boost

#endif // STREAMS_BOOST_SERIALIZATION_WEAK_PTR_HPP
