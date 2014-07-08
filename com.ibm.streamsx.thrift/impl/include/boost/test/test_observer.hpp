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
//  Description : defines abstract interface for test observer
// ***************************************************************************

#ifndef STREAMS_BOOST_TEST_TEST_OBSERVER_HPP_021005GER
#define STREAMS_BOOST_TEST_TEST_OBSERVER_HPP_021005GER

// Boost.Test
#include <streams_boost/test/detail/fwd_decl.hpp>
#include <streams_boost/test/detail/global_typedef.hpp>
#include <streams_boost/test/detail/config.hpp>

#include <streams_boost/test/detail/suppress_warnings.hpp>

//____________________________________________________________________________//

namespace streams_boost {

namespace unit_test {

// ************************************************************************** //
// **************                 test_observer                ************** //
// ************************************************************************** //

class STREAMS_BOOST_TEST_DECL test_observer {
public:
    // test observer interface
    virtual void    test_start( counter_t /* test_cases_amount */ ) {}
    virtual void    test_finish() {}
    virtual void    test_aborted() {}

    virtual void    test_unit_start( test_unit const& ) {}
    virtual void    test_unit_finish( test_unit const&, unsigned long /* elapsed */ ) {}
    virtual void    test_unit_skipped( test_unit const& ) {}
    virtual void    test_unit_aborted( test_unit const& ) {}

    virtual void    assertion_result( bool /* passed */ ) {}
    virtual void    exception_caught( execution_exception const& ) {}

    virtual int     priority() { return 0; }

protected:
    STREAMS_BOOST_TEST_PROTECTED_VIRTUAL ~test_observer() {}
};

} // unit_test

} // namespace streams_boost

//____________________________________________________________________________//

#include <streams_boost/test/detail/enable_warnings.hpp>

#endif // STREAMS_BOOST_TEST_TEST_OBSERVER_HPP_021005GER

