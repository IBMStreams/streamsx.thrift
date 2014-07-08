/*=============================================================================
    Copyright (c) 2009 Hartmut Kaiser

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !defined(STREAMS_BOOST_FUSION_NVIEW_ITERATOR_SEP_24_2009_0329PM)
#define STREAMS_BOOST_FUSION_NVIEW_ITERATOR_SEP_24_2009_0329PM

#include <streams_boost/fusion/iterator/equal_to.hpp>

namespace streams_boost { namespace fusion 
{
    struct nview_iterator_tag;

    namespace extension
    {
        template<typename Tag>
        struct equal_to_impl;

        template<>
        struct equal_to_impl<nview_iterator_tag>
        {
            template<typename It1, typename It2>
            struct apply
              : result_of::equal_to<typename It1::first_type, typename It2::first_type>
            {};
        };
    }
}}

#endif
