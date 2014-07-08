// Boost.Bimap
//
// Copyright (c) 2006-2007 Matias Capeletto
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

/// \file views/vector_map_view.hpp
/// \brief View of a side of a bimap.

#ifndef STREAMS_BOOST_BIMAP_VIEWS_VECTOR_MAP_VIEW_HPP
#define STREAMS_BOOST_BIMAP_VIEWS_VECTOR_MAP_VIEW_HPP

#if defined(_MSC_VER) && (_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/config.hpp>

#include <streams_boost/bimap/container_adaptor/vector_map_adaptor.hpp>
#include <streams_boost/bimap/support/iterator_type_by.hpp>
#include <streams_boost/bimap/detail/map_view_base.hpp>
#include <streams_boost/bimap/container_adaptor/detail/comparison_adaptor.hpp>

namespace streams_boost {
namespace bimaps {
namespace views {

/// \brief View of a side of a bimap.
/**

This class uses container_adaptor and iterator_adaptor to wrapped a index of the
multi_index bimap core.

See also const_map_view.
                                                                             **/
template< class Tag, class BimapType >
class vector_map_view
:
    public STREAMS_BOOST_BIMAP_MAP_VIEW_CONTAINER_ADAPTOR(
        vector_map_adaptor,
        Tag,BimapType,
        reverse_iterator_type_by, const_reverse_iterator_type_by
    ),

