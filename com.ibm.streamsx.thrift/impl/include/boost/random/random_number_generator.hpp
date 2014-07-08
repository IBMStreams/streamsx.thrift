/* streams_boost random/random_number_generator.hpp header file
 *
 * Copyright Jens Maurer 2000-2001
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.streams_boost.org/LICENSE_1_0.txt)
 *
 * See http://www.streams_boost.org for most recent version including documentation.
 *
 * $Id: random_number_generator.hpp 26164 2004-11-09 21:22:00Z jmaurer $
 *
 * Revision history
 *  2001-02-18  moved to individual header files
 */

#ifndef STREAMS_BOOST_RANDOM_RANDOM_NUMBER_GENERATOR_HPP
#define STREAMS_BOOST_RANDOM_RANDOM_NUMBER_GENERATOR_HPP

#include <streams_boost/config.hpp>
#include <streams_boost/limits.hpp>
#include <streams_boost/static_assert.hpp>
#include <streams_boost/random/uniform_int.hpp>
#include <streams_boost/random/variate_generator.hpp>

namespace streams_boost {

// a model for RandomNumberGenerator std:25.2.11 [lib.alg.random.shuffle]
template<class UniformRandomNumberGenerator, class IntType = long>
class random_number_generator
{
public:
  typedef UniformRandomNumberGenerator base_type;
  typedef IntType argument_type;
  typedef IntType result_type;
  random_number_generator(base_type& rng) : _rng(rng)
  { 
#ifndef STREAMS_BOOST_NO_LIMITS_COMPILE_TIME_CONSTANTS
    STREAMS_BOOST_STATIC_ASSERT(std::numeric_limits<result_type>::is_integer);
#endif
  }
  // compiler-generated copy ctor is fine
  // assignment is disallowed because there is a reference member

  result_type operator()(argument_type n)
  {
    typedef uniform_int<IntType> dist_type;
    return variate_generator<base_type&, dist_type>(_rng, dist_type(0, n-1))();
  }

private:
  base_type& _rng;
};

} // namespace streams_boost

#endif // STREAMS_BOOST_RANDOM_RANDOM_NUMBER_GENERATOR_HPP
