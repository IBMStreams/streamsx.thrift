// Boost.Bimap
//
// Copyright (c) 2006-2007 Matias Capeletto
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_BIMAP_DETAIL_CHECK_METADATA_HPP
#define STREAMS_BOOST_BIMAP_DETAIL_CHECK_METADATA_HPP

#if defined(_MSC_VER) && (_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/config.hpp>

#include <streams_boost/mpl/assert.hpp>
#include <streams_boost/type_traits/is_same.hpp>
#include <streams_boost/preprocessor/cat.hpp>


// Easier way to call STREAMS_BOOST_MPL_ASSERT_MSG in class scope
/*===========================================================================*/
#define STREAMS_BOOST_BIMAP_MPL_ASSERT_MSG_ACS(p1,p2,p3)                              \
                                                                              \
    struct p2 {};                                                             \
    STREAMS_BOOST_MPL_ASSERT_MSG(p1,p2,p3);                                           \
/*===========================================================================*/


// Build a descriptive name.
/*===========================================================================*/
#define STREAMS_BOOST_BIMAP_WRONG_METADATA_MESSAGE(                                   \
                                                                              \
        P_CLASS,                                                              \
        P_NAME,                                                               \
        P_CORRECT_TYPE                                                        \
                                                                              \
    )                                                                         \
                                                                              \
    STREAMS_BOOST_PP_CAT                                                              \
    (                                                                         \
        WRONG_METADATA__,                                                     \
        STREAMS_BOOST_PP_CAT                                                          \
        (                                                                     \
            P_CLASS,                                                          \
            STREAMS_BOOST_PP_CAT                                                      \
            (                                                                 \
                __AT__,                                                       \
                STREAMS_BOOST_PP_CAT                                                  \
                (                                                             \
                    P_NAME,                                                   \
                    STREAMS_BOOST_PP_CAT                                              \
                    (                                                         \
                        __IS_DIFERENT_TO__,                                   \
                        P_CORRECT_TYPE                                        \
                    )                                                         \
                )                                                             \
            )                                                                 \
        )                                                                     \
    )
/*===========================================================================*/


// Check if the metadata have the correct type, and if not inform
// it with a useful compile time message.
/*===========================================================================*/
#define STREAMS_BOOST_BIMAP_CHECK_METADATA(                                           \
                                                                              \
        P_CLASS,                                                              \
        P_NAME,                                                               \
        P_CORRECT_TYPE                                                        \
                                                                              \
    )                                                                         \
                                                                              \
    STREAMS_BOOST_BIMAP_MPL_ASSERT_MSG_ACS                                            \
    (                                                                         \
        (                                                                     \
            ::streams_boost::is_same                                                  \
            <                                                                 \
                P_CLASS::P_NAME,                                              \
                P_CORRECT_TYPE                                                \
                                                                              \
            >::value                                                          \
        ),                                                                    \
        STREAMS_BOOST_BIMAP_WRONG_METADATA_MESSAGE                                    \
        (                                                                     \
            P_CLASS,                                                          \
            P_NAME,                                                           \
            P_CORRECT_TYPE                                                    \
        ),                                                                    \
        (P_CLASS::P_NAME,P_CORRECT_TYPE)                                      \
    )
/*===========================================================================*/


// Just for autodocumment the test code
/*===========================================================================*/
#define STREAMS_BOOST_BIMAP_TEST_STATIC_FUNCTION(NAME)                                \
    namespace NAME
/*===========================================================================*/


// Just for autodocument the test code
/*===========================================================================*/
#define STREAMS_BOOST_BIMAP_CALL_TEST_STATIC_FUNCTION(NAME)
/*===========================================================================*/



#endif // STREAMS_BOOST_BIMAP_DETAIL_CHECK_METADATA_HPP

