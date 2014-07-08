// Boost.Bimap
//
// Copyright (c) 2006-2007 Matias Capeletto
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

/// \file views/unordered_multiset_view.hpp
/// \brief View of a bimap that is signature compatible with tr1::unordered_multiset.

#ifndef STREAMS_BOOST_BIMAP_VIEWS_UNORDERED_MULTISET_VIEW_HPP
#define STREAMS_BOOST_BIMAP_VIEWS_UNORDERED_MULTISET_VIEW_HPP

#if defined(_MSC_VER) && (_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/config.hpp>

#include <streams_boost/bimap/container_adaptor/unordered_multiset_adaptor.hpp>
#include <streams_boost/bimap/detail/non_unique_views_helper.hpp>
#include <streams_boost/bimap/detail/set_view_base.hpp>

namespace streams_boost {
namespace bimaps {
namespace views {

/// \brief View of a bimap that is signature compatible with std::unordered_multiset.
/**

This class uses container_adaptor and iterator_adaptor to wrapped a index of the
multi_index bimap core so it can be used as a std::unordered_multiset.

See also const_unordered_multiset_view.
                                                                                    **/

template< class CoreIndex >
class unordered_multiset_view
:
    public STREAMS_BOOST_BIMAP_SET_VIEW_CONTAINER_ADAPTOR(
        unordered_multiset_adaptor,
        CoreIndex,
        local_iterator,
        const_local_iterator

    ),

    public ::streams_boost::bimaps::detail::
                set_view_base< unordered_multiset_view< CoreIndex >, CoreIndex >
{
    STREAMS_BOOST_BIMAP_SET_VIEW_BASE_FRIEND(unordered_multiset_view,CoreIndex)

    typedef STREAMS_BOOST_BIMAP_SET_VIEW_CONTAINER_ADAPTOR(
        unordered_multiset_adaptor,
        CoreIndex,
        local_iterator,
        const_local_iterator

    ) base_;

    public:

    unordered_multiset_view(STREAMS_BOOST_DEDUCED_TYPENAME base_::base_type & c)
        : base_(c) {}

    STREAMS_BOOST_BIMAP_NON_UNIQUE_VIEW_INSERT_FUNCTIONS

    unordered_multiset_view & operator=(const unordered_multiset_view & v)
    {
        this->base() = v.base();
        return *this;
    }
};


} // namespace views
} // namespace bimaps
} // namespace streams_boost

#endif // STREAMS_BOOST_BIMAP_VIEWS_UNORDERED_MULTISET_VIEW_HPP


