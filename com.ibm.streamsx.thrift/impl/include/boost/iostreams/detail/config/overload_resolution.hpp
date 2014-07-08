// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2003-2007 Jonathan Turkanis
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt.)

// See http://www.streams_boost.org/libs/iostreams for documentation.

// Adapted from <streams_boost/config/auto_link.hpp> and from
// http://www.streams_boost.org/more/separate_compilation.html, by John Maddock.

#ifndef STREAMS_BOOST_IOSTREAMS_DETAIL_CONFIG_BROKEN_OVERLOAD_RESOLUTION_HPP_INCLUDED
#define STREAMS_BOOST_IOSTREAMS_DETAIL_CONFIG_BROKEN_OVERLOAD_RESOLUTION_HPP_INCLUDED

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif             

#include <streams_boost/config.hpp> // STREAMS_BOOST_MSVC.
#include <streams_boost/detail/workaround.hpp>
#include <streams_boost/iostreams/detail/config/gcc.hpp>

#if !defined(STREAMS_BOOST_IOSTREAMS_BROKEN_OVERLOAD_RESOLUTION)
# if STREAMS_BOOST_WORKAROUND(__MWERKS__, <= 0x3003) || \
     STREAMS_BOOST_WORKAROUND(__BORLANDC__, < 0x600) || \
     STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, <= 1300) || \
     STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_IOSTREAMS_GCC, <= 295) \
     /**/
#  define STREAMS_BOOST_IOSTREAMS_BROKEN_OVERLOAD_RESOLUTION
# endif
#endif

#endif // #ifndef STREAMS_BOOST_IOSTREAMS_DETAIL_CONFIG_BROKEN_OVERLOAD_RESOLUTION_HPP_INCLUDED
