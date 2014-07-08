/* streams_boost random/exponential_distribution.hpp header file
 *
 * Copyright Jens Maurer 2000-2001
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.streams_boost.org/LICENSE_1_0.txt)
 *
 * See http://www.streams_boost.org for most recent version including documentation.
 *
 * $Id: exponential_distribution.hpp 52492 2009-04-19 14:55:57Z steven_watanabe $
 *
 * Revision history
 *  2001-02-18  moved to individual header files
 */

#ifndef STREAMS_BOOST_RANDOM_EXPONENTIAL_DISTRIBUTION_HPP
#define STREAMS_BOOST_RANDOM_EXPONENTIAL_DISTRIBUTION_HPP

#include <streams_boost/config/no_tr1/cmath.hpp>
#include <cassert>
#include <iostream>
#include <streams_boost/limits.hpp>
#include <streams_boost/static_assert.hpp>
#include <streams_boost/random/detail/config.hpp>

namespace streams_boost {

// exponential distribution: p(x) = lambda * exp(-lambda * x)
template<class RealType = double>
class exponential_distribution
{
public:
  typedef RealType input_type;
  typedef RealType result_type;

#if !defined(STREAMS_BOOST_NO_LIMITS_COMPILE_TIME_CONSTANTS) && !(defined(STREAMS_BOOST_MSVC) && STREAMS_BOOST_MSVC <= 1300)
  STREAMS_BOOST_STATIC_ASSERT(!std::numeric_limits<RealType>::is_integer);
#endif

  explicit exponential_distribution(result_type lambda_arg = result_type(1))
    : _lambda(lambda_arg) { assert(_lambda > result_type(0)); }

  // compiler-generated copy ctor and assignment operator are fine

  result_type lambda() const { return _lambda; }

  void reset() { }

  template<class Engine>
  result_type operator()(Engine& eng)
  { 
#ifndef STREAMS_BOOST_NO_STDC_NAMESPACE
    using std::log;
#endif
    return -result_type(1) / _lambda * log(result_type(1)-eng());
  }

#ifndef STREAMS_BOOST_RANDOM_NO_STREAM_OPERATORS
  template<class CharT, class Traits>
  friend std::basic_ostream<CharT,Traits>&
  operator<<(std::basic_ostream<CharT,Traits>& os, const exponential_distribution& ed)
  {
    os << ed._lambda;
    return os;
  }

  template<class CharT, class Traits>
  friend std::basic_istream<CharT,Traits>&
  operator>>(std::basic_istream<CharT,Traits>& is, exponential_distribution& ed)
  {
    is >> std::ws >> ed._lambda;
    return is;
  }
#endif

private:
  result_type _lambda;
};

} // namespace streams_boost

#endif // STREAMS_BOOST_RANDOM_EXPONENTIAL_DISTRIBUTION_HPP