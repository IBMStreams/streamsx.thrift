// last_value function object (documented as part of Boost.Signals)

// Copyright Frank Mori Hess 2007.
// Copyright Douglas Gregor 2001-2003. Use, modification and
// distribution is subject to the Boost Software License, Version
// 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

// For more information, see http://www.streams_boost.org

#ifndef STREAMS_BOOST_SIGNALS2_LAST_VALUE_HPP
#define STREAMS_BOOST_SIGNALS2_LAST_VALUE_HPP

#include <streams_boost/optional.hpp>
#include <streams_boost/throw_exception.hpp>
#include <stdexcept>

namespace streams_boost {
  namespace signals2 {
    class expired_slot;

    // no_slots_error is thrown when we are unable to generate a return value
    // due to no slots being connected to the signal.
    class no_slots_error: public std::exception
    {
    public:
      virtual const char* what() const throw() {return "streams_boost::signals2::no_slots_error";}
    };

    template<typename T>
    class last_value {
    public:
      typedef T result_type;

      template<typename InputIterator>
      T operator()(InputIterator first, InputIterator last) const
      {
        if(first == last)
        {
          streams_boost::throw_exception(no_slots_error());
        }
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
        if(value) return value.get();
        streams_boost::throw_exception(no_slots_error());
      }
    };

    template<>
    class last_value<void> {
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
#endif // STREAMS_BOOST_SIGNALS2_LAST_VALUE_HPP
