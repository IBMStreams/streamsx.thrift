// DEPRECATED in favor of adl_postconstruct and adl_predestruct with
// deconstruct<T>().
// A factory function for creating a shared_ptr that enhances the plain
// shared_ptr constructors by adding support for postconstructors
// and predestructors through the streams_boost::signals2::postconstructible and
// streams_boost::signals2::predestructible base classes.
//
// Copyright Frank Mori Hess 2007-2008.
//
// Use, modification and
// distribution is subject to the Boost Software License, Version
// 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_SIGNALS2_DECONSTRUCT_PTR_HPP
#define STREAMS_BOOST_SIGNALS2_DECONSTRUCT_PTR_HPP

#include <streams_boost/assert.hpp>
#include <streams_boost/checked_delete.hpp>
#include <streams_boost/signals2/postconstructible.hpp>
#include <streams_boost/signals2/predestructible.hpp>
#include <streams_boost/shared_ptr.hpp>

namespace streams_boost
{
  namespace signals2
  {
    namespace detail
    {
      extern inline void do_postconstruct(const postconstructible *ptr)
      {
        postconstructible *nonconst_ptr = const_cast<postconstructible*>(ptr);
        nonconst_ptr->postconstruct();
      }
      extern inline void do_postconstruct(...)
      {
      }
      extern inline void do_predestruct(...)
      {
      }
      extern inline void do_predestruct(const predestructible *ptr)
      {
        try
        {
          predestructible *nonconst_ptr = const_cast<predestructible*>(ptr);
          nonconst_ptr->predestruct();
        }
        catch(...)
        {
          STREAMS_BOOST_ASSERT(false);
        }
      }
    }

    template<typename T> class predestructing_deleter
    {
    public:
      void operator()(const T *ptr) const
      {
        detail::do_predestruct(ptr);
        checked_delete(ptr);
      }
    };

    template<typename T>
    shared_ptr<T> deconstruct_ptr(T *ptr)
    {
      if(ptr == 0) return shared_ptr<T>(ptr);
      shared_ptr<T> shared(ptr, streams_boost::signals2::predestructing_deleter<T>());
      detail::do_postconstruct(ptr);
      return shared;
    }
    template<typename T, typename D>
    shared_ptr<T> deconstruct_ptr(T *ptr, D deleter)
    {
      shared_ptr<T> shared(ptr, deleter);
      if(ptr == 0) return shared;
      detail::do_postconstruct(ptr);
      return shared;
    }
  }
}

#endif // STREAMS_BOOST_SIGNALS2_DECONSTRUCT_PTR_HPP
