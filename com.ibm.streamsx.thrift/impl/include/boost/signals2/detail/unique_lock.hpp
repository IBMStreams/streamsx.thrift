/*
  Provides a basic subset of streams_boost::unique_lock functionality.  Provided only because
  including streams_boost/thread/locks.hpp requires linking to thread library
*/
// Copyright Frank Mori Hess 2008.
// Distributed under the Boost Software License, Version
// 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

// See http://www.streams_boost.org/libs/signals2 for library home page.

#ifndef STREAMS_BOOST_SIGNALS2_UNIQUE_LOCK_HPP
#define STREAMS_BOOST_SIGNALS2_UNIQUE_LOCK_HPP

#include <streams_boost/noncopyable.hpp>

namespace streams_boost
{
  namespace signals2
  {
    namespace detail
    {
      template<typename Mutex>
      class unique_lock: public noncopyable
      {
      public:
        unique_lock(Mutex &m): _mutex(m)
        {
          _mutex.lock();
        }
        ~unique_lock()
        {
          _mutex.unlock();
        }
      private:
        Mutex &_mutex;
      };
    } // namespace detail
  } // namespace signals2
} // namespace streams_boost

#endif  // STREAMS_BOOST_SIGNALS2_UNIQUE_LOCK_HPP
