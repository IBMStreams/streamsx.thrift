/*=============================================================================
    Copyright (c) 2001-2006 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(FUSION_EMPTY_10022005_1619)
#define FUSION_EMPTY_10022005_1619

#include <streams_boost/mpl/empty.hpp>
#include <streams_boost/fusion/sequence/intrinsic/empty.hpp>

namespace streams_boost { namespace mpl
{
    template <typename Tag>
    struct empty_impl;

    template <>
    struct empty_impl<fusion::fusion_sequence_tag>
    {
        template <typename Sequence>
        struct apply : fusion::result_of::empty<Sequence> {};
    };
}}

#endif