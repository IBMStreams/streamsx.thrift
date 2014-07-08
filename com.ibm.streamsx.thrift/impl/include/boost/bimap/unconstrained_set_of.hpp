// Boost.Bimap
//
// Copyright (c) 2006-2007 Matias Capeletto
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

/// \file unconstrained_set_of.hpp
/// \brief Include support for set constrains for the bimap container

#ifndef STREAMS_BOOST_BIMAP_UNCONSTRAINED_SET_OF_HPP
#define STREAMS_BOOST_BIMAP_UNCONSTRAINED_SET_OF_HPP

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

#include <streams_boost/bimap/views/unconstrained_map_view.hpp>
#include <streams_boost/bimap/views/unconstrained_set_view.hpp>

namespace streams_boost {
namespace bimaps {

/// \brief Set Type Specification
/**
This struct is used to specify a set specification.
It is not a container, it is just a metaprogramming facility to
express the type of a set. Generally, this specification will
be used in other place to create a container.
The first parameter is the type of the objects in the set.

\code

using namespace support;

STREAMS_BOOST_STATIC_ASSERT( is_set_type_of< unconstrained_set_of<Type> >::value )

\endcode

See also unconstrained_set_of_relation.
                                                                        **/

template
<
    class KeyType
>
struct unconstrained_set_of : public ::streams_boost::bimaps::detail::set_type_of_tag
{
    /// User type, can be tagged
    typedef KeyType user_type;

    /// Type of the object that will be stored in the container
    typedef STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::bimaps::tags::support::
        value_type_of<user_type>::type value_type;

    struct lazy_concept_checked
    {
        STREAMS_BOOST_CLASS_REQUIRE ( value_type,
                              streams_boost, AssignableConcept );

        typedef unconstrained_set_of type;
    };

    STREAMS_BOOST_BIMAP_GENERATE_INDEX_BINDER_FAKE

    STREAMS_BOOST_BIMAP_GENERATE_MAP_VIEW_BINDER(

        // binds to
        views::unconstrained_map_view
    )

    STREAMS_BOOST_BIMAP_GENERATE_SET_VIEW_BINDER(

        // binds to
        views::unconstrained_set_view
    )

    typedef mpl::bool_<true> mutable_key;
};

/// \brief Set Of Relation Specification
/**
This struct is similar to unconstrained_set_of but it is bind
logically to a relation. It is used in the bimap instantiation to
specify the desired type of the main view.

See also unconstrained_set_of, is_set_type_of_relation.
                                                                **/

struct unconstrained_set_of_relation : public ::streams_boost::bimaps::detail::set_type_of_relation_tag
{

    STREAMS_BOOST_BIMAP_GENERATE_RELATION_BINDER_0CP(

        // binds to
        unconstrained_set_of
    )

    typedef mpl::bool_<true>  left_mutable_key;
    typedef mpl::bool_<true> right_mutable_key;
};

#ifndef STREAMS_BOOST_BIMAP_DOXYGEN_WILL_NOT_PROCESS_THE_FOLLOWING_LINES

namespace detail {

template<class T>
struct is_unconstrained_set_of :
    ::streams_boost::mpl::false_ {};

template<class T>
struct is_unconstrained_set_of< unconstrained_set_of<T> > :
    ::streams_boost::mpl::true_ {};

} // namespace detail

#endif // STREAMS_BOOST_BIMAP_DOXYGEN_WILL_NOT_PROCESS_THE_FOLLOWING_LINES

} // namespace bimaps
} // namespace streams_boost


/** \struct streams_boost::bimaps::detail::is_unconstrained_set_of
\brief Trait to check if a type is unconstrained_set_of.
\code
template< class T >
struct is_unconstrained_set_of;
\endcode
                                                                            **/


#endif // STREAMS_BOOST_BIMAP_UNCONSTRAINED_SET_OF_HPP

