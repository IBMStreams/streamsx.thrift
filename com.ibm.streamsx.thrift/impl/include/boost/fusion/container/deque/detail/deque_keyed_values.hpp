/*=============================================================================
    Copyright (c) 2001-2006 Joel de Guzman
    Copyright (c) 2005-2006 Dan Marsden

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(STREAMS_BOOST_FUSION_DEQUE_DETAIL_DEQUE_KEYED_VALUES_26112006_1330)
#define STREAMS_BOOST_FUSION_DEQUE_DETAIL_DEQUE_KEYED_VALUES_26112006_1330

#include <streams_boost/fusion/container/deque/limits.hpp>
#include <streams_boost/fusion/container/deque/detail/keyed_element.hpp>

#include <streams_boost/preprocessor/iterate.hpp>
#include <streams_boost/preprocessor/repetition/enum_params_with_a_default.hpp>
#include <streams_boost/preprocessor/repetition/enum_shifted_params.hpp>
#include <streams_boost/preprocessor/repetition/enum.hpp>
#include <streams_boost/preprocessor/repetition/enum_params.hpp>
#include <streams_boost/type_traits/add_reference.hpp>

#include <streams_boost/mpl/plus.hpp>
#include <streams_boost/mpl/int.hpp>
#include <streams_boost/mpl/print.hpp>

#define FUSION_VOID(z, n, _) void_

namespace streams_boost { namespace fusion { 

    struct void_;

namespace detail {

    template<typename Key, typename Value, typename Rest>
    struct keyed_element;

    struct nil_keyed_element;

    template<typename N, STREAMS_BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(FUSION_MAX_DEQUE_SIZE, typename T, void_)>
    struct deque_keyed_values_impl;

    template<typename N>
    struct deque_keyed_values_impl<N, STREAMS_BOOST_PP_ENUM(FUSION_MAX_DEQUE_SIZE, FUSION_VOID, _)>
    {
        typedef nil_keyed_element type;

        static type call()
            {
                return type();
            }
    };
    
    template<typename N, STREAMS_BOOST_PP_ENUM_PARAMS(FUSION_MAX_DEQUE_SIZE, typename T)>
    struct deque_keyed_values_impl
    {
        typedef mpl::int_<mpl::plus<N, mpl::int_<1> >::value> next_index;

        typedef typename deque_keyed_values_impl<
            next_index, 
            STREAMS_BOOST_PP_ENUM_SHIFTED_PARAMS(FUSION_MAX_DEQUE_SIZE, T)>::type tail;
        typedef keyed_element<N, T0, tail> type;

#include <streams_boost/fusion/container/deque/detail/deque_keyed_values_call.hpp>

    };

    template<STREAMS_BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(FUSION_MAX_DEQUE_SIZE, typename T, void_)>
    struct deque_keyed_values
        : deque_keyed_values_impl<mpl::int_<0>, STREAMS_BOOST_PP_ENUM_PARAMS(FUSION_MAX_DEQUE_SIZE, T)>
    {};

}}}

#undef FUSION_VOID

#endif
