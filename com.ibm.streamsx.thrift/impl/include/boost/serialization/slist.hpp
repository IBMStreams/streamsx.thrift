#ifndef STREAMS_BOOST_SERIALIZATION_SLIST_HPP
#define STREAMS_BOOST_SERIALIZATION_SLIST_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// slist.hpp

// (C) Copyright 2002 Robert Ramey - http://www.rrsd.com . 
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org for updates, documentation, and revision history.

#include <cstddef> // size_t
#include <streams_boost/config.hpp> // msvc 6.0 needs this for warning suppression
#if defined(STREAMS_BOOST_NO_STDC_NAMESPACE)
namespace std{ 
    using ::size_t; 
} // namespace std
#endif

#ifdef STREAMS_BOOST_HAS_SLIST
#include STREAMS_BOOST_SLIST_HEADER

#include <streams_boost/serialization/collections_save_imp.hpp>
#include <streams_boost/serialization/collections_load_imp.hpp>
#include <streams_boost/serialization/split_free.hpp>
#include <streams_boost/serialization/nvp.hpp>

namespace streams_boost { 
namespace serialization {

template<class Archive, class U, class Allocator>
inline void save(
    Archive & ar,
    const STREAMS_BOOST_STD_EXTENSION_NAMESPACE::slist<U, Allocator> &t,
    const unsigned int file_version
){
    streams_boost::serialization::stl::save_collection<
        Archive,
        STREAMS_BOOST_STD_EXTENSION_NAMESPACE::slist<U, Allocator> 
    >(ar, t);
}

template<class Archive, class U, class Allocator>
inline void load(
    Archive & ar,
    STREAMS_BOOST_STD_EXTENSION_NAMESPACE::slist<U, Allocator> &t,
    const unsigned int file_version
){
    // retrieve number of elements
    t.clear();
    // retrieve number of elements
    collection_size_type count;
    ar >> STREAMS_BOOST_SERIALIZATION_NVP(count);
    if(std::size_t(0) == count)
        return;
    unsigned int v;
    if(3 < ar.get_library_version()){
        ar >> streams_boost::serialization::make_nvp("item_version", v);
    }
    streams_boost::serialization::detail::stack_construct<Archive, U> u(ar, v);
    ar >> streams_boost::serialization::make_nvp("item", u.reference());
    t.push_front(u.reference());
    STREAMS_BOOST_DEDUCED_TYPENAME STREAMS_BOOST_STD_EXTENSION_NAMESPACE::slist<U, Allocator>::iterator last;
    last = t.begin();
    collection_size_type c = count;
    while(--c > 0){
        streams_boost::serialization::detail::stack_construct<Archive, U> 
            u(ar, file_version);
        ar >> streams_boost::serialization::make_nvp("item", u.reference());
        last = t.insert_after(last, u.reference());
        ar.reset_object_address(& (*last), & u.reference());
    }
}

// split non-intrusive serialization function member into separate
// non intrusive save/load member functions
template<class Archive, class U, class Allocator>
inline void serialize(
    Archive & ar,
    STREAMS_BOOST_STD_EXTENSION_NAMESPACE::slist<U, Allocator> &t,
    const unsigned int file_version
){
    streams_boost::serialization::split_free(ar, t, file_version);
}

} // serialization
} // namespace streams_boost

#include <streams_boost/serialization/collection_traits.hpp>

STREAMS_BOOST_SERIALIZATION_COLLECTION_TRAITS(STREAMS_BOOST_STD_EXTENSION_NAMESPACE::slist)

#endif  // STREAMS_BOOST_HAS_SLIST
#endif  // STREAMS_BOOST_SERIALIZATION_SLIST_HPP
