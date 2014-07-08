// Boost.Bimap
//
// Copyright (c) 2006-2007 Matias Capeletto
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

/// \file container_adaptor/sequence_container_adaptor.hpp
/// \brief Container adaptor to build a type that is compliant to the concept of a weak associative container.

#ifndef STREAMS_BOOST_BIMAP_CONTAINER_ADAPTOR_SEQUENCE_CONTAINER_ADAPTOR_HPP
#define STREAMS_BOOST_BIMAP_CONTAINER_ADAPTOR_SEQUENCE_CONTAINER_ADAPTOR_HPP

#if defined(_MSC_VER) && (_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/config.hpp>

#include <utility>

#include <streams_boost/mpl/if.hpp>
#include <streams_boost/mpl/vector.hpp>
#include <streams_boost/mpl/aux_/na.hpp>
#include <streams_boost/bimap/container_adaptor/detail/identity_converters.hpp>
#include <streams_boost/bimap/container_adaptor/container_adaptor.hpp>
#include <streams_boost/call_traits.hpp>
#include <streams_boost/operators.hpp>

namespace streams_boost {
namespace bimaps {
namespace container_adaptor {

#ifndef STREAMS_BOOST_BIMAP_DOXYGEN_WILL_NOT_PROCESS_THE_FOLLOWING_LINES

template
<
    class Base, class Iterator, class ConstIterator,
    class ReverseIterator, class ConstReverseIterator,
    class IteratorToBaseConverter, class IteratorFromBaseConverter,
    class ReverseIteratorFromBaseConverter,
    class ValueToBaseConverter, class ValueFromBaseConverter,
    class FunctorsFromDerivedClasses
>
struct sequence_container_adaptor_base
{
    typedef container_adaptor
    <
        Base, Iterator, ConstIterator,
        IteratorToBaseConverter, IteratorFromBaseConverter,
        ValueToBaseConverter, ValueFromBaseConverter,

        STREAMS_BOOST_DEDUCED_TYPENAME mpl::push_front<

            FunctorsFromDerivedClasses,

            STREAMS_BOOST_DEDUCED_TYPENAME mpl::if_<
                ::streams_boost::mpl::is_na<ReverseIteratorFromBaseConverter>,
            // {
                    detail::iterator_from_base_identity
                    <
                        STREAMS_BOOST_DEDUCED_TYPENAME Base::reverse_iterator, 
                        ReverseIterator,
                        STREAMS_BOOST_DEDUCED_TYPENAME Base::const_reverse_iterator,
                        ConstReverseIterator
                    >,
            // }
            // else
            // {
                    ReverseIteratorFromBaseConverter
            // }

            >::type

        >::type

    > type;
};

#endif // STREAMS_BOOST_BIMAP_DOXYGEN_WILL_NOT_PROCESS_THE_FOLLOWING_LINES

/// \brief Container adaptor to build a type that is compliant to the concept of a sequence container.

template
<
    class Base,

    class Iterator,
    class ConstIterator,

    class ReverseIterator,
    class ConstReverseIterator,

    class IteratorToBaseConverter           = ::streams_boost::mpl::na,
    class IteratorFromBaseConverter         = ::streams_boost::mpl::na,
    class ReverseIteratorFromBaseConverter  = ::streams_boost::mpl::na,
    class ValueToBaseConverter              = ::streams_boost::mpl::na,
    class ValueFromBaseConverter            = ::streams_boost::mpl::na,

    class FunctorsFromDerivedClasses = mpl::vector<>
>
class sequence_container_adaptor :

    public sequence_container_adaptor_base
    <
        Base, Iterator, ConstIterator,
        ReverseIterator, ConstReverseIterator,
        IteratorToBaseConverter, IteratorFromBaseConverter,
        ReverseIteratorFromBaseConverter,
        ValueToBaseConverter, ValueFromBaseConverter,
        FunctorsFromDerivedClasses

    >::type,

