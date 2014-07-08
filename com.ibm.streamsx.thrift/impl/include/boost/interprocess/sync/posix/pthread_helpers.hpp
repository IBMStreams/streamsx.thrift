//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2005-2009. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/interprocess for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef STREAMS_BOOST_INTERPROCESS_PTHREAD_HELPERS_HPP
#define STREAMS_BOOST_INTERPROCESS_PTHREAD_HELPERS_HPP

#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

#include <streams_boost/interprocess/detail/config_begin.hpp>
#include <streams_boost/interprocess/detail/workaround.hpp>

#include <pthread.h>
#include <errno.h>   
#include <streams_boost/interprocess/exceptions.hpp>   

namespace streams_boost {
namespace interprocess {
namespace detail{

   #if defined STREAMS_BOOST_INTERPROCESS_POSIX_PROCESS_SHARED

   //!Makes pthread_mutexattr_t cleanup easy when using exceptions
   struct mutexattr_wrapper 
   {
      //!Constructor
      mutexattr_wrapper(bool recursive = false)
      {
         if(pthread_mutexattr_init(&m_attr)!=0 ||
            pthread_mutexattr_setpshared(&m_attr, PTHREAD_PROCESS_SHARED)!= 0 ||
             (recursive &&
              pthread_mutexattr_settype(&m_attr, PTHREAD_MUTEX_RECURSIVE)!= 0 ))
            throw streams_boost::interprocess::interprocess_exception();
      }

      //!Destructor
     ~mutexattr_wrapper()  {  pthread_mutexattr_destroy(&m_attr);  }

      //!This allows using mutexattr_wrapper as pthread_mutexattr_t
      operator pthread_mutexattr_t&()  {  return m_attr;  }

      pthread_mutexattr_t m_attr;
   };

   //!Makes pthread_condattr_t cleanup easy when using exceptions
   struct condattr_wrapper 
   {
      //!Constructor
      condattr_wrapper()
      {
         if(pthread_condattr_init(&m_attr)!=0 ||
            pthread_condattr_setpshared(&m_attr, PTHREAD_PROCESS_SHARED)!= 0)
            throw streams_boost::interprocess::interprocess_exception();
      }

      //!Destructor
     ~condattr_wrapper() { pthread_condattr_destroy(&m_attr); }

      //!This allows using condattr_wrapper as pthread_condattr_t
      operator pthread_condattr_t&(){  return m_attr;  }

      pthread_condattr_t m_attr;
   };

   //!Makes initialized pthread_mutex_t cleanup easy when using exceptions
   class mutex_initializer
   {
    public:
      //!Constructor. Takes interprocess_mutex attributes to initialize the interprocess_mutex
      mutex_initializer(pthread_mutex_t &mut, pthread_mutexattr_t &mut_attr)
      : mp_mut(&mut)
      {
         if(pthread_mutex_init(mp_mut, &mut_attr) != 0)
            throw streams_boost::interprocess::interprocess_exception();
      }

     ~mutex_initializer() {  if(mp_mut) pthread_mutex_destroy(mp_mut);  }

      void release() {mp_mut = 0; }

    private:     
      pthread_mutex_t *mp_mut;
   };

   //!Makes initialized pthread_cond_t cleanup easy when using exceptions
   class condition_initializer
   {
    public:
      condition_initializer(pthread_cond_t &cond, pthread_condattr_t &cond_attr) 
      : mp_cond(&cond)
      {
         if(pthread_cond_init(mp_cond, &cond_attr)!= 0)
            throw streams_boost::interprocess::interprocess_exception();
      }

     ~condition_initializer()   {  if(mp_cond) pthread_cond_destroy(mp_cond);  }

      void release()       { mp_cond = 0; }

    private:   
      pthread_cond_t *mp_cond;
   };

   #endif   //   #if defined STREAMS_BOOST_INTERPROCESS_POSIX_PROCESS_SHARED

   #if defined(STREAMS_BOOST_INTERPROCESS_POSIX_BARRIERS) && defined(STREAMS_BOOST_INTERPROCESS_POSIX_PROCESS_SHARED)

   //!Makes pthread_barrierattr_t cleanup easy when using exceptions
   struct barrierattr_wrapper 
   {
      //!Constructor
      barrierattr_wrapper()
      {
         if(pthread_barrierattr_init(&m_attr)!=0 ||
            pthread_barrierattr_setpshared(&m_attr, PTHREAD_PROCESS_SHARED)!= 0)
            throw streams_boost::interprocess::interprocess_exception();
      }

      //!Destructor
     ~barrierattr_wrapper()  {  pthread_barrierattr_destroy(&m_attr);  }

      //!This allows using mutexattr_wrapper as pthread_barrierattr_t
      operator pthread_barrierattr_t&()  {  return m_attr;  }

      pthread_barrierattr_t m_attr;
   };

   //!Makes initialized pthread_barrier_t cleanup easy when using exceptions
   class barrier_initializer
   {
    public:
      //!Constructor. Takes barrier attributes to initialize the barrier
      barrier_initializer(pthread_barrier_t &mut, 
                          pthread_barrierattr_t &mut_attr, 
                          int count)
      : mp_barrier(&mut)
      {
         if(pthread_barrier_init(mp_barrier, &mut_attr, count) != 0)
            throw streams_boost::interprocess::interprocess_exception();
      }

     ~barrier_initializer() {  if(mp_barrier) pthread_barrier_destroy(mp_barrier);  }

      void release() {mp_barrier = 0; }

    private:     
      pthread_barrier_t *mp_barrier;
   };

   #endif   //#if defined(STREAMS_BOOST_INTERPROCESS_POSIX_BARRIERS) && defined(STREAMS_BOOST_INTERPROCESS_POSIX_PROCESS_SHARED)

}//namespace detail

}//namespace interprocess

}//namespace streams_boost

#include <streams_boost/interprocess/detail/config_end.hpp>

#endif //ifdef STREAMS_BOOST_INTERPROCESS_PTHREAD_HELPERS_HPP
