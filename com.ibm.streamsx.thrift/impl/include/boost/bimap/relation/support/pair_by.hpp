// Boost.Bimap
//
// Copyright (c) 2006-2007 Matias Capeletto
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

/// \file relation/support/pair_by.hpp
/// \brief pair_by<member>(r) function

#ifndef STREAMS_BOOST_BIMAP_RELATION_SUPPORT_PAIR_BY_HPP
#define STREAMS_BOOST_BIMAP_RELATION_SUPPORT_PAIR_BY_HPP

#if defined(_MSC_VER) && (_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/config.hpp>

#include <streams_boost/bimap/relation/support/pair_type_by.hpp>
#include <streams_boost/bimap/relation/detail/access_builder.hpp>

#ifdef STREAMS_BOOST_BIMAP_ONLY_DOXYGEN_WILL_PROCESS_THE_FOLLOWING_LINES

namespace streams_boost {
namespace bimaps {
namespace relation {
namespace support {

/** \brief Gets a pair view of the relation.

\ingroup relation_group
                                                                        **/

template< class Tag, class Relation >
STREAMS_BOOST_DEDUCED_TYPENAME result_of::pair_by<Tag,Relation>::type
    pair_by( Relation & rel );

} // namespace support
} // namespace relation
} // namespace bimaps
} // namespace streams_boost

#endif // STREAMS_BOOST_BIMAP_ONLY_DOXYGEN_WILL_PROCESS_THE_FOLLOWING_LINES


#ifndef STREAMS_BOOST_BIMAP_DOXYGEN_WILL_NOT_PROCESS_THE_FOLLOWING_LINES

namespace streams_boost {
namespace bimaps {
namespace relation {
namespace support {


// Since it is very error-prone to directly write the hole bunch
// of relation accesor. They are buil from litle macro blocks that
// are both more readable, leading to self docummenting code and a
// lot more easier to understand and mantain.
// It is very important to note that the three building blocks have
// to laid in the same namespace in order to work. There is also
// important to keep them in order.
// The forward declaration are not necesary but they help a lot to
// the reader, as they undercover what is the signature of the
// result code.
// In the end, it is not quicker to do it in this way because you
// write a lot. But this code has no complexity at all and almost
// every word writed is for documentation.

// Result of
// -------------------------------------------------------------------------
/*
    namespace result_of {

    template< class Tag, class Relation >
    struct pair_by<Tag,Relation>;
    {
        typedef -unspecified- type;
    };

    } // namespace result_of
*/

STREAMS_BOOST_BIMAP_SYMMETRIC_ACCESS_RESULT_OF_BUILDER
(
    pair_by,
    pair_type_by
)



// Implementation
// -------------------------------------------------------------------------

STREAMS_BOOST_BIMAP_SYMMETRIC_ACCESS_IMPLEMENTATION_BUILDER
(
    pair_by,
    Relation,
    rel,
    return rel.get_left_pair(),
    return rel.get_right_pair()
)

// Interface
// --------------------------------------------------------------------------

STREAMS_BOOST_BIMAP_SYMMETRIC_ACCESS_INTERFACE_BUILDER
(
    pair_by
)

} // namespace support
} // namespace relation
} // namespace bimaps
} // namespace streams_boost


#endif // STREAMS_BOOST_BIMAP_DOXIGEN_WILL_NOT_PROCESS_THE_FOLLOWING_LINES

#endif // STREAMS_BOOST_BIMAP_RELATION_SUPPORT_PAIR_BY_HPP
