//  Copyright (c) 2001-2010 Hartmut Kaiser
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#if !defined(STREAMS_BOOST_SPIRIT_ASSERT_MSG_JUN_23_2009_0836AM)
#define STREAMS_BOOST_SPIRIT_ASSERT_MSG_JUN_23_2009_0836AM

#if defined(_MSC_VER)
#pragma once
#endif

// Allow to work around the MPL problem in STREAMS_BOOST_MPL_ASSERT_MSG generating
// multiple definition linker errors for certain compilers (VC++)
#if STREAMS_BOOST_SPIRIT_DONT_USE_MPL_ASSERT_MSG != 0
#include <streams_boost/static_assert.hpp>
#define STREAMS_BOOST_SPIRIT_ASSERT_MSG(Cond, Msg, Types)                             \
        STREAMS_BOOST_STATIC_ASSERT(Cond)
#else
#include <streams_boost/mpl/assert.hpp>
#define STREAMS_BOOST_SPIRIT_ASSERT_MSG(Cond, Msg, Types)                             \
        STREAMS_BOOST_MPL_ASSERT_MSG(Cond, Msg, Types)
#endif

#define STREAMS_BOOST_SPIRIT_ASSERT_MATCH(Domain, Expr)                               \
        STREAMS_BOOST_SPIRIT_ASSERT_MSG((                                             \
            streams_boost::spirit::traits::matches<Domain, Expr>::value               \
        ), error_invalid_expression, (Expr))

#endif

