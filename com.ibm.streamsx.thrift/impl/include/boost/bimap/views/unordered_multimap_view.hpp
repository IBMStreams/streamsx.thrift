// Boost.Bimap
//
// Copyright (c) 2006-2007 Matias Capeletto
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

/// \file views/unordered_multimap_view.hpp
/// \brief View of a side of a bimap that is signature compatible with tr1::unordered_multimap.

#ifndef STREAMS_BOOST_BIMAP_VIEWS_UNOREDERED_MULTIMAP_VIEW_HPP
#define STREAMS_BOOST_BIMAP_VIEWS_UNOREDERED_MULTIMAP_VIEW_HPP

#if defined(_MSC_VER) && (_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/config.hpp>

#include <utility>

#include <streams_boost/bimap/container_adaptor/unordered_multimap_adaptor.hpp>
#include <streams_boost/bimap/detail/non_unique_views_helper.hpp>
#include <streams_boost/bimap/support/iterator_type_by.hpp>
#include <streams_boost/bimap/detail/map_view_base.hpp>

namespace streams_boost {
namespace bimaps {
namespace views {

/// \brief View of a side of a bimap that is signature compatible with tr1::unordered_multimap.
/**

This class uses container_adaptor and iterator_adaptor to wrapped a index of the
multi_index bimap core so it can be used as a tr1::unordered_multimap.

See also const_unordered_multimap_view.
                                                                             **/

template< class Tag, class BimapType >
class unordered_multimap_view
:
    public STREAMS_BOOST_BIMAP_MAP_VIEW_CONTAINER_ADAPTOR(
        unordered_multimap_adaptor,
        Tag,BimapType,
        local_iterator_type_by,const_local_iterator_type_by
    ),

    public ::streams_boost::bimaps::detail::map_view_base<
                unordered_multimap_view<Tag,BimapType>,Tag,BimapType >

{
    typedef STREAMS_BOOST_BIMAP_MAP_VIEW_CONTAINER_ADAPTOR(
        unordered_multimap_adaptor,
        Tag,BimapType,
        local_iterator_type_by,const_local_iterator_type_by

    ) base_;

    STREAMS_BOOST_BIMAP_MAP_VIEW_BASE_FRIEND(unordered_multimap_view,Tag,BimapType)

    public:

    typedef std::pair<
        STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator,
        STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator
    > range_type;

    typedef std::pair<
        STREAMS_BOOST_DEDUCED_TYPENAME base_::const_iterator,
        STREAMS_BOOST_DEDUCED_TYPENAME base_::const_iterator
    > const_range_type;

    typedef STREAMS_BOOST_DEDUCED_TYPENAME base_::value_type::info_type info_type;

    unordered_multimap_view(STREAMS_BOOST_DEDUCED_TYPENAME base_::base_type & c)
        : base_(c) {}

    STREAMS_BOOST_BIMAP_NON_UNIQUE_VIEW_INSERT_FUNCTIONS

    unordered_multimap_view & operator=(const unordered_multimap_view & v) 
    {
        this->base() = v.base();
        return *this;
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
    STREAMS_BOOST_BIMAP_MAP_VIEW_EXTRA_TYPEDEF(MAP_VIEW,SIDE,local_iterator)          \
    STREAMS_BOOST_BIMAP_MAP_VIEW_EXTRA_TYPEDEF(MAP_VIEW,SIDE,const_local_iterator)    \
    STREAMS_BOOST_BIMAP_MAP_VIEW_EXTRA_TYPEDEF(MAP_VIEW,SIDE,range_type)              \
    STREAMS_BOOST_BIMAP_MAP_VIEW_EXTRA_TYPEDEF(MAP_VIEW,SIDE,const_range_type)        \
    STREAMS_BOOST_BIMAP_MAP_VIEW_EXTRA_TYPEDEF(MAP_VIEW,SIDE,hasher)                  \
    STREAMS_BOOST_BIMAP_MAP_VIEW_EXTRA_TYPEDEF(MAP_VIEW,SIDE,key_equal)
/*===========================================================================*/

namespace detail {

template< class Tag, class BimapType >
struct left_map_view_extra_typedefs< ::streams_boost::bimaps::views::unordered_multimap_view<Tag,BimapType> >
{
    private: typedef ::streams_boost::bimaps::views::unordered_multimap_view<Tag,BimapType> map_view_;
    public : STREAMS_BOOST_BIMAP_MAP_VIEW_EXTRA_TYPEDEFS_BODY(map_view_,left)
};

template< class Tag, class BimapType >
struct right_map_view_extra_typedefs< ::streams_boost::bimaps::views::unordered_multimap_view<Tag,BimapType> >
{
    private: typedef ::streams_boost::bimaps::views::unordered_multimap_view<Tag,BimapType> map_view_;
    public : STREAMS_BOOST_BIMAP_MAP_VIEW_EXTRA_TYPEDEFS_BODY(map_view_,right)
};

} // namespace detail

/*===========================================================================*/
#undef STREAMS_BOOST_BIMAP_MAP_VIEW_EXTRA_TYPEDEF
#undef STREAMS_BOOST_BIMAP_MAP_VIEW_EXTRA_TYPEDEFS_BODY
/*===========================================================================*/

} // namespace bimaps
} // namespace streams_boost

#endif // STREAMS_BOOST_BIMAP_VIEWS_UNOREDERED_MULTIMAP_VIEW_HPP


