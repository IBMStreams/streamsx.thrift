/* streams_boost random/inversive_congruential.hpp header file
 *
 * Copyright Jens Maurer 2000-2001
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.streams_boost.org/LICENSE_1_0.txt)
 *
 * See http://www.streams_boost.org for most recent version including documentation.
 *
 * $Id: inversive_congruential.hpp 52492 2009-04-19 14:55:57Z steven_watanabe $
 *
 * Revision history
 *  2001-02-18  moved to individual header files
 */

#ifndef STREAMS_BOOST_RANDOM_INVERSIVE_CONGRUENTIAL_HPP
#define STREAMS_BOOST_RANDOM_INVERSIVE_CONGRUENTIAL_HPP

#include <iostream>
#include <cassert>
#include <stdexcept>
#include <streams_boost/config.hpp>
#include <streams_boost/static_assert.hpp>
#include <streams_boost/random/detail/config.hpp>
#include <streams_boost/random/detail/const_mod.hpp>

namespace streams_boost {
namespace random {

// Eichenauer and Lehn 1986
template<class IntType, IntType a, IntType b, IntType p, IntType val>
class inversive_congruential
{
public:
  typedef IntType result_type;
#ifndef STREAMS_BOOST_NO_INCLASS_MEMBER_INITIALIZATION
  static const bool has_fixed_range = true;
  static const result_type min_value = (b == 0 ? 1 : 0);
  static const result_type max_value = p-1;
#else
  STREAMS_BOOST_STATIC_CONSTANT(bool, has_fixed_range = false);
#endif
  STREAMS_BOOST_STATIC_CONSTANT(result_type, multiplier = a);
  STREAMS_BOOST_STATIC_CONSTANT(result_type, increment = b);
  STREAMS_BOOST_STATIC_CONSTANT(result_type, modulus = p);

  result_type min STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION () const { return b == 0 ? 1 : 0; }
  result_type max STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION () const { return p-1; }

  explicit inversive_congruential(IntType y0 = 1) : value(y0)
  {
    STREAMS_BOOST_STATIC_ASSERT(b >= 0);
    STREAMS_BOOST_STATIC_ASSERT(p > 1);
    STREAMS_BOOST_STATIC_ASSERT(a >= 1);
    if(b == 0) 
      assert(y0 > 0); 
  }
  template<class It> inversive_congruential(It& first, It last)
  { seed(first, last); }

  void seed(IntType y0 = 1) { value = y0; if(b == 0) assert(y0 > 0); }
  template<class It> void seed(It& first, It last)
  {
    if(first == last)
      throw std::invalid_argument("inversive_congruential::seed");
    value = *first++;
  }
  IntType operator()()
  {
    typedef const_mod<IntType, p> do_mod;
    value = do_mod::mult_add(a, do_mod::invert(value), b);
    return value;
  }

  static bool validation(result_type x) { return val == x; }

#ifndef STREAMS_BOOST_NO_OPERATORS_IN_NAMESPACE

#ifndef STREAMS_BOOST_RANDOM_NO_STREAM_OPERATORS
  template<class CharT, class Traits>
  friend std::basic_ostream<CharT,Traits>&
  operator<<(std::basic_ostream<CharT,Traits>& os, inversive_congruential x)
  { os << x.value; return os; }

  template<class CharT, class Traits>
  friend std::basic_istream<CharT,Traits>&
  operator>>(std::basic_istream<CharT,Traits>& is, inversive_congruential& x)
  { is >> x.value; return is; }
#endif

  friend bool operator==(inversive_congruential x, inversive_congruential y)
  { return x.value == y.value; }
  friend bool operator!=(inversive_congruential x, inversive_congruential y)
  { return !(x == y); }
#else
  // Use a member function; Streamable concept not supported.
  bool operator==(inversive_congruential rhs) const
  { return value == rhs.value; }
  bool operator!=(inversive_congruential rhs) const
  { return !(*this == rhs); }
#endif
private:
  IntType value;
};

#ifndef STREAMS_BOOST_NO_INCLASS_MEMBER_INITIALIZATION
//  A definition is required even for integral static constants
template<class IntType, IntType a, IntType b, IntType p, IntType val>
const bool inversive_congruential<IntType, a, b, p, val>::has_fixed_range;
template<class IntType, IntType a, IntType b, IntType p, IntType val>
const typename inversive_congruential<IntType, a, b, p, val>::result_type inversive_congruential<IntType, a, b, p, val>::min_value;
template<class IntType, IntType a, IntType b, IntType p, IntType val>
const typename inversive_congruential<IntType, a, b, p, val>::result_type inversive_congruential<IntType, a, b, p, val>::max_value;
template<class IntType, IntType a, IntType b, IntType p, IntType val>
const typename inversive_congruential<IntType, a, b, p, val>::result_type inversive_congruential<IntType, a, b, p, val>::multiplier;
template<class IntType, IntType a, IntType b, IntType p, IntType val>
const typename inversive_congruential<IntType, a, b, p, val>::result_type inversive_congruential<IntType, a, b, p, val>::increment;
template<class IntType, IntType a, IntType b, IntType p, IntType val>
const typename inversive_congruential<IntType, a, b, p, val>::result_type inversive_congruential<IntType, a, b, p, val>::modulus;
#endif

} // namespace random

typedef random::inversive_congruential<int32_t, 9102, 2147483647-36884165,
  2147483647, 0> hellekalek1995;

} // namespace streams_boost

#endif // STREAMS_BOOST_RANDOM_INVERSIVE_CONGRUENTIAL_HPP
