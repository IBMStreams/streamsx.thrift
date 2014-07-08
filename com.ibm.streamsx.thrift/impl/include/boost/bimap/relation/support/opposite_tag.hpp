// Boost.Bimap
//
// Copyright (c) 2006-2007 Matias Capeletto
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

/// \file relation/support/opposite_tag.hpp
/// \brief Metafunction to obtain the opposite tag in a relation.

#ifndef STREAMS_BOOST_BIMAP_RELATION_SUPPORT_OPPOSITE_TAG_HPP
#define STREAMS_BOOST_BIMAP_RELATION_SUPPORT_OPPOSITE_TAG_HPP

#if defined(_MSC_VER) && (_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/config.hpp>

#include <streams_boost/bimap/relation/detail/metadata_access_builder.hpp>

/** \struct streams_boost::bimaps::relation::support::opposite_tag

\brief Metafunction to obtain the opposite tag in a relation.

\code

template< class Tag, class Relation >
struct opposite_tag
{
        typedef {OppositeTag} type;
};

\endcode

\ingroup relation_group
                                                                    **/

namespace streams_boost {
namespace bimaps {
namespace relation {
namespace support {

// Implementation of const pair reference type by metafunction

STREAMS_BOOST_BIMAP_SYMMETRIC_METADATA_ACCESS_BUILDER
(
    opossite_tag,
    right_tag,
    left_tag
)

} // namespace support
} // namespace relation
} // namespace bimaps
} // namespace streams_boost


#endif // STREAMS_BOOST_BIMAP_RELATION_SUPPORT_OPPOSITE_TAG_HPP

