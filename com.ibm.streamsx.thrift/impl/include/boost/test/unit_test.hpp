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
//  Description : Entry point for the end user into the Unit Test Framework.
// ***************************************************************************

#ifndef STREAMS_BOOST_TEST_UNIT_TEST_HPP_071894GER
#define STREAMS_BOOST_TEST_UNIT_TEST_HPP_071894GER

// Boost.Test
#include <streams_boost/test/test_tools.hpp>
#include <streams_boost/test/unit_test_suite.hpp>

//____________________________________________________________________________//

// ************************************************************************** //
// **************                 Auto Linking                 ************** //
// ************************************************************************** //

#if !defined(STREAMS_BOOST_ALL_NO_LIB) && !defined(STREAMS_BOOST_TEST_NO_LIB) && \
    !defined(STREAMS_BOOST_TEST_SOURCE) && !defined(STREAMS_BOOST_TEST_INCLUDED)
#  define STREAMS_BOOST_LIB_NAME streams_boost_unit_test_framework

#  if defined(STREAMS_BOOST_ALL_DYN_LINK) || defined(STREAMS_BOOST_TEST_DYN_LINK)
#    define STREAMS_BOOST_DYN_LINK
#  endif

#  include <streams_boost/config/auto_link.hpp>

#endif  // auto-linking disabled

// ************************************************************************** //
// **************                  unit_test_main              ************** //
// ************************************************************************** //

namespace streams_boost { namespace unit_test {

int STREAMS_BOOST_TEST_DECL unit_test_main( init_unit_test_func init_func, int argc, char* argv[] );

}}

#if defined(STREAMS_BOOST_TEST_DYN_LINK) && defined(STREAMS_BOOST_TEST_MAIN) && !defined(STREAMS_BOOST_TEST_NO_MAIN)

// ************************************************************************** //
// **************        main function for tests using dll     ************** //
// ************************************************************************** //

int STREAMS_BOOST_TEST_CALL_DECL
main( int argc, char* argv[] )
{
    return ::streams_boost::unit_test::unit_test_main( &init_unit_test, argc, argv );
}

//____________________________________________________________________________//

#endif // STREAMS_BOOST_TEST_DYN_LINK && STREAMS_BOOST_TEST_MAIN && !STREAMS_BOOST_TEST_NO_MAIN

#endif // STREAMS_BOOST_TEST_UNIT_TEST_HPP_071894GER
