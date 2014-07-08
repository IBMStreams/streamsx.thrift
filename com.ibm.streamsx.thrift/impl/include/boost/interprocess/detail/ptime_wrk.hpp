//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2006. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/interprocess for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef STREAMS_BOOST_INTERPROCESS_PTIME_WRK_HPP
#define STREAMS_BOOST_INTERPROCESS_PTIME_WRK_HPP

//workaround to avoid winsock redefines when using date-time

#ifdef _WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN 
#define STREAMS_BOOST_INTERPROCESS_WIN32_LEAN_AND_MEAN
#endif   //#ifndef WIN32_LEAN_AND_MEAN
#endif   //#ifdef _WIN32

#include <streams_boost/date_time/posix_time/ptime.hpp>

#ifdef _WIN32
#ifdef STREAMS_BOOST_INTERPROCESS_WIN32_LEAN_AND_MEAN
#undef WIN32_LEAN_AND_MEAN
#undef STREAMS_BOOST_INTERPROCESS_WIN32_LEAN_AND_MEAN
#endif   //#ifdef STREAMS_BOOST_INTERPROCESS_WIN32_LEAN_AND_MEAN
#endif   //#ifdef _WIN32

#endif   //#ifndef STREAMS_BOOST_INTERPROCESS_PTIME_WRK_HPP

