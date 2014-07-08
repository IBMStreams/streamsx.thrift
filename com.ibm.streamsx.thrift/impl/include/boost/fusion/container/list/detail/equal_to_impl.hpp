/*=============================================================================
    Copyright (c) 2001-2006 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(FUSION_EQUAL_TO_IMPL_09172005_1120)
#define FUSION_EQUAL_TO_IMPL_09172005_1120

#include <streams_boost/type_traits/is_same.hpp>
#include <streams_boost/mpl/equal_to.hpp>
#include <streams_boost/mpl/and.hpp>

namespace streams_boost { namespace fusion
{
    struct cons_iterator_tag;

    namespace extension
    {
        template <typename Tag>
        struct equal_to_impl;

        template <>
        struct equal_to_impl<cons_iterator_tag>
        {
            template <typename I1, typename I2>
            struct apply             
                : is_same<
                    typename I1::identity
                  , typename I2::identity
                >
            {
            };
        };
    }
}}

#endif
