/*=============================================================================
    Copyright (c) 2001-2010 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
=============================================================================*/
#if !defined(SPIRIT_RAW_APRIL_9_2007_0912AM)
#define SPIRIT_RAW_APRIL_9_2007_0912AM

#if defined(_MSC_VER)
#pragma once
#endif

#include <streams_boost/spirit/home/qi/meta_compiler.hpp>
#include <streams_boost/spirit/home/qi/skip_over.hpp>
#include <streams_boost/spirit/home/qi/parser.hpp>
#include <streams_boost/spirit/home/qi/detail/assign_to.hpp>
#include <streams_boost/spirit/home/support/unused.hpp>
#include <streams_boost/spirit/home/support/info.hpp>
#include <streams_boost/spirit/home/support/common_terminals.hpp>
#include <streams_boost/spirit/home/support/unused.hpp>
#include <streams_boost/spirit/home/support/has_semantic_action.hpp>
#include <streams_boost/range/iterator_range.hpp>

namespace streams_boost { namespace spirit
{
    ///////////////////////////////////////////////////////////////////////////
    // Enablers
    ///////////////////////////////////////////////////////////////////////////
    template <>
    struct use_directive<qi::domain, tag::raw> // enables raw
      : mpl::true_ {};
}}

namespace streams_boost { namespace spirit { namespace qi
{
    using spirit::raw;
    using spirit::raw_type;

    template <typename Subject>
    struct raw_directive : unary_parser<raw_directive<Subject> >
    {
        typedef Subject subject_type;
        raw_directive(Subject const& subject)
          : subject(subject) {}

        template <typename Context, typename Iterator>
        struct attribute
        {
            typedef iterator_range<Iterator> type;
        };

        template <typename Iterator, typename Context
          , typename Skipper, typename Attribute>
        bool parse(Iterator& first, Iterator const& last
          , Context& context, Skipper const& skipper, Attribute& attr) const
        {
            qi::skip_over(first, last, skipper);
            Iterator i = first;
            if (subject.parse(i, last, context, skipper, unused))
            {
                spirit::traits::assign_to(first, i, attr);
                first = i;
                return true;
            }
            return false;
        }

        template <typename Context>
        info what(Context& context) const
        {
            return info("raw", subject.what(context));

        }

        Subject subject;
    };

    ///////////////////////////////////////////////////////////////////////////
    // Parser generators: make_xxx function (objects)
    ///////////////////////////////////////////////////////////////////////////
    template <typename Subject, typename Modifiers>
    struct make_directive<tag::raw, Subject, Modifiers>
    {
        typedef raw_directive<Subject> result_type;
        result_type operator()(unused_type, Subject const& subject, unused_type) const
        {
            return result_type(subject);
        }
    };
}}}

namespace streams_boost { namespace spirit { namespace traits
{
    template <typename Subject>
    struct has_semantic_action<qi::raw_directive<Subject> >
      : unary_has_semantic_action<Subject> {};
}}}

#endif