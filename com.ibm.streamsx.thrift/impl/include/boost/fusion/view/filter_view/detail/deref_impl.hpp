/*=============================================================================
    Copyright (c) 2001-2006 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(FUSION_DEREF_IMPL_05062005_0905)
#define FUSION_DEREF_IMPL_05062005_0905

#include <streams_boost/fusion/iterator/detail/adapt_deref_traits.hpp>

namespace streams_boost { namespace fusion
{
    struct filter_view_iterator_tag;

    namespace extension
    {
        template <typename Tag>
        struct deref_impl;

        template <>
        struct deref_impl<filter_view_iterator_tag>
            : detail::adapt_deref_traits {};
    }
}}

#endif

