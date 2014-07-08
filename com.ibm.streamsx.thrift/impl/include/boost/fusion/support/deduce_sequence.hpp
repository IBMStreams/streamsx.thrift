/*=============================================================================
    Copyright (c) 2007 Tobias Schwinger

    Use modification and distribution are subject to the Boost Software
    License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
    http://www.streams_boost.org/LICENSE_1_0.txt).
==============================================================================*/

#if !defined(STREAMS_BOOST_FUSION_SUPPORT_DEDUCE_SEQUENCE_HPP_INCLUDED)
#define STREAMS_BOOST_FUSION_SUPPORT_DEDUCE_SEQUENCE_HPP_INCLUDED

#include <streams_boost/fusion/support/deduce.hpp>
#include <streams_boost/fusion/container/vector/convert.hpp>
#include <streams_boost/fusion/view/transform_view.hpp>


namespace streams_boost { namespace fusion { namespace traits
{
    template <class Sequence> struct deduce_sequence;

    namespace detail
    {
        struct deducer
        {
            template <typename Sig>
            struct result;

            template <class Self, typename T>
            struct result< Self(T) >
                : fusion::traits::deduce<T>
            { };
        };
    }

    template <class Sequence>
    struct deduce_sequence
        : result_of::as_vector<
            fusion::transform_view<Sequence, detail::deducer> >
    { };

}}}

#endif

