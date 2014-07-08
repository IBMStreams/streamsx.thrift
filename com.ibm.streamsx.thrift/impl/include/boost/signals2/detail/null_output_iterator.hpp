/*
  An output iterator which simply discards output.
*/
// Copyright Frank Mori Hess 2008.
// Distributed under the Boost Software License, Version
// 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

// See http://www.streams_boost.org/libs/signals2 for library home page.

#ifndef STREAMS_BOOST_SIGNALS2_NULL_OUTPUT_ITERATOR_HPP
#define STREAMS_BOOST_SIGNALS2_NULL_OUTPUT_ITERATOR_HPP

#include <streams_boost/function_output_iterator.hpp>

namespace streams_boost
{
  namespace signals2
  {
    namespace detail
    {
      class does_nothing
      {
      public:
        template<typename T>
          void operator()(const T&) const
          {}
      };
      typedef streams_boost::function_output_iterator<does_nothing> null_output_iterator;
    } // namespace detail
  } // namespace signals2
} // namespace streams_boost

#endif  // STREAMS_BOOST_SIGNALS2_NULL_OUTPUT_ITERATOR_HPP
