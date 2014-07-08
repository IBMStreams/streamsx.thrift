#ifndef STREAMS_BOOST_SERIALIZATION_COLLECTIONS_SAVE_IMP_HPP
#define STREAMS_BOOST_SERIALIZATION_COLLECTIONS_SAVE_IMP_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// collections_save_imp.hpp: serialization for stl collections

// (C) Copyright 2002 Robert Ramey - http://www.rrsd.com . 
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org for updates, documentation, and revision history.

// helper function templates for serialization of collections

#include <streams_boost/config.hpp>
#include <streams_boost/serialization/nvp.hpp>
#include <streams_boost/serialization/serialization.hpp>
#include <streams_boost/serialization/version.hpp>
#include <streams_boost/serialization/collection_size_type.hpp>

namespace streams_boost{
namespace serialization {
namespace stl {

//////////////////////////////////////////////////////////////////////
// implementation of serialization for STL containers
//

template<class Archive, class Container>
inline void save_collection(Archive & ar, const Container &s)
{
    // record number of elements
    collection_size_type const count(s.size());
    ar <<  STREAMS_BOOST_SERIALIZATION_NVP(count);
    // make sure the target type is registered so we can retrieve
    // the version when we load
    if(3 < ar.get_library_version()){
        const unsigned int item_version = version<
            STREAMS_BOOST_DEDUCED_TYPENAME Container::value_type
        >::value;
        ar << STREAMS_BOOST_SERIALIZATION_NVP(item_version);
    }
    STREAMS_BOOST_DEDUCED_TYPENAME Container::const_iterator it = s.begin();
    collection_size_type c=count;
    while(c-- > 0){
            // note borland emits a no-op without the explicit namespace
            streams_boost::serialization::save_construct_data_adl(
                ar, 
                &(*it), 
                streams_boost::serialization::version<
                    STREAMS_BOOST_DEDUCED_TYPENAME Container::value_type
                >::value
            );
        ar << streams_boost::serialization::make_nvp("item", *it++);
    }
}

} // namespace stl 
} // namespace serialization
} // namespace streams_boost

#endif //STREAMS_BOOST_SERIALIZATION_COLLECTIONS_SAVE_IMP_HPP
