// Boost.Bimap
//
// Copyright (c) 2006-2007 Matias Capeletto
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

/// \file views/unconstrained_map_view.hpp
/// \brief Unconstrained view of a side of a bimap.

#ifndef STREAMS_BOOST_BIMAP_VIEWS_UNCONSTRAINED_MAP_VIEW_HPP
#define STREAMS_BOOST_BIMAP_VIEWS_UNCONSTRAINED_MAP_VIEW_HPP

#if defined(_MSC_VER) && (_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/config.hpp>

namespace streams_boost {
namespace bimaps {
namespace views {

/// \brief Unconstrained view of a side of a bimap.

template< class Tag, class BimapType>
class unconstrained_map_view
{
    public:
    template< class T >
    unconstrained_map_view(const T & t) {}

    typedef void reference;
    typedef void const_reference;
    typedef void info_type;
};

} // namespace views
} // namespace bimaps
} // namespace streams_boost

#endif // STREAMS_BOOST_BIMAP_VIEWS_UNCONSTRAINED_MAP_VIEW_HPP
