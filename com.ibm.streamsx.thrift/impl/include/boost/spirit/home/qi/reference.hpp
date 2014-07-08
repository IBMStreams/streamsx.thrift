/*=============================================================================
    Copyright (c) 2001-2010 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(STREAMS_BOOST_SPIRIT_REFERENCE_OCTOBER_31_2008_1218AM)
#define STREAMS_BOOST_SPIRIT_REFERENCE_OCTOBER_31_2008_1218AM

#if defined(_MSC_VER)
#pragma once
#endif

#include <streams_boost/spirit/home/qi/meta_compiler.hpp>
#include <streams_boost/spirit/home/qi/parser.hpp>
#include <streams_boost/spirit/home/support/info.hpp>
#include <streams_boost/ref.hpp>

namespace streams_boost { namespace spirit { namespace qi
{
    ///////////////////////////////////////////////////////////////////////////
    // reference is a parser that references another parser (its Subject)
    ///////////////////////////////////////////////////////////////////////////
    template <typename Subject>
    struct reference : parser<reference<Subject> >
    {
        typedef Subject subject_type;

        reference(Subject& subject)
          : ref(subject) {}

        template <typename Context, typename Iterator>
        struct attribute : Subject::template attribute<Context, Iterator> {};

        template <typename Iterator, typename Context
          , typename Skipper, typename Attribute>
        bool parse(Iterator& first, Iterator const& last
          , Context& context, Skipper const& skipper
          , Attribute& attr) const
        {
            return ref.get().parse(first, last, context, skipper, attr);
        }

        template <typename Context>
        info what(Context& context) const
        {
            // the reference is transparent (does not add any info)
            return ref.get().what(context);
        }

        streams_boost::reference_wrapper<Subject> ref;
    };
}}}

#endif
