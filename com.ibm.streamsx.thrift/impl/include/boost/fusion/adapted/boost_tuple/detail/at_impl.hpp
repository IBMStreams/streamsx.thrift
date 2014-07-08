/*=============================================================================
    Copyright (c) 2001-2006 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(STREAMS_BOOST_FUSION_AT_IMPL_09262006_1920)
#define STREAMS_BOOST_FUSION_AT_IMPL_09262006_1920

#include <streams_boost/tuple/tuple.hpp>
#include <streams_boost/mpl/if.hpp>

namespace streams_boost { namespace fusion 
{
    struct streams_boost_tuple_tag;

    namespace extension
    {
        template<typename T>
        struct at_impl;

        template <>
        struct at_impl<streams_boost_tuple_tag>
        {
            template <typename Sequence, typename N>
            struct apply 
            {
                typedef typename
                    tuples::element<N::value, Sequence>::type 
                element;
    
                typedef typename 
                    mpl::if_<
                        is_const<Sequence>
                      , typename tuples::access_traits<element>::const_type
                      , typename tuples::access_traits<element>::non_const_type
                    >::type 
                type;
    
                static type
                call(Sequence& seq)
                {
                    return tuples::get<N::value>(seq);
                }
            };
        };
    }
}}

#endif
