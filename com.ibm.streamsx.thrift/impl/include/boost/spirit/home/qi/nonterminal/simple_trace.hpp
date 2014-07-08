/*=============================================================================
    Copyright (c) 2001-2010 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(STREAMS_BOOST_SPIRIT_SIMPLE_TRACE_DECEMBER_06_2008_1102AM)
#define STREAMS_BOOST_SPIRIT_SIMPLE_TRACE_DECEMBER_06_2008_1102AM

#if defined(_MSC_VER)
#pragma once
#endif

#include <streams_boost/spirit/home/support/unused.hpp>
#include <streams_boost/fusion/include/out.hpp>
#include <iostream>

//  The stream to use for debug output
#if !defined(STREAMS_BOOST_SPIRIT_DEBUG_OUT)
#define STREAMS_BOOST_SPIRIT_DEBUG_OUT std::cerr
#endif

//  number of input tokens to print while debugging
#if !defined(STREAMS_BOOST_SPIRIT_DEBUG_PRINT_SOME)
#define STREAMS_BOOST_SPIRIT_DEBUG_PRINT_SOME 20
#endif

//  number of spaces to indent
#if !defined(STREAMS_BOOST_SPIRIT_DEBUG_INDENT)
#define STREAMS_BOOST_SPIRIT_DEBUG_INDENT 2
#endif

namespace streams_boost { namespace spirit { namespace qi
{
    namespace detail
    {
        struct token_printer_aux_for_chars
        {
            template<typename Char>
            static void print(std::ostream& o, Char c)
            {
                using namespace std;    // allow for ADL to find the proper iscntrl

                if (c == static_cast<Char>('\a'))
                    o << "\\a";
                else if (c == static_cast<Char>('\b'))
                    o << "\\b";
                else if (c == static_cast<Char>('\f'))
                    o << "\\f";
                else if (c == static_cast<Char>('\n'))
                    o << "\\n";
                else if (c == static_cast<Char>('\r'))
                    o << "\\r";
                else if (c == static_cast<Char>('\t'))
                    o << "\\t";
                else if (c == static_cast<Char>('\v'))
                    o << "\\v";
                else if (iscntrl(c))
                    o << "\\" << std::oct << static_cast<int>(c);
                else
                    o << static_cast<char>(c);
            }
        };

        // for token types where the comparison with char constants wouldn't work
        struct token_printer_aux_for_other_types
        {
            template<typename Char>
            static void print(std::ostream& o, Char c)
            {
                o << c;
            }
        };

        template <typename Char>
        struct token_printer_aux
          : mpl::if_<
                mpl::and_<
                    is_convertible<Char, char>, is_convertible<char, Char> >
              , token_printer_aux_for_chars
              , token_printer_aux_for_other_types>::type
        {};

        template<typename Char>
        inline void token_printer(std::ostream& o, Char c)
        {
            // allow to customize the token printer routine
#if !defined(STREAMS_BOOST_SPIRIT_DEBUG_TOKEN_PRINTER)
            token_printer_aux<Char>::print(o, c);
#else
            STREAMS_BOOST_SPIRIT_DEBUG_TOKEN_PRINTER(o, c);
#endif
        }
    }

    struct simple_trace
    {
        void print_indent(int n) const
        {
            n *= STREAMS_BOOST_SPIRIT_DEBUG_INDENT;
            for (int i = 0; i != n; ++i)
                STREAMS_BOOST_SPIRIT_DEBUG_OUT << ' ';
        }

        template <typename Iterator>
        void print_some(
            char const* tag
          , int indent
          , Iterator first, Iterator const& last) const
        {
            print_indent(indent);
            STREAMS_BOOST_SPIRIT_DEBUG_OUT << '<' << tag << '>';
            int const n = STREAMS_BOOST_SPIRIT_DEBUG_PRINT_SOME;
            for (int i = 0; first != last && i != n && *first; ++i, ++first)
                detail::token_printer(STREAMS_BOOST_SPIRIT_DEBUG_OUT, *first);
            STREAMS_BOOST_SPIRIT_DEBUG_OUT << "</" << tag << '>' << std::endl;
        }

        template <typename Iterator, typename Context, typename State>
        void operator()(
            Iterator const& first
          , Iterator const& last
          , Context const& context
          , State state
          , std::string const& rule_name) const
        {
            int static indent = 0;

            switch (state)
            {
                case pre_parse:
                    print_indent(indent++);
                    STREAMS_BOOST_SPIRIT_DEBUG_OUT
                        << '<' << rule_name << '>'
                        << std::endl;
                    print_some("try", indent, first, last);
                    break;
                case successful_parse:
                    print_some("success", indent, first, last);
                    print_indent(indent);
                    STREAMS_BOOST_SPIRIT_DEBUG_OUT
                        << "<attributes>"
                        << context.attributes
                        << "</attributes>";
                    if (!fusion::empty(context.locals))
                        STREAMS_BOOST_SPIRIT_DEBUG_OUT
                            << "<locals>"
                            << context.locals
                            << "</locals>";
                    STREAMS_BOOST_SPIRIT_DEBUG_OUT << std::endl;
                    print_indent(--indent);
                    STREAMS_BOOST_SPIRIT_DEBUG_OUT
                        << "</" << rule_name << '>'
                        << std::endl;
                    break;
                case failed_parse:
                    print_indent(indent);
                    STREAMS_BOOST_SPIRIT_DEBUG_OUT << "<fail/>" << std::endl;
                    print_indent(--indent);
                    STREAMS_BOOST_SPIRIT_DEBUG_OUT
                        << "</" << rule_name << '>'
                        << std::endl;
                    break;
            }
        }
    };
}}}

#endif
