/* Boost interval/ext/integer.hpp template implementation file
 *
 * Copyright 2003 Guillaume Melquiond
 *
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or
 * copy at http://www.streams_boost.org/LICENSE_1_0.txt)
 */

#ifndef STREAMS_BOOST_NUMERIC_INTERVAL_EXT_INTEGER_HPP
#define STREAMS_BOOST_NUMERIC_INTERVAL_EXT_INTEGER_HPP

#include <streams_boost/numeric/interval/detail/interval_prototype.hpp>
#include <streams_boost/numeric/interval/detail/test_input.hpp>

namespace streams_boost {
namespace numeric {

template<class T, class Policies> inline
interval<T, Policies> operator+ (const interval<T, Policies>& x, int y)
{
  return x + static_cast<T>(y);
}

template<class T, class Policies> inline
interval<T, Policies> operator+ (int x, const interval<T, Policies>& y)
{
  return static_cast<T>(x) + y;
}

template<class T, class Policies> inline
interval<T, Policies> operator- (const interval<T, Policies>& x, int y)
{
  return x - static_cast<T>(y);
}

template<class T, class Policies> inline
interval<T, Policies> operator- (int x, const interval<T, Policies>& y)
{
  return static_cast<T>(x) - y;
}

template<class T, class Policies> inline
interval<T, Policies> operator* (const interval<T, Policies>& x, int y)
{
  return x * static_cast<T>(y);
}

template<class T, class Policies> inline
interval<T, Policies> operator* (int x, const interval<T, Policies>& y)
{
  return static_cast<T>(x) * y;
}

template<class T, class Policies> inline
interval<T, Policies> operator/ (const interval<T, Policies>& x, int y)
{
  return x / static_cast<T>(y);
}

template<class T, class Policies> inline
interval<T, Policies> operator/ (int x, const interval<T, Policies>& y)
{
  return static_cast<T>(x) / y;
}

} // namespace numeric
} // namespace streams_boost

#endif // STREAMS_BOOST_NUMERIC_INTERVAL_EXT_INTEGER_HPP
