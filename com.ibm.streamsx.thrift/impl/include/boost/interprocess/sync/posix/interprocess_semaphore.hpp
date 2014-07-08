//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2005-2009. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/interprocess for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#include <streams_boost/interprocess/sync/posix/ptime_to_timespec.hpp>
#include <streams_boost/interprocess/detail/posix_time_types_wrk.hpp>

namespace streams_boost {

namespace interprocess {

inline interprocess_semaphore::~interprocess_semaphore()
{}

inline interprocess_semaphore::interprocess_semaphore(unsigned int initialCount)
   :  m_sem(initialCount)
{}

inline void interprocess_semaphore::post()
{  m_sem.post();   }

inline void interprocess_semaphore::wait()
{  m_sem.wait();   }

inline bool interprocess_semaphore::try_wait()
{  return m_sem.try_wait();   }

inline bool interprocess_semaphore::timed_wait(const streams_boost::posix_time::ptime &abs_time)
{
   if(abs_time == streams_boost::posix_time::pos_infin){
      this->wait();
      return true;
   }
   return m_sem.timed_wait(abs_time);
}
/*
inline int interprocess_semaphore::get_count() const
{  return m_sem.get_count();  }
*/
}  //namespace interprocess {

}  //namespace streams_boost {

