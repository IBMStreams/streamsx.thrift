// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2003-2007 Jonathan Turkanis
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt.)

// See http://www.streams_boost.org/libs/iostreams for documentation.

#ifndef STREAMS_BOOST_IOSTREAMS_DETAIL_FSTREAM_HPP_INCLUDED
#define STREAMS_BOOST_IOSTREAMS_DETAIL_FSTREAM_HPP_INCLUDED

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif              
                 
#include <streams_boost/iostreams/detail/config/wide_streams.hpp>
#ifndef STREAMS_BOOST_IOSTREAMS_NO_STREAM_TEMPLATES
# include <fstream>
#else
# include <fstream.h>
#endif 

#ifndef STREAMS_BOOST_IOSTREAMS_NO_STREAM_TEMPLATES
# define STREAMS_BOOST_IOSTREAMS_BASIC_IFSTREAM(Ch, Tr) std::basic_ifstream<Ch, Tr>
# define STREAMS_BOOST_IOSTREAMS_BASIC_OFSTREAM(Ch, Tr) std::basic_ofstream<Ch, Tr>
# define STREAMS_BOOST_IOSTREAMS_BASIC_FSTREAM(Ch, Tr) std::basic_fstream<Ch, Tr>
# define STREAMS_BOOST_IOSTREAMS_BASIC_FILEBUF(Ch) std::basic_filebuf<Ch>
#else 
# define STREAMS_BOOST_IOSTREAMS_BASIC_IFSTREAM(Ch, Tr) std::ifstream
# define STREAMS_BOOST_IOSTREAMS_BASIC_OFSTREAM(Ch, Tr) std::ofstream
# define STREAMS_BOOST_IOSTREAMS_BASIC_FILEBUF(Ch) std::filebuf
#endif

#endif // #ifndef STREAMS_BOOST_IOSTREAMS_DETAIL_FSTREAM_HPP_INCLUDED
