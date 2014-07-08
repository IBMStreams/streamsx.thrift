/*=============================================================================
    Copyright (c) 2009 Hartmut Kaiser

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef STREAMS_BOOST_PP_IS_ITERATING

#if !defined(STREAMS_BOOST_FUSION_NVIEW_IMPL_SEP_23_2009_1017PM)
#define STREAMS_BOOST_FUSION_NVIEW_IMPL_SEP_23_2009_1017PM

#include <climits>
#include <streams_boost/preprocessor/cat.hpp>
#include <streams_boost/preprocessor/repeat.hpp>
#include <streams_boost/preprocessor/iterate.hpp>
#include <streams_boost/preprocessor/repetition/enum_params.hpp>
#include <streams_boost/preprocessor/repetition/enum_binary_params.hpp>
#include <streams_boost/preprocessor/repetition/enum_params_with_a_default.hpp>

#define STREAMS_BOOST_PP_ITERATION_PARAMS_1                                           \
    (3, (1, FUSION_MAX_VECTOR_SIZE,                                           \
    "streams_boost/fusion/view/nview/detail/nview_impl.hpp"))                         \
    /**/

///////////////////////////////////////////////////////////////////////////////
namespace streams_boost { namespace fusion { namespace result_of
{
    template <typename Sequence
      , STREAMS_BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(FUSION_MAX_VECTOR_SIZE, int I, LONG_MAX)>
    struct as_nview
    {
        typedef mpl::vector_c<
            int, STREAMS_BOOST_PP_ENUM_PARAMS(FUSION_MAX_VECTOR_SIZE, I)
        > index_type;
        typedef nview<Sequence, index_type> type;
    };
}}}

#include STREAMS_BOOST_PP_ITERATE()

#endif

///////////////////////////////////////////////////////////////////////////////
//  Preprocessor vertical repetition code
///////////////////////////////////////////////////////////////////////////////
#else // defined(STREAMS_BOOST_PP_IS_ITERATING)

#define N STREAMS_BOOST_PP_ITERATION()

#if N < FUSION_MAX_VECTOR_SIZE
namespace streams_boost { namespace fusion { namespace result_of
{
    template <typename Sequence, STREAMS_BOOST_PP_ENUM_PARAMS(N, int I)>
    struct as_nview<Sequence, STREAMS_BOOST_PP_ENUM_PARAMS(N, I)>
    {
        typedef mpl::vector_c<int, STREAMS_BOOST_PP_ENUM_PARAMS(N, I)> index_type;
        typedef nview<Sequence, index_type> type;
    };
}}}
#endif

namespace streams_boost { namespace fusion
{
    template<STREAMS_BOOST_PP_ENUM_PARAMS(N, int I), typename Sequence>
    inline nview<Sequence, mpl::vector_c<int, STREAMS_BOOST_PP_ENUM_PARAMS(N, I)> >
    as_nview(Sequence& s)
    {
        typedef mpl::vector_c<int, STREAMS_BOOST_PP_ENUM_PARAMS(N, I)> index_type;
        return nview<Sequence, index_type>(s);
    }

}}

#undef N

#endif