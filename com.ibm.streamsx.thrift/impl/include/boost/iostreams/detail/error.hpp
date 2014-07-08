// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2003-2007 Jonathan Turkanis
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt.)

// See http://www.streams_boost.org/libs/iostreams for documentation.

#ifndef STREAMS_BOOST_IOSTREAMS_DETAIL_ERROR_HPP_INCLUDED
#define STREAMS_BOOST_IOSTREAMS_DETAIL_ERROR_HPP_INCLUDED

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif              
                 
#include <streams_boost/iostreams/detail/ios.hpp>  // failure.

namespace streams_boost { namespace iostreams { namespace detail {

inline STREAMS_BOOST_IOSTREAMS_FAILURE cant_read() 
{ return STREAMS_BOOST_IOSTREAMS_FAILURE("no read access"); }

inline STREAMS_BOOST_IOSTREAMS_FAILURE cant_write() 
{ return STREAMS_BOOST_IOSTREAMS_FAILURE("no write access"); }

inline STREAMS_BOOST_IOSTREAMS_FAILURE cant_seek() 
{ return STREAMS_BOOST_IOSTREAMS_FAILURE("no random access"); }

inline STREAMS_BOOST_IOSTREAMS_FAILURE bad_read() 
{ return STREAMS_BOOST_IOSTREAMS_FAILURE("bad read"); }

inline STREAMS_BOOST_IOSTREAMS_FAILURE bad_putback() 
{ return STREAMS_BOOST_IOSTREAMS_FAILURE("putback buffer full"); }

inline STREAMS_BOOST_IOSTREAMS_FAILURE bad_write() 
{ return STREAMS_BOOST_IOSTREAMS_FAILURE("bad write"); }

inline STREAMS_BOOST_IOSTREAMS_FAILURE write_area_exhausted() 
{ return STREAMS_BOOST_IOSTREAMS_FAILURE("write area exhausted"); }

inline STREAMS_BOOST_IOSTREAMS_FAILURE bad_seek() 
{ return STREAMS_BOOST_IOSTREAMS_FAILURE("bad seek"); }

} } } // End namespaces detail, iostreams, streams_boost.

#endif // #ifndef STREAMS_BOOST_IOSTREAMS_DETAIL_ERROR_HPP_INCLUDED
