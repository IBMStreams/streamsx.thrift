/*=============================================================================
    Copyright (c) 2003 Hartmut Kaiser
    http://spirit.sourceforge.net/

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
=============================================================================*/
#ifndef STREAMS_BOOST_SPIRIT_SELECT_HPP
#define STREAMS_BOOST_SPIRIT_SELECT_HPP

#include <streams_boost/preprocessor/repeat.hpp>
#include <streams_boost/preprocessor/enum.hpp>
#include <streams_boost/preprocessor/enum_params.hpp>
#include <streams_boost/preprocessor/enum_params_with_defaults.hpp>
#include <streams_boost/preprocessor/inc.hpp>
#include <streams_boost/preprocessor/cat.hpp>
#include <streams_boost/preprocessor/facilities/intercept.hpp>

#include <streams_boost/spirit/home/classic/namespace.hpp>
#include <streams_boost/spirit/home/classic/core/parser.hpp>

#include <streams_boost/spirit/home/classic/phoenix/tuples.hpp>

///////////////////////////////////////////////////////////////////////////////
//
//  Spirit predefined maximum number of possible embedded select_p parsers.
//  It should NOT be greater than PHOENIX_LIMIT!
//
///////////////////////////////////////////////////////////////////////////////
#if !defined(STREAMS_BOOST_SPIRIT_SELECT_LIMIT)
#define STREAMS_BOOST_SPIRIT_SELECT_LIMIT PHOENIX_LIMIT
#endif // !defined(STREAMS_BOOST_SPIRIT_SELECT_LIMIT)

///////////////////////////////////////////////////////////////////////////////
//
// ensure   STREAMS_BOOST_SPIRIT_SELECT_LIMIT <= PHOENIX_LIMIT and 
//          STREAMS_BOOST_SPIRIT_SELECT_LIMIT > 0
//          STREAMS_BOOST_SPIRIT_SELECT_LIMIT <= 15
//
//  [Pushed this down a little to make CW happy with STREAMS_BOOST_STATIC_ASSERT]
//  [Otherwise, it complains: 'streams_boost_static_assert_test_42' redefined]
//
///////////////////////////////////////////////////////////////////////////////
STREAMS_BOOST_STATIC_ASSERT(STREAMS_BOOST_SPIRIT_SELECT_LIMIT <= PHOENIX_LIMIT);
STREAMS_BOOST_STATIC_ASSERT(STREAMS_BOOST_SPIRIT_SELECT_LIMIT > 0);
STREAMS_BOOST_STATIC_ASSERT(STREAMS_BOOST_SPIRIT_SELECT_LIMIT <= 15);

///////////////////////////////////////////////////////////////////////////////
//
//  Calculate the required amount of tuple members rounded up to the nearest 
//  integer dividable by 3
//
///////////////////////////////////////////////////////////////////////////////
#if STREAMS_BOOST_SPIRIT_SELECT_LIMIT > 12
#define STREAMS_BOOST_SPIRIT_SELECT_LIMIT_A     15
#elif STREAMS_BOOST_SPIRIT_SELECT_LIMIT > 9
#define STREAMS_BOOST_SPIRIT_SELECT_LIMIT_A     12
#elif STREAMS_BOOST_SPIRIT_SELECT_LIMIT > 6
#define STREAMS_BOOST_SPIRIT_SELECT_LIMIT_A     9
#elif STREAMS_BOOST_SPIRIT_SELECT_LIMIT > 3
#define STREAMS_BOOST_SPIRIT_SELECT_LIMIT_A     6
#else
#define STREAMS_BOOST_SPIRIT_SELECT_LIMIT_A     3
#endif

///////////////////////////////////////////////////////////////////////////////
namespace streams_boost { namespace spirit {

STREAMS_BOOST_SPIRIT_CLASSIC_NAMESPACE_BEGIN

///////////////////////////////////////////////////////////////////////////////
//
//  The select_default_no_fail and select_default_fail structs are used to 
//  distinguish two different behaviours for the select_parser in case that not
//  any of the given sub-parsers match.
//
//  If the select_parser is used with the select_default_no_fail behaviour,
//  then in case of no matching sub-parser the whole select_parser returns an
//  empty match and the value -1.
//
//  If the select_parser is used with the select_default_fail behaviour, then
//  in case of no matching sub-parser the whole select_parser fails to match at 
//  all.
//
///////////////////////////////////////////////////////////////////////////////
struct select_default_no_fail {};
struct select_default_fail {};

STREAMS_BOOST_SPIRIT_CLASSIC_NAMESPACE_END

}}  // namespace STREAMS_BOOST_SPIRIT_CLASSIC_NS

///////////////////////////////////////////////////////////////////////////////
#include <streams_boost/spirit/home/classic/dynamic/impl/select.ipp>

///////////////////////////////////////////////////////////////////////////////
namespace streams_boost { namespace spirit {

STREAMS_BOOST_SPIRIT_CLASSIC_NAMESPACE_BEGIN

///////////////////////////////////////////////////////////////////////////////
template <typename TupleT, typename BehaviourT, typename T>
struct select_parser
:   public parser<select_parser<TupleT, BehaviourT, T> >
{
    typedef select_parser<TupleT, BehaviourT, T> self_t;

    select_parser(TupleT const &t_)
    :   t(t_)
    {}
    
    template <typename ScannerT>
    struct result
    {
        typedef typename match_result<ScannerT, T>::type type;
    };

    template <typename ScannerT>
    typename parser_result<self_t, ScannerT>::type
    parse(ScannerT const& scan) const
    {
        typedef typename parser_result<self_t, ScannerT>::type result_t;
        
        if (!scan.at_end()) {
            return impl::parse_tuple_element<
                TupleT::length, result_t, TupleT, BehaviourT>::do_(t, scan);
        }
        return impl::select_match_gen<result_t, BehaviourT>::do_(scan);
    }
        
    TupleT const t;
};

///////////////////////////////////////////////////////////////////////////////
template <typename BehaviourT, typename T = int>
struct select_parser_gen {

