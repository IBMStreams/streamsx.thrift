/*=============================================================================
    Copyright (c) 2001-2010 Hartmut Kaiser

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
=============================================================================*/
#if !defined(STREAMS_BOOST_SPIRIT_DETAIL_PARSE_AUTO_DEC_02_2009_0426PM)
#define STREAMS_BOOST_SPIRIT_DETAIL_PARSE_AUTO_DEC_02_2009_0426PM

#if defined(_MSC_VER)
#pragma once
#endif

#include <streams_boost/spirit/home/qi/parse.hpp>
#include <streams_boost/spirit/home/qi/auto/create_parser.hpp>
#include <streams_boost/utility/enable_if.hpp>
#include <streams_boost/mpl/not.hpp>
#include <streams_boost/mpl/and.hpp>

namespace streams_boost { namespace spirit { namespace qi { namespace detail
{
    ///////////////////////////////////////////////////////////////////////////
    template <typename Expr>
    struct parse_impl<Expr
      , typename enable_if<traits::meta_create_exists<qi::domain, Expr> >::type>
    {
        template <typename Iterator>
        static bool call(
            Iterator& first
          , Iterator last
          , Expr const& expr)
        {
            return qi::parse(first, last, create_parser<Expr>()
              , const_cast<Expr&>(expr));
        }
    };

    ///////////////////////////////////////////////////////////////////////////
    template <typename Expr>
    struct phrase_parse_impl<Expr
      , typename enable_if<traits::meta_create_exists<qi::domain, Expr> >::type>
    {
        template <typename Iterator, typename Skipper>
        static bool call(
            Iterator& first
          , Iterator last
          , Expr const& expr
          , Skipper const& skipper
          , STREAMS_BOOST_SCOPED_ENUM(skip_flag) post_skip)
        {
            return qi::phrase_parse(first, last, create_parser<Expr>()
              , skipper, post_skip, const_cast<Expr&>(expr));
        }
    };

}}}}

#endif

