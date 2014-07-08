/*=============================================================================
    Copyright (c) 2001-2010 Hartmut Kaiser
    Copyright (c) 2001-2010 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(STREAMS_BOOST_SPIRIT_EOL_APRIL_18_2008_0751PM)
#define STREAMS_BOOST_SPIRIT_EOL_APRIL_18_2008_0751PM

#if defined(_MSC_VER)
#pragma once
#endif

#include <streams_boost/mpl/bool.hpp>
#include <streams_boost/spirit/home/qi/domain.hpp>
#include <streams_boost/spirit/home/qi/parser.hpp>
#include <streams_boost/spirit/home/qi/meta_compiler.hpp>
#include <streams_boost/spirit/home/qi/skip_over.hpp>
#include <streams_boost/spirit/home/support/common_terminals.hpp>

namespace streams_boost { namespace spirit
{
    ///////////////////////////////////////////////////////////////////////////
    // Enablers
    ///////////////////////////////////////////////////////////////////////////
    template <>
    struct use_terminal<qi::domain, tag::eol>       // enables eol
      : mpl::true_ {};
}}

namespace streams_boost { namespace spirit { namespace qi
{
    using spirit::eol;

    struct eol_parser : primitive_parser<eol_parser>
    {
        template <typename Context, typename Iterator>
        struct attribute
        {
            typedef unused_type type;
        };

        template <typename Iterator, typename Context
          , typename Skipper, typename Attribute>
        bool parse(Iterator& first, Iterator const& last
          , Context& /*context*/, Skipper const& skipper
          , Attribute& /*attr*/) const
        {
            qi::skip_over(first, last, skipper);

            Iterator it = first;
            bool matched = false;
            if (it != last && *it == '\r')  // CR
            {
                matched = true;
                ++it;
            }
            if (it != last && *it == '\n')  // LF
            {
                matched = true;
                ++it;
            }

            if (!matched)
                return false;

            first = it;
            return true;
        }

        template <typename Context>
        info what(Context& /*context*/) const
        {
            return info("eol");
        }
    };

    ///////////////////////////////////////////////////////////////////////////
    // Parser generators: make_xxx function (objects)
    ///////////////////////////////////////////////////////////////////////////
    template <typename Modifiers>
    struct make_primitive<tag::eol, Modifiers>
    {
        typedef eol_parser result_type;
        result_type operator()(unused_type, unused_type) const
        {
            return result_type();
        }
    };
}}}

#endif


