#ifndef STREAMS_BOOST_THREAD_PTHREAD_RECURSIVE_MUTEX_HPP
#define STREAMS_BOOST_THREAD_PTHREAD_RECURSIVE_MUTEX_HPP
// (C) Copyright 2007-8 Anthony Williams
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#include <pthread.h>
#include <streams_boost/utility.hpp>
#include <streams_boost/thread/exceptions.hpp>
#include <streams_boost/thread/locks.hpp>
#include <streams_boost/thread/thread_time.hpp>
#include <streams_boost/assert.hpp>
#ifndef _WIN32
#include <unistd.h>
#endif
#include <streams_boost/date_time/posix_time/conversion.hpp>
#include <errno.h>
#include "timespec.hpp"
#include "pthread_mutex_scoped_lock.hpp"

#ifdef _POSIX_TIMEOUTS
#if _POSIX_TIMEOUTS >= 0
#define STREAMS_BOOST_PTHREAD_HAS_TIMEDLOCK
#endif
#endif

#include <streams_boost/config/abi_prefix.hpp>

namespace streams_boost
{
    class recursive_mutex:
        streams_boost::noncopyable
    {
    private:
        pthread_mutex_t m;
    public:
        recursive_mutex()
        {
            pthread_mutexattr_t attr;
            
            int const init_attr_res=pthread_mutexattr_init(&attr);
            if(init_attr_res)
            {
                throw thread_resource_error();
            }
            int const set_attr_res=pthread_mutexattr_settype(&attr,PTHREAD_MUTEX_RECURSIVE);
            if(set_attr_res)
            {
                throw thread_resource_error();
            }
            
            int const res=pthread_mutex_init(&m,&attr);
            if(res)
            {
                throw thread_resource_error();
            }
            STREAMS_BOOST_VERIFY(!pthread_mutexattr_destroy(&attr));
        }
        ~recursive_mutex()
        {
            STREAMS_BOOST_VERIFY(!pthread_mutex_destroy(&m));
        }
        
        void lock()
        {
            STREAMS_BOOST_VERIFY(!pthread_mutex_lock(&m));
        }

        void unlock()
        {
            STREAMS_BOOST_VERIFY(!pthread_mutex_unlock(&m));
        }
        
        bool try_lock()
        {
            int const res=pthread_mutex_trylock(&m);
            STREAMS_BOOST_ASSERT(!res || res==EBUSY);
            return !res;
        }

        typedef pthread_mutex_t* native_handle_type;
        native_handle_type native_handle()
        {
            return &m;
        }

        typedef unique_lock<recursive_mutex> scoped_lock;
        typedef detail::try_lock_wrapper<recursive_mutex> scoped_try_lock;
    };

    typedef recursive_mutex recursive_try_mutex;

    class recursive_timed_mutex:
        streams_boost::noncopyable
    {
    private:
        pthread_mutex_t m;
#ifndef STREAMS_BOOST_PTHREAD_HAS_TIMEDLOCK
        pthread_cond_t cond;
        bool is_locked;
        pthread_t owner;
        unsigned count;
#endif
    public:
        recursive_timed_mutex()
        {
#ifdef STREAMS_BOOST_PTHREAD_HAS_TIMEDLOCK
            pthread_mutexattr_t attr;
            
            int const init_attr_res=pthread_mutexattr_init(&attr);
            if(init_attr_res)
            {
                throw thread_resource_error();
            }
            int const set_attr_res=pthread_mutexattr_settype(&attr,PTHREAD_MUTEX_RECURSIVE);
            if(set_attr_res)
            {
                throw thread_resource_error();
            }
            
            int const res=pthread_mutex_init(&m,&attr);
            if(res)
            {
                STREAMS_BOOST_VERIFY(!pthread_mutexattr_destroy(&attr));
                throw thread_resource_error();
            }
            STREAMS_BOOST_VERIFY(!pthread_mutexattr_destroy(&attr));
#else
            int const res=pthread_mutex_init(&m,NULL);
            if(res)
            {
                throw thread_resource_error();
            }
            int const res2=pthread_cond_init(&cond,NULL);
            if(res2)
            {
                STREAMS_BOOST_VERIFY(!pthread_mutex_destroy(&m));
                throw thread_resource_error();
            }
            is_locked=false;
            count=0;
#endif
        }
        ~recursive_timed_mutex()
        {
            STREAMS_BOOST_VERIFY(!pthread_mutex_destroy(&m));
#ifndef STREAMS_BOOST_PTHREAD_HAS_TIMEDLOCK
            STREAMS_BOOST_VERIFY(!pthread_cond_destroy(&cond));
#endif
        }

        template<typename TimeDuration>
        bool timed_lock(TimeDuration const & relative_time)
        {
            return timed_lock(get_system_time()+relative_time);
        }

#ifdef STREAMS_BOOST_PTHREAD_HAS_TIMEDLOCK
        void lock()
        {
            STREAMS_BOOST_VERIFY(!pthread_mutex_lock(&m));
        }

        void unlock()
        {
            STREAMS_BOOST_VERIFY(!pthread_mutex_unlock(&m));
        }
        
        bool try_lock()
        {
            int const res=pthread_mutex_trylock(&m);
            STREAMS_BOOST_ASSERT(!res || res==EBUSY);
            return !res;
        }
        bool timed_lock(system_time const & abs_time)
        {
            struct timespec const timeout=detail::get_timespec(abs_time);
            int const res=pthread_mutex_timedlock(&m,&timeout);
            STREAMS_BOOST_ASSERT(!res || res==ETIMEDOUT);
            return !res;
        }

        typedef pthread_mutex_t* native_handle_type;
        native_handle_type native_handle()
        {
            return &m;
        }

#else
        void lock()
        {
            streams_boost::pthread::pthread_mutex_scoped_lock const local_lock(&m);
            if(is_locked && pthread_equal(owner,pthread_self()))
            {
                ++count;
                return;
            }
            
            while(is_locked)
            {
                STREAMS_BOOST_VERIFY(!pthread_cond_wait(&cond,&m));
            }
            is_locked=true;
            ++count;
            owner=pthread_self();
        }

        void unlock()
        {
            streams_boost::pthread::pthread_mutex_scoped_lock const local_lock(&m);
            if(!--count)
            {
                is_locked=false;
            }
            STREAMS_BOOST_VERIFY(!pthread_cond_signal(&cond));
        }
        
        bool try_lock()
        {
            streams_boost::pthread::pthread_mutex_scoped_lock const local_lock(&m);
            if(is_locked && !pthread_equal(owner,pthread_self()))
            {
                return false;
            }
            is_locked=true;
            ++count;
            owner=pthread_self();
            return true;
        }

        bool timed_lock(system_time const & abs_time)
        {
            struct timespec const timeout=detail::get_timespec(abs_time);
            streams_boost::pthread::pthread_mutex_scoped_lock const local_lock(&m);
            if(is_locked && pthread_equal(owner,pthread_self()))
            {
                ++count;
                return true;
            }
            while(is_locked)
            {
                int const cond_res=pthread_cond_timedwait(&cond,&m,&timeout);
                if(cond_res==ETIMEDOUT)
                {
                    return false;
                }
                STREAMS_BOOST_ASSERT(!cond_res);
            }
            is_locked=true;
            ++count;
            owner=pthread_self();
            return true;
        }
#endif

        typedef unique_lock<recursive_timed_mutex> scoped_timed_lock;
        typedef detail::try_lock_wrapper<recursive_timed_mutex> scoped_try_lock;
        typedef scoped_timed_lock scoped_lock;
    };

}

#include <streams_boost/config/abi_suffix.hpp>

#endif
