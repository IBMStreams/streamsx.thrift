// Boost.Bimap
//
// Copyright (c) 2006-2007 Matias Capeletto
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

/// \file detail/user_interface_config.hpp
/// \brief General configuration directives


#ifndef STREAMS_BOOST_BIMAP_DETAIL_USER_INTERFACE_CONFIG_HPP
#define STREAMS_BOOST_BIMAP_DETAIL_USER_INTERFACE_CONFIG_HPP

#if defined(_MSC_VER) && (_MSC_VER>=1200)
#pragma once
#endif

#ifdef STREAMS_BOOST_BIMAP_DISABLE_SERIALIZATION
    #define STREAMS_BOOST_MULTI_INDEX_DISABLE_SERIALIZATION
#endif

#endif // STREAMS_BOOST_BIMAP_DETAIL_USER_INTERFACE_CONFIG_HPP
