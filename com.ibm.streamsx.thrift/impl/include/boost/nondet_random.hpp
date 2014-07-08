/* streams_boost nondet_random.hpp header file
 *
 * Copyright Jens Maurer 2000
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.streams_boost.org/LICENSE_1_0.txt)
 *
 * $Id: nondet_random.hpp 49314 2008-10-13 09:00:03Z johnmaddock $
 *
 * Revision history
 *  2000-02-18  Portability fixes (thanks to Beman Dawes)
 */

//  See http://www.streams_boost.org/libs/random for documentation.


#ifndef STREAMS_BOOST_NONDET_RANDOM_HPP
#define STREAMS_BOOST_NONDET_RANDOM_HPP

#include <string>                       // std::abs
#include <algorithm>                    // std::min
#include <streams_boost/config/no_tr1/cmath.hpp>
#include <streams_boost/config.hpp>
#include <streams_boost/utility.hpp>            // noncopyable
#include <streams_boost/integer_traits.hpp>     // compile-time integral limits

namespace streams_boost {

// use some OS service to generate non-deterministic random numbers
class random_device : private noncopyable
{
public:
  typedef unsigned int result_type;
  STREAMS_BOOST_STATIC_CONSTANT(bool, has_fixed_range = true);
  STREAMS_BOOST_STATIC_CONSTANT(result_type, min_value = integer_traits<result_type>::const_min);
  STREAMS_BOOST_STATIC_CONSTANT(result_type, max_value = integer_traits<result_type>::const_max);

  result_type min STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION () const { return min_value; }
  result_type max STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION () const { return max_value; }
  explicit random_device(const std::string& token = default_token);
  ~random_device();
  double entropy() const;
  unsigned int operator()();

private:
  static const char * const default_token;

  /*
   * std:5.3.5/5 [expr.delete]: "If the object being deleted has incomplete
   * class type at the point of deletion and the complete class has a
   * non-trivial destructor [...], the behavior is undefined".
   * This disallows the use of scoped_ptr<> with pimpl-like classes
   * having a non-trivial destructor.
   */
  class impl;
  impl * pimpl;
};


// TODO: put Schneier's Yarrow-160 algorithm here.

} // namespace streams_boost

#endif /* STREAMS_BOOST_NONDET_RANDOM_HPP */
