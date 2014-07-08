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
//  Description : implements XML Log formatter
// ***************************************************************************

#ifndef STREAMS_BOOST_TEST_XML_LOG_FORMATTER_IPP_020105GER
#define STREAMS_BOOST_TEST_XML_LOG_FORMATTER_IPP_020105GER

// Boost.Test
#include <streams_boost/test/output/xml_log_formatter.hpp>
#include <streams_boost/test/unit_test_suite_impl.hpp>
#include <streams_boost/test/framework.hpp>
#include <streams_boost/test/utils/basic_cstring/io.hpp>

#include <streams_boost/test/utils/xml_printer.hpp>

// Boost
#include <streams_boost/version.hpp>

// STL
#include <iostream>

#include <streams_boost/test/detail/suppress_warnings.hpp>

//____________________________________________________________________________//

namespace streams_boost {

namespace unit_test {

namespace output {

static const_string tu_type_name( test_unit const& tu )
{
    return tu.p_type == tut_case ? "TestCase" : "TestSuite";
}

// ************************************************************************** //
// **************               xml_log_formatter              ************** //
// ************************************************************************** //

void
xml_log_formatter::log_start( std::ostream& ostr, counter_t )
{
    ostr  << "<TestLog>";
}

//____________________________________________________________________________//

void
xml_log_formatter::log_finish( std::ostream& ostr )
{
    ostr  << "</TestLog>";
}

//____________________________________________________________________________//

void
xml_log_formatter::log_build_info( std::ostream& ostr )
{
    ostr  << "<BuildInfo"
            << " platform"  << attr_value() << STREAMS_BOOST_PLATFORM
            << " compiler"  << attr_value() << STREAMS_BOOST_COMPILER
            << " stl"       << attr_value() << STREAMS_BOOST_STDLIB
            << " streams_boost=\""  << STREAMS_BOOST_VERSION/100000     << "."
                            << STREAMS_BOOST_VERSION/100 % 1000 << "."
                            << STREAMS_BOOST_VERSION % 100      << '\"'
            << "/>";
}

//____________________________________________________________________________//

void
xml_log_formatter::test_unit_start( std::ostream& ostr, test_unit const& tu )
{
    ostr << "<" << tu_type_name( tu ) << " name" << attr_value() << tu.p_name.get() << ">";
}

//____________________________________________________________________________//

void
xml_log_formatter::test_unit_finish( std::ostream& ostr, test_unit const& tu, unsigned long elapsed )
{
    if( tu.p_type == tut_case )
        ostr << "<TestingTime>" << elapsed << "</TestingTime>";
        
    ostr << "</" << tu_type_name( tu ) << ">";
}

//____________________________________________________________________________//

void
xml_log_formatter::test_unit_skipped( std::ostream& ostr, test_unit const& tu )
{
    ostr << "<" << tu_type_name( tu )
         << " name"    << attr_value() << tu.p_name.get()
         << " skipped" << attr_value() << "yes"
         << "/>";
}
    
//____________________________________________________________________________//

void
xml_log_formatter::log_exception( std::ostream& ostr, log_checkpoint_data const& checkpoint_data, execution_exception const& ex )
{
    execution_exception::location const& loc = ex.where();

    ostr << "<Exception file" << attr_value() << loc.m_file_name
         << " line"           << attr_value() << loc.m_line_num;

    if( !loc.m_function.is_empty() )
        ostr << " function"   << attr_value() << loc.m_function;

    ostr << ">" << cdata() << ex.what();

    if( !checkpoint_data.m_file_name.is_empty() ) {
        ostr << "<LastCheckpoint file" << attr_value() << checkpoint_data.m_file_name
             << " line"                << attr_value() << checkpoint_data.m_line_num
             << ">"
             << cdata() << checkpoint_data.m_message
             << "</LastCheckpoint>";
    }

    ostr << "</Exception>";
}

//____________________________________________________________________________//

void
xml_log_formatter::log_entry_start( std::ostream& ostr, log_entry_data const& entry_data, log_entry_types let )
{
    static literal_string xml_tags[] = { "Info", "Message", "Warning", "Error", "FatalError" };

    m_curr_tag = xml_tags[let];
    ostr << '<' << m_curr_tag
         << STREAMS_BOOST_TEST_L( " file" ) << attr_value() << entry_data.m_file_name
         << STREAMS_BOOST_TEST_L( " line" ) << attr_value() << entry_data.m_line_num
         << STREAMS_BOOST_TEST_L( "><![CDATA[" );
}

//____________________________________________________________________________//

void
xml_log_formatter::log_entry_value( std::ostream& ostr, const_string value )
{
    ostr << value;
}

//____________________________________________________________________________//

void
xml_log_formatter::log_entry_finish( std::ostream& ostr )
{
    ostr << STREAMS_BOOST_TEST_L( "]]></" ) << m_curr_tag << STREAMS_BOOST_TEST_L( ">" );

    m_curr_tag.clear();
}

//____________________________________________________________________________//

} // namespace output

} // namespace unit_test

} // namespace streams_boost

//____________________________________________________________________________//

#include <streams_boost/test/detail/enable_warnings.hpp>

#endif // STREAMS_BOOST_TEST_XML_LOG_FORMATTER_IPP_020105GER
