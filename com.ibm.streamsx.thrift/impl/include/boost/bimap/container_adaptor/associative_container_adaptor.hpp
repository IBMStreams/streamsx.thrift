// Boost.Bimap
//
// Copyright (c) 2006-2007 Matias Capeletto
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

/// \file container_adaptor/associative_container_adaptor.hpp
/// \brief Container adaptor to build a type that is compliant to the concept of an associative container.

#ifndef STREAMS_BOOST_BIMAP_CONTAINER_ADAPTOR_ASSOCIATIVE_CONTAINER_ADAPTOR_HPP
#define STREAMS_BOOST_BIMAP_CONTAINER_ADAPTOR_ASSOCIATIVE_CONTAINER_ADAPTOR_HPP

#if defined(_MSC_VER) && (_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/config.hpp>

#include <utility>

#include <streams_boost/mpl/vector.hpp>
#include <streams_boost/mpl/if.hpp>
#include <streams_boost/mpl/aux_/na.hpp>
#include <streams_boost/bimap/container_adaptor/detail/identity_converters.hpp>
#include <streams_boost/bimap/container_adaptor/container_adaptor.hpp>
#include <streams_boost/call_traits.hpp>

namespace streams_boost {
namespace bimaps {
namespace container_adaptor {

#ifndef STREAMS_BOOST_BIMAP_DOXYGEN_WILL_NOT_PROCESS_THE_FOLLOWING_LINES

template
<
    class Base, class Iterator, class ConstIterator, class KeyType,
    class IteratorToBaseConverter, class IteratorFromBaseConverter,
    class ValueToBaseConverter, class ValueFromBaseConverter, class KeyToBaseConverter,
    class FunctorsFromDerivedClasses
>
struct associative_container_adaptor_base
{
    typedef container_adaptor
    <
        Base,

        Iterator, ConstIterator,

        IteratorToBaseConverter, IteratorFromBaseConverter,
        ValueToBaseConverter   , ValueFromBaseConverter,

        STREAMS_BOOST_DEDUCED_TYPENAME mpl::push_front<

            FunctorsFromDerivedClasses,

            STREAMS_BOOST_DEDUCED_TYPENAME mpl::if_< ::streams_boost::mpl::is_na<KeyToBaseConverter>,
            // {
                    detail::key_to_base_identity
                    <
                        STREAMS_BOOST_DEDUCED_TYPENAME Base::key_type, KeyType
                    >,
            // }
            // else
            // {
                    KeyToBaseConverter
            // }

            >::type

        >::type

    > type;
};

#endif // STREAMS_BOOST_BIMAP_DOXYGEN_WILL_NOT_PROCESS_THE_FOLLOWING_LINES


/// \brief Container adaptor to build a type that is compliant to the concept of an associative container.

template
<
    class Base,

    class Iterator,
    class ConstIterator,

    class KeyType,

    class IteratorToBaseConverter   = ::streams_boost::mpl::na,
    class IteratorFromBaseConverter = ::streams_boost::mpl::na,
    class ValueToBaseConverter      = ::streams_boost::mpl::na,
    class ValueFromBaseConverter    = ::streams_boost::mpl::na,
    class KeyToBaseConverter        = ::streams_boost::mpl::na,

    class FunctorsFromDerivedClasses = mpl::vector<>
>
class associative_container_adaptor :

    public associative_container_adaptor_base
    <
        Base, Iterator, ConstIterator, KeyType,
        IteratorToBaseConverter, IteratorFromBaseConverter,
        ValueToBaseConverter, ValueFromBaseConverter, KeyToBaseConverter,
        FunctorsFromDerivedClasses

