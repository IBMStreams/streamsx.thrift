/*=============================================================================
    Copyright (c) 2001-2006 Joel de Guzman
    Copyright (c) 2005-2006 Dan Marsden

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(STREAMS_BOOST_FUSION_CATEGORY_OF_IMPL_20060217_2141)
#define STREAMS_BOOST_FUSION_CATEGORY_OF_IMPL_20060217_2141

#include <streams_boost/fusion/support/detail/mpl_iterator_category.hpp>
#include <streams_boost/mpl/begin_end.hpp>
#include <streams_boost/mpl/is_sequence.hpp>
#include <streams_boost/static_assert.hpp>

namespace streams_boost { namespace fusion {

    namespace detail
    {
        template <typename T>
        struct mpl_sequence_category_of
        {
            // assumes T is an mpl sequence
            // there should be no way this will ever be
            // called where T is an mpl iterator
        
            STREAMS_BOOST_STATIC_ASSERT(mpl::is_sequence<T>::value);
            typedef typename 
                mpl_iterator_category<
                    typename mpl::begin<T>::type::category
                >::type
            type;
        };
    }

    struct mpl_sequence_tag;

    namespace extension
    {
        template<typename Tag>
        struct category_of_impl;

        template<>
        struct category_of_impl<mpl_sequence_tag>
        {
            template<typename T>
            struct apply
                : detail::mpl_sequence_category_of<T>
            {};
        };
    }
}}

#endif
