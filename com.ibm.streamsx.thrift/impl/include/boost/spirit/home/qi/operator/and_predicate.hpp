/*=============================================================================
    Copyright (c) 2001-2010 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
=============================================================================*/
#if !defined(SPIRIT_AND_PREDICATE_MARCH_23_2007_0617PM)
#define SPIRIT_AND_PREDICATE_MARCH_23_2007_0617PM

#if defined(_MSC_VER)
#pragma once
#endif

#include <streams_boost/spirit/home/qi/domain.hpp>
#include <streams_boost/spirit/home/qi/meta_compiler.hpp>
#include <streams_boost/spirit/home/qi/parser.hpp>
#include <streams_boost/spirit/home/support/attributes.hpp>
#include <streams_boost/spirit/home/support/info.hpp>
#include <streams_boost/fusion/include/at.hpp>

namespace streams_boost { namespace spirit
{
    ///////////////////////////////////////////////////////////////////////////
    // Enablers
    ///////////////////////////////////////////////////////////////////////////
    template <>
    struct use_operator<qi::domain, proto::tag::address_of> // enables &p
      : mpl::true_ {};
}}

namespace streams_boost { namespace spirit { namespace qi
{
    template <typename Subject>
    struct and_predicate : unary_parser<and_predicate<Subject> >
    {
        typedef Subject subject_type;

        template <typename Context, typename Iterator>
        struct attribute
        {
            typedef unused_type type;
        };

        and_predicate(Subject const& subject)
          : subject(subject) {}

        template <typename Iterator, typename Context
          , typename Skipper, typename Attribute>
        bool parse(Iterator& first, Iterator const& last
          , Context& context, Skipper const& skipper
          , Attribute& /*attr*/) const
        {
            Iterator i = first;
            return subject.parse(i, last, context, skipper, unused);
        }

        template <typename Context>
        info what(Context& context) const
        {
            return info("and-predicate", subject.what(context));
        }

        Subject subject;
    };

    ///////////////////////////////////////////////////////////////////////////
    // Parser generators: make_xxx function (objects)
    ///////////////////////////////////////////////////////////////////////////
    template <typename Elements, typename Modifiers>
    struct make_composite<proto::tag::address_of, Elements, Modifiers>
      : make_unary_composite<Elements, and_predicate>
    {};
}}}

namespace streams_boost { namespace spirit { namespace traits
{
    template <typename Subject>
    struct has_semantic_action<qi::and_predicate<Subject> >
      : unary_has_semantic_action<Subject> {};
}}}

#endif