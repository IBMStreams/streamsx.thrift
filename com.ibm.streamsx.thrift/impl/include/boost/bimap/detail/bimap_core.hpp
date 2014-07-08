// Boost.Bimap
//
// Copyright (c) 2006-2007 Matias Capeletto
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

/// \file detail/bimap_core.hpp
/// \brief Bimap base definition.

#ifndef STREAMS_BOOST_BIMAP_DETAIL_BIMAP_CORE_HPP
#define STREAMS_BOOST_BIMAP_DETAIL_BIMAP_CORE_HPP

#if defined(_MSC_VER) && (_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/config.hpp>

#include <streams_boost/mpl/placeholders.hpp>
#include <streams_boost/mpl/push_front.hpp>
#include <streams_boost/mpl/if.hpp>
#include <streams_boost/mpl/and.hpp>
#include <streams_boost/mpl/not.hpp>
#include <streams_boost/mpl/vector.hpp>

#include <streams_boost/type_traits/add_const.hpp>
#include <streams_boost/type_traits/is_same.hpp>

#include <streams_boost/concept_check.hpp>

// Boost.MultiIndex
#include <streams_boost/multi_index_container.hpp>
#include <streams_boost/multi_index/member.hpp>

// Boost.Bimap
#include <streams_boost/bimap/relation/mutant_relation.hpp>
#include <streams_boost/bimap/relation/member_at.hpp>
#include <streams_boost/bimap/relation/support/data_extractor.hpp>
#include <streams_boost/bimap/tags/support/default_tagged.hpp>
#include <streams_boost/bimap/tags/tagged.hpp>
#include <streams_boost/bimap/detail/manage_bimap_key.hpp>
#include <streams_boost/bimap/detail/manage_additional_parameters.hpp>
#include <streams_boost/bimap/detail/map_view_iterator.hpp>
#include <streams_boost/bimap/detail/set_view_iterator.hpp>

#include <streams_boost/bimap/set_of.hpp>
#include <streams_boost/bimap/unconstrained_set_of.hpp>

namespace streams_boost {
namespace bimaps {

/// \brief Library details

namespace detail {

#ifndef STREAMS_BOOST_BIMAP_DOXYGEN_WILL_NOT_PROCESS_THE_FOLLOWING_LINES

template< class Type >
struct get_value_type
{
    typedef STREAMS_BOOST_DEDUCED_TYPENAME Type::value_type type;
};

struct independent_index_tag {};

#endif // STREAMS_BOOST_BIMAP_DOXYGEN_WILL_NOT_PROCESS_THE_FOLLOWING_LINES


/// \brief Base for the bimap class.
/**


See also bimap.
                                                                        **/


template< class LeftSetType, class RightSetType, class AP1, class AP2, class AP3 >
class bimap_core
{
    // Manage bimap key instantiation
    // --------------------------------------------------------------------
    public:

    typedef STREAMS_BOOST_DEDUCED_TYPENAME manage_bimap_key
    <
        LeftSetType

    >::type left_set_type;

    typedef STREAMS_BOOST_DEDUCED_TYPENAME manage_bimap_key
    <
        RightSetType

    >::type right_set_type;


    private:

    typedef STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::bimaps::tags::support::default_tagged
    <
        STREAMS_BOOST_DEDUCED_TYPENAME left_set_type::user_type,
        ::streams_boost::bimaps::relation::member_at::left

    >::type left_tagged_type;

    typedef STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::bimaps::tags::support::default_tagged
    <
        STREAMS_BOOST_DEDUCED_TYPENAME right_set_type::user_type,
        ::streams_boost::bimaps::relation::member_at::right

    >::type right_tagged_type;

    public:

    //@{

        typedef STREAMS_BOOST_DEDUCED_TYPENAME  left_tagged_type::tag  left_tag;
        typedef STREAMS_BOOST_DEDUCED_TYPENAME right_tagged_type::tag right_tag;

    //@}

    //@{

