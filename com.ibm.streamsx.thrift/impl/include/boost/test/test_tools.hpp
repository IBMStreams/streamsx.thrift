//  (C) Copyright Gennadiy Rozental 2001-2008.
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE_1_0.txt or copy at 
//  http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org/libs/test for the library home page.
//
//  File        : $RCSfile$
//
//  Version     : $Revision: 54633 $
//
//  Description : contains definition for all test tools in test toolbox
// ***************************************************************************

#ifndef STREAMS_BOOST_TEST_TEST_TOOLS_HPP_012705GER
#define STREAMS_BOOST_TEST_TEST_TOOLS_HPP_012705GER

// Boost.Test
#include <streams_boost/test/predicate_result.hpp>
#include <streams_boost/test/unit_test_log.hpp>
#include <streams_boost/test/floating_point_comparison.hpp>

#include <streams_boost/test/detail/config.hpp>
#include <streams_boost/test/detail/global_typedef.hpp>
#include <streams_boost/test/detail/workaround.hpp>

#include <streams_boost/test/utils/wrap_stringstream.hpp>
#include <streams_boost/test/utils/basic_cstring/io.hpp>
#include <streams_boost/test/utils/lazy_ostream.hpp>

// Boost
#include <streams_boost/preprocessor/seq/for_each.hpp>
#include <streams_boost/preprocessor/seq/size.hpp>
#include <streams_boost/preprocessor/seq/enum.hpp> 
#include <streams_boost/preprocessor/repetition/repeat.hpp>
#include <streams_boost/preprocessor/punctuation/comma_if.hpp>
#include <streams_boost/preprocessor/arithmetic/add.hpp>

#include <streams_boost/limits.hpp>

#include <streams_boost/type_traits/is_array.hpp>
#include <streams_boost/type_traits/is_function.hpp>
#include <streams_boost/type_traits/is_abstract.hpp>

#include <streams_boost/mpl/or.hpp>

// STL
#include <cstddef>          // for std::size_t
#include <iosfwd>
#include <ios>              // for std::boolalpha
#include <climits>          // for CHAR_BIT

#ifdef STREAMS_BOOST_MSVC
# pragma warning(disable: 4127) // conditional expression is constant
#endif

#include <streams_boost/test/detail/suppress_warnings.hpp>

//____________________________________________________________________________//

// ************************************************************************** //
// **************                    TOOL BOX                  ************** //
// ************************************************************************** //

// In macros below following argument abbreviations are used:
// P - predicate
// M - message
// S - statement
// E - exception
// L - left argument
// R - right argument
// TL - tool level
// CT - check type
// ARGS - arguments list

#define STREAMS_BOOST_TEST_TOOL_IMPL( func, P, check_descr, TL, CT )            \
    ::streams_boost::test_tools::tt_detail::func(                               \
        P,                                                              \
        ::streams_boost::unit_test::lazy_ostream::instance() << check_descr,    \
        STREAMS_BOOST_TEST_L(__FILE__),                                         \
        static_cast<std::size_t>(__LINE__),                             \
        ::streams_boost::test_tools::tt_detail::TL,                             \
        ::streams_boost::test_tools::tt_detail::CT                              \
/**/

//____________________________________________________________________________//

#define STREAMS_BOOST_CHECK_IMPL( P, check_descr, TL, CT )                  \
do {                                                                \
    STREAMS_BOOST_TEST_PASSPOINT();                                         \
    STREAMS_BOOST_TEST_TOOL_IMPL( check_impl, P, check_descr, TL, CT ), 0 );\
} while( ::streams_boost::test_tools::dummy_cond )                          \
/**/

//____________________________________________________________________________//

#define STREAMS_BOOST_TEST_PASS_ARG_INFO( r, data, arg ) , arg, STREAMS_BOOST_STRINGIZE( arg )

#define STREAMS_BOOST_CHECK_WITH_ARGS_IMPL( P, check_descr, TL, CT, ARGS )  \
do {                                                                \
    STREAMS_BOOST_TEST_PASSPOINT();                                         \
    STREAMS_BOOST_TEST_TOOL_IMPL( check_frwd, P, check_descr, TL, CT )      \
    STREAMS_BOOST_PP_SEQ_FOR_EACH( STREAMS_BOOST_TEST_PASS_ARG_INFO, '_', ARGS ) ); \
} while( ::streams_boost::test_tools::dummy_cond )                          \
/**/

