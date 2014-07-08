/*=============================================================================
    Copyright (c) 2001-2006 Joel de Guzman
    Copyright (c) 2005-2006 Dan Marsden

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(STREAMS_BOOST_FUSION_END_IMPL_31122005_1237)
#define STREAMS_BOOST_FUSION_END_IMPL_31122005_1237

#include <streams_boost/fusion/adapted/mpl/mpl_iterator.hpp>
#include <streams_boost/mpl/end.hpp>
#include <streams_boost/type_traits/add_const.hpp>

namespace streams_boost { namespace fusion
{
    struct mpl_sequence_tag;

    namespace extension
    {
        template <typename Tag>
        struct end_impl;

        template <>
        struct end_impl<mpl_sequence_tag>
        {
            template <typename Sequence>
            struct apply
            {
                typedef typename mpl::end<
                    typename remove_const<Sequence>::type
                >::type iterator;
                typedef mpl_iterator<iterator> type;
                
                static type
                call(Sequence)
                {
                    return type();
                }
            };
        };
    }
}}

#endif
