/*=============================================================================
    Copyright (c) 2001-2006 Joel de Guzman
    Copyright (c) 2005-2006 Dan Marsden

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(STREAMS_BOOST_FUSION_HAS_KEY_IMPL_31122005_1647)
#define STREAMS_BOOST_FUSION_HAS_KEY_IMPL_31122005_1647

#include <streams_boost/mpl/has_key.hpp>

namespace streams_boost { namespace fusion 
{
    struct mpl_sequence_tag;

    namespace extension
    {
        template <typename Tag>
        struct has_key_impl;

        template <>
        struct has_key_impl<mpl_sequence_tag>
        {
            template <typename Sequence, typename Key>
            struct apply : mpl::has_key<Sequence, Key> {};
        };
    }
}}

#endif
