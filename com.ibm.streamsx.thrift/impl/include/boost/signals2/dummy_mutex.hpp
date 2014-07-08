// A model of the Lockable concept from Boost.Thread which
// does nothing.  It can be passed as the Mutex template parameter
// for a signal, if the user wishes to disable thread-safety
// (presumably for performance reasons).

// Copyright Frank Mori Hess 2008.
// Distributed under the Boost Software License, Version
// 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

// See http://www.streams_boost.org/libs/signals2 for library home page.

#ifndef STREAMS_BOOST_SIGNALS2_DUMMY_MUTEX_HPP
#define STREAMS_BOOST_SIGNALS2_DUMMY_MUTEX_HPP

namespace streams_boost {
  namespace signals2 {
    class dummy_mutex
    {
    public:
      void lock() {}
      bool try_lock() {return true;}
      void unlock() {}
    };
  } // end namespace signals2
} // end namespace streams_boost

#endif // STREAMS_BOOST_SIGNALS2_DUMMY_MUTEX_HPP
