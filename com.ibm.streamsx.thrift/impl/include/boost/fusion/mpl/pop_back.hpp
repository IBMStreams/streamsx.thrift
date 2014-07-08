/*=============================================================================
    Copyright (c) 2001-2006 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(FUSION_POP_BACK_10022005_1801)
#define FUSION_POP_BACK_10022005_1801

#include <streams_boost/mpl/pop_back.hpp>
#include <streams_boost/fusion/support/tag_of.hpp>
#include <streams_boost/fusion/algorithm/transformation/pop_back.hpp>
#include <streams_boost/fusion/sequence/convert.hpp>

namespace streams_boost { namespace mpl
{
    template <typename Tag>
    struct pop_back_impl;

    template <>
    struct pop_back_impl<fusion::fusion_sequence_tag>
    {
        template <typename Sequence>
        struct apply
        {
            typedef typename
                fusion::result_of::pop_back<Sequence>::type
            result;

            typedef typename
                fusion::result_of::convert<
                    typename fusion::detail::tag_of<Sequence>::type, result>::type
            type;
        };
    };
}}

#endif

