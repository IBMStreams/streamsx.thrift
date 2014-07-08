#ifndef STREAMS_BOOST_SERIALIZATION_SCOPED_PTR_HPP_VP_2003_10_30
#define STREAMS_BOOST_SERIALIZATION_SCOPED_PTR_HPP_VP_2003_10_30

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

//  Copyright (c) 2003 Vladimir Prus.
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

// Provides non-intrusive serialization for streams_boost::scoped_ptr
// Does not allow to serialize scoped_ptr's to builtin types.

#include <streams_boost/config.hpp>

#include <streams_boost/scoped_ptr.hpp>
#include <streams_boost/serialization/nvp.hpp>
#include <streams_boost/serialization/split_free.hpp>

namespace streams_boost { 
namespace serialization {
    
    template<class Archive, class T>
    void save(
        Archive & ar, 
        const streams_boost::scoped_ptr<T> & t, 
        const unsigned int /* version */
    ){
        T* r = t.get();
        ar << streams_boost::serialization::make_nvp("scoped_ptr", r);
    }

    template<class Archive, class T>
    void load(
        Archive & ar, 
        streams_boost::scoped_ptr<T> & t, 
        const unsigned int /* version */
    ){
        T* r;
        ar >> streams_boost::serialization::make_nvp("scoped_ptr", r);
        t.reset(r); 
    }

    template<class Archive, class T>
    void serialize(
        Archive& ar, 
        streams_boost::scoped_ptr<T>& t, 
        const unsigned int version
    ){
        streams_boost::serialization::split_free(ar, t, version);
    }

} // namespace serialization
} // namespace streams_boost

#endif // STREAMS_BOOST_SERIALIZATION_SCOPED_PTR_HPP_VP_2003_10_30
