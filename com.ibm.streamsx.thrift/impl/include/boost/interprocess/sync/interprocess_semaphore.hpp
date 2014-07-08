//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2005-2009. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/interprocess for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef STREAMS_BOOST_INTERPROCESS_SEMAPHORE_HPP
#define STREAMS_BOOST_INTERPROCESS_SEMAPHORE_HPP

/// @cond

#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

#include <streams_boost/interprocess/detail/config_begin.hpp>
#include <streams_boost/interprocess/detail/workaround.hpp>
#include <streams_boost/interprocess/creation_tags.hpp>
#include <streams_boost/interprocess/exceptions.hpp>
#include <streams_boost/interprocess/detail/posix_time_types_wrk.hpp>

#if !defined(STREAMS_BOOST_INTERPROCESS_FORCE_GENERIC_EMULATION) && \
   (defined(STREAMS_BOOST_INTERPROCESS_POSIX_PROCESS_SHARED) && defined(STREAMS_BOOST_INTERPROCESS_POSIX_NAMED_SEMAPHORES))
   #include <fcntl.h>      //O_CREAT, O_*... 
   #include <unistd.h>     //close
   #include <string>       //std::string
   #include <semaphore.h>  //sem_* family, SEM_VALUE_MAX
   #include <sys/stat.h>   //mode_t, S_IRWXG, S_IRWXO, S_IRWXU,
   #include <streams_boost/interprocess/sync/posix/semaphore_wrapper.hpp>
   #define STREAMS_BOOST_INTERPROCESS_USE_POSIX
#else
   #include <streams_boost/interprocess/detail/atomic.hpp>
   #include <streams_boost/cstdint.hpp>
   #include <streams_boost/interprocess/detail/os_thread_functions.hpp>
   #define STREAMS_BOOST_INTERPROCESS_USE_GENERIC_EMULATION
#endif

/// @endcond

//!\file
//!Describes a interprocess_semaphore class for inter-process synchronization

namespace streams_boost {

namespace interprocess {

//!Wraps a interprocess_semaphore that can be placed in shared memory and can be 
//!shared between processes. Allows timed lock tries
class interprocess_semaphore
{
   /// @cond
   //Non-copyable
   interprocess_semaphore(const interprocess_semaphore &);
   interprocess_semaphore &operator=(const interprocess_semaphore &);
   /// @endcond
   public:
   //!Creates a interprocess_semaphore with the given initial count. 
   //!interprocess_exception if there is an error.*/
   interprocess_semaphore(unsigned int initialCount);

   //!Destroys the interprocess_semaphore.
   //!Does not throw
   ~interprocess_semaphore();

   //!Increments the interprocess_semaphore count. If there are processes/threads blocked waiting
   //!for the interprocess_semaphore, then one of these processes will return successfully from
   //!its wait function. If there is an error an interprocess_exception exception is thrown.
   void post();

   //!Decrements the interprocess_semaphore. If the interprocess_semaphore value is not greater than zero,
   //!then the calling process/thread blocks until it can decrement the counter. 
   //!If there is an error an interprocess_exception exception is thrown.
   void wait();

   //!Decrements the interprocess_semaphore if the interprocess_semaphore's value is greater than zero
   //!and returns true. If the value is not greater than zero returns false.
   //!If there is an error an interprocess_exception exception is thrown.
   bool try_wait();

   //!Decrements the interprocess_semaphore if the interprocess_semaphore's value is greater
   //!than zero and returns true. Otherwise, waits for the interprocess_semaphore
   //!to the posted or the timeout expires. If the timeout expires, the
   //!function returns false. If the interprocess_semaphore is posted the function
   //!returns true. If there is an error throws sem_exception
   bool timed_wait(const streams_boost::posix_time::ptime &abs_time);

   //!Returns the interprocess_semaphore count
//   int get_count() const;
   /// @cond
   private:
   #if defined(STREAMS_BOOST_INTERPROCESS_USE_GENERIC_EMULATION)
   volatile streams_boost::uint32_t m_count;
   #else 
   detail::semaphore_wrapper m_sem;
   #endif   //#if defined(STREAMS_BOOST_INTERPROCESS_USE_GENERIC_EMULATION)
   /// @endcond
};

}  //namespace interprocess {

}  //namespace streams_boost {

#ifdef STREAMS_BOOST_INTERPROCESS_USE_GENERIC_EMULATION
#  undef STREAMS_BOOST_INTERPROCESS_USE_GENERIC_EMULATION
#  include <streams_boost/interprocess/sync/emulation/interprocess_semaphore.hpp>
#endif

#ifdef STREAMS_BOOST_INTERPROCESS_USE_POSIX
#  undef STREAMS_BOOST_INTERPROCESS_USE_POSIX
#  include <streams_boost/interprocess/sync/posix/interprocess_semaphore.hpp>
#endif

#include <streams_boost/interprocess/detail/config_end.hpp>

#endif   //STREAMS_BOOST_INTERPROCESS_SEMAPHORE_HPP
