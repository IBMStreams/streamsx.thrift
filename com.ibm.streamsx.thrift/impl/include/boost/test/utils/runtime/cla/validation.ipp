//  (C) Copyright Gennadiy Rozental 2005-2008.
//  Use, modification, and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org/libs/test for the library home page.
//
//  File        : $RCSfile$
//
//  Version     : $Revision: 49312 $
//
//  Description : input validation helpers implementation
// ***************************************************************************

#ifndef STREAMS_BOOST_RT_CLA_VALIDATION_IPP_070604GER
#define STREAMS_BOOST_RT_CLA_VALIDATION_IPP_070604GER

// Boost.Runtime.Parameter
#include <streams_boost/test/utils/runtime/config.hpp>

#include <streams_boost/test/utils/runtime/cla/argv_traverser.hpp>
#include <streams_boost/test/utils/runtime/cla/validation.hpp>
#include <streams_boost/test/utils/runtime/validation.hpp> // STREAMS_BOOST_RT_PARAM_NAMESPACE::logic_error

// Boost
#include <streams_boost/test/utils/basic_cstring/io.hpp>

// STL

namespace streams_boost {

namespace STREAMS_BOOST_RT_PARAM_NAMESPACE {

namespace cla {

// ************************************************************************** //
// **************           runtime::cla::validation           ************** //
// ************************************************************************** //

STREAMS_BOOST_RT_PARAM_INLINE void
report_input_error( argv_traverser const& tr, format_stream& msg )
{
    if( tr.eoi() )
        msg << STREAMS_BOOST_RT_PARAM_LITERAL( " at the end of input" );
    else {
        msg << STREAMS_BOOST_RT_PARAM_LITERAL( " in the following position: " );

        if( tr.input().size() > 5 )
            msg << tr.input().substr( 0, 5 ) << STREAMS_BOOST_RT_PARAM_LITERAL( "..." );
        else
            msg << tr.input();
    }

    throw STREAMS_BOOST_RT_PARAM_NAMESPACE::logic_error( msg.str() );
}

//____________________________________________________________________________//

} // namespace cla

} // namespace STREAMS_BOOST_RT_PARAM_NAMESPACE

} // namespace streams_boost

#endif // STREAMS_BOOST_RT_CLA_VALIDATION_IPP_070604GER
