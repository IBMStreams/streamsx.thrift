// Boost.Bimap
//
// Copyright (c) 2006-2007 Matias Capeletto
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

/// \file views/vector_set_view.hpp
/// \brief View of a side of a bimap that is signature compatible with std::vector.

#ifndef STREAMS_BOOST_BIMAP_VIEWS_VECTOR_SET_VIEW_HPP
#define STREAMS_BOOST_BIMAP_VIEWS_VECTOR_SET_VIEW_HPP

#if defined(_MSC_VER) && (_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/config.hpp>

#include <streams_boost/bimap/container_adaptor/vector_adaptor.hpp>
#include <streams_boost/bimap/container_adaptor/detail/comparison_adaptor.hpp>
#include <streams_boost/bimap/detail/set_view_base.hpp>
#include <streams_boost/bimap/detail/map_view_base.hpp>

namespace streams_boost {
namespace bimaps {
namespace views {

/// \brief View of a bimap that is signature compatible with std::vector.
/**

This class uses container_adaptor and iterator_adaptor to wrapped a index of the
multi_index bimap core so it can be used as a std::vector.

See also const_set_view.
                                                                                    **/

template< class CoreIndex >
class vector_set_view
:
    public STREAMS_BOOST_BIMAP_SEQUENCED_SET_VIEW_CONTAINER_ADAPTOR(
        vector_adaptor,
        CoreIndex,
        reverse_iterator, const_reverse_iterator
    ),

