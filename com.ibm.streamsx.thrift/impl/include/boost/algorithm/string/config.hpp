//  Boost string_algo library config.hpp header file  ---------------------------//

//  Copyright Pavol Droba 2002-2003.
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org/ for updates, documentation, and revision history.

#ifndef STREAMS_BOOST_STRING_CONFIG_HPP
#define STREAMS_BOOST_STRING_CONFIG_HPP

#include <streams_boost/config.hpp>
#include <streams_boost/detail/workaround.hpp>

#ifdef STREAMS_BOOST_STRING_DEDUCED_TYPENAME
#   error "macro already defined!"
#endif

#define STREAMS_BOOST_STRING_TYPENAME STREAMS_BOOST_DEDUCED_TYPENAME

// Metrowerks workaround
#if STREAMS_BOOST_WORKAROUND(__MWERKS__, <= 0x3003) // 8.x
#pragma parse_func_templ off
#endif

#endif  // STREAMS_BOOST_STRING_CONFIG_HPP
