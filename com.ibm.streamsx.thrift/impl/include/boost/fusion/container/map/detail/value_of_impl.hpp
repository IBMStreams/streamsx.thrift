/*=============================================================================
    Copyright (c) 2009 Christopher Schmidt

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef STREAMS_BOOST_FUSION_CONTAINER_MAP_DETAIL_VALUE_OF_IMPL_HPP
#define STREAMS_BOOST_FUSION_CONTAINER_MAP_DETAIL_VALUE_OF_IMPL_HPP

#include <streams_boost/fusion/sequence/intrinsic/value_at.hpp>
#include <streams_boost/type_traits/is_const.hpp>

namespace streams_boost { namespace fusion { namespace extension
{
    template <typename>
    struct value_of_impl;

    template <>
    struct value_of_impl<map_iterator_tag>
    {
        template <typename It>
        struct apply
        {
            typedef typename
                result_of::value_at<
                    typename mpl::if_<
                        is_const<typename It::seq_type>
                      , typename It::seq_type::storage_type const
                      , typename It::seq_type::storage_type
                    >::type
                  , typename It::index
                >::type
            type;
        };
    };
}}}

#endif
