/* streams_boost random.hpp header file
 *
 * Copyright Jens Maurer 2000-2001
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.streams_boost.org/LICENSE_1_0.txt)
 *
 * See http://www.streams_boost.org/libs/random for documentation.
 *
 * $Id: random.hpp 58649 2010-01-02 21:23:17Z steven_watanabe $
 *
 * Revision history
 *  2000-02-18  portability fixes (thanks to Beman Dawes)
 *  2000-02-21  shuffle_output, inversive_congruential_schrage,
 *              generator_iterator, uniform_smallint
 *  2000-02-23  generic modulus arithmetic helper, removed *_schrage classes,
 *              implemented Streamable and EqualityComparable concepts for 
 *              generators, added Bernoulli distribution and Box-Muller
 *              transform
 *  2000-03-01  cauchy, lognormal, triangle distributions; fixed 
 *              uniform_smallint; renamed gaussian to normal distribution
 *  2000-03-05  implemented iterator syntax for distribution functions
 *  2000-04-21  removed some optimizations for better BCC/MSVC compatibility
 *  2000-05-10  adapted to BCC and MSVC
 *  2000-06-13  incorporated review results
 *  2000-07-06  moved basic templates from namespace detail to random
 *  2000-09-23  warning removals and int64 fixes (Ed Brey)
 *  2000-09-24  added lagged_fibonacci generator (Matthias Troyer)
 *  2001-02-18  moved to individual header files
 */

#ifndef STREAMS_BOOST_RANDOM_HPP
#define STREAMS_BOOST_RANDOM_HPP

// generators
#include <streams_boost/random/linear_congruential.hpp>
#include <streams_boost/random/additive_combine.hpp>
#include <streams_boost/random/inversive_congruential.hpp>
#include <streams_boost/random/shuffle_output.hpp>
#include <streams_boost/random/mersenne_twister.hpp>
#include <streams_boost/random/lagged_fibonacci.hpp>
#include <streams_boost/random/ranlux.hpp>
#include <streams_boost/random/linear_feedback_shift.hpp>
#include <streams_boost/random/xor_combine.hpp>
#include <streams_boost/random/discard_block.hpp>
#include <streams_boost/random/subtract_with_carry.hpp>
#include <streams_boost/random/variate_generator.hpp>

namespace streams_boost {
  typedef random::xor_combine<random::xor_combine<random::linear_feedback_shift<uint32_t, 32, 31, 13, 12, 0>, 0,
    random::linear_feedback_shift<uint32_t, 32, 29, 2, 4, 0>, 0, 0>, 0,
                      random::linear_feedback_shift<uint32_t, 32, 28, 3, 17, 0>, 0, 0> taus88;
} // namespace  streams_boost

// misc
#include <streams_boost/random/random_number_generator.hpp>

// distributions
#include <streams_boost/random/uniform_smallint.hpp>
#include <streams_boost/random/uniform_int.hpp>
#include <streams_boost/random/uniform_01.hpp>
#include <streams_boost/random/uniform_real.hpp>
#include <streams_boost/random/triangle_distribution.hpp>
#include <streams_boost/random/bernoulli_distribution.hpp>
#include <streams_boost/random/cauchy_distribution.hpp>
#include <streams_boost/random/exponential_distribution.hpp>
#include <streams_boost/random/geometric_distribution.hpp>
#include <streams_boost/random/normal_distribution.hpp>
#include <streams_boost/random/lognormal_distribution.hpp>
#include <streams_boost/random/poisson_distribution.hpp>
#include <streams_boost/random/gamma_distribution.hpp>
#include <streams_boost/random/binomial_distribution.hpp>
#include <streams_boost/random/uniform_on_sphere.hpp>

#endif // STREAMS_BOOST_RANDOM_HPP
