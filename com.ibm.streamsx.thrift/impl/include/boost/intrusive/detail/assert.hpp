/////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga  2006-2009
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/intrusive for documentation.
//
/////////////////////////////////////////////////////////////////////////////

#ifndef STREAMS_BOOST_INTRUSIVE_DETAIL_ASSERT_HPP
#define STREAMS_BOOST_INTRUSIVE_DETAIL_ASSERT_HPP 

#if defined(_MSC_VER)&&(_MSC_VER>=1200)
#pragma once
#endif

#if !defined(STREAMS_BOOST_INTRUSIVE_INVARIANT_ASSERT)
   #include <streams_boost/assert.hpp>
   #define STREAMS_BOOST_INTRUSIVE_INVARIANT_ASSERT STREAMS_BOOST_ASSERT
#elif defined(STREAMS_BOOST_INTRUSIVE_INVARIANT_ASSERT_INCLUDE)
   #include STREAMS_BOOST_INTRUSIVE_INVARIANT_ASSERT_INCLUDE
#endif

#if !defined(STREAMS_BOOST_INTRUSIVE_SAFE_HOOK_DEFAULT_ASSERT)
   #include <streams_boost/assert.hpp>
   #define STREAMS_BOOST_INTRUSIVE_SAFE_HOOK_DEFAULT_ASSERT STREAMS_BOOST_ASSERT
#elif defined(STREAMS_BOOST_INTRUSIVE_SAFE_HOOK_DEFAULT_ASSERT_INCLUDE)
   #include STREAMS_BOOST_INTRUSIVE_SAFE_HOOK_DEFAULT_ASSERT_INCLUDE
#endif

#if !defined(STREAMS_BOOST_INTRUSIVE_SAFE_HOOK_DESTRUCTOR_ASSERT)
   #include <streams_boost/assert.hpp>
   #define STREAMS_BOOST_INTRUSIVE_SAFE_HOOK_DESTRUCTOR_ASSERT STREAMS_BOOST_ASSERT
#elif defined(STREAMS_BOOST_INTRUSIVE_SAFE_HOOK_DESTRUCTOR_ASSERT_INCLUDE)
   #include STREAMS_BOOST_INTRUSIVE_SAFE_HOOK_DESTRUCTOR_ASSERT_INCLUDE
#endif

#endif //STREAMS_BOOST_INTRUSIVE_DETAIL_ASSERT_HPP
