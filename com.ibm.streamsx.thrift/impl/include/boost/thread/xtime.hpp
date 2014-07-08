// Copyright (C) 2001-2003
// William E. Kempf
// Copyright (C) 2007-8 Anthony Williams
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying 
//  file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_XTIME_WEK070601_HPP
#define STREAMS_BOOST_XTIME_WEK070601_HPP

#include <streams_boost/thread/detail/config.hpp>

#include <streams_boost/cstdint.hpp>
#include <streams_boost/thread/thread_time.hpp>
#include <streams_boost/date_time/posix_time/conversion.hpp>

#include <streams_boost/config/abi_prefix.hpp>

namespace streams_boost {

enum xtime_clock_types
{
    TIME_UTC=1
//    TIME_TAI,
//    TIME_MONOTONIC,
//    TIME_PROCESS,
//    TIME_THREAD,
//    TIME_LOCAL,
//    TIME_SYNC,
//    TIME_RESOLUTION
};

struct xtime
{
#if defined(STREAMS_BOOST_NO_INT64_T)
    typedef int_fast32_t xtime_sec_t; //INT_FAST32_MIN <= sec <= INT_FAST32_MAX
#else
    typedef int_fast64_t xtime_sec_t; //INT_FAST64_MIN <= sec <= INT_FAST64_MAX
#endif

    typedef int_fast32_t xtime_nsec_t; //0 <= xtime.nsec < NANOSECONDS_PER_SECOND

    xtime_sec_t sec;
    xtime_nsec_t nsec;

    operator system_time() const
    {
        return streams_boost::posix_time::from_time_t(0)+
            streams_boost::posix_time::seconds(static_cast<long>(sec))+
#ifdef STREAMS_BOOST_DATE_TIME_HAS_NANOSECONDS
            streams_boost::posix_time::nanoseconds(nsec);
#else
        streams_boost::posix_time::microseconds((nsec+500)/1000);
#endif
    }
    
};

inline xtime get_xtime(streams_boost::system_time const& abs_time)
{
    xtime res;
    streams_boost::posix_time::time_duration const time_since_epoch=abs_time-streams_boost::posix_time::from_time_t(0);
            
    res.sec=static_cast<xtime::xtime_sec_t>(time_since_epoch.total_seconds());
    res.nsec=static_cast<xtime::xtime_nsec_t>(time_since_epoch.fractional_seconds()*(1000000000/time_since_epoch.ticks_per_second()));
    return res;
}

inline int xtime_get(struct xtime* xtp, int clock_type)
{
    if (clock_type == TIME_UTC)
    {
        *xtp=get_xtime(get_system_time());
        return clock_type;
    }
    return 0;
}


inline int xtime_cmp(const xtime& xt1, const xtime& xt2)
{
    if (xt1.sec == xt2.sec)
        return (int)(xt1.nsec - xt2.nsec);
    else 
        return (xt1.sec > xt2.sec) ? 1 : -1;
}

} // namespace streams_boost

#include <streams_boost/config/abi_suffix.hpp>

#endif //STREAMS_BOOST_XTIME_WEK070601_HPP
