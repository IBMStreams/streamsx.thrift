/*=============================================================================
    Copyright (c) 2001-2006 Joel de Guzman
    Copyright (c) 2009 Christopher Schmidt

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef STREAMS_BOOST_FUSION_CONTAINER_SET_DETAIL_END_IMPL_HPP
#define STREAMS_BOOST_FUSION_CONTAINER_SET_DETAIL_END_IMPL_HPP

#include <streams_boost/fusion/iterator/basic_iterator.hpp>

namespace streams_boost { namespace fusion { namespace extension
{
    template <typename>
    struct end_impl;

    template <>
    struct end_impl<set_tag>
    {
        template <typename Seq>
        struct apply
        {
            typedef
                basic_iterator<
                    set_iterator_tag
                  , typename Seq::category
                  , Seq
                  , Seq::size::value
                >
            type;

            static type
            call(Seq& seq)
            {
                return type(seq,0);
            }
        };
    };
}}}

#endif
