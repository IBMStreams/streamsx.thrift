// Boost.Bimap
//
// Copyright (c) 2006-2007 Matias Capeletto
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

/// \file relation/symmetrical_base.hpp
/// \brief Base class for symmetrical types

#ifndef STREAMS_BOOST_BIMAP_RELATION_SYMMETRICAL_BASE_HPP
#define STREAMS_BOOST_BIMAP_RELATION_SYMMETRICAL_BASE_HPP

#if defined(_MSC_VER) && (_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/config.hpp>

#include <streams_boost/mpl/if.hpp>
#include <streams_boost/type_traits/remove_const.hpp>

// Boost.Bimap
#include <streams_boost/bimap/tags/tagged.hpp>
#include <streams_boost/bimap/tags/support/default_tagged.hpp>

#include <streams_boost/bimap/relation/member_at.hpp>


namespace streams_boost {
namespace bimaps {
namespace relation {

/// \brief Base of symetrical tagged types.
/**

                                                           **/

template< class TA, class TB, bool force_mutable = false >
class symmetrical_base
{

    public:

    typedef STREAMS_BOOST_DEDUCED_TYPENAME tags::support::default_tagged
    <
        TA,
        member_at::left

    >::type tagged_left_type;

    typedef STREAMS_BOOST_DEDUCED_TYPENAME tags::support::default_tagged
    <
        TB,
        member_at::right

    >::type tagged_right_type;

    public:

    //@{
        /// The type stored in the relation

        typedef STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::mpl::if_c< force_mutable,

            STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::remove_const<
                STREAMS_BOOST_DEDUCED_TYPENAME tagged_left_type::value_type >::type,
            STREAMS_BOOST_DEDUCED_TYPENAME tagged_left_type::value_type

        >::type left_value_type;

        typedef STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::mpl::if_c< force_mutable,

            STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::remove_const<
                STREAMS_BOOST_DEDUCED_TYPENAME tagged_right_type::value_type >::type,
            STREAMS_BOOST_DEDUCED_TYPENAME tagged_right_type::value_type

        >::type right_value_type;
    //@}

    //@{
        /// The tag of the member. By default it is \c member_at::{side}
        typedef STREAMS_BOOST_DEDUCED_TYPENAME tagged_left_type ::tag  left_tag;
        typedef STREAMS_BOOST_DEDUCED_TYPENAME tagged_right_type::tag right_tag;
    //@}
};



} // namespace relation
} // namespace bimaps
} // namespace streams_boost


#endif // STREAMS_BOOST_BIMAP_RELATION_SYMMETRICAL_BASE_HPP

