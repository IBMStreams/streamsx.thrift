// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2003-2007 Jonathan Turkanis
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt.)

// See http://www.streams_boost.org/libs/iostreams for documentation.

// Adapted from http://www.streams_boost.org/more/separate_compilation.html, by
// John Maddock.

#ifndef STREAMS_BOOST_IOSTREAMS_DETAIL_CONFIG_WIDE_STREAMS_HPP_INCLUDED
#define STREAMS_BOOST_IOSTREAMS_DETAIL_CONFIG_WIDE_STREAMS_HPP_INCLUDED

#include <streams_boost/config.hpp>
#include <streams_boost/detail/workaround.hpp>
#include <cstddef>

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif       

//------------------Templated stream support----------------------------------//

// From streams_boost/dynamic_bitset.hpp; thanks to Matthias Troyer for cray patch.
#ifndef STREAMS_BOOST_IOSTREAMS_NO_STREAM_TEMPLATES
# if defined(__STL_CONFIG_H) && \
    !defined (__STL_USE_NEW_IOSTREAMS) && !defined(__crayx1) \
    /**/
#  define STREAMS_BOOST_IOSTREAMS_NO_STREAM_TEMPLATES
# endif
#endif // #ifndef STREAMS_BOOST_IOSTREAMS_NO_STREAM_TEMPLATES

//------------------Wide stream support---------------------------------------//

#ifndef STREAMS_BOOST_IOSTREAMS_NO_WIDE_STREAMS
# if defined(STREAMS_BOOST_IOSTREAMS_NO_STREAM_TEMPLATES) || \
     defined (STREAMS_BOOST_NO_STD_WSTREAMBUF) && \
     ( !defined(__MSL_CPP__) || defined(_MSL_NO_WCHART_CPP_SUPPORT) ) \
     /**/
#  define STREAMS_BOOST_IOSTREAMS_NO_WIDE_STREAMS
# endif
#endif // #ifndef STREAMS_BOOST_IOSTREAMS_NO_WIDE_STREAMS   

//------------------Locale support--------------------------------------------//

#ifndef STREAMS_BOOST_IOSTREAMS_NO_LOCALE
# if defined(STREAMS_BOOST_NO_STD_LOCALE) || \
     defined(__CYGWIN__) && \
     ( !defined(__MSL_CPP__) || defined(_MSL_NO_WCHART_CPP_SUPPORT) ) \
     /**/
#  define STREAMS_BOOST_IOSTREAMS_NO_LOCALE
# endif
#endif // #ifndef STREAMS_BOOST_IOSTREAMS_NO_LOCALE

#endif // #ifndef STREAMS_BOOST_IOSTREAMS_DETAIL_CONFIG_WIDE_STREAMS_HPP_INCLUDED