//____________________________________________________________________________//

#define STREAMS_BOOST_WARN( P )                     STREAMS_BOOST_CHECK_IMPL( (P), STREAMS_BOOST_TEST_STRINGIZE( P ), WARN, CHECK_PRED )
#define STREAMS_BOOST_CHECK( P )                    STREAMS_BOOST_CHECK_IMPL( (P), STREAMS_BOOST_TEST_STRINGIZE( P ), CHECK, CHECK_PRED )
#define STREAMS_BOOST_REQUIRE( P )                  STREAMS_BOOST_CHECK_IMPL( (P), STREAMS_BOOST_TEST_STRINGIZE( P ), REQUIRE, CHECK_PRED )

//____________________________________________________________________________//

#define STREAMS_BOOST_WARN_MESSAGE( P, M )          STREAMS_BOOST_CHECK_IMPL( (P), M, WARN, CHECK_MSG )
#define STREAMS_BOOST_CHECK_MESSAGE( P, M )         STREAMS_BOOST_CHECK_IMPL( (P), M, CHECK, CHECK_MSG )
#define STREAMS_BOOST_REQUIRE_MESSAGE( P, M )       STREAMS_BOOST_CHECK_IMPL( (P), M, REQUIRE, CHECK_MSG )

//____________________________________________________________________________//

#define STREAMS_BOOST_ERROR( M )                    STREAMS_BOOST_CHECK_MESSAGE( false, M )
#define STREAMS_BOOST_FAIL( M )                     STREAMS_BOOST_REQUIRE_MESSAGE( false, M )

//____________________________________________________________________________//

#define STREAMS_BOOST_CHECK_THROW_IMPL( S, E, P, prefix, TL )                                                   \
    try {                                                                                               \
        STREAMS_BOOST_TEST_PASSPOINT();                                                                         \
        S;                                                                                              \
        STREAMS_BOOST_CHECK_IMPL( false, "exception " STREAMS_BOOST_STRINGIZE( E ) " is expected", TL, CHECK_MSG ); }   \
    catch( E const& ex ) {                                                                              \
        ::streams_boost::unit_test::ut_detail::ignore_unused_variable_warning( ex );                            \
        STREAMS_BOOST_CHECK_IMPL( P, prefix STREAMS_BOOST_STRINGIZE( E ) " is caught", TL, CHECK_MSG );                 \
    }                                                                                                   \
/**/

//____________________________________________________________________________//

#define STREAMS_BOOST_WARN_THROW( S, E )            STREAMS_BOOST_CHECK_THROW_IMPL( S, E, true, "exception ", WARN )
#define STREAMS_BOOST_CHECK_THROW( S, E )           STREAMS_BOOST_CHECK_THROW_IMPL( S, E, true, "exception ", CHECK )
#define STREAMS_BOOST_REQUIRE_THROW( S, E )         STREAMS_BOOST_CHECK_THROW_IMPL( S, E, true, "exception ", REQUIRE )

//____________________________________________________________________________//

#define STREAMS_BOOST_WARN_EXCEPTION( S, E, P )     STREAMS_BOOST_CHECK_THROW_IMPL( S, E, P( ex ), "incorrect exception ", WARN )
#define STREAMS_BOOST_CHECK_EXCEPTION( S, E, P )    STREAMS_BOOST_CHECK_THROW_IMPL( S, E, P( ex ), "incorrect exception ", CHECK )
#define STREAMS_BOOST_REQUIRE_EXCEPTION( S, E, P )  STREAMS_BOOST_CHECK_THROW_IMPL( S, E, P( ex ), "incorrect exception ", REQUIRE )

//____________________________________________________________________________//

#define STREAMS_BOOST_CHECK_NO_THROW_IMPL( S, TL )                                                          \
    try {                                                                                           \
        S;                                                                                          \
        STREAMS_BOOST_CHECK_IMPL( true, "no exceptions thrown by " STREAMS_BOOST_STRINGIZE( S ), TL, CHECK_MSG ); } \
    catch( ... ) {                                                                                  \
        STREAMS_BOOST_CHECK_IMPL( false, "exception thrown by " STREAMS_BOOST_STRINGIZE( S ), TL, CHECK_MSG );      \
    }                                                                                               \
/**/

