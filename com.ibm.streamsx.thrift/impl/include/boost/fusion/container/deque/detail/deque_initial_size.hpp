/*=============================================================================
    Copyright (c) 2001-2006 Joel de Guzman
    Copyright (c) 2005-2006 Dan Marsden

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(STREAMS_BOOST_FUSION_DEQUE_DETAIL_DEQUE_INITIAL_SIZE_26112006_2139)
#define STREAMS_BOOST_FUSION_DEQUE_DETAIL_DEQUE_INITIAL_SIZE_26112006_2139

#include <streams_boost/preprocessor/repetition/enum_params.hpp>
#include <streams_boost/mpl/find.hpp>
#include <streams_boost/mpl/begin.hpp>
#include <streams_boost/mpl/distance.hpp>
#include <streams_boost/mpl/equal_to.hpp>
#include <streams_boost/mpl/vector.hpp>

namespace streams_boost { namespace fusion { 

    struct void_;

namespace detail {

    template<STREAMS_BOOST_PP_ENUM_PARAMS(FUSION_MAX_DEQUE_SIZE, typename T)>
    struct deque_initial_size
    {
        typedef mpl::vector<STREAMS_BOOST_PP_ENUM_PARAMS(FUSION_MAX_DEQUE_SIZE, T)> args;
        typedef typename mpl::find<args, void_>::type first_void;
        typedef typename mpl::distance<typename mpl::begin<args>::type, first_void>::type type;
    };
}}}

#endif
