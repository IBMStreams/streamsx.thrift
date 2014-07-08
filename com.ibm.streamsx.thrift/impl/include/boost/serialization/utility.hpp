#ifndef  STREAMS_BOOST_SERIALIZATION_UTILITY_HPP
#define STREAMS_BOOST_SERIALIZATION_UTILITY_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// serialization/utility.hpp:
// serialization for stl utility templates

// (C) Copyright 2002 Robert Ramey - http://www.rrsd.com . 
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org for updates, documentation, and revision history.

#include <utility>
#include <streams_boost/config.hpp>

#include <streams_boost/type_traits/remove_const.hpp>
#include <streams_boost/serialization/nvp.hpp>
#include <streams_boost/serialization/is_bitwise_serializable.hpp>
#include <streams_boost/mpl/and.hpp>

namespace streams_boost { 
namespace serialization {

// pair
template<class Archive, class F, class S>
inline void serialize(
    Archive & ar,
    std::pair<F, S> & p,
    const unsigned int /* file_version */
){
    // note: we remove any const-ness on the first argument.  The reason is that 
    // for stl maps, the type saved is pair<const key, T).  We remove
    // the const-ness in order to be able to load it.
    typedef STREAMS_BOOST_DEDUCED_TYPENAME streams_boost::remove_const<F>::type typef;
    ar & streams_boost::serialization::make_nvp("first", const_cast<typef &>(p.first));
    ar & streams_boost::serialization::make_nvp("second", p.second);
}

/// specialization of is_bitwise_serializable for pairs
template <class T, class U>
struct is_bitwise_serializable<std::pair<T,U> >
 : public mpl::and_<is_bitwise_serializable<T>,is_bitwise_serializable<U> >
{
};

} // serialization
} // namespace streams_boost

#endif // STREAMS_BOOST_SERIALIZATION_UTILITY_HPP