#define STREAMS_BOOST_WARN_NO_THROW( S )            STREAMS_BOOST_CHECK_NO_THROW_IMPL( S, WARN )
#define STREAMS_BOOST_CHECK_NO_THROW( S )           STREAMS_BOOST_CHECK_NO_THROW_IMPL( S, CHECK )
#define STREAMS_BOOST_REQUIRE_NO_THROW( S )         STREAMS_BOOST_CHECK_NO_THROW_IMPL( S, REQUIRE )

//____________________________________________________________________________//

#define STREAMS_BOOST_WARN_EQUAL( L, R ) \
    STREAMS_BOOST_CHECK_WITH_ARGS_IMPL( ::streams_boost::test_tools::tt_detail::equal_impl_frwd(), "", WARN, CHECK_EQUAL, (L)(R) )
#define STREAMS_BOOST_CHECK_EQUAL( L, R ) \
    STREAMS_BOOST_CHECK_WITH_ARGS_IMPL( ::streams_boost::test_tools::tt_detail::equal_impl_frwd(), "", CHECK, CHECK_EQUAL, (L)(R) )
#define STREAMS_BOOST_REQUIRE_EQUAL( L, R ) \
    STREAMS_BOOST_CHECK_WITH_ARGS_IMPL( ::streams_boost::test_tools::tt_detail::equal_impl_frwd(), "", REQUIRE, CHECK_EQUAL, (L)(R) )

//____________________________________________________________________________//

#define STREAMS_BOOST_WARN_NE( L, R ) \
    STREAMS_BOOST_CHECK_WITH_ARGS_IMPL( ::streams_boost::test_tools::tt_detail::ne_impl(), "", WARN, CHECK_NE, (L)(R) )
#define STREAMS_BOOST_CHECK_NE( L, R ) \
    STREAMS_BOOST_CHECK_WITH_ARGS_IMPL( ::streams_boost::test_tools::tt_detail::ne_impl(), "", CHECK, CHECK_NE, (L)(R) )
#define STREAMS_BOOST_REQUIRE_NE( L, R ) \
    STREAMS_BOOST_CHECK_WITH_ARGS_IMPL( ::streams_boost::test_tools::tt_detail::ne_impl(), "", REQUIRE, CHECK_NE, (L)(R) )

//____________________________________________________________________________//

#define STREAMS_BOOST_WARN_LT( L, R ) \
    STREAMS_BOOST_CHECK_WITH_ARGS_IMPL( ::streams_boost::test_tools::tt_detail::lt_impl(), "", WARN, CHECK_LT, (L)(R) )
#define STREAMS_BOOST_CHECK_LT( L, R ) \
    STREAMS_BOOST_CHECK_WITH_ARGS_IMPL( ::streams_boost::test_tools::tt_detail::lt_impl(), "", CHECK, CHECK_LT, (L)(R) )
#define STREAMS_BOOST_REQUIRE_LT( L, R ) \
    STREAMS_BOOST_CHECK_WITH_ARGS_IMPL( ::streams_boost::test_tools::tt_detail::lt_impl(), "", REQUIRE, CHECK_LT, (L)(R) )

//____________________________________________________________________________//

#define STREAMS_BOOST_WARN_LE( L, R ) \
    STREAMS_BOOST_CHECK_WITH_ARGS_IMPL( ::streams_boost::test_tools::tt_detail::le_impl(), "", WARN, CHECK_LE, (L)(R) )
#define STREAMS_BOOST_CHECK_LE( L, R ) \
    STREAMS_BOOST_CHECK_WITH_ARGS_IMPL( ::streams_boost::test_tools::tt_detail::le_impl(), "", CHECK, CHECK_LE, (L)(R) )
#define STREAMS_BOOST_REQUIRE_LE( L, R ) \
    STREAMS_BOOST_CHECK_WITH_ARGS_IMPL( ::streams_boost::test_tools::tt_detail::le_impl(), "", REQUIRE, CHECK_LE, (L)(R) )

//____________________________________________________________________________//

#define STREAMS_BOOST_WARN_GT( L, R ) \
    STREAMS_BOOST_CHECK_WITH_ARGS_IMPL( ::streams_boost::test_tools::tt_detail::gt_impl(), "", WARN, CHECK_GT, (L)(R) )
#define STREAMS_BOOST_CHECK_GT( L, R ) \
    STREAMS_BOOST_CHECK_WITH_ARGS_IMPL( ::streams_boost::test_tools::tt_detail::gt_impl(), "", CHECK, CHECK_GT, (L)(R) )
