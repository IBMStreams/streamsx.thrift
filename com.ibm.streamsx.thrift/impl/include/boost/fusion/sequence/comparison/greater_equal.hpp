/*=============================================================================
    Copyright (c) 1999-2003 Jaakko Jarvi
    Copyright (c) 2001-2006 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(FUSION_GREATER_EQUAL_05052005_0432)
#define FUSION_GREATER_EQUAL_05052005_0432

#include <streams_boost/fusion/sequence/intrinsic/begin.hpp>
#include <streams_boost/fusion/sequence/intrinsic/end.hpp>
#include <streams_boost/fusion/sequence/intrinsic/size.hpp>
#include <streams_boost/fusion/sequence/comparison/detail/enable_comparison.hpp>

#if defined(FUSION_DIRECT_OPERATOR_USAGE)
#include <streams_boost/fusion/sequence/comparison/detail/greater_equal.hpp>
#else
#include <streams_boost/fusion/sequence/comparison/less.hpp>
#endif

namespace streams_boost { namespace fusion
{
    template <typename Seq1, typename Seq2>
    inline bool
    greater_equal(Seq1 const& a, Seq2 const& b)
    {
#if defined(FUSION_DIRECT_OPERATOR_USAGE)
        return detail::sequence_greater_equal<Seq1 const, Seq2 const>::
            call(fusion::begin(a), fusion::begin(b));
#else
        return !(a < b);
#endif
    }

    namespace operators
    {
        template <typename Seq1, typename Seq2>
        inline typename
            enable_if<
                detail::enable_comparison<Seq1, Seq2>
              , bool
            >::type
        operator>=(Seq1 const& a, Seq2 const& b)
        {
            return fusion::greater_equal(a, b);
        }
    }
    using operators::operator>=;
}}

#endif