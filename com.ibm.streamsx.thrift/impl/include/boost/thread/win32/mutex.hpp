#ifndef STREAMS_BOOST_THREAD_WIN32_MUTEX_HPP
#define STREAMS_BOOST_THREAD_WIN32_MUTEX_HPP
// (C) Copyright 2005-7 Anthony Williams
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#include "basic_timed_mutex.hpp"
#include <streams_boost/utility.hpp>
#include <streams_boost/thread/exceptions.hpp>
#include <streams_boost/thread/locks.hpp>

#include <streams_boost/config/abi_prefix.hpp>

namespace streams_boost
{
    namespace detail
    {
        typedef ::streams_boost::detail::basic_timed_mutex underlying_mutex;
    }

    class mutex:
        streams_boost::noncopyable,
        public ::streams_boost::detail::underlying_mutex
    {
    public:
        mutex()
        {
            initialize();
        }
        ~mutex()
        {
            destroy();
        }

        typedef unique_lock<mutex> scoped_lock;
        typedef detail::try_lock_wrapper<mutex> scoped_try_lock;
    };

    typedef mutex try_mutex;

    class timed_mutex:
        streams_boost::noncopyable,
        public ::streams_boost::detail::basic_timed_mutex
    {
    public:
        timed_mutex()
        {
            initialize();
        }

        ~timed_mutex()
        {
            destroy();
        }

        typedef unique_lock<timed_mutex> scoped_timed_lock;
        typedef detail::try_lock_wrapper<timed_mutex> scoped_try_lock;
        typedef scoped_timed_lock scoped_lock;
    };
}

#include <streams_boost/config/abi_suffix.hpp>

#endif
