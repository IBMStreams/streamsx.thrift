#ifndef  STREAMS_BOOST_SERIALIZATION_VECTOR_HPP
#define STREAMS_BOOST_SERIALIZATION_VECTOR_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// vector.hpp: serialization for stl vector templates

// (C) Copyright 2002 Robert Ramey - http://www.rrsd.com . 
// fast array serialization (C) Copyright 2005 Matthias Troyer 
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org for updates, documentation, and revision history.

#include <vector>

#include <streams_boost/config.hpp>
#include <streams_boost/detail/workaround.hpp>
#include <streams_boost/type_traits/is_arithmetic.hpp> 

#include <streams_boost/serialization/collections_save_imp.hpp>
#include <streams_boost/serialization/collections_load_imp.hpp>
#include <streams_boost/serialization/split_free.hpp>
#include <streams_boost/serialization/array.hpp>
#include <streams_boost/serialization/detail/get_data.hpp>
#include <streams_boost/mpl/bool.hpp>

// default is being compatible with version 1.34.1 files, not 1.35 files
#ifndef STREAMS_BOOST_SERIALIZATION_VECTOR_VERSIONED
#define STREAMS_BOOST_SERIALIZATION_VECTOR_VERSIONED(V) (V==4 || V==5)
#endif

namespace streams_boost { 
namespace serialization {

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// vector<T>

// the default versions

template<class Archive, class U, class Allocator>
inline void save(
    Archive & ar,
    const std::vector<U, Allocator> &t,
    const unsigned int /* file_version */,
    mpl::false_
){
    streams_boost::serialization::stl::save_collection<Archive, STD::vector<U, Allocator> >(
        ar, t
    );
}

template<class Archive, class U, class Allocator>
inline void load(
    Archive & ar,
    std::vector<U, Allocator> &t,
    const unsigned int /* file_version */,
    mpl::false_
){
    streams_boost::serialization::stl::load_collection<
        Archive,
        std::vector<U, Allocator>,
        streams_boost::serialization::stl::archive_input_seq<
            Archive, STD::vector<U, Allocator> 
        >,
        streams_boost::serialization::stl::reserve_imp<STD::vector<U, Allocator> >
    >(ar, t);
}

// the optimized versions

template<class Archive, class U, class Allocator>
inline void save(
    Archive & ar,
    const std::vector<U, Allocator> &t,
    const unsigned int /* file_version */,
    mpl::true_
){
    const collection_size_type count(t.size());
    ar << STREAMS_BOOST_SERIALIZATION_NVP(count);
    if (!t.empty())
        ar << make_array(detail::get_data(t),t.size());
}

template<class Archive, class U, class Allocator>
inline void load(
    Archive & ar,
    std::vector<U, Allocator> &t,
    const unsigned int /* file_version */,
    mpl::true_
){
    collection_size_type count(t.size());
    ar >> STREAMS_BOOST_SERIALIZATION_NVP(count);
    t.resize(count);
    unsigned int item_version=0;
    if(STREAMS_BOOST_SERIALIZATION_VECTOR_VERSIONED(ar.get_library_version())) {
        ar >> STREAMS_BOOST_SERIALIZATION_NVP(item_version);
    }
    if (!t.empty())
        ar >> make_array(detail::get_data(t),t.size());
  }

// dispatch to either default or optimized versions

template<class Archive, class U, class Allocator>
inline void save(
    Archive & ar,
    const std::vector<U, Allocator> &t,
    const unsigned int file_version
){
    typedef STREAMS_BOOST_DEDUCED_TYPENAME 
    streams_boost::serialization::use_array_optimization<Archive>::template apply<
        STREAMS_BOOST_DEDUCED_TYPENAME remove_const<U>::type 
    >::type use_optimized;
    save(ar,t,file_version, use_optimized());
}

template<class Archive, class U, class Allocator>
inline void load(
    Archive & ar,
    std::vector<U, Allocator> &t,
    const unsigned int file_version
){
#ifdef STREAMS_BOOST_SERIALIZATION_VECTOR_135_HPP
    if (ar.get_library_version()==5)
    {
      load(ar,t,file_version, streams_boost::is_arithmetic<U>());
      return;
    }
#endif
    typedef STREAMS_BOOST_DEDUCED_TYPENAME 
    streams_boost::serialization::use_array_optimization<Archive>::template apply<
        STREAMS_BOOST_DEDUCED_TYPENAME remove_const<U>::type 
    >::type use_optimized;
    load(ar,t,file_version, use_optimized());
}

// split non-intrusive serialization function member into separate
// non intrusive save/load member functions
template<class Archive, class U, class Allocator>
inline void serialize(
    Archive & ar,
    std::vector<U, Allocator> & t,
    const unsigned int file_version
){
    streams_boost::serialization::split_free(ar, t, file_version);
}

#if ! STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, <= 1300)

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// vector<bool>
template<class Archive, class Allocator>
inline void save(
    Archive & ar,
    const std::vector<bool, Allocator> &t,
    const unsigned int /* file_version */
){
    // record number of elements
    collection_size_type count (t.size());
    ar << STREAMS_BOOST_SERIALIZATION_NVP(count);
    std::vector<bool>::const_iterator it = t.begin();
    while(count-- > 0){
        bool tb = *it++;
        ar << streams_boost::serialization::make_nvp("item", tb);
    }
}

template<class Archive, class Allocator>
inline void load(
    Archive & ar,
    std::vector<bool, Allocator> &t,
    const unsigned int /* file_version */
){
    // retrieve number of elements
    collection_size_type count;
    ar >> STREAMS_BOOST_SERIALIZATION_NVP(count);
    t.clear();
    while(count-- > 0){
        bool i;
        ar >> streams_boost::serialization::make_nvp("item", i);
        t.push_back(i);
    }
}

// split non-intrusive serialization function member into separate
// non intrusive save/load member functions
template<class Archive, class Allocator>
inline void serialize(
    Archive & ar,
    std::vector<bool, Allocator> & t,
    const unsigned int file_version
){
    streams_boost::serialization::split_free(ar, t, file_version);
}

#endif // STREAMS_BOOST_WORKAROUND

} // serialization
} // namespace streams_boost

#include <streams_boost/serialization/collection_traits.hpp>

STREAMS_BOOST_SERIALIZATION_COLLECTION_TRAITS(std::vector)

#endif // STREAMS_BOOST_SERIALIZATION_VECTOR_HPP
