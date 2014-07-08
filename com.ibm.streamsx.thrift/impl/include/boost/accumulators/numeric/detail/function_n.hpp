// Copyright David Abrahams 2006. Distributed under the Boost
// Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//
// #include guards intentionally disabled.
// #ifndef STREAMS_BOOST_DETAIL_FUNCTION_N_DWA2006514_STREAMS_HPP
// # define STREAMS_BOOST_DETAIL_FUNCTION_N_DWA2006514_STREAMS_HPP

#include <streams_boost/mpl/void.hpp>
#include <streams_boost/mpl/apply.hpp>

#include <streams_boost/preprocessor/control/if.hpp>
#include <streams_boost/preprocessor/cat.hpp>
#include <streams_boost/preprocessor/punctuation/comma_if.hpp>
#include <streams_boost/preprocessor/repetition/enum_params.hpp>
#include <streams_boost/preprocessor/repetition/enum_trailing_params.hpp>
#include <streams_boost/preprocessor/repetition/repeat.hpp>
#include <streams_boost/preprocessor/seq/fold_left.hpp>
#include <streams_boost/preprocessor/seq/seq.hpp>
#include <streams_boost/preprocessor/seq/for_each.hpp>
#include <streams_boost/preprocessor/seq/for_each_i.hpp>
#include <streams_boost/preprocessor/seq/for_each_product.hpp>
#include <streams_boost/preprocessor/seq/size.hpp>
#include <streams_boost/type_traits/add_const.hpp>
#include <streams_boost/type_traits/remove_reference.hpp>

namespace streams_boost { namespace detail {

# define STREAMS_BOOST_DETAIL_default_arg(z, n, _)                                      \
    typedef mpl::void_ STREAMS_BOOST_PP_CAT(arg, n);

# define STREAMS_BOOST_DETAIL_function_arg(z, n, _)                                     \
    typedef typename remove_reference<                                          \
        typename add_const< STREAMS_BOOST_PP_CAT(A, n) >::type                          \
    >::type STREAMS_BOOST_PP_CAT(arg, n);

#define STREAMS_BOOST_DETAIL_cat_arg_counts(s, state, n)                                \
    STREAMS_BOOST_PP_IF(                                                                \
        n                                                                       \
      , STREAMS_BOOST_PP_CAT(state, STREAMS_BOOST_PP_CAT(_, n))                                 \
      , state                                                                   \
    )                                                                           \
    /**/

#define function_name                                                           \
    STREAMS_BOOST_PP_SEQ_FOLD_LEFT(                                                     \
        STREAMS_BOOST_DETAIL_cat_arg_counts                                             \
      , STREAMS_BOOST_PP_CAT(function, STREAMS_BOOST_PP_SEQ_HEAD(args))                         \
      , STREAMS_BOOST_PP_SEQ_TAIL(args)(0)                                              \
    )                                                                           \
    /**/

template<typename F>
struct function_name
{
    STREAMS_BOOST_PP_REPEAT(
        STREAMS_BOOST_MPL_LIMIT_METAFUNCTION_ARITY
      , STREAMS_BOOST_DETAIL_default_arg
      , ~
    )

    template<typename Signature>
    struct result {};

#define STREAMS_BOOST_DETAIL_function_result(r, _, n)                                   \
    template<typename This STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(n, typename A)>        \
    struct result<This(STREAMS_BOOST_PP_ENUM_PARAMS(n, A))>                             \
    {                                                                           \
        STREAMS_BOOST_PP_REPEAT(n, STREAMS_BOOST_DETAIL_function_arg, ~)                        \
        typedef                                                                 \
            typename STREAMS_BOOST_PP_CAT(mpl::apply, STREAMS_BOOST_MPL_LIMIT_METAFUNCTION_ARITY)<\
                F                                                               \
                STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(                                  \
                    STREAMS_BOOST_MPL_LIMIT_METAFUNCTION_ARITY                          \
                  , arg                                                         \
                )                                                               \
            >::type                                                             \
        impl;                                                                   \
        typedef typename impl::result_type type;                                \
    };                                                                          \
    /**/

    STREAMS_BOOST_PP_SEQ_FOR_EACH(STREAMS_BOOST_DETAIL_function_result, _, args)

# define arg_type(r, _, i, is_const)                                            \
    STREAMS_BOOST_PP_COMMA_IF(i) STREAMS_BOOST_PP_CAT(A, i) STREAMS_BOOST_PP_CAT(const_if, is_const) &

# define result_(r, n, constness)                                               \
    typename result<                                                            \
        function_name(                                                          \
            STREAMS_BOOST_PP_SEQ_FOR_EACH_I_R(r, arg_type, ~, constness)                \
        )                                                                       \
    >                                                                           \
    /**/

# define param(r, _, i, is_const) STREAMS_BOOST_PP_COMMA_IF(i)                          \
    STREAMS_BOOST_PP_CAT(A, i) STREAMS_BOOST_PP_CAT(const_if, is_const) & STREAMS_BOOST_PP_CAT(x, i)

# define param_list(r, n, constness)                                            \
    STREAMS_BOOST_PP_SEQ_FOR_EACH_I_R(r, param, ~, constness)

# define call_operator(r, constness)                                            \
    template<STREAMS_BOOST_PP_ENUM_PARAMS(STREAMS_BOOST_PP_SEQ_SIZE(constness), typename A)>    \
        result_(r, STREAMS_BOOST_PP_SEQ_SIZE(constness), constness)::type               \
    operator ()( param_list(r, STREAMS_BOOST_PP_SEQ_SIZE(constness), constness) ) const \
    {                                                                           \
        typedef result_(r, STREAMS_BOOST_PP_SEQ_SIZE(constness), constness)::impl impl; \
        return impl()(STREAMS_BOOST_PP_ENUM_PARAMS(STREAMS_BOOST_PP_SEQ_SIZE(constness), x));   \
    }                                                                           \
    /**/

# define const_if0
# define const_if1 const

# define bits(z, n, _) ((0)(1))

# define gen_operator(r, _, n)                                                  \
    STREAMS_BOOST_PP_SEQ_FOR_EACH_PRODUCT_R(                                            \
        r                                                                       \
      , call_operator                                                           \
      , STREAMS_BOOST_PP_REPEAT(n, bits, ~)                                             \
    )                                                                           \
    /**/

    STREAMS_BOOST_PP_SEQ_FOR_EACH(
        gen_operator
      , ~
      , args
    )

# undef bits
# undef const_if1
# undef const_if0
# undef call_operator
# undef param_list
# undef param
# undef result_
# undef default_
# undef arg_type
# undef gen_operator
# undef function_name

# undef args
};

}} // namespace streams_boost::detail

//#endif // STREAMS_BOOST_DETAIL_FUNCTION_N_DWA2006514_STREAMS_HPP
