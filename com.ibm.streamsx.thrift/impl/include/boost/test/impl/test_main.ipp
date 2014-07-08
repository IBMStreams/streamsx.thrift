//  (C) Copyright Gennadiy Rozental 2001-2008.
//  (C) Copyright Beman Dawes 1995-2001.
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org/libs/test for the library home page.
//
//  File        : $RCSfile$
//
//  Version     : $$Revision: 49312 $
//
//  Description : implements main function for Test Execution Monitor.
// ***************************************************************************

#ifndef STREAMS_BOOST_TEST_TEST_MAIN_IPP_012205GER
#define STREAMS_BOOST_TEST_TEST_MAIN_IPP_012205GER

// Boost.Test
#include <streams_boost/test/framework.hpp>
#include <streams_boost/test/test_tools.hpp>
#include <streams_boost/test/unit_test_suite.hpp>

// Boost
#include <streams_boost/cstdlib.hpp>

#include <streams_boost/test/detail/suppress_warnings.hpp>

//____________________________________________________________________________//

extern int test_main( int argc, char* argv[] );    // prototype for user's test_main()

struct test_main_caller {
    test_main_caller( int argc, char** argv ) : m_argc( argc ), m_argv( argv ) {}
    
    void operator()() {
        int test_main_result = test_main( m_argc, m_argv );

        // translate a test_main non-success return into a test error
        STREAMS_BOOST_CHECK( test_main_result == 0 || test_main_result == streams_boost::exit_success );
    }
  
private:
    // Data members    
    int      m_argc;
    char**   m_argv;
};

// ************************************************************************** //
// **************                   test main                  ************** //
// ************************************************************************** //

::streams_boost::unit_test::test_suite*
init_unit_test_suite( int argc, char* argv[] ) {
    using namespace ::streams_boost::unit_test;
    
    framework::master_test_suite().p_name.value = "Test Program";
    
    framework::master_test_suite().add( STREAMS_BOOST_TEST_CASE( test_main_caller( argc, argv ) ) );
    
    return 0;
}

//____________________________________________________________________________//

#include <streams_boost/test/detail/enable_warnings.hpp>

#endif // STREAMS_BOOST_TEST_TEST_MAIN_IPP_012205GER
