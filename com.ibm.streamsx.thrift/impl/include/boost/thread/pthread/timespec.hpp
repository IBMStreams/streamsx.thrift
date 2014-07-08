#ifndef STREAMS_BOOST_THREAD_PTHREAD_TIMESPEC_HPP
#define STREAMS_BOOST_THREAD_PTHREAD_TIMESPEC_HPP
//  (C) Copyright 2007-8 Anthony Williams 
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt)

#include <streams_boost/thread/thread_time.hpp>
#include <streams_boost/date_time/posix_time/conversion.hpp>
#include <pthread.h>
#ifndef _WIN32
#include <unistd.h>
#endif

#include <streams_boost/config/abi_prefix.hpp>

namespace streams_boost
{
    namespace detail
    {
        inline struct timespec get_timespec(streams_boost::system_time const& abs_time)
        {
            struct timespec timeout={0,0};
            streams_boost::posix_time::time_duration const time_since_epoch=abs_time-streams_boost::posix_time::from_time_t(0);
            
            timeout.tv_sec=time_since_epoch.total_seconds();
            timeout.tv_nsec=(long)(time_since_epoch.fractional_seconds()*(1000000000l/time_since_epoch.ticks_per_second()));
            return timeout;
        }
    }
}

#include <streams_boost/config/abi_suffix.hpp>

#endif
