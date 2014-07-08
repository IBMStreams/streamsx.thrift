/*=============================================================================
    Copyright (c) 2001-2006 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(STREAMS_BOOST_FUSION_END_IMPL_09272006_0721)
#define STREAMS_BOOST_FUSION_END_IMPL_09272006_0721

#include <streams_boost/fusion/adapted/streams_boost_tuple/streams_boost_tuple_iterator.hpp>
#include <streams_boost/mpl/if.hpp>
#include <streams_boost/type_traits/is_const.hpp>

namespace streams_boost { namespace tuples
{
    struct null_type;
}}
    
namespace streams_boost { namespace fusion
{
    struct streams_boost_tuple_tag;

    namespace extension
    {
        template <typename Tag>
        struct end_impl;

        template <>
        struct end_impl<streams_boost_tuple_tag>
        {
            template <typename Sequence>
            struct apply 
            {
                typedef 
                    streams_boost_tuple_iterator<
                        typename mpl::if_<
                            is_const<Sequence>
                          , tuples::null_type const
                          , tuples::null_type
                        >::type
                    > 
                type;

                static type
                call(Sequence& seq)
                {
                    return type(seq);
                }
            };
        };
    }
}}

#endif
