/*=============================================================================
    Copyright (c) 2001-2003 Joel de Guzman
    Copyright (c) 2002-2003 Hartmut Kaiser
    http://spirit.sourceforge.net/

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
=============================================================================*/
#if !defined(STREAMS_BOOST_SPIRIT_ASSERT_HPP)
#define STREAMS_BOOST_SPIRIT_ASSERT_HPP

#include <streams_boost/config.hpp>
#include <streams_boost/throw_exception.hpp>

///////////////////////////////////////////////////////////////////////////////
//
//  STREAMS_BOOST_SPIRIT_ASSERT is used throughout the framework.  It can be
//  overridden by the user. If STREAMS_BOOST_SPIRIT_ASSERT_EXCEPTION is defined,
//  then that will be thrown, otherwise, STREAMS_BOOST_SPIRIT_ASSERT simply turns
//  into a plain assert()
//
///////////////////////////////////////////////////////////////////////////////
#if !defined(STREAMS_BOOST_SPIRIT_ASSERT)
#if defined(NDEBUG)
    #define STREAMS_BOOST_SPIRIT_ASSERT(x)
#elif defined (STREAMS_BOOST_SPIRIT_ASSERT_EXCEPTION)
    #define STREAMS_BOOST_SPIRIT_ASSERT_AUX(f, l, x) STREAMS_BOOST_SPIRIT_ASSERT_AUX2(f, l, x)
    #define STREAMS_BOOST_SPIRIT_ASSERT_AUX2(f, l, x)                                   \
    do{ if (!(x)) streams_boost::throw_exception(                                       \
        STREAMS_BOOST_SPIRIT_ASSERT_EXCEPTION(f "(" #l "): " #x)); } while(0)
    #define STREAMS_BOOST_SPIRIT_ASSERT(x) STREAMS_BOOST_SPIRIT_ASSERT_AUX(__FILE__, __LINE__, x)
#else
    #include <cassert>
    #define STREAMS_BOOST_SPIRIT_ASSERT(x) assert(x)
#endif
#endif // !defined(STREAMS_BOOST_SPIRIT_ASSERT)

#endif // STREAMS_BOOST_SPIRIT_ASSERT_HPP
