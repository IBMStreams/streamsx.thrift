#ifndef STREAMS_BOOST_PTHREAD_MUTEX_SCOPED_LOCK_HPP
#define STREAMS_BOOST_PTHREAD_MUTEX_SCOPED_LOCK_HPP
//  (C) Copyright 2007-8 Anthony Williams 
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt)

#include <pthread.h>
#include <streams_boost/assert.hpp>

#include <streams_boost/config/abi_prefix.hpp>

namespace streams_boost
{
    namespace pthread
    {
        class pthread_mutex_scoped_lock
        {
            pthread_mutex_t* m;
        public:
            explicit pthread_mutex_scoped_lock(pthread_mutex_t* m_):
                m(m_)
            {
                STREAMS_BOOST_VERIFY(!pthread_mutex_lock(m));
            }
            ~pthread_mutex_scoped_lock()
            {
                STREAMS_BOOST_VERIFY(!pthread_mutex_unlock(m));
            }
            
        };

        class pthread_mutex_scoped_unlock
        {
            pthread_mutex_t* m;
        public:
            explicit pthread_mutex_scoped_unlock(pthread_mutex_t* m_):
                m(m_)
            {
                STREAMS_BOOST_VERIFY(!pthread_mutex_unlock(m));
            }
            ~pthread_mutex_scoped_unlock()
            {
                STREAMS_BOOST_VERIFY(!pthread_mutex_lock(m));
            }
            
        };
    }
}

#include <streams_boost/config/abi_suffix.hpp>

#endif
