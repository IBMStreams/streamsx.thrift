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
//  Description : defines specific version of execution monitor used to managed 
//  run unit of test cases. Translates execution exception into error level
// ***************************************************************************

#ifndef STREAMS_BOOST_TEST_UNIT_TEST_MONITOR_HPP_020905GER
#define STREAMS_BOOST_TEST_UNIT_TEST_MONITOR_HPP_020905GER

// Boost.Test
#include <streams_boost/test/execution_monitor.hpp>
#include <streams_boost/test/detail/fwd_decl.hpp>
#include <streams_boost/test/utils/trivial_singleton.hpp>
#include <streams_boost/test/utils/callback.hpp>

#include <streams_boost/test/detail/suppress_warnings.hpp>

//____________________________________________________________________________//

namespace streams_boost {

namespace unit_test {

// ************************************************************************** //
// **************               unit_test_monitor              ************** //
// ************************************************************************** //

class STREAMS_BOOST_TEST_DECL unit_test_monitor_t : public singleton<unit_test_monitor_t>, public execution_monitor {
public:
    enum error_level { 
        test_fail               =  1,
        test_ok                 =  0,
        constructor_error       = -1, 
        unexpected_exception    = -2, 
        os_exception            = -3, 
        os_timeout              = -4, 
        fatal_error             = -5,  // includes both system and user
        destructor_error        = -6
    };

    static bool is_critical_error( error_level e ) { return e <= fatal_error; }

    // monitor method
    error_level execute_and_translate( test_case const& );

private:
    STREAMS_BOOST_TEST_SINGLETON_CONS( unit_test_monitor_t );
};

STREAMS_BOOST_TEST_SINGLETON_INST( unit_test_monitor )

} // namespace unit_test

} // namespace streams_boost

//____________________________________________________________________________//

#include <streams_boost/test/detail/enable_warnings.hpp>

#endif // STREAMS_BOOST_TEST_UNIT_TEST_MONITOR_HPP_020905GER
