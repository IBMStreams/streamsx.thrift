/*=============================================================================
    Copyright (c) 2001-2006 Joel de Guzman
    Copyright (c) 2005-2006 Dan Marsden

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(STREAMS_BOOST_FUSION_BEGIN_IMPL_31122005_1209)
#define STREAMS_BOOST_FUSION_BEGIN_IMPL_31122005_1209

#include <streams_boost/fusion/adapted/mpl/mpl_iterator.hpp>
#include <streams_boost/mpl/begin.hpp>
#include <streams_boost/type_traits/remove_const.hpp>

namespace streams_boost { namespace fusion {
    
    struct mpl_sequence_tag;

    namespace extension
    {
        template <typename Tag>
        struct begin_impl;

        template <>
        struct begin_impl<mpl_sequence_tag>
        {
            template <typename Sequence>
            struct apply 
            {
                typedef typename mpl::begin<
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
