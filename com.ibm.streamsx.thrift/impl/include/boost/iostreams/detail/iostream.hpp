// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2003-2007 Jonathan Turkanis
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt.)

// See http://www.streams_boost.org/libs/iostreams for documentation.

#ifndef STREAMS_BOOST_IOSTREAMS_DETAIL_IOSTREAM_HPP_INCLUDED
#define STREAMS_BOOST_IOSTREAMS_DETAIL_IOSTREAM_HPP_INCLUDED

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif              
                 
#include <streams_boost/iostreams/detail/config/wide_streams.hpp>
#ifndef STREAMS_BOOST_IOSTREAMS_NO_STREAM_TEMPLATES
# include <istream>
# include <ostream>
#else
# include <iostream.h>
#endif

#ifndef STREAMS_BOOST_IOSTREAMS_NO_STREAM_TEMPLATES
# define STREAMS_BOOST_IOSTREAMS_BASIC_ISTREAM(ch, tr) std::basic_istream< ch, tr >
# define STREAMS_BOOST_IOSTREAMS_BASIC_OSTREAM(ch, tr) std::basic_ostream< ch, tr >
# define STREAMS_BOOST_IOSTREAMS_BASIC_IOSTREAM(ch, tr) std::basic_iostream< ch, tr >
#else
# define STREAMS_BOOST_IOSTREAMS_BASIC_STREAMBUF(ch, tr) std::streambuf
# define STREAMS_BOOST_IOSTREAMS_BASIC_ISTREAM(ch, tr) std::istream
# define STREAMS_BOOST_IOSTREAMS_BASIC_OSTREAM(ch, tr) std::ostream
# define STREAMS_BOOST_IOSTREAMS_BASIC_IOSTREAM(ch, tr) std::iostream
#endif

#endif // #ifndef STREAMS_BOOST_IOSTREAMS_DETAIL_IOSTREAM_HPP_INCLUDED
