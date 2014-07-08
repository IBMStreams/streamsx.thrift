// Boost.Bimap
//
// Copyright (c) 2006-2007 Matias Capeletto
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

/// \file views/set_view.hpp
/// \brief View of a bimap that is signature compatible with std::set.

#ifndef STREAMS_BOOST_BIMAP_VIEWS_SET_VIEW_HPP
#define STREAMS_BOOST_BIMAP_VIEWS_SET_VIEW_HPP

#if defined(_MSC_VER) && (_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/config.hpp>

#include <streams_boost/bimap/container_adaptor/set_adaptor.hpp>
#include <streams_boost/bimap/detail/set_view_base.hpp>

namespace streams_boost {
namespace bimaps {
namespace views {

/// \brief View of a bimap that is signature compatible with std::set.
/**

This class uses container_adaptor and iterator_adaptor to wrapped a index of the
multi_index bimap core so it can be used as a std::set.

See also const_set_view.
                                                                                    **/

template< class CoreIndex >
class set_view
:
    public STREAMS_BOOST_BIMAP_SET_VIEW_CONTAINER_ADAPTOR(
        set_adaptor,
        CoreIndex,
        reverse_iterator, const_reverse_iterator
    ),

    public ::streams_boost::bimaps::detail::
                set_view_base< set_view< CoreIndex >, CoreIndex >
{
    typedef STREAMS_BOOST_BIMAP_SET_VIEW_CONTAINER_ADAPTOR(
        set_adaptor,
        CoreIndex,
        reverse_iterator, const_reverse_iterator

    ) base_;

    STREAMS_BOOST_BIMAP_SET_VIEW_BASE_FRIEND(set_view,CoreIndex)

    public:

    set_view(STREAMS_BOOST_DEDUCED_TYPENAME base_::base_type & c) : base_(c) {}

    /*
    template< class LowerBounder, class UpperBounder >
    std::pair<STREAMS_BOOST_DEDUCED_TYPENAME base_::const_iterator,
              STREAMS_BOOST_DEDUCED_TYPENAME base_::const_iterator>
        range(LowerBounder lower,UpperBounder upper) const
    {
        return this->base().range(

            ::streams_boost::bimaps::container_adaptor::detail::unary_check_adaptor
            <
                LowerBounder,
                STREAMS_BOOST_DEDUCED_TYPENAME base_::base_type::value_type,
                STREAMS_BOOST_DEDUCED_TYPENAME base_::value_from_base

            >( lower, this->template functor<
                            STREAMS_BOOST_DEDUCED_TYPENAME base_::value_from_base>() ),

            ::streams_boost::bimaps::container_adaptor::detail::unary_check_adaptor
            <
                UpperBounder,
                STREAMS_BOOST_DEDUCED_TYPENAME base_::base_type::value_type,
                STREAMS_BOOST_DEDUCED_TYPENAME base_::value_from_base

            >( upper, this->template functor<
                            STREAMS_BOOST_DEDUCED_TYPENAME base_::value_from_base>() )

        );
    }
    */

    set_view & operator=(const set_view & v) 
    {
        this->base() = v.base();
        return *this;
    }
};


} // namespace views
} // namespace bimaps
} // namespace streams_boost

#endif // STREAMS_BOOST_BIMAP_VIEWS_SET_VIEW_HPP


