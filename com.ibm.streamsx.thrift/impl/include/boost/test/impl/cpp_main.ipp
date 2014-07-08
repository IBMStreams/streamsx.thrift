//  (C) Copyright Gennadiy Rozental 2001-2008.
//  (C) Copyright Beman Dawes 1995-2001.
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE_1_0.txt or copy at 
//  http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org/libs/test for the library home page.
//
//  File        : $RCSfile$
//
//  Version     : $Revision: 49312 $
//
//  Description : main function implementation for Program Executon Monitor
// ***************************************************************************

#ifndef STREAMS_BOOST_TEST_CPP_MAIN_IPP_012205GER
#define STREAMS_BOOST_TEST_CPP_MAIN_IPP_012205GER

// Boost.Test
#include <streams_boost/test/execution_monitor.hpp>
#include <streams_boost/test/detail/config.hpp>
#include <streams_boost/test/utils/basic_cstring/io.hpp>

// Boost
#include <streams_boost/cstdlib.hpp>    // for exit codes
#include <streams_boost/config.hpp>     // for workarounds

// STL
#include <iostream>
#include <cstdlib>      // std::getenv
#include <cstring>      // std::strerror

#include <streams_boost/test/detail/suppress_warnings.hpp>

//____________________________________________________________________________//

#ifdef STREAMS_BOOST_NO_STDC_NAMESPACE
namespace std { using ::getenv; using ::strerror; }
#endif

namespace {

struct cpp_main_caller {
    cpp_main_caller( int (*cpp_main_func)( int argc, char* argv[] ), int argc, char** argv ) 
    : m_cpp_main_func( cpp_main_func )
    , m_argc( argc )
    , m_argv( argv ) {}
    
    int operator()() { return (*m_cpp_main_func)( m_argc, m_argv ); }
  
private:
    // Data members    
    int (*m_cpp_main_func)( int argc, char* argv[] );
    int      m_argc;
    char**   m_argv;
};

} // local namespace

// ************************************************************************** //
// **************             prg_exec_monitor_main            ************** //
// ************************************************************************** //

namespace streams_boost {

int STREAMS_BOOST_TEST_DECL
prg_exec_monitor_main( int (*cpp_main)( int argc, char* argv[] ), int argc, char* argv[] )
{
    int result = 0;

    try {
        streams_boost::unit_test::const_string p( std::getenv( "STREAMS_BOOST_TEST_CATCH_SYSTEM_ERRORS" ) );
        ::streams_boost::execution_monitor ex_mon;

        ex_mon.p_catch_system_errors.value = p != "no";
        
        result = ex_mon.execute( 
            ::streams_boost::unit_test::callback0<int>( cpp_main_caller( cpp_main, argc, argv ) ) );
        
        if( result == 0 )
            result = ::streams_boost::exit_success;
        else if( result != ::streams_boost::exit_success ) {
            std::cout << "\n**** error return code: " << result << std::endl;
            result = ::streams_boost::exit_failure;
        }
    }
    catch( ::streams_boost::execution_exception const& exex ) {
        std::cout << "\n**** exception(" << exex.code() << "): " << exex.what() << std::endl;
        result = ::streams_boost::exit_exception_failure;
    }
    catch( ::streams_boost::system_error const& ex ) {
        std::cout << "\n**** failed to initialize execution monitor."
                  << "\n**** expression at fault: " << ex.p_failed_exp 
                  << "\n**** error(" << ex.p_errno << "): " << std::strerror( ex.p_errno ) << std::endl;
        result = ::streams_boost::exit_exception_failure;
    }

    if( result != ::streams_boost::exit_success ) {
        std::cerr << "******** errors detected; see standard output for details ********" << std::endl;
    }
    else {
        //  Some prefer a confirming message when all is well, while others don't
        //  like the clutter.  Use an environment variable to avoid command
        //  line argument modifications; for use in production programs
        //  that's a no-no in some organizations.
        ::streams_boost::unit_test::const_string p( std::getenv( "STREAMS_BOOST_PRG_MON_CONFIRM" ) );
        if( p != "no" ) { 
            std::cerr << std::flush << "no errors detected" << std::endl; 
        }
    }

    return result;
}

} // namespace streams_boost

#if !defined(STREAMS_BOOST_TEST_DYN_LINK) && !defined(STREAMS_BOOST_TEST_NO_MAIN)

// ************************************************************************** //
// **************        main function for tests using lib     ************** //
// ************************************************************************** //

int cpp_main( int argc, char* argv[] );  // prototype for user's cpp_main()

int STREAMS_BOOST_TEST_CALL_DECL
main( int argc, char* argv[] )
{
    return ::streams_boost::prg_exec_monitor_main( &cpp_main, argc, argv );
}

//____________________________________________________________________________//

#endif // !STREAMS_BOOST_TEST_DYN_LINK && !STREAMS_BOOST_TEST_NO_MAIN

//____________________________________________________________________________//

#include <streams_boost/test/detail/enable_warnings.hpp>

#endif // STREAMS_BOOST_TEST_CPP_MAIN_IPP_012205GER
