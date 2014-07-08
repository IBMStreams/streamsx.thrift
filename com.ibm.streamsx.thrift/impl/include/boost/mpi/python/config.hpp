// Copyright (C) 2006 Douglas Gregor <doug.gregor -at- gmail.com>

// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

/** @file config.hpp
 *
 *  This header provides auto-linking and configuration support for the 
 *  Boost.MPI python bindings.
 */
#ifndef STREAMS_BOOST_MPI_PYTHON_CONFIG_HPP
#define STREAMS_BOOST_MPI_PYTHON_CONFIG_HPP

#include <streams_boost/mpi/config.hpp>

/*****************************************************************************
 *                                                                           *
 *  DLL import/export options                                                *  
 *                                                                           *
 *****************************************************************************/

#if defined(STREAMS_BOOST_HAS_DECLSPEC) && (defined(STREAMS_BOOST_MPI_PYTHON_DYN_LINK) || defined(STREAMS_BOOST_ALL_DYN_LINK)) && !defined(STREAMS_BOOST_MPI_PYTHON_STATIC_LINK)
#  if defined(STREAMS_BOOST_MPI_PYTHON_SOURCE)
#     define STREAMS_BOOST_MPI_PYTHON_DECL __declspec(dllexport)
#     define STREAMS_BOOST_MPI_PYTHON_BUILD_DLL
#  else
#     define STREAMS_BOOST_MPI_PYTHON_DECL __declspec(dllimport)
#  endif
#endif

#ifndef STREAMS_BOOST_MPI_PYTHON_DECL
#  define STREAMS_BOOST_MPI_PYTHON_DECL
#endif

#if !defined(STREAMS_BOOST_MPI_PYTHON_NO_LIB) && !defined(STREAMS_BOOST_MPI_PYTHON_SOURCE) && !defined(STREAMS_BOOST_ALL_NO_LIB)
#  define STREAMS_BOOST_LIB_NAME streams_boost_mpi_python
#  if defined(STREAMS_BOOST_MPI_PYTHON_DYN_LINK) || defined(STREAMS_BOOST_ALL_DYN_LINK)
#     define STREAMS_BOOST_DYN_LINK
#  endif
#  ifdef STREAMS_BOOST_MPI_PYTHON_DIAG
#     define STREAMS_BOOST_LIB_DIAGNOSTIC
#  endif
#  include <streams_boost/config/auto_link.hpp>
#endif

#endif // STREAMS_BOOST_MPI_PYTHON_CONFIG_HPP