#define STREAMS_BOOST_REQUIRE_GT( L, R ) \
    STREAMS_BOOST_CHECK_WITH_ARGS_IMPL( ::streams_boost::test_tools::tt_detail::gt_impl(), "", REQUIRE, CHECK_GT, (L)(R) )

//____________________________________________________________________________//

#define STREAMS_BOOST_WARN_GE( L, R ) \
    STREAMS_BOOST_CHECK_WITH_ARGS_IMPL( ::streams_boost::test_tools::tt_detail::ge_impl(), "", WARN, CHECK_GE, (L)(R) )
#define STREAMS_BOOST_CHECK_GE( L, R ) \
    STREAMS_BOOST_CHECK_WITH_ARGS_IMPL( ::streams_boost::test_tools::tt_detail::ge_impl(), "", CHECK, CHECK_GE, (L)(R) )
#define STREAMS_BOOST_REQUIRE_GE( L, R ) \
    STREAMS_BOOST_CHECK_WITH_ARGS_IMPL( ::streams_boost::test_tools::tt_detail::ge_impl(), "", REQUIRE, CHECK_GE, (L)(R) )

//____________________________________________________________________________//

#define STREAMS_BOOST_WARN_CLOSE( L, R, T ) \
    STREAMS_BOOST_CHECK_WITH_ARGS_IMPL( ::streams_boost::test_tools::check_is_close, "", WARN, CHECK_CLOSE, \
        (L)(R)(::streams_boost::test_tools::percent_tolerance(T)) )
#define STREAMS_BOOST_CHECK_CLOSE( L, R, T ) \
    STREAMS_BOOST_CHECK_WITH_ARGS_IMPL( ::streams_boost::test_tools::check_is_close, "", CHECK, CHECK_CLOSE, \
        (L)(R)(::streams_boost::test_tools::percent_tolerance(T)) )
#define STREAMS_BOOST_REQUIRE_CLOSE( L, R, T ) \
    STREAMS_BOOST_CHECK_WITH_ARGS_IMPL( ::streams_boost::test_tools::check_is_close, "", REQUIRE, CHECK_CLOSE, \
        (L)(R)(::streams_boost::test_tools::percent_tolerance(T)) )

//____________________________________________________________________________//

#define STREAMS_BOOST_WARN_CLOSE_FRACTION( L, R, T ) \
    STREAMS_BOOST_CHECK_WITH_ARGS_IMPL( ::streams_boost::test_tools::check_is_close, "", WARN, CHECK_CLOSE_FRACTION, \
    (L)(R)(::streams_boost::test_tools::fraction_tolerance(T)) )
#define STREAMS_BOOST_CHECK_CLOSE_FRACTION( L, R, T ) \
    STREAMS_BOOST_CHECK_WITH_ARGS_IMPL( ::streams_boost::test_tools::check_is_close, "", CHECK, CHECK_CLOSE_FRACTION, \
    (L)(R)(::streams_boost::test_tools::fraction_tolerance(T)) )
#define STREAMS_BOOST_REQUIRE_CLOSE_FRACTION( L, R, T ) \
    STREAMS_BOOST_CHECK_WITH_ARGS_IMPL( ::streams_boost::test_tools::check_is_close, "", REQUIRE, CHECK_CLOSE_FRACTION, \
    (L)(R)(::streams_boost::test_tools::fraction_tolerance(T)) )

//____________________________________________________________________________//

#define STREAMS_BOOST_WARN_SMALL( FPV, T ) \
    STREAMS_BOOST_CHECK_WITH_ARGS_IMPL( ::streams_boost::test_tools::check_is_small, "", WARN, CHECK_SMALL, (FPV)(T) )
#define STREAMS_BOOST_CHECK_SMALL( FPV, T ) \
    STREAMS_BOOST_CHECK_WITH_ARGS_IMPL( ::streams_boost::test_tools::check_is_small, "", CHECK, CHECK_SMALL, (FPV)(T) )
#define STREAMS_BOOST_REQUIRE_SMALL( FPV, T ) \
    STREAMS_BOOST_CHECK_WITH_ARGS_IMPL( ::streams_boost::test_tools::check_is_small, "", REQUIRE, CHECK_SMALL, (FPV)(T) )

//____________________________________________________________________________//

#define STREAMS_BOOST_WARN_PREDICATE( P, ARGS ) \
    STREAMS_BOOST_CHECK_WITH_ARGS_IMPL( P, STREAMS_BOOST_TEST_STRINGIZE( P ), WARN, CHECK_PRED_WITH_ARGS, ARGS )
