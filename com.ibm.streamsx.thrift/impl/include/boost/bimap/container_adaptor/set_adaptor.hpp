// Boost.Bimap
//
// Copyright (c) 2006-2007 Matias Capeletto
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

/// \file container_adaptor/set_adaptor.hpp
/// \brief Container adaptor to easily build a std::set signature compatible container.

#ifndef STREAMS_BOOST_BIMAP_CONTAINER_ADAPTOR_SET_ADAPTOR_HPP
#define STREAMS_BOOST_BIMAP_CONTAINER_ADAPTOR_SET_ADAPTOR_HPP

#if defined(_MSC_VER) && (_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/config.hpp>

#include <streams_boost/bimap/container_adaptor/ordered_associative_container_adaptor.hpp>
#include <streams_boost/mpl/vector.hpp>
#include <streams_boost/mpl/aux_/na.hpp>

namespace streams_boost {
namespace bimaps {
namespace container_adaptor {

/// \brief Container adaptor to easily build a std::set signature compatible container.

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
    class KeyToBaseConverter               = ::streams_boost::mpl::na,

    class FunctorsFromDerivedClasses = mpl::vector<>
>
class set_adaptor :

    public ::streams_boost::bimaps::container_adaptor::
                ordered_associative_container_adaptor
    <
        Base,
        Iterator, ConstIterator, ReverseIterator, ConstReverseIterator,
        STREAMS_BOOST_DEDUCED_TYPENAME Iterator::value_type,
        IteratorToBaseConverter, IteratorFromBaseConverter,
        ReverseIteratorFromBaseConverter,
        ValueToBaseConverter, ValueFromBaseConverter,
        KeyToBaseConverter,
        FunctorsFromDerivedClasses
    >
{

    typedef ::streams_boost::bimaps::container_adaptor::
                ordered_associative_container_adaptor
    <
        Base,
        Iterator, ConstIterator, ReverseIterator, ConstReverseIterator,
        STREAMS_BOOST_DEDUCED_TYPENAME Iterator::value_type,
        IteratorToBaseConverter, IteratorFromBaseConverter,
        ReverseIteratorFromBaseConverter,
        ValueToBaseConverter, ValueFromBaseConverter,
        KeyToBaseConverter,
        FunctorsFromDerivedClasses

    > base_;

    // Access -----------------------------------------------------------------

    public:

    explicit set_adaptor(Base & c) :
        base_(c) {}

    protected:

    typedef set_adaptor set_adaptor_;

};


} // namespace container_adaptor
} // namespace bimaps
} // namespace streams_boost


#endif // STREAMS_BOOST_BIMAP_CONTAINER_ADAPTOR_SET_ADAPTOR_HPP


