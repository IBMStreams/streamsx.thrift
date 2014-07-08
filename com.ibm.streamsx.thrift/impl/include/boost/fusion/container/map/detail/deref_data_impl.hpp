/*=============================================================================
    Copyright (c) 2009 Christopher Schmidt

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef STREAMS_BOOST_FUSION_CONTAINER_MAP_DETAIL_DEREF_DATA_IMPL_HPP
#define STREAMS_BOOST_FUSION_CONTAINER_MAP_DETAIL_DEREF_DATA_IMPL_HPP

#include <streams_boost/fusion/iterator/value_of.hpp>
#include <streams_boost/fusion/iterator/deref.hpp>
#include <streams_boost/fusion/support/detail/access.hpp>
#include <streams_boost/type_traits/is_const.hpp>
#include <streams_boost/mpl/eval_if.hpp>
#include <streams_boost/mpl/identity.hpp>

namespace streams_boost { namespace fusion { namespace extension
{
    template <typename>
    struct deref_data_impl;

    template <>
    struct deref_data_impl<map_iterator_tag>
    {
        template <typename It>
        struct apply
        {
            typedef typename result_of::value_of<It>::type::second_type data;

            typedef typename
                mpl::eval_if<
                    is_const<typename It::seq_type>
                  , detail::cref_result<mpl::identity<data> >
                  , detail::ref_result<mpl::identity<data> >
                >::type
            type;

            static type
            call(It const& it)
            {
                return deref(it).second;
            }
        };
    };
}}}

#endif