        typedef STREAMS_BOOST_DEDUCED_TYPENAME  left_set_type::value_type  left_key_type;
        typedef STREAMS_BOOST_DEDUCED_TYPENAME right_set_type::value_type right_key_type;

    //@}

    //@{

        typedef right_key_type  left_data_type;
        typedef  left_key_type right_data_type;

    //@}

    // Manage the additional parameters
    // --------------------------------------------------------------------
    private:

    typedef STREAMS_BOOST_DEDUCED_TYPENAME manage_additional_parameters<AP1,AP2,AP3>::type parameters;

    /// \brief Relation type stored by the bimap.
    // --------------------------------------------------------------------
    public:

    typedef ::streams_boost::bimaps::relation::mutant_relation
    <

        ::streams_boost::bimaps::tags::tagged<
            STREAMS_BOOST_DEDUCED_TYPENAME mpl::if_<
                mpl::and_
                <
                    STREAMS_BOOST_DEDUCED_TYPENAME left_set_type::mutable_key,
                    STREAMS_BOOST_DEDUCED_TYPENAME parameters::set_type_of_relation::left_mutable_key
                >,
            // {
                    left_key_type,
            // }
            // else
            // {
                    STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::add_const< left_key_type >::type
            // }

            >::type,
            left_tag
        >,

        ::streams_boost::bimaps::tags::tagged<
            STREAMS_BOOST_DEDUCED_TYPENAME mpl::if_<
                mpl::and_
                <
                    STREAMS_BOOST_DEDUCED_TYPENAME right_set_type::mutable_key,
                    STREAMS_BOOST_DEDUCED_TYPENAME parameters::set_type_of_relation::right_mutable_key
                >,
            // {
                    right_key_type,
            // }
            // else
            // {
                    STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::add_const< right_key_type >::type
            // }

            >::type,
            right_tag
        >,

        // It is ::streams_boost::mpl::na if no info_hook was included
        STREAMS_BOOST_DEDUCED_TYPENAME parameters::additional_info,

        // Force mutable keys
        true

    > relation;

    //@{

        typedef STREAMS_BOOST_DEDUCED_TYPENAME relation::left_pair  left_value_type;
        typedef STREAMS_BOOST_DEDUCED_TYPENAME relation::right_pair right_value_type;

    //@}

    // Bind the member of the relation, so multi_index can manage them
    // --------------------------------------------------------------------
    private:

    typedef STREAMS_BOOST_DEDUCED_TYPENAME relation::storage_base relation_storage_base;

    typedef STREAMS_BOOST_MULTI_INDEX_MEMBER(relation_storage_base, left_key_type, left)
        left_member_extractor;

    typedef STREAMS_BOOST_MULTI_INDEX_MEMBER(relation_storage_base,right_key_type,right)
        right_member_extractor;

    // The core indices are somewhat complicated to calculate, because they
    // can be zero, one, two or three indices, depending on the use of
    // {side}_based set type of relations and unconstrained_set_of and
    // unconstrained_set_of_relation specifications.

    typedef STREAMS_BOOST_DEDUCED_TYPENAME mpl::if_<
        ::streams_boost::bimaps::detail::is_unconstrained_set_of< left_set_type >,
    // {
            mpl::vector<>,
    // }
    // else
    // {
            mpl::vector
            <
                STREAMS_BOOST_DEDUCED_TYPENAME left_set_type::
                STREAMS_BOOST_NESTED_TEMPLATE index_bind
                <
                    left_member_extractor,
                    left_tag

                >::type
            >
    // }
    >::type left_core_indices;

    typedef STREAMS_BOOST_DEDUCED_TYPENAME mpl::if_<
        ::streams_boost::bimaps::detail::is_unconstrained_set_of< right_set_type >,
    // {
            left_core_indices,
    // }
    // else
    // {
            STREAMS_BOOST_DEDUCED_TYPENAME mpl::push_front
            <
                left_core_indices,

                STREAMS_BOOST_DEDUCED_TYPENAME right_set_type::
                STREAMS_BOOST_NESTED_TEMPLATE index_bind
                <
                    right_member_extractor,
                    right_tag

