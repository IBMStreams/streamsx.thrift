// Boost.Bimap
//
// Copyright (c) 2006-2007 Matias Capeletto
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

/// \file tags/support/tag_of.hpp
/// \brief Safe way to acces the tag of a type

#ifndef STREAMS_BOOST_BIMAP_TAGS_SUPPORT_TAG_OF_HPP
#define STREAMS_BOOST_BIMAP_TAGS_SUPPORT_TAG_OF_HPP

#if defined(_MSC_VER) && (_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/config.hpp>

#include <streams_boost/bimap/tags/tagged.hpp>
#include <streams_boost/bimap/detail/debug/static_error.hpp>

/** \struct streams_boost::bimaps::tags::support::tag_of
\brief Metafunction to obtain the tag of a type.

\code
template< class TaggedType >
struct tag_of
{
    typedef {Tag} type;
};
\endcode

If the type is not tagged you will get a compile timer error with the following message:

\verbatim
USING_TAG_OF_WITH_AN_UNTAGGED_TYPE, TaggedType
\endverbatim

See also tagged, value_type_of.
                                                                                **/

#ifndef STREAMS_BOOST_BIMAP_DOXYGEN_WILL_NOT_PROCESS_THE_FOLLOWING_LINES

namespace streams_boost {
namespace bimaps {
namespace tags {
namespace support {


// tag_of metafunction

template< class Type >
struct tag_of
{
    STREAMS_BOOST_BIMAP_STATIC_ERROR( USING_TAG_OF_WITH_AN_UNTAGGED_TYPE, (Type) );
};

template< class Type, class Tag >
struct tag_of< tagged< Type, Tag > >
{
    typedef Tag type;
};


} // namespace support
} // namespace tags
} // namespace bimaps
} // namespace streams_boost

#endif // STREAMS_BOOST_BIMAP_DOXYGEN_WILL_NOT_PROCESS_THE_FOLLOWING_LINES

#endif // STREAMS_BOOST_BIMAP_TAGS_SUPPORT_TAG_OF_HPP

