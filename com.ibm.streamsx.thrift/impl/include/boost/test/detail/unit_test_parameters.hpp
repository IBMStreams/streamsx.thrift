//  (C) Copyright Gennadiy Rozental 2001-2008.
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE_1_0.txt or copy at 
//  http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org/libs/test for the library home page.
//
//  File        : $RCSfile$
//
//  Version     : $Revision: 57992 $
//
//  Description : storage for unit test framework parameters information
// ***************************************************************************

#ifndef STREAMS_BOOST_TEST_UNIT_TEST_PARAMETERS_HPP_071894GER
#define STREAMS_BOOST_TEST_UNIT_TEST_PARAMETERS_HPP_071894GER

#include <streams_boost/test/detail/global_typedef.hpp>
#include <streams_boost/test/detail/log_level.hpp>

#include <streams_boost/test/detail/suppress_warnings.hpp>

// STL
#include <iosfwd>

//____________________________________________________________________________//

namespace streams_boost {

namespace unit_test {

// ************************************************************************** //
// **************                 runtime_config               ************** //
// ************************************************************************** //

namespace runtime_config {

STREAMS_BOOST_TEST_DECL void                     init( int& argc, char** argv );

STREAMS_BOOST_TEST_DECL unit_test::log_level     log_level();
STREAMS_BOOST_TEST_DECL bool                     no_result_code();
STREAMS_BOOST_TEST_DECL unit_test::report_level  report_level();
STREAMS_BOOST_TEST_DECL const_string             test_to_run();
STREAMS_BOOST_TEST_DECL const_string             break_exec_path();
STREAMS_BOOST_TEST_DECL bool                     save_pattern();
STREAMS_BOOST_TEST_DECL bool                     show_build_info();
STREAMS_BOOST_TEST_DECL bool                     show_progress();
STREAMS_BOOST_TEST_DECL bool                     catch_sys_errors();
STREAMS_BOOST_TEST_DECL bool                     auto_start_dbg();
STREAMS_BOOST_TEST_DECL bool                     use_alt_stack();
STREAMS_BOOST_TEST_DECL bool                     detect_fp_exceptions();
STREAMS_BOOST_TEST_DECL output_format            report_format();
STREAMS_BOOST_TEST_DECL output_format            log_format();
STREAMS_BOOST_TEST_DECL std::ostream*            report_sink();
STREAMS_BOOST_TEST_DECL std::ostream*            log_sink();
STREAMS_BOOST_TEST_DECL long                     detect_memory_leaks();
STREAMS_BOOST_TEST_DECL int                      random_seed();

} // namespace runtime_config

} // namespace unit_test

} // namespace streams_boost

//____________________________________________________________________________//

#include <streams_boost/test/detail/enable_warnings.hpp>

#endif // STREAMS_BOOST_TEST_UNIT_TEST_PARAMETERS_HPP_071894GER
