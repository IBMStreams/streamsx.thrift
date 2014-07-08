/*=============================================================================
    Copyright (c) 2001-2006 Joel de Guzman
    Copyright (c) 2006 Dan Marsden

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(STREAMS_BOOST_FUSION_SWAP_20070501_1956)
#define STREAMS_BOOST_FUSION_SWAP_20070501_1956

#include <algorithm>

#include <streams_boost/fusion/support/is_sequence.hpp>
#include <streams_boost/fusion/view/zip_view.hpp>
#include <streams_boost/fusion/algorithm/iteration/for_each.hpp>
#include <streams_boost/utility/enable_if.hpp>
#include <streams_boost/fusion/sequence/intrinsic/front.hpp>
#include <streams_boost/fusion/sequence/intrinsic/back.hpp>
#include <streams_boost/mpl/and.hpp>

namespace streams_boost { namespace fusion {
    namespace result_of
    {
        template<typename Seq1, typename Seq2>
        struct swap
        {
            typedef void type;
        };
    }

    namespace detail
    {
        struct swap
        {
            template<typename Elem>
            struct result
            {
                typedef void type;
            };

            template<typename Elem>
            void operator()(Elem const& e) const
            {
                using std::swap;
                swap(front(e), back(e));
            }
        };
    }

    template<typename Seq1, typename Seq2>
    typename enable_if<mpl::and_<traits::is_sequence<Seq1>, traits::is_sequence<Seq2> >, void>::type 
    swap(Seq1& lhs, Seq2& rhs)
    {
        typedef vector<Seq1&, Seq2&> references;
        for_each(zip_view<references>(references(lhs, rhs)), detail::swap());
    }
}}

#endif
