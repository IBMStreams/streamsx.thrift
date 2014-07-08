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
//  Description : Entry point for the end user into the Test Execution Monitor.
// ***************************************************************************

#ifndef STREAMS_BOOST_TEST_EXEC_MONITOR_HPP_071894GER
#define STREAMS_BOOST_TEST_EXEC_MONITOR_HPP_071894GER

// Boost.Test
#include <streams_boost/test/test_tools.hpp>

//____________________________________________________________________________//

// ************************************************************************** //
// **************                 Auto Linking                 ************** //
// ************************************************************************** //

// Automatically link to the correct build variant where possible. 
#if !defined(STREAMS_BOOST_ALL_NO_LIB) && !defined(STREAMS_BOOST_TEST_NO_LIB) && \
    !defined(STREAMS_BOOST_TEST_SOURCE) && !defined(STREAMS_BOOST_TEST_INCLUDED)

#  define STREAMS_BOOST_LIB_NAME streams_boost_test_exec_monitor
#  include <streams_boost/config/auto_link.hpp>

#endif  // auto-linking disabled

#endif // STREAMS_BOOST_TEST_EXEC_MONITOR_HPP_071894GER
