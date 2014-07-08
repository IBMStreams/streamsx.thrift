// Boost.Bimap
//
// Copyright (c) 2006-2007 Matias Capeletto
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

/// \file tags/support/default_tagged.hpp
/// \brief Weak tagging

#ifndef STREAMS_BOOST_BIMAP_TAGS_SUPPORT_DEFAULT_TAGGED_HPP
#define STREAMS_BOOST_BIMAP_TAGS_SUPPORT_DEFAULT_TAGGED_HPP

#if defined(_MSC_VER) && (_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/config.hpp>

#include <streams_boost/bimap/tags/tagged.hpp>

/** \struct streams_boost::bimaps::tags::support::default_tagged
\brief Weak tagging metafunction

\code
template< class Type, class Tag >
struct default_tagged
{
    typedef {TaggedType} type;
};
\endcode

If the type is not tagged, this metafunction returns a tagged type with the
default tag. If it is tagged, the returns the type unchanged.

See also tagged, overwrite_tagged.
                                                                                **/

#ifndef STREAMS_BOOST_BIMAP_DOXYGEN_WILL_NOT_PROCESS_THE_FOLLOWING_LINES

namespace streams_boost {
namespace bimaps {
namespace tags {
namespace support {


// Default Tagging
// A metafunction that create a tagged type with a default tag value.

template< class Type, class DefaultTag >
struct default_tagged
{
    typedef tagged<Type,DefaultTag> type;
};

template< class Type, class OldTag, class NewTag >
struct default_tagged< tagged< Type, OldTag >, NewTag >
{
    typedef tagged<Type,OldTag> type;
};

} // namespace support
} // namespace tags
} // namespace bimaps
} // namespace streams_boost

#endif // STREAMS_BOOST_BIMAP_DOXYGEN_WILL_NOT_PROCESS_THE_FOLLOWING_LINES

#endif // STREAMS_BOOST_BIMAP_TAGS_SUPPORT_DEFAULT_TAGGED_HPP



