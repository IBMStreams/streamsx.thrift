// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2003-2007 Jonathan Turkanis
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt.)

// See http://www.streams_boost.org/libs/iostreams for documentation.

// Contains constants used by library.

#ifndef STREAMS_BOOST_IOSTREAMS_CONSTANTS_HPP_INCLUDED
#define STREAMS_BOOST_IOSTREAMS_CONSTANTS_HPP_INCLUDED

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif              

#ifndef STREAMS_BOOST_IOSTREAMS_DEFAULT_DEVICE_BUFFER_SIZE
# define STREAMS_BOOST_IOSTREAMS_DEFAULT_DEVICE_BUFFER_SIZE 4096
#endif

#ifndef STREAMS_BOOST_IOSTREAMS_DEFAULT_FILTER_BUFFER_SIZE
# define STREAMS_BOOST_IOSTREAMS_DEFAULT_FILTER_BUFFER_SIZE 128
#endif

#ifndef STREAMS_BOOST_IOSTREAMS_DEFAULT_PBACK_BUFFER_SIZE
# define STREAMS_BOOST_IOSTREAMS_DEFAULT_PBACK_BUFFER_SIZE 4
#endif

#include <streams_boost/iostreams/detail/ios.hpp>  // streamsize.

namespace streams_boost { namespace iostreams {

const std::streamsize default_device_buffer_size = 
    STREAMS_BOOST_IOSTREAMS_DEFAULT_DEVICE_BUFFER_SIZE; 
const std::streamsize default_filter_buffer_size = 
    STREAMS_BOOST_IOSTREAMS_DEFAULT_FILTER_BUFFER_SIZE;
const std::streamsize default_pback_buffer_size = 
    STREAMS_BOOST_IOSTREAMS_DEFAULT_PBACK_BUFFER_SIZE;

} } // End namespaces iostreams, streams_boost.

#endif // #ifndef STREAMS_BOOST_IOSTREAMS_CONSTANTS_HPP_INCLUDED
