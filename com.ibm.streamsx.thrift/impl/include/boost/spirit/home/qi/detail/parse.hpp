/*=============================================================================
    Copyright (c) 2001-2010 Hartmut Kaiser

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
=============================================================================*/
#if !defined(STREAMS_BOOST_SPIRIT_DETAIL_PARSE_DEC_02_2009_0411PM)
#define STREAMS_BOOST_SPIRIT_DETAIL_PARSE_DEC_02_2009_0411PM

#if defined(_MSC_VER)
#pragma once
#endif

#include <streams_boost/spirit/home/qi/meta_compiler.hpp>
#include <streams_boost/spirit/home/qi/skip_flag.hpp>
#include <streams_boost/spirit/home/qi/skip_over.hpp>
#include <streams_boost/spirit/home/support/unused.hpp>
#include <streams_boost/mpl/assert.hpp>
#include <streams_boost/mpl/bool.hpp>

namespace streams_boost { namespace spirit { namespace qi { namespace detail
{
    ///////////////////////////////////////////////////////////////////////////
    template <typename Expr, typename Enable = void>
    struct parse_impl
    {
        // Report invalid expression error as early as possible.
        // If you got an error_invalid_expression error message here,
        // then the expression (expr) is not a valid spirit qi expression.
        // Did you intend to use the auto_ facilities while forgetting to 
        // #include <streams_boost/spirit/include/qi_auto.hpp>?
        STREAMS_BOOST_SPIRIT_ASSERT_MATCH(qi::domain, Expr);
    };

    template <typename Expr>
    struct parse_impl<Expr
      , typename enable_if<traits::matches<qi::domain, Expr> >::type>
    {
        template <typename Iterator>
        static bool call(
            Iterator& first
          , Iterator last
          , Expr const& expr)
        {
            return compile<qi::domain>(expr).parse(
                first, last, unused, unused, unused);
        }
    };

    ///////////////////////////////////////////////////////////////////////////
    template <typename Expr, typename Enable = void>
    struct phrase_parse_impl
    {
        // Report invalid expression error as early as possible.
        // If you got an error_invalid_expression error message here,
        // then the expression (expr) is not a valid spirit qi expression.
        // Did you intend to use the auto_ facilities while forgetting to 
        // #include <streams_boost/spirit/include/qi_auto.hpp>?
        STREAMS_BOOST_SPIRIT_ASSERT_MATCH(qi::domain, Expr);
    };

    template <typename Expr>
    struct phrase_parse_impl<Expr
      , typename enable_if<traits::matches<qi::domain, Expr> >::type>
    {
        template <typename Iterator, typename Skipper>
        static bool call(
            Iterator& first
          , Iterator last
          , Expr const& expr
          , Skipper const& skipper
          , STREAMS_BOOST_SCOPED_ENUM(skip_flag) post_skip)
        {
            // Report invalid expression error as early as possible.
            // If you got an error_invalid_expression error message here,
            // then the skipper is not a valid spirit qi expression.
            STREAMS_BOOST_SPIRIT_ASSERT_MATCH(qi::domain, Skipper);

            typedef
                typename result_of::compile<qi::domain, Skipper>::type
            skipper_type;
            skipper_type const skipper_ = compile<qi::domain>(skipper);

            if (!compile<qi::domain>(expr).parse(
                    first, last, unused, skipper_, unused))
                return false;

            if (post_skip == skip_flag::postskip)
                qi::skip_over(first, last, skipper_);
            return true;
        }
    };

}}}}

#endif

