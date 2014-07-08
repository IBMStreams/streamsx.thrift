//  (C) Copyright Gennadiy Rozental 2005-2008.
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org/libs/test for the library home page.
//
//  File        : $RCSfile$
//
//  Version     : $Revision: 57992 $
//
//  Description : implements simple text based progress monitor
// ***************************************************************************

#ifndef STREAMS_BOOST_TEST_PROGRESS_MONITOR_IPP_020105GER
#define STREAMS_BOOST_TEST_PROGRESS_MONITOR_IPP_020105GER

// Boost.Test
#include <streams_boost/test/progress_monitor.hpp>
#include <streams_boost/test/unit_test_suite_impl.hpp>

#include <streams_boost/test/detail/unit_test_parameters.hpp>

// Boost
#include <streams_boost/progress.hpp>
#include <streams_boost/scoped_ptr.hpp>

#include <streams_boost/test/detail/suppress_warnings.hpp>

//____________________________________________________________________________//

namespace streams_boost {

namespace unit_test {

// ************************************************************************** //
// **************                progress_monitor              ************** //
// ************************************************************************** //

namespace {

struct progress_monitor_impl {
    // Constructor
    progress_monitor_impl()
        : m_stream( runtime_config::log_sink() )
    {}

    std::ostream*                m_stream;
    scoped_ptr<progress_display> m_progress_display;
};

progress_monitor_impl& s_pm_impl() { static progress_monitor_impl the_inst; return the_inst; }

} // local namespace

//____________________________________________________________________________//

void
progress_monitor_t::test_start( counter_t test_cases_amount )
{
    s_pm_impl().m_progress_display.reset( new progress_display( test_cases_amount, *s_pm_impl().m_stream ) );
}

//____________________________________________________________________________//

void
progress_monitor_t::test_aborted()
{
    (*s_pm_impl().m_progress_display) += s_pm_impl().m_progress_display->count();
}

//____________________________________________________________________________//

void
progress_monitor_t::test_unit_finish( test_unit const& tu, unsigned long )
{
    if( tu.p_type == tut_case )
        ++(*s_pm_impl().m_progress_display);
}

//____________________________________________________________________________//

void
progress_monitor_t::test_unit_skipped( test_unit const& tu )
{
    test_case_counter tcc;
    traverse_test_tree( tu, tcc );
    
    (*s_pm_impl().m_progress_display) += tcc.p_count;
}

//____________________________________________________________________________//

void
progress_monitor_t::set_stream( std::ostream& ostr )
{
    s_pm_impl().m_stream = &ostr;
}

//____________________________________________________________________________//
    
} // namespace unit_test

} // namespace streams_boost

//____________________________________________________________________________//

#include <streams_boost/test/detail/enable_warnings.hpp>

#endif // STREAMS_BOOST_TEST_PROGRESS_MONITOR_IPP_020105GER
