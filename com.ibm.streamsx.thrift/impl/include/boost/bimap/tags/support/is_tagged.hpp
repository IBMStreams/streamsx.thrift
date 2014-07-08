// Boost.Bimap
//
// Copyright (c) 2006-2007 Matias Capeletto
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

/// \file tags/support/is_tagged.hpp
/// \brief type_traits extension

#ifndef STREAMS_BOOST_BIMAP_TAGS_SUPPORT_IS_TAGGED_HPP
#define STREAMS_BOOST_BIMAP_TAGS_SUPPORT_IS_TAGGED_HPP

#if defined(_MSC_VER) && (_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/config.hpp>

#include <streams_boost/mpl/bool.hpp>
#include <streams_boost/bimap/tags/tagged.hpp>

/** \struct streams_boost::bimaps::tags::support::is_tagged
\brief Type trait to check if a type is tagged.

\code
template< class Type >
struct is_tagged
{
    typedef {mpl::true_/mpl::false_} type;
};
\endcode

See also tagged.
                                                                                **/

#ifndef STREAMS_BOOST_BIMAP_DOXYGEN_WILL_NOT_PROCESS_THE_FOLLOWING_LINES

namespace streams_boost {
namespace bimaps {
namespace tags {
namespace support {


// is_tagged metafunction

template< class Type >
struct is_tagged :
    ::streams_boost::mpl::false_ {};

template< class Type, class Tag >
struct is_tagged< tagged< Type, Tag > > :
    ::streams_boost::mpl::true_ {};

} // namespace support
} // namespace tags
} // namespace bimaps
} // namespace streams_boost

#endif // STREAMS_BOOST_BIMAP_DOXYGEN_WILL_NOT_PROCESS_THE_FOLLOWING_LINES

#endif // STREAMS_BOOST_BIMAP_TAGS_SUPPORT_IS_TAGGED_HPP

