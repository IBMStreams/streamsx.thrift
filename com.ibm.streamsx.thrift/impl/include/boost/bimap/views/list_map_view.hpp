// Boost.Bimap
//
// Copyright (c) 2006-2007 Matias Capeletto
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

/// \file views/list_map_view.hpp
/// \brief View of a side of a bimap.

#ifndef STREAMS_BOOST_BIMAP_VIEWS_LIST_MAP_VIEW_HPP
#define STREAMS_BOOST_BIMAP_VIEWS_LIST_MAP_VIEW_HPP

#if defined(_MSC_VER) && (_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/config.hpp>

#include <streams_boost/bimap/container_adaptor/list_map_adaptor.hpp>
#include <streams_boost/bimap/relation/support/pair_by.hpp>
#include <streams_boost/bimap/support/iterator_type_by.hpp>
#include <streams_boost/bimap/detail/map_view_base.hpp>
#include <streams_boost/bimap/relation/support/data_extractor.hpp>
#include <streams_boost/bimap/relation/detail/to_mutable_relation_functor.hpp>

namespace streams_boost {
namespace bimaps {
namespace views {

#ifndef STREAMS_BOOST_BIMAP_DOXYGEN_WILL_NOT_PROCESS_THE_FOLLOWING_LINES

template< class Tag, class BimapType >
struct list_map_view_base
{
    typedef ::streams_boost::bimaps::container_adaptor::list_map_adaptor
    <
        STREAMS_BOOST_DEDUCED_TYPENAME BimapType::core_type::STREAMS_BOOST_NESTED_TEMPLATE index<Tag>::type,
        STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::bimaps::support::
                    iterator_type_by<Tag,BimapType>::type,
        STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::bimaps::support::
                    const_iterator_type_by<Tag,BimapType>::type,
        STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::bimaps::support::
                   reverse_iterator_type_by<Tag,BimapType>::type,
        STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::bimaps::support::
                   const_reverse_iterator_type_by<Tag,BimapType>::type,
        ::streams_boost::bimaps::container_adaptor::support::iterator_facade_to_base
        <
            STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::bimaps::support::
                iterator_type_by<Tag,BimapType>::type,
            STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::bimaps::support::
                const_iterator_type_by<Tag,BimapType>::type

        >,
        ::streams_boost::mpl::na,
        ::streams_boost::mpl::na,
        ::streams_boost::bimaps::relation::detail::
            pair_to_relation_functor<Tag, STREAMS_BOOST_DEDUCED_TYPENAME BimapType::relation >,
        ::streams_boost::bimaps::relation::support::
            get_pair_functor<Tag, STREAMS_BOOST_DEDUCED_TYPENAME BimapType::relation >,

        STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::bimaps::relation::support::data_extractor
        <
            Tag,
            STREAMS_BOOST_DEDUCED_TYPENAME BimapType::relation

        >::type

    > type;
};

#endif // STREAMS_BOOST_BIMAP_DOXYGEN_WILL_NOT_PROCESS_THE_FOLLOWING_LINES

/// \brief View of a side of a bimap.
/**

This class uses container_adaptor and iterator_adaptor to wrapped a index of the
multi_index bimap core.

See also const_list_map_view.
                                                                                    **/
template< class Tag, class BimapType >
class list_map_view
:
    public list_map_view_base<Tag,BimapType>::type,
    public ::streams_boost::bimaps::detail::
            map_view_base< list_map_view<Tag,BimapType>,Tag,BimapType >

{
    typedef STREAMS_BOOST_DEDUCED_TYPENAME list_map_view_base<Tag,BimapType>::type base_;

    STREAMS_BOOST_BIMAP_MAP_VIEW_BASE_FRIEND(list_map_view,Tag,BimapType)

    public:

    typedef STREAMS_BOOST_DEDUCED_TYPENAME base_::value_type::info_type info_type;

    list_map_view(STREAMS_BOOST_DEDUCED_TYPENAME base_::base_type & c) :
        base_(c) {}

    list_map_view & operator=(const list_map_view & v)
    {
        this->base() = v.base(); 
        return *this;
    }

    STREAMS_BOOST_BIMAP_VIEW_ASSIGN_IMPLEMENTATION(base_)

    STREAMS_BOOST_BIMAP_VIEW_FRONT_BACK_IMPLEMENTATION(base_)

    // Rearrange Operations

    void relocate(STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator position,
                  STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator i)
    {
        this->base().relocate(
            this->template functor<
                STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator_to_base>()(position),
            this->template functor<
                STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator_to_base>()(i)
        );
    }

    void relocate(STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator position,
                  STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator first,
                  STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator last)
    {
        this->base().relocate(
            this->template functor<
                STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator_to_base>()(position),
            this->template functor<
                STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator_to_base>()(first),
            this->template functor<
                STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator_to_base>()(last)
        );
    }
};


} // namespace views

/*===========================================================================*/
#define STREAMS_BOOST_BIMAP_MAP_VIEW_EXTRA_TYPEDEF(MAP_VIEW,SIDE,TYPENAME)            \
typedef STREAMS_BOOST_DEDUCED_TYPENAME MAP_VIEW::TYPENAME                             \
    STREAMS_BOOST_PP_CAT(SIDE,STREAMS_BOOST_PP_CAT(_,TYPENAME));
/*===========================================================================*/

/*===========================================================================*/
#define STREAMS_BOOST_BIMAP_MAP_VIEW_EXTRA_TYPEDEFS_BODY(MAP_VIEW,SIDE)               \
    STREAMS_BOOST_BIMAP_MAP_VIEW_EXTRA_TYPEDEF(MAP_VIEW,SIDE,reverse_iterator)        \
    STREAMS_BOOST_BIMAP_MAP_VIEW_EXTRA_TYPEDEF(MAP_VIEW,SIDE,const_reverse_iterator)  \
/*===========================================================================*/

namespace detail {

template< class Tag, class BimapType >
struct left_map_view_extra_typedefs< ::streams_boost::bimaps::views::list_map_view<Tag,BimapType> >
{
    private: typedef ::streams_boost::bimaps::views::list_map_view<Tag,BimapType> map_view_;
    public : STREAMS_BOOST_BIMAP_MAP_VIEW_EXTRA_TYPEDEFS_BODY(map_view_,left)
};

template< class Tag, class BimapType >
struct right_map_view_extra_typedefs< ::streams_boost::bimaps::views::list_map_view<Tag,BimapType> >
{
    private: typedef ::streams_boost::bimaps::views::list_map_view<Tag,BimapType> map_view_;
    public : STREAMS_BOOST_BIMAP_MAP_VIEW_EXTRA_TYPEDEFS_BODY(map_view_,right)
};

} // namespace detail

/*===========================================================================*/
#undef STREAMS_BOOST_BIMAP_MAP_VIEW_EXTRA_TYPEDEF
#undef STREAMS_BOOST_BIMAP_MAP_VIEW_EXTRA_TYPEDEFS_BODY
/*===========================================================================*/

} // namespace bimaps
} // namespace streams_boost

#endif // STREAMS_BOOST_BIMAP_VIEWS_LIST_MAP_VIEW_HPP

