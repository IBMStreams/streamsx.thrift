// Boost.Bimap
//
// Copyright (c) 2006-2007 Matias Capeletto
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

/// \file views/unconstrained_set_view.hpp
/// \brief Unconstrained view of a bimap.

#ifndef STREAMS_BOOST_BIMAP_VIEWS_UNCONSTRAINED_SET_VIEW_HPP
#define STREAMS_BOOST_BIMAP_VIEWS_UNCONSTRAINED_SET_VIEW_HPP

#if defined(_MSC_VER) && (_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/config.hpp>

namespace streams_boost {
namespace bimaps {
namespace views {

/// \brief Unconstrained view of a bimap.

template< class CoreIndex >
class unconstrained_set_view
{
    public:
    template< class T >
    unconstrained_set_view(const T & t) {}

    typedef void iterator;
    typedef void const_iterator;
};

} // namespace views
} // namespace bimaps
} // namespace streams_boost

#endif // STREAMS_BOOST_BIMAP_VIEWS_UNCONSTRAINED_SET_VIEW_HPP
