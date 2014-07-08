// Boost.Bimap
//
// Copyright (c) 2006-2007 Matias Capeletto
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

/// \file tags/support/apply_to_value_type.hpp
/// \brief Similar to mpl::apply but for tagged types.

#ifndef STREAMS_BOOST_BIMAP_TAGS_SUPPORT_APPLY_TO_VALUE_TYPE_HPP
#define STREAMS_BOOST_BIMAP_TAGS_SUPPORT_APPLY_TO_VALUE_TYPE_HPP

#if defined(_MSC_VER) && (_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/config.hpp>

#include <streams_boost/bimap/tags/tagged.hpp>
#include <streams_boost/mpl/apply.hpp>

/** \struct streams_boost::bimaps::tags::support::apply_to_value_type
\brief Higger order metafunction similar to mpl::apply but for tagged types.

\code
template< class Metafunction, class TaggedType >
struct apply_to_value_type
{
    typedef tagged
    <
        Metafuntion< value_type_of< TaggedType >::type >::type,
        tag_of< TaggedType >::type

    > type;
};
\endcode

This higher order metafunctions is very useful, and it can be used with lambda
expresions.

See also tagged.
                                                                                **/

#ifndef STREAMS_BOOST_BIMAP_DOXYGEN_WILL_NOT_PROCESS_THE_FOLLOWING_LINES

namespace streams_boost {
namespace bimaps {
namespace tags {
namespace support {

template < class F, class TaggedType >
struct apply_to_value_type;

template < class F, class ValueType, class Tag >
struct apply_to_value_type<F, tagged<ValueType,Tag> >
{
    typedef STREAMS_BOOST_DEDUCED_TYPENAME mpl::apply< F, ValueType >::type new_value_type;
    typedef tagged< new_value_type, Tag > type;
};

} // namespace support
} // namespace tags
} // namespace bimaps
} // namespace streams_boost

#endif // STREAMS_BOOST_BIMAP_DOXYGEN_WILL_NOT_PROCESS_THE_FOLLOWING_LINES

#endif // STREAMS_BOOST_BIMAP_TAGS_SUPPORT_APPLY_TO_VALUE_TYPE_HPP
