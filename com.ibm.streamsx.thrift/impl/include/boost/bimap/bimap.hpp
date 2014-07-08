// Boost.Bimap
//
// Copyright (c) 2006-2007 Matias Capeletto
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

/// \file bimap.hpp
/// \brief Includes the basic bimap container

/** \mainpage notitle
\n
\image html http://matias.capeletto.googlepages.com/streams_boost.bimap.reference.logo.png

\section Introduction

This is the complete reference of Boost.Bimap.

After getting a good understanding of the library from a user perspective
the next step will be:

    - Understand the tagged idiom. (streams_boost::bimaps::tags)
    - Understand the internals of the relation class (streams_boost::bimaps::relation)
    - Read the container_adaptor toolbox docs (streams_boost::bimaps::container_adaptor)
    - Understand the internals of the bimap class. (streams_boost::bimaps, streams_boost::bimaps::views
      and streams_boost::bimaps::detail)


                                                                        **/

/** \defgroup mutant_group mutant idiom
\brief A safe wrapper around reinterpret_cast
                                                                        **/

/** \defgroup relation_group relation
\brief The relation
                                                                        **/

/** \defgroup tags_group tagged idiom
\brief The tagged idiom
                                                                        **/


#ifndef STREAMS_BOOST_BIMAP_BIMAP_HPP
#define STREAMS_BOOST_BIMAP_BIMAP_HPP

#if defined(_MSC_VER) && (_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/config.hpp>
#include <streams_boost/bimap/detail/user_interface_config.hpp>
#include <streams_boost/mpl/aux_/na.hpp>

#ifndef STREAMS_BOOST_BIMAP_DISABLE_SERIALIZATION
    #include <streams_boost/serialization/nvp.hpp>
#endif // STREAMS_BOOST_BIMAP_DISABLE_SERIALIZATION

// Boost.Bimap
#include <streams_boost/bimap/detail/bimap_core.hpp>
#include <streams_boost/bimap/detail/map_view_base.hpp>
#include <streams_boost/bimap/detail/modifier_adaptor.hpp>
#include <streams_boost/bimap/relation/support/data_extractor.hpp>
#include <streams_boost/bimap/relation/support/member_with_tag.hpp>

#include <streams_boost/bimap/support/map_type_by.hpp>
#include <streams_boost/bimap/support/map_by.hpp>
#include <streams_boost/bimap/support/iterator_type_by.hpp>

/// \brief The namespace where all the streams_boost libraries lives.

namespace streams_boost {

/// \brief Boost.Bimap library namespace
/**
All the entities in the library are defined in this namespace.
                                                                    **/
namespace bimaps {

/// \brief The bimap class is the entry point to the library.
/**
This class manages the instantiation of the desired bimap type.
As there are several types of bidirectional maps that can be
created using it. the main job of it is to find the desired
type. This is done using metaprogramming to obtain the relation
type that will be stored, the map_view type of each side and
the set_view type of the general relationship. The instantiation
is kept simple using an extended standard set theory, where a
bidirectional map type is defined by the set types it relates.
For example, a bidirectional map that has multimap semantics
viewed from both sides is defined by specifying that the two
keys sets are of \c multiset_of<Key> type.
This allows the bimap class to support seamingless N-N, 1-N,
ordered/unordered and even vector-list types of mapping.
The three last parameters are used to specify the set type of
the relation, an inplace hooked data class and the allocator
type. As a help to the bimap user, these parameters support
default types but use a special idiom that allow them to be
specified without interleaving the usual use_default keyword.
The possible bimap instantiation are enumerated here:
\c {Side}KeyType can be directly a type, this is default to
\c set_of<{Side}KeyType>, or can be a \c {SetType}_of<Type>
specification. Additionally this two parameters can be tagged
to specify others tags instead of the usual \c member_at::{Side}
ones.


\code

    typedef bimap
    <
        LeftCollectionType, RightCollectionType

        [ , SetTypeOfRelation  ]  // Default to left_based
        [ , info_hook< Info >  ]  // Default to no info
        [ , Allocator          ]  // Default to std::allocator<>

    > bm;

\endcode

                                                                       **/


template
<
    class KeyTypeA, class KeyTypeB,
    class AP1 = ::streams_boost::mpl::na,
    class AP2 = ::streams_boost::mpl::na,
    class AP3 = ::streams_boost::mpl::na
>
class bimap
:
    // Bimap Core, use mpl magic to find the desired bimap type

    public ::streams_boost::bimaps::detail::bimap_core<KeyTypeA,KeyTypeB,AP1,AP2,AP3>,

