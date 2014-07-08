/* Boost interval/detail/test_input.hpp file
 *
 * Copyright 2002 Herv� Br�nnimann, Guillaume Melquiond, Sylvain Pion
 *
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or
 * copy at http://www.streams_boost.org/LICENSE_1_0.txt)
 */

#ifndef STREAMS_BOOST_NUMERIC_INTERVAL_DETAIL_TEST_INPUT_HPP
#define STREAMS_BOOST_NUMERIC_INTERVAL_DETAIL_TEST_INPUT_HPP

#include <streams_boost/numeric/interval/detail/interval_prototype.hpp>

namespace streams_boost {
namespace numeric {
namespace interval_lib {
namespace user {

template<class T> inline
bool is_zero(T const &v) { return v == static_cast<T>(0); }

template<class T> inline
bool is_neg (T const &v) { return v <  static_cast<T>(0); }

template<class T> inline
bool is_pos (T const &v) { return v >  static_cast<T>(0); }

} // namespace user

namespace detail {

template<class T, class Policies> inline
bool test_input(const interval<T, Policies>& x) {
  typedef typename Policies::checking checking;
  return checking::is_empty(x.lower(), x.upper());
}

template<class T, class Policies1, class Policies2> inline
bool test_input(const interval<T, Policies1>& x, const interval<T, Policies2>& y) {
  typedef typename Policies1::checking checking1;
  typedef typename Policies2::checking checking2;
  return checking1::is_empty(x.lower(), x.upper()) ||
         checking2::is_empty(y.lower(), y.upper());
}

template<class T, class Policies> inline
bool test_input(const T& x, const interval<T, Policies>& y) {
  typedef typename Policies::checking checking;
  return checking::is_nan(x) || checking::is_empty(y.lower(), y.upper());
}

template<class T, class Policies> inline
bool test_input(const interval<T, Policies>& x, const T& y) {
  typedef typename Policies::checking checking;
  return checking::is_empty(x.lower(), x.upper()) || checking::is_nan(y);
}

template<class T, class Policies> inline
bool test_input(const T& x) {
  typedef typename Policies::checking checking;
  return checking::is_nan(x);
}

template<class T, class Policies> inline
bool test_input(const T& x, const T& y) {
  typedef typename Policies::checking checking;
  return checking::is_nan(x) || checking::is_nan(y);
}

} // namespace detail
} // namespace interval_lib
} // namespace numeric
} // namespace streams_boost

#endif // STREAMS_BOOST_NUMERIC_INTERVAL_DETAIL_TEST_INPUT_HPP
