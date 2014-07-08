// Boost.Bimap
//
// Copyright (c) 2006-2007 Matias Capeletto
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

/// \file detail/set_view_base.hpp
/// \brief Helper base for the construction of the bimap views types.

#ifndef STREAMS_BOOST_BIMAP_DETAIL_SET_VIEW_BASE_HPP
#define STREAMS_BOOST_BIMAP_DETAIL_SET_VIEW_BASE_HPP

#if defined(_MSC_VER) && (_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/config.hpp>

#include <streams_boost/bimap/relation/member_at.hpp>
#include <streams_boost/bimap/relation/support/data_extractor.hpp>
#include <streams_boost/bimap/detail/modifier_adaptor.hpp>
#include <streams_boost/bimap/detail/set_view_iterator.hpp>
#include <streams_boost/bimap/relation/support/get_pair_functor.hpp>
#include <streams_boost/bimap/relation/detail/to_mutable_relation_functor.hpp>
#include <streams_boost/bimap/relation/mutant_relation.hpp>
#include <streams_boost/bimap/container_adaptor/support/iterator_facade_converters.hpp>

namespace streams_boost {
namespace bimaps {
namespace detail {

template< class Key, class Value, class KeyToBase >
class set_view_key_to_base
{
    public:
    const Key operator()( const Value & v ) const
    {
        return keyToBase( v );
    }
    private:
    KeyToBase keyToBase;
};

template< class MutantRelationStorage, class KeyToBase >
class set_view_key_to_base<MutantRelationStorage,MutantRelationStorage,KeyToBase>
{
    typedef STREAMS_BOOST_DEDUCED_TYPENAME MutantRelationStorage::non_mutable_storage non_mutable_storage;
    public:
    const MutantRelationStorage & operator()( const non_mutable_storage & k ) const
    {
        return ::streams_boost::bimaps::relation::detail::mutate<MutantRelationStorage>(k);
    }
    const MutantRelationStorage & operator()( const MutantRelationStorage & k ) const
    {
        return k;
    }
};


// The next macro can be converted in a metafunctor to gain code robustness.
/*===========================================================================*/
#define STREAMS_BOOST_BIMAP_SET_VIEW_CONTAINER_ADAPTOR(                               \
    CONTAINER_ADAPTOR, CORE_INDEX, OTHER_ITER, CONST_OTHER_ITER               \
)                                                                             \
::streams_boost::bimaps::container_adaptor::CONTAINER_ADAPTOR                         \
<                                                                             \
    CORE_INDEX,                                                               \
    ::streams_boost::bimaps::detail::                                                 \
              set_view_iterator<                                              \
                    STREAMS_BOOST_DEDUCED_TYPENAME CORE_INDEX::iterator         >,    \
    ::streams_boost::bimaps::detail::                                                 \
        const_set_view_iterator<                                              \
                    STREAMS_BOOST_DEDUCED_TYPENAME CORE_INDEX::const_iterator   >,    \
    ::streams_boost::bimaps::detail::                                                 \
              set_view_iterator<                                              \
                    STREAMS_BOOST_DEDUCED_TYPENAME CORE_INDEX::OTHER_ITER       >,    \
    ::streams_boost::bimaps::detail::                                                 \
        const_set_view_iterator<                                              \
                    STREAMS_BOOST_DEDUCED_TYPENAME CORE_INDEX::CONST_OTHER_ITER >,    \
    ::streams_boost::bimaps::container_adaptor::support::iterator_facade_to_base      \
    <                                                                         \
        ::streams_boost::bimaps::detail::      set_view_iterator<                     \
            STREAMS_BOOST_DEDUCED_TYPENAME CORE_INDEX::iterator>,                     \
        ::streams_boost::bimaps::detail::const_set_view_iterator<                     \
            STREAMS_BOOST_DEDUCED_TYPENAME CORE_INDEX::const_iterator>                \
                                                                              \
    >,                                                                        \
    ::streams_boost::mpl::na,                                                         \
    ::streams_boost::mpl::na,                                                         \
    ::streams_boost::bimaps::relation::detail::                                       \
        get_mutable_relation_functor<                                         \
            STREAMS_BOOST_DEDUCED_TYPENAME CORE_INDEX::value_type >,                  \
    ::streams_boost::bimaps::relation::support::                                      \
        get_above_view_functor<                                               \
            STREAMS_BOOST_DEDUCED_TYPENAME CORE_INDEX::value_type >,                  \
    ::streams_boost::bimaps::detail::set_view_key_to_base<                            \
        STREAMS_BOOST_DEDUCED_TYPENAME CORE_INDEX::key_type,                          \
        STREAMS_BOOST_DEDUCED_TYPENAME CORE_INDEX::value_type,                        \
        STREAMS_BOOST_DEDUCED_TYPENAME CORE_INDEX::key_from_value                     \
    >                                                                         \
>
/*===========================================================================*/


/*===========================================================================*/
#define STREAMS_BOOST_BIMAP_SEQUENCED_SET_VIEW_CONTAINER_ADAPTOR(                     \
    CONTAINER_ADAPTOR, CORE_INDEX, OTHER_ITER, CONST_OTHER_ITER               \
)                                                                             \
::streams_boost::bimaps::container_adaptor::CONTAINER_ADAPTOR                         \
<                                                                             \
    CORE_INDEX,                                                               \
    ::streams_boost::bimaps::detail::                                                 \
              set_view_iterator<                                              \
                    STREAMS_BOOST_DEDUCED_TYPENAME CORE_INDEX::iterator         >,    \
    ::streams_boost::bimaps::detail::                                                 \
        const_set_view_iterator<                                              \
                    STREAMS_BOOST_DEDUCED_TYPENAME CORE_INDEX::const_iterator   >,    \
    ::streams_boost::bimaps::detail::                                                 \
              set_view_iterator<                                              \
                    STREAMS_BOOST_DEDUCED_TYPENAME CORE_INDEX::OTHER_ITER       >,    \
    ::streams_boost::bimaps::detail::                                                 \
        const_set_view_iterator<                                              \
                    STREAMS_BOOST_DEDUCED_TYPENAME CORE_INDEX::CONST_OTHER_ITER >,    \
    ::streams_boost::bimaps::container_adaptor::support::iterator_facade_to_base      \
    <                                                                         \
        ::streams_boost::bimaps::detail::      set_view_iterator<                     \
            STREAMS_BOOST_DEDUCED_TYPENAME CORE_INDEX::iterator>,                     \
        ::streams_boost::bimaps::detail::const_set_view_iterator<                     \
            STREAMS_BOOST_DEDUCED_TYPENAME CORE_INDEX::const_iterator>                \
                                                                              \
    >,                                                                        \
    ::streams_boost::mpl::na,                                                         \
    ::streams_boost::mpl::na,                                                         \
    ::streams_boost::bimaps::relation::detail::                                       \
        get_mutable_relation_functor<                                         \
            STREAMS_BOOST_DEDUCED_TYPENAME CORE_INDEX::value_type >,                  \
    ::streams_boost::bimaps::relation::support::                                      \
        get_above_view_functor<                                               \
            STREAMS_BOOST_DEDUCED_TYPENAME CORE_INDEX::value_type >                   \
>
/*===========================================================================*/


#if defined(STREAMS_BOOST_MSVC)
/*===========================================================================*/
#define STREAMS_BOOST_BIMAP_SET_VIEW_BASE_FRIEND(TYPE,INDEX_TYPE)                     \
    typedef ::streams_boost::bimaps::detail::set_view_base<                           \
        TYPE< INDEX_TYPE >, INDEX_TYPE > template_class_friend;               \
    friend class template_class_friend;
/*===========================================================================*/
#else
/*===========================================================================*/
#define STREAMS_BOOST_BIMAP_SET_VIEW_BASE_FRIEND(TYPE,INDEX_TYPE)                     \
    friend class ::streams_boost::bimaps::detail::set_view_base<                      \
        TYPE< INDEX_TYPE >, INDEX_TYPE >;
/*===========================================================================*/
#endif


/// \brief Common base for set views.

template< class Derived, class Index >
class set_view_base
{
    typedef ::streams_boost::bimaps::container_adaptor::support::
    iterator_facade_to_base
    <
        ::streams_boost::bimaps::detail::
                  set_view_iterator<STREAMS_BOOST_DEDUCED_TYPENAME Index::      iterator>,
        ::streams_boost::bimaps::detail::
            const_set_view_iterator<STREAMS_BOOST_DEDUCED_TYPENAME Index::const_iterator>

