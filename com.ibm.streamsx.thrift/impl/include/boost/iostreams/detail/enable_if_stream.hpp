// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2003-2007 Jonathan Turkanis
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt.)

// See http://www.streams_boost.org/libs/iostreams for documentation.

#ifndef STREAMS_BOOST_IOSTREAMS_DETAIL_ENABLE_IF_STREAM_HPP_INCLUDED
#define STREAMS_BOOST_IOSTREAMS_DETAIL_ENABLE_IF_STREAM_HPP_INCLUDED

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif              

#include <streams_boost/config.hpp>                // STREAMS_BOOST_NO_SFINAE.
#include <streams_boost/utility/enable_if.hpp>                  
#include <streams_boost/iostreams/traits_fwd.hpp>  // is_std_io.

#if !defined(STREAMS_BOOST_NO_SFINAE) && \
    !STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x592))
# define STREAMS_BOOST_IOSTREAMS_ENABLE_IF_STREAM(T) \
    , typename streams_boost::enable_if< streams_boost::iostreams::is_std_io<T> >::type* = 0 \
    /**/
# define STREAMS_BOOST_IOSTREAMS_DISABLE_IF_STREAM(T) \
    , typename streams_boost::disable_if< streams_boost::iostreams::is_std_io<T> >::type* = 0 \
    /**/
#else 
# define STREAMS_BOOST_IOSTREAMS_ENABLE_IF_STREAM(T)
# define STREAMS_BOOST_IOSTREAMS_DISABLE_IF_STREAM(T)
#endif

#endif // #ifndef STREAMS_BOOST_IOSTREAMS_DETAIL_ENABLE_IF_STREAM_HPP_INCLUDED
