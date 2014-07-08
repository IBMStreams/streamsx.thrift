// Boost.Bimap
//
// Copyright (c) 2006-2007 Matias Capeletto
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

/// \file views/list_set_view.hpp
/// \brief View of a side of a bimap that is signature compatible with std::list.

#ifndef STREAMS_BOOST_BIMAP_VIEWS_LIST_SET_VIEW_HPP
#define STREAMS_BOOST_BIMAP_VIEWS_LIST_SET_VIEW_HPP

#if defined(_MSC_VER) && (_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/config.hpp>

#include <streams_boost/bimap/container_adaptor/list_adaptor.hpp>
#include <streams_boost/bimap/detail/set_view_base.hpp>
#include <streams_boost/bimap/detail/map_view_base.hpp>

namespace streams_boost {
namespace bimaps {
namespace views {

/// \brief View of a bimap that is signature compatible with std::list.
/**

This class uses container_adaptor and iterator_adaptor to wrapped a index of the
multi_index bimap core so it can be used as a std::list.

See also const_list_set_view.
                                                                                    **/

template< class CoreIndex >
class list_set_view
:
    public STREAMS_BOOST_BIMAP_SEQUENCED_SET_VIEW_CONTAINER_ADAPTOR(
        list_adaptor,
        CoreIndex,
        reverse_iterator, const_reverse_iterator
    ),

    public ::streams_boost::bimaps::detail::
        set_view_base< list_set_view< CoreIndex >, CoreIndex >
{
    STREAMS_BOOST_BIMAP_SET_VIEW_BASE_FRIEND(list_set_view,CoreIndex)

    typedef STREAMS_BOOST_BIMAP_SEQUENCED_SET_VIEW_CONTAINER_ADAPTOR(
        list_adaptor,
        CoreIndex,
        reverse_iterator, const_reverse_iterator

    ) base_;

    public:

    list_set_view(STREAMS_BOOST_DEDUCED_TYPENAME base_::base_type & c) :
        base_(c) {}

    list_set_view & operator=(const list_set_view & v) 
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
} // namespace bimaps
} // namespace streams_boost


#endif // STREAMS_BOOST_BIMAP_VIEWS_LIST_SET_VIEW_HPP

