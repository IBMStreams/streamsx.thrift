// Boost.Bimap
//
// Copyright (c) 2006-2007 Matias Capeletto
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

/// \file container_adaptor/unordered_set_adaptor.hpp
/// \brief Container adaptor to easily build a std::unordered_set signature compatible container.

#ifndef STREAMS_BOOST_BIMAP_CONTAINER_ADAPTOR_UNORDERED_SET_ADAPTOR_HPP
#define STREAMS_BOOST_BIMAP_CONTAINER_ADAPTOR_UNORDERED_SET_ADAPTOR_HPP

#if defined(_MSC_VER) && (_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/config.hpp>

#include <streams_boost/bimap/container_adaptor/unordered_associative_container_adaptor.hpp>
#include <streams_boost/mpl/aux_/na.hpp>
#include <streams_boost/mpl/vector.hpp>

namespace streams_boost {
namespace bimaps {
namespace container_adaptor {

/// \brief Container adaptor to easily build a std::unordered_set signature compatible container.

template
<
    class Base,

    class Iterator,
    class ConstIterator,
    class LocalIterator,
    class ConstLocalIterator,

    class IteratorToBaseConverter        = ::streams_boost::mpl::na,
    class IteratorFromBaseConverter      = ::streams_boost::mpl::na,
    class LocalIteratorFromBaseConverter = ::streams_boost::mpl::na,
    class ValueToBaseConverter           = ::streams_boost::mpl::na,
    class ValueFromBaseConverter         = ::streams_boost::mpl::na,
    class KeyToBaseConverter             = ::streams_boost::mpl::na,

    class FunctorsFromDerivedClasses = mpl::vector<>
>
class unordered_set_adaptor :

    public ::streams_boost::bimaps::container_adaptor::
                unordered_associative_container_adaptor
    <
        Base,
        Iterator, ConstIterator, LocalIterator, ConstLocalIterator,
        STREAMS_BOOST_DEDUCED_TYPENAME Iterator::value_type,
        IteratorToBaseConverter, IteratorFromBaseConverter,
        LocalIteratorFromBaseConverter,
        ValueToBaseConverter, ValueFromBaseConverter,
        KeyToBaseConverter,
        FunctorsFromDerivedClasses
    >
{
    typedef ::streams_boost::bimaps::container_adaptor::
                unordered_associative_container_adaptor
    <
        Base,
        Iterator, ConstIterator, LocalIterator, ConstLocalIterator,
        STREAMS_BOOST_DEDUCED_TYPENAME Iterator::value_type,
        IteratorToBaseConverter, IteratorFromBaseConverter,
        LocalIteratorFromBaseConverter,
        ValueToBaseConverter, ValueFromBaseConverter,
        KeyToBaseConverter,
        FunctorsFromDerivedClasses

    > base_;

    // Access -----------------------------------------------------------------

    public:

    explicit unordered_set_adaptor(Base & c) :
        base_(c) {}

    protected:

    typedef unordered_set_adaptor unordered_set_adaptor_;

};


} // namespace container_adaptor
} // namespace bimaps
} // namespace streams_boost


#endif // STREAMS_BOOST_BIMAP_CONTAINER_ADAPTOR_UNORDERED_SET_ADAPTOR_HPP

