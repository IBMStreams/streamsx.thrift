//  (C) Copyright Gennadiy Rozental 2002-2008.
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE_1_0.txt or copy at 
//  http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org/libs/test for the library home page.
//
//  File        : $RCSfile$
//
//  Version     : $Revision: 49312 $
//
//  Description : simple minimal testing definitions and implementation
// ***************************************************************************

#ifndef STREAMS_BOOST_TEST_MINIMAL_HPP_071894GER
#define STREAMS_BOOST_TEST_MINIMAL_HPP_071894GER

#define STREAMS_BOOST_CHECK(exp)       \
  ( (exp)                      \
      ? static_cast<void>(0)   \
      : streams_boost::minimal_test::report_error(#exp,__FILE__,__LINE__, STREAMS_BOOST_CURRENT_FUNCTION) )

#define STREAMS_BOOST_REQUIRE(exp)     \
  ( (exp)                      \
      ? static_cast<void>(0)   \
      : streams_boost::minimal_test::report_critical_error(#exp,__FILE__,__LINE__,STREAMS_BOOST_CURRENT_FUNCTION))

#define STREAMS_BOOST_ERROR( msg_ )    \
        streams_boost::minimal_test::report_error( (msg_),__FILE__,__LINE__, STREAMS_BOOST_CURRENT_FUNCTION, true )
#define STREAMS_BOOST_FAIL( msg_ )     \
        streams_boost::minimal_test::report_critical_error( (msg_),__FILE__,__LINE__, STREAMS_BOOST_CURRENT_FUNCTION, true )

//____________________________________________________________________________//

// Boost.Test
#include <streams_boost/test/detail/global_typedef.hpp>
#include <streams_boost/test/impl/execution_monitor.ipp>
#include <streams_boost/test/impl/debug.ipp>
#include <streams_boost/test/utils/class_properties.hpp>
#include <streams_boost/test/utils/basic_cstring/io.hpp>

// Boost
#include <streams_boost/cstdlib.hpp>            // for exit codes#include <streams_boost/cstdlib.hpp>            // for exit codes
#include <streams_boost/current_function.hpp>   // for STREAMS_BOOST_CURRENT_FUNCTION

// STL
#include <iostream>                     // std::cerr, std::endl
#include <string>                       // std::string

#include <streams_boost/test/detail/suppress_warnings.hpp>

//____________________________________________________________________________//

int test_main( int argc, char* argv[] );  // prototype for users test_main()

namespace streams_boost {
namespace minimal_test {

typedef streams_boost::unit_test::const_string const_string;

inline unit_test::counter_t& errors_counter() { static unit_test::counter_t ec = 0; return ec; }

inline void
report_error( const char* msg, const char* file, int line, const_string func_name, bool is_msg = false )
{
    ++errors_counter();
    std::cerr << file << "(" << line << "): ";

    if( is_msg )
        std::cerr << msg;
    else
        std::cerr << "test " << msg << " failed";

    if( func_name != "(unknown)" )
        std::cerr << " in function: '" << func_name << "'";

    std::cerr << std::endl;
}

inline void
report_critical_error( const char* msg, const char* file, int line, const_string func_name, bool is_msg = false )
{
    report_error( msg, file, line, func_name, is_msg );

    throw streams_boost::execution_aborted();
}

class caller {
public:
    // constructor
    caller( int argc, char** argv )
    : m_argc( argc ), m_argv( argv ) {}

    // execution monitor hook implementation
    int operator()() { return test_main( m_argc, m_argv ); }

private:
    // Data members
    int         m_argc;
    char**      m_argv;
}; // monitor

} // namespace minimal_test

} // namespace streams_boost

//____________________________________________________________________________//

int STREAMS_BOOST_TEST_CALL_DECL main( int argc, char* argv[] )
{
    using namespace streams_boost::minimal_test;

    try {
        ::streams_boost::execution_monitor ex_mon;
        int run_result = ex_mon.execute( caller( argc, argv ) );

        STREAMS_BOOST_CHECK( run_result == 0 || run_result == streams_boost::exit_success );
    }
    catch( streams_boost::execution_exception const& exex ) {
        if( exex.code() != streams_boost::execution_exception::no_error )
            STREAMS_BOOST_ERROR( (std::string( "exception \"" ).
                            append( exex.what().begin(), exex.what().end() ).
                            append( "\" caught" ) ).c_str() );
        std::cerr << "\n**** Testing aborted.";
    }

    if( streams_boost::minimal_test::errors_counter() != 0 ) {
        std::cerr << "\n**** " << errors_counter()
                  << " error" << (errors_counter() > 1 ? "s" : "" ) << " detected\n";

        return streams_boost::exit_test_failure;
    }

    std::cout << "\n**** no errors detected\n";
    
    return streams_boost::exit_success;
}

//____________________________________________________________________________//

#include <streams_boost/test/detail/enable_warnings.hpp>

#endif // STREAMS_BOOST_TEST_MINIMAL_HPP_071894GER
