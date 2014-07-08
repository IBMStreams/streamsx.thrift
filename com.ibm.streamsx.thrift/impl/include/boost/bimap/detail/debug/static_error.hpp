// Boost.Bimap
//
// Copyright (c) 2006-2007 Matias Capeletto
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

/// \file detail/debug/static_error.hpp
/// \brief Formatted compile time error

#ifndef STREAMS_BOOST_BIMAP_DETAIL_DEBUG_STATIC_ERROR_HPP
#define STREAMS_BOOST_BIMAP_DETAIL_DEBUG_STATIC_ERROR_HPP

#if defined(_MSC_VER) && (_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/config.hpp>

#include <streams_boost/mpl/assert.hpp>
#include <streams_boost/preprocessor/cat.hpp>

// Easier way to call STREAMS_BOOST_MPL_ASSERT_MSG in class scope to generate
// a static error.
/*===========================================================================*/
#define STREAMS_BOOST_BIMAP_STATIC_ERROR(MESSAGE,VARIABLES)                           \
        struct STREAMS_BOOST_PP_CAT(BIMAP_STATIC_ERROR__,MESSAGE) {};                 \
        STREAMS_BOOST_MPL_ASSERT_MSG(false,                                           \
                             STREAMS_BOOST_PP_CAT(BIMAP_STATIC_ERROR__,MESSAGE),      \
                             VARIABLES)
/*===========================================================================*/



#endif // STREAMS_BOOST_BIMAP_DETAIL_DEBUG_STATIC_ERROR_HPP
