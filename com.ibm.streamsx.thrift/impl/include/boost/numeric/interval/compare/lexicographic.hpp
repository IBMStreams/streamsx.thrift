/* Boost interval/compare/lexicographic.hpp template implementation file
 *
 * Copyright 2002-2003 Guillaume Melquiond
 *
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or
 * copy at http://www.streams_boost.org/LICENSE_1_0.txt)
 */

#ifndef STREAMS_BOOST_NUMERIC_INTERVAL_COMPARE_LEXICOGRAPHIC_HPP
#define STREAMS_BOOST_NUMERIC_INTERVAL_COMPARE_LEXICOGRAPHIC_HPP

#include <streams_boost/numeric/interval/detail/interval_prototype.hpp>
#include <streams_boost/numeric/interval/detail/test_input.hpp>

namespace streams_boost {
namespace numeric {
namespace interval_lib {
namespace compare {
namespace lexicographic {

template<class T, class Policies1, class Policies2> inline
bool operator<(const interval<T, Policies1>& x, const interval<T, Policies2>& y)
{
  if (detail::test_input(x, y)) throw comparison_error();
  const T& xl = x.lower();
  const T& yl = y.lower();
  return xl < yl || (xl == yl && x.upper() < y.upper());
}

template<class T, class Policies> inline
bool operator<(const interval<T, Policies>& x, const T& y)
{
  if (detail::test_input(x, y)) throw comparison_error();
  return x.lower() < y;
}

template<class T, class Policies1, class Policies2> inline
bool operator<=(const interval<T, Policies1>& x, const interval<T, Policies2>& y)
{
  if (detail::test_input(x, y)) throw comparison_error();
  const T& xl = x.lower();
  const T& yl = y.lower();
  return xl < yl || (xl == yl && x.upper() <= y.upper());
}

template<class T, class Policies> inline
bool operator<=(const interval<T, Policies>& x, const T& y)
{
  if (detail::test_input(x, y)) throw comparison_error();
  const T& xl = x.lower();
  return xl < y || (xl == y && x.upper() <= y);
}

template<class T, class Policies1, class Policies2> inline
bool operator>(const interval<T, Policies1>& x, const interval<T, Policies2>& y)
{
  if (detail::test_input(x, y)) throw comparison_error();
  const T& xl = x.lower();
  const T& yl = y.lower();
  return xl > yl || (xl == yl && x.upper() > y.upper());
}

template<class T, class Policies> inline
bool operator>(const interval<T, Policies>& x, const T& y)
{
  if (detail::test_input(x, y)) throw comparison_error();
  const T& xl = x.lower();
  return xl > y || (xl == y && x.upper() > y);
}

template<class T, class Policies1, class Policies2> inline
bool operator>=(const interval<T, Policies1>& x, const interval<T, Policies2>& y)
{
  if (detail::test_input(x, y)) throw comparison_error();
  const T& xl = x.lower();
  const T& yl = y.lower();
  return xl > yl || (xl == yl && x.upper() >= y.upper());
}

template<class T, class Policies> inline
bool operator>=(const interval<T, Policies>& x, const T& y)
{
  if (detail::test_input(x, y)) throw comparison_error();
  return x.lower() >= y;
}

template<class T, class Policies1, class Policies2> inline
bool operator==(const interval<T, Policies1>& x, const interval<T, Policies2>& y)
{
  if (detail::test_input(x, y)) throw comparison_error();
  return x.lower() == y.lower() && x.upper() == y.upper();
}

template<class T, class Policies> inline
bool operator==(const interval<T, Policies>& x, const T& y)
{
  if (detail::test_input(x, y)) throw comparison_error();
  return x.lower() == y && x.upper() == y;
}

template<class T, class Policies1, class Policies2> inline
bool operator!=(const interval<T, Policies1>& x, const interval<T, Policies2>& y)
{
  if (detail::test_input(x, y)) throw comparison_error();
  return x.lower() != y.lower() || x.upper() != y.upper();
}

template<class T, class Policies> inline
bool operator!=(const interval<T, Policies>& x, const T& y)
{
  if (detail::test_input(x, y)) throw comparison_error();
  return x.lower() != y || x.upper() != y;
}

} // namespace lexicographic
} // namespace compare
} // namespace interval_lib
} // namespace numeric
} // namespace streams_boost

#endif // STREAMS_BOOST_NUMERIC_INTERVAL_COMPARE_LEXICOGRAPHIC_HPP
