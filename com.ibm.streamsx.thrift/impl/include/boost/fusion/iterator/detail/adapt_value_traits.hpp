/*=============================================================================
    Copyright (c) 2001-2006 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(FUSION_ADAPT_VALUE_TRAITS_05062005_0859)
#define FUSION_ADAPT_VALUE_TRAITS_05062005_0859

#include <streams_boost/fusion/iterator/value_of.hpp>

namespace streams_boost { namespace fusion { namespace detail
{
    struct adapt_value_traits
    {
        template <typename Iterator>
        struct apply
        {
            typedef typename
                result_of::value_of<typename Iterator::first_type>::type
            type;
        };
    };
}}}

#endif

