// Boost.Bimap
//
// Copyright (c) 2006-2007 Matias Capeletto
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

/// \file container_adaptor/list_adaptor.hpp
/// \brief Container adaptor to easily build a std::list signature compatible container.

#ifndef STREAMS_BOOST_BIMAP_CONTAINER_ADAPTOR_LIST_ADAPTOR_HPP
#define STREAMS_BOOST_BIMAP_CONTAINER_ADAPTOR_LIST_ADAPTOR_HPP

#if defined(_MSC_VER) && (_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/config.hpp>

#include <streams_boost/bimap/container_adaptor/sequence_container_adaptor.hpp>
#include <streams_boost/bimap/container_adaptor/detail/comparison_adaptor.hpp>
#include <streams_boost/mpl/aux_/na.hpp>
#include <streams_boost/mpl/vector.hpp>
#include <streams_boost/call_traits.hpp>
#include <functional>

namespace streams_boost {
namespace bimaps {
namespace container_adaptor {

/// \brief Container adaptor to easily build a std::list signature compatible container.

template
<
    class Base,

    class Iterator,
    class ConstIterator,
    class ReverseIterator,
    class ConstReverseIterator,

    class IteratorToBaseConverter          = ::streams_boost::mpl::na,
    class IteratorFromBaseConverter        = ::streams_boost::mpl::na,
    class ReverseIteratorFromBaseConverter = ::streams_boost::mpl::na,
    class ValueToBaseConverter             = ::streams_boost::mpl::na,
    class ValueFromBaseConverter           = ::streams_boost::mpl::na,

    class FunctorsFromDerivedClasses = mpl::vector<>
>
class list_adaptor :

    public ::streams_boost::bimaps::container_adaptor::sequence_container_adaptor
    <
        Base, Iterator, ConstIterator, ReverseIterator, ConstReverseIterator,
        IteratorToBaseConverter, IteratorFromBaseConverter,
        ReverseIteratorFromBaseConverter,
        ValueToBaseConverter, ValueFromBaseConverter,
        FunctorsFromDerivedClasses
    >
{
    typedef ::streams_boost::bimaps::container_adaptor::sequence_container_adaptor
    <
        Base, Iterator, ConstIterator, ReverseIterator, ConstReverseIterator,
        IteratorToBaseConverter, IteratorFromBaseConverter,
        ReverseIteratorFromBaseConverter,
        ValueToBaseConverter, ValueFromBaseConverter,
        FunctorsFromDerivedClasses

    > base_;

    // Access -----------------------------------------------------------------

    public:

    explicit list_adaptor(Base & c) :
        base_(c) {}

    protected:

    typedef list_adaptor list_adaptor_;

    // Interface -------------------------------------------------------------

    public:

    void splice(Iterator position, list_adaptor & x)
    {
        this->base().splice(
            this->template functor<STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator_to_base>()
                (position),
            x.base()
        );
    }

    void splice(Iterator position, list_adaptor & x, Iterator i)
    {
        this->base().splice(
            this->template functor<STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator_to_base>()
                (position),
            x.base(),
            this->template functor<STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator_to_base>()(i)
        );
    }

    void splice(Iterator position, list_adaptor & x, 
                Iterator first, Iterator last)
    {
        this->base().splice(
            this->template functor<STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator_to_base>()
                (position),
            x.base(),
            this->template functor<STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator_to_base>()(first),
            this->template functor<STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator_to_base>()(last)
        );
    }

    void remove(
        STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::call_traits<
            STREAMS_BOOST_DEDUCED_TYPENAME base_::value_type
        >::param_type value
    )
    {
        this->base().remove(
            this->template functor<STREAMS_BOOST_DEDUCED_TYPENAME base_::value_to_base>()(value)
        );
    }

    template< class Predicate >
    void remove_if(Predicate pred)
    {
        this->base().remove_if(
            ::streams_boost::bimaps::container_adaptor::detail::unary_check_adaptor
            <
                Predicate,
                STREAMS_BOOST_DEDUCED_TYPENAME Base::value_type,
                STREAMS_BOOST_DEDUCED_TYPENAME base_::value_from_base

            >( pred, this->template functor<STREAMS_BOOST_DEDUCED_TYPENAME base_::value_from_base>() )
        );
    }

    void unique()
    {
        this->base().unique(
            ::streams_boost::bimaps::container_adaptor::detail::comparison_adaptor
            <
                std::equal_to<STREAMS_BOOST_DEDUCED_TYPENAME base_::value_type>,
                STREAMS_BOOST_DEDUCED_TYPENAME Base::value_type,
                STREAMS_BOOST_DEDUCED_TYPENAME base_::value_from_base

            >(
                std::equal_to<STREAMS_BOOST_DEDUCED_TYPENAME base_::value_type>(),
                this->template functor<STREAMS_BOOST_DEDUCED_TYPENAME base_::value_from_base>()
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
                STREAMS_BOOST_DEDUCED_TYPENAME Base::value_type,
                STREAMS_BOOST_DEDUCED_TYPENAME base_::value_from_base

            >( binary_pred,
               this->template functor<STREAMS_BOOST_DEDUCED_TYPENAME base_::value_from_base>() )
        );
    }

    void merge(list_adaptor & x)
    {
        this->base().merge(x.base(),
            ::streams_boost::bimaps::container_adaptor::detail::comparison_adaptor
            <
                std::less<STREAMS_BOOST_DEDUCED_TYPENAME base_::value_type>,
                STREAMS_BOOST_DEDUCED_TYPENAME Base::value_type,
                STREAMS_BOOST_DEDUCED_TYPENAME base_::value_from_base

            >(
                std::less<STREAMS_BOOST_DEDUCED_TYPENAME base_::value_type>(),
                this->template functor<STREAMS_BOOST_DEDUCED_TYPENAME base_::value_from_base>()
            )
        );
    }

    template< class Compare >
    void merge(list_adaptor & x, Compare comp)
    {
        this->base().merge(x.base(),
            ::streams_boost::bimaps::container_adaptor::detail::comparison_adaptor
            <
                Compare,
                STREAMS_BOOST_DEDUCED_TYPENAME Base::value_type,
                STREAMS_BOOST_DEDUCED_TYPENAME base_::value_from_base

            >( comp, this->template functor<STREAMS_BOOST_DEDUCED_TYPENAME base_::value_from_base>() )
        );
    }

    void sort()
    {
        this->base().sort(
            ::streams_boost::bimaps::container_adaptor::detail::comparison_adaptor
            <
                std::less<STREAMS_BOOST_DEDUCED_TYPENAME base_::value_type>,
                STREAMS_BOOST_DEDUCED_TYPENAME Base::value_type,
                STREAMS_BOOST_DEDUCED_TYPENAME base_::value_from_base

            >(
                std::less<STREAMS_BOOST_DEDUCED_TYPENAME base_::value_type>(),
                this->template functor<STREAMS_BOOST_DEDUCED_TYPENAME base_::value_from_base>()
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
                STREAMS_BOOST_DEDUCED_TYPENAME Base::value_type,
                STREAMS_BOOST_DEDUCED_TYPENAME base_::value_from_base

            >( comp, this->template functor<STREAMS_BOOST_DEDUCED_TYPENAME base_::value_from_base>() )
        );
    }

    void reverse()
    {
        this->base().reverse();
    }

};


} // namespace container_adaptor
} // namespace bimaps
} // namespace streams_boost


#endif // STREAMS_BOOST_BIMAP_CONTAINER_ADAPTOR_SET_ADAPTOR_HPP


