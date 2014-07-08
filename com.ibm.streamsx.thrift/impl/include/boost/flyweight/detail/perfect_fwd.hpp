/* Copyright 2006-2008 Joaquin M Lopez Munoz.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.streams_boost.org/LICENSE_1_0.txt)
 *
 * See http://www.streams_boost.org/libs/flyweight for library home page.
 */

/* Brute force implementation of perfect forwarding overloads.
 * Usage: include after having defined the argument macros:
 *   STREAMS_BOOST_FLYWEIGHT_PERFECT_FWD_NAME
 *   STREAMS_BOOST_FLYWEIGHT_PERFECT_FWD_BODY
 */

/* This user_definable macro limits the maximum number of arguments to
 * be perfect forwarded. Beware combinatorial explosion: manual perfect
 * forwarding for n arguments produces 2^n distinct overloads.
 */

#if !defined(STREAMS_BOOST_FLYWEIGHT_LIMIT_PERFECT_FWD_ARGS)
#define STREAMS_BOOST_FLYWEIGHT_LIMIT_PERFECT_FWD_ARGS 5
#endif

#if STREAMS_BOOST_FLYWEIGHT_LIMIT_PERFECT_FWD_ARGS<=5
#include <streams_boost/flyweight/detail/pp_perfect_fwd.hpp>
#else
#include <streams_boost/flyweight/detail/dyn_perfect_fwd.hpp>
#endif
