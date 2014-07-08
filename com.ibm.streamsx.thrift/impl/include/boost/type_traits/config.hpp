
//  (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt).
//
//  See http://www.streams_boost.org/libs/type_traits for most recent version including documentation.

#ifndef STREAMS_BOOST_TT_CONFIG_HPP_INCLUDED
#define STREAMS_BOOST_TT_CONFIG_HPP_INCLUDED

#ifndef STREAMS_BOOST_CONFIG_HPP
#include <streams_boost/config.hpp>
#endif

#include <streams_boost/detail/workaround.hpp>

//
// whenever we have a conversion function with elipses
// it needs to be declared __cdecl to suppress compiler
// warnings from MS and Borland compilers (this *must*
// appear before we include is_same.hpp below):
#if defined(STREAMS_BOOST_MSVC) || (defined(__BORLANDC__) && !defined(STREAMS_BOOST_DISABLE_WIN32))
#   define STREAMS_BOOST_TT_DECL __cdecl
#else
#   define STREAMS_BOOST_TT_DECL /**/
#endif

# if (STREAMS_BOOST_WORKAROUND(__MWERKS__, < 0x3000)                         \
    || STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, <= 1301)                        \
    || !defined(__EDG_VERSION__) && STREAMS_BOOST_WORKAROUND(__GNUC__, < 3) \
    || STREAMS_BOOST_WORKAROUND(__IBMCPP__, < 600 )                         \
    || STREAMS_BOOST_WORKAROUND(__BORLANDC__, < 0x5A0)                      \
    || defined(__ghs)                                               \
    || STREAMS_BOOST_WORKAROUND(__HP_aCC, < 60700)           \
    || STREAMS_BOOST_WORKAROUND(MPW_CPLUS, STREAMS_BOOST_TESTED_AT(0x890))          \
    || STREAMS_BOOST_WORKAROUND(__SUNPRO_CC, STREAMS_BOOST_TESTED_AT(0x580)))       \
    && defined(STREAMS_BOOST_NO_IS_ABSTRACT)

#   define STREAMS_BOOST_TT_NO_CONFORMING_IS_CLASS_IMPLEMENTATION 1

#endif

#ifndef STREAMS_BOOST_TT_NO_CONFORMING_IS_CLASS_IMPLEMENTATION
# define STREAMS_BOOST_TT_HAS_CONFORMING_IS_CLASS_IMPLEMENTATION 1
#endif

//
// Define STREAMS_BOOST_TT_NO_ELLIPSIS_IN_FUNC_TESTING 
// when we can't test for function types with elipsis:
//
#if STREAMS_BOOST_WORKAROUND(__GNUC__, < 3)
#  define STREAMS_BOOST_TT_NO_ELLIPSIS_IN_FUNC_TESTING
#endif

//
// define STREAMS_BOOST_TT_TEST_MS_FUNC_SIGS
// when we want to test __stdcall etc function types with is_function etc
// (Note, does not work with Borland, even though it does support __stdcall etc):
//
#if defined(_MSC_EXTENSIONS) && !defined(__BORLANDC__)
#  define STREAMS_BOOST_TT_TEST_MS_FUNC_SIGS
#endif

//
// define STREAMS_BOOST_TT_NO_CV_FUNC_TEST
// if tests for cv-qualified member functions don't 
// work in is_member_function_pointer
//
#if STREAMS_BOOST_WORKAROUND(__MWERKS__, < 0x3000) || STREAMS_BOOST_WORKAROUND(__IBMCPP__, <= 600)
#  define STREAMS_BOOST_TT_NO_CV_FUNC_TEST
#endif

#endif // STREAMS_BOOST_TT_CONFIG_HPP_INCLUDED


