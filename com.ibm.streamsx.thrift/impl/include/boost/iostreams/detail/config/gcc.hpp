// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2003-2007 Jonathan Turkanis
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt.)

// See http://www.streams_boost.org/libs/iostreams for documentation.

// Adapted from <streams_boost/config/auto_link.hpp> and from
// http://www.streams_boost.org/more/separate_compilation.html, by John Maddock.

#ifndef STREAMS_BOOST_IOSTREAMS_DETAIL_CONFIG_GCC_HPP_INCLUDED
#define STREAMS_BOOST_IOSTREAMS_DETAIL_CONFIG_GCC_HPP_INCLUDED

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif              

#include <streams_boost/config.hpp> // STREAMS_BOOST_INTEL.

#if defined(__GNUC__) && !defined(STREAMS_BOOST_INTEL)
# define STREAMS_BOOST_IOSTREAMS_GCC (__GNUC__ * 100 + __GNUC_MINOR__)
#endif

#endif // #ifndef STREAMS_BOOST_IOSTREAMS_DETAIL_CONFIG_GCC_HPP_INCLUDED
