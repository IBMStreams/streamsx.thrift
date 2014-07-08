// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2004-2007 Jonathan Turkanis
// (C) Copyright 2002, 2003 Beman Dawes   Boost.Filesystem
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt.)

// See http://www.streams_boost.org/libs/iostreams for documentation.

#ifndef STREAMS_BOOST_IOSTREAMS_DETAIL_CONFIG_WINDOWS_POSIX_STREAMS_HPP_INCLUDED
#define STREAMS_BOOST_IOSTREAMS_DETAIL_CONFIG_WINDOWS_POSIX_STREAMS_HPP_INCLUDED

//------------------From streams_boost/libs/filesystem/src/path_posix_windows.cpp-----//

// STREAMS_BOOST_IOSTREAMS_POSIX or STREAMS_BOOST_IOSTREAMS_WINDOWS specify which API to use.
#if !defined( STREAMS_BOOST_IOSTREAMS_WINDOWS ) && !defined( STREAMS_BOOST_IOSTREAMS_POSIX )
# if (defined(_WIN32) || defined(__WIN32__) || defined(WIN32)) && \
     !defined(__CYGWIN__) \
     /**/
#  define STREAMS_BOOST_IOSTREAMS_WINDOWS
# else
#  define STREAMS_BOOST_IOSTREAMS_POSIX
# endif
#endif

#endif // #ifndef STREAMS_BOOST_IOSTREAMS_DETAIL_CONFIG_WINDOWS_POSIX_STREAMS_HPP_INCLUDED