                >::type

            >::type
    // }
    >::type basic_core_indices;

    // If it is based either on the left or on the right, then only the side
    // indices are needed. But the set type of the relation can be completely
    // diferent from the one used for the sides in wich case we have to add yet
    // another index to the core.

    // TODO
    // If all the set types are unsconstrained there must be readable compile
    // time error.

    typedef STREAMS_BOOST_DEDUCED_TYPENAME mpl::if_<

        is_same< STREAMS_BOOST_DEDUCED_TYPENAME parameters::set_type_of_relation, left_based >,
    // {
            ::streams_boost::bimaps::tags::tagged< left_set_type, left_tag >,
    // }
    /* else */ STREAMS_BOOST_DEDUCED_TYPENAME mpl::if_<
            is_same< STREAMS_BOOST_DEDUCED_TYPENAME parameters::set_type_of_relation, right_based >,
    // {
            ::streams_boost::bimaps::tags::tagged< right_set_type, right_tag >,
    // }
    // else
    // {
            tags::tagged
            <
                STREAMS_BOOST_DEDUCED_TYPENAME parameters::
                set_type_of_relation::STREAMS_BOOST_NESTED_TEMPLATE bind_to
                <
                    relation

                >::type,
                independent_index_tag
            >
    // }
    >::type
    >::type tagged_set_of_relation_type;

    protected:

    typedef STREAMS_BOOST_DEDUCED_TYPENAME tagged_set_of_relation_type::tag
                        relation_set_tag;

    typedef STREAMS_BOOST_DEDUCED_TYPENAME tagged_set_of_relation_type::value_type
                        relation_set_type_of;

    // Logic tags
    // This is a necesary extra level of indirection to allow unconstrained
    // sets to be plug in the design. The bimap constructors use this logic
    // tags.

    typedef STREAMS_BOOST_DEDUCED_TYPENAME mpl::if_<
        ::streams_boost::bimaps::detail::is_unconstrained_set_of< left_set_type >,

        STREAMS_BOOST_DEDUCED_TYPENAME mpl::if_<
            ::streams_boost::bimaps::detail::is_unconstrained_set_of< right_set_type >,

            independent_index_tag,
            right_tag

        >::type,

        left_tag

    >::type logic_left_tag;

    typedef STREAMS_BOOST_DEDUCED_TYPENAME mpl::if_<
        ::streams_boost::bimaps::detail::is_unconstrained_set_of< right_set_type >,

        STREAMS_BOOST_DEDUCED_TYPENAME mpl::if_< 
            ::streams_boost::bimaps::detail::is_unconstrained_set_of< left_set_type >,

            independent_index_tag,
            left_tag

        >::type,

        right_tag

    >::type logic_right_tag;

    typedef STREAMS_BOOST_DEDUCED_TYPENAME mpl::if_< 
        is_same< relation_set_tag, independent_index_tag >,

        STREAMS_BOOST_DEDUCED_TYPENAME mpl::if_< 
            ::streams_boost::bimaps::detail::
                is_unconstrained_set_of< relation_set_type_of >,

            logic_left_tag,
            independent_index_tag

        >::type,

        STREAMS_BOOST_DEDUCED_TYPENAME mpl::if_<
            is_same< STREAMS_BOOST_DEDUCED_TYPENAME parameters::set_type_of_relation, left_based >,

            logic_left_tag,
            logic_right_tag

        >::type

    >::type logic_relation_set_tag;

    private:

    typedef STREAMS_BOOST_DEDUCED_TYPENAME mpl::if_<
        mpl::and_< is_same< relation_set_tag, independent_index_tag >,
                   mpl::not_<
                       ::streams_boost::bimaps::detail::
                            is_unconstrained_set_of< relation_set_type_of > 
                   >
        >,
    // {
            STREAMS_BOOST_DEDUCED_TYPENAME mpl::push_front
            <
                basic_core_indices,

