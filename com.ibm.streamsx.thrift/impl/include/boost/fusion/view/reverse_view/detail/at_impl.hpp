/*=============================================================================
    Copyright (c) 2009 Christopher Schmidt

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef STREAMS_BOOST_FUSION_VIEW_REVERSE_VIEW_DETAIL_AT_IMPL_HPP
#define STREAMS_BOOST_FUSION_VIEW_REVERSE_VIEW_DETAIL_AT_IMPL_HPP

#include <streams_boost/fusion/sequence/intrinsic/at.hpp>
#include <streams_boost/mpl/minus.hpp>
#include <streams_boost/mpl/int.hpp>

namespace streams_boost { namespace fusion { namespace extension
{
    template <typename>
    struct at_impl;

    template <>
    struct at_impl<reverse_view_tag>
    {
        template <typename Seq, typename N>
        struct apply
        {
            typedef mpl::minus<typename Seq::size, mpl::int_<1>, N> real_n;

            typedef typename
                result_of::at<typename Seq::seq_type, real_n>::type
            type;

            static type
            call(Seq& seq)
            {
                return fusion::at<real_n>(seq.seq);
            }
        };
    };
}}}

#endif
