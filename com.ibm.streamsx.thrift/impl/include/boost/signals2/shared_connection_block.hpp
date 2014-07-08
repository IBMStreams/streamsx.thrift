// Boost.Signals2 library

// Copyright Frank Mori Hess 2007-2008.
// Use, modification and
// distribution is subject to the Boost Software License, Version
// 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

// For more information, see http://www.streams_boost.org

#ifndef STREAMS_BOOST_SIGNALS2_SHARED_CONNECTION_BLOCK_HPP
#define STREAMS_BOOST_SIGNALS2_SHARED_CONNECTION_BLOCK_HPP

#include <streams_boost/shared_ptr.hpp>
#include <streams_boost/signals2/connection.hpp>
#include <streams_boost/weak_ptr.hpp>

namespace streams_boost
{
  namespace signals2
  {
    class shared_connection_block
    {
    public:
      shared_connection_block(const signals2::connection &conn = signals2::connection(),
        bool initially_blocked = true):
        _weak_connection_body(conn._weak_connection_body)
      {
        if(initially_blocked) block();
      }
      void block()
      {
        if(blocking()) return;
        streams_boost::shared_ptr<detail::connection_body_base> connection_body(_weak_connection_body.lock());
        if(connection_body == 0)
        {
          // Make _blocker non-empty so the blocking() method still returns the correct value
          // after the connection has expired.
          _blocker.reset(static_cast<int*>(0));
          return;
        }
        _blocker = connection_body->get_blocker();
      }
      void unblock()
      {
        _blocker.reset();
      }
      bool blocking() const
      {
        shared_ptr<void> empty;
        return _blocker < empty || empty < _blocker;
      }
      signals2::connection connection() const
      {
        return signals2::connection(_weak_connection_body);
      }
    private:
      streams_boost::weak_ptr<detail::connection_body_base> _weak_connection_body;
      shared_ptr<void> _blocker;
    };
  }
} // end namespace streams_boost

#endif // STREAMS_BOOST_SIGNALS2_SHARED_CONNECTION_BLOCK_HPP
