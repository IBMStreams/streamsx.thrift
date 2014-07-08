/*=============================================================================
    Copyright (c) 2001-2006 Joel de Guzman
    Copyright (c) 2005-2006 Dan Marsden

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(STREAMS_BOOST_FUSION_DEQUE_AT_IMPL_09122006_2017)
#define STREAMS_BOOST_FUSION_DEQUE_AT_IMPL_09122006_2017

#include <streams_boost/fusion/container/deque/detail/keyed_element.hpp>

#include <streams_boost/mpl/eval_if.hpp>
#include <streams_boost/mpl/equal_to.hpp>
#include <streams_boost/mpl/assert.hpp>
#include <streams_boost/mpl/identity.hpp>

#include <streams_boost/type_traits/is_const.hpp>
#include <streams_boost/type_traits/add_const.hpp>
#include <streams_boost/type_traits/add_reference.hpp>

namespace streams_boost { namespace fusion { 

    struct deque_tag;

    namespace extension 
    {
        template<typename T>
        struct at_impl;
        
        template<>
        struct at_impl<deque_tag>
        {
            template<typename Sequence, typename N>
            struct apply
            {
                typedef typename Sequence::next_up next_up;
                typedef typename Sequence::next_down next_down;
                STREAMS_BOOST_MPL_ASSERT_RELATION(next_down::value, !=, next_up::value);
                
                typedef mpl::plus<next_down, mpl::int_<1> > offset;
                typedef mpl::int_<mpl::plus<N, offset>::value> adjusted_index;
                typedef typename detail::keyed_element_value_at<Sequence, adjusted_index>::type element_type;
                typedef typename add_reference<
                    typename mpl::eval_if<
                    is_const<Sequence>,
                    add_const<element_type>,
                    mpl::identity<element_type> >::type>::type type;

                static type call(Sequence& seq)
                {
                    return seq.get(adjusted_index());
                }
            };
        };
    }
}}

#endif