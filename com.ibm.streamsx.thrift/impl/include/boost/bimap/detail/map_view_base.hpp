// Boost.Bimap
//
// Copyright (c) 2006-2007 Matias Capeletto
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

/// \file detail/map_view_base.hpp
/// \brief Helper base for the construction of the bimap views types.

#ifndef STREAMS_BOOST_BIMAP_DETAIL_MAP_VIEW_BASE_HPP
#define STREAMS_BOOST_BIMAP_DETAIL_MAP_VIEW_BASE_HPP

#if defined(_MSC_VER) && (_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/config.hpp>

#include <stdexcept>
#include <utility>

#include <streams_boost/throw_exception.hpp>
#include <streams_boost/type_traits/is_const.hpp>
#include <streams_boost/mpl/if.hpp>

#include <streams_boost/bimap/relation/support/get_pair_functor.hpp>
#include <streams_boost/bimap/relation/detail/to_mutable_relation_functor.hpp>
#include <streams_boost/bimap/container_adaptor/support/iterator_facade_converters.hpp>
#include <streams_boost/bimap/relation/support/data_extractor.hpp>
#include <streams_boost/bimap/relation/support/opposite_tag.hpp>
#include <streams_boost/bimap/relation/support/pair_type_by.hpp>
#include <streams_boost/bimap/support/iterator_type_by.hpp>
#include <streams_boost/bimap/support/key_type_by.hpp>
#include <streams_boost/bimap/support/data_type_by.hpp>
#include <streams_boost/bimap/support/value_type_by.hpp>
#include <streams_boost/bimap/detail/modifier_adaptor.hpp>
#include <streams_boost/bimap/detail/debug/static_error.hpp>

namespace streams_boost {
namespace bimaps {

namespace detail {


// The next macro can be converted in a metafunctor to gain code robustness.
/*===========================================================================*/
#define STREAMS_BOOST_BIMAP_MAP_VIEW_CONTAINER_ADAPTOR(                               \
    CONTAINER_ADAPTOR, TAG,BIMAP, OTHER_ITER, CONST_OTHER_ITER                \
)                                                                             \
::streams_boost::bimaps::container_adaptor::CONTAINER_ADAPTOR                         \
<                                                                             \
    STREAMS_BOOST_DEDUCED_TYPENAME BIMAP::core_type::                                 \
        STREAMS_BOOST_NESTED_TEMPLATE index<TAG>::type,                               \
    STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::bimaps::support::                         \
        iterator_type_by<TAG,BIMAP>::type,                                    \
    STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::bimaps::support::                         \
        const_iterator_type_by<TAG,BIMAP>::type,                              \
    STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::bimaps::support::                         \
        OTHER_ITER<TAG,BIMAP>::type,                                          \
    STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::bimaps::support::                         \
        CONST_OTHER_ITER<TAG,BIMAP>::type,                                    \
    ::streams_boost::bimaps::container_adaptor::support::iterator_facade_to_base      \
    <                                                                         \
        STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::bimaps::support::                     \
                  iterator_type_by<TAG,BIMAP>::type,                          \
        STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::bimaps::support::                     \
            const_iterator_type_by<TAG,BIMAP>::type                           \
                                                                              \
    >,                                                                        \
    ::streams_boost::mpl::na,                                                         \
    ::streams_boost::mpl::na,                                                         \
    ::streams_boost::bimaps::relation::detail::                                       \
        pair_to_relation_functor<TAG,STREAMS_BOOST_DEDUCED_TYPENAME BIMAP::relation>, \
    ::streams_boost::bimaps::relation::support::                                      \
        get_pair_functor<TAG, STREAMS_BOOST_DEDUCED_TYPENAME BIMAP::relation >        \
>
/*===========================================================================*/


#if defined(STREAMS_BOOST_MSVC)
/*===========================================================================*/
#define STREAMS_BOOST_BIMAP_MAP_VIEW_BASE_FRIEND(TYPE,TAG,BIMAP)                      \
    typedef ::streams_boost::bimaps::detail::map_view_base<                           \
        TYPE<TAG,BIMAP>,TAG,BIMAP > friend_map_view_base;                     \
    friend class friend_map_view_base;
/*===========================================================================*/
#else
/*===========================================================================*/
#define STREAMS_BOOST_BIMAP_MAP_VIEW_BASE_FRIEND(TYPE,TAG,BIMAP)                      \
    friend class ::streams_boost::bimaps::detail::map_view_base<                      \
        TYPE<TAG,BIMAP>,TAG,BIMAP >;
/*===========================================================================*/
#endif


/// \brief Common base for map views.

template< class Derived, class Tag, class BimapType>
class map_view_base
{
    typedef ::streams_boost::bimaps::container_adaptor::support::
        iterator_facade_to_base<

            STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::bimaps::support::
                iterator_type_by<Tag,BimapType>::type,

            STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::bimaps::support::
                const_iterator_type_by<Tag,BimapType>::type

        > iterator_to_base_;

    typedef ::streams_boost::bimaps::relation::detail::
        pair_to_relation_functor<Tag,
            STREAMS_BOOST_DEDUCED_TYPENAME BimapType::relation>      value_to_base_;

    typedef STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::bimaps::support::
                           key_type_by<Tag,BimapType>::type       key_type_;

    typedef STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::bimaps::support::
                          data_type_by<Tag,BimapType>::type      data_type_;

    typedef STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::bimaps::relation::support::
           pair_type_by<Tag,
              STREAMS_BOOST_DEDUCED_TYPENAME BimapType::relation>::type value_type_;

    typedef STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::bimaps::support::
                    iterator_type_by<Tag,BimapType>::type         iterator_;

    public:

    bool replace(iterator_ position, const value_type_ & x)
    {
        return derived().base().replace(
            derived().template functor<iterator_to_base_>()(position),
            derived().template functor<value_to_base_>()(x)
        );
    }

    template< class CompatibleKey >
    bool replace_key(iterator_ position, const CompatibleKey & k)
    {
        return derived().base().replace(
            derived().template functor<iterator_to_base_>()(position),
            derived().template functor<value_to_base_>()(
                value_type_(k,position->second)
            )
        );
    }

    template< class CompatibleData >
    bool replace_data(iterator_ position, const CompatibleData & d)
    {
        return derived().base().replace(
            derived().template functor<iterator_to_base_>()(position),
            derived().template functor<value_to_base_>()(
                value_type_(position->first,d)
            )
        );
    }

    /* This function may be provided in the future

    template< class Modifier >
    bool modify(iterator_ position, Modifier mod)
    {
        return derived().base().modify(

            derived().template functor<iterator_to_base_>()(position),

            ::streams_boost::bimaps::detail::relation_modifier_adaptor
            <
                Modifier,
                STREAMS_BOOST_DEDUCED_TYPENAME BimapType::relation,
                STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::bimaps::relation::support::
                data_extractor
                <
                    Tag, STREAMS_BOOST_DEDUCED_TYPENAME BimapType::relation

                >::type,
                STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::bimaps::relation::support::
                data_extractor
                <
                    STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::bimaps::relation::support::
                        opossite_tag<Tag,BimapType>::type,
                    STREAMS_BOOST_DEDUCED_TYPENAME BimapType::relation

                >::type

            >(mod)
        );
    }
    */

    template< class Modifier >
    bool modify_key(iterator_ position, Modifier mod)
    {
        return derived().base().modify_key(
            derived().template functor<iterator_to_base_>()(position), mod
        );
    }

    template< class Modifier >
    bool modify_data(iterator_ position, Modifier mod)
    {
        typedef STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::bimaps::relation::support::
        data_extractor
        <
            STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::bimaps::relation::support::
                        opossite_tag<Tag,BimapType>::type,
            STREAMS_BOOST_DEDUCED_TYPENAME BimapType::relation

        >::type data_extractor_;

        return derived().base().modify(

            derived().template functor<iterator_to_base_>()(position),

            // this may be replaced later by
            // ::streams_boost::bind( mod, ::streams_boost::bind(data_extractor_(),_1) )

            ::streams_boost::bimaps::detail::unary_modifier_adaptor
            <
                Modifier,
                STREAMS_BOOST_DEDUCED_TYPENAME BimapType::relation,
                data_extractor_

            >(mod)
        );
    }

    protected:

    typedef map_view_base map_view_base_;

    private:

    // Curiously Recurring Template interface.

    Derived& derived()
    {
        return *static_cast<Derived*>(this);
    }

    Derived const& derived() const
    {
        return *static_cast<Derived const*>(this);
    }
};




template< class Derived, class Tag, class BimapType>
class mutable_data_unique_map_view_access
{
    typedef STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::bimaps::support::
                          data_type_by<Tag,BimapType>::type      data_type_;

    public:

    template< class CompatibleKey >
    data_type_ & at(const CompatibleKey& k)
    {
        typedef STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::bimaps::support::
                            iterator_type_by<Tag,BimapType>::type iterator;

        iterator iter = derived().find(k);
        if( iter == derived().end() )
        {
            ::streams_boost::throw_exception(
                std::out_of_range("bimap<>: invalid key")
            );
        }
        return iter->second;
    }

