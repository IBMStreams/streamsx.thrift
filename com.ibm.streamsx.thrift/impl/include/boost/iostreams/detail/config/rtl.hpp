/*
 * Distributed under the Boost Software License, Version 1.0.(See accompanying 
 * file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt.)
 * 
 * See http://www.streams_boost.org/libs/iostreams for documentation.
 *
 * Defines preprocessor symbols expanding to the names of functions in the 
 * C runtime library used to access file descriptors and to the type used
 * to store file offsets for seeking.
 * 
 * File:        streams_boost/iostreams/detail/config/rtl.hpp
 * Date:        Wed Dec 26 11:58:11 MST 2007
 * 
 * Copyright:   2007-2008 CodeRage, LLC
 * Author:      Jonathan Turkanis
 * Contact:     turkanis at coderage dot com
 */

#ifndef STREAMS_BOOST_IOSTREAMS_DETAIL_CONFIG_RTL_HPP_INCLUDED
#define STREAMS_BOOST_IOSTREAMS_DETAIL_CONFIG_RTL_HPP_INCLUDED

#include <streams_boost/config.hpp>
#include <streams_boost/iostreams/detail/config/windows_posix.hpp>

// Handle open, close, read, and write
#ifdef __BORLANDC__
# define STREAMS_BOOST_IOSTREAMS_RTL(x) STREAMS_BOOST_JOIN(_rtl_, x)
#elif defined STREAMS_BOOST_IOSTREAMS_WINDOWS
# define STREAMS_BOOST_IOSTREAMS_RTL(x) STREAMS_BOOST_JOIN(_, x)
#else
# define STREAMS_BOOST_IOSTREAMS_RTL(x) ::x  // Distinguish from member function named x
#endif
#define STREAMS_BOOST_IOSTREAMS_FD_OPEN   STREAMS_BOOST_IOSTREAMS_RTL(open)
#define STREAMS_BOOST_IOSTREAMS_FD_CLOSE  STREAMS_BOOST_IOSTREAMS_RTL(close)
#define STREAMS_BOOST_IOSTREAMS_FD_READ   STREAMS_BOOST_IOSTREAMS_RTL(read)
#define STREAMS_BOOST_IOSTREAMS_FD_WRITE  STREAMS_BOOST_IOSTREAMS_RTL(write)

// Handle lseek, off_t, ftruncate, and stat
#ifdef STREAMS_BOOST_IOSTREAMS_WINDOWS
# if defined(STREAMS_BOOST_MSVC) || defined(__MSVCRT__) // MSVC, MinGW
#  define STREAMS_BOOST_IOSTREAMS_FD_SEEK    _lseeki64
#  define STREAMS_BOOST_IOSTREAMS_FD_OFFSET  __int64
# else                                          // Borland, Metrowerks, ...
#  define STREAMS_BOOST_IOSTREAMS_FD_SEEK    lseek  
#  define STREAMS_BOOST_IOSTREAMS_FD_OFFSET  long
# endif
#else // Non-windows
# if defined(_LARGEFILE64_SOURCE) && \
         (!defined(_FILE_OFFSET_BITS) || _FILE_OFFSET_BITS != 64) || \
     defined(_AIX) && !defined(_LARGE_FILES) || \
     defined(STREAMS_BOOST_IOSTREAMS_HAS_LARGE_FILE_EXTENSIONS)
     /**/

    /* Systems with transitional extensions for large file support */

#  define STREAMS_BOOST_IOSTREAMS_FD_SEEK      lseek64
#  define STREAMS_BOOST_IOSTREAMS_FD_TRUNCATE  ftruncate64
#  define STREAMS_BOOST_IOSTREAMS_FD_MMAP      mmap64
#  define STREAMS_BOOST_IOSTREAMS_FD_STAT      stat64
#  define STREAMS_BOOST_IOSTREAMS_FD_FSTAT     fstat64
#  define STREAMS_BOOST_IOSTREAMS_FD_OFFSET    off64_t
# else
#  define STREAMS_BOOST_IOSTREAMS_FD_SEEK      lseek
#  define STREAMS_BOOST_IOSTREAMS_FD_TRUNCATE  ftruncate
#  define STREAMS_BOOST_IOSTREAMS_FD_MMAP      mmap
#  define STREAMS_BOOST_IOSTREAMS_FD_STAT      stat
#  define STREAMS_BOOST_IOSTREAMS_FD_FSTAT     fstat
#  define STREAMS_BOOST_IOSTREAMS_FD_OFFSET    off_t
# endif
#endif

#endif // #ifndef STREAMS_BOOST_IOSTREAMS_DETAIL_CONFIG_RTL_HPP_INCLUDED
