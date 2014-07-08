/*=============================================================================
    Copyright (c) 2001-2006 Joel de Guzman
    Copyright (c) 2006 Dan Marsden

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(FUSION_ZIP_VIEW_ITERATOR_23012006_0814)
#define FUSION_ZIP_VIEW_ITERATOR_23012006_0814

#include <streams_boost/fusion/view/zip_view/zip_view_iterator_fwd.hpp>
#include <streams_boost/fusion/support/iterator_base.hpp>
#include <streams_boost/fusion/view/zip_view/detail/deref_impl.hpp>
#include <streams_boost/fusion/view/zip_view/detail/next_impl.hpp>
#include <streams_boost/fusion/view/zip_view/detail/prior_impl.hpp>
#include <streams_boost/fusion/view/zip_view/detail/advance_impl.hpp>
#include <streams_boost/fusion/view/zip_view/detail/distance_impl.hpp>
#include <streams_boost/fusion/view/zip_view/detail/value_of_impl.hpp>
#include <streams_boost/fusion/view/zip_view/detail/equal_to_impl.hpp>

#include <streams_boost/fusion/container/vector/convert.hpp>

namespace streams_boost { namespace fusion {
    
    struct zip_view_iterator_tag;

    template<
        typename IteratorSequence, 
        typename Traversal>
    struct zip_view_iterator
        : iterator_base<zip_view_iterator<IteratorSequence, Traversal> >
    {
        typedef zip_view_iterator_tag fusion_tag;
        typedef Traversal category;

        template<typename InitSeq>
        zip_view_iterator(
            const InitSeq& iterator_seq)
            : iterators_(iterator_seq)
        {}

        typedef typename result_of::as_vector<IteratorSequence>::type iterators;
        iterators iterators_;
    };
}}

#endif