// Boost.Bimap
//
// Copyright (c) 2006-2007 Matias Capeletto
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

/// \file relation/support/is_tag_of_member_at.hpp
/// \brief is_tag_of_member_at<tag,relation> metafunction

#ifndef STREAMS_BOOST_BIMAP_RELATION_SUPPORT_IS_TAG_OF_MEMBER_AT_HPP
#define STREAMS_BOOST_BIMAP_RELATION_SUPPORT_IS_TAG_OF_MEMBER_AT_HPP

#if defined(_MSC_VER) && (_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/config.hpp>

#include <streams_boost/bimap/relation/member_at.hpp>
#include <streams_boost/type_traits/is_same.hpp>

#include <streams_boost/mpl/bool.hpp>
#include <streams_boost/utility/enable_if.hpp>
#include <streams_boost/bimap/relation/support/member_with_tag.hpp>

/** \struct streams_boost::bimaps::relation::support::is_tag_of_member_at_left

\brief Metafunction to test if a user tag is refering to the left member.

\code

template< class Tag, class Relation >
struct is_tag_of_member_at_left : {true_|false_} {};

\endcode

This metafunction is somewhat redundant with member_with_tag, but it is included
because it is a lot easier to metaprogram with it. The result type is the
same that:

\code

 is_same< member_with_tag<Tag,Relation>::type , member_at::left >::type

\endcode

See also member_with_tag, member_at, is_tag_of_member_at_right.
\ingroup relation_group
                                                                             **/


/** \struct streams_boost::bimaps::relation::support::is_tag_of_member_at_right

\brief Metafunction to test if a user tag is refering to the left member.

\code

template< class Tag, class Relation >
struct is_tag_of_member_at_right : {true_|false_} {};

\endcode

This metafunction is somewhat redundat with member_with_tag, but it is included
because it is a lot easier to metaprogram with it. The result type is the
same that:

\code

 is_same< member_with_tag<Tag,Relation>::type , member_at::right >::type

\endcode

See also member_with_tag, member_at, is_tag_of_member_at_left.
\ingroup relation_group
                                                                             **/


#ifndef STREAMS_BOOST_BIMAP_DOXYGEN_WILL_NOT_PROCESS_THE_FOLLOWING_LINES

namespace streams_boost {
namespace bimaps {
namespace relation {
namespace support {

// Metafunction is_tag_of_member_at_left
// Easiear metaprogramming

template
<
    class Tag,
    class Relation,
    class Enable = void
>
struct is_tag_of_member_at_left :
    ::streams_boost::mpl::false_ {};

template< class Tag, class Relation >
struct is_tag_of_member_at_left
<
    Tag, Relation,
    STREAMS_BOOST_DEDUCED_TYPENAME enable_if
    <
        is_same
        <
            STREAMS_BOOST_DEDUCED_TYPENAME member_with_tag<Tag,Relation>::type,
            member_at::left
        >

    >::type
> :
    ::streams_boost::mpl::true_ {};

// Metafunction is_tag_of_member_at_right
// Easiear metaprogramming

template
<
    class Tag,
    class Relation,
    class Enable = void
>
struct is_tag_of_member_at_right :
    ::streams_boost::mpl::false_ {};

template< class Tag, class Relation >
struct is_tag_of_member_at_right
<
    Tag, Relation,
    STREAMS_BOOST_DEDUCED_TYPENAME enable_if
    <
        is_same
        <
            STREAMS_BOOST_DEDUCED_TYPENAME member_with_tag<Tag,Relation>::type,
            member_at::right
        >

    >::type
> :
    ::streams_boost::mpl::true_ {};


// Metafunction is_tag_of_member_at_info
// Easiear metaprogramming

template
<
    class Tag,
    class Relation,
    class Enable = void
>
struct is_tag_of_member_at_info :
    ::streams_boost::mpl::false_ {};

template< class Tag, class Relation >
struct is_tag_of_member_at_info
<
    Tag, Relation,
    STREAMS_BOOST_DEDUCED_TYPENAME enable_if
    <
        is_same
        <
            STREAMS_BOOST_DEDUCED_TYPENAME member_with_tag<Tag,Relation>::type,
            member_at::info
        >

    >::type
> :
    ::streams_boost::mpl::true_ {};

} // namespace support
} // namespace relation
} // namespace bimaps
} // namespace streams_boost

#endif // STREAMS_BOOST_BIMAP_DOXYGEN_WILL_NOT_PROCESS_THE_FOLLOWING_LINES

#endif // STREAMS_BOOST_BIMAP_RELATION_SUPPORT_IS_TAG_OF_MEMBER_AT_HPP


