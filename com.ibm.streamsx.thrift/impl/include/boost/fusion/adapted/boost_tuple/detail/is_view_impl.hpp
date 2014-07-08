/*=============================================================================
    Copyright (c) 2001-2006 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(STREAMS_BOOST_FUSION_IS_VIEW_IMPL_09272006_0725)
#define STREAMS_BOOST_FUSION_IS_VIEW_IMPL_09272006_0725

#include <streams_boost/mpl/bool.hpp>

namespace streams_boost { namespace fusion 
{
    struct streams_boost_tuple_tag;

    namespace extension
    {
        template<typename Tag>
        struct is_view_impl;

        template<>
        struct is_view_impl<streams_boost_tuple_tag>
        {
            template<typename T>
            struct apply : mpl::false_ {};
        };
    }
}}

#endif
