//  Copyright (c) 2001-2010 Hartmut Kaiser
//  Copyright (c) 2001-2010 Joel de Guzman
//  Copyright (c) 2009 Carl Barron
// 
//  Distributed under the Boost Software License, Version 1.0. (See accompanying 
//  file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#if !defined(STREAMS_BOOST_PP_IS_ITERATING)

#if !defined(STREAMS_BOOST_SPIRIT_LEXER_PARSE_ATTR_MAY_27_2009_0926AM)
#define STREAMS_BOOST_SPIRIT_LEXER_PARSE_ATTR_MAY_27_2009_0926AM

#include <streams_boost/spirit/home/lex/tokenize_and_parse.hpp>

#include <streams_boost/fusion/include/vector.hpp>
#include <streams_boost/preprocessor/cat.hpp>
#include <streams_boost/preprocessor/iterate.hpp>
#include <streams_boost/preprocessor/repetition/enum.hpp>
#include <streams_boost/preprocessor/repetition/enum_params.hpp>
#include <streams_boost/preprocessor/repetition/enum_binary_params.hpp>

#define STREAMS_BOOST_PP_FILENAME_1 <streams_boost/spirit/home/lex/tokenize_and_parse_attr.hpp>
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
#define STREAMS_BOOST_SPIRIT_QI_ATTRIBUTE_REFERENCE(z, n, A) STREAMS_BOOST_PP_CAT(A, n)&

namespace streams_boost { namespace spirit { namespace lex
{
    template <typename Iterator, typename Lexer, typename ParserExpr
      , STREAMS_BOOST_PP_ENUM_PARAMS(N, typename A)>
    inline bool
    tokenize_and_parse(Iterator& first, Iterator last, Lexer const& lex
      , ParserExpr const& expr, STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N, A, & attr))
    {
        // Report invalid expression error as early as possible.
        // If you got an error_invalid_expression error message here,
        // then the expression (expr) is not a valid spirit qi expression.
        STREAMS_BOOST_SPIRIT_ASSERT_MATCH(qi::domain, ParserExpr);

        typedef fusion::vector<
            STREAMS_BOOST_PP_ENUM(N, STREAMS_BOOST_SPIRIT_QI_ATTRIBUTE_REFERENCE, A)
        > vector_type;

        vector_type attr (STREAMS_BOOST_PP_ENUM_PARAMS(N, attr));
        typename Lexer::iterator_type iter = lex.begin(first, last);
        return compile<qi::domain>(expr).parse(
            iter, lex.end(), unused, unused, attr);
    }

    ///////////////////////////////////////////////////////////////////////////
    template <typename Iterator, typename Lexer, typename ParserExpr
      , typename Skipper, STREAMS_BOOST_PP_ENUM_PARAMS(N, typename A)>
    inline bool
    tokenize_and_phrase_parse(Iterator& first, Iterator last, Lexer const& lex
      , ParserExpr const& expr, Skipper const& skipper
      , STREAMS_BOOST_SCOPED_ENUM(skip_flag) post_skip
      , STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N, A, & attr))
    {
        // Report invalid expression error as early as possible.
        // If you got an error_invalid_expression error message here,
        // then either the expression (expr) or skipper is not a valid
        // spirit qi expression.
        STREAMS_BOOST_SPIRIT_ASSERT_MATCH(qi::domain, ParserExpr);
        STREAMS_BOOST_SPIRIT_ASSERT_MATCH(qi::domain, Skipper);

        typedef
            typename result_of::compile<qi::domain, Skipper>::type
        skipper_type;
        skipper_type const skipper_ = compile<qi::domain>(skipper);

        typedef fusion::vector<
            STREAMS_BOOST_PP_ENUM(N, STREAMS_BOOST_SPIRIT_QI_ATTRIBUTE_REFERENCE, A)
        > vector_type;

        vector_type attr (STREAMS_BOOST_PP_ENUM_PARAMS(N, attr));
        typename Lexer::iterator_type iter = lex.begin(first, last);
        if (!compile<qi::domain>(expr).parse(
                iter, lex.end(), unused, skipper_, attr))
            return false;

        if (post_skip == skip_flag::postskip)
            qi::skip_over(first, last, skipper_);
        return true;
    }

    template <typename Iterator, typename Lexer, typename ParserExpr
      , typename Skipper, STREAMS_BOOST_PP_ENUM_PARAMS(N, typename A)>
    inline bool
    tokenize_and_phrase_parse(Iterator& first, Iterator last, Lexer const& lex
      , ParserExpr const& expr, Skipper const& skipper
      , STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N, A, & attr))
    {
        return tokenize_and_phrase_parse(first, last, expr, skipper
          , skip_flag::postskip, STREAMS_BOOST_PP_ENUM_PARAMS(N, attr));
    }

}}}

#undef STREAMS_BOOST_SPIRIT_QI_ATTRIBUTE_REFERENCE
#undef N

#endif

