//  (C) Copyright Gennadiy Rozental 2001-2008.
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE_1_0.txt or copy at 
//  http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org/libs/test for the library home page.
//
//  File        : $RCSfile$
//
//  Version     : $Revision: 57992 $
//
//  Description : defines Unit Test Framework public API
// ***************************************************************************

#ifndef STREAMS_BOOST_TEST_UNIT_TEST_SUITE_HPP_071894GER
#define STREAMS_BOOST_TEST_UNIT_TEST_SUITE_HPP_071894GER

// Boost.Test
#include <streams_boost/test/unit_test_suite_impl.hpp>
#include <streams_boost/test/framework.hpp>

//____________________________________________________________________________//

// ************************************************************************** //
// **************    Non-auto (explicit) test case interface   ************** //
// ************************************************************************** //

#define STREAMS_BOOST_TEST_CASE( test_function ) \
streams_boost::unit_test::make_test_case( streams_boost::unit_test::callback0<>(test_function), STREAMS_BOOST_TEST_STRINGIZE( test_function ) )
#define STREAMS_BOOST_CLASS_TEST_CASE( test_function, tc_instance ) \
streams_boost::unit_test::make_test_case((test_function), STREAMS_BOOST_TEST_STRINGIZE( test_function ), tc_instance )

// ************************************************************************** //
// **************               STREAMS_BOOST_TEST_SUITE               ************** //
// ************************************************************************** //

#define STREAMS_BOOST_TEST_SUITE( testsuite_name ) \
( new streams_boost::unit_test::test_suite( testsuite_name ) )

// ************************************************************************** //
// **************             STREAMS_BOOST_AUTO_TEST_SUITE            ************** //
// ************************************************************************** //

#define STREAMS_BOOST_AUTO_TEST_SUITE( suite_name )                             \
namespace suite_name {                                                  \
STREAMS_BOOST_AUTO_TU_REGISTRAR( suite_name )( STREAMS_BOOST_STRINGIZE( suite_name ) ); \
/**/

// ************************************************************************** //
// **************            STREAMS_BOOST_FIXTURE_TEST_SUITE          ************** //
// ************************************************************************** //

#define STREAMS_BOOST_FIXTURE_TEST_SUITE( suite_name, F )                       \
STREAMS_BOOST_AUTO_TEST_SUITE( suite_name )                                     \
typedef F STREAMS_BOOST_AUTO_TEST_CASE_FIXTURE;                                 \
/**/

// ************************************************************************** //
// **************           STREAMS_BOOST_AUTO_TEST_SUITE_END          ************** //
// ************************************************************************** //

#define STREAMS_BOOST_AUTO_TEST_SUITE_END()                                     \
STREAMS_BOOST_AUTO_TU_REGISTRAR( STREAMS_BOOST_JOIN( end_suite, __LINE__ ) )( 1 );      \
}                                                                       \
/**/

// ************************************************************************** //
// **************    STREAMS_BOOST_AUTO_TEST_CASE_EXPECTED_FAILURES    ************** //
// ************************************************************************** //

#define STREAMS_BOOST_AUTO_TEST_CASE_EXPECTED_FAILURES( test_name, n )          \
struct STREAMS_BOOST_AUTO_TC_UNIQUE_ID( test_name );                            \
                                                                        \
static struct STREAMS_BOOST_JOIN( test_name, _exp_fail_num_spec )               \
: streams_boost::unit_test::ut_detail::                                         \
  auto_tc_exp_fail<STREAMS_BOOST_AUTO_TC_UNIQUE_ID( test_name ) >               \
{                                                                       \
    STREAMS_BOOST_JOIN( test_name, _exp_fail_num_spec )()                       \
    : streams_boost::unit_test::ut_detail::                                     \
      auto_tc_exp_fail<STREAMS_BOOST_AUTO_TC_UNIQUE_ID( test_name ) >( n )      \
    {}                                                                  \
} STREAMS_BOOST_JOIN( test_name, _exp_fail_num_spec_inst );                     \
                                                                        \
/**/

// ************************************************************************** //
// **************            STREAMS_BOOST_FIXTURE_TEST_CASE           ************** //
// ************************************************************************** //

#define STREAMS_BOOST_FIXTURE_TEST_CASE( test_name, F )                         \
struct test_name : public F { void test_method(); };                    \
                                                                        \
static void STREAMS_BOOST_AUTO_TC_INVOKER( test_name )()                        \
{                                                                       \
    test_name t;                                                        \
    t.test_method();                                                    \
}                                                                       \
                                                                        \
struct STREAMS_BOOST_AUTO_TC_UNIQUE_ID( test_name ) {};                         \
                                                                        \
