//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2005-2009. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/interprocess for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef STREAMS_BOOST_INTERPROCESS_DETAIL_PTIME_TO_TIMESPEC_HPP
#define STREAMS_BOOST_INTERPROCESS_DETAIL_PTIME_TO_TIMESPEC_HPP

#include <streams_boost/interprocess/detail/posix_time_types_wrk.hpp>

namespace streams_boost {

namespace interprocess {

namespace detail {

inline timespec ptime_to_timespec (const streams_boost::posix_time::ptime &tm)
{
   const streams_boost::posix_time::ptime epoch(streams_boost::gregorian::date(1970,1,1));
   streams_boost::posix_time::time_duration duration (tm - epoch);
   timespec ts;
   ts.tv_sec  = duration.total_seconds();
   ts.tv_nsec = duration.total_nanoseconds() % 1000000000;
   return ts;
}

}  //namespace detail {

}  //namespace interprocess {

}  //namespace streams_boost {

#endif   //ifndef STREAMS_BOOST_INTERPROCESS_DETAIL_PTIME_TO_TIMESPEC_HPP
