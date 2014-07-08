/*=============================================================================
    Copyright (c) 2007 Tobias Schwinger

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !defined(STREAMS_BOOST_FUSION_REPETITIVE_VIEW_ITERATOR_HPP_INCLUDED)
#define STREAMS_BOOST_FUSION_REPETITIVE_VIEW_HPP_ITERATOR_INCLUDED

#include <streams_boost/fusion/support/iterator_base.hpp>
#include <streams_boost/fusion/support/category_of.hpp>
#include <streams_boost/fusion/iterator/mpl/convert_iterator.hpp>
#include <streams_boost/fusion/adapted/mpl/mpl_iterator.hpp>
#include <streams_boost/fusion/sequence/intrinsic/begin.hpp>
#include <streams_boost/fusion/sequence/intrinsic/end.hpp>
#include <streams_boost/fusion/view/repetitive_view/detail/deref_impl.hpp>
#include <streams_boost/fusion/view/repetitive_view/detail/next_impl.hpp>
#include <streams_boost/fusion/view/repetitive_view/detail/value_of_impl.hpp>

namespace streams_boost { namespace fusion
{
    struct repetitive_view_iterator_tag;

    template<typename Sequence, typename Pos =
        typename result_of::begin<Sequence>::type>
    struct repetitive_view_iterator
        : iterator_base< repetitive_view_iterator<Sequence,Pos> >
    {
        typedef repetitive_view_iterator_tag fusion_tag;

        typedef Sequence sequence_type;
        typedef typename convert_iterator<Pos>::type pos_type;
        typedef typename convert_iterator<typename result_of::begin<Sequence>::type>::type first_type;
        typedef typename convert_iterator<typename result_of::end<Sequence>::type>::type end_type;
        typedef single_pass_traversal_tag category;

        explicit repetitive_view_iterator(Sequence& seq)
            : seq(seq), pos(begin(seq)) {}

        repetitive_view_iterator(Sequence& seq, pos_type const& pos)
            : seq(seq), pos(pos) {}

        Sequence& seq;
        pos_type pos;

    };
}}

#endif

