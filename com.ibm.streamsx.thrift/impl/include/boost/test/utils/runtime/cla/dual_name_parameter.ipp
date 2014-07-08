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
//  Description : implements model of generic parameter with dual naming
// ***************************************************************************

#ifndef STREAMS_BOOST_RT_CLA_DUAL_NAME_PARAMETER_IPP_062904GER
#define STREAMS_BOOST_RT_CLA_DUAL_NAME_PARAMETER_IPP_062904GER

// Boost.Runtime.Parameter
#include <streams_boost/test/utils/runtime/config.hpp>
#include <streams_boost/test/utils/runtime/validation.hpp>

#include <streams_boost/test/utils/runtime/cla/dual_name_parameter.hpp>

namespace streams_boost {

namespace STREAMS_BOOST_RT_PARAM_NAMESPACE {

namespace cla {

// ************************************************************************** //
// **************               dual_name_policy               ************** //
// ************************************************************************** //

STREAMS_BOOST_RT_PARAM_INLINE 
dual_name_policy::dual_name_policy()
{
    m_primary.accept_modifier( prefix = STREAMS_BOOST_RT_PARAM_CSTRING_LITERAL( "--" ) );
    m_secondary.accept_modifier( prefix = STREAMS_BOOST_RT_PARAM_CSTRING_LITERAL( "-" ) );
}

//____________________________________________________________________________//

namespace {

template<typename K>
inline void
split( string_name_policy& snp, char_name_policy& cnp, cstring src, K const& k )
{
    cstring::iterator sep = std::find( src.begin(), src.end(), STREAMS_BOOST_RT_PARAM_LITERAL( '|' ) );
    
    if( sep != src.begin() )
        snp.accept_modifier( k = cstring( src.begin(), sep ) );

    if( sep != src.end() )
        cnp.accept_modifier( k = cstring( sep+1, src.end() ) );
}

} // local namespace

STREAMS_BOOST_RT_PARAM_INLINE void
dual_name_policy::set_prefix( cstring src )
{
    split( m_primary, m_secondary, src, prefix );
}

//____________________________________________________________________________//

STREAMS_BOOST_RT_PARAM_INLINE void
dual_name_policy::set_name( cstring src )
{
    split( m_primary, m_secondary, src, name );
}

//____________________________________________________________________________//

STREAMS_BOOST_RT_PARAM_INLINE void
dual_name_policy::set_separator( cstring src )
{
    split( m_primary, m_secondary, src, separator );
}

//____________________________________________________________________________//

} // namespace cla

} // namespace STREAMS_BOOST_RT_PARAM_NAMESPACE

} // namespace streams_boost

#endif // STREAMS_BOOST_RT_CLA_DUAL_NAME_PARAMETER_IPP_062904GER
