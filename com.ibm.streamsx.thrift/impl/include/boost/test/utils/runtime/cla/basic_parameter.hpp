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
//  Description : generic custom parameter generator
// ***************************************************************************

#ifndef STREAMS_BOOST_RT_CLA_BASIC_PARAMETER_HPP_062604GER
#define STREAMS_BOOST_RT_CLA_BASIC_PARAMETER_HPP_062604GER

// Boost.Runtime.Parameter
#include <streams_boost/test/utils/runtime/config.hpp>

#include <streams_boost/test/utils/runtime/cla/typed_parameter.hpp>

// Boost.Test
#include <streams_boost/test/utils/rtti.hpp>

// Boost
#include <streams_boost/utility/base_from_member.hpp>

namespace streams_boost {

namespace STREAMS_BOOST_RT_PARAM_NAMESPACE {

namespace cla {

// ************************************************************************** //
// **************         runtime::cla::basic_parameter        ************** //
// ************************************************************************** //

template<typename T, typename IdPolicy>
class basic_parameter : private base_from_member<IdPolicy>, public typed_parameter<T> {
public:
    // Constructors
    explicit    basic_parameter( cstring n ) 
    : base_from_member<IdPolicy>()
    , typed_parameter<T>( base_from_member<IdPolicy>::member )
    {
        this->accept_modifier( name = n );
    }

    // parameter properties modification
    template<typename Modifier>
    void        accept_modifier( Modifier const& m )
    {
        typed_parameter<T>::accept_modifier( m );

        base_from_member<IdPolicy>::member.accept_modifier( m );
    }
};

//____________________________________________________________________________//

#define STREAMS_BOOST_RT_CLA_NAMED_PARAM_GENERATORS( param_type )                                       \
template<typename T>                                                                            \
inline shared_ptr<param_type ## _t<T> >                                                         \
param_type( cstring name = cstring() )                                                          \
{                                                                                               \
    return shared_ptr<param_type ## _t<T> >( new param_type ## _t<T>( name ) );                 \
}                                                                                               \
                                                                                                \
inline shared_ptr<param_type ## _t<cstring> >                                                   \
param_type( cstring name = cstring() )                                                          \
{                                                                                               \
    return shared_ptr<param_type ## _t<cstring> >( new param_type ## _t<cstring>( name ) );     \
}                                                                                               \
/**/

//____________________________________________________________________________//

} // namespace cla

} // namespace STREAMS_BOOST_RT_PARAM_NAMESPACE

} // namespace streams_boost

#endif // STREAMS_BOOST_RT_CLA_BASIC_PARAMETER_HPP_062604GER
