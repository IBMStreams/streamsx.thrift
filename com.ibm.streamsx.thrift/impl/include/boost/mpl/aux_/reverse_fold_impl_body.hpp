
// NO INCLUDE GUARDS, THE HEADER IS INTENDED FOR MULTIPLE INCLUSION!

#if !defined(STREAMS_BOOST_PP_IS_ITERATING)

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: reverse_fold_impl_body.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#   include <streams_boost/mpl/limits/unrolling.hpp>
#   include <streams_boost/mpl/aux_/preprocessor/repeat.hpp>
#   include <streams_boost/mpl/aux_/config/ctps.hpp>
#   include <streams_boost/mpl/aux_/nttp_decl.hpp>

#   include <streams_boost/preprocessor/arithmetic/sub.hpp>
#   include <streams_boost/preprocessor/iterate.hpp>
#   include <streams_boost/preprocessor/dec.hpp>
#   include <streams_boost/preprocessor/inc.hpp>
#   include <streams_boost/preprocessor/cat.hpp>

// local macros, #undef-ined at the end of the header

#   define AUX778076_ITER_FOLD_FORWARD_STEP(unused, n_, unused2) \
    typedef typename apply2< \
          ForwardOp \
        , STREAMS_BOOST_PP_CAT(fwd_state,n_) \
        , AUX778076_FOLD_IMPL_OP(STREAMS_BOOST_PP_CAT(iter,n_)) \
        >::type STREAMS_BOOST_PP_CAT(fwd_state,STREAMS_BOOST_PP_INC(n_)); \
    typedef typename mpl::next<STREAMS_BOOST_PP_CAT(iter,n_)>::type \
        STREAMS_BOOST_PP_CAT(iter,STREAMS_BOOST_PP_INC(n_)); \
    /**/

#   define AUX778076_ITER_FOLD_BACKWARD_STEP_FUNC(n_) \
    typedef typename apply2< \
          BackwardOp \
        , STREAMS_BOOST_PP_CAT(bkwd_state,n_) \
        , AUX778076_FOLD_IMPL_OP(STREAMS_BOOST_PP_CAT(iter,STREAMS_BOOST_PP_DEC(n_))) \
        >::type STREAMS_BOOST_PP_CAT(bkwd_state,STREAMS_BOOST_PP_DEC(n_)); \
    /**/

#   define AUX778076_ITER_FOLD_BACKWARD_STEP(unused, n_, j) \
    AUX778076_ITER_FOLD_BACKWARD_STEP_FUNC( \
          STREAMS_BOOST_PP_SUB_D(1,j,n_) \
        ) \
    /**/

#   define AUX778076_FIRST_BACKWARD_STATE_TYPEDEF(n_) \
    typedef typename nested_chunk::state STREAMS_BOOST_PP_CAT(bkwd_state,n_);
    /**/

#   define AUX778076_FOLD_IMPL_NAME \
    STREAMS_BOOST_PP_CAT(AUX778076_FOLD_IMPL_NAME_PREFIX,_impl) \
    /**/

#   define AUX778076_FOLD_CHUNK_NAME \
    STREAMS_BOOST_PP_CAT(AUX778076_FOLD_IMPL_NAME_PREFIX,_chunk) \
    /**/

namespace streams_boost { namespace mpl { namespace aux {

/// forward declaration
template<
      STREAMS_BOOST_MPL_AUX_NTTP_DECL(long, N)
    , typename First
    , typename Last
    , typename State
    , typename BackwardOp
    , typename ForwardOp
    > 
struct AUX778076_FOLD_IMPL_NAME;

#if !defined(STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION) \
    && !defined(STREAMS_BOOST_MPL_CFG_NO_NONTYPE_TEMPLATE_PARTIAL_SPEC)

#   define STREAMS_BOOST_PP_ITERATION_PARAMS_1 \
    (3,(0, STREAMS_BOOST_MPL_LIMIT_UNROLLING, <streams_boost/mpl/aux_/reverse_fold_impl_body.hpp>))
#   include STREAMS_BOOST_PP_ITERATE()

// implementation for N that exceeds STREAMS_BOOST_MPL_LIMIT_UNROLLING
template<
      STREAMS_BOOST_MPL_AUX_NTTP_DECL(long, N)
    , typename First
    , typename Last
    , typename State
    , typename BackwardOp
    , typename ForwardOp
    > 
struct AUX778076_FOLD_IMPL_NAME
{
    typedef First iter0;
    typedef State fwd_state0;

    STREAMS_BOOST_MPL_PP_REPEAT(
          STREAMS_BOOST_MPL_LIMIT_UNROLLING
        , AUX778076_ITER_FOLD_FORWARD_STEP
        , unused
        )