STREAMS_BOOST_AUTO_TU_REGISTRAR( test_name )(                                   \
    streams_boost::unit_test::make_test_case(                                   \
        &STREAMS_BOOST_AUTO_TC_INVOKER( test_name ), #test_name ),              \
    streams_boost::unit_test::ut_detail::auto_tc_exp_fail<                      \
        STREAMS_BOOST_AUTO_TC_UNIQUE_ID( test_name )>::instance()->value() );   \
                                                                        \
void test_name::test_method()                                           \
/**/

// ************************************************************************** //
// **************             STREAMS_BOOST_AUTO_TEST_CASE             ************** //
// ************************************************************************** //

#define STREAMS_BOOST_AUTO_TEST_CASE( test_name )                               \
STREAMS_BOOST_FIXTURE_TEST_CASE( test_name, STREAMS_BOOST_AUTO_TEST_CASE_FIXTURE )
/**/

// ************************************************************************** //
// **************       STREAMS_BOOST_FIXTURE_TEST_CASE_TEMPLATE       ************** //
// ************************************************************************** //

#define STREAMS_BOOST_FIXTURE_TEST_CASE_TEMPLATE( test_name, type_name, TL, F ) \
template<typename type_name>                                            \
struct test_name : public F                                             \
{ void test_method(); };                                                \
                                                                        \
struct STREAMS_BOOST_AUTO_TC_INVOKER( test_name ) {                             \
    template<typename TestType>                                         \
    static void run( streams_boost::type<TestType>* = 0 )                       \
    {                                                                   \
        test_name<TestType> t;                                          \
        t.test_method();                                                \
    }                                                                   \
};                                                                      \
                                                                        \
STREAMS_BOOST_AUTO_TU_REGISTRAR( test_name )(                                   \
    streams_boost::unit_test::ut_detail::template_test_case_gen<                \
        STREAMS_BOOST_AUTO_TC_INVOKER( test_name ),TL >(                        \
          STREAMS_BOOST_STRINGIZE( test_name ) ) );                             \
                                                                        \
template<typename type_name>                                            \
void test_name<type_name>::test_method()                                \
/**/

// ************************************************************************** //
// **************        STREAMS_BOOST_AUTO_TEST_CASE_TEMPLATE         ************** //
// ************************************************************************** //

#define STREAMS_BOOST_AUTO_TEST_CASE_TEMPLATE( test_name, type_name, TL )       \
STREAMS_BOOST_FIXTURE_TEST_CASE_TEMPLATE( test_name, type_name, TL, STREAMS_BOOST_AUTO_TEST_CASE_FIXTURE )

// ************************************************************************** //
// **************           STREAMS_BOOST_TEST_CASE_TEMPLATE           ************** //
// ************************************************************************** //

#define STREAMS_BOOST_TEST_CASE_TEMPLATE( name, typelist )                          \
    streams_boost::unit_test::ut_detail::template_test_case_gen<name,typelist >(    \
        STREAMS_BOOST_TEST_STRINGIZE( name ) )                                      \
/**/

// ************************************************************************** //
// **************      STREAMS_BOOST_TEST_CASE_TEMPLATE_FUNCTION       ************** //
// ************************************************************************** //

#define STREAMS_BOOST_TEST_CASE_TEMPLATE_FUNCTION( name, type_name )    \
template<typename type_name>                                    \
void STREAMS_BOOST_JOIN( name, _impl )( streams_boost::type<type_name>* );      \
                                                                \
struct name {                                                   \
    template<typename TestType>                                 \
    static void run( streams_boost::type<TestType>* frwrd = 0 )         \
    {                                                           \
       STREAMS_BOOST_JOIN( name, _impl )( frwrd );                      \
    }                                                           \
};                                                              \
                                                                \
template<typename type_name>                                    \
void STREAMS_BOOST_JOIN( name, _impl )( streams_boost::type<type_name>* )       \
/**/

// ************************************************************************** //
// **************              STREAMS_BOOST_GLOBAL_FIXURE             ************** //
// ************************************************************************** //

#define STREAMS_BOOST_GLOBAL_FIXTURE( F ) \
static streams_boost::unit_test::ut_detail::global_fixture_impl<F> STREAMS_BOOST_JOIN( gf_, F ) ; \
/**/

// ************************************************************************** //
// **************         STREAMS_BOOST_AUTO_TEST_CASE_FIXTURE         ************** //
// ************************************************************************** //

namespace streams_boost { namespace unit_test { namespace ut_detail {

struct nil_t {};

} // namespace ut_detail
} // unit_test
} // namespace streams_boost

// Intentionally is in global namespace, so that FIXURE_TEST_SUITE can reset it in user code.
typedef ::streams_boost::unit_test::ut_detail::nil_t STREAMS_BOOST_AUTO_TEST_CASE_FIXTURE;

// ************************************************************************** //
// **************   Auto registration facility helper macros   ************** //
// ************************************************************************** //

#define STREAMS_BOOST_AUTO_TU_REGISTRAR( test_name )    \
static streams_boost::unit_test::ut_detail::auto_test_unit_registrar STREAMS_BOOST_JOIN( STREAMS_BOOST_JOIN( test_name, _registrar ), __LINE__ )
#define STREAMS_BOOST_AUTO_TC_INVOKER( test_name )      STREAMS_BOOST_JOIN( test_name, _invoker )
#define STREAMS_BOOST_AUTO_TC_UNIQUE_ID( test_name )    STREAMS_BOOST_JOIN( test_name, _id )

// ************************************************************************** //
// **************                STREAMS_BOOST_TEST_MAIN               ************** //
// ************************************************************************** //

#if defined(STREAMS_BOOST_TEST_MAIN)

#ifdef STREAMS_BOOST_TEST_ALTERNATIVE_INIT_API
bool init_unit_test()                   {
#else
::streams_boost::unit_test::test_suite*
init_unit_test_suite( int, char* [] )   {
#endif

#ifdef STREAMS_BOOST_TEST_MODULE
    using namespace ::streams_boost::unit_test;
    assign_op( framework::master_test_suite().p_name.value, STREAMS_BOOST_TEST_STRINGIZE( STREAMS_BOOST_TEST_MODULE ).trim( "\"" ), 0 );
    
#endif

#ifdef STREAMS_BOOST_TEST_ALTERNATIVE_INIT_API
    return true;
}
#else
    return 0;
}
#endif

#endif

//____________________________________________________________________________//

#endif // STREAMS_BOOST_TEST_UNIT_TEST_SUITE_HPP_071894GER