    > iterator_to_base_;

    typedef STREAMS_BOOST_DEDUCED_TYPENAME Index::value_type::left_value_type          left_type_;

    typedef STREAMS_BOOST_DEDUCED_TYPENAME Index::value_type::right_value_type        right_type_;

    typedef STREAMS_BOOST_DEDUCED_TYPENAME Index::value_type                          value_type_;

    typedef ::streams_boost::bimaps::detail::
                    set_view_iterator<STREAMS_BOOST_DEDUCED_TYPENAME Index::iterator>   iterator_;

    public:

    bool replace(iterator_ position,
                 const value_type_ & x)
    {
        return derived().base().replace(
            derived().template functor<iterator_to_base_>()(position),x
        );
    }

    template< class CompatibleLeftType >
    bool replace_left(iterator_ position,
                      const CompatibleLeftType & l)
    {
        return derived().base().replace(
            derived().template functor<iterator_to_base_>()(position),
            value_type_(l,position->right)
        );
    }

    template< class CompatibleRightType >
    bool replace_right(iterator_ position,
                       const CompatibleRightType & r)
    {
        return derived().base().replace(
            derived().template functor<iterator_to_base_>()(position),
            value_type_(position->left,r)
        );
    }

    /* This function may be provided in the future

    template< class Modifier >
    bool modify(iterator_ position,
                Modifier mod)
    {
        return derived().base().modify(

            derived().template functor<iterator_to_base_>()(position),

            ::streams_boost::bimaps::detail::relation_modifier_adaptor
            <
                Modifier,
                STREAMS_BOOST_DEDUCED_TYPENAME Index::value_type,
                STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::bimaps::relation::support::
                data_extractor
                <
                    ::streams_boost::bimaps::relation::member_at::left,
                    STREAMS_BOOST_DEDUCED_TYPENAME Index::value_type

                >::type,
                STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::bimaps::relation::support::
                data_extractor
                <
                    ::streams_boost::bimaps::relation::member_at::right,
                    STREAMS_BOOST_DEDUCED_TYPENAME Index::value_type

                >::type

            >(mod)
        );
    }
    */
    /*
    template< class Modifier >
    bool modify_left(iterator_ position, Modifier mod)
    {
        typedef STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::bimaps::relation::support::
        data_extractor
        <
            STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::bimaps::relation::member_at::right,
            STREAMS_BOOST_DEDUCED_TYPENAME Index::value_type

        >::type left_data_extractor_;

        return derived().base().modify(

            derived().template functor<iterator_to_base_>()(position),

            // this may be replaced later by
            // ::streams_boost::bind( mod, ::streams_boost::bind(data_extractor_(),_1) )

            ::streams_boost::bimaps::detail::unary_modifier_adaptor
            <
                Modifier,
                STREAMS_BOOST_DEDUCED_TYPENAME Index::value_type,
                left_data_extractor_

            >(mod)
        );
    }

    template< class Modifier >
    bool modify_right(iterator_ position, Modifier mod)
    {
        typedef STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::bimaps::relation::support::
        data_extractor
        <
            STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::bimaps::relation::member_at::right,
            STREAMS_BOOST_DEDUCED_TYPENAME Index::value_type

        >::type right_data_extractor_;

        return derived().base().modify(

            derived().template functor<iterator_to_base_>()(position),

            // this may be replaced later by
            // ::streams_boost::bind( mod, ::streams_boost::bind(data_extractor_(),_1) )

            ::streams_boost::bimaps::detail::unary_modifier_adaptor
            <
                Modifier,
                STREAMS_BOOST_DEDUCED_TYPENAME Index::value_type,
                right_data_extractor_

            >(mod)
        );
    }
    */
    protected:

    typedef set_view_base set_view_base_;

    private:

    // Curiously Recurring Template interface.

    Derived& derived()
    {
        return *static_cast<Derived*>(this);
    }

    Derived const& derived() const
    {
        return *static_cast<Derived const*>(this);
    }
};



} // namespace detail
} // namespace bimaps
} // namespace streams_boost

#endif // STREAMS_BOOST_BIMAP_DETAIL_SET_VIEW_BASE_HPP