    // You can use bimap as a collection of relations

    public ::streams_boost::bimaps::detail::bimap_core<KeyTypeA,KeyTypeB,AP1,AP2,AP3>
                ::relation_set,

    // Include extra typedefs (i.e. left_local_iterator for unordered_map)

    public ::streams_boost::bimaps::detail:: left_map_view_extra_typedefs<
        STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::bimaps::detail::left_map_view_type<
            ::streams_boost::bimaps::detail::bimap_core<KeyTypeA,KeyTypeB,AP1,AP2,AP3>
        >::type
    >,
    public ::streams_boost::bimaps::detail::right_map_view_extra_typedefs< 
        STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::bimaps::detail::right_map_view_type<
            ::streams_boost::bimaps::detail::bimap_core<KeyTypeA,KeyTypeB,AP1,AP2,AP3>
        >::type
    >
{
    typedef STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::bimaps::detail::
        bimap_core<KeyTypeA,KeyTypeB,AP1,AP2,AP3> base_;

    STREAMS_BOOST_DEDUCED_TYPENAME base_::core_type core;

    public:

    // metadata --------------------------------------------------------

    /*
    // The rest is computed in the core, because it is quite difficult to
    // expose a nice interface with so many metaprogramming stuff.
    // Here it is the complete metadat list.

    // Map by {side} metadata

    typedef -unspecified- {side}_tag;
    typedef -unspecified- {side}_data_type;
    typedef -unspecified- {side}_value_type;
    typedef -unspecified- {side}_key_type;
    typedef -unspecified- {side}_iterator;
    typedef -unspecified- {side}_const_iterator;

    ------------------------------------------------------------------*/

    typedef STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::bimaps::detail::
          left_map_view_type<base_>::type  left_map;
    typedef STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::bimaps::detail::
         right_map_view_type<base_>::type right_map;

    typedef STREAMS_BOOST_DEDUCED_TYPENAME
         left_map::reference        left_reference;
    typedef STREAMS_BOOST_DEDUCED_TYPENAME
         left_map::const_reference  left_const_reference;

    typedef STREAMS_BOOST_DEDUCED_TYPENAME
        right_map::reference       right_reference;
    typedef STREAMS_BOOST_DEDUCED_TYPENAME
        right_map::const_reference right_const_reference;

    typedef STREAMS_BOOST_DEDUCED_TYPENAME base_::relation::info_type info_type;

    typedef STREAMS_BOOST_DEDUCED_TYPENAME base_::core_type::allocator_type allocator_type; 
    
    /// Left map view
    left_map  left;

    /// Right map view
    right_map right;

    typedef STREAMS_BOOST_DEDUCED_TYPENAME base_::logic_relation_set_tag 
                                          logic_relation_set_tag;
    typedef STREAMS_BOOST_DEDUCED_TYPENAME base_::logic_left_tag logic_left_tag;
    typedef STREAMS_BOOST_DEDUCED_TYPENAME base_::logic_right_tag logic_right_tag;
    typedef STREAMS_BOOST_DEDUCED_TYPENAME base_::core_type::ctor_args_list 
                                                     ctor_args_list;

   bimap(const allocator_type& al = allocator_type()) :

       base_::relation_set(
           ::streams_boost::multi_index::get<
               logic_relation_set_tag
           >(core)
       ),

       core(al),

       left (
           ::streams_boost::multi_index::get<
               logic_left_tag
           >(core)
       ),
       right (
           ::streams_boost::multi_index::get<
               logic_right_tag
           >(core)
       )

   {}

   template< class InputIterator >
   bimap(InputIterator first,InputIterator last,
         const allocator_type& al = allocator_type()) :

       base_::relation_set(
           ::streams_boost::multi_index::get<logic_relation_set_tag>(core)
       ),

       core(first,last,ctor_args_list(),al),

       left (
           ::streams_boost::multi_index::get<logic_left_tag>(core)
       ),
       right (
           ::streams_boost::multi_index::get<logic_right_tag>(core)
       )

   {}

   bimap(const bimap& x) :

       base_::relation_set(
           ::streams_boost::multi_index::get<logic_relation_set_tag>(core)
       ),

       core(x.core),

       left (
           ::streams_boost::multi_index::get<logic_left_tag>(core)
       ),
       right (
           ::streams_boost::multi_index::get<logic_right_tag>(core)
       )

   {}

    bimap& operator=(const bimap& x)
    {
        core = x.core;
        return *this;
    }

    // Projection of iterators

    template< class IteratorType >
    STREAMS_BOOST_DEDUCED_TYPENAME base_::left_iterator
        project_left(IteratorType iter)
    {
        return core.template project<
            STREAMS_BOOST_DEDUCED_TYPENAME base_::logic_left_tag>(iter.base());
    }

    template< class IteratorType >
    STREAMS_BOOST_DEDUCED_TYPENAME base_::left_const_iterator
        project_left(IteratorType iter) const
    {
        return core.template project<
            STREAMS_BOOST_DEDUCED_TYPENAME base_::logic_left_tag>(iter.base());
    }

    template< class IteratorType >
    STREAMS_BOOST_DEDUCED_TYPENAME base_::right_iterator
        project_right(IteratorType iter)
    {
        return core.template project<
            STREAMS_BOOST_DEDUCED_TYPENAME base_::logic_right_tag>(iter.base());
    }

    template< class IteratorType >
    STREAMS_BOOST_DEDUCED_TYPENAME base_::right_const_iterator
        project_right(IteratorType iter) const
    {
        return core.template project<
            STREAMS_BOOST_DEDUCED_TYPENAME base_::logic_right_tag>(iter.base());
    }

    template< class IteratorType >
    STREAMS_BOOST_DEDUCED_TYPENAME base_::relation_set::iterator
        project_up(IteratorType iter)
    {
        return core.template project<
            STREAMS_BOOST_DEDUCED_TYPENAME base_::logic_relation_set_tag>(iter.base());
    }

    template< class IteratorType >
    STREAMS_BOOST_DEDUCED_TYPENAME base_::relation_set::const_iterator
        project_up(IteratorType iter) const
    {
        return core.template project<
            STREAMS_BOOST_DEDUCED_TYPENAME base_::logic_relation_set_tag>(iter.base());
    }

    // Support for tags

    template< class Tag, class IteratorType >
    STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::bimaps::support::
    iterator_type_by<Tag,bimap>::type
        project(IteratorType iter
                STREAMS_BOOST_APPEND_EXPLICIT_TEMPLATE_TYPE(Tag))
    {
        return core.template project<Tag>(iter.base());
    }

    template< class Tag, class IteratorType >
    STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::bimaps::support::
    const_iterator_type_by<Tag,bimap>::type
        project(IteratorType iter
                STREAMS_BOOST_APPEND_EXPLICIT_TEMPLATE_TYPE(Tag)) const
    {
        return core.template project<Tag>(iter.base());
    }

    template< class Tag >
    struct map_by :
        public ::streams_boost::bimaps::support::map_type_by<Tag,bimap>::type
    {
        typedef STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::bimaps::support::
            map_type_by<Tag,bimap>::type type;

        private: map_by() {}
    };

    template< class Tag >
    STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::bimaps::support::
    map_type_by<Tag,bimap>::type &
        by(STREAMS_BOOST_EXPLICIT_TEMPLATE_TYPE(Tag))
    {
        return ::streams_boost::bimaps::support::map_by<Tag>(*this);
    }

    template< class Tag >
    const STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::bimaps::support::
    map_type_by<Tag,bimap>::type &
        by(STREAMS_BOOST_EXPLICIT_TEMPLATE_TYPE(Tag)) const
    {
        return ::streams_boost::bimaps::support::map_by<Tag>(*this);
    }


    #ifndef STREAMS_BOOST_BIMAP_DISABLE_SERIALIZATION

    // Serialization support

    private:

    friend class streams_boost::serialization::access;

    template<class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
        ar & serialization::make_nvp("mi_core",core);
    }

    #endif // STREAMS_BOOST_BIMAP_DISABLE_SERIALIZATION
};

} // namespace bimaps
} // namespace streams_boost


/** \namespace streams_boost::bimaps::support
\brief Metafunctions to help working with bimaps.
                                                            **/

/** \namespace streams_boost::bimaps::views
\brief Bimap views.
                                                            **/

/** \namespace streams_boost::bimaps::views::detail
\brief Bimap views details.
                                                            **/



// Include basic tools for user commodity

#include <streams_boost/bimap/tags/tagged.hpp>
#include <streams_boost/bimap/relation/member_at.hpp>
#include <streams_boost/multi_index/detail/unbounded.hpp>

// Bring the most used namespaces directly to the user main namespace
namespace streams_boost {
namespace bimaps {

using ::streams_boost::bimaps::tags::tagged;

namespace member_at = ::streams_boost::bimaps::relation::member_at;

using ::streams_boost::multi_index::unbounded;

} // namespace bimaps
} // namespace streams_boost


#endif // STREAMS_BOOST_BIMAP_BIMAP_HPP
