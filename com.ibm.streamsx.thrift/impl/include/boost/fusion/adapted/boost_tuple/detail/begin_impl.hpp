/*=============================================================================
    Copyright (c) 2001-2006 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(STREAMS_BOOST_FUSION_BEGIN_IMPL_09272006_0719)
#define STREAMS_BOOST_FUSION_BEGIN_IMPL_09272006_0719

#include <streams_boost/fusion/adapted/streams_boost_tuple/streams_boost_tuple_iterator.hpp>

namespace streams_boost { namespace fusion 
{
    struct streams_boost_tuple_tag;

    namespace extension
    {
        template<typename T>
        struct begin_impl;

        template <>
        struct begin_impl<streams_boost_tuple_tag>
        {
            template <typename Sequence>
            struct apply 
            {
                typedef streams_boost_tuple_iterator<Sequence> type;
    
                static type
                call(Sequence& v)
                {
                    return type(v);
                }
            };
        };
    }
}}

#endif
