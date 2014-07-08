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
//  Description : defines model of parameter with single char name
// ***************************************************************************

#ifndef STREAMS_BOOST_RT_CLA_CHAR_PARAMETER_HPP_062604GER
#define STREAMS_BOOST_RT_CLA_CHAR_PARAMETER_HPP_062604GER

// Boost.Runtime.Parameter
#include <streams_boost/test/utils/runtime/config.hpp>
#include <streams_boost/test/utils/runtime/validation.hpp>

#include <streams_boost/test/utils/runtime/cla/basic_parameter.hpp>
#include <streams_boost/test/utils/runtime/cla/id_policy.hpp>

namespace streams_boost {

namespace STREAMS_BOOST_RT_PARAM_NAMESPACE {

namespace cla {

// ************************************************************************** //
// **************               char_name_policy               ************** //
// ************************************************************************** //

class char_name_policy : public basic_naming_policy {
public:
    // Constructor
    char_name_policy();
    STREAMS_BOOST_RT_PARAM_UNNEEDED_VIRTUAL ~char_name_policy() {}

    // policy interface
    virtual bool    conflict_with( identification_policy const& ) const;

    // Accept modifier
    template<typename Modifier>
    void            accept_modifier( Modifier const& m )
    {
        basic_naming_policy::accept_modifier( m );

        STREAMS_BOOST_RT_PARAM_VALIDATE_LOGIC( p_name->size() <= 1, "Invalid parameter name "  << p_name );
    }
};

// ************************************************************************** //
// **************          runtime::cla::char_parameter        ************** //
// ************************************************************************** //

template<typename T>
class char_parameter_t : public basic_parameter<T,char_name_policy> {
    typedef basic_parameter<T,char_name_policy> base;
public:
    // Constructors
    explicit    char_parameter_t( char_type name ) : base( cstring( &name, 1 ) ) {}
};

//____________________________________________________________________________//

template<typename T>
inline shared_ptr<char_parameter_t<T> >
char_parameter( char_type name )
{
    return shared_ptr<char_parameter_t<T> >( new char_parameter_t<T>( name ) );
}

//____________________________________________________________________________//

inline shared_ptr<char_parameter_t<cstring> >
char_parameter( char_type name )
{
    return shared_ptr<char_parameter_t<cstring> >( new char_parameter_t<cstring>( name ) );
}

//____________________________________________________________________________//

} // namespace cla

} // namespace STREAMS_BOOST_RT_PARAM_NAMESPACE

} // namespace streams_boost

#ifndef STREAMS_BOOST_RT_PARAM_OFFLINE

#  define STREAMS_BOOST_RT_PARAM_INLINE inline
#  include <streams_boost/test/utils/runtime/cla/char_parameter.ipp>

#endif

#endif // STREAMS_BOOST_RT_CLA_CHAR_PARAMETER_HPP_062604GER
