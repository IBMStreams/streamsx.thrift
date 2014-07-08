/*=============================================================================
    Copyright (c) 2001-2006 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(FUSION_FIND_IF_05052005_1108)
#define FUSION_FIND_IF_05052005_1108

#include <streams_boost/fusion/algorithm/query/detail/find_if.hpp>
#include <streams_boost/fusion/sequence/intrinsic/begin.hpp>
#include <streams_boost/fusion/sequence/intrinsic/end.hpp>
#include <streams_boost/fusion/iterator/value_of.hpp>
#include <streams_boost/mpl/bind.hpp>
#include <streams_boost/mpl/lambda.hpp>
#include <streams_boost/mpl/quote.hpp>
#include <streams_boost/utility/enable_if.hpp>
#include <streams_boost/type_traits/is_const.hpp>

namespace streams_boost { namespace fusion
{
    namespace result_of
    {
        template <typename Sequence, typename Pred>
        struct find_if
        {
            typedef
                detail::static_find_if<
                    typename result_of::begin<Sequence>::type
                  , typename result_of::end<Sequence>::type
                  , mpl::bind1<
                        typename mpl::lambda<Pred>::type
                      , mpl::bind1<mpl::quote1<value_of>,mpl::_1>
                    >
                >
            filter;

            typedef typename filter::type type;
        };
    }

    template <typename Pred, typename Sequence>
    inline typename 
        lazy_disable_if<
            is_const<Sequence>
          , result_of::find_if<Sequence, Pred>
        >::type
    find_if(Sequence& seq)
    {
        typedef typename result_of::find_if<Sequence, Pred>::filter filter;
        return filter::call(fusion::begin(seq));
    }

    template <typename Pred, typename Sequence>
    inline typename result_of::find_if<Sequence const, Pred>::type const
    find_if(Sequence const& seq)
    {
        typedef typename result_of::find_if<Sequence const, Pred>::filter filter;
        return filter::call(fusion::begin(seq));
    }
}}

#endif

