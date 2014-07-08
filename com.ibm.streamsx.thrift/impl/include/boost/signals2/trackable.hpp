// Boost.Signals2 library

// Copyright Frank Mori Hess 2007,2009.
// Copyright Timmo Stange 2007.
// Copyright Douglas Gregor 2001-2004. Use, modification and
// distribution is subject to the Boost Software License, Version
// 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

// Compatibility class to ease porting from the original
// Boost.Signals library.  However,
// streams_boost::signals2::trackable is NOT thread-safe.

// For more information, see http://www.streams_boost.org

#ifndef STREAMS_BOOST_SIGNALS2_TRACKABLE_HPP
#define STREAMS_BOOST_SIGNALS2_TRACKABLE_HPP

#include <streams_boost/assert.hpp>
#include <streams_boost/shared_ptr.hpp>

namespace streams_boost {
  namespace signals2 {
    namespace detail
    {
        class tracked_objects_visitor;
    }
    class trackable {
    protected:
      trackable(): _tracked_ptr(static_cast<int*>(0)) {}
      trackable(const trackable &): _tracked_ptr(static_cast<int*>(0)) {}
      trackable& operator=(const trackable &)
      {
          return *this;
      }
      ~trackable() {}
    private:
      friend class detail::tracked_objects_visitor;
      const shared_ptr<void>& get_shared_ptr() const
      {
          return _tracked_ptr;
      }

      shared_ptr<void> _tracked_ptr;
    };
  } // end namespace signals2
} // end namespace streams_boost

#endif // STREAMS_BOOST_SIGNALS2_TRACKABLE_HPP
