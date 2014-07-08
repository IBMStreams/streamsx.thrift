#ifndef STREAMS_BOOST_RECURSIVE_MUTEX_WIN32_HPP
#define STREAMS_BOOST_RECURSIVE_MUTEX_WIN32_HPP

//  recursive_mutex.hpp
//
//  (C) Copyright 2006-7 Anthony Williams 
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt)


#include <streams_boost/utility.hpp>
#include "basic_recursive_mutex.hpp"
#include <streams_boost/thread/exceptions.hpp>
#include <streams_boost/thread/locks.hpp>

#include <streams_boost/config/abi_prefix.hpp>

namespace streams_boost
{
    class recursive_mutex:
        streams_boost::noncopyable,
        public ::streams_boost::detail::basic_recursive_mutex
    {
    public:
        recursive_mutex()
        {
            ::streams_boost::detail::basic_recursive_mutex::initialize();
        }
        ~recursive_mutex()
        {
            ::streams_boost::detail::basic_recursive_mutex::destroy();
        }

        typedef unique_lock<recursive_mutex> scoped_lock;
        typedef detail::try_lock_wrapper<recursive_mutex> scoped_try_lock;
    };

    typedef recursive_mutex recursive_try_mutex;

    class recursive_timed_mutex:
        streams_boost::noncopyable,
        public ::streams_boost::detail::basic_recursive_timed_mutex
    {
    public:
        recursive_timed_mutex()
        {
            ::streams_boost::detail::basic_recursive_timed_mutex::initialize();
        }
        ~recursive_timed_mutex()
        {
            ::streams_boost::detail::basic_recursive_timed_mutex::destroy();
        }

        typedef unique_lock<recursive_timed_mutex> scoped_timed_lock;
        typedef detail::try_lock_wrapper<recursive_timed_mutex> scoped_try_lock;
        typedef scoped_timed_lock scoped_lock;
    };
}

#include <streams_boost/config/abi_suffix.hpp>

#endif
