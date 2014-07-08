// Boost.Signals2 library

// Copyright Frank Mori Hess 2007-2008.
// Copyright Timmo Stange 2007.
// Copyright Douglas Gregor 2001-2004. Use, modification and
// distribution is subject to the Boost Software License, Version
// 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

// For more information, see http://www.streams_boost.org

#ifndef STREAMS_BOOST_SIGNALS2_SLOT_BASE_HPP
#define STREAMS_BOOST_SIGNALS2_SLOT_BASE_HPP

#include <streams_boost/shared_ptr.hpp>
#include <streams_boost/weak_ptr.hpp>
#include <streams_boost/signals2/signal_base.hpp>
#include <streams_boost/throw_exception.hpp>
#include <vector>

namespace streams_boost
{
  namespace signals2
  {
    namespace detail
    {
      class tracked_objects_visitor;
    }

    class expired_slot: public bad_weak_ptr
    {
    public:
      virtual char const * what() const throw()
      {
        return "streams_boost::signals2::expired_slot";
      }
    };

    class slot_base
    {
    public:
      typedef std::vector<streams_boost::weak_ptr<void> > tracked_container_type;
      typedef std::vector<streams_boost::shared_ptr<void> > locked_container_type;

      const tracked_container_type& tracked_objects() const {return _tracked_objects;}
      locked_container_type lock() const
      {
        locked_container_type locked_objects;
        tracked_container_type::const_iterator it;
        for(it = tracked_objects().begin(); it != tracked_objects().end(); ++it)
        {
          try
          {
            locked_objects.push_back(shared_ptr<void>(*it));
          }
          catch(const bad_weak_ptr &)
          {
            streams_boost::throw_exception(expired_slot());
          }
        }
        return locked_objects;
      }
      bool expired() const
      {
        tracked_container_type::const_iterator it;
        for(it = tracked_objects().begin(); it != tracked_objects().end(); ++it)
        {
          if(it->expired()) return true;
        }
        return false;
      }
    protected:
      friend class detail::tracked_objects_visitor;

      void track_signal(const signal_base &signal)
      {
        _tracked_objects.push_back(signal.lock_pimpl());
      }

      tracked_container_type _tracked_objects;
    };
  }
} // end namespace streams_boost

#endif // STREAMS_BOOST_SIGNALS2_SLOT_BASE_HPP
