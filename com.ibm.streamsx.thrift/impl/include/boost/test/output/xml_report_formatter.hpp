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
//  Description : XML report formatter implementation
// ***************************************************************************

#ifndef STREAMS_BOOST_TEST_XML_REPORT_FORMATTER_HPP_020105GER
#define STREAMS_BOOST_TEST_XML_REPORT_FORMATTER_HPP_020105GER

// Boost.Test
#include <streams_boost/test/detail/global_typedef.hpp>
#include <streams_boost/test/results_reporter.hpp>

#include <streams_boost/test/detail/suppress_warnings.hpp>

//____________________________________________________________________________//

namespace streams_boost {

namespace unit_test {

namespace output {

// ************************************************************************** //
// **************              xml_report_formatter            ************** //
// ************************************************************************** //

class xml_report_formatter : public results_reporter::format {
public:
    // Formatter interface
    void    results_report_start( std::ostream& ostr );
    void    results_report_finish( std::ostream& ostr );

    void    test_unit_report_start( test_unit const&, std::ostream& ostr );
    void    test_unit_report_finish( test_unit const&, std::ostream& ostr );

    void    do_confirmation_report( test_unit const&, std::ostream& ostr );
};

} // namespace output

} // namespace unit_test

} // namespace streams_boost

//____________________________________________________________________________//

#include <streams_boost/test/detail/enable_warnings.hpp>

#endif // STREAMS_BOOST_TEST_XML_REPORT_FORMATTER_HPP_020105GER
