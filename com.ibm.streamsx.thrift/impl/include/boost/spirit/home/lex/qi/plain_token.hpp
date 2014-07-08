//  Copyright (c) 2001-2010 Hartmut Kaiser
// 
//  Distributed under the Boost Software License, Version 1.0. (See accompanying 
//  file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#if !defined(STREAMS_BOOST_SPIRIT_LEX_PLAIN_TOKEN_NOV_11_2007_0451PM)
#define STREAMS_BOOST_SPIRIT_LEX_PLAIN_TOKEN_NOV_11_2007_0451PM

#if defined(_MSC_VER)
#pragma once
#endif

#include <streams_boost/spirit/home/support/info.hpp>
#include <streams_boost/spirit/home/support/attributes.hpp>
#include <streams_boost/spirit/home/support/common_terminals.hpp>
#include <streams_boost/spirit/home/qi/skip_over.hpp>
#include <streams_boost/spirit/home/qi/domain.hpp>
#include <streams_boost/spirit/home/qi/parser.hpp>
#include <streams_boost/spirit/home/qi/meta_compiler.hpp>
#include <streams_boost/spirit/home/qi/detail/assign_to.hpp>
#include <streams_boost/range/iterator_range.hpp>
#include <streams_boost/fusion/include/vector.hpp>
#include <streams_boost/fusion/include/at.hpp>
#include <streams_boost/mpl/or.hpp>
#include <streams_boost/type_traits/is_integral.hpp>
#include <streams_boost/type_traits/is_enum.hpp>

namespace streams_boost { namespace spirit
{
    ///////////////////////////////////////////////////////////////////////////
    // Enablers
    ///////////////////////////////////////////////////////////////////////////

    // enables token(id)
    template <typename A0>
    struct use_terminal<qi::domain
      , terminal_ex<tag::token, fusion::vector1<A0> >
    > : mpl::or_<is_integral<A0>, is_enum<A0> > {};

    // enables *lazy* token(id)
    template <>
    struct use_lazy_terminal<
        qi::domain, tag::token, 1
    > : mpl::true_ {};

}}

namespace streams_boost { namespace spirit { namespace qi
{
    using spirit::token;

    ///////////////////////////////////////////////////////////////////////////
    template <typename TokenId>
    struct plain_token 
      : primitive_parser<plain_token<TokenId> >
    {
        template <typename Context, typename Iterator>
        struct attribute
        {
            typedef typename Iterator::base_iterator_type iterator_type;
            typedef iterator_range<iterator_type> type;
        };

        plain_token(TokenId const& id)
          : id(id) {}

        template <typename Iterator, typename Context
          , typename Skipper, typename Attribute>
        bool parse(Iterator& first, Iterator const& last
          , Context& /*context*/, Skipper const& skipper
          , Attribute& attr) const
        {
            qi::skip_over(first, last, skipper);   // always do a pre-skip

            if (first != last) {
                // simply match the token id with the id this component has 
                // been initialized with

                typedef typename 
                    streams_boost::detail::iterator_traits<Iterator>::value_type 
                token_type;
                typedef typename token_type::id_type id_type;

                token_type const& t = *first;
                if (id_type(id) == t.id()) {
                    spirit::traits::assign_to(t, attr);
                    ++first;
                    return true;
                }
            }
            return false;
        }

        template <typename Context>
        info what(Context& /*context*/) const
        {
            return info("token");
        }

        TokenId id;
    };

    ///////////////////////////////////////////////////////////////////////////
    // Parser generators: make_xxx function (objects)
    ///////////////////////////////////////////////////////////////////////////
    template <typename Modifiers, typename TokenId>
    struct make_primitive<terminal_ex<tag::token, fusion::vector1<TokenId> >
      , Modifiers>
    {
        typedef plain_token<TokenId> result_type;

        template <typename Terminal>
        result_type operator()(Terminal const& term, unused_type) const
        {
            return result_type(fusion::at_c<0>(term.args));
        }
    };

}}}

#endif
