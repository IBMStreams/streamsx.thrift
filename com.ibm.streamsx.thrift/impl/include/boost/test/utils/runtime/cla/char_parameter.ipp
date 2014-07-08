//  (C) Copyright Gennadiy Rozental 2005-2008.
//  Use, modification, and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org/libs/test for the library home page.
//
//  File        : $RCSfile$
//
//  Version     : $Revision: 54633 $
//
//  Description : implements model of parameter with single char name
// ***************************************************************************

#ifndef STREAMS_BOOST_RT_CLA_CHAR_PARAMETER_IPP_062904GER
#define STREAMS_BOOST_RT_CLA_CHAR_PARAMETER_IPP_062904GER

// Boost.Runtime.Parameter
#include <streams_boost/test/utils/runtime/config.hpp>

#include <streams_boost/test/utils/runtime/cla/char_parameter.hpp>

namespace streams_boost {

namespace STREAMS_BOOST_RT_PARAM_NAMESPACE {

namespace cla {

// ************************************************************************** //
// **************               char_name_policy               ************** //
// ************************************************************************** //

STREAMS_BOOST_RT_PARAM_INLINE 
char_name_policy::char_name_policy()
: basic_naming_policy( rtti::type_id<char_name_policy>() )
{
    assign_op( p_prefix.value, STREAMS_BOOST_RT_PARAM_CSTRING_LITERAL( "-" ), 0 );
}

//____________________________________________________________________________//

STREAMS_BOOST_RT_PARAM_INLINE bool
char_name_policy::conflict_with( identification_policy const& id ) const
{
    return id.p_type_id == p_type_id && 
           p_name == static_cast<char_name_policy const&>( id ).p_name;
}

//____________________________________________________________________________//

} // namespace cla

} // namespace STREAMS_BOOST_RT_PARAM_NAMESPACE

} // namespace streams_boost

#endif // STREAMS_BOOST_RT_CLA_CHAR_PARAMETER_IPP_062904GER
