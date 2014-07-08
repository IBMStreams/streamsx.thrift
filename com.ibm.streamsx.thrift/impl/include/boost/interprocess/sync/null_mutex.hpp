//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2005-2009. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/interprocess for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef STREAMS_BOOST_INTERPROCESS_NULL_MUTEX_HPP
#define STREAMS_BOOST_INTERPROCESS_NULL_MUTEX_HPP

#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

#include <streams_boost/interprocess/detail/config_begin.hpp>
#include <streams_boost/interprocess/detail/workaround.hpp>


//!\file
//!Describes null_mutex classes

namespace streams_boost {

namespace posix_time
{  class ptime;   }

namespace interprocess {

//!Implements a mutex that simulates a mutex without doing any operation and
//!simulates a successful operation.
class null_mutex
{
   /// @cond
   null_mutex(const null_mutex&);
   null_mutex &operator= (const null_mutex&);
   /// @endcond
   public:

   //!Constructor.
   //!Empty.
   null_mutex(){}

   //!Destructor.
   //!Empty.
   ~null_mutex(){}

   //!Simulates a mutex lock() operation. Empty function.
   void lock(){}

   //!Simulates a mutex try_lock() operation.
   //!Equivalent to "return true;"
   bool try_lock()
   {  return true;   }

   //!Simulates a mutex timed_lock() operation.
   //!Equivalent to "return true;"
   bool timed_lock(const streams_boost::posix_time::ptime &)
   {  return true;   }

   //!Simulates a mutex unlock() operation.
   //!Empty function.
   void unlock(){}

   //!Simulates a mutex lock_sharable() operation.
   //!Empty function.
   void lock_sharable(){}

   //!Simulates a mutex try_lock_sharable() operation.
   //!Equivalent to "return true;"
   bool try_lock_sharable()
   {  return true;   }

   //!Simulates a mutex timed_lock_sharable() operation.
   //!Equivalent to "return true;"
   bool timed_lock_sharable(const streams_boost::posix_time::ptime &)
   {  return true;   }

   //!Simulates a mutex unlock_sharable() operation.
   //!Empty function.
   void unlock_sharable(){}

   //!Simulates a mutex lock_upgradable() operation.
   //!Empty function.
   void lock_upgradable(){}

   //!Simulates a mutex try_lock_upgradable() operation.
   //!Equivalent to "return true;"
   bool try_lock_upgradable()
   {  return true;   }

   //!Simulates a mutex timed_lock_upgradable() operation.
   //!Equivalent to "return true;"
   bool timed_lock_upgradable(const streams_boost::posix_time::ptime &)
   {  return true;   }

   //!Simulates a mutex unlock_upgradable() operation.
   //!Empty function.
   void unlock_upgradable(){}

   //!Simulates unlock_and_lock_upgradable().
   //!Empty function.
   void unlock_and_lock_upgradable(){}

   //!Simulates unlock_and_lock_sharable().
   //!Empty function.
   void unlock_and_lock_sharable(){}

   //!Simulates unlock_upgradable_and_lock_sharable().
   //!Empty function.
   void unlock_upgradable_and_lock_sharable(){}

   //Promotions

   //!Simulates unlock_upgradable_and_lock().
   //!Empty function.
   void unlock_upgradable_and_lock(){}

   //!Simulates try_unlock_upgradable_and_lock().
   //!Equivalent to "return true;"
   bool try_unlock_upgradable_and_lock()
   {  return true;   }

   //!Simulates timed_unlock_upgradable_and_lock().
   //!Equivalent to "return true;"
   bool timed_unlock_upgradable_and_lock(const streams_boost::posix_time::ptime &)
   {  return true;   }

   //!Simulates try_unlock_sharable_and_lock().
   //!Equivalent to "return true;"
   bool try_unlock_sharable_and_lock()
   {  return true;   }

   //!Simulates try_unlock_sharable_and_lock_upgradable().
   //!Equivalent to "return true;"
   bool try_unlock_sharable_and_lock_upgradable()
   {  return true;   }
};

}  //namespace interprocess {
}  //namespace streams_boost {

#include <streams_boost/interprocess/detail/config_end.hpp>

#endif   //STREAMS_BOOST_INTERPROCESS_NULL_MUTEX_HPP
