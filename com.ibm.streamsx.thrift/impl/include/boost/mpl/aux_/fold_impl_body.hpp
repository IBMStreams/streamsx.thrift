
// NO INCLUDE GUARDS, THE HEADER IS INTENDED FOR MULTIPLE INCLUSION

#if !defined(STREAMS_BOOST_PP_IS_ITERATING)

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: fold_impl_body.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#   include <streams_boost/mpl/limits/unrolling.hpp>
#   include <streams_boost/mpl/aux_/preprocessor/repeat.hpp>
#   include <streams_boost/mpl/aux_/config/workaround.hpp>
#   include <streams_boost/mpl/aux_/config/ctps.hpp>
#   include <streams_boost/mpl/aux_/nttp_decl.hpp>
#   include <streams_boost/mpl/aux_/config/eti.hpp>

#   include <streams_boost/preprocessor/iterate.hpp>
#   include <streams_boost/preprocessor/dec.hpp>
#   include <streams_boost/preprocessor/cat.hpp>

// local macros, #undef-ined at the end of the header

#   define AUX778076_ITER_FOLD_STEP(unused, i, unused2) \
    typedef typename apply2< \
          ForwardOp \
        , STREAMS_BOOST_PP_CAT(state,i) \
        , AUX778076_FOLD_IMPL_OP(STREAMS_BOOST_PP_CAT(iter,i)) \
        >::type STREAMS_BOOST_PP_CAT(state,STREAMS_BOOST_PP_INC(i)); \
    typedef typename mpl::next<STREAMS_BOOST_PP_CAT(iter,i)>::type \
        STREAMS_BOOST_PP_CAT(iter,STREAMS_BOOST_PP_INC(i)); \
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
      STREAMS_BOOST_MPL_AUX_NTTP_DECL(int, N)
    , typename First
    , typename Last
    , typename State
    , typename ForwardOp
    > 
struct AUX778076_FOLD_IMPL_NAME;

#if !defined(STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)

#   if !STREAMS_BOOST_WORKAROUND(__BORLANDC__, < 0x600)

#   define STREAMS_BOOST_PP_ITERATION_PARAMS_1 \
    (3,(0, STREAMS_BOOST_MPL_LIMIT_UNROLLING, <streams_boost/mpl/aux_/fold_impl_body.hpp>))
#   include STREAMS_BOOST_PP_ITERATE()

// implementation for N that exceeds STREAMS_BOOST_MPL_LIMIT_UNROLLING
template<
      STREAMS_BOOST_MPL_AUX_NTTP_DECL(int, N)
    , typename First
    , typename Last
    , typename State
    , typename ForwardOp
    > 
struct AUX778076_FOLD_IMPL_NAME
{
    typedef AUX778076_FOLD_IMPL_NAME<
          STREAMS_BOOST_MPL_LIMIT_UNROLLING
        , First
        , Last
        , State
        , ForwardOp
        > chunk_;

    typedef AUX778076_FOLD_IMPL_NAME<
          ( (N - STREAMS_BOOST_MPL_LIMIT_UNROLLING) < 0 ? 0 : N - STREAMS_BOOST_MPL_LIMIT_UNROLLING )
        , typename chunk_::iterator
        , Last
        , typename chunk_::state
        , ForwardOp
        > res_;
        
    typedef typename res_::state state;
    typedef typename res_::iterator iterator;
};

// fallback implementation for sequences of unknown size
template<
      typename First
    , typename Last
    , typename State
    , typename ForwardOp
    > 
struct AUX778076_FOLD_IMPL_NAME<-1,First,Last,State,ForwardOp>
    : AUX778076_FOLD_IMPL_NAME<
          -1
        , typename mpl::next<First>::type
        , Last
        , typename apply2<ForwardOp,State,AUX778076_FOLD_IMPL_OP(First)>::type
        , ForwardOp
        >
{
};

template<
      typename Last
    , typename State
    , typename ForwardOp
    > 
struct AUX778076_FOLD_IMPL_NAME<-1,Last,Last,State,ForwardOp>
{
    typedef State state;
    typedef Last iterator;
};

#   else // STREAMS_BOOST_WORKAROUND(__BORLANDC__, < 0x600)

// Borland have some serious problems with the unrolled version, so
// we always use a basic implementation
template<
      STREAMS_BOOST_MPL_AUX_NTTP_DECL(int, N)
    , typename First
    , typename Last
    , typename State
    , typename ForwardOp
    > 
struct AUX778076_FOLD_IMPL_NAME
{
    typedef AUX778076_FOLD_IMPL_NAME<
          -1
        , typename mpl::next<First>::type
        , Last
        , typename apply2<ForwardOp,State,AUX778076_FOLD_IMPL_OP(First)>::type
        , ForwardOp
        > res_;

    typedef typename res_::state state;
    typedef typename res_::iterator iterator;
    typedef state type;
};

template<
      STREAMS_BOOST_MPL_AUX_NTTP_DECL(int, N)
     , typename Last
    , typename State
    , typename ForwardOp
    > 
struct AUX778076_FOLD_IMPL_NAME<N,Last,Last,State,ForwardOp >
{
    typedef State state;
    typedef Last iterator;
    typedef state type;
};

