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
//  Description : input validation helpers definition
// ***************************************************************************

#ifndef STREAMS_BOOST_RT_CLA_VALIDATION_HPP_062604GER
#define STREAMS_BOOST_RT_CLA_VALIDATION_HPP_062604GER

// Boost.Runtime.Parameter
#include <streams_boost/test/utils/runtime/config.hpp>

#include <streams_boost/test/utils/runtime/cla/fwd.hpp>

namespace streams_boost {

namespace STREAMS_BOOST_RT_PARAM_NAMESPACE {

namespace cla {

// ************************************************************************** //
// **************       runtime::cla::report_input_error       ************** //
// ************************************************************************** //

void report_input_error( argv_traverser const& tr, format_stream& msg );

//____________________________________________________________________________//

#define STREAMS_BOOST_RT_CLA_VALIDATE_INPUT( b, tr, msg ) \
    if( b ) ; else ::streams_boost::STREAMS_BOOST_RT_PARAM_NAMESPACE::cla::report_input_error( tr, format_stream().ref() << msg )

//____________________________________________________________________________//

} // namespace cla

} // namespace STREAMS_BOOST_RT_PARAM_NAMESPACE

} // namespace streams_boost

#ifndef STREAMS_BOOST_RT_PARAM_OFFLINE

#  define STREAMS_BOOST_RT_PARAM_INLINE inline
#  include <streams_boost/test/utils/runtime/cla/validation.ipp>

#endif

#endif // STREAMS_BOOST_RT_CLA_VALIDATION_HPP_062604GER
