///////////////////////////////////////////////////////////////////////////////
/// \file xpressive_static.hpp
/// Includes everything you need to write static regular expressions and use
/// them.
//
//  Copyright 2008 Eric Niebler. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_XPRESSIVE_STATIC_HPP_EAN_10_04_2005
#define STREAMS_BOOST_XPRESSIVE_STATIC_HPP_EAN_10_04_2005

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

#ifdef _MSC_VER
// inline aggressively
# pragma inline_recursion(on) // turn on inline recursion
# pragma inline_depth(255)    // max inline depth
#endif

#include <streams_boost/xpressive/regex_primitives.hpp>
#include <streams_boost/xpressive/basic_regex.hpp>
#include <streams_boost/xpressive/sub_match.hpp>
#include <streams_boost/xpressive/match_results.hpp>
#include <streams_boost/xpressive/regex_algorithms.hpp>
#include <streams_boost/xpressive/regex_iterator.hpp>
#include <streams_boost/xpressive/regex_token_iterator.hpp>

#endif
