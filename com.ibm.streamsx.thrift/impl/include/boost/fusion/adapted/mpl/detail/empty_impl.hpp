/*=============================================================================
    Copyright (c) 2001-2006 Joel de Guzman
    Copyright (c) 2005-2006 Dan Marsden

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(STREAMS_BOOST_FUSION_EMPTY_IMPL_31122005_1554)
#define STREAMS_BOOST_FUSION_EMPTY_IMPL_31122005_1554

#include <streams_boost/mpl/empty.hpp>

namespace streams_boost { namespace fusion 
{
    struct mpl_sequence_tag;

    namespace extension
    {
        template <>
        struct empty_impl<mpl_sequence_tag>
        {
            template <typename Sequence>
            struct apply : mpl::empty<Sequence> {};
        };
    }
}}

#endif