#   endif // STREAMS_BOOST_WORKAROUND(__BORLANDC__, < 0x600)
 
#else // STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

template< STREAMS_BOOST_MPL_AUX_NTTP_DECL(int, N) >
struct AUX778076_FOLD_CHUNK_NAME;

#   define STREAMS_BOOST_PP_ITERATION_PARAMS_1 \
    (3,(0, STREAMS_BOOST_MPL_LIMIT_UNROLLING, <streams_boost/mpl/aux_/fold_impl_body.hpp>))
#   include STREAMS_BOOST_PP_ITERATE()

// implementation for N that exceeds STREAMS_BOOST_MPL_LIMIT_UNROLLING
template< STREAMS_BOOST_MPL_AUX_NTTP_DECL(int, N) > 
struct AUX778076_FOLD_CHUNK_NAME
{
    template<
          typename First
        , typename Last
        , typename State
        , typename ForwardOp
        > 
    struct result_
    {
        typedef AUX778076_FOLD_IMPL_NAME<
              STREAMS_BOOST_MPL_LIMIT_UNROLLING
            , First
            , Last
            , State
            , ForwardOp
            > chunk_;

        typedef AUX778076_FOLD_IMPL_NAME<
              ( (N - STREAMS_BOOST_MPL_LIMIT_UNROLLING) < 0 ? 0 : N - STREAMS_BOOST_MPL_LIMIT_UNROLLING )
            , typename chunk_::iterator
            , Last
            , typename chunk_::state
            , ForwardOp
            > res_;

        typedef typename res_::state state;
        typedef typename res_::iterator iterator;
    };
};

// fallback implementation for sequences of unknown size
template<
      typename First
    , typename Last
    , typename State
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
        , typename ForwardOp
        > 
    struct result_
    {
        typedef typename if_<
              typename is_same<First,Last>::type
            , STREAMS_BOOST_PP_CAT(AUX778076_FOLD_IMPL_NAME_PREFIX,_null_step)<Last,State>
            , STREAMS_BOOST_PP_CAT(AUX778076_FOLD_IMPL_NAME_PREFIX,_step)<First,Last,State,ForwardOp>
            >::type res_;

        typedef typename res_::state state;
        typedef typename res_::iterator iterator;
    };

#if defined(STREAMS_BOOST_MPL_CFG_MSVC_60_ETI_BUG)
    /// ETI workaround
    template<> struct result_<int,int,int,int>
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
    , typename ForwardOp
    > 
struct STREAMS_BOOST_PP_CAT(AUX778076_FOLD_IMPL_NAME_PREFIX,_step)
{
    // can't inherit here - it breaks MSVC 7.0
    typedef AUX778076_FOLD_CHUNK_NAME<-1>::template result_<
          typename mpl::next<First>::type
        , Last
        , typename apply2<ForwardOp,State,AUX778076_FOLD_IMPL_OP(First)>::type
        , ForwardOp
        > chunk_;

    typedef typename chunk_::state state;
    typedef typename chunk_::iterator iterator;
};

template<
      STREAMS_BOOST_MPL_AUX_NTTP_DECL(int, N)
    , typename First
    , typename Last
    , typename State
    , typename ForwardOp
    > 
struct AUX778076_FOLD_IMPL_NAME
    : AUX778076_FOLD_CHUNK_NAME<N>
        ::template result_<First,Last,State,ForwardOp>
{
};

#endif // STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

}}}

#   undef AUX778076_FOLD_IMPL_NAME
#   undef AUX778076_FOLD_CHUNK_NAME
#   undef AUX778076_ITER_FOLD_STEP

#undef AUX778076_FOLD_IMPL_OP
#undef AUX778076_FOLD_IMPL_NAME_PREFIX

///// iteration

#else

#   define n_ STREAMS_BOOST_PP_FRAME_ITERATION(1)

#if !defined(STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)

template<
      typename First
    , typename Last
    , typename State
    , typename ForwardOp
    >
struct AUX778076_FOLD_IMPL_NAME<n_,First,Last,State,ForwardOp>
{
    typedef First iter0;
    typedef State state0;

    STREAMS_BOOST_MPL_PP_REPEAT(n_, AUX778076_ITER_FOLD_STEP, unused)

    typedef STREAMS_BOOST_PP_CAT(state,n_) state;
    typedef STREAMS_BOOST_PP_CAT(iter,n_) iterator;
};

#else

template<> struct AUX778076_FOLD_CHUNK_NAME<n_>
{
    template<
          typename First
        , typename Last
        , typename State
        , typename ForwardOp
        >
    struct result_
    {
        typedef First iter0;
        typedef State state0;

        STREAMS_BOOST_MPL_PP_REPEAT(n_, AUX778076_ITER_FOLD_STEP, unused)

        typedef STREAMS_BOOST_PP_CAT(state,n_) state;
        typedef STREAMS_BOOST_PP_CAT(iter,n_) iterator;
    };

#if defined(STREAMS_BOOST_MPL_CFG_MSVC_60_ETI_BUG)
    /// ETI workaround
    template<> struct result_<int,int,int,int>
    {
        typedef int state;
        typedef int iterator;
    };
#endif
};

#endif // STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

#   undef n_

#endif // STREAMS_BOOST_PP_IS_ITERATING