    >::type
{

    // MetaData -------------------------------------------------------------

    typedef typename associative_container_adaptor_base
    <
        Base, Iterator, ConstIterator, KeyType,
        IteratorToBaseConverter, IteratorFromBaseConverter,
        ValueToBaseConverter, ValueFromBaseConverter, KeyToBaseConverter,
        FunctorsFromDerivedClasses

    >::type base_;

    public:

    typedef KeyType key_type;

    protected:

    typedef STREAMS_BOOST_DEDUCED_TYPENAME mpl::if_< ::streams_boost::mpl::is_na<KeyToBaseConverter>,
    // {
            detail::key_to_base_identity
            <
                STREAMS_BOOST_DEDUCED_TYPENAME Base::key_type, KeyType
            >,
    // }
    // else
    // {
            KeyToBaseConverter
    // }

    >::type key_to_base;

    public:

    explicit associative_container_adaptor(Base & c)
        : base_(c) {}

    protected:


    typedef associative_container_adaptor associative_container_adaptor_;

    // Interface --------------------------------------------------------------

    public:

    template< class CompatibleKey >
    STREAMS_BOOST_DEDUCED_TYPENAME base_::size_type erase(const CompatibleKey & k)
    {
        return this->base().erase
        (
            this->template functor<key_to_base>()(k)
        );
    }

    // As we redefine erase, the other overloads need to be manually routed

    STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator erase(
        STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator pos)
    {
        return base_::container_adaptor_::erase(pos);
    }

    STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator erase(
        STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator first,
        STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator last)
    {
        return base_::container_adaptor_::erase(first,last);
    }

    template< class CompatibleKey >
    STREAMS_BOOST_DEDUCED_TYPENAME base_::size_type count(const CompatibleKey & k) const
    {
        return this->base().count(
            this->template functor<key_to_base>()(k)
        );
    }

    template< class CompatibleKey >
    STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator find(const CompatibleKey & k)
    {
        return this->template functor<typename base_::iterator_from_base>()
        (
            this->base().find(
                this->template functor<key_to_base>()(k)
            )
        );
    }

    template< class CompatibleKey >
    STREAMS_BOOST_DEDUCED_TYPENAME base_::const_iterator
        find(const CompatibleKey & k) const
    {
        return this->template functor<
            STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator_from_base>()
        (
            this->base().find(
                this->template functor<key_to_base>()(k)
            )
        );
    }

    template< class CompatibleKey >
    std::pair
    <
        STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator,
        STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator
    >
        equal_range(const CompatibleKey & k)
    {
        std::pair<

            STREAMS_BOOST_DEDUCED_TYPENAME Base::iterator,
            STREAMS_BOOST_DEDUCED_TYPENAME Base::iterator

        > r( this->base().equal_range(
                this->template functor<key_to_base>()(k)
            )
        );

        return std::pair
        <
            STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator,
            STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator
        >(
            this->template functor<
                STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator_from_base
            >()                                         ( r.first ),
            this->template functor<
                STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator_from_base
            >()                                         ( r.second )
        );
    }

    template< class CompatibleKey >
    std::pair
    <
        STREAMS_BOOST_DEDUCED_TYPENAME base_::const_iterator,
        STREAMS_BOOST_DEDUCED_TYPENAME base_::const_iterator
    >
        equal_range(const CompatibleKey & k) const
    {
        std::pair<

            STREAMS_BOOST_DEDUCED_TYPENAME Base::const_iterator,
            STREAMS_BOOST_DEDUCED_TYPENAME Base::const_iterator

        > r( this->base().equal_range(
                this->template functor<key_to_base>()(k)
            )
        );

        return std::pair
        <
            STREAMS_BOOST_DEDUCED_TYPENAME base_::const_iterator,
            STREAMS_BOOST_DEDUCED_TYPENAME base_::const_iterator
        >(
            this->template functor<
                STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator_from_base
            >()                                         ( r.first ),
            this->template functor<
                STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator_from_base
            >()                                         ( r.second )
        );
    }

};


} // namespace container_adaptor
} // namespace bimaps
} // namespace streams_boost


#endif // STREAMS_BOOST_BIMAP_CONTAINER_ADAPTOR_ASSOCIATIVE_CONTAINER_ADAPTOR_HPP



