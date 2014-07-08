// Boost.Bimap
//
// Copyright (c) 2006-2007 Matias Capeletto
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

/// \file list_of.hpp
/// \brief Include support for list constrains for the bimap container

#ifndef STREAMS_BOOST_BIMAP_LIST_OF_HPP
#define STREAMS_BOOST_BIMAP_LIST_OF_HPP

#if defined(_MSC_VER) && (_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/config.hpp>

#include <streams_boost/bimap/detail/user_interface_config.hpp>

#include <streams_boost/mpl/bool.hpp>

#include <streams_boost/concept_check.hpp>

#include <streams_boost/bimap/detail/concept_tags.hpp>

#include <streams_boost/bimap/tags/support/value_type_of.hpp>

#include <streams_boost/bimap/detail/generate_index_binder.hpp>
#include <streams_boost/bimap/detail/generate_view_binder.hpp>
#include <streams_boost/bimap/detail/generate_relation_binder.hpp>

#include <streams_boost/multi_index/sequenced_index.hpp>

#include <streams_boost/bimap/views/list_map_view.hpp>
#include <streams_boost/bimap/views/list_set_view.hpp>

namespace streams_boost {
namespace bimaps {


/// \brief Set Type Specification
/**
This struct is used to specify a set specification.
It is not a container, it is just a metaprogramming facility to
express the type of a set. Generally, this specification will
be used in other place to create a container.
It has the same syntax that an std::list instantiation, except
that the allocator cannot be specified. The rationale behind
this difference is that the allocator is not part of the set
type specification, rather it is a container configuration
parameter.

\code
using namespace support;

STREAMS_BOOST_STATIC_ASSERT( is_set_type_of< list_of<Type> >::value )

STREAMS_BOOST_STATIC_ASSERT
(
     is_same
     <
        list_of<Type>::index_bind
        <
            KeyExtractor,
            Tag

        >::type,

        sequenced< tag<Tag>, KeyExtractor >

    >::value
)

typedef bimap
<
    list_of<Type>, RightKeyType

> bimap_with_left_type_as_list;

STREAMS_BOOST_STATIC_ASSERT
(
    is_same
    <
        list_of<Type>::map_view_bind
        <
            member_at::left,
            bimap_with_left_type_as_list

        >::type,
        list_map_view< member_at::left, bimap_with_left_type_as_list >

    >::value
)

\endcode

See also list_of_relation.
                                                                        **/

template< class Type >
struct list_of : public ::streams_boost::bimaps::detail::set_type_of_tag
{
    /// User type, can be tagged
    typedef Type user_type;

    /// Type of the object that will be stored in the list
    typedef STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::bimaps::tags::support::
        value_type_of<user_type>::type value_type;


    struct lazy_concept_checked
    {
        STREAMS_BOOST_CLASS_REQUIRE ( value_type,
                              streams_boost, AssignableConcept );

        typedef list_of type;
    };

    STREAMS_BOOST_BIMAP_GENERATE_INDEX_BINDER_0CP_NO_EXTRACTOR(

        // binds to
        multi_index::sequenced
    )

    STREAMS_BOOST_BIMAP_GENERATE_MAP_VIEW_BINDER(

        // binds to
        views::list_map_view
    )

    STREAMS_BOOST_BIMAP_GENERATE_SET_VIEW_BINDER(

        // binds to
        views::list_set_view
    )

    typedef mpl::bool_<true> mutable_key;
};


/// \brief List Of Relation Specification
/**
This struct is similar to list_of but it is bind logically to a
relation. It is used in the bimap instantiation to specify the
desired type of the main view. This struct implements internally
a metafunction named bind_to that manages the quite complicated
task of finding the right type of the set for the relation.

\code
template<class Relation>
struct bind_to
{
    typedef -unspecified- type;
};
\endcode

See also list_of, is_set_type_of_relation.
                                                                **/

struct list_of_relation : public ::streams_boost::bimaps::detail::set_type_of_relation_tag
{
    STREAMS_BOOST_BIMAP_GENERATE_RELATION_BINDER_0CP(

        // binds to
        list_of
    )

    typedef mpl::bool_<true>  left_mutable_key;
    typedef mpl::bool_<true> right_mutable_key;
};


} // namespace bimaps
} // namespace streams_boost


#endif // STREAMS_BOOST_BIMAP_LIST_OF_HPP

