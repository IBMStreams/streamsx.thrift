/*=============================================================================
    Copyright (c) 2009 Hartmut Kaiser

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !defined(STREAMS_BOOST_FUSION_NVIEW_ADVANCE_IMPL_SEP_24_2009_0212PM)
#define STREAMS_BOOST_FUSION_NVIEW_ADVANCE_IMPL_SEP_24_2009_0212PM

#include <streams_boost/mpl/advance.hpp>
#include <streams_boost/fusion/iterator/advance.hpp>

namespace streams_boost { namespace fusion 
{
    struct nview_iterator_tag;

    template <typename Sequence, typename Pos>
    struct nview_iterator;

    namespace extension
    {
        template<typename Tag>
        struct advance_impl;

        template<>
        struct advance_impl<nview_iterator_tag>
        {
            template<typename Iterator, typename Dist>
            struct apply
            {
                typedef typename Iterator::first_type::iterator_type iterator_type;
                typedef typename Iterator::sequence_type sequence_type;

                typedef nview_iterator<sequence_type, 
                    typename mpl::advance<iterator_type, Dist>::type> type;

                static type
                call(Iterator const& i)
                {
                    return type(i.seq);
                }
            };
        };
    }

}}

#endif