#define STREAMS_BOOST_CHECK_PREDICATE( P, ARGS ) \
    STREAMS_BOOST_CHECK_WITH_ARGS_IMPL( P, STREAMS_BOOST_TEST_STRINGIZE( P ), CHECK, CHECK_PRED_WITH_ARGS, ARGS )
#define STREAMS_BOOST_REQUIRE_PREDICATE( P, ARGS ) \
    STREAMS_BOOST_CHECK_WITH_ARGS_IMPL( P, STREAMS_BOOST_TEST_STRINGIZE( P ), REQUIRE, CHECK_PRED_WITH_ARGS, ARGS )

//____________________________________________________________________________//

#define STREAMS_BOOST_EQUAL_COLLECTIONS_IMPL( L_begin, L_end, R_begin, R_end, TL )      \
    STREAMS_BOOST_TEST_TOOL_IMPL( check_impl, ::streams_boost::test_tools::tt_detail::equal_coll_impl( \
        (L_begin), (L_end), (R_begin), (R_end) ), "", TL, CHECK_EQUAL_COLL ),   \
    4,                                                                          \
    STREAMS_BOOST_STRINGIZE( L_begin ), STREAMS_BOOST_STRINGIZE( L_end ),                       \
    STREAMS_BOOST_STRINGIZE( R_begin ), STREAMS_BOOST_STRINGIZE( R_end ) )                      \
/**/

#define STREAMS_BOOST_WARN_EQUAL_COLLECTIONS( L_begin, L_end, R_begin, R_end )          \
    STREAMS_BOOST_EQUAL_COLLECTIONS_IMPL( L_begin, L_end, R_begin, R_end, WARN )
#define STREAMS_BOOST_CHECK_EQUAL_COLLECTIONS( L_begin, L_end, R_begin, R_end )         \
    STREAMS_BOOST_EQUAL_COLLECTIONS_IMPL( L_begin, L_end, R_begin, R_end, CHECK )
#define STREAMS_BOOST_REQUIRE_EQUAL_COLLECTIONS( L_begin, L_end, R_begin, R_end )       \
    STREAMS_BOOST_EQUAL_COLLECTIONS_IMPL( L_begin, L_end, R_begin, R_end, REQUIRE )

//____________________________________________________________________________//

#define STREAMS_BOOST_BITWISE_EQUAL_IMPL( L, R, TL )                                    \
    STREAMS_BOOST_TEST_TOOL_IMPL( check_impl,                                           \
      ::streams_boost::test_tools::tt_detail::bitwise_equal_impl( (L), (R) ),           \
      "", TL, CHECK_BITWISE_EQUAL ),                                            \
    2, STREAMS_BOOST_STRINGIZE( L ), STREAMS_BOOST_STRINGIZE( R ) )                             \
/**/

#define STREAMS_BOOST_WARN_BITWISE_EQUAL( L, R )    STREAMS_BOOST_BITWISE_EQUAL_IMPL( L, R, WARN )
#define STREAMS_BOOST_CHECK_BITWISE_EQUAL( L, R )   STREAMS_BOOST_BITWISE_EQUAL_IMPL( L, R, CHECK )
#define STREAMS_BOOST_REQUIRE_BITWISE_EQUAL( L, R ) STREAMS_BOOST_BITWISE_EQUAL_IMPL( L, R, REQUIRE )

//____________________________________________________________________________//

#define STREAMS_BOOST_IS_DEFINED( symb )            ::streams_boost::test_tools::tt_detail::is_defined_impl( #symb, STREAMS_BOOST_STRINGIZE(= symb) )

//____________________________________________________________________________//

// ***************************** //
// deprecated interface

#define STREAMS_BOOST_BITWISE_EQUAL( L, R )         STREAMS_BOOST_CHECK_BITWISE_EQUAL( L, R )
#define STREAMS_BOOST_MESSAGE( M )                  STREAMS_BOOST_TEST_MESSAGE( M )
#define STREAMS_BOOST_CHECKPOINT( M )               STREAMS_BOOST_TEST_CHECKPOINT( M )

