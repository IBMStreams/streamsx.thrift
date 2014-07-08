/* streams_boost random/uniform_real.hpp header file
 *
 * Copyright Jens Maurer 2000-2001
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.streams_boost.org/LICENSE_1_0.txt)
 *
 * See http://www.streams_boost.org for most recent version including documentation.
 *
 * $Id: uniform_real.hpp 56814 2009-10-14 04:54:01Z steven_watanabe $
 *
 * Revision history
 *  2001-04-08  added min<max assertion (N. Becker)
 *  2001-02-18  moved to individual header files
 */

#ifndef STREAMS_BOOST_RANDOM_UNIFORM_REAL_HPP
#define STREAMS_BOOST_RANDOM_UNIFORM_REAL_HPP

#include <cassert>
#include <iostream>
#include <streams_boost/config.hpp>
#include <streams_boost/limits.hpp>
#include <streams_boost/static_assert.hpp>
#include <streams_boost/random/detail/config.hpp>

namespace streams_boost {

// uniform distribution on a real range
template<class RealType = double>
class uniform_real
{
public:
  typedef RealType input_type;
  typedef RealType result_type;

  explicit uniform_real(RealType min_arg = RealType(0),
                        RealType max_arg = RealType(1))
    : _min(min_arg), _max(max_arg)
  {
#ifndef STREAMS_BOOST_NO_LIMITS_COMPILE_TIME_CONSTANTS
    STREAMS_BOOST_STATIC_ASSERT(!std::numeric_limits<RealType>::is_integer);
#endif
    assert(min_arg <= max_arg);
  }

  // compiler-generated copy ctor and assignment operator are fine

  result_type min STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION () const { return _min; }
  result_type max STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION () const { return _max; }
  void reset() { }

  template<class Engine>
  result_type operator()(Engine& eng) {
    result_type numerator = static_cast<result_type>(eng() - eng.min STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION());
    result_type divisor = static_cast<result_type>(eng.max STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION() - eng.min STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION());
    assert(divisor > 0);
    assert(numerator >= 0 && numerator <= divisor);
    return numerator / divisor * (_max - _min) + _min;
  }

#ifndef STREAMS_BOOST_RANDOM_NO_STREAM_OPERATORS
  template<class CharT, class Traits>
  friend std::basic_ostream<CharT,Traits>&
  operator<<(std::basic_ostream<CharT,Traits>& os, const uniform_real& ud)
  {
    os << ud._min << " " << ud._max;
    return os;
  }

  template<class CharT, class Traits>
  friend std::basic_istream<CharT,Traits>&
  operator>>(std::basic_istream<CharT,Traits>& is, uniform_real& ud)
  {
    is >> std::ws >> ud._min >> std::ws >> ud._max;
    return is;
  }
#endif

private:
  RealType _min, _max;
};

} // namespace streams_boost

#endif // STREAMS_BOOST_RANDOM_UNIFORM_REAL_HPP
