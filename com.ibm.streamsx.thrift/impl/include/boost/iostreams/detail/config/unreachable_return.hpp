// (C) Copyright 2010 Daniel James
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt.)

// See http://www.streams_boost.org/libs/iostreams for documentation.

#ifndef STREAMS_BOOST_IOSTREAMS_DETAIL_UNREACHABLE_RETURN_HPP_INCLUDED
#define STREAMS_BOOST_IOSTREAMS_DETAIL_UNREACHABLE_RETURN_HPP_INCLUDED

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif              

#include <streams_boost/config.hpp>

// If Boost.Exception has STREAMS_BOOST_ATTRIBUTE_NORETURN
#if defined(_MSC_VER) || defined(__GNUC__)
#define STREAMS_BOOST_IOSTREAMS_UNREACHABLE_RETURN(x) \
    STREAMS_BOOST_UNREACHABLE_RETURN(x)
#else
#define STREAMS_BOOST_IOSTREAMS_UNREACHABLE_RETURN(x) \
    return x;
#endif

#endif
