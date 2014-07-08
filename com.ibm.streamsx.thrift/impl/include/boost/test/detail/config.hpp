//  (C) Copyright Gennadiy Rozental 2001-2008.
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE_1_0.txt or copy at 
//  http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org/libs/test for the library home page.
//
//  File        : $RCSfile$
//
//  Version     : $Revision: 49312 $
//
//  Description : as a central place for global configuration switches
// ***************************************************************************

#ifndef STREAMS_BOOST_TEST_CONFIG_HPP_071894GER
#define STREAMS_BOOST_TEST_CONFIG_HPP_071894GER

// Boost
#include <streams_boost/config.hpp> // compilers workarounds
#include <streams_boost/detail/workaround.hpp>

//____________________________________________________________________________//

#if STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x570)) || \
    STREAMS_BOOST_WORKAROUND(__IBMCPP__, STREAMS_BOOST_TESTED_AT(600))     || \
    (defined __sgi && STREAMS_BOOST_WORKAROUND(_COMPILER_VERSION, STREAMS_BOOST_TESTED_AT(730)))
#  define STREAMS_BOOST_TEST_SHIFTED_LINE
#endif

//____________________________________________________________________________//

#if defined(STREAMS_BOOST_MSVC) || (defined(__BORLANDC__) && !defined(STREAMS_BOOST_DISABLE_WIN32))
#  define STREAMS_BOOST_TEST_CALL_DECL __cdecl
#else
#  define STREAMS_BOOST_TEST_CALL_DECL /**/
#endif

//____________________________________________________________________________//

#if !defined(STREAMS_BOOST_NO_STD_LOCALE) &&            \
    !STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, < 1310)  &&   \
    !defined(__MWERKS__) 
#  define STREAMS_BOOST_TEST_USE_STD_LOCALE 1
#endif

//____________________________________________________________________________//

#if STREAMS_BOOST_WORKAROUND(__BORLANDC__, <= 0x570)            || \
    STREAMS_BOOST_WORKAROUND( __COMO__, <= 0x433 )              || \
    STREAMS_BOOST_WORKAROUND( __INTEL_COMPILER, <= 800 )        || \
    defined(__sgi) && _COMPILER_VERSION <= 730          || \
    STREAMS_BOOST_WORKAROUND(__IBMCPP__, STREAMS_BOOST_TESTED_AT(600))  || \
    defined(__DECCXX)                                   || \
    defined(__DMC__)
#  define STREAMS_BOOST_TEST_NO_PROTECTED_USING
#endif

//____________________________________________________________________________//

#if defined(__GNUC__) || STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, == 1400)
#define STREAMS_BOOST_TEST_PROTECTED_VIRTUAL virtual
#else
#define STREAMS_BOOST_TEST_PROTECTED_VIRTUAL
#endif

//____________________________________________________________________________//

#if !STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x564)) && \
    !STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, <1310) && \
    !STREAMS_BOOST_WORKAROUND(__SUNPRO_CC, STREAMS_BOOST_TESTED_AT(0x530))
#  define STREAMS_BOOST_TEST_SUPPORT_INTERACTION_TESTING 1
#endif

//____________________________________________________________________________//

#if defined(STREAMS_BOOST_ALL_DYN_LINK) && !defined(STREAMS_BOOST_TEST_DYN_LINK)
#  define STREAMS_BOOST_TEST_DYN_LINK
#endif

#if defined(STREAMS_BOOST_TEST_INCLUDED)
#  undef STREAMS_BOOST_TEST_DYN_LINK
#endif

#if defined(STREAMS_BOOST_TEST_DYN_LINK)
#  define STREAMS_BOOST_TEST_ALTERNATIVE_INIT_API

#  if defined(STREAMS_BOOST_HAS_DECLSPEC) && defined(STREAMS_BOOST_TEST_DYN_LINK)
#    ifdef STREAMS_BOOST_TEST_SOURCE
#      define STREAMS_BOOST_TEST_DECL __declspec(dllexport)
#    else
#      define STREAMS_BOOST_TEST_DECL __declspec(dllimport)
#    endif  // STREAMS_BOOST_TEST_SOURCE
#  endif  // STREAMS_BOOST_HAS_DECLSPEC
#endif  // STREAMS_BOOST_TEST_DYN_LINK


#ifndef STREAMS_BOOST_TEST_DECL
#  define STREAMS_BOOST_TEST_DECL
#endif

#if !defined(STREAMS_BOOST_TEST_MAIN) && defined(STREAMS_BOOST_AUTO_TEST_MAIN)
#define STREAMS_BOOST_TEST_MAIN STREAMS_BOOST_AUTO_TEST_MAIN
#endif

#if !defined(STREAMS_BOOST_TEST_MAIN) && defined(STREAMS_BOOST_TEST_MODULE)
#define STREAMS_BOOST_TEST_MAIN STREAMS_BOOST_TEST_MODULE
#endif

#endif // STREAMS_BOOST_TEST_CONFIG_HPP_071894GER
