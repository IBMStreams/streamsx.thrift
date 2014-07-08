//  (C) Copyright Gennadiy Rozental 2005-2008.
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE_1_0.txt or copy at 
//  http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org/libs/test for the library home page.
//
//  File        : $RCSfile$
//
//  Version     : $Revision: 54633 $
//
//  Description : defines framework interface
// ***************************************************************************

#ifndef STREAMS_BOOST_TEST_FRAMEWORK_HPP_020805GER
#define STREAMS_BOOST_TEST_FRAMEWORK_HPP_020805GER

// Boost.Test
#include <streams_boost/test/detail/global_typedef.hpp>
#include <streams_boost/test/detail/fwd_decl.hpp>
#include <streams_boost/test/utils/trivial_singleton.hpp>

#include <streams_boost/test/detail/suppress_warnings.hpp>

// STL
#include <stdexcept>

//____________________________________________________________________________//

namespace streams_boost {

namespace unit_test {

// ************************************************************************** //
// **************              init_unit_test_func             ************** //
// ************************************************************************** //

#ifdef STREAMS_BOOST_TEST_ALTERNATIVE_INIT_API
typedef bool        (*init_unit_test_func)();
#else
typedef test_suite* (*init_unit_test_func)( int, char* [] );
#endif

// ************************************************************************** //
// **************                   framework                  ************** //
// ************************************************************************** //

namespace framework {

// initialization
STREAMS_BOOST_TEST_DECL void    init( init_unit_test_func init_func, int argc, char* argv[] );
STREAMS_BOOST_TEST_DECL bool    is_initialized();

// mutation access methods
STREAMS_BOOST_TEST_DECL void    register_test_unit( test_case* tc );
STREAMS_BOOST_TEST_DECL void    register_test_unit( test_suite* ts );
STREAMS_BOOST_TEST_DECL void    deregister_test_unit( test_unit* tu );
STREAMS_BOOST_TEST_DECL void    clear();

STREAMS_BOOST_TEST_DECL void    register_observer( test_observer& );
STREAMS_BOOST_TEST_DECL void    deregister_observer( test_observer& );
STREAMS_BOOST_TEST_DECL void    reset_observers();

STREAMS_BOOST_TEST_DECL master_test_suite_t& master_test_suite();

// constant access methods
STREAMS_BOOST_TEST_DECL test_case const&    current_test_case();

STREAMS_BOOST_TEST_DECL test_unit&  get( test_unit_id, test_unit_type );
template<typename UnitType>
UnitType&               get( test_unit_id id )
{
    return static_cast<UnitType&>( get( id, static_cast<test_unit_type>(UnitType::type) ) );
}

// test initiation
STREAMS_BOOST_TEST_DECL void    run( test_unit_id = INV_TEST_UNIT_ID, bool continue_test = true );
STREAMS_BOOST_TEST_DECL void    run( test_unit const*, bool continue_test = true );

// public test events dispatchers
STREAMS_BOOST_TEST_DECL void    assertion_result( bool passed );
STREAMS_BOOST_TEST_DECL void    exception_caught( execution_exception const& );
STREAMS_BOOST_TEST_DECL void    test_unit_aborted( test_unit const& );

// ************************************************************************** //
// **************                framework errors              ************** //
// ************************************************************************** //

struct internal_error : std::runtime_error {
    internal_error( const_string m ) : std::runtime_error( std::string( m.begin(), m.size() ) ) {}
};

struct setup_error : std::runtime_error {
    setup_error( const_string m ) : std::runtime_error( std::string( m.begin(), m.size() ) ) {}
};

#define STREAMS_BOOST_TEST_SETUP_ASSERT( cond, msg ) if( cond ) {} else throw unit_test::framework::setup_error( msg )

struct nothing_to_test {}; // not really an error

} // namespace framework

} // unit_test

} // namespace streams_boost

//____________________________________________________________________________//

#include <streams_boost/test/detail/enable_warnings.hpp>

#endif // STREAMS_BOOST_TEST_FRAMEWORK_HPP_020805GER

