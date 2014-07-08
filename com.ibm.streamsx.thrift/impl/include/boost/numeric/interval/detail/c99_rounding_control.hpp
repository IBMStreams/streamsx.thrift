/* Boost interval/detail/c99_rounding_control.hpp file
 *
 * Copyright 2000 Jens Maurer
 * Copyright 2002 Hervé Brönnimann, Guillaume Melquiond, Sylvain Pion
 *
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or
 * copy at http://www.streams_boost.org/LICENSE_1_0.txt)
 */

#ifndef STREAMS_BOOST_NUMERIC_INTERVAL_DETAIL_C99_ROUNDING_CONTROL_HPP
#define STREAMS_BOOST_NUMERIC_INTERVAL_DETAIL_C99_ROUNDING_CONTROL_HPP

#include <streams_boost/numeric/interval/detail/c99sub_rounding_control.hpp>

namespace streams_boost {
namespace numeric {
namespace interval_lib {
namespace detail {

struct c99_rounding_control: c99_rounding
{
  template<class T>
  static T force_rounding(const T& r) { volatile T r_ = r; return r_; }
};

} // namespace detail

template<>
struct rounding_control<float>:
  detail::c99_rounding_control { };

template<>
struct rounding_control<double>:
  detail::c99_rounding_control { };

template<>
struct rounding_control<long double>:
  detail::c99_rounding_control { };

} // namespace interval_lib
} // namespace numeric
} // namespace streams_boost

#undef STREAMS_BOOST_NUMERIC_INTERVAL_NO_HARDWARE

#endif // STREAMS_BOOST_NUMERIC_INTERVAL_DETAIL_C99_ROUNDING_CONTROL_HPP
