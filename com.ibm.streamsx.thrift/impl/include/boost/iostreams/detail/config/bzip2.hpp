// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2003-2007 Jonathan Turkanis
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt.)

// See http://www.streams_boost.org/libs/iostreams for documentation.

// Adapted from <streams_boost/config/auto_link.hpp> and from
// http://www.streams_boost.org/more/separate_compilation.html, by John Maddock.

#ifndef STREAMS_BOOST_IOSTREAMS_DETAIL_CONFIG_BZIP2_HPP_INCLUDED
#define STREAMS_BOOST_IOSTREAMS_DETAIL_CONFIG_BZIP2_HPP_INCLUDED

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif              

#if defined(STREAMS_BOOST_BZIP2_BINARY)
# if defined(STREAMS_BOOST_MSVC) || \
     defined(__BORLANDC__) || \
     (defined(__MWERKS__) && defined(_WIN32) && (__MWERKS__ >= 0x3000)) || \
     (defined(__ICL) && defined(_MSC_EXTENSIONS) && (_MSC_VER >= 1200)) \
     /**/

// Specify the name of the .lib file.
#  pragma comment(lib, STREAMS_BOOST_STRINGIZE(STREAMS_BOOST_BZIP2_BINARY))
# endif
#else 
# if !defined(STREAMS_BOOST_IOSTREAMS_SOURCE) && \
     !defined(STREAMS_BOOST_ALL_NO_LIB) && \
     !defined(STREAMS_BOOST_IOSTREAMS_NO_LIB) \
     /**/

// Set the name of our library, this will get undef'ed by auto_link.hpp
// once it's done with it.
#  define STREAMS_BOOST_LIB_NAME streams_boost_bzip2

// If we're importing code from a dll, then tell auto_link.hpp about it.
#  if defined(STREAMS_BOOST_ALL_DYN_LINK) || defined(STREAMS_BOOST_IOSTREAMS_DYN_LINK)
#   define STREAMS_BOOST_DYN_LINK
#  endif

// And include the header that does the work.
#  include <streams_boost/config/auto_link.hpp>
# endif
#endif

#endif // #ifndef STREAMS_BOOST_IOSTREAMS_DETAIL_CONFIG_BZIP2_HPP_INCLUDED
