/* streams_boost random/tausworthe.hpp header file
 *
 * Copyright Jens Maurer 2002
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.streams_boost.org/LICENSE_1_0.txt)
 *
 * See http://www.streams_boost.org for most recent version including documentation.
 *
 * $Id: linear_feedback_shift.hpp 58649 2010-01-02 21:23:17Z steven_watanabe $
 *
 */

#ifndef STREAMS_BOOST_RANDOM_LINEAR_FEEDBACK_SHIFT_HPP
#define STREAMS_BOOST_RANDOM_LINEAR_FEEDBACK_SHIFT_HPP

#include <iostream>
#include <cassert>
#include <stdexcept>
#include <streams_boost/config.hpp>
#include <streams_boost/static_assert.hpp>
#include <streams_boost/limits.hpp>
#include <streams_boost/random/detail/config.hpp>

namespace streams_boost {
namespace random {

// Tausworte 1965
template<class UIntType, int w, int k, int q, int s, UIntType val>
class linear_feedback_shift
{
public:
  typedef UIntType result_type;
  // avoid the warning trouble when using (1<<w) on 32 bit machines
  STREAMS_BOOST_STATIC_CONSTANT(bool, has_fixed_range = false);
  STREAMS_BOOST_STATIC_CONSTANT(int, word_size = w);
  STREAMS_BOOST_STATIC_CONSTANT(int, exponent1 = k);
  STREAMS_BOOST_STATIC_CONSTANT(int, exponent2 = q);
  STREAMS_BOOST_STATIC_CONSTANT(int, step_size = s);

  result_type min STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION () const { return 0; }
  result_type max STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION () const { return wordmask; }

  // MSVC 6 and possibly others crash when encountering complicated integral
  // constant expressions.  Avoid the checks for now.
  // STREAMS_BOOST_STATIC_ASSERT(w > 0);
  // STREAMS_BOOST_STATIC_ASSERT(q > 0);
  // STREAMS_BOOST_STATIC_ASSERT(k < w);
  // STREAMS_BOOST_STATIC_ASSERT(0 < 2*q && 2*q < k);
  // STREAMS_BOOST_STATIC_ASSERT(0 < s && s <= k-q);

  explicit linear_feedback_shift(UIntType s0 = 341) : wordmask(0)
  {
    // MSVC fails STREAMS_BOOST_STATIC_ASSERT with std::numeric_limits at class scope
#ifndef STREAMS_BOOST_NO_LIMITS_COMPILE_TIME_CONSTANTS
    STREAMS_BOOST_STATIC_ASSERT(std::numeric_limits<UIntType>::is_integer);
    STREAMS_BOOST_STATIC_ASSERT(!std::numeric_limits<UIntType>::is_signed);
#endif

    // avoid "left shift count >= with of type" warning
    for(int i = 0; i < w; ++i)
      wordmask |= (1u << i);
    seed(s0);
  }

  template<class It> linear_feedback_shift(It& first, It last) : wordmask(0)
  {
    // MSVC fails STREAMS_BOOST_STATIC_ASSERT with std::numeric_limits at class scope
#ifndef STREAMS_BOOST_NO_LIMITS_COMPILE_TIME_CONSTANTS
    STREAMS_BOOST_STATIC_ASSERT(std::numeric_limits<UIntType>::is_integer);
    STREAMS_BOOST_STATIC_ASSERT(!std::numeric_limits<UIntType>::is_signed);
#endif

    // avoid "left shift count >= with of type" warning
    for(int i = 0; i < w; ++i)
      wordmask |= (1u << i);
    seed(first, last);
  }

  void seed(UIntType s0 = 341) {
      if(s0 < (1 << (w-k))) {
          s0 += 1 << (w-k);
      }
      value = s0;
  }
  template<class It> void seed(It& first, It last)
  {
    if(first == last)
      throw std::invalid_argument("linear_feedback_shift::seed");
    value = *first++;
    assert(value >= (1 << (w-k)));
  }

  result_type operator()()
  {
    const UIntType b = (((value << q) ^ value) & wordmask) >> (k-s);
    const UIntType mask = ( (~static_cast<UIntType>(0)) << (w-k) ) & wordmask;
    value = ((value & mask) << s) ^ b;
    return value;
  }
  static bool validation(result_type x) { return val == x; }

#ifndef STREAMS_BOOST_NO_OPERATORS_IN_NAMESPACE

#ifndef STREAMS_BOOST_RANDOM_NO_STREAM_OPERATORS
  template<class CharT, class Traits>
  friend std::basic_ostream<CharT,Traits>&
  operator<<(std::basic_ostream<CharT,Traits>& os, linear_feedback_shift x)
  { os << x.value; return os; }

  template<class CharT, class Traits>
  friend std::basic_istream<CharT,Traits>&
  operator>>(std::basic_istream<CharT,Traits>& is, linear_feedback_shift& x)
  { is >> x.value; return is; }
#endif

  friend bool operator==(linear_feedback_shift x, linear_feedback_shift y)
  { return x.value == y.value; }
  friend bool operator!=(linear_feedback_shift x, linear_feedback_shift y)
  { return !(x == y); }
#else
  // Use a member function; Streamable concept not supported.
  bool operator==(linear_feedback_shift rhs) const
  { return value == rhs.value; }
  bool operator!=(linear_feedback_shift rhs) const
  { return !(*this == rhs); }
#endif

private:
  UIntType wordmask; // avoid "left shift count >= width of type" warnings
  UIntType value;
};

#ifndef STREAMS_BOOST_NO_INCLASS_MEMBER_INITIALIZATION
//  A definition is required even for integral static constants
template<class UIntType, int w, int k, int q, int s, UIntType val>
const bool linear_feedback_shift<UIntType, w, k, q, s, val>::has_fixed_range;
template<class UIntType, int w, int k, int q, int s, UIntType val>
const int linear_feedback_shift<UIntType, w, k, q, s, val>::word_size;
template<class UIntType, int w, int k, int q, int s, UIntType val>
const int linear_feedback_shift<UIntType, w, k, q, s, val>::exponent1;
template<class UIntType, int w, int k, int q, int s, UIntType val>
const int linear_feedback_shift<UIntType, w, k, q, s, val>::exponent2;
template<class UIntType, int w, int k, int q, int s, UIntType val>
const int linear_feedback_shift<UIntType, w, k, q, s, val>::step_size;
#endif

} // namespace random
} // namespace streams_boost

#endif // STREAMS_BOOST_RANDOM_LINEAR_FEEDBACK_SHIFT_HPP
