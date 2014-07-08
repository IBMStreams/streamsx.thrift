/*=============================================================================
    Copyright (c) 2007 Tobias Schwinger

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !defined(STREAMS_BOOST_FUSION_REPETITIVE_VIEW_DEREF_IMPL_HPP_INCLUDED)
#define STREAMS_BOOST_FUSION_REPETITIVE_VIEW_DEREF_IMPL_HPP_INCLUDED

#include <streams_boost/fusion/iterator/deref.hpp>

namespace streams_boost { namespace fusion
{
    struct repetitive_view_iterator_tag;

    namespace extension
    {
        template<typename Tag>
        struct deref_impl;

        template<>
        struct deref_impl<repetitive_view_iterator_tag>
        {
            template<typename Iterator>
            struct apply
            {
                typedef typename
                    result_of::deref<typename Iterator::pos_type>::type
                type;

                static type call(Iterator const& i)
                {
                    return *i.pos;
                }
            };
        };

    }

}}

#endif