    template< class CompatibleKey >
    const data_type_ & at(const CompatibleKey& k) const
    {
        typedef STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::bimaps::support::
                const_iterator_type_by<Tag,BimapType>::type const_iterator;

        const_iterator iter = derived().find(k);
        if( iter == derived().end() )
        {
            ::streams_boost::throw_exception(
                std::out_of_range("bimap<>: invalid key")
            );
        }
        return iter->second;
    }

    template< class CompatibleKey >
    data_type_ & operator[](const CompatibleKey& k)
    {
        typedef STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::bimaps::support::
                      iterator_type_by<Tag,BimapType>::type       iterator;

        typedef STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::bimaps::support::
                         value_type_by<Tag,BimapType>::type     value_type;

        iterator iter = derived().find(k);
        if( iter == derived().end() )
        {
            iter = derived().insert( value_type(k,data_type_()) ).first;
        }
        return iter->second;
    }

    protected:

    typedef mutable_data_unique_map_view_access
                mutable_data_unique_map_view_access_;

    private:

    // Curiously Recurring Template interface.

    Derived& derived()
    {
        return *static_cast<Derived*>(this);
    }

    Derived const& derived() const
    {
        return *static_cast<Derived const*>(this);
    }
};


template< class Derived, class Tag, class BimapType>
class non_mutable_data_unique_map_view_access
{
    typedef STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::bimaps::support::
                          data_type_by<Tag,BimapType>::type      data_type_;

    public:

    template< class CompatibleKey >
    const data_type_ & at(const CompatibleKey& k) const
    {
        typedef STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::bimaps::support::
                const_iterator_type_by<Tag,BimapType>::type const_iterator;

        const_iterator iter = derived().find(k);
        if( iter == derived().end() )
        {
            ::streams_boost::throw_exception(
                std::out_of_range("bimap<>: invalid key")
            );
        }
        return iter->second;
    }

    template< class CompatibleKey >
    data_type_ & operator[](const CompatibleKey& k)
    {
        STREAMS_BOOST_BIMAP_STATIC_ERROR( OPERATOR_BRACKET_IS_NOT_SUPPORTED, (Derived));
    }

    protected:

    typedef non_mutable_data_unique_map_view_access
                non_mutable_data_unique_map_view_access_;

    private:

    // Curiously Recurring Template interface.

    Derived& derived()
    {
        return *static_cast<Derived*>(this);
    }

    Derived const& derived() const
    {
        return *static_cast<Derived const*>(this);
    }
};


template< class Derived, class Tag, class BimapType>
struct unique_map_view_access
{
    private:
    typedef STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::bimaps::support::
        value_type_by<Tag,BimapType>::type value_type;

    public:
    typedef STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::mpl::if_
    <
        typename ::streams_boost::is_const<
            STREAMS_BOOST_DEDUCED_TYPENAME value_type::second_type >::type,

        non_mutable_data_unique_map_view_access<Derived,Tag,BimapType>,
        mutable_data_unique_map_view_access<Derived,Tag,BimapType>

    >::type type;
};

// Map views specialize the following structs to provide to the bimap class
// the extra side typedefs (i.e. left_local_iterator for unordered_maps, 
// right_range_type for maps)

template< class MapView >
struct  left_map_view_extra_typedefs {};

template< class MapView >
struct right_map_view_extra_typedefs {};

} // namespace detail

// This function is already part of Boost.Lambda.
// They may be moved to Boost.Utility.

template <class T> inline const T&  make_const(const T& t) { return t; }

} // namespace bimaps
} // namespace streams_boost


// The following macros avoids code duplication in map views
// Maybe this can be changed in the future using a scheme similar to
// the one used with map_view_base.

/*===========================================================================*/
#define STREAMS_BOOST_BIMAP_MAP_VIEW_RANGE_IMPLEMENTATION(BASE)                       \
                                                                              \
typedef std::pair<                                                            \
    STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator,                                   \
    STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator> range_type;                       \
                                                                              \
typedef std::pair<                                                            \
    STREAMS_BOOST_DEDUCED_TYPENAME base_::const_iterator,                             \
    STREAMS_BOOST_DEDUCED_TYPENAME base_::const_iterator> const_range_type;           \
                                                                              \
                                                                              \
