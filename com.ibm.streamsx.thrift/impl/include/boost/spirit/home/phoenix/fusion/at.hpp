/*=============================================================================
    Copyright (c) 2005-2008 Hartmut Kaiser
    Copyright (c) 2005-2007 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_SEQUENCE_AT_HPP
#define PHOENIX_SEQUENCE_AT_HPP

#include <streams_boost/fusion/include/at.hpp>
#include <streams_boost/spirit/home/phoenix/core/actor.hpp>
#include <streams_boost/spirit/home/phoenix/core/compose.hpp>
#include <streams_boost/type_traits/remove_reference.hpp>

namespace streams_boost { namespace phoenix
{
    template <int N>
    struct at_eval
    {
        template <typename Env, typename Tuple>
        struct result
        {
            typedef typename Tuple::template result<Env>::type tuple;
            typedef typename
                fusion::result_of::at_c<
                    typename remove_reference<tuple>::type, N
                >::type
            type;
        };

        template <typename RT, typename Env, typename Tuple>
        static RT
        eval(Env const& env, Tuple const& t)
        {
            return fusion::at_c<N>(t.eval(env));
        }
    };

    template <int N, typename Tuple>
    inline actor<typename as_composite<at_eval<N>, Tuple>::type>
    at_c(Tuple const& tup)
    {
        return compose<at_eval<N> >(tup);
    }

}}

#endif
