/*=============================================================================
    Copyright (c) 2001-2006 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(FUSION_ERASE_10022005_1835)
#define FUSION_ERASE_10022005_1835

#include <streams_boost/mpl/erase.hpp>
#include <streams_boost/fusion/support/tag_of.hpp>
#include <streams_boost/fusion/algorithm/transformation/erase.hpp>
#include <streams_boost/fusion/sequence/convert.hpp>

namespace streams_boost { namespace mpl
{
    template <typename Tag>
    struct erase_impl;

    template <>
    struct erase_impl<fusion::fusion_sequence_tag>
    {
        template <typename Sequence, typename First, typename Last>
        struct apply
        {
            typedef typename
                fusion::result_of::erase<Sequence, First, Last>::type
            result;

            typedef typename
                fusion::result_of::convert<
                    typename fusion::detail::tag_of<Sequence>::type, result>::type
            type;
        };
    };
}}

#endif

