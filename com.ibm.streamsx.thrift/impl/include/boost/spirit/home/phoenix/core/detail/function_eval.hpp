/*=============================================================================
    Copyright (c) 2001-2007 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(STREAMS_BOOST_PP_IS_ITERATING)
#if !defined(PHOENIX_CORE_DETAIL_FUNCTION_EVAL_HPP)
#define PHOENIX_CORE_DETAIL_FUNCTION_EVAL_HPP

#include <streams_boost/preprocessor/iterate.hpp>
#include <streams_boost/preprocessor/enum.hpp>
#include <streams_boost/preprocessor/repeat.hpp>
#include <streams_boost/preprocessor/dec.hpp>
#include <streams_boost/mpl/eval_if.hpp>
#include <streams_boost/mpl/find.hpp>
#include <streams_boost/mpl/identity.hpp>
#include <streams_boost/type_traits/is_same.hpp>
#include <streams_boost/type_traits/remove_reference.hpp>

// we assume that mpl::vectorN, where N = PHOENIX_COMPOSITE_LIMIT
// is included already.

namespace streams_boost { namespace phoenix { namespace detail
{
    template <int N>
    struct function_eval;

    template <>
    struct function_eval<0>
    {
        template <typename Env, typename F>
        struct result
        {
            typedef typename
                remove_reference<
                    typename F::template result<Env>::type 
                >::type
            fn;
            typedef typename fn::result_type type;
        };

        template <typename RT, typename Env, typename F>
        static RT
        eval(Env const& env, F const& f)
        {
            return f.eval(env)();
        }
    };

    template <typename T>
    T& help_rvalue_deduction(T& x)
    {
        return x;
    }

    template <typename T>
    T const& help_rvalue_deduction(T const& x)
    {
        return x;
    }

// When we call f(_0, _1...) we remove the reference when deducing f's
// return type. $$$ Explain why $$$

#define PHOENIX_GET_ARG(z, n, data)                                             \
    typedef typename                                                            \
        remove_reference<                                                       \
            typename STREAMS_BOOST_PP_CAT(A, n)::template result<Env>::type             \
        >::type                                                                 \
    STREAMS_BOOST_PP_CAT(a, n);

#define PHOENIX_EVAL_ARG(z, n, data)                                            \
    help_rvalue_deduction(STREAMS_BOOST_PP_CAT(_, n).eval(env))

#define STREAMS_BOOST_PP_ITERATION_PARAMS_1                                             \
    (3, (1, STREAMS_BOOST_PP_DEC(PHOENIX_COMPOSITE_LIMIT),                              \
    "streams_boost/spirit/home/phoenix/core/detail/function_eval.hpp"))
#include STREAMS_BOOST_PP_ITERATE()

}}} // namespace streams_boost::phoenix::detail

#undef PHOENIX_GET_ARG
#undef PHOENIX_EVAL_ARG
#endif

///////////////////////////////////////////////////////////////////////////////
//
//  Preprocessor vertical repetition code
//
///////////////////////////////////////////////////////////////////////////////
#else // defined(STREAMS_BOOST_PP_IS_ITERATING)

#define N STREAMS_BOOST_PP_ITERATION()

    template <>
    struct function_eval<N>
    {
        template <typename Env, typename F
          , STREAMS_BOOST_PP_ENUM_PARAMS(N, typename A)>
        struct result
        {
            typedef typename
                remove_reference<
                    typename F::template result<Env>::type 
                >::type
            fn;
            STREAMS_BOOST_PP_REPEAT(N, PHOENIX_GET_ARG, _)

            typedef STREAMS_BOOST_PP_CAT(mpl::vector, N)
                <STREAMS_BOOST_PP_ENUM_PARAMS(N, a)>
            args;

            typedef typename
                fn::template result<STREAMS_BOOST_PP_ENUM_PARAMS(N, a)>
            function_apply;

            typedef typename
                mpl::eval_if<
                    is_same<
                        typename mpl::find<args, fusion::void_>::type
                      , typename mpl::end<args>::type>
                  , function_apply
                  , mpl::identity<fusion::void_>
                >::type
            type;
        };

        template <typename RT, typename Env, typename F
          , STREAMS_BOOST_PP_ENUM_PARAMS(N, typename A)>
        static RT
        eval(Env const& env, F const& f
          , STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N, A, & _))
        {
            return f.eval(env)(STREAMS_BOOST_PP_ENUM(N, PHOENIX_EVAL_ARG, _));
        }
    };

#undef N
#endif // defined(STREAMS_BOOST_PP_IS_ITERATING)