    typedef AUX778076_FOLD_IMPL_NAME<
          ( (N - STREAMS_BOOST_MPL_LIMIT_UNROLLING) < 0 ? 0 : N - STREAMS_BOOST_MPL_LIMIT_UNROLLING )
        , STREAMS_BOOST_PP_CAT(iter,STREAMS_BOOST_MPL_LIMIT_UNROLLING)
        , Last
        , STREAMS_BOOST_PP_CAT(fwd_state,STREAMS_BOOST_MPL_LIMIT_UNROLLING)
        , BackwardOp
        , ForwardOp
        > nested_chunk;
        
    AUX778076_FIRST_BACKWARD_STATE_TYPEDEF(STREAMS_BOOST_MPL_LIMIT_UNROLLING)

    STREAMS_BOOST_MPL_PP_REPEAT(
          STREAMS_BOOST_MPL_LIMIT_UNROLLING
        , AUX778076_ITER_FOLD_BACKWARD_STEP
        , STREAMS_BOOST_MPL_LIMIT_UNROLLING
        )

    typedef bkwd_state0 state;
    typedef typename nested_chunk::iterator iterator;
};

// fallback implementation for sequences of unknown size
template<
      typename First
    , typename Last
    , typename State
    , typename BackwardOp
    , typename ForwardOp
    > 
struct AUX778076_FOLD_IMPL_NAME<-1,First,Last,State,BackwardOp,ForwardOp>
{
    typedef AUX778076_FOLD_IMPL_NAME<
          -1
        , typename mpl::next<First>::type
        , Last
        , typename apply2<ForwardOp,State,AUX778076_FOLD_IMPL_OP(First)>::type
        , BackwardOp
        , ForwardOp
        > nested_step;

    typedef typename apply2<
          BackwardOp
        , typename nested_step::state
        , AUX778076_FOLD_IMPL_OP(First)
        >::type state;

    typedef typename nested_step::iterator iterator;
};

template<
      typename Last
    , typename State
    , typename BackwardOp
    , typename ForwardOp
    > 
struct AUX778076_FOLD_IMPL_NAME<-1,Last,Last,State,BackwardOp,ForwardOp>
{
    typedef State state;
    typedef Last iterator;
};

#else // STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

template< STREAMS_BOOST_MPL_AUX_NTTP_DECL(long, N) >
struct AUX778076_FOLD_CHUNK_NAME;

#   define STREAMS_BOOST_PP_ITERATION_PARAMS_1 \
    (3,(0, STREAMS_BOOST_MPL_LIMIT_UNROLLING, <streams_boost/mpl/aux_/reverse_fold_impl_body.hpp>))
#   include STREAMS_BOOST_PP_ITERATE()

// implementation for N that exceeds STREAMS_BOOST_MPL_LIMIT_UNROLLING
template< STREAMS_BOOST_MPL_AUX_NTTP_DECL(long, N) > 
struct AUX778076_FOLD_CHUNK_NAME
{
    template<
          typename First
        , typename Last
        , typename State
        , typename BackwardOp
        , typename ForwardOp
        > 
    struct result_
    {
        typedef First iter0;
        typedef State fwd_state0;

        STREAMS_BOOST_MPL_PP_REPEAT(
              STREAMS_BOOST_MPL_LIMIT_UNROLLING
            , AUX778076_ITER_FOLD_FORWARD_STEP
            , unused
            )

        typedef AUX778076_FOLD_IMPL_NAME<
              ( (N - STREAMS_BOOST_MPL_LIMIT_UNROLLING) < 0 ? 0 : N - STREAMS_BOOST_MPL_LIMIT_UNROLLING )
            , STREAMS_BOOST_PP_CAT(iter,STREAMS_BOOST_MPL_LIMIT_UNROLLING)
            , Last
            , STREAMS_BOOST_PP_CAT(fwd_state,STREAMS_BOOST_MPL_LIMIT_UNROLLING)
            , BackwardOp
            , ForwardOp
            > nested_chunk;
            
        AUX778076_FIRST_BACKWARD_STATE_TYPEDEF(STREAMS_BOOST_MPL_LIMIT_UNROLLING)

        STREAMS_BOOST_MPL_PP_REPEAT(
              STREAMS_BOOST_MPL_LIMIT_UNROLLING
            , AUX778076_ITER_FOLD_BACKWARD_STEP
            , STREAMS_BOOST_MPL_LIMIT_UNROLLING
            )

        typedef bkwd_state0 state;
        typedef typename nested_chunk::iterator iterator;
    };
};

// fallback implementation for sequences of unknown size
template<
      typename First
    , typename Last
    , typename State
    , typename BackwardOp
    , typename ForwardOp
    > 
struct STREAMS_BOOST_PP_CAT(AUX778076_FOLD_IMPL_NAME_PREFIX,_step);

template<
      typename Last
    , typename State
    >
struct STREAMS_BOOST_PP_CAT(AUX778076_FOLD_IMPL_NAME_PREFIX,_null_step)
{
    typedef Last iterator;
    typedef State state;
};

template<> 
struct AUX778076_FOLD_CHUNK_NAME<-1>
{
    template<
          typename First
        , typename Last
        , typename State
        , typename BackwardOp
        , typename ForwardOp
        > 
    struct result_
    {
        typedef typename if_<
              typename is_same<First,Last>::type
            , STREAMS_BOOST_PP_CAT(AUX778076_FOLD_IMPL_NAME_PREFIX,_null_step)<Last,State>
            , STREAMS_BOOST_PP_CAT(AUX778076_FOLD_IMPL_NAME_PREFIX,_step)<First,Last,State,BackwardOp,ForwardOp>
            >::type res_;

