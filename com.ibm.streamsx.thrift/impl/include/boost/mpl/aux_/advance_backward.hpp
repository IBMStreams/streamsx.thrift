
#if !defined(STREAMS_BOOST_PP_IS_ITERATING)

///// header body

#ifndef STREAMS_BOOST_MPL_AUX778076_ADVANCE_BACKWARD_HPP_INCLUDED
#define STREAMS_BOOST_MPL_AUX778076_ADVANCE_BACKWARD_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: advance_backward.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#if !defined(STREAMS_BOOST_MPL_PREPROCESSING_MODE)
#   include <streams_boost/mpl/prior.hpp>
#   include <streams_boost/mpl/apply_wrap.hpp>
#endif

#include <streams_boost/mpl/aux_/config/use_preprocessed.hpp>

#if    !defined(STREAMS_BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS) \
    && !defined(STREAMS_BOOST_MPL_PREPROCESSING_MODE)

#   define STREAMS_BOOST_MPL_PREPROCESSED_HEADER advance_backward.hpp
#   include <streams_boost/mpl/aux_/include_preprocessed.hpp>

#else

#   include <streams_boost/mpl/limits/unrolling.hpp>
#   include <streams_boost/mpl/aux_/nttp_decl.hpp>
#   include <streams_boost/mpl/aux_/config/eti.hpp>

#   include <streams_boost/preprocessor/iterate.hpp>
#   include <streams_boost/preprocessor/cat.hpp>
#   include <streams_boost/preprocessor/inc.hpp>

namespace streams_boost { namespace mpl { namespace aux {

// forward declaration
template< STREAMS_BOOST_MPL_AUX_NTTP_DECL(long, N) > struct advance_backward;

#   define STREAMS_BOOST_PP_ITERATION_PARAMS_1 \
    (3,(0, STREAMS_BOOST_MPL_LIMIT_UNROLLING, <streams_boost/mpl/aux_/advance_backward.hpp>))
#   include STREAMS_BOOST_PP_ITERATE()

// implementation for N that exceeds STREAMS_BOOST_MPL_LIMIT_UNROLLING
template< STREAMS_BOOST_MPL_AUX_NTTP_DECL(long, N) >
struct advance_backward
{
    template< typename Iterator > struct apply
    {
        typedef typename apply_wrap1<
              advance_backward<STREAMS_BOOST_MPL_LIMIT_UNROLLING>
            , Iterator
            >::type chunk_result_;

        typedef typename apply_wrap1<
              advance_backward<(
                (N - STREAMS_BOOST_MPL_LIMIT_UNROLLING) < 0
                    ? 0
                    : N - STREAMS_BOOST_MPL_LIMIT_UNROLLING
                    )>
            , chunk_result_
            >::type type;
    };
};

}}}

#endif // STREAMS_BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#endif // STREAMS_BOOST_MPL_AUX778076_ADVANCE_BACKWARD_HPP_INCLUDED

///// iteration, depth == 1

// For gcc 4.4 compatability, we must include the
// STREAMS_BOOST_PP_ITERATION_DEPTH test inside an #else clause.
#else // STREAMS_BOOST_PP_IS_ITERATING
#if STREAMS_BOOST_PP_ITERATION_DEPTH() == 1
#define i_ STREAMS_BOOST_PP_FRAME_ITERATION(1)

template<>
struct advance_backward< STREAMS_BOOST_PP_FRAME_ITERATION(1) >
{
    template< typename Iterator > struct apply
    {
        typedef Iterator iter0;

#if i_ > 0
#   define STREAMS_BOOST_PP_ITERATION_PARAMS_2 \
    (3,(1, STREAMS_BOOST_PP_FRAME_ITERATION(1), <streams_boost/mpl/aux_/advance_backward.hpp>))
#   include STREAMS_BOOST_PP_ITERATE()
#endif

        typedef STREAMS_BOOST_PP_CAT(iter,STREAMS_BOOST_PP_FRAME_ITERATION(1)) type;
    };

#if defined(STREAMS_BOOST_MPL_CFG_MSVC_60_ETI_BUG)
    /// ETI workaround
    template<> struct apply<int>
    {
        typedef int type;
    };
#endif
};

#undef i_

///// iteration, depth == 2

#elif STREAMS_BOOST_PP_ITERATION_DEPTH() == 2

#   define AUX778076_ITER_0 STREAMS_BOOST_PP_CAT(iter,STREAMS_BOOST_PP_DEC(STREAMS_BOOST_PP_FRAME_ITERATION(2)))
#   define AUX778076_ITER_1 STREAMS_BOOST_PP_CAT(iter,STREAMS_BOOST_PP_FRAME_ITERATION(2))

        typedef typename prior<AUX778076_ITER_0>::type AUX778076_ITER_1;
        
#   undef AUX778076_ITER_1
#   undef AUX778076_ITER_0

#endif // STREAMS_BOOST_PP_ITERATION_DEPTH()
#endif // STREAMS_BOOST_PP_IS_ITERATING
