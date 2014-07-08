/*=============================================================================
    Copyright (c) 2001-2006 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(STREAMS_BOOST_FUSION_VALUE_AT_IMPL_09262006_1926)
#define STREAMS_BOOST_FUSION_VALUE_AT_IMPL_09262006_1926

#include <streams_boost/tuple/tuple.hpp>

namespace streams_boost { namespace fusion
{
    struct streams_boost_tuple_tag;

    namespace extension
    {
        template<typename T>
        struct value_at_impl;

        template <>
        struct value_at_impl<streams_boost_tuple_tag>
        {
            template <typename Sequence, typename N>
            struct apply : tuples::element<N::value, Sequence> {};
        };
    }
}}

#endif
