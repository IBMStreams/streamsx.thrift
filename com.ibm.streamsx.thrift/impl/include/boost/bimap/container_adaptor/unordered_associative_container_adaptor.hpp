// Boost.Bimap
//
// Copyright (c) 2006-2007 Matias Capeletto
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

/// \file container_adaptor/unordered_associative_container_adaptor.hpp
/// \brief Container adaptor to build a type that is compliant to the concept of an unordered associative container.

#ifndef STREAMS_BOOST_BIMAP_CONTAINER_ADAPTOR_UNORDERED_ASSOCIATIVE_CONTAINER_ADAPTOR_HPP
#define STREAMS_BOOST_BIMAP_CONTAINER_ADAPTOR_UNORDERED_ASSOCIATIVE_CONTAINER_ADAPTOR_HPP

#if defined(_MSC_VER) && (_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/config.hpp>

#include <streams_boost/bimap/container_adaptor/associative_container_adaptor.hpp>
#include <streams_boost/mpl/if.hpp>
#include <streams_boost/mpl/vector.hpp>
#include <streams_boost/mpl/push_front.hpp>
#include <streams_boost/mpl/aux_/na.hpp>
#include <streams_boost/call_traits.hpp>

namespace streams_boost {
namespace bimaps {
namespace container_adaptor {


#ifndef STREAMS_BOOST_BIMAP_DOXYGEN_WILL_NOT_PROCESS_THE_FOLLOWING_LINES

template
<
    class Base, class Iterator, class ConstIterator,
    class LocalIterator, class ConstLocalIterator,
    class KeyType,
    class IteratorToBaseConverter, class IteratorFromBaseConverter,
    class LocalIteratorFromBaseConverter,
    class ValueToBaseConverter, class ValueFromBaseConverter,
    class KeyToBaseConverter,
    class FunctorsFromDerivedClasses
>
struct unordered_associative_container_adaptor_base
{

    typedef associative_container_adaptor
    <
        Base, Iterator, ConstIterator, KeyType,
        IteratorToBaseConverter, IteratorFromBaseConverter,
        ValueToBaseConverter   , ValueFromBaseConverter,
        KeyToBaseConverter,

        STREAMS_BOOST_DEDUCED_TYPENAME mpl::push_front<

            FunctorsFromDerivedClasses,

            STREAMS_BOOST_DEDUCED_TYPENAME mpl::if_<
                ::streams_boost::mpl::is_na<LocalIteratorFromBaseConverter>,
            // {
                    detail::iterator_from_base_identity
                    <
                        STREAMS_BOOST_DEDUCED_TYPENAME Base::local_iterator,
                        LocalIterator,
                        STREAMS_BOOST_DEDUCED_TYPENAME Base::const_local_iterator,
                        ConstLocalIterator
                    >,
            // }
            // else
            // {
                    LocalIteratorFromBaseConverter
            // }

            >::type

        >::type

    > type;
};

#endif // STREAMS_BOOST_BIMAP_DOXYGEN_WILL_NOT_PROCESS_THE_FOLLOWING_LINES


/// \brief Container adaptor to build a type that is compliant to the concept of an unordered associative container.

template
<
    class Base,

    class Iterator,
    class ConstIterator,

    class LocalIterator,
    class ConstLocalIterator,

    class KeyType,

    class IteratorToBaseConverter        = ::streams_boost::mpl::na,
    class IteratorFromBaseConverter      = ::streams_boost::mpl::na,
    class LocalIteratorFromBaseConverter = ::streams_boost::mpl::na,
    class ValueToBaseConverter           = ::streams_boost::mpl::na,
    class ValueFromBaseConverter         = ::streams_boost::mpl::na,
    class KeyToBaseConverter             = ::streams_boost::mpl::na,

    class FunctorsFromDerivedClasses     = mpl::vector<>

>
class unordered_associative_container_adaptor :

    public unordered_associative_container_adaptor_base
    <
        Base, Iterator, ConstIterator,
        LocalIterator, ConstLocalIterator,
        KeyType,
        IteratorToBaseConverter, IteratorFromBaseConverter,
        LocalIteratorFromBaseConverter,
        ValueToBaseConverter, ValueFromBaseConverter,
        KeyToBaseConverter,
        FunctorsFromDerivedClasses

