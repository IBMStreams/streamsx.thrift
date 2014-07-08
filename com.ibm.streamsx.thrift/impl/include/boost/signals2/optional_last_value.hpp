// optional_last_value function object (documented as part of Boost.Signals2)

// Copyright Frank Mori Hess 2007-2008.
// Copyright Douglas Gregor 2001-2003.
// Distributed under the Boost Software License, Version
// 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

// See http://www.streams_boost.org/libs/signals2 for library home page.

#ifndef STREAMS_BOOST_SIGNALS2_OPTIONAL_LAST_VALUE_HPP
#define STREAMS_BOOST_SIGNALS2_OPTIONAL_LAST_VALUE_HPP

#include <streams_boost/optional.hpp>

namespace streams_boost {
  namespace signals2 {
    class expired_slot;

    template<typename T>
      class optional_last_value
    {
    public:
      typedef optional<T> result_type;

      template<typename InputIterator>
        optional<T> operator()(InputIterator first, InputIterator last) const
      {
        optional<T> value;
        while (first != last)
        {
          try
          {
            value = *first;
          }
          catch(const expired_slot &) {}
          ++first;
        }
        return value;
      }
    };

    template<>
      class optional_last_value<void>
    {
    public:
      typedef void result_type;
      template<typename InputIterator>
        result_type operator()(InputIterator first, InputIterator last) const
      {
        while (first != last)
        {
          try
          {
            *first;
          }
          catch(const expired_slot &) {}
          ++first;
        }
        return;
      }
    };
  } // namespace signals2
} // namespace streams_boost
#endif // STREAMS_BOOST_SIGNALS2_OPTIONAL_LAST_VALUE_HPP