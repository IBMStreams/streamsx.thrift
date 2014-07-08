// Boost.Bimap
//
// Copyright (c) 2006-2007 Matias Capeletto
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

/// \file container_adaptor/vector_adaptor.hpp
/// \brief Container adaptor to easily build a std::vector signature compatible container.

#ifndef STREAMS_BOOST_BIMAP_CONTAINER_ADAPTOR_VECTOR_ADAPTOR_HPP
#define STREAMS_BOOST_BIMAP_CONTAINER_ADAPTOR_VECTOR_ADAPTOR_HPP

#if defined(_MSC_VER) && (_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/config.hpp>

#include <streams_boost/bimap/container_adaptor/sequence_container_adaptor.hpp>
#include <streams_boost/mpl/aux_/na.hpp>
#include <streams_boost/mpl/vector.hpp>

namespace streams_boost {
namespace bimaps {
namespace container_adaptor {

/// \brief Container adaptor to easily build a std::vector signature compatible container.

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
class vector_adaptor :

    public ::streams_boost::bimaps::container_adaptor::sequence_container_adaptor
    <
        Base,
        Iterator, ConstIterator, ReverseIterator, ConstReverseIterator,
        IteratorToBaseConverter, IteratorFromBaseConverter,
        ReverseIteratorFromBaseConverter,
        ValueToBaseConverter, ValueFromBaseConverter,
        FunctorsFromDerivedClasses
    >
{

    typedef ::streams_boost::bimaps::container_adaptor::sequence_container_adaptor
    <
        Base,
        Iterator, ConstIterator, ReverseIterator, ConstReverseIterator,
        IteratorToBaseConverter, IteratorFromBaseConverter,
        ReverseIteratorFromBaseConverter,
        ValueToBaseConverter, ValueFromBaseConverter,
        FunctorsFromDerivedClasses

    > base_;

    // Access -----------------------------------------------------------------

    public:

    vector_adaptor() {}

    explicit vector_adaptor(Base & c) :
        base_(c) {}

    protected:

    typedef vector_adaptor vector_adaptor_;

    // Interface --------------------------------------------------------------

    public:

    STREAMS_BOOST_DEDUCED_TYPENAME base_::size_type capacity() const
    {
        return this->base().capacity();
    }

    void reserve(STREAMS_BOOST_DEDUCED_TYPENAME base_::size_type m)
    {
        this->base().resize(m);
    }

    void resize(STREAMS_BOOST_DEDUCED_TYPENAME base_::size_type n,
                STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::call_traits<
                    STREAMS_BOOST_DEDUCED_TYPENAME base_::value_type >::param_type x =
                        STREAMS_BOOST_DEDUCED_TYPENAME base_::value_type())
    {
        this->base().resize(n,
            this->template functor<STREAMS_BOOST_DEDUCED_TYPENAME base_::value_to_base>()(x)
        );
    }

    STREAMS_BOOST_DEDUCED_TYPENAME base_::const_reference
        operator[](STREAMS_BOOST_DEDUCED_TYPENAME base_::size_type n) const
    {
        return this->base().operator[](n);
    }

    STREAMS_BOOST_DEDUCED_TYPENAME base_::const_reference
        at(STREAMS_BOOST_DEDUCED_TYPENAME base_::size_type n) const
    {
        return this->base().at(n);
    }

    STREAMS_BOOST_DEDUCED_TYPENAME base_::reference
        operator[](STREAMS_BOOST_DEDUCED_TYPENAME base_::size_type n)
    {
        return this->base().operator[](n);
    }

    STREAMS_BOOST_DEDUCED_TYPENAME base_::reference
        at(STREAMS_BOOST_DEDUCED_TYPENAME base_::size_type n)
    {
        return this->base().at(n);
    }
};


} // namespace container_adaptor
} // namespace bimaps
} // namespace streams_boost


#endif // STREAMS_BOOST_BIMAP_CONTAINER_ADAPTOR_VECTOR_ADAPTOR_HPP


