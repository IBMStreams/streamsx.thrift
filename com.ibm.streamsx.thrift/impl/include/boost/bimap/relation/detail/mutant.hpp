// Boost.Bimap
//
// Copyright (c) 2006-2007 Matias Capeletto
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

/// \file relation/detail/mutant.hpp
/// \brief Mutate functions to extract views of mutant classes.

#ifndef STREAMS_BOOST_BIMAP_RELATION_DETAIL_MUTANT_HPP
#define STREAMS_BOOST_BIMAP_RELATION_DETAIL_MUTANT_HPP

#if defined(_MSC_VER) && (_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/config.hpp>

#include <streams_boost/bimap/detail/debug/static_error.hpp>
#include <streams_boost/mpl/contains.hpp>
#include <streams_boost/mpl/assert.hpp>
#include <streams_boost/utility.hpp>
#include <streams_boost/static_assert.hpp>
#include <streams_boost/type_traits/is_const.hpp>
#include <streams_boost/mpl/not.hpp>
#include <streams_boost/utility/enable_if.hpp>

namespace streams_boost {
namespace bimaps {
namespace relation {

/// \brief Relation details, mutant idiom and symmetrical metafunctions builders.

namespace detail {

//@{
/// \brief Converts a mutant class to a view with zero overhead.
/**

This function is a safe wrapper around reinterpret_cast. It checks at
compile time that the desired view is supported by the mutant class.
See also mutant, can_mutate_in.
\ingroup mutant_group
                                                                            **/


template< class View, class Type >
STREAMS_BOOST_DEDUCED_TYPENAME enable_if< mpl::not_< is_const< Type > >,

View&

>::type mutate( Type & m )
{
    STREAMS_BOOST_MPL_ASSERT((
        ::streams_boost::mpl::contains<STREAMS_BOOST_DEDUCED_TYPENAME Type::mutant_views,View>
    ));
    return *reinterpret_cast< View* >(streams_boost::addressof(m));
}

template< class View, class Type >
STREAMS_BOOST_DEDUCED_TYPENAME enable_if< is_const< Type >,

const View&

>::type mutate( Type & m )
{
    STREAMS_BOOST_MPL_ASSERT((
        ::streams_boost::mpl::contains<STREAMS_BOOST_DEDUCED_TYPENAME Type::mutant_views,View> 
    ));
    return *reinterpret_cast< const View* >(streams_boost::addressof(m));
}

//@}

} // namespace detail
} // namespace relation
} // namespace bimaps
} // namespace streams_boost

#endif // STREAMS_BOOST_BIMAP_RELATION_DETAIL_MUTANT_HPP

