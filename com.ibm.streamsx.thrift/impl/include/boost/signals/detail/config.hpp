/*
 *
 * Copyright (c) 1998-2002
 * John Maddock
 *
 * Copyright (c) 2003-2004
 * Douglas Gregor
 *
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.streams_boost.org/LICENSE_1_0.txt)
 *
 */

#ifndef STREAMS_BOOST_SIGNALS_CONFIG_HPP
#define STREAMS_BOOST_SIGNALS_CONFIG_HPP

#include <streams_boost/config.hpp>

#ifdef STREAMS_BOOST_HAS_DECLSPEC
#  if defined(STREAMS_BOOST_ALL_DYN_LINK) || defined(STREAMS_BOOST_SIGNALS_DYN_LINK)
#    ifdef STREAMS_BOOST_SIGNALS_SOURCE
#      define STREAMS_BOOST_SIGNALS_DECL __declspec(dllexport)
#    else
#      define STREAMS_BOOST_SIGNALS_DECL __declspec(dllimport)
#    endif  // STREAMS_BOOST_SIGNALS_SOURCE
#  endif  // DYN_LINK
#endif  // STREAMS_BOOST_HAS_DECLSPEC

#ifndef STREAMS_BOOST_SIGNALS_DECL
#  define STREAMS_BOOST_SIGNALS_DECL
#endif

// Setup autolinking
#if !defined(STREAMS_BOOST_SIGNALS_SOURCE) && !defined(STREAMS_BOOST_ALL_NO_LIB) && !defined(STREAMS_BOOST_SIGNALS_NO_LIB)
#  define STREAMS_BOOST_LIB_NAME streams_boost_signals

#  if defined(STREAMS_BOOST_ALL_DYN_LINK) || defined(STREAMS_BOOST_SIGNALS_DYN_LINK)
#    define STREAMS_BOOST_DYN_LINK
#  endif

#  include <streams_boost/config/auto_link.hpp>
#endif // autolinking on

#endif // STREAMS_BOOST_SIGNALS_CONFIG_HPP