    public ::streams_boost::bimaps::detail::
                map_view_base< vector_map_view<Tag,BimapType>,Tag,BimapType >
{
    typedef STREAMS_BOOST_BIMAP_MAP_VIEW_CONTAINER_ADAPTOR(
        vector_map_adaptor,
        Tag,BimapType,
        reverse_iterator_type_by, const_reverse_iterator_type_by

    ) base_;

    STREAMS_BOOST_BIMAP_MAP_VIEW_BASE_FRIEND(vector_map_view,Tag,BimapType)

    typedef STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::bimaps::relation::support::data_extractor
    <
        Tag,
        STREAMS_BOOST_DEDUCED_TYPENAME BimapType::relation

    >::type key_from_base_value;

    public:

    typedef STREAMS_BOOST_DEDUCED_TYPENAME base_::value_type::info_type info_type;

    vector_map_view(STREAMS_BOOST_DEDUCED_TYPENAME base_::base_type & c) :
        base_(c) {}

    vector_map_view & operator=(const vector_map_view & v)
    {
        this->base() = v.base();
        return *this;
    }

    STREAMS_BOOST_BIMAP_VIEW_ASSIGN_IMPLEMENTATION(base_)

    STREAMS_BOOST_BIMAP_VIEW_FRONT_BACK_IMPLEMENTATION(base_)

    // Lists operations

    void splice(STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator position, vector_map_view & x)
    {
        this->base().splice(
            this->template functor<
                STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator_to_base>()(position),
            x.base()
        );
    }

    void splice(STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator position,
                vector_map_view & x,
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
                vector_map_view & x,
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

    template< class Predicate >
    void remove_if(Predicate pred)
    {
        this->base().remove_if(
            ::streams_boost::bimaps::container_adaptor::detail::unary_check_adaptor
            <
                Predicate,
                STREAMS_BOOST_DEDUCED_TYPENAME base_::base_type::value_type,
                key_from_base_value

            >( pred, key_from_base_value() )
        );
    }

    void unique()
    {
        this->base().unique(
            ::streams_boost::bimaps::container_adaptor::detail::comparison_adaptor
            <
                std::equal_to<STREAMS_BOOST_DEDUCED_TYPENAME base_::key_type>,
                STREAMS_BOOST_DEDUCED_TYPENAME base_::base_type::value_type,
                key_from_base_value

            >(std::equal_to<STREAMS_BOOST_DEDUCED_TYPENAME base_::key_type>(),
                    key_from_base_value() )
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
                key_from_base_value

            >( binary_pred, key_from_base_value() )
        );
    }

    void merge(vector_map_view & x)
    {
        this->base().merge(x.base(),
            ::streams_boost::bimaps::container_adaptor::detail::comparison_adaptor
            <
                std::less<STREAMS_BOOST_DEDUCED_TYPENAME base_::key_type>,
                STREAMS_BOOST_DEDUCED_TYPENAME base_::base_type::value_type,
                key_from_base_value

            >( std::less<STREAMS_BOOST_DEDUCED_TYPENAME base_::key_type>(), 
                    key_from_base_value() )
        );
    }

    template< class Compare >
    void merge(vector_map_view & x, Compare comp)
    {
        this->base().merge(x.base(),
            ::streams_boost::bimaps::container_adaptor::detail::comparison_adaptor
            <
                Compare,
                STREAMS_BOOST_DEDUCED_TYPENAME base_::base_type::value_type,
                key_from_base_value

            >( comp, key_from_base_value() )
        );
    }

    void sort()
    {
        this->base().sort(
            ::streams_boost::bimaps::container_adaptor::detail::comparison_adaptor
            <
                std::less<STREAMS_BOOST_DEDUCED_TYPENAME base_::key_type>,
                STREAMS_BOOST_DEDUCED_TYPENAME base_::base_type::value_type,
                key_from_base_value

            >( std::less<STREAMS_BOOST_DEDUCED_TYPENAME base_::key_type>(),
                    key_from_base_value() )
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
                key_from_base_value

            >( comp, key_from_base_value() )
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

/*===========================================================================*/
#define STREAMS_BOOST_BIMAP_MAP_VIEW_EXTRA_TYPEDEF(MAP_VIEW,SIDE,TYPENAME)            \
typedef STREAMS_BOOST_DEDUCED_TYPENAME MAP_VIEW::TYPENAME                             \
    STREAMS_BOOST_PP_CAT(SIDE,STREAMS_BOOST_PP_CAT(_,TYPENAME));
/*===========================================================================*/

/*===========================================================================*/
#define STREAMS_BOOST_BIMAP_MAP_VIEW_EXTRA_TYPEDEFS_BODY(MAP_VIEW,SIDE)               \
    STREAMS_BOOST_BIMAP_MAP_VIEW_EXTRA_TYPEDEF(MAP_VIEW,SIDE,reverse_iterator)        \
    STREAMS_BOOST_BIMAP_MAP_VIEW_EXTRA_TYPEDEF(MAP_VIEW,SIDE,const_reverse_iterator)  \
/*===========================================================================*/

namespace detail {

template< class Tag, class BimapType >
struct left_map_view_extra_typedefs< ::streams_boost::bimaps::views::vector_map_view<Tag,BimapType> >
{
    private: typedef ::streams_boost::bimaps::views::vector_map_view<Tag,BimapType> map_view_;
    public : STREAMS_BOOST_BIMAP_MAP_VIEW_EXTRA_TYPEDEFS_BODY(map_view_,left)
};

template< class Tag, class BimapType >
struct right_map_view_extra_typedefs< ::streams_boost::bimaps::views::vector_map_view<Tag,BimapType> >
{
    private: typedef ::streams_boost::bimaps::views::vector_map_view<Tag,BimapType> map_view_;
    public : STREAMS_BOOST_BIMAP_MAP_VIEW_EXTRA_TYPEDEFS_BODY(map_view_,right)
};

} // namespace detail

/*===========================================================================*/
#undef STREAMS_BOOST_BIMAP_MAP_VIEW_EXTRA_TYPEDEF
#undef STREAMS_BOOST_BIMAP_MAP_VIEW_EXTRA_TYPEDEFS_BODY
/*===========================================================================*/

} // namespace bimaps
} // namespace streams_boost

#endif // STREAMS_BOOST_BIMAP_VIEWS_VECTOR_MAP_VIEW_HPP

