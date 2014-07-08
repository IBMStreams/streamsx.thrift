/*=============================================================================
    Copyright (c) 2001-2006 Joel de Guzman
    Copyright (c) 2007 Dan Marsden

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(STREAMS_BOOST_FUSION_ALL_05052005_1238)
#define STREAMS_BOOST_FUSION_ALL_05052005_1238

#include <streams_boost/fusion/support/category_of.hpp>
#include <streams_boost/fusion/algorithm/query/detail/all.hpp>

namespace streams_boost { namespace fusion
{
    namespace result_of
    {
        template <typename Sequence, typename F>
        struct all
        {
            typedef bool type;
        };
    }

    template <typename Sequence, typename F>
    inline bool
    all(Sequence const& seq, F f)
    {
        return detail::all(seq, f, typename traits::category_of<Sequence>::type());
    }
}}

#endif

