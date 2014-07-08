// Boost.Signals2 library

// Copyright Frank Mori Hess 2007-2008.
// Use, modification and
// distribution is subject to the Boost Software License, Version
// 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

// For more information, see http://www.streams_boost.org

#ifndef STREAMS_BOOST_SIGNALS2_SIGNAL_BASE_HPP
#define STREAMS_BOOST_SIGNALS2_SIGNAL_BASE_HPP

#include <streams_boost/noncopyable.hpp>
#include <streams_boost/shared_ptr.hpp>

namespace streams_boost {
  namespace signals2 {
    class slot_base;

    class signal_base : public noncopyable
    {
    public:
      friend class slot_base;

      virtual ~signal_base() {}
    protected:
      virtual shared_ptr<void> lock_pimpl() const = 0;
    };
  } // end namespace signals2
} // end namespace streams_boost

#endif // STREAMS_BOOST_SIGNALS2_SIGNAL_BASE_HPP
