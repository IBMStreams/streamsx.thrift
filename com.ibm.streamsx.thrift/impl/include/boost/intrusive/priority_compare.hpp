/////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2008
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/intrusive for documentation.
//
/////////////////////////////////////////////////////////////////////////////

#ifndef STREAMS_BOOST_INTRUSIVE_PRIORITY_COMPARE_HPP
#define STREAMS_BOOST_INTRUSIVE_PRIORITY_COMPARE_HPP

#include <streams_boost/intrusive/detail/config_begin.hpp>
#include <streams_boost/intrusive/intrusive_fwd.hpp>

#include <functional>

namespace streams_boost {
namespace intrusive {

template <class T>
struct priority_compare
   : public std::binary_function<T, T, bool>
{
   bool operator()(const T &val, const T &val2) const
   {
      return priority_order(val, val2);
   }
};

} //namespace intrusive 
} //namespace streams_boost 

#include <streams_boost/intrusive/detail/config_end.hpp>

#endif //STREAMS_BOOST_INTRUSIVE_PRIORITY_COMPARE_HPP
