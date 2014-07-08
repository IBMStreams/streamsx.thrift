//-----------------------------------------------------------------------------
// streams_boost variant/detail/config.hpp header file
// See http://www.streams_boost.org for updates, documentation, and revision history.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2003
// Eric Friedman
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_VARIANT_DETAIL_CONFIG_HPP
#define STREAMS_BOOST_VARIANT_DETAIL_CONFIG_HPP

#include "streams_boost/config.hpp"
#include "streams_boost/detail/workaround.hpp"

///////////////////////////////////////////////////////////////////////////////
// macro STREAMS_BOOST_VARIANT_AUX_BROKEN_CONSTRUCTOR_TEMPLATE_ORDERING
//
#if STREAMS_BOOST_WORKAROUND(__MWERKS__, <= 0x3201) \
 || STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_INTEL, <= 700) \
 || STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, <= 1300) \
 && !defined(STREAMS_BOOST_VARIANT_AUX_BROKEN_CONSTRUCTOR_TEMPLATE_ORDERING)
#   define STREAMS_BOOST_VARIANT_AUX_BROKEN_CONSTRUCTOR_TEMPLATE_ORDERING
#endif

///////////////////////////////////////////////////////////////////////////////
// macro STREAMS_BOOST_VARIANT_AUX_HAS_CONSTRUCTOR_TEMPLATE_ORDERING_SFINAE_WKND
//
#if !defined(STREAMS_BOOST_NO_SFINAE) \
 && !STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_INTEL, <= 700) \
 && !defined(STREAMS_BOOST_VARIANT_AUX_HAS_CONSTRUCTOR_TEMPLATE_ORDERING_SFINAE_WKND)
#   define STREAMS_BOOST_VARIANT_AUX_HAS_CONSTRUCTOR_TEMPLATE_ORDERING_SFINAE_WKND
#endif

#endif // STREAMS_BOOST_VARIANT_DETAIL_CONFIG_HPP
