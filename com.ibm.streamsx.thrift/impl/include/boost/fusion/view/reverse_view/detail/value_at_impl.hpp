/*=============================================================================
    Copyright (c) 2009 Christopher Schmidt

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef STREAMS_BOOST_FUSION_VIEW_REVERSE_VIEW_DETAIL_VALUE_AT_IMPL_HPP
#define STREAMS_BOOST_FUSION_VIEW_REVERSE_VIEW_DETAIL_VALUE_AT_IMPL_HPP

#include <streams_boost/fusion/sequence/intrinsic/value_at.hpp>
#include <streams_boost/mpl/minus.hpp>
#include <streams_boost/mpl/int.hpp>

namespace streams_boost { namespace fusion { namespace extension
{
    template <typename>
    struct value_at_impl;

    template <>
    struct value_at_impl<reverse_view_tag>
    {
        template <typename Seq, typename N>
        struct apply
          : result_of::value_at<
                typename Seq::seq_type
              , mpl::minus<typename Seq::size, mpl::int_<1>, N>
            >
        {};
    };
}}}

#endif
