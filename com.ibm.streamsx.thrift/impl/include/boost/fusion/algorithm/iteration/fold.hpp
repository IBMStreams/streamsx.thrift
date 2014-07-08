/*=============================================================================
    Copyright (c) 2001-2007 Joel de Guzman
    Copyright (c) 2007 Dan Marsden

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(STREAMS_BOOST_FUSION_FOLD_05052005_1214)
#define STREAMS_BOOST_FUSION_FOLD_05052005_1214

#include <streams_boost/fusion/algorithm/iteration/detail/fold.hpp>
#include <streams_boost/fusion/sequence/intrinsic/size.hpp>
#include <streams_boost/fusion/support/category_of.hpp>

#include <streams_boost/type_traits/is_base_of.hpp>
#include <streams_boost/static_assert.hpp>

namespace streams_boost { namespace fusion { 

    struct random_access_traversal_tag;

    namespace result_of
    {
        template <typename Sequence, typename State, typename F>
        struct fold
            : fusion::detail::choose_fold<
            Sequence, State, F
            , is_base_of<random_access_traversal_tag, typename traits::category_of<Sequence>::type>::value>
        {};
    }

    template <typename Sequence, typename State, typename F>
    inline typename result_of::fold<Sequence, State, F>::type
    fold(Sequence& seq, State const& state, F f)
    {
        return detail::fold(seq, state, f, typename traits::category_of<Sequence>::type());
    }

    template <typename Sequence, typename State, typename F>
    inline typename result_of::fold<Sequence const, State, F>::type
    fold(Sequence const& seq, State const& state, F f)
    {
        return detail::fold(seq, state, f, typename traits::category_of<Sequence>::type());
    }
}}

#endif

