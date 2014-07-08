/* streams_boost random/shuffle_output.hpp header file
 *
 * Copyright Jens Maurer 2000-2001
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.streams_boost.org/LICENSE_1_0.txt)
 *
 * See http://www.streams_boost.org for most recent version including documentation.
 *
 * $Id: shuffle_output.hpp 52492 2009-04-19 14:55:57Z steven_watanabe $
 *
 * Revision history
 *  2001-02-18  moved to individual header files
 */

#ifndef STREAMS_BOOST_RANDOM_SHUFFLE_OUTPUT_HPP
#define STREAMS_BOOST_RANDOM_SHUFFLE_OUTPUT_HPP

#include <iostream>
#include <algorithm>     // std::copy
#include <cassert>
#include <streams_boost/config.hpp>
#include <streams_boost/limits.hpp>
#include <streams_boost/static_assert.hpp>
#include <streams_boost/cstdint.hpp>
#include <streams_boost/random/linear_congruential.hpp>

namespace streams_boost {
namespace random {

// Carter Bays and S.D. Durham 1979
template<class UniformRandomNumberGenerator, int k,
#ifndef STREAMS_BOOST_NO_DEPENDENT_TYPES_IN_TEMPLATE_VALUE_PARAMETERS
  typename UniformRandomNumberGenerator::result_type 
#else
  uint32_t
#endif
  val = 0>
class shuffle_output
{
public:
  typedef UniformRandomNumberGenerator base_type;
  typedef typename base_type::result_type result_type;

  STREAMS_BOOST_STATIC_CONSTANT(bool, has_fixed_range = false);
  STREAMS_BOOST_STATIC_CONSTANT(int, buffer_size = k);

  shuffle_output() : _rng() { init(); }
#if defined(STREAMS_BOOST_MSVC) && _MSC_VER < 1300
  // MSVC does not implicitly generate the copy constructor here
  shuffle_output(const shuffle_output & x)
    : _rng(x._rng), y(x.y) { std::copy(x.v, x.v+k, v); }
#endif
  template<class T>
  explicit shuffle_output(T s) : _rng(s) { init(); }
  explicit shuffle_output(const base_type & rng) : _rng(rng) { init(); }
  template<class It> shuffle_output(It& first, It last)
    : _rng(first, last) { init(); }
  void seed() { _rng.seed(); init(); }
  template<class T>
  void seed(T s) { _rng.seed(s); init(); }
  template<class It> void seed(It& first, It last)
  {
    _rng.seed(first, last);
    init();
  }

  const base_type& base() const { return _rng; }

  result_type operator()() {
    // calculating the range every time may seem wasteful.  However, this
    // makes the information locally available for the optimizer.
    result_type range = (max)()-(min)()+1;
    int j = k*(y-(min)())/range;
    // assert(0 <= j && j < k);
    y = v[j];
    v[j] = _rng();
    return y;
  }

  result_type min STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION () const { return (_rng.min)(); }
  result_type max STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION () const { return (_rng.max)(); }
  static bool validation(result_type x) { return val == x; }

#ifndef STREAMS_BOOST_NO_OPERATORS_IN_NAMESPACE

#ifndef STREAMS_BOOST_RANDOM_NO_STREAM_OPERATORS
  template<class CharT, class Traits>
  friend std::basic_ostream<CharT,Traits>&
  operator<<(std::basic_ostream<CharT,Traits>& os, const shuffle_output& s)
  {
    os << s._rng << " " << s.y << " ";
    for(int i = 0; i < s.buffer_size; ++i)
      os << s.v[i] << " ";
    return os;
  }

  template<class CharT, class Traits>
  friend std::basic_istream<CharT,Traits>&
  operator>>(std::basic_istream<CharT,Traits>& is, shuffle_output& s)
  {
    is >> s._rng >> std::ws >> s.y >> std::ws;
    for(int i = 0; i < s.buffer_size; ++i)
      is >> s.v[i] >> std::ws;
    return is;
  }
#endif

  friend bool operator==(const shuffle_output& x, const shuffle_output& y)
  { return x._rng == y._rng && x.y == y.y && std::equal(x.v, x.v+k, y.v); }
  friend bool operator!=(const shuffle_output& x, const shuffle_output& y)
  { return !(x == y); }
#else
  // Use a member function; Streamable concept not supported.
  bool operator==(const shuffle_output& rhs) const
  { return _rng == rhs._rng && y == rhs.y && std::equal(v, v+k, rhs.v); }
  bool operator!=(const shuffle_output& rhs) const
  { return !(*this == rhs); }
#endif
private:
  void init()
  {
#ifndef STREAMS_BOOST_NO_LIMITS_COMPILE_TIME_CONSTANTS
    STREAMS_BOOST_STATIC_ASSERT(std::numeric_limits<result_type>::is_integer);
#endif
    result_type range = (max)()-(min)();
    assert(range > 0);      // otherwise there would be little choice
    if(static_cast<unsigned long>(k * range) < 
       static_cast<unsigned long>(range))  // not a sufficient condition
      // likely overflow with bucket number computation
      assert(!"overflow will occur");

    // we cannot use std::generate, because it uses pass-by-value for _rng
    for(result_type * p = v; p != v+k; ++p)
      *p = _rng();
    y = _rng();
  }

  base_type _rng;
  result_type v[k];
  result_type y;
};

#ifndef STREAMS_BOOST_NO_INCLASS_MEMBER_INITIALIZATION
//  A definition is required even for integral static constants
template<class UniformRandomNumberGenerator, int k, 
#ifndef STREAMS_BOOST_NO_DEPENDENT_TYPES_IN_TEMPLATE_VALUE_PARAMETERS
  typename UniformRandomNumberGenerator::result_type 
#else
  uint32_t
#endif
  val>
const bool shuffle_output<UniformRandomNumberGenerator, k, val>::has_fixed_range;

template<class UniformRandomNumberGenerator, int k, 
#ifndef STREAMS_BOOST_NO_DEPENDENT_TYPES_IN_TEMPLATE_VALUE_PARAMETERS
  typename UniformRandomNumberGenerator::result_type 
#else
  uint32_t
#endif
  val>
const int shuffle_output<UniformRandomNumberGenerator, k, val>::buffer_size;
#endif

} // namespace random

// validation by experiment from Harry Erwin's generator.h (private e-mail)
typedef random::shuffle_output<
    random::linear_congruential<uint32_t, 1366, 150889, 714025, 0>,
  97, 139726> kreutzer1986;


} // namespace streams_boost

#endif // STREAMS_BOOST_RANDOM_SHUFFLE_OUTPUT_HPP
