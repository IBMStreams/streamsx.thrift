// Boost.Bimap
//
// Copyright (c) 2006-2007 Matias Capeletto
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

/// \file relation/detail/metadata_access_builder.hpp
/// \brief Define macros to help building metafunctions

#ifndef STREAMS_BOOST_BIMAP_RELATION_DETAIL_METADATA_ACCESS_BUILDER_HPP
#define STREAMS_BOOST_BIMAP_RELATION_DETAIL_METADATA_ACCESS_BUILDER_HPP

#if defined(_MSC_VER) && (_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/config.hpp>

#include <streams_boost/bimap/relation/support/is_tag_of_member_at.hpp>
#include <streams_boost/bimap/detail/debug/static_error.hpp>
#include <streams_boost/utility/enable_if.hpp>
#include <streams_boost/preprocessor/cat.hpp>



/******************************************************************************
              BIMAP SYMMETRIC METADATA ACCESS INTERFACE
*******************************************************************************

template< class Tag, class SymmetricType >
struct NAME
{
    typedef -unspecified- type;
};

******************************************************************************/


/*===========================================================================*/
#define STREAMS_BOOST_BIMAP_SYMMETRIC_METADATA_ACCESS_BUILDER(                        \
                                                                              \
        NAME,                                                                 \
        METADATA_BY_LEFT,                                                     \
        METADATA_BY_RIGHT                                                     \
    )                                                                         \
                                                                              \
    template                                                                  \
    <                                                                         \
        class Tag,                                                            \
        class SymmetricType,                                                  \
        class Enable = void                                                   \
    >                                                                         \
    struct NAME                                                               \
    {                                                                         \
        STREAMS_BOOST_BIMAP_STATIC_ERROR(                                             \
            STREAMS_BOOST_PP_CAT(NAME,_FAILURE),                                      \
            (SymmetricType,Tag)                                               \
        );                                                                    \
    };                                                                        \
                                                                              \
    template< class Tag, class SymmetricType >                                \
    struct NAME                                                               \
    <                                                                         \
        Tag, SymmetricType,                                                   \
        STREAMS_BOOST_DEDUCED_TYPENAME enable_if                                      \
        <                                                                     \
            ::streams_boost::bimaps::relation::support::is_tag_of_member_at_left      \
            <                                                                 \
                Tag,                                                          \
                SymmetricType                                                 \
            >                                                                 \
                                                                              \
        >::type                                                               \
    >                                                                         \
    {                                                                         \
        typedef STREAMS_BOOST_DEDUCED_TYPENAME SymmetricType::METADATA_BY_LEFT type;  \
    };                                                                        \
                                                                              \
    template< class Tag, class SymmetricType >                                \
    struct NAME                                                               \
    <                                                                         \
        Tag, SymmetricType,                                                   \
        STREAMS_BOOST_DEDUCED_TYPENAME enable_if                                      \
        <                                                                     \
            ::streams_boost::bimaps::relation::support::is_tag_of_member_at_right     \
            <                                                                 \
                Tag,                                                          \
                SymmetricType                                                 \
            >                                                                 \
                                                                              \
        >::type                                                               \
    >                                                                         \
    {                                                                         \
        typedef STREAMS_BOOST_DEDUCED_TYPENAME SymmetricType::METADATA_BY_RIGHT type; \
    };
/*===========================================================================*/


#endif // STREAMS_BOOST_BIMAP_RELATION_DETAIL_METADATA_ACCES_BUILDER_HPP


