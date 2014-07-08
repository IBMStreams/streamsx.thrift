// Boost.Bimap
//
// Copyright (c) 2006-2007 Matias Capeletto
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

/// \file multiset_of.hpp
/// \brief Include support for multiset constrains for the bimap container

#ifndef STREAMS_BOOST_BIMAP_MULTISET_OF_HPP
#define STREAMS_BOOST_BIMAP_MULTISET_OF_HPP

#if defined(_MSC_VER) && (_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/config.hpp>

#include <streams_boost/bimap/detail/user_interface_config.hpp>

#include <functional>
#include <streams_boost/mpl/bool.hpp>

#include <streams_boost/concept_check.hpp>

#include <streams_boost/bimap/detail/concept_tags.hpp>

#include <streams_boost/bimap/tags/support/value_type_of.hpp>

#include <streams_boost/bimap/detail/generate_index_binder.hpp>
#include <streams_boost/bimap/detail/generate_view_binder.hpp>
#include <streams_boost/bimap/detail/generate_relation_binder.hpp>

#include <streams_boost/multi_index/ordered_index.hpp>

#include <streams_boost/bimap/views/multimap_view.hpp>
#include <streams_boost/bimap/views/multiset_view.hpp>

namespace streams_boost {
namespace bimaps {

/// \brief Set Type Specification
/**
This struct is used to specify a multiset specification.
It is not a container, it is just a metaprogramming facility to
express the type of a set. Generally, this specification will
be used in other place to create a container.
It has the same syntax that an std::set instantiation, except
that the allocator cannot be specified. The rationale behind
this difference is that the allocator is not part of the set
type specification, rather it is a container configuration
parameter.
The first parameter is the type of the objects in the multiset,
and the second one is a Functor that compares them.
Bimap binding metafunctions can be used with this class in
the following way:

\code
using namespace support;

STREAMS_BOOST_STATIC_ASSERT( is_set_type_of< multiset_of<Type> >::value )

STREAMS_BOOST_STATIC_ASSERT
(
     is_same
     <
        compute_index_type
        <
            multiset_of<Type,KeyCompare>,
            KeyExtractor,
            Tag

        >::type
        ,
        ordered_nonunique< tag<Tag>, KeyExtractor, KeyCompare >

    >::value
)

typedef bimap
<
    multiset_of<Type>, RightKeyType

> bimap_with_left_type_as_multiset;

STREAMS_BOOST_STATIC_ASSERT
(
    is_same
    <
        compute_map_view_type
        <
            member_at::left,
            bimap_with_left_type_as_multiset

        >::type,
        multimap_view< member_at::left, bimap_with_left_type_as_multiset >

    >::value
)

\endcode

See also multiset_of_relation.
                                                                        **/

template
<
    class KeyType,
    class KeyCompare = std::less< STREAMS_BOOST_DEDUCED_TYPENAME
        ::streams_boost::bimaps::tags::support::value_type_of<KeyType>::type >
>
struct multiset_of : public ::streams_boost::bimaps::detail::set_type_of_tag
{
    /// User type, can be tagged
    typedef KeyType user_type;

    /// Type of the object that will be stored in the multiset
    typedef STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::bimaps::tags::support::
        value_type_of<user_type>::type value_type;

    /// Functor that compare two keys
    typedef KeyCompare key_compare;

    struct lazy_concept_checked
    {
        STREAMS_BOOST_CLASS_REQUIRE ( value_type,
                              streams_boost, AssignableConcept );

        STREAMS_BOOST_CLASS_REQUIRE4( key_compare, bool, value_type, value_type,
                              streams_boost, BinaryFunctionConcept );

        typedef multiset_of type;
    };

    STREAMS_BOOST_BIMAP_GENERATE_INDEX_BINDER_1CP(

        // binds to
        multi_index::ordered_non_unique,

        // with
        key_compare
    )

    STREAMS_BOOST_BIMAP_GENERATE_MAP_VIEW_BINDER(

        // binds to
        views::multimap_view
    )

    STREAMS_BOOST_BIMAP_GENERATE_SET_VIEW_BINDER(

        // binds to
        views::multiset_view
    )

    typedef mpl::bool_<false> mutable_key;
};


/// \brief Set Of Relation Specification
/**
This struct is similar to multiset_of but it is bind logically to a
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

See also multiset_of, is_set_type_of_relation.
                                                                **/

template< class KeyCompare = std::less< _relation > >
struct multiset_of_relation : public ::streams_boost::bimaps::detail::set_type_of_relation_tag
{
    /// Functor that compare two keys
    typedef KeyCompare key_compare;


    STREAMS_BOOST_BIMAP_GENERATE_RELATION_BINDER_1CP(

        // binds to
        multiset_of,

        // with
        key_compare
    )

    typedef mpl::bool_<false>  left_mutable_key;
    typedef mpl::bool_<false> right_mutable_key;
};

} // namespace bimaps
} // namespace streams_boost


#endif // STREAMS_BOOST_BIMAP_MULTISET_OF_HPP