        typedef typename res_::state state;
        typedef typename res_::iterator iterator;
    };

#if defined(STREAMS_BOOST_MPL_CFG_MSVC_60_ETI_BUG)
    /// ETI workaround
    template<> struct result_<int,int,int,int,int>
    {
        typedef int state;
        typedef int iterator;
    };
#endif
};

template<
      typename First
    , typename Last
    , typename State
    , typename BackwardOp
    , typename ForwardOp
    > 
struct STREAMS_BOOST_PP_CAT(AUX778076_FOLD_IMPL_NAME_PREFIX,_step)
{
    typedef AUX778076_FOLD_CHUNK_NAME<-1>::template result_<
          typename mpl::next<First>::type
        , Last
        , typename apply2<ForwardOp,State,AUX778076_FOLD_IMPL_OP(First)>::type
        , BackwardOp
        , ForwardOp
        > nested_step;

    typedef typename apply2<
          BackwardOp
        , typename nested_step::state
        , AUX778076_FOLD_IMPL_OP(First)
        >::type state;

    typedef typename nested_step::iterator iterator;
};

template<
      STREAMS_BOOST_MPL_AUX_NTTP_DECL(long, N)
    , typename First
    , typename Last
    , typename State
    , typename BackwardOp
    , typename ForwardOp
    > 
struct AUX778076_FOLD_IMPL_NAME
    : AUX778076_FOLD_CHUNK_NAME<N>
        ::template result_<First,Last,State,BackwardOp,ForwardOp>
{
};

#endif // STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

}}}

#   undef AUX778076_FIRST_BACKWARD_STATE_TYPEDEF
#   undef AUX778076_ITER_FOLD_BACKWARD_STEP
#   undef AUX778076_ITER_FOLD_BACKWARD_STEP_FUNC
#   undef AUX778076_ITER_FOLD_FORWARD_STEP

#undef AUX778076_FOLD_IMPL_OP
#undef AUX778076_FOLD_IMPL_NAME_PREFIX

///// iteration

#else

#   define n_ STREAMS_BOOST_PP_FRAME_ITERATION(1)

#if !defined(STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION) \
    && !defined(STREAMS_BOOST_MPL_CFG_NO_NONTYPE_TEMPLATE_PARTIAL_SPEC)

template<
      typename First
    , typename Last
    , typename State
    , typename BackwardOp
    , typename ForwardOp
    >
struct AUX778076_FOLD_IMPL_NAME<n_,First,Last,State,BackwardOp,ForwardOp>
{
    typedef First iter0;
    typedef State fwd_state0;

    STREAMS_BOOST_MPL_PP_REPEAT(
          n_
        , AUX778076_ITER_FOLD_FORWARD_STEP
        , unused
        )

    typedef STREAMS_BOOST_PP_CAT(fwd_state,n_) STREAMS_BOOST_PP_CAT(bkwd_state,n_);

    STREAMS_BOOST_MPL_PP_REPEAT(
          n_
        , AUX778076_ITER_FOLD_BACKWARD_STEP
        , n_
        )

    typedef bkwd_state0 state;
    typedef STREAMS_BOOST_PP_CAT(iter,n_) iterator;
};

#else

template<> struct AUX778076_FOLD_CHUNK_NAME<n_>
{
    template<
          typename First
        , typename Last
        , typename State
        , typename BackwardOp
        , typename ForwardOp
        >
    struct result_
    {
        typedef First iter0;
        typedef State fwd_state0;

        STREAMS_BOOST_MPL_PP_REPEAT(
              n_
            , AUX778076_ITER_FOLD_FORWARD_STEP
            , unused
            )

        typedef STREAMS_BOOST_PP_CAT(fwd_state,n_) STREAMS_BOOST_PP_CAT(bkwd_state,n_);

        STREAMS_BOOST_MPL_PP_REPEAT(
              n_
            , AUX778076_ITER_FOLD_BACKWARD_STEP
            , n_
            )

        typedef bkwd_state0 state;
        typedef STREAMS_BOOST_PP_CAT(iter,n_) iterator;
    };

#if defined(STREAMS_BOOST_MPL_CFG_MSVC_60_ETI_BUG)
    /// ETI workaround
    template<> struct result_<int,int,int,int,int>
    {
        typedef int state;
        typedef int iterator;
    };
#endif
};

#endif // STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

#   undef n_

#endif // STREAMS_BOOST_PP_IS_ITERATING
