/*=============================================================================
    Copyright (c) 2009 Christopher Schmidt

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef STREAMS_BOOST_FUSION_ITERATOR_KEY_OF_HPP
#define STREAMS_BOOST_FUSION_ITERATOR_KEY_OF_HPP

#include <streams_boost/fusion/support/tag_of.hpp>

namespace streams_boost { namespace fusion
{
    struct iterator_facade_tag;

    namespace extension
    {
        template <typename>
        struct key_of_impl;

        template <>
        struct key_of_impl<iterator_facade_tag>
        {
            template <typename It>
            struct apply
              : It::template key_of<It>
            {};
        };
    }

    namespace result_of
    {
        template <typename It>
        struct key_of
          : extension::key_of_impl<typename traits::tag_of<It>::type>::
                template apply<It>
        {};
    }
}}

#endif
