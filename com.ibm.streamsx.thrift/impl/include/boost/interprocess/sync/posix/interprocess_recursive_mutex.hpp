//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2005-2009. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/interprocess for documentation.
//
//////////////////////////////////////////////////////////////////////////////
//
// Parts of the pthread code come from Boost Threads code:
//
//////////////////////////////////////////////////////////////////////////////
//
// Copyright (C) 2001-2003
// William E. Kempf
//
// Permission to use, copy, modify, distribute and sell this software
// and its documentation for any purpose is hereby granted without fee,
// provided that the above copyright notice appear in all copies and
// that both that copyright notice and this permission notice appear
// in supporting documentation.  William E. Kempf makes no representations
// about the suitability of this software for any purpose.
// It is provided "as is" without express or implied warranty.
//////////////////////////////////////////////////////////////////////////////

#include <streams_boost/interprocess/sync/posix/ptime_to_timespec.hpp>
#include <streams_boost/interprocess/detail/posix_time_types_wrk.hpp>
#include <streams_boost/interprocess/exceptions.hpp>
#ifndef STREAMS_BOOST_INTERPROCESS_POSIX_TIMEOUTS
#  include <streams_boost/interprocess/detail/os_thread_functions.hpp>
#endif

namespace streams_boost {

namespace interprocess {

inline interprocess_recursive_mutex::interprocess_recursive_mutex()
{
   detail::mutexattr_wrapper mut_attr(true);
   detail::mutex_initializer mut(m_mut, mut_attr);
   mut.release();
}

inline interprocess_recursive_mutex::~interprocess_recursive_mutex()
{
   int res = pthread_mutex_destroy(&m_mut);
   assert(res == 0);(void)res;
}

inline void interprocess_recursive_mutex::lock()
{
   if (pthread_mutex_lock(&m_mut) != 0) 
      throw lock_exception();
}

inline bool interprocess_recursive_mutex::try_lock()
{
   int res = pthread_mutex_trylock(&m_mut);
   if (!(res == 0 || res == EBUSY))
      throw lock_exception();
   return res == 0;
}

inline bool interprocess_recursive_mutex::timed_lock(const streams_boost::posix_time::ptime &abs_time)
{
   if(abs_time == streams_boost::posix_time::pos_infin){
      this->lock();
      return true;
   }
   #ifdef STREAMS_BOOST_INTERPROCESS_POSIX_TIMEOUTS

   timespec ts = detail::ptime_to_timespec(abs_time);
   int res = pthread_mutex_timedlock(&m_mut, &ts);
   if (res != 0 && res != ETIMEDOUT)
      throw lock_exception();
   return res == 0;

   #else //STREAMS_BOOST_INTERPROCESS_POSIX_TIMEOUTS

   //Obtain current count and target time
   streams_boost::posix_time::ptime now = microsec_clock::universal_time();

   if(now >= abs_time) return false;

   do{
      if(this->try_lock()){
         break;
      }
      now = microsec_clock::universal_time();

      if(now >= abs_time){
         return false;
      }
      // relinquish current time slice
     detail::thread_yield();
   }while (true);
   return true;

   #endif   //STREAMS_BOOST_INTERPROCESS_POSIX_TIMEOUTS
}

inline void interprocess_recursive_mutex::unlock()
{
   int res = 0;
   res = pthread_mutex_unlock(&m_mut);
   assert(res == 0);
}

}  //namespace interprocess {
}  //namespace streams_boost {
