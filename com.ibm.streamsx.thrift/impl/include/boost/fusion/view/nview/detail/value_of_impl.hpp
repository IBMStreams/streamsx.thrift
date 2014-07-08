/*=============================================================================
    Copyright (c) 2009 Hartmut Kaiser

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !defined(STREAMS_BOOST_FUSION_VALUE_OF_PRIOR_IMPL_SEP_24_2009_0158PM)
#define STREAMS_BOOST_FUSION_VALUE_OF_PRIOR_IMPL_SEP_24_2009_0158PM

#include <streams_boost/fusion/iterator/deref.hpp>
#include <streams_boost/fusion/container/vector.hpp>

namespace streams_boost { namespace fusion
{
    struct nview_iterator_tag;

    template <typename Sequence, typename Pos>
    struct nview_iterator;

    namespace extension
    {
        template <typename Tag>
        struct value_of_impl;

        template <>
        struct value_of_impl<nview_iterator_tag>
        {
            template <typename Iterator>
            struct apply 
            {
                typedef typename Iterator::first_type first_type;
                typedef typename Iterator::sequence_type sequence_type;

                typedef typename result_of::deref<first_type>::type index;
                typedef typename result_of::at<
                    typename sequence_type::sequence_type, index>::type type;
            };
        };
    }

}}

#endif