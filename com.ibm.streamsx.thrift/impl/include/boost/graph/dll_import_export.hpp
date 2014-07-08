//=======================================================================
// Copyright 2001 University of Notre Dame.
// Copyright 2003 Jeremy Siek
// Authors: Lie-Quan Lee, Jeremy Siek, and Douglas Gregor
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
//=======================================================================

#ifndef STREAMS_BOOST_GRAPH_DLL_IMPORT_EXPORT_HPP
#define STREAMS_BOOST_GRAPH_DLL_IMPORT_EXPORT_HPP

#include <streams_boost/config.hpp>

#ifdef STREAMS_BOOST_HAS_DECLSPEC
#  if defined(STREAMS_BOOST_ALL_DYN_LINK) || defined(STREAMS_BOOST_GRAPH_DYN_LINK)
#    ifdef STREAMS_BOOST_GRAPH_SOURCE
#      define STREAMS_BOOST_GRAPH_DECL __declspec(dllexport)
#    else
#      define STREAMS_BOOST_GRAPH_DECL __declspec(dllimport)
#    endif  // STREAMS_BOOST_GRAPH_SOURCE
#  endif  // DYN_LINK
#endif  // STREAMS_BOOST_HAS_DECLSPEC

#ifndef STREAMS_BOOST_GRAPH_DECL
#  define STREAMS_BOOST_GRAPH_DECL
#endif

#endif // STREAMS_BOOST_GRAPH_DLL_IMPORT_EXPORT_HPP