namespace streams_boost {

namespace test_tools {

typedef unit_test::const_string      const_string;

namespace { bool dummy_cond = false; }

// ************************************************************************** //
// **************                print_log_value               ************** //
// ************************************************************************** //

template<typename T>
struct print_log_value {
    void    operator()( std::ostream& ostr, T const& t )
    {
        // avoid warning: 'streams_boost::test_tools::<unnamed>::dummy_cond' defined but not used 
        if (::streams_boost::test_tools::dummy_cond) {}

        typedef typename mpl::or_<is_array<T>,is_function<T>,is_abstract<T> >::type cant_use_nl;

        set_precision( ostr, cant_use_nl() );

        ostr << t; // by default print the value
    }

    void set_precision( std::ostream& ostr, mpl::false_ )
    {
        if( std::numeric_limits<T>::is_specialized && std::numeric_limits<T>::radix == 2 )
            ostr.precision( 2 + std::numeric_limits<T>::digits * 301/1000 ); 
    }

    void set_precision( std::ostream&, mpl::true_ ) {}
};

//____________________________________________________________________________//

#define STREAMS_BOOST_TEST_DONT_PRINT_LOG_VALUE( the_type )         \
namespace streams_boost { namespace test_tools {                    \
template<>                                                  \
struct print_log_value<the_type > {                         \
    void operator()( std::ostream&, the_type const& ) {}    \
};                                                          \
}}                                                          \
/**/

//____________________________________________________________________________//

#if STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x564))
template<typename T, std::size_t N >
struct print_log_value< T[N] > {
    void    operator()( std::ostream& ostr, T const* t )
    {
        ostr << t;
    }
};
#endif

//____________________________________________________________________________//

template<>
struct STREAMS_BOOST_TEST_DECL print_log_value<bool> {
    void    operator()( std::ostream& ostr, bool t )
    {
         ostr << std::boolalpha << t;
    }
};

//____________________________________________________________________________//

template<>
struct STREAMS_BOOST_TEST_DECL print_log_value<char> {
    void    operator()( std::ostream& ostr, char t );
};

//____________________________________________________________________________//

template<>
struct STREAMS_BOOST_TEST_DECL print_log_value<unsigned char> {
    void    operator()( std::ostream& ostr, unsigned char t );
};

//____________________________________________________________________________//

template<>
struct STREAMS_BOOST_TEST_DECL print_log_value<char const*> {
    void    operator()( std::ostream& ostr, char const* t );
};

//____________________________________________________________________________//

template<>
struct STREAMS_BOOST_TEST_DECL print_log_value<wchar_t const*> {
    void    operator()( std::ostream& ostr, wchar_t const* t );
};

//____________________________________________________________________________//

namespace tt_detail {

// ************************************************************************** //
// **************              tools classification            ************** //
// ************************************************************************** //

enum check_type {
    CHECK_PRED, 
    CHECK_MSG,
    CHECK_EQUAL,
    CHECK_NE,
    CHECK_LT,
    CHECK_LE,
    CHECK_GT,
    CHECK_GE,
    CHECK_CLOSE,
    CHECK_CLOSE_FRACTION,
    CHECK_SMALL,
    CHECK_BITWISE_EQUAL,
    CHECK_PRED_WITH_ARGS,
    CHECK_EQUAL_COLL
};

enum tool_level {
    WARN, CHECK, REQUIRE, PASS
};

// ************************************************************************** //
// **************                 print_helper                 ************** //
// ************************************************************************** //
// Adds level of indirection to the output operation, allowing us to customize 
// it for types that do not support operator << directly or for any other reason

template<typename T>
struct print_helper_t {
    explicit    print_helper_t( T const& t ) : m_t( t ) {}

    T const&    m_t;
};

//____________________________________________________________________________//

#if STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x564)) 
// Borland suffers premature pointer decay passing arrays by reference
template<typename T, std::size_t N >
struct print_helper_t< T[N] > {
    explicit    print_helper_t( T const * t ) : m_t( t ) {}

