/* Boost interval/rounded_transc.hpp template implementation file
 *
 * Copyright 2002-2003 Hervé Brönnimann, Guillaume Melquiond, Sylvain Pion
 *
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or
 * copy at http://www.streams_boost.org/LICENSE_1_0.txt)
 */

#ifndef STREAMS_BOOST_NUMERIC_INTERVAL_ROUNDED_TRANSC_HPP
#define STREAMS_BOOST_NUMERIC_INTERVAL_ROUNDED_TRANSC_HPP

#include <streams_boost/numeric/interval/rounding.hpp>
#include <streams_boost/numeric/interval/detail/bugs.hpp>
#include <streams_boost/config/no_tr1/cmath.hpp>

namespace streams_boost {
namespace numeric {
namespace interval_lib {

template<class T, class Rounding>
struct rounded_transc_exact: Rounding
{
# define STREAMS_BOOST_NUMERIC_INTERVAL_new_func(f) \
    T f##_down(const T& x) { STREAMS_BOOST_NUMERIC_INTERVAL_using_math(f); return f(x); } \
    T f##_up  (const T& x) { STREAMS_BOOST_NUMERIC_INTERVAL_using_math(f); return f(x); }
  STREAMS_BOOST_NUMERIC_INTERVAL_new_func(exp)
  STREAMS_BOOST_NUMERIC_INTERVAL_new_func(log)
  STREAMS_BOOST_NUMERIC_INTERVAL_new_func(sin)
  STREAMS_BOOST_NUMERIC_INTERVAL_new_func(cos)
  STREAMS_BOOST_NUMERIC_INTERVAL_new_func(tan)
  STREAMS_BOOST_NUMERIC_INTERVAL_new_func(asin)
  STREAMS_BOOST_NUMERIC_INTERVAL_new_func(acos)
  STREAMS_BOOST_NUMERIC_INTERVAL_new_func(atan)
  STREAMS_BOOST_NUMERIC_INTERVAL_new_func(sinh)
  STREAMS_BOOST_NUMERIC_INTERVAL_new_func(cosh)
  STREAMS_BOOST_NUMERIC_INTERVAL_new_func(tanh)
# undef STREAMS_BOOST_NUMERIC_INTERVAL_new_func
# define STREAMS_BOOST_NUMERIC_INTERVAL_new_func(f) \
    T f##_down(const T& x) { STREAMS_BOOST_NUMERIC_INTERVAL_using_ahyp(f); return f(x); } \
    T f##_up  (const T& x) { STREAMS_BOOST_NUMERIC_INTERVAL_using_ahyp(f); return f(x); }
  STREAMS_BOOST_NUMERIC_INTERVAL_new_func(asinh)
  STREAMS_BOOST_NUMERIC_INTERVAL_new_func(acosh)
  STREAMS_BOOST_NUMERIC_INTERVAL_new_func(atanh)
# undef STREAMS_BOOST_NUMERIC_INTERVAL_new_func
};
  
template<class T, class Rounding>
struct rounded_transc_std: Rounding
{
# define STREAMS_BOOST_NUMERIC_INTERVAL_new_func(f) \
    T f##_down(const T& x) \
    { STREAMS_BOOST_NUMERIC_INTERVAL_using_math(f); \
      this->downward(); return this->force_rounding(f(x)); } \
    T f##_up  (const T& x) \
    { STREAMS_BOOST_NUMERIC_INTERVAL_using_math(f); \
      this->upward(); return this->force_rounding(f(x)); }
  STREAMS_BOOST_NUMERIC_INTERVAL_new_func(exp)
  STREAMS_BOOST_NUMERIC_INTERVAL_new_func(log)
  STREAMS_BOOST_NUMERIC_INTERVAL_new_func(sin)
  STREAMS_BOOST_NUMERIC_INTERVAL_new_func(cos)
  STREAMS_BOOST_NUMERIC_INTERVAL_new_func(tan)
  STREAMS_BOOST_NUMERIC_INTERVAL_new_func(asin)
  STREAMS_BOOST_NUMERIC_INTERVAL_new_func(acos)
  STREAMS_BOOST_NUMERIC_INTERVAL_new_func(atan)
  STREAMS_BOOST_NUMERIC_INTERVAL_new_func(sinh)
  STREAMS_BOOST_NUMERIC_INTERVAL_new_func(cosh)
  STREAMS_BOOST_NUMERIC_INTERVAL_new_func(tanh)
# undef STREAMS_BOOST_NUMERIC_INTERVAL_new_func
# define STREAMS_BOOST_NUMERIC_INTERVAL_new_func(f) \
    T f##_down(const T& x) \
    { STREAMS_BOOST_NUMERIC_INTERVAL_using_ahyp(f); \
      this->downward(); return this->force_rounding(f(x)); } \
    T f##_up  (const T& x) \
    { STREAMS_BOOST_NUMERIC_INTERVAL_using_ahyp(f); \
      this->upward(); return this->force_rounding(f(x)); }
  STREAMS_BOOST_NUMERIC_INTERVAL_new_func(asinh)
  STREAMS_BOOST_NUMERIC_INTERVAL_new_func(acosh)
  STREAMS_BOOST_NUMERIC_INTERVAL_new_func(atanh)
# undef STREAMS_BOOST_NUMERIC_INTERVAL_new_func
};

template<class T, class Rounding>
struct rounded_transc_opp: Rounding
{
# define STREAMS_BOOST_NUMERIC_INTERVAL_new_func(f) \
    T f##_down(const T& x) \
    { STREAMS_BOOST_NUMERIC_INTERVAL_using_math(f); \
      this->downward(); T y = this->force_rounding(f(x)); \
      this->upward(); return y; } \
    T f##_up  (const T& x) \
    { STREAMS_BOOST_NUMERIC_INTERVAL_using_math(f); \
      return this->force_rounding(f(x)); }
  STREAMS_BOOST_NUMERIC_INTERVAL_new_func(exp)
  STREAMS_BOOST_NUMERIC_INTERVAL_new_func(log)
  STREAMS_BOOST_NUMERIC_INTERVAL_new_func(cos)
  STREAMS_BOOST_NUMERIC_INTERVAL_new_func(acos)
  STREAMS_BOOST_NUMERIC_INTERVAL_new_func(cosh)
# undef STREAMS_BOOST_NUMERIC_INTERVAL_new_func
# define STREAMS_BOOST_NUMERIC_INTERVAL_new_func(f) \
    T f##_down(const T& x) \
    { STREAMS_BOOST_NUMERIC_INTERVAL_using_math(f); \
      return -this->force_rounding(-f(x)); } \
    T f##_up  (const T& x) \
    { STREAMS_BOOST_NUMERIC_INTERVAL_using_math(f); \
      return this->force_rounding(f(x)); }
  STREAMS_BOOST_NUMERIC_INTERVAL_new_func(sin)
  STREAMS_BOOST_NUMERIC_INTERVAL_new_func(tan)
  STREAMS_BOOST_NUMERIC_INTERVAL_new_func(asin)
  STREAMS_BOOST_NUMERIC_INTERVAL_new_func(atan)
  STREAMS_BOOST_NUMERIC_INTERVAL_new_func(sinh)
  STREAMS_BOOST_NUMERIC_INTERVAL_new_func(tanh)
# undef STREAMS_BOOST_NUMERIC_INTERVAL_new_func
# define STREAMS_BOOST_NUMERIC_INTERVAL_new_func(f) \
    T f##_down(const T& x) \
    { STREAMS_BOOST_NUMERIC_INTERVAL_using_ahyp(f); \
      this->downward(); T y = this->force_rounding(f(x)); \
      this->upward(); return y; } \
    T f##_up  (const T& x) \
    { STREAMS_BOOST_NUMERIC_INTERVAL_using_ahyp(f); \
      return this->force_rounding(f(x)); }
  STREAMS_BOOST_NUMERIC_INTERVAL_new_func(asinh)
  STREAMS_BOOST_NUMERIC_INTERVAL_new_func(atanh)
# undef STREAMS_BOOST_NUMERIC_INTERVAL_new_func
# define STREAMS_BOOST_NUMERIC_INTERVAL_new_func(f) \
    T f##_down(const T& x) \
    { STREAMS_BOOST_NUMERIC_INTERVAL_using_ahyp(f); \
      return -this->force_rounding(-f(x)); } \
    T f##_up  (const T& x) \
    { STREAMS_BOOST_NUMERIC_INTERVAL_using_ahyp(f); \
      return this->force_rounding(f(x)); }
  STREAMS_BOOST_NUMERIC_INTERVAL_new_func(acosh)
# undef STREAMS_BOOST_NUMERIC_INTERVAL_new_func
};
  
} // namespace interval_lib
} // namespace numeric
} // namespace streams_boost

#endif // STREAMS_BOOST_NUMERIC_INTERVAL_ROUNDED_TRANSC_HPP