    public ::streams_boost::bimaps::detail::
                set_view_base< vector_set_view< CoreIndex >, CoreIndex >
{
    STREAMS_BOOST_BIMAP_SET_VIEW_BASE_FRIEND(vector_set_view,CoreIndex)

    typedef STREAMS_BOOST_BIMAP_SEQUENCED_SET_VIEW_CONTAINER_ADAPTOR(
        vector_adaptor,
        CoreIndex,
        reverse_iterator, const_reverse_iterator

    ) base_;

    public:

    vector_set_view(STREAMS_BOOST_DEDUCED_TYPENAME base_::base_type & c) :
        base_(c) {}

    vector_set_view & operator=(const vector_set_view & v)
    {
        this->base() = v.base();
        return *this;
    }

    STREAMS_BOOST_BIMAP_VIEW_ASSIGN_IMPLEMENTATION(base_)

    STREAMS_BOOST_BIMAP_VIEW_FRONT_BACK_IMPLEMENTATION(base_)

    // List operations

    void splice(STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator position, 
                vector_set_view & x)
    {
        this->base().splice(
            this->template functor<
                STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator_to_base>()(position),
            x.base()
        );
    }

    void splice(STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator position,
                vector_set_view & x,
                STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator i)
    {
        this->base().splice(
            this->template functor<
                STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator_to_base>()(position),
            x.base(),
            this->template functor<
                STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator_to_base>()(i)
        );
    }

    void splice(STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator position, 
                vector_set_view & x,
                STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator first, 
                STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator last)
    {
        this->base().splice(
            this->template functor<
                STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator_to_base>()(position),
            x.base(),
            this->template functor<
                STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator_to_base>()(first),
            this->template functor<
                STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator_to_base>()(last)
        );
    }

    void remove(STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::call_traits<
                    STREAMS_BOOST_DEDUCED_TYPENAME base_::value_type >::param_type value)
    {
        this->base().remove(
            this->template functor<
                STREAMS_BOOST_DEDUCED_TYPENAME base_::value_to_base>()(value)
        );
    }

    template<typename Predicate>
    void remove_if(Predicate pred)
    {
        this->base().remove_if(
            ::streams_boost::bimaps::container_adaptor::detail::unary_check_adaptor
            <
                Predicate,
                STREAMS_BOOST_DEDUCED_TYPENAME base_::base_type::value_type,
                STREAMS_BOOST_DEDUCED_TYPENAME base_::value_from_base

            >( pred, this->template functor<
                            STREAMS_BOOST_DEDUCED_TYPENAME base_::value_from_base>() )
        );
    }

    void unique()
    {
        this->base().unique(
            ::streams_boost::bimaps::container_adaptor::detail::comparison_adaptor
            <
                std::equal_to<STREAMS_BOOST_DEDUCED_TYPENAME base_::value_type>,
                STREAMS_BOOST_DEDUCED_TYPENAME base_::base_type::value_type,
                STREAMS_BOOST_DEDUCED_TYPENAME base_::value_from_base

            >(
                std::equal_to<STREAMS_BOOST_DEDUCED_TYPENAME base_::value_type>(),
                this->template functor<
                    STREAMS_BOOST_DEDUCED_TYPENAME base_::value_from_base>()
            )
        );
    }

    template< class BinaryPredicate >
    void unique(BinaryPredicate binary_pred)
    {
        this->base().unique(
            ::streams_boost::bimaps::container_adaptor::detail::comparison_adaptor
            <
                BinaryPredicate,
                STREAMS_BOOST_DEDUCED_TYPENAME base_::base_type::value_type,
                STREAMS_BOOST_DEDUCED_TYPENAME base_::value_from_base

            >( binary_pred,
               this->template functor<
                    STREAMS_BOOST_DEDUCED_TYPENAME base_::value_from_base>() 
            )
        );
    }

    void merge(vector_set_view & x)
    {
        this->base().merge(x.base(),
            ::streams_boost::bimaps::container_adaptor::detail::comparison_adaptor
            <
                std::less<STREAMS_BOOST_DEDUCED_TYPENAME base_::value_type>,
                STREAMS_BOOST_DEDUCED_TYPENAME base_::base_type::value_type,
                STREAMS_BOOST_DEDUCED_TYPENAME base_::value_from_base

            >(
                std::less<STREAMS_BOOST_DEDUCED_TYPENAME base_::value_type>(),
                this->template functor<
                        STREAMS_BOOST_DEDUCED_TYPENAME base_::value_from_base>()
            )
        );
    }

    template< class Compare >
    void merge(vector_set_view & x, Compare comp)
    {
        this->base().merge(x.base(),
            ::streams_boost::bimaps::container_adaptor::detail::comparison_adaptor
            <
                Compare,
                STREAMS_BOOST_DEDUCED_TYPENAME base_::base_type::value_type,
                STREAMS_BOOST_DEDUCED_TYPENAME base_::value_from_base

            >( comp, this->template functor<
                        STREAMS_BOOST_DEDUCED_TYPENAME base_::value_from_base>() )
        );
    }

    void sort()
    {
        this->base().sort(
            ::streams_boost::bimaps::container_adaptor::detail::comparison_adaptor
            <
                std::less<STREAMS_BOOST_DEDUCED_TYPENAME base_::value_type>,
                STREAMS_BOOST_DEDUCED_TYPENAME base_::base_type::value_type,
                STREAMS_BOOST_DEDUCED_TYPENAME base_::value_from_base

            >(
                std::less<STREAMS_BOOST_DEDUCED_TYPENAME base_::value_type>(),
                this->template functor<
                    STREAMS_BOOST_DEDUCED_TYPENAME base_::value_from_base>()
            )
        );
    }

    template< class Compare >
    void sort(Compare comp)
    {
        this->base().sort(
            ::streams_boost::bimaps::container_adaptor::detail::comparison_adaptor
            <
                Compare,
                STREAMS_BOOST_DEDUCED_TYPENAME base_::base_type::value_type,
                STREAMS_BOOST_DEDUCED_TYPENAME base_::value_from_base

            >( comp, this->template functor<
                        STREAMS_BOOST_DEDUCED_TYPENAME base_::value_from_base>() )
        );
    }

    void reverse()
    {
        this->base().reverse();
    }

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


#endif // STREAMS_BOOST_BIMAP_VIEWS_VECTOR_SET_VIEW_HPP