    T const *   m_t;
};
#endif

//____________________________________________________________________________//

template<typename T>
inline print_helper_t<T> print_helper( T const& t )
{
    return print_helper_t<T>( t );
}

//____________________________________________________________________________//

template<typename T>
inline std::ostream& 
operator<<( std::ostream& ostr, print_helper_t<T> const& ph )
{
    print_log_value<T>()( ostr, ph.m_t );

    return ostr;
}

//____________________________________________________________________________//

// ************************************************************************** //
// **************            TOOL BOX Implementation           ************** //
// ************************************************************************** //

STREAMS_BOOST_TEST_DECL 
bool check_impl( predicate_result const& pr, ::streams_boost::unit_test::lazy_ostream const& check_descr,
                 const_string file_name, std::size_t line_num,
                 tool_level tl, check_type ct,
                 std::size_t num_args, ... );

//____________________________________________________________________________//

#define TEMPL_PARAMS( z, m, dummy ) , typename STREAMS_BOOST_JOIN( Arg, m )
#define FUNC_PARAMS( z, m, dummy )                                                  \
 , STREAMS_BOOST_JOIN( Arg, m ) const& STREAMS_BOOST_JOIN( arg, m )                                 \
 , char const* STREAMS_BOOST_JOIN( STREAMS_BOOST_JOIN( arg, m ), _descr )                           \
/**/

#define PRED_PARAMS( z, m, dummy ) STREAMS_BOOST_PP_COMMA_IF( m ) STREAMS_BOOST_JOIN( arg, m ) 

#define ARG_INFO( z, m, dummy )                                                     \
 , STREAMS_BOOST_JOIN( STREAMS_BOOST_JOIN( arg, m ), _descr )                                       \
 , &static_cast<const unit_test::lazy_ostream&>(unit_test::lazy_ostream::instance() \
        << ::streams_boost::test_tools::tt_detail::print_helper( STREAMS_BOOST_JOIN( arg, m ) ))    \
/**/

#define IMPL_FRWD( z, n, dummy )                                                    \
template<typename Pred                                                              \
         STREAMS_BOOST_PP_REPEAT_ ## z( STREAMS_BOOST_PP_ADD( n, 1 ), TEMPL_PARAMS, _ )>            \
inline bool                                                                         \
check_frwd( Pred P, unit_test::lazy_ostream const& check_descr,                     \
            const_string file_name, std::size_t line_num,                           \
            tool_level tl, check_type ct                                            \
            STREAMS_BOOST_PP_REPEAT_ ## z( STREAMS_BOOST_PP_ADD( n, 1 ), FUNC_PARAMS, _ )           \
)                                                                                   \
{                                                                                   \
    return                                                                          \
    check_impl( P( STREAMS_BOOST_PP_REPEAT_ ## z( STREAMS_BOOST_PP_ADD( n, 1 ), PRED_PARAMS, _ ) ), \
                check_descr, file_name, line_num, tl, ct,                           \
                STREAMS_BOOST_PP_ADD( n, 1 )                                                \
                STREAMS_BOOST_PP_REPEAT_ ## z( STREAMS_BOOST_PP_ADD( n, 1 ), ARG_INFO, _ )          \
    );                                                                              \
}                                                                                   \
/**/

#ifndef STREAMS_BOOST_TEST_MAX_PREDICATE_ARITY
#define STREAMS_BOOST_TEST_MAX_PREDICATE_ARITY 5
#endif

STREAMS_BOOST_PP_REPEAT( STREAMS_BOOST_TEST_MAX_PREDICATE_ARITY, IMPL_FRWD, _ )

#undef TEMPL_PARAMS
#undef FUNC_PARAMS
#undef PRED_INFO
#undef ARG_INFO
#undef IMPL_FRWD

//____________________________________________________________________________//

template <class Left, class Right>
predicate_result equal_impl( Left const& left, Right const& right )
{
    return left == right;
}

//____________________________________________________________________________//

predicate_result        STREAMS_BOOST_TEST_DECL equal_impl( char const* left, char const* right );
inline predicate_result equal_impl( char* left, char const* right ) { return equal_impl( static_cast<char const*>(left), static_cast<char const*>(right) ); }
inline predicate_result equal_impl( char const* left, char* right ) { return equal_impl( static_cast<char const*>(left), static_cast<char const*>(right) ); }
inline predicate_result equal_impl( char* left, char* right )       { return equal_impl( static_cast<char const*>(left), static_cast<char const*>(right) ); }

#if !defined( STREAMS_BOOST_NO_CWCHAR )
predicate_result        STREAMS_BOOST_TEST_DECL equal_impl( wchar_t const* left, wchar_t const* right );
inline predicate_result equal_impl( wchar_t* left, wchar_t const* right ) { return equal_impl( static_cast<wchar_t const*>(left), static_cast<wchar_t const*>(right) ); }
inline predicate_result equal_impl( wchar_t const* left, wchar_t* right ) { return equal_impl( static_cast<wchar_t const*>(left), static_cast<wchar_t const*>(right) ); }
inline predicate_result equal_impl( wchar_t* left, wchar_t* right )       { return equal_impl( static_cast<wchar_t const*>(left), static_cast<wchar_t const*>(right) ); }
#endif

//____________________________________________________________________________//

struct equal_impl_frwd {
    template <typename Left, typename Right>
    inline predicate_result
    call_impl( Left const& left, Right const& right, mpl::false_ ) const
    {
        return equal_impl( left, right );
    }

    template <typename Left, typename Right>
    inline predicate_result
    call_impl( Left const& left, Right const& right, mpl::true_ ) const
    {
        return (*this)( right, &left[0] );
    }

    template <typename Left, typename Right>
    inline predicate_result
    operator()( Left const& left, Right const& right ) const
    {
        typedef typename is_array<Left>::type left_is_array;
        return call_impl( left, right, left_is_array() );
    }
};

//____________________________________________________________________________//

struct ne_impl {
    template <class Left, class Right>
    predicate_result operator()( Left const& left, Right const& right )
    {
        return !equal_impl_frwd()( left, right );
    }
};

//____________________________________________________________________________//

struct lt_impl {
    template <class Left, class Right>
    predicate_result operator()( Left const& left, Right const& right )
    {
        return left < right;
    }
};

//____________________________________________________________________________//

struct le_impl {
    template <class Left, class Right>
    predicate_result operator()( Left const& left, Right const& right )
    {
        return left <= right;
    }
};

//____________________________________________________________________________//

struct gt_impl {
    template <class Left, class Right>
    predicate_result operator()( Left const& left, Right const& right )
    {
        return left > right;
    }
};

//____________________________________________________________________________//

struct ge_impl {
    template <class Left, class Right>
    predicate_result operator()( Left const& left, Right const& right )
    {
        return left >= right;
    }
};

//____________________________________________________________________________//

template <typename Left, typename Right>
inline predicate_result
equal_coll_impl( Left left_begin, Left left_end, Right right_begin, Right right_end )
{
    predicate_result    res( true );
    std::size_t         pos = 0;

    for( ; left_begin != left_end && right_begin != right_end; ++left_begin, ++right_begin, ++pos ) {
        if( *left_begin != *right_begin ) {
            res = false;
            res.message() << "\nMismatch in a position " << pos << ": "  << *left_begin << " != " << *right_begin;
        }
    }

    if( left_begin != left_end ) {
        std::size_t r_size = pos;
        while( left_begin != left_end ) {
            ++pos;
            ++left_begin;
        }

        res = false;
        res.message() << "\nCollections size mismatch: " << pos << " != " << r_size;
    }

    if( right_begin != right_end ) {
        std::size_t l_size = pos;
        while( right_begin != right_end ) {
            ++pos;
            ++right_begin;
        }

        res = false;
        res.message() << "\nCollections size mismatch: " << l_size << " != " << pos;
    }

    return res;
}

//____________________________________________________________________________//

template <class Left, class Right>
inline predicate_result
bitwise_equal_impl( Left const& left, Right const& right )
{
    predicate_result    res( true );

    std::size_t left_bit_size  = sizeof(Left)*CHAR_BIT;
    std::size_t right_bit_size = sizeof(Right)*CHAR_BIT;

    static Left const leftOne( 1 );
    static Right const rightOne( 1 );

    std::size_t total_bits = left_bit_size < right_bit_size ? left_bit_size : right_bit_size;

    for( std::size_t counter = 0; counter < total_bits; ++counter ) {
        if( ( left & ( leftOne << counter ) ) != ( right & ( rightOne << counter ) ) ) {
            res = false;
            res.message() << "\nMismatch in a position " << counter;
        }
    }

    if( left_bit_size != right_bit_size ) {
        res = false;
        res.message() << "\nOperands bit sizes mismatch: " << left_bit_size << " != " << right_bit_size;
    }

    return res;
}

//____________________________________________________________________________//

bool STREAMS_BOOST_TEST_DECL is_defined_impl( const_string symbol_name, const_string symbol_value );

//____________________________________________________________________________//

} // namespace tt_detail

} // namespace test_tools

namespace test_toolbox = test_tools;

} // namespace streams_boost

//____________________________________________________________________________//

#include <streams_boost/test/detail/enable_warnings.hpp>

#endif // STREAMS_BOOST_TEST_TEST_TOOLS_HPP_012705GER
