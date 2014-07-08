#ifndef POSIX_TIME_SYSTEM_STREAMS_HPP___
#define POSIX_TIME_SYSTEM_STREAMS_HPP___

/* Copyright (c) 2002,2003 CrystalClear Software, Inc.
 * Use, modification and distribution is subject to the 
 * Boost Software License, Version 1.0. (See accompanying
 * file LICENSE_1_0.txt or http://www.streams_boost.org/LICENSE_1_0.txt)
 * Author: Jeff Garland
 * $Date: 2008-02-27 15:00:24 -0500 (Wed, 27 Feb 2008) $
 */


#include "streams_boost/date_time/posix_time/posix_time_config.hpp"
#include "streams_boost/date_time/time_system_split.hpp"
#include "streams_boost/date_time/time_system_counted.hpp"
#include "streams_boost/date_time/compiler_config.hpp"


namespace streams_boost {
namespace posix_time { 

#ifdef STREAMS_BOOST_DATE_TIME_POSIX_TIME_STD_CONFIG

#if (defined(STREAMS_BOOST_DATE_TIME_NO_MEMBER_INIT)) //help bad compilers 
  typedef date_time::split_timedate_system<posix_time_system_config, 1000000000> posix_time_system;
#else
  typedef date_time::split_timedate_system<posix_time_system_config> posix_time_system;
#endif

#else

  typedef date_time::counted_time_rep<millisec_posix_time_system_config> int64_time_rep;
  typedef date_time::counted_time_system<int64_time_rep> posix_time_system;

#endif

} }//namespace posix_time


#endif




























