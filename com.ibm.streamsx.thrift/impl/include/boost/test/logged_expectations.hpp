//  (C) Copyright Gennadiy Rozental 2005-2008.
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE_1_0.txt or copy at 
//  http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org/libs/test for the library home page.
//
//  File        : $RCSfile$
//
//  Version     : $Revision: 49312 $
//
//  Description : Facilities to perform interaction based testng of logged expectations
// ***************************************************************************

#ifndef STREAMS_BOOST_TEST_LOGGED_EXPECTATIONS_HPP_120905GER
#define STREAMS_BOOST_TEST_LOGGED_EXPECTATIONS_HPP_120905GER

// Boost.Test
#include <streams_boost/test/detail/config.hpp>
#include <streams_boost/test/detail/unit_test_parameters.hpp>
#include <streams_boost/test/utils/callback.hpp>

#include <streams_boost/test/detail/suppress_warnings.hpp>

//____________________________________________________________________________//

// ************************************************************************** //
// **************        STREAMS_BOOST_TEST_LOGGED_EXPECTATIONS        ************** //
// ************************************************************************** //

#define STREAMS_BOOST_TEST_LOGGED_EXPECTATIONS( test_name )                     \
struct test_name : public STREAMS_BOOST_AUTO_TEST_CASE_FIXTURE                  \
{ void test_method(); };                                                \
                                                                        \
static void STREAMS_BOOST_AUTO_TC_INVOKER( test_name )()                        \
{                                                                       \
    test_name t;                                                        \
    ::streams_boost::itest::logged_expectations(                                \
        streams_boost::bind( &test_name::test_method, t ),                      \
        STREAMS_BOOST_STRINGIZE(test_name) ".elog",                             \
        !::streams_boost::unit_test::runtime_config::save_pattern() );          \
}                                                                       \
                                                                        \
struct STREAMS_BOOST_AUTO_TC_UNIQUE_ID( test_name ) {};                         \
                                                                        \
STREAMS_BOOST_AUTO_TU_REGISTRAR( test_name )(                                   \
    streams_boost::unit_test::make_test_case(                                   \
        &STREAMS_BOOST_AUTO_TC_INVOKER( test_name ), #test_name ),              \
    streams_boost::unit_test::ut_detail::auto_tc_exp_fail<                      \
        STREAMS_BOOST_AUTO_TC_UNIQUE_ID( test_name )>::instance()->value() );   \
                                                                        \
void test_name::test_method()                                           \
/**/

namespace streams_boost {

namespace itest {

// ************************************************************************** //
// **************           logged expectations test           ************** //
// ************************************************************************** //

void    STREAMS_BOOST_TEST_DECL
logged_expectations( unit_test::callback0<> const&  F, 
                     unit_test::const_string        log_file_name, 
                     bool                           test_or_log = true );

} // namespace itest

} // namespace streams_boost

#include <streams_boost/test/detail/enable_warnings.hpp>

#endif // STREAMS_BOOST_TEST_LOGGED_EXPECTATIONS_HPP_120905GER