                STREAMS_BOOST_DEDUCED_TYPENAME relation_set_type_of::
                STREAMS_BOOST_NESTED_TEMPLATE index_bind
                <
                    ::streams_boost::bimaps::relation::support::both_keys_extractor<relation>,
                    independent_index_tag

                >::type

            >::type,
    // }
    // else
    // {
            basic_core_indices
    // }

    >::type complete_core_indices;

    struct core_indices : public complete_core_indices {};

    // Define the core using compute_index_type to translate the
    // set type to an multi-index specification
    // --------------------------------------------------------------------
    public:

    typedef multi_index::multi_index_container
    <
        relation,
        core_indices,
        STREAMS_BOOST_DEDUCED_TYPENAME parameters::allocator::
            STREAMS_BOOST_NESTED_TEMPLATE rebind<relation>::other

    > core_type;

    // Core metadata
    // --------------------------------------------------------------------
    public:

    typedef STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::multi_index::
        index<core_type, logic_left_tag>::type  left_index;

    typedef STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::multi_index::
        index<core_type,logic_right_tag>::type right_index;

    typedef STREAMS_BOOST_DEDUCED_TYPENAME  left_index::iterator        left_core_iterator;
    typedef STREAMS_BOOST_DEDUCED_TYPENAME  left_index::const_iterator  left_core_const_iterator;

    typedef STREAMS_BOOST_DEDUCED_TYPENAME right_index::iterator       right_core_iterator;
    typedef STREAMS_BOOST_DEDUCED_TYPENAME right_index::const_iterator right_core_const_iterator;

    // Map by {side} iterator metadata
    // --------------------------------------------------------------------
    public:

    //@{

        typedef ::streams_boost::bimaps::detail::map_view_iterator
        <
            left_tag,
            relation,
            left_core_iterator

        > left_iterator;

        typedef ::streams_boost::bimaps::detail::map_view_iterator
        <
            right_tag,
            relation,
            right_core_iterator

        > right_iterator;

    //@}

    //@{

        typedef ::streams_boost::bimaps::detail::const_map_view_iterator
        <
            left_tag,
            relation,
            left_core_const_iterator

        > left_const_iterator;

        typedef ::streams_boost::bimaps::detail::const_map_view_iterator
        <
            right_tag,
            relation,
            right_core_const_iterator

        > right_const_iterator;

    //@}

    // Relation set view

    typedef STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::multi_index::index
    <
        core_type, logic_relation_set_tag

    >::type relation_set_core_index;

    typedef STREAMS_BOOST_DEDUCED_TYPENAME relation_set_type_of::
    STREAMS_BOOST_NESTED_TEMPLATE set_view_bind
    <
        relation_set_core_index

    >::type relation_set;

    public:

    typedef bimap_core bimap_core_;
};

// Two auxiliar metafunctions to compute the map view types
// The map view type can not be computed inside the bimap core because a 
// they need the bimap core to be parsed first.

template< class BimapBaseType >
struct left_map_view_type
{
    typedef STREAMS_BOOST_DEDUCED_TYPENAME BimapBaseType::left_set_type left_set_type;
    typedef STREAMS_BOOST_DEDUCED_TYPENAME
        left_set_type::STREAMS_BOOST_NESTED_TEMPLATE map_view_bind<
            STREAMS_BOOST_DEDUCED_TYPENAME BimapBaseType::left_tag, BimapBaseType
        >::type type;
};

template< class BimapBaseType >
struct right_map_view_type
{
    typedef STREAMS_BOOST_DEDUCED_TYPENAME BimapBaseType::right_set_type right_set_type;
    typedef STREAMS_BOOST_DEDUCED_TYPENAME
        right_set_type::STREAMS_BOOST_NESTED_TEMPLATE map_view_bind<
            STREAMS_BOOST_DEDUCED_TYPENAME BimapBaseType::right_tag, BimapBaseType
        >::type type;
};

} // namespace detail
} // namespace bimaps
} // namespace streams_boost

#endif // STREAMS_BOOST_BIMAP_DETAIL_BIMAP_CORE_HPP
