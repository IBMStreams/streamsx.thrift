//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2005-2009. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/interprocess for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef STREAMS_BOOST_INTERPROCESS_POSIX_TIMES_WRK_STREAMS_HPP
#define STREAMS_BOOST_INTERPROCESS_POSIX_TIMES_WRK_STREAMS_HPP

//workaround to avoid winsock redefines when using date-time

#ifdef _WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN 
#define STREAMS_BOOST_INTERPROCESS_WIN32_LEAN_AND_MEAN
#endif   //#ifndef WIN32_LEAN_AND_MEAN
#endif   //#ifdef _WIN32

//#include <streams_boost/date_time/posix_time/ptime.hpp>
//#include <streams_boost/date_time/microsec_time_clock.hpp>
#include <streams_boost/date_time/posix_time/posix_time_types.hpp>

namespace streams_boost {
namespace interprocess {

typedef streams_boost::date_time::microsec_clock<streams_boost::posix_time::ptime> microsec_clock;

}
}

#ifdef _WIN32
#ifdef STREAMS_BOOST_INTERPROCESS_WIN32_LEAN_AND_MEAN
#undef WIN32_LEAN_AND_MEAN
#undef STREAMS_BOOST_INTERPROCESS_WIN32_LEAN_AND_MEAN
#endif   //#ifdef STREAMS_BOOST_INTERPROCESS_WIN32_LEAN_AND_MEAN
#endif   //#ifdef _WIN32

#endif   //#ifndef STREAMS_BOOST_INTERPROCESS_POSIX_TIMES_WRK_STREAMS_HPP