    ::streams_boost::totally_ordered
    <
        sequence_container_adaptor
        <
            Base, Iterator, ConstIterator,
            ReverseIterator, ConstReverseIterator,
            IteratorToBaseConverter, IteratorFromBaseConverter,
            ReverseIteratorFromBaseConverter,
            ValueToBaseConverter, ValueFromBaseConverter,
            FunctorsFromDerivedClasses
        >
    >
{
    typedef STREAMS_BOOST_DEDUCED_TYPENAME sequence_container_adaptor_base
    <
        Base, Iterator, ConstIterator,
        ReverseIterator, ConstReverseIterator,
        IteratorToBaseConverter, IteratorFromBaseConverter,
        ReverseIteratorFromBaseConverter,
        ValueToBaseConverter, ValueFromBaseConverter,
        FunctorsFromDerivedClasses

    >::type base_;

    // MetaData -------------------------------------------------------------

    public:

    typedef ReverseIterator      reverse_iterator;
    typedef ConstReverseIterator const_reverse_iterator;

    protected:

    typedef STREAMS_BOOST_DEDUCED_TYPENAME mpl::if_<
        ::streams_boost::mpl::is_na<ReverseIteratorFromBaseConverter>,
        // {
                detail::iterator_from_base_identity
                <
                    STREAMS_BOOST_DEDUCED_TYPENAME Base::reverse_iterator,
                    reverse_iterator,
                    STREAMS_BOOST_DEDUCED_TYPENAME Base::const_reverse_iterator,
                    const_reverse_iterator
                >,
        // }
        // else
        // {
                ReverseIteratorFromBaseConverter
        // }

        >::type reverse_iterator_from_base;


    // Access -----------------------------------------------------------------

    public:

    explicit sequence_container_adaptor(Base & c)
        : base_(c) {}

    protected:


    typedef sequence_container_adaptor sequence_container_adaptor_;

    // Interface --------------------------------------------------------------

    public:

    reverse_iterator rbegin()
    {
        return this->template functor<
            reverse_iterator_from_base
        >()                            ( this->base().rbegin() );

    }

    reverse_iterator rend()
    {
        return this->template functor<
            reverse_iterator_from_base
        >()                            ( this->base().rend() );
    }

    const_reverse_iterator rbegin() const
    {
        return this->template functor<
            reverse_iterator_from_base
        >()                            ( this->base().rbegin() );
    }

    const_reverse_iterator rend() const
    {
        return this->template functor<
            reverse_iterator_from_base
        >()                            ( this->base().rend() );
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

    STREAMS_BOOST_DEDUCED_TYPENAME base_::reference front()
    {
        return this->template functor<
            STREAMS_BOOST_DEDUCED_TYPENAME base_::value_from_base>()
        (
            this->base().front()
        );
    }

    STREAMS_BOOST_DEDUCED_TYPENAME base_::reference back()
    {
        return this->template functor<
            STREAMS_BOOST_DEDUCED_TYPENAME base_::value_from_base>()
        (
            this->base().back()
        );
    }

    STREAMS_BOOST_DEDUCED_TYPENAME base_::const_reference front() const
    {
        return this->template functor<
            STREAMS_BOOST_DEDUCED_TYPENAME base_::value_from_base>()
        (
            this->base().front()
        );
    }

    STREAMS_BOOST_DEDUCED_TYPENAME base_::const_reference back() const
    {
        return this->template functor<
            STREAMS_BOOST_DEDUCED_TYPENAME base_::value_from_base>()
        (
            this->base().back()
        );
    }

    void push_front(
        STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::call_traits<
            STREAMS_BOOST_DEDUCED_TYPENAME base_::value_type >::param_type x)
    {
        this->base().push_front(
            this->template functor<STREAMS_BOOST_DEDUCED_TYPENAME base_::value_to_base>()(x));
    }

    void pop_front()
    {
        this->base().pop_front();
    }

    void push_back(
        STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::call_traits< 
            STREAMS_BOOST_DEDUCED_TYPENAME base_::value_type >::param_type x)
    {
        this->base().push_back(
            this->template functor<STREAMS_BOOST_DEDUCED_TYPENAME base_::value_to_base>()(x));
    }

    void pop_back()
    {
        this->base().pop_back();
    }

    std::pair<STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator,bool>
    insert(STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator position,
           STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::call_traits< 
                STREAMS_BOOST_DEDUCED_TYPENAME base_::value_type >::param_type x)
    {
        std::pair< STREAMS_BOOST_DEDUCED_TYPENAME Base::iterator, bool > r(
            this->base().insert(
                this->template functor<
                    STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator_to_base>()(position),
                this->template functor<
                    STREAMS_BOOST_DEDUCED_TYPENAME base_::value_to_base   >()(x)
            )
        );

        return std::pair<STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator, bool>(
            this->template functor<
                STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator_from_base>()(r.first),
            r.second
        );
    }

    void insert(STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator position,
                STREAMS_BOOST_DEDUCED_TYPENAME base_::size_type m,
                STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::call_traits<
                    STREAMS_BOOST_DEDUCED_TYPENAME base_::value_type >::param_type x)
    {
        this->base().insert(
            this->template functor<
                STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator_to_base>()(position),
            m,
            this->template functor<STREAMS_BOOST_DEDUCED_TYPENAME base_::value_to_base   >()(x)
        );
    }

    template< class InputIterator >
    void insert(STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator position,
                InputIterator first, InputIterator last)
    {
        // This is the same problem found in the insert function 
        // of container_adaptor
        // For now, do the simple thing. This can be optimized

        for( ; first != last ; ++first )
        {
            this->base().insert(
                this->template functor<
                    STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator_to_base>()( position ),
                this->template functor<
                    STREAMS_BOOST_DEDUCED_TYPENAME base_::value_to_base   >()( *first )
            );
        }
    }

    // Totally ordered implementation

    bool operator==(const sequence_container_adaptor & c) const
    {
        return ( this->base() == c.base() );
    }

    bool operator<(const sequence_container_adaptor & c) const
    {
        return ( this->base() < c.base() );
    }
};

} // namespace container_adaptor
} // namespace bimaps
} // namespace streams_boost


#endif // STREAMS_BOOST_BIMAP_CONTAINER_ADAPTOR_SEQUENCE_CONTAINER_ADAPTOR_HPP
