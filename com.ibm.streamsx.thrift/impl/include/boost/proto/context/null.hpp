#ifndef STREAMS_BOOST_PP_IS_ITERATING
    ///////////////////////////////////////////////////////////////////////////////
    /// \file null.hpp
    /// Definintion of null_context\<\>, an evaluation context for
    /// proto::eval() that simply evaluates each child expression, doesn't
    /// combine the results at all, and returns void.
    //
    //  Copyright 2008 Eric Niebler. Distributed under the Boost
    //  Software License, Version 1.0. (See accompanying file
    //  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

    #ifndef STREAMS_BOOST_PROTO_CONTEXT_NULL_HPP_EAN_06_24_2007
    #define STREAMS_BOOST_PROTO_CONTEXT_NULL_HPP_EAN_06_24_2007

    #include <streams_boost/preprocessor/iteration/iterate.hpp>
    #include <streams_boost/preprocessor/repetition/repeat.hpp>
    #include <streams_boost/proto/proto_fwd.hpp>
    #include <streams_boost/proto/eval.hpp>
    #include <streams_boost/proto/traits.hpp>

    namespace streams_boost { namespace proto { namespace context
    {

        template<
            typename Expr
          , typename Context
          , long Arity          // = Expr::proto_arity_c
        >
        struct null_eval
        {};

        template<typename Expr, typename Context>
        struct null_eval<Expr, Context, 0>
        {
            typedef void result_type;
            void operator()(Expr &, Context &) const
            {}
        };

    #define STREAMS_BOOST_PROTO_EVAL_N(Z, N, DATA)                                                          \
        proto::eval(proto::child_c<N>(expr), ctx);                                                    \
        /**/

    #define STREAMS_BOOST_PP_ITERATION_PARAMS_1                                                             \
        (3, (1, STREAMS_BOOST_PROTO_MAX_ARITY, <streams_boost/proto/context/null.hpp>))                   \
        /**/

    #include STREAMS_BOOST_PP_ITERATE()

    #undef STREAMS_BOOST_PROTO_EVAL_N

        /// null_context
        ///
        struct null_context
        {
            /// null_context::eval
            ///
            template<typename Expr, typename ThisContext = null_context const>
            struct eval
              : null_eval<Expr, ThisContext>
            {};
        };

    }}}

    #endif

#else

    #define N STREAMS_BOOST_PP_ITERATION()

        template<typename Expr, typename Context>
        struct null_eval<Expr, Context, N>
        {
            typedef void result_type;

            void operator ()(Expr &expr, Context &ctx) const
            {
                STREAMS_BOOST_PP_REPEAT(N, STREAMS_BOOST_PROTO_EVAL_N, ~)
            }
        };

    #undef N

#endif
