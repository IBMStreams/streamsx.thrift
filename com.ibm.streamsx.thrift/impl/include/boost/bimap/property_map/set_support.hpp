// Boost.Bimap
//
// Copyright (c) 2006-2007 Matias Capeletto
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

/// \file property_map/set_support.hpp
/// \brief Support for the property map concept.

#ifndef STREAMS_BOOST_BIMAP_PROPERTY_MAP_SET_SUPPORT_HPP
#define STREAMS_BOOST_BIMAP_PROPERTY_MAP_SET_SUPPORT_HPP

#if defined(_MSC_VER) && (_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/config.hpp>

#include <streams_boost/property_map/property_map.hpp>
#include <streams_boost/bimap/set_of.hpp>
#include <streams_boost/bimap/support/data_type_by.hpp>
#include <streams_boost/bimap/support/key_type_by.hpp>

#ifndef STREAMS_BOOST_BIMAP_DOXYGEN_WILL_NOT_PROCESS_THE_FOLLOWING_LINES

namespace streams_boost {

template< class Tag, class Bimap >
struct property_traits< ::streams_boost::bimaps::views::map_view<Tag,Bimap> >
{
    typedef STREAMS_BOOST_DEDUCED_TYPENAME
        ::streams_boost::bimaps::support::data_type_by<Tag,Bimap>::type value_type;
    typedef STREAMS_BOOST_DEDUCED_TYPENAME
        ::streams_boost::bimaps::support:: key_type_by<Tag,Bimap>::type   key_type;

    typedef readable_property_map_tag category;
};


template< class Tag, class Bimap >
const STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::bimaps::support::data_type_by<Tag,Bimap>::type &
    get(const ::streams_boost::bimaps::views::map_view<Tag,Bimap> & m,
        const STREAMS_BOOST_DEDUCED_TYPENAME
            ::streams_boost::bimaps::support::key_type_by<Tag,Bimap>::type & key)
{
    return m.at(key);
}

} // namespace streams_boost

#endif // STREAMS_BOOST_BIMAP_DOXYGEN_WILL_NOT_PROCESS_THE_FOLLOWING_LINES

#endif // STREAMS_BOOST_BIMAP_PROPERTY_MAP_SET_SUPPORT_HPP
