/*=============================================================================
    Copyright (c) 2001-2006 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(FUSION_FILTER_VIEW_ITERATOR_05062005_0849)
#define FUSION_FILTER_VIEW_ITERATOR_05062005_0849

#include <streams_boost/fusion/iterator/mpl/convert_iterator.hpp>
#include <streams_boost/fusion/adapted/mpl/mpl_iterator.hpp>
#include <streams_boost/fusion/iterator/value_of.hpp>
#include <streams_boost/fusion/support/iterator_base.hpp>
#include <streams_boost/fusion/algorithm/query/detail/find_if.hpp>
#include <streams_boost/mpl/lambda.hpp>
#include <streams_boost/mpl/quote.hpp>
#include <streams_boost/mpl/bind.hpp>
#include <streams_boost/mpl/placeholders.hpp>

#include <streams_boost/fusion/view/filter_view/detail/deref_impl.hpp>
#include <streams_boost/fusion/view/filter_view/detail/next_impl.hpp>
#include <streams_boost/fusion/view/filter_view/detail/value_of_impl.hpp>
#include <streams_boost/fusion/view/filter_view/detail/equal_to_impl.hpp>
#include <streams_boost/fusion/view/filter_view/detail/deref_data_impl.hpp>
#include <streams_boost/fusion/view/filter_view/detail/value_of_data_impl.hpp>
#include <streams_boost/fusion/view/filter_view/detail/key_of_impl.hpp>

namespace streams_boost { namespace fusion
{
    struct filter_view_iterator_tag;
    struct forward_traversal_tag;

    template <typename Category, typename First, typename Last, typename Pred>
    struct filter_iterator : iterator_base<filter_iterator<Category, First, Last, Pred> >
    {
        typedef convert_iterator<First> first_converter;
        typedef typename first_converter::type first_iter;
        typedef convert_iterator<Last> last_converter;
        typedef typename last_converter::type last_iter;

        typedef filter_view_iterator_tag fusion_tag;
        typedef Category category;
        typedef
            detail::static_find_if<
                first_iter
              , last_iter
              , mpl::bind1<
                    typename mpl::lambda<Pred>::type
                  , mpl::bind1<mpl::quote1<result_of::value_of>,mpl::_1>
                >
            >
        filter;
        typedef typename filter::type first_type;
        typedef last_iter last_type;
        typedef Pred pred_type;

        filter_iterator(First const& first)
            : first(filter::call(first_converter::call(first))) {}

        first_type first;
    };
}}

#endif


