/*=============================================================================
    Copyright (c) 2001-2006 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(FUSION_ENABLE_COMPARISON_09232005_1958)
#define FUSION_ENABLE_COMPARISON_09232005_1958

#include <streams_boost/mpl/or.hpp>
#include <streams_boost/mpl/and.hpp>
#include <streams_boost/mpl/not.hpp>
#include <streams_boost/mpl/equal_to.hpp>
#include <streams_boost/fusion/support/is_sequence.hpp>
#include <streams_boost/fusion/sequence/intrinsic/size.hpp>
#include <streams_boost/fusion/support/detail/is_mpl_sequence.hpp>

namespace streams_boost { namespace fusion { namespace detail
{
    template <typename Sequence>
    struct is_native_fusion_sequence : is_base_of<sequence_root, Sequence> {};

    template <typename Seq1, typename Seq2>
    struct enable_equality
        : mpl::or_<is_native_fusion_sequence<Seq1>, is_native_fusion_sequence<Seq2> >
    {};

    template <typename Seq1, typename Seq2>
    struct enable_comparison
        : mpl::and_<
            mpl::or_<is_native_fusion_sequence<Seq1>, is_native_fusion_sequence<Seq2> >
          , mpl::equal_to<result_of::size<Seq1>, result_of::size<Seq2> > 
        >
    {};

}}}

#endif
