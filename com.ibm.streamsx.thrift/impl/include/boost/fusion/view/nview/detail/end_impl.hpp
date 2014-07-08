/*=============================================================================
    Copyright (c) 2009 Hartmut Kaiser

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !defined(STREAMS_BOOST_FUSION_NVIEW_END_IMPL_SEP_24_2009_0140PM)
#define STREAMS_BOOST_FUSION_NVIEW_END_IMPL_SEP_24_2009_0140PM

#include <streams_boost/mpl/end.hpp>
#include <streams_boost/fusion/sequence/intrinsic/end.hpp>

namespace streams_boost { namespace fusion
{
    struct nview_tag;

    template <typename Sequence, typename Pos>
    struct nview_iterator;

    namespace extension
    {
        template <typename Tag>
        struct end_impl;

        // Unary Version
        template <>
        struct end_impl<nview_tag>
        {
            template <typename Sequence>
            struct apply
            {
                typedef typename Sequence::index_type index_type;

                typedef nview_iterator<Sequence, 
                    typename mpl::end<index_type>::type> type;

                static type call(Sequence& s)
                {
                    return type(s);
                }
            };
        };
    }

}}

#endif

