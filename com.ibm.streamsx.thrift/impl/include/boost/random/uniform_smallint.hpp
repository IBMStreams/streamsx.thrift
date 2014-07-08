/* streams_boost random/uniform_smallint.hpp header file
 *
 * Copyright Jens Maurer 2000-2001
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.streams_boost.org/LICENSE_1_0.txt)
 *
 * See http://www.streams_boost.org for most recent version including documentation.
 *
 * $Id: uniform_smallint.hpp 52492 2009-04-19 14:55:57Z steven_watanabe $
 *
 * Revision history
 *  2001-04-08  added min<max assertion (N. Becker)
 *  2001-02-18  moved to individual header files
 */

#ifndef STREAMS_BOOST_RANDOM_UNIFORM_SMALLINT_HPP
#define STREAMS_BOOST_RANDOM_UNIFORM_SMALLINT_HPP

#include <cassert>
#include <iostream>
#include <streams_boost/config.hpp>
#include <streams_boost/limits.hpp>
#include <streams_boost/static_assert.hpp>
#include <streams_boost/random/detail/config.hpp>
#include <streams_boost/random/uniform_01.hpp>
#include <streams_boost/detail/workaround.hpp>

namespace streams_boost {

// uniform integer distribution on a small range [min, max]

template<class IntType = int>
class uniform_smallint
{
public:
  typedef IntType input_type;
  typedef IntType result_type;

  explicit uniform_smallint(IntType min_arg = 0, IntType max_arg = 9)
    : _min(min_arg), _max(max_arg)
  {
#ifndef STREAMS_BOOST_NO_LIMITS_COMPILE_TIME_CONSTANTS
    // MSVC fails STREAMS_BOOST_STATIC_ASSERT with std::numeric_limits at class scope
    STREAMS_BOOST_STATIC_ASSERT(std::numeric_limits<IntType>::is_integer);
#endif
 }

  result_type min STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION () const { return _min; }
  result_type max STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION () const { return _max; }
  void reset() { }

  template<class Engine>
  result_type operator()(Engine& eng)
  {
    typedef typename Engine::result_type base_result;
    base_result _range = static_cast<base_result>(_max-_min)+1;
    base_result _factor = 1;
    
    // LCGs get bad when only taking the low bits.
    // (probably put this logic into a partial template specialization)
    // Check how many low bits we can ignore before we get too much
    // quantization error.
    base_result r_base = (eng.max)() - (eng.min)();
    if(r_base == (std::numeric_limits<base_result>::max)()) {
      _factor = 2;
      r_base /= 2;
    }
    r_base += 1;
    if(r_base % _range == 0) {
      // No quantization effects, good
      _factor = r_base / _range;
    } else {
      // carefully avoid overflow; pessimizing here
      for( ; r_base/_range/32 >= _range; _factor *= 2)
        r_base /= 2;
    }

    return ((eng() - (eng.min)()) / _factor) % _range + _min;
  }

#ifndef STREAMS_BOOST_RANDOM_NO_STREAM_OPERATORS
  template<class CharT, class Traits>
  friend std::basic_ostream<CharT,Traits>&
  operator<<(std::basic_ostream<CharT,Traits>& os, const uniform_smallint& ud)
  {
    os << ud._min << " " << ud._max;
    return os;
  }

  template<class CharT, class Traits>
  friend std::basic_istream<CharT,Traits>&
  operator>>(std::basic_istream<CharT,Traits>& is, uniform_smallint& ud)
  {
    is >> std::ws >> ud._min >> std::ws >> ud._max;
    return is;
  }
#endif

private:

  result_type _min;
  result_type _max;
};

} // namespace streams_boost

#endif // STREAMS_BOOST_RANDOM_UNIFORM_SMALLINT_HPP