    ///////////////////////////////////////////////////////////////////////////
    //
    //  This generates different select_parser_gen::operator()() functions with 
    //  an increasing number of parser parameters:
    //
    //      template <typename ParserT0, ...>
    //      select_parser<
    //          phoenix::tuple<
    //              typename impl::as_embedded_parser<ParserT0>::type,
    //              ...
    //          >,
    //          BehaviourT,
    //          T
    //      >
    //      operator()(ParserT0 const &p0, ...) const
    //      {
    //          typedef impl::as_embedded_parser<ParserT0> parser_t0;
    //          ...
    //
    //          typedef phoenix::tuple< 
    //                  parser_t0::type,
    //                  ...
    //              > tuple_t; 
    //          typedef select_parser<tuple_t, BehaviourT, T> result_t;
    //
    //          return result_t(tuple_t(
    //                  parser_t0::convert(p0),
    //                  ...
    //              ));
    //      }
    //
    //  The number of generated functions depends on the maximum tuple member 
    //  limit defined by the PHOENIX_LIMIT pp constant. 
    //
    ///////////////////////////////////////////////////////////////////////////
    #define STREAMS_BOOST_SPIRIT_SELECT_EMBEDDED(z, N, _)                           \
        typename impl::as_embedded_parser<STREAMS_BOOST_PP_CAT(ParserT, N)>::type   \
        /**/
    #define STREAMS_BOOST_SPIRIT_SELECT_EMBEDDED_TYPEDEF(z, N, _)                   \
        typedef impl::as_embedded_parser<STREAMS_BOOST_PP_CAT(ParserT, N)>          \
            STREAMS_BOOST_PP_CAT(parser_t, N);                                      \
        /**/
    #define STREAMS_BOOST_SPIRIT_SELECT_CONVERT(z, N, _)                            \
        STREAMS_BOOST_PP_CAT(parser_t, N)::convert(STREAMS_BOOST_PP_CAT(p, N))              \
        /**/
        
    #define STREAMS_BOOST_SPIRIT_SELECT_PARSER(z, N, _)                             \
        template <                                                          \
            STREAMS_BOOST_PP_ENUM_PARAMS_Z(z, STREAMS_BOOST_PP_INC(N), typename ParserT)    \
        >                                                                   \
        select_parser<                                                      \
            phoenix::tuple<                                                 \
                STREAMS_BOOST_PP_ENUM_ ## z(STREAMS_BOOST_PP_INC(N),                        \
                    STREAMS_BOOST_SPIRIT_SELECT_EMBEDDED, _)                        \
            >,                                                              \
            BehaviourT,                                                     \
            T                                                               \
        >                                                                   \
        operator()(                                                         \
            STREAMS_BOOST_PP_ENUM_BINARY_PARAMS_Z(z, STREAMS_BOOST_PP_INC(N),               \
                ParserT, const &p)                                          \
        ) const                                                             \
        {                                                                   \
            STREAMS_BOOST_PP_REPEAT_ ## z(STREAMS_BOOST_PP_INC(N),                          \
                STREAMS_BOOST_SPIRIT_SELECT_EMBEDDED_TYPEDEF, _)                    \
                                                                            \
            typedef phoenix::tuple<                                         \
                    STREAMS_BOOST_PP_ENUM_BINARY_PARAMS_Z(z, STREAMS_BOOST_PP_INC(N),       \
                        typename parser_t, ::type STREAMS_BOOST_PP_INTERCEPT)       \
                > tuple_t;                                                  \
            typedef select_parser<tuple_t, BehaviourT, T> result_t;         \
                                                                            \
            return result_t(tuple_t(                                        \
                    STREAMS_BOOST_PP_ENUM_ ## z(STREAMS_BOOST_PP_INC(N),                    \
                        STREAMS_BOOST_SPIRIT_SELECT_CONVERT, _)                     \
                ));                                                         \
        }                                                                   \
        /**/
        
    STREAMS_BOOST_PP_REPEAT(STREAMS_BOOST_SPIRIT_SELECT_LIMIT_A, 
        STREAMS_BOOST_SPIRIT_SELECT_PARSER, _)
        
    #undef STREAMS_BOOST_SPIRIT_SELECT_PARSER
    #undef STREAMS_BOOST_SPIRIT_SELECT_CONVERT
    #undef STREAMS_BOOST_SPIRIT_SELECT_EMBEDDED_TYPEDEF
    #undef STREAMS_BOOST_SPIRIT_SELECT_EMBEDDED
    ///////////////////////////////////////////////////////////////////////////
};

///////////////////////////////////////////////////////////////////////////////
//
//  Predefined parser generator helper objects
//
///////////////////////////////////////////////////////////////////////////////
select_parser_gen<select_default_no_fail> const select_p = 
    select_parser_gen<select_default_no_fail>();

select_parser_gen<select_default_fail> const select_fail_p = 
    select_parser_gen<select_default_fail>();

#undef STREAMS_BOOST_SPIRIT_SELECT_LIMIT_A

///////////////////////////////////////////////////////////////////////////////
STREAMS_BOOST_SPIRIT_CLASSIC_NAMESPACE_END

}}  // namespace STREAMS_BOOST_SPIRIT_CLASSIC_NS

#endif // STREAMS_BOOST_SPIRIT_SELECT_HPP
