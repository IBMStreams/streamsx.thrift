// Boost.Bimap
//
// Copyright (c) 2006-2007 Matias Capeletto
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

/// \file container_adaptor/vector_map_adaptor.hpp
/// \brief Container adaptor.

#ifndef STREAMS_BOOST_BIMAP_CONTAINER_ADAPTOR_VECTOR_MAP_ADAPTOR_HPP
#define STREAMS_BOOST_BIMAP_CONTAINER_ADAPTOR_VECTOR_MAP_ADAPTOR_HPP

#if defined(_MSC_VER) && (_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/config.hpp>

#include <streams_boost/mpl/list.hpp>
#include <streams_boost/mpl/push_front.hpp>
#include <streams_boost/mpl/aux_/na.hpp>
#include <streams_boost/bimap/container_adaptor/vector_adaptor.hpp>
#include <streams_boost/bimap/container_adaptor/detail/identity_converters.hpp>
#include <streams_boost/mpl/vector.hpp>

namespace streams_boost {
namespace bimaps {
namespace container_adaptor {

/// \brief Container adaptor.

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
class vector_map_adaptor :

    public vector_adaptor
    <
        Base,
        Iterator, ConstIterator, ReverseIterator, ConstReverseIterator,
        IteratorToBaseConverter, IteratorFromBaseConverter,
        ReverseIteratorFromBaseConverter,
        ValueToBaseConverter, ValueFromBaseConverter,
        FunctorsFromDerivedClasses
    >
{
    typedef vector_adaptor
    <
        Base,
        Iterator, ConstIterator, ReverseIterator, ConstReverseIterator,
        IteratorToBaseConverter, IteratorFromBaseConverter,
        ReverseIteratorFromBaseConverter,
        ValueToBaseConverter, ValueFromBaseConverter,
        FunctorsFromDerivedClasses

    > base_;

    // MetaData -------------------------------------------------------------

    public:

    typedef STREAMS_BOOST_DEDUCED_TYPENAME Iterator::value_type::first_type  key_type;
    typedef STREAMS_BOOST_DEDUCED_TYPENAME Iterator::value_type::second_type data_type;

    // Access -----------------------------------------------------------------

    public:

    vector_map_adaptor() {}

    explicit vector_map_adaptor(Base & c) :
        base_(c) {}

    protected:

    typedef vector_map_adaptor vector_map_adaptor_;

};


} // namespace container_adaptor
} // namespace bimaps
} // namespace streams_boost


#endif // STREAMS_BOOST_BIMAP_CONTAINER_ADAPTOR_VECTOR_MAP_ADAPTOR_HPP

