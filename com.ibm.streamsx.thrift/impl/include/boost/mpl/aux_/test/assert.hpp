
#ifndef STREAMS_BOOST_MPL_AUX_TEST_ASSERT_HPP_INCLUDED
#define STREAMS_BOOST_MPL_AUX_TEST_ASSERT_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2002-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: assert.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/assert.hpp>
#include <streams_boost/preprocessor/cat.hpp>

#define MPL_ASSERT(pred)                STREAMS_BOOST_MPL_ASSERT(pred)
#define MPL_ASSERT_NOT(pred)            STREAMS_BOOST_MPL_ASSERT_NOT(pred)
#define MPL_ASSERT_MSG(c, msg, types)   STREAMS_BOOST_MPL_ASSERT_MSG(c, msg, types)
#define MPL_ASSERT_RELATION(x, rel, y)  STREAMS_BOOST_MPL_ASSERT_RELATION(x, rel, y)

#define MPL_ASSERT_INSTANTIATION(x) \
    enum { STREAMS_BOOST_PP_CAT(instantiation_test, __LINE__) = sizeof( x ) } \
/**/

#endif // STREAMS_BOOST_MPL_AUX_TEST_ASSERT_HPP_INCLUDED