    >::type
{
    typedef STREAMS_BOOST_DEDUCED_TYPENAME unordered_associative_container_adaptor_base
    <
        Base, Iterator, ConstIterator,
        LocalIterator, ConstLocalIterator,
        KeyType,
        IteratorToBaseConverter, IteratorFromBaseConverter,
        LocalIteratorFromBaseConverter,
        ValueToBaseConverter, ValueFromBaseConverter,
        KeyToBaseConverter,
        FunctorsFromDerivedClasses

    >::type base_;

    // Metadata ---------------------------------------------------------------

    public:

    typedef STREAMS_BOOST_DEDUCED_TYPENAME Base::key_equal key_equal;
    typedef STREAMS_BOOST_DEDUCED_TYPENAME Base::hasher hasher;

    typedef LocalIterator      local_iterator;
    typedef ConstLocalIterator const_local_iterator;

    protected:

    typedef STREAMS_BOOST_DEDUCED_TYPENAME mpl::if_<
        ::streams_boost::mpl::is_na<LocalIteratorFromBaseConverter>,
        // {
                detail::iterator_from_base_identity
                <
                    STREAMS_BOOST_DEDUCED_TYPENAME Base::local_iterator,
                    local_iterator,
                    STREAMS_BOOST_DEDUCED_TYPENAME Base::const_local_iterator,
                    const_local_iterator
                >,
        // }
        // else
        // {
                LocalIteratorFromBaseConverter
        // }

        >::type local_iterator_from_base;

    // Access -----------------------------------------------------------------

    public:

    explicit unordered_associative_container_adaptor(Base & c)
        : base_(c) {}

    protected:


    typedef unordered_associative_container_adaptor
                unordered_associative_container_adaptor_;

    // Interface --------------------------------------------------------------

    public:

    // bucket interface:

    STREAMS_BOOST_DEDUCED_TYPENAME base_::size_type bucket_count() const
    {
        return this->base().bucket_count();
    }

    STREAMS_BOOST_DEDUCED_TYPENAME base_::size_type max_bucket_count() const
    {
        return this->base().max_bucket_count();
    }

    STREAMS_BOOST_DEDUCED_TYPENAME base_::size_type bucket_size(
        STREAMS_BOOST_DEDUCED_TYPENAME base_::size_type n) const
    {
        return this->base().bucket_size(n);
    }

    template< class CompatibleKey >
    STREAMS_BOOST_DEDUCED_TYPENAME base_::size_type bucket(
        const CompatibleKey & k) const
    {
        typedef STREAMS_BOOST_DEDUCED_TYPENAME base_::key_to_base key_to_base;
        return this->base().bucket(
            this->template functor<key_to_base>()(k)
        );
    }

    local_iterator       begin(STREAMS_BOOST_DEDUCED_TYPENAME base_::size_type n)
    {
        return this->template functor<
            local_iterator_from_base
        >()                          ( this->base().begin(n) );
    }

    const_local_iterator begin(STREAMS_BOOST_DEDUCED_TYPENAME base_::size_type n) const
    {
        return this->template functor<
            local_iterator_from_base
        >()                          ( this->base().begin(n) );
    }

    local_iterator       end(STREAMS_BOOST_DEDUCED_TYPENAME base_::size_type n)
    {
        return this->template functor<
            local_iterator_from_base
        >()                          ( this->base().end(n) );
    }

    const_local_iterator end(STREAMS_BOOST_DEDUCED_TYPENAME base_::size_type n) const
    {
        return this->template functor<
            local_iterator_from_base
        >()                          ( this->base().end(n) );
    }

    // hash policy

    float load_factor() const
    {
        return this->base().load_factor();
    }

    float max_load_factor() const
    {
        return this->base().max_load_factor();
    }

    void max_load_factor(float z)
    {
        return this->base().max_load_factor(z);
    }

    void rehash(STREAMS_BOOST_DEDUCED_TYPENAME base_::size_type n)
    {
        return this->base().rehash(n);
    }

    // We have redefined end and begin so we have to manually route the old ones

    STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator begin()
    {
        return base_::container_adaptor_::begin();
    }

    STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator end()
    {
        return base_::container_adaptor_::end();
    }

    STREAMS_BOOST_DEDUCED_TYPENAME base_::const_iterator begin() const
    {
        return base_::container_adaptor_::begin();
    }

    STREAMS_BOOST_DEDUCED_TYPENAME base_::const_iterator end() const
    {
        return base_::container_adaptor_::end();
    }

};


} // namespace container_adaptor
} // namespace bimaps
} // namespace streams_boost


#endif // STREAMS_BOOST_BIMAP_CONTAINER_ADAPTOR_UNORDERED_ASSOCIATIVE_CONTAINER_ADAPTOR_HPP
