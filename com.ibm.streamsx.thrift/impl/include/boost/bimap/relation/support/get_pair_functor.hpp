// Boost.Bimap
//
// Copyright (c) 2006-2007 Matias Capeletto
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

/// \file relation/support/get_pair_functor.hpp
/// \brief get_pair_functor definition

#ifndef STREAMS_BOOST_BIMAP_RELATION_SUPPORT_GET_PAIR_FUNCTOR_HPP
#define STREAMS_BOOST_BIMAP_RELATION_SUPPORT_GET_PAIR_FUNCTOR_HPP

#if defined(_MSC_VER) && (_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/config.hpp>

#include <streams_boost/bimap/relation/support/pair_by.hpp>

namespace streams_boost {
namespace bimaps {
namespace relation {
namespace support {

/// \brief A Functor that takes a relation as a parameter an return the desired view.
/**

This functor is included to help users of the relation class when using
stl algorithms.

See also member_at, pair_by().
\ingroup relation_group

                                                                                  **/

template< class Tag, class Relation >
struct get_pair_functor
{
    STREAMS_BOOST_DEDUCED_TYPENAME result_of::pair_by<Tag,Relation>::type
    operator()( Relation & r ) const
    {
        return pair_by<Tag>(r);
    }

    STREAMS_BOOST_DEDUCED_TYPENAME result_of::pair_by<Tag,const Relation>::type
    operator()( const Relation & r ) const
    {
        return pair_by<Tag>(r);
    }
};


/// \brief A Functor that takes a relation as a parameter an return the above view.
/**

\ingroup relation_group
                                                                                  **/

template< class Relation >
struct get_above_view_functor
{
    STREAMS_BOOST_DEDUCED_TYPENAME Relation::above_view &
    operator()( Relation & r ) const
    {
        return r.get_view();
    }

    const STREAMS_BOOST_DEDUCED_TYPENAME Relation::above_view &
    operator()( const Relation & r ) const
    {
        return r.get_view();
    }
};

} // namespace support
} // namespace relation
} // namespace bimaps
} // namespace streams_boost


#endif // STREAMS_BOOST_BIMAP_RELATION_SUPPORT_GET_PAIR_FUNCTOR_HPP

