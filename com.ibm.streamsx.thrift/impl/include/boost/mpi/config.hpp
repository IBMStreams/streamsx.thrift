// Copyright (C) 2006 Douglas Gregor <doug.gregor -at- gmail.com>

// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

/** @file config.hpp
 *
 *  This header provides MPI configuration details that expose the
 *  capabilities of the underlying MPI implementation, and provides
 *  auto-linking support on Windows.
 */
#ifndef STREAMS_BOOST_MPI_CONFIG_HPP
#define STREAMS_BOOST_MPI_CONFIG_HPP

/* Force MPICH not to define SEEK_SET, SEEK_CUR, and SEEK_END, which
   conflict with the versions in <stdio.h> and <cstdio>. */
#define MPICH_IGNORE_CXX_SEEK 1

#include <mpi.h>
#include <streams_boost/config.hpp>

/** @brief Define this macro to avoid expensice MPI_Pack/Unpack calls on 
 *  homogeneous machines.
*/
//#define STREAMS_BOOST_MPI_HOMOGENEOUS

// If this is an MPI-2 implementation, define configuration macros for
// the features we are interested in.
#if defined(MPI_VERSION) && MPI_VERSION == 2
/** @brief Determine if the MPI implementation has support for memory
 *  allocation.
 *
 *  This macro will be defined when the underlying MPI implementation
 *  has support for the MPI-2 memory allocation routines @c
 *  MPI_Alloc_mem and @c MPI_Free_mem. When defined, the @c allocator
 *  class template will provide Standard Library-compliant access to
 *  these memory-allocation routines.
 */
#  define STREAMS_BOOST_MPI_HAS_MEMORY_ALLOCATION

/** @brief Determine if the MPI implementation has supports initialization 
 *  without command-line arguments.
 *
 *  This macro will be defined when the underlying implementation
 *  supports initialization of MPI without passing along command-line
 *  arguments, e.g., @c MPI_Init(NULL, NULL). When defined, the @c
 *  environment class will provide a default constructor. This macro is 
 *  always defined for MPI-2 implementations. */
#  define STREAMS_BOOST_MPI_HAS_NOARG_INITIALIZATION
#endif

#if defined(MPIAPI)
#  define STREAMS_BOOST_MPI_CALLING_CONVENTION MPIAPI
#else
/** @brief Specifies the calling convention that will be used for callbacks
 *  from the underlying C MPI. 
 *
 *  This is a Windows-specific macro, which will be used internally to state
 *  the calling convention of any function that is to be used as a callback
 *  from MPI. For example, the internally-defined functions that are used in
 *  a call to @c MPI_Op_create. This macro is likely only to be useful to
 *  users that wish to bypass Boost.MPI, registering their own callbacks in
 *  certain cases, e.g., through @c MPI_Op_create.
 */
#  define STREAMS_BOOST_MPI_CALLING_CONVENTION
#endif

#if defined(LAM_MPI)
// Configuration for LAM/MPI
#  define STREAMS_BOOST_MPI_HAS_MEMORY_ALLOCATION
#  define STREAMS_BOOST_MPI_HAS_NOARG_INITIALIZATION
#elif defined(MPICH_NAME)
// Configuration for MPICH
#endif

/*****************************************************************************
 *                                                                           *
 *  DLL import/export options                                                *  
 *                                                                           *
 *****************************************************************************/

#if defined(STREAMS_BOOST_HAS_DECLSPEC) && (defined(STREAMS_BOOST_MPI_DYN_LINK) || defined(STREAMS_BOOST_ALL_DYN_LINK)) && !defined(STREAMS_BOOST_MPI_STATIC_LINK)
#  if defined(STREAMS_BOOST_MPI_SOURCE)
#     define STREAMS_BOOST_MPI_DECL __declspec(dllexport)
#     define STREAMS_BOOST_MPI_BUILD_DLL
#  else
#     define STREAMS_BOOST_MPI_DECL __declspec(dllimport)
#  endif
#endif

#ifndef STREAMS_BOOST_MPI_DECL
#  define STREAMS_BOOST_MPI_DECL
#endif

#if !defined(STREAMS_BOOST_MPI_NO_LIB) && !defined(STREAMS_BOOST_MPI_SOURCE) && !defined(STREAMS_BOOST_ALL_NO_LIB) && defined(__cplusplus)
#  define STREAMS_BOOST_LIB_NAME streams_boost_mpi
#  if defined(STREAMS_BOOST_MPI_DYN_LINK) || defined(STREAMS_BOOST_ALL_DYN_LINK)
#     define STREAMS_BOOST_DYN_LINK
#  endif
#  ifdef STREAMS_BOOST_MPI_DIAG
#     define STREAMS_BOOST_LIB_DIAGNOSTIC
#  endif
#  include <streams_boost/config/auto_link.hpp>
#endif

#endif // STREAMS_BOOST_MPI_CONFIG_HPP
