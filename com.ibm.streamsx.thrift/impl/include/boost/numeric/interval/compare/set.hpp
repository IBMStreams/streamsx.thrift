/* Boost interval/compare/set.hpp template implementation file
 *
 * Copyright 2002-2003 Guillaume Melquiond
 *
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or
 * copy at http://www.streams_boost.org/LICENSE_1_0.txt)
 */

#ifndef STREAMS_BOOST_NUMERIC_INTERVAL_COMPARE_SET_HPP
#define STREAMS_BOOST_NUMERIC_INTERVAL_COMPARE_SET_HPP

#include <streams_boost/numeric/interval/detail/interval_prototype.hpp>
#include <streams_boost/numeric/interval/detail/test_input.hpp>
#include <streams_boost/numeric/interval/utility.hpp>

namespace streams_boost {
namespace numeric {
namespace interval_lib {
namespace compare {
namespace set {

template<class T, class Policies1, class Policies2> inline
bool operator<(const interval<T, Policies1>& x, const interval<T, Policies2>& y)
{
  return proper_subset(x, y);
}

template<class T, class Policies> inline
bool operator<(const interval<T, Policies>& x, const T& y)
{
  throw comparison_error();
}

template<class T, class Policies1, class Policies2> inline
bool operator<=(const interval<T, Policies1>& x, const interval<T, Policies2>& y)
{
  return subset(x, y);
}

template<class T, class Policies> inline
bool operator<=(const interval<T, Policies>& x, const T& y)
{
  throw comparison_error();
}

template<class T, class Policies1, class Policies2> inline
bool operator>(const interval<T, Policies1>& x, const interval<T, Policies2>& y)
{
  return proper_subset(y, x);
}

template<class T, class Policies> inline
bool operator>(const interval<T, Policies>& x, const T& y)
{
  throw comparison_error();
}

template<class T, class Policies1, class Policies2> inline
bool operator>=(const interval<T, Policies1>& x, const interval<T, Policies2>& y)
{
  return subset(y, x);
}

template<class T, class Policies> inline
bool operator>=(const interval<T, Policies>& x, const T& y)
{
  throw comparison_error();
}

template<class T, class Policies1, class Policies2> inline
bool operator==(const interval<T, Policies1>& x, const interval<T, Policies2>& y)
{
  return equal(y, x);
}

template<class T, class Policies> inline
bool operator==(const interval<T, Policies>& x, const T& y)
{
  throw comparison_error();
}

template<class T, class Policies1, class Policies2> inline
bool operator!=(const interval<T, Policies1>& x, const interval<T, Policies2>& y)
{
  return !equal(y, x);
}

template<class T, class Policies> inline
bool operator!=(const interval<T, Policies>& x, const T& y)
{
  throw comparison_error();
}

} // namespace set
} // namespace compare
} // namespace interval_lib
} // namespace numeric
} // namespace streams_boost

#endif // STREAMS_BOOST_NUMERIC_INTERVAL_COMPARE_SET_HPP
