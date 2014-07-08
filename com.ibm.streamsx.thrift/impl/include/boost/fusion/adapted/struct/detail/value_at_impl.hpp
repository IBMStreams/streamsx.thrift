/*=============================================================================
    Copyright (c) 2001-2006 Joel de Guzman
    Copyright (c) 2005-2006 Dan Marsden

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(STREAMS_BOOST_FUSION_VALUE_AT_IMPL_24122005_1917)
#define STREAMS_BOOST_FUSION_VALUE_AT_IMPL_24122005_1917

#include <streams_boost/mpl/if.hpp>
#include <streams_boost/static_assert.hpp>

namespace streams_boost { namespace fusion
{
    struct struct_tag;

    namespace extension
    {
        template<typename T>
        struct value_at_impl;

        template <typename Struct, int N>
        struct struct_member;

        template <typename Struct>
        struct struct_size;

        template <>
        struct value_at_impl<struct_tag>
        {
            template <typename Sequence, typename N>
            struct apply
            {
                static int const n_value = N::value;
                STREAMS_BOOST_MPL_ASSERT_RELATION(
                    n_value, <=, extension::struct_size<Sequence>::value);

                typedef typename
                    extension::struct_member<Sequence, N::value>::type
                type;
            };
        };
    }
}}

#endif