template< class LowerBounder, class UpperBounder>                             \
range_type range(LowerBounder lower,UpperBounder upper)                       \
{                                                                             \
    std::pair<                                                                \
                                                                              \
        STREAMS_BOOST_DEDUCED_TYPENAME BASE::base_type::iterator,                     \
        STREAMS_BOOST_DEDUCED_TYPENAME BASE::base_type::iterator                      \
                                                                              \
    > r( this->base().range(lower,upper) );                                   \
                                                                              \
    return range_type(                                                        \
        this->template functor<                                               \
            STREAMS_BOOST_DEDUCED_TYPENAME BASE::iterator_from_base                   \
        >()                                         ( r.first ),              \
        this->template functor<                                               \
            STREAMS_BOOST_DEDUCED_TYPENAME BASE::iterator_from_base                   \
        >()                                         ( r.second )              \
    );                                                                        \
}                                                                             \
                                                                              \
template< class LowerBounder, class UpperBounder>                             \
const_range_type range(LowerBounder lower,UpperBounder upper) const           \
{                                                                             \
    std::pair<                                                                \
                                                                              \
        STREAMS_BOOST_DEDUCED_TYPENAME BASE::base_type::const_iterator,               \
        STREAMS_BOOST_DEDUCED_TYPENAME BASE::base_type::const_iterator                \
                                                                              \
    > r( this->base().range(lower,upper) );                                   \
                                                                              \
    return const_range_type(                                                  \
        this->template functor<                                               \
            STREAMS_BOOST_DEDUCED_TYPENAME BASE::iterator_from_base                   \
        >()                                         ( r.first ),              \
        this->template functor<                                               \
            STREAMS_BOOST_DEDUCED_TYPENAME BASE::iterator_from_base                   \
        >()                                         ( r.second )              \
    );                                                                        \
}
/*===========================================================================*/


/*===========================================================================*/
#define STREAMS_BOOST_BIMAP_VIEW_ASSIGN_IMPLEMENTATION(BASE)                          \
                                                                              \
template< class InputIterator >                                               \
void assign(InputIterator first,InputIterator last)                           \
{                                                                             \
    this->clear();                                                            \
    this->insert(this->end(),first,last);                                     \
}                                                                             \
                                                                              \
void assign(STREAMS_BOOST_DEDUCED_TYPENAME BASE::size_type n,                         \
            const STREAMS_BOOST_DEDUCED_TYPENAME BASE::value_type& v)                 \
{                                                                             \
    this->clear();                                                            \
    for(STREAMS_BOOST_DEDUCED_TYPENAME BASE::size_type i = 0 ; i < n ; ++n)           \
    {                                                                         \
        this->push_back(v);                                                   \
    }                                                                         \
}
/*===========================================================================*/


/*===========================================================================*/
#define STREAMS_BOOST_BIMAP_VIEW_FRONT_BACK_IMPLEMENTATION(BASE)                      \
                                                                              \
STREAMS_BOOST_DEDUCED_TYPENAME BASE::reference front()                                \
{                                                                             \
    return this->template functor<                                            \
        STREAMS_BOOST_DEDUCED_TYPENAME base_::value_from_base>()                      \
    (                                                                         \
        const_cast                                                            \
        <                                                                     \
            STREAMS_BOOST_DEDUCED_TYPENAME BASE::base_type::value_type &              \
                                                                              \
        > ( this->base().front() )                                            \
    );                                                                        \
}                                                                             \
                                                                              \
STREAMS_BOOST_DEDUCED_TYPENAME BASE::reference back()                                 \
{                                                                             \
    return this->template functor<                                            \
        STREAMS_BOOST_DEDUCED_TYPENAME base_::value_from_base>()                      \
    (                                                                         \
        const_cast                                                            \
        <                                                                     \
            STREAMS_BOOST_DEDUCED_TYPENAME BASE::base_type::value_type &              \
                                                                              \
        >( this->base().back() )                                              \
    );                                                                        \
}                                                                             \
                                                                              \
STREAMS_BOOST_DEDUCED_TYPENAME BASE::const_reference front() const                    \
{                                                                             \
    return this->template functor<                                            \
        STREAMS_BOOST_DEDUCED_TYPENAME BASE::value_from_base>()                       \
    (                                                                         \
        this->base().front()                                                  \
    );                                                                        \
}                                                                             \
                                                                              \
STREAMS_BOOST_DEDUCED_TYPENAME BASE::const_reference back() const                     \
{                                                                             \
    return this->template functor<                                            \
        STREAMS_BOOST_DEDUCED_TYPENAME BASE::value_from_base>()                       \
    (                                                                         \
        this->base().back()                                                   \
    );                                                                        \
}
/*===========================================================================*/


#endif // STREAMS_BOOST_BIMAP_DETAIL_MAP_VIEW_BASE_HPP
