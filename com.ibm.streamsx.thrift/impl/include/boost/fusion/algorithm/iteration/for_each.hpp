/*=============================================================================
    Copyright (c) 2001-2007 Joel de Guzman
    Copyright (c) 2007 Dan Marsden

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(STREAMS_BOOST_FUSION_FOR_EACH_20070527_0943)
#define STREAMS_BOOST_FUSION_FOR_EACH_20070527_0943

#include <streams_boost/fusion/algorithm/iteration/detail/for_each.hpp>

#include <streams_boost/fusion/support/category_of.hpp>

namespace streams_boost { namespace fusion {

    namespace result_of
    {
        template <typename Sequence, typename F>
        struct for_each
        {
            typedef void type;
        };
    }

    struct random_access_traversal_tag;

    template <typename Sequence, typename F>
    inline void
    for_each(Sequence& seq, F const& f)
    {
        detail::for_each(seq, f, typename traits::category_of<Sequence>::type());
    }

    template <typename Sequence, typename F>
    inline void
    for_each(Sequence const& seq, F const& f)
    {
        detail::for_each(seq, f, typename traits::category_of<Sequence>::type());
    }
}}

#endif