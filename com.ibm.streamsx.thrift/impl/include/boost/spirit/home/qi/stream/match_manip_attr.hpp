/*=============================================================================
    Copyright (c) 2001-2010 Hartmut Kaiser
    Copyright (c) 2001-2010 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(STREAMS_BOOST_PP_IS_ITERATING)

#if !defined(STREAMS_BOOST_SPIRIT_MATCH_MANIP_ATTR_MAY_05_2007_1202PM)
#define STREAMS_BOOST_SPIRIT_MATCH_MANIP_ATTR_MAY_05_2007_1202PM

#include <streams_boost/spirit/home/qi/stream/match_manip.hpp>

#include <streams_boost/fusion/include/vector.hpp>
#include <streams_boost/preprocessor/iterate.hpp>
#include <streams_boost/preprocessor/repetition/enum.hpp>
#include <streams_boost/preprocessor/repetition/enum_params.hpp>
#include <streams_boost/preprocessor/repetition/enum_binary_params.hpp>

#define STREAMS_BOOST_PP_FILENAME_1                                                   \
    <streams_boost/spirit/home/qi/stream/match_manip_attr.hpp>
#define STREAMS_BOOST_PP_ITERATION_LIMITS (2, SPIRIT_ARGUMENTS_LIMIT)
#include STREAMS_BOOST_PP_ITERATE()

#endif

///////////////////////////////////////////////////////////////////////////////
//
//  Preprocessor vertical repetition code
//
///////////////////////////////////////////////////////////////////////////////
#else // defined(STREAMS_BOOST_PP_IS_ITERATING)

#define N STREAMS_BOOST_PP_ITERATION()
#define STREAMS_BOOST_SPIRIT_QI_ATTRIBUTE_REFERENCE(z, n, A) STREAMS_BOOST_PP_CAT(A, n) &

///////////////////////////////////////////////////////////////////////////////
namespace streams_boost { namespace spirit { namespace qi
{
    ///////////////////////////////////////////////////////////////////////////
    template <typename Expr, STREAMS_BOOST_PP_ENUM_PARAMS(N, typename A)>
    inline detail::match_manip<Expr, mpl::false_, mpl::true_, unused_type
      , fusion::vector<
            STREAMS_BOOST_PP_ENUM(N, STREAMS_BOOST_SPIRIT_QI_ATTRIBUTE_REFERENCE, A)
        > > 
    match(
        Expr const& xpr
      , STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N, A, & attr))
    {
        using qi::detail::match_manip;

        // Report invalid expression error as early as possible.
        // If you got an error_invalid_expression error message here,
        // then the expression (expr) is not a valid spirit qi expression.
        STREAMS_BOOST_SPIRIT_ASSERT_MATCH(qi::domain, Expr);

        typedef fusion::vector<
            STREAMS_BOOST_PP_ENUM(N, STREAMS_BOOST_SPIRIT_QI_ATTRIBUTE_REFERENCE, A)
        > vector_type;

        vector_type attr (STREAMS_BOOST_PP_ENUM_PARAMS(N, attr));
        return match_manip<Expr, mpl::false_, mpl::true_, unused_type, vector_type>(
            xpr, unused, attr);
    }

    ///////////////////////////////////////////////////////////////////////////
    template <typename Expr, typename Skipper
      , STREAMS_BOOST_PP_ENUM_PARAMS(N, typename A)>
    inline detail::match_manip<Expr, mpl::false_, mpl::true_, Skipper
      , fusion::vector<
            STREAMS_BOOST_PP_ENUM(N, STREAMS_BOOST_SPIRIT_QI_ATTRIBUTE_REFERENCE, A)
        > > 
    phrase_match(
        Expr const& xpr
      , Skipper const& s
      , STREAMS_BOOST_SCOPED_ENUM(skip_flag) post_skip
      , STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N, A, & attr))
    {
        using qi::detail::match_manip;

        // Report invalid expression error as early as possible.
        // If you got an error_invalid_expression error message here,
        // then either the expression (expr) or skipper is not a valid
        // spirit qi expression.
        STREAMS_BOOST_SPIRIT_ASSERT_MATCH(qi::domain, Expr);
        STREAMS_BOOST_SPIRIT_ASSERT_MATCH(qi::domain, Skipper);

        typedef fusion::vector<
            STREAMS_BOOST_PP_ENUM(N, STREAMS_BOOST_SPIRIT_QI_ATTRIBUTE_REFERENCE, A)
        > vector_type;

        vector_type attr (STREAMS_BOOST_PP_ENUM_PARAMS(N, attr));
        return match_manip<Expr, mpl::false_, mpl::true_, Skipper, vector_type>(
            xpr, s, post_skip, attr);
    }

    template <typename Expr, typename Skipper
      , STREAMS_BOOST_PP_ENUM_PARAMS(N, typename A)>
    inline detail::match_manip<Expr, mpl::false_, mpl::true_, Skipper
      , fusion::vector<
            STREAMS_BOOST_PP_ENUM(N, STREAMS_BOOST_SPIRIT_QI_ATTRIBUTE_REFERENCE, A)
        > > 
    phrase_match(
        Expr const& xpr
      , Skipper const& s
      , STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N, A, & attr))
    {
        using qi::detail::match_manip;

        // Report invalid expression error as early as possible.
        // If you got an error_invalid_expression error message here,
        // then either the expression (expr) or skipper is not a valid
        // spirit qi expression.
        STREAMS_BOOST_SPIRIT_ASSERT_MATCH(qi::domain, Expr);
        STREAMS_BOOST_SPIRIT_ASSERT_MATCH(qi::domain, Skipper);

        typedef fusion::vector<
            STREAMS_BOOST_PP_ENUM(N, STREAMS_BOOST_SPIRIT_QI_ATTRIBUTE_REFERENCE, A)
        > vector_type;

        vector_type attr (STREAMS_BOOST_PP_ENUM_PARAMS(N, attr));
        return match_manip<Expr, mpl::false_, mpl::true_, Skipper, vector_type>(
            xpr, s, attr);
    }

}}}

#undef STREAMS_BOOST_SPIRIT_QI_ATTRIBUTE_REFERENCE
#undef N

#endif

