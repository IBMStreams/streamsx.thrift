#ifndef STREAMS_BOOST_THREAD_PTHREAD_THREAD_DATA_HPP
#define STREAMS_BOOST_THREAD_PTHREAD_THREAD_DATA_HPP
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
// (C) Copyright 2007 Anthony Williams

#include <streams_boost/thread/detail/config.hpp>
#include <streams_boost/thread/exceptions.hpp>
#include <streams_boost/shared_ptr.hpp>
#include <streams_boost/enable_shared_from_this.hpp>
#include <streams_boost/thread/mutex.hpp>
#include <streams_boost/optional.hpp>
#include <pthread.h>
#include "condition_variable_fwd.hpp"
#include <map>

#include <streams_boost/config/abi_prefix.hpp>

namespace streams_boost
{
    class thread;
    
    namespace detail
    {
        struct tss_cleanup_function;
        struct thread_exit_callback_node;
        struct tss_data_node
        {
            streams_boost::shared_ptr<streams_boost::detail::tss_cleanup_function> func;
            void* value;

            tss_data_node(streams_boost::shared_ptr<streams_boost::detail::tss_cleanup_function> func_,
                          void* value_):
                func(func_),value(value_)
            {}
        };

        struct thread_data_base;
        typedef streams_boost::shared_ptr<thread_data_base> thread_data_ptr;
        
        struct STREAMS_BOOST_THREAD_DECL thread_data_base:
            enable_shared_from_this<thread_data_base>
        {
            thread_data_ptr self;
            pthread_t thread_handle;
            streams_boost::mutex data_mutex;
            streams_boost::condition_variable done_condition;
            streams_boost::mutex sleep_mutex;
            streams_boost::condition_variable sleep_condition;
            bool done;
            bool join_started;
            bool joined;
            streams_boost::detail::thread_exit_callback_node* thread_exit_callbacks;
            std::map<void const*,streams_boost::detail::tss_data_node> tss_data;
            bool interrupt_enabled;
            bool interrupt_requested;
            pthread_cond_t* current_cond;

            thread_data_base():
                done(false),join_started(false),joined(false),
                thread_exit_callbacks(0),
                interrupt_enabled(true),
                interrupt_requested(false),
                current_cond(0)
            {}
            virtual ~thread_data_base();

            typedef pthread_t native_handle_type;

            virtual void run()=0;
        };

        STREAMS_BOOST_THREAD_DECL thread_data_base* get_current_thread_data();

        class interruption_checker
        {
            thread_data_base* const thread_info;

            void check_for_interruption()
            {
                if(thread_info->interrupt_requested)
                {
                    thread_info->interrupt_requested=false;
                    throw thread_interrupted();
                }
            }
            
            void operator=(interruption_checker&);
        public:
            explicit interruption_checker(pthread_cond_t* cond):
                thread_info(detail::get_current_thread_data())
            {
                if(thread_info && thread_info->interrupt_enabled)
                {
                    lock_guard<mutex> guard(thread_info->data_mutex);
                    check_for_interruption();
                    thread_info->current_cond=cond;
                }
            }
            ~interruption_checker()
            {
                if(thread_info && thread_info->interrupt_enabled)
                {
                    lock_guard<mutex> guard(thread_info->data_mutex);
                    thread_info->current_cond=NULL;
                    check_for_interruption();
                }
            }
        };
    }

    namespace this_thread
    {
        void STREAMS_BOOST_THREAD_DECL yield();
        
        void STREAMS_BOOST_THREAD_DECL sleep(system_time const& abs_time);
        
        template<typename TimeDuration>
        inline void sleep(TimeDuration const& rel_time)
        {
            this_thread::sleep(get_system_time()+rel_time);
        }
    }
}

#include <streams_boost/config/abi_suffix.hpp>

#endif
