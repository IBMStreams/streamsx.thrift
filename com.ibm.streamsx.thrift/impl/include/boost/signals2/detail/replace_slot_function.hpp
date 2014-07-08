// Copyright Frank Mori Hess 2007-2009
//
// Use, modification and
// distribution is subject to the Boost Software License, Version
// 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

// For more information, see http://www.streams_boost.org

#ifndef STREAMS_BOOST_SIGNALS2_DETAIL_REPLACE_SLOT_FUNCTION_HPP
#define STREAMS_BOOST_SIGNALS2_DETAIL_REPLACE_SLOT_FUNCTION_HPP

#include <streams_boost/signals2/slot_base.hpp>

namespace streams_boost
{
  namespace signals2
  {
    namespace detail
    {
      template<typename ResultSlot, typename SlotIn, typename SlotFunction>
        ResultSlot replace_slot_function(const SlotIn &slot_in, const SlotFunction &fun)
      {
        ResultSlot slot(fun);
        slot_base::tracked_container_type tracked_objects = slot_in.tracked_objects();
        slot_base::tracked_container_type::const_iterator it;
        for(it = tracked_objects.begin(); it != tracked_objects.end(); ++it)
        {
          slot.track(*it);
        }
        return slot;
      }
    } // namespace detail
  } // namespace signals2
} // namespace streams_boost

#endif // STREAMS_BOOST_SIGNALS2_DETAIL_REPLACE_SLOT_FUNCTION_HPP
