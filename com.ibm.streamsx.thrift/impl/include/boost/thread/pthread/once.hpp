#ifndef STREAMS_BOOST_THREAD_PTHREAD_ONCE_HPP
#define STREAMS_BOOST_THREAD_PTHREAD_ONCE_HPP

//  once.hpp
//
//  (C) Copyright 2007-8 Anthony Williams 
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt)

#include <streams_boost/thread/detail/config.hpp>

#include <pthread.h>
#include <streams_boost/assert.hpp>
#include "pthread_mutex_scoped_lock.hpp"
#include <streams_boost/thread/pthread/pthread_mutex_scoped_lock.hpp>
#include <streams_boost/cstdint.hpp>

#include <streams_boost/config/abi_prefix.hpp>

namespace streams_boost
{

    struct once_flag
    {
        streams_boost::uintmax_t epoch;
    };

    namespace detail
    {
        STREAMS_BOOST_THREAD_DECL streams_boost::uintmax_t& get_once_per_thread_epoch();
        STREAMS_BOOST_THREAD_DECL extern streams_boost::uintmax_t once_global_epoch;
        STREAMS_BOOST_THREAD_DECL extern pthread_mutex_t once_epoch_mutex;
        STREAMS_BOOST_THREAD_DECL extern pthread_cond_t once_epoch_cv;
    }
    
#define STREAMS_BOOST_ONCE_INITIAL_FLAG_VALUE 0
#define STREAMS_BOOST_ONCE_INIT {STREAMS_BOOST_ONCE_INITIAL_FLAG_VALUE}


    // Based on Mike Burrows fast_pthread_once algorithm as described in
    // http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2007/n2444.html
    template<typename Function>
    void call_once(once_flag& flag,Function f)
    {
        static streams_boost::uintmax_t const uninitialized_flag=STREAMS_BOOST_ONCE_INITIAL_FLAG_VALUE;
        static streams_boost::uintmax_t const being_initialized=uninitialized_flag+1;
        streams_boost::uintmax_t const epoch=flag.epoch;
        streams_boost::uintmax_t& this_thread_epoch=detail::get_once_per_thread_epoch();
        
        if(epoch<this_thread_epoch)
        {
            pthread::pthread_mutex_scoped_lock lk(&detail::once_epoch_mutex);

            while(flag.epoch<=being_initialized)
            {
                if(flag.epoch==uninitialized_flag)
                {
                    flag.epoch=being_initialized;
                    try
                    {
                        pthread::pthread_mutex_scoped_unlock relocker(&detail::once_epoch_mutex);
                        f();
                    }
                    catch(...)
                    {
                        flag.epoch=uninitialized_flag;
                        STREAMS_BOOST_VERIFY(!pthread_cond_broadcast(&detail::once_epoch_cv));
                        throw;
                    }
                    flag.epoch=--detail::once_global_epoch;
                    STREAMS_BOOST_VERIFY(!pthread_cond_broadcast(&detail::once_epoch_cv));
                }
                else
                {
                    while(flag.epoch==being_initialized)
                    {
                        STREAMS_BOOST_VERIFY(!pthread_cond_wait(&detail::once_epoch_cv,&detail::once_epoch_mutex));
                    }
                }
            }
            this_thread_epoch=detail::once_global_epoch;
        }
    }
}

#include <streams_boost/config/abi_suffix.hpp>

#endif
