///////////////////////////////////////////////////////////////////////////////
/// \file deprecated.hpp
/// Definition of the deprecated STREAMS_BOOST_PROTO_DEFINE_FUCTION_TEMPLATE and
/// STREAMS_BOOST_PROTO_DEFINE_VARARG_FUCTION_TEMPLATE macros
//
//  Copyright 2008 Eric Niebler. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_PROTO_DETAIL_DEPRECATED_HPP_EAN_11_25_2008
#define STREAMS_BOOST_PROTO_DETAIL_DEPRECATED_HPP_EAN_11_25_2008

#include <streams_boost/preprocessor/cat.hpp>
#include <streams_boost/preprocessor/facilities/intercept.hpp>
#include <streams_boost/preprocessor/arithmetic/inc.hpp>
#include <streams_boost/preprocessor/arithmetic/dec.hpp>
#include <streams_boost/preprocessor/arithmetic/sub.hpp>
#include <streams_boost/preprocessor/punctuation/comma_if.hpp>
#include <streams_boost/preprocessor/control/if.hpp>
#include <streams_boost/preprocessor/control/expr_if.hpp>
#include <streams_boost/preprocessor/comparison/greater.hpp>
#include <streams_boost/preprocessor/tuple/elem.hpp>
#include <streams_boost/preprocessor/tuple/to_list.hpp>
#include <streams_boost/preprocessor/logical/and.hpp>
#include <streams_boost/preprocessor/seq/size.hpp>
#include <streams_boost/preprocessor/seq/enum.hpp>
#include <streams_boost/preprocessor/seq/seq.hpp>
#include <streams_boost/preprocessor/seq/to_tuple.hpp>
#include <streams_boost/preprocessor/seq/for_each_i.hpp>
#include <streams_boost/preprocessor/seq/pop_back.hpp>
#include <streams_boost/preprocessor/seq/push_back.hpp>
#include <streams_boost/preprocessor/seq/push_front.hpp>
#include <streams_boost/preprocessor/list/for_each_i.hpp>
#include <streams_boost/preprocessor/repetition/repeat.hpp>
#include <streams_boost/preprocessor/repetition/repeat_from_to.hpp>
#include <streams_boost/preprocessor/repetition/enum_binary_params.hpp>
#include <streams_boost/preprocessor/repetition/enum_trailing_binary_params.hpp>
#include <streams_boost/proto/proto_fwd.hpp>

/// INTERNAL ONLY
///
#define STREAMS_BOOST_PROTO_VARARG_TEMPLATE_AUX_(R, DATA, I, ELEM)                                      \
    (ELEM STREAMS_BOOST_PP_CAT(STREAMS_BOOST_PP_CAT(X, DATA), STREAMS_BOOST_PP_CAT(_, I)))                              \
    /**/

/// INTERNAL ONLY
///
#define STREAMS_BOOST_PROTO_VARARG_TEMPLATE_YES_(R, DATA, I, ELEM)                                      \
    STREAMS_BOOST_PP_LIST_FOR_EACH_I_R(                                                                 \
        R                                                                                       \
      , STREAMS_BOOST_PROTO_VARARG_TEMPLATE_AUX_                                                        \
      , I                                                                                       \
      , STREAMS_BOOST_PP_TUPLE_TO_LIST(                                                                 \
            STREAMS_BOOST_PP_DEC(STREAMS_BOOST_PP_SEQ_SIZE(ELEM))                                               \
          , STREAMS_BOOST_PP_SEQ_TO_TUPLE(STREAMS_BOOST_PP_SEQ_TAIL(ELEM))                                      \
        )                                                                                       \
    )                                                                                           \
    /**/

/// INTERNAL ONLY
///
#define STREAMS_BOOST_PROTO_VARARG_TEMPLATE_NO_(R, DATA, I, ELEM)                                       \
    /**/

/// INTERNAL ONLY
///
#define STREAMS_BOOST_PROTO_VARARG_TEMPLATE_(R, DATA, I, ELEM)                                          \
    STREAMS_BOOST_PP_IF(                                                                                \
        STREAMS_BOOST_PP_DEC(STREAMS_BOOST_PP_SEQ_SIZE(ELEM))                                                   \
      , STREAMS_BOOST_PROTO_VARARG_TEMPLATE_YES_                                                        \
      , STREAMS_BOOST_PROTO_VARARG_TEMPLATE_NO_                                                         \
    )(R, DATA, I, ELEM)                                                                         \
    /**/

/// INTERNAL ONLY
///
#define STREAMS_BOOST_PROTO_VARARG_TYPE_AUX_(R, DATA, I, ELEM)                                          \
    (STREAMS_BOOST_PP_CAT(STREAMS_BOOST_PP_CAT(X, DATA), STREAMS_BOOST_PP_CAT(_, I)))                                   \
    /**/

/// INTERNAL ONLY
///
#define STREAMS_BOOST_PROTO_TEMPLATE_PARAMS_YES_(R, DATA, I, ELEM)                                      \
    <                                                                                           \
        STREAMS_BOOST_PP_SEQ_ENUM(                                                                      \
            STREAMS_BOOST_PP_LIST_FOR_EACH_I_R(                                                         \
                R                                                                               \
              , STREAMS_BOOST_PROTO_VARARG_TYPE_AUX_                                                    \
              , I                                                                               \
              , STREAMS_BOOST_PP_TUPLE_TO_LIST(                                                         \
                    STREAMS_BOOST_PP_DEC(STREAMS_BOOST_PP_SEQ_SIZE(ELEM))                                       \
                  , STREAMS_BOOST_PP_SEQ_TO_TUPLE(STREAMS_BOOST_PP_SEQ_TAIL(ELEM))                              \
                )                                                                               \
            )                                                                                   \
        )                                                                                       \
    >                                                                                           \
    /**/

/// INTERNAL ONLY
///
#define STREAMS_BOOST_PROTO_TEMPLATE_PARAMS_NO_(R, DATA, I, ELEM)                                       \
    /**/

/// INTERNAL ONLY
///
#define STREAMS_BOOST_PROTO_VARARG_TYPE_(R, DATA, I, ELEM)                                              \
    STREAMS_BOOST_PP_COMMA_IF(I)                                                                        \
    STREAMS_BOOST_PP_SEQ_HEAD(ELEM)                                                                     \
    STREAMS_BOOST_PP_IF(                                                                                \
        STREAMS_BOOST_PP_DEC(STREAMS_BOOST_PP_SEQ_SIZE(ELEM))                                                   \
      , STREAMS_BOOST_PROTO_TEMPLATE_PARAMS_YES_                                                        \
      , STREAMS_BOOST_PROTO_TEMPLATE_PARAMS_NO_                                                         \
    )(R, DATA, I, ELEM) STREAMS_BOOST_PP_EXPR_IF(STREAMS_BOOST_PP_GREATER(I, 1), const)                         \
    /**/

/// INTERNAL ONLY
///
#define STREAMS_BOOST_PROTO_VARARG_AS_EXPR_(R, DATA, I, ELEM)                                           \
    STREAMS_BOOST_PP_EXPR_IF(                                                                           \
        STREAMS_BOOST_PP_GREATER(I, 1)                                                                  \
      , ((                                                                                      \
            STREAMS_BOOST_PP_SEQ_HEAD(ELEM)                                                             \
            STREAMS_BOOST_PP_IF(                                                                        \
                STREAMS_BOOST_PP_DEC(STREAMS_BOOST_PP_SEQ_SIZE(ELEM))                                           \
              , STREAMS_BOOST_PROTO_TEMPLATE_PARAMS_YES_                                                \
              , STREAMS_BOOST_PROTO_TEMPLATE_PARAMS_NO_                                                 \
            )(R, DATA, I, ELEM)()                                                               \
        ))                                                                                      \
    )                                                                                           \
    /**/

/// INTERNAL ONLY
///
#define STREAMS_BOOST_PROTO_VARARG_AS_CHILD_(Z, N, DATA)                                                \
    (STREAMS_BOOST_PP_CAT(DATA, N))                                                                     \
    /**/

/// INTERNAL ONLY
///
#define STREAMS_BOOST_PROTO_SEQ_PUSH_FRONT(SEQ, ELEM)                                                   \
    STREAMS_BOOST_PP_SEQ_POP_BACK(STREAMS_BOOST_PP_SEQ_PUSH_FRONT(STREAMS_BOOST_PP_SEQ_PUSH_BACK(SEQ, _dummy_), ELEM))  \
    /**/

/// INTERNAL ONLY
///
#define STREAMS_BOOST_PROTO_VARARG_AS_PARAM_(Z, N, DATA)                                                \
    (STREAMS_BOOST_PP_CAT(DATA, N))                                                                     \
    /**/

/// INTERNAL ONLY
///
#define STREAMS_BOOST_PROTO_VARARG_FUN_(Z, N, DATA)                                                     \
    template<                                                                                   \
        STREAMS_BOOST_PP_SEQ_ENUM(                                                                      \
            STREAMS_BOOST_PP_SEQ_FOR_EACH_I(                                                            \
                STREAMS_BOOST_PROTO_VARARG_TEMPLATE_, ~                                                 \
              , STREAMS_BOOST_PP_SEQ_PUSH_FRONT(                                                        \
                    STREAMS_BOOST_PROTO_SEQ_PUSH_FRONT(                                                 \
                        STREAMS_BOOST_PP_TUPLE_ELEM(4, 2, DATA)                                         \
                      , (STREAMS_BOOST_PP_TUPLE_ELEM(4, 3, DATA))                                       \
                    )                                                                           \
                  , STREAMS_BOOST_PP_TUPLE_ELEM(4, 1, DATA)                                             \
                )                                                                               \
            )                                                                                   \
            STREAMS_BOOST_PP_REPEAT_ ## Z(N, STREAMS_BOOST_PROTO_VARARG_AS_PARAM_, typename A)                  \
        )                                                                                       \
    >                                                                                           \
    typename streams_boost::proto::result_of::make_expr<                                                \
        STREAMS_BOOST_PP_SEQ_FOR_EACH_I(                                                                \
            STREAMS_BOOST_PROTO_VARARG_TYPE_, ~                                                         \
          , STREAMS_BOOST_PP_SEQ_PUSH_FRONT(                                                            \
                STREAMS_BOOST_PROTO_SEQ_PUSH_FRONT(                                                     \
                    STREAMS_BOOST_PP_TUPLE_ELEM(4, 2, DATA)                                             \
                  , (STREAMS_BOOST_PP_TUPLE_ELEM(4, 3, DATA))                                           \
                )                                                                               \
              , STREAMS_BOOST_PP_TUPLE_ELEM(4, 1, DATA)                                                 \
            )                                                                                   \
        )                                                                                       \
        STREAMS_BOOST_PP_ENUM_TRAILING_BINARY_PARAMS_Z(Z, N, A, const & STREAMS_BOOST_PP_INTERCEPT)             \
    >::type const                                                                               \
    STREAMS_BOOST_PP_TUPLE_ELEM(4, 0, DATA)(STREAMS_BOOST_PP_ENUM_BINARY_PARAMS_Z(Z, N, A, const &a))           \
    {                                                                                           \
        return streams_boost::proto::detail::make_expr_<                                                \
            STREAMS_BOOST_PP_SEQ_FOR_EACH_I(                                                            \
                STREAMS_BOOST_PROTO_VARARG_TYPE_, ~                                                     \
              , STREAMS_BOOST_PP_SEQ_PUSH_FRONT(                                                        \
                    STREAMS_BOOST_PROTO_SEQ_PUSH_FRONT(                                                 \
                        STREAMS_BOOST_PP_TUPLE_ELEM(4, 2, DATA)                                         \
                      , (STREAMS_BOOST_PP_TUPLE_ELEM(4, 3, DATA))                                       \
                    )                                                                           \
                  , STREAMS_BOOST_PP_TUPLE_ELEM(4, 1, DATA)                                             \
                )                                                                               \
            )                                                                                   \
            STREAMS_BOOST_PP_ENUM_TRAILING_BINARY_PARAMS_Z(Z, N, A, const & STREAMS_BOOST_PP_INTERCEPT)         \
        >()(                                                                                    \
            STREAMS_BOOST_PP_SEQ_ENUM(                                                                  \
                STREAMS_BOOST_PP_SEQ_FOR_EACH_I(                                                        \
                    STREAMS_BOOST_PROTO_VARARG_AS_EXPR_, ~                                              \
                  , STREAMS_BOOST_PP_SEQ_PUSH_FRONT(                                                    \
                        STREAMS_BOOST_PROTO_SEQ_PUSH_FRONT(                                             \
                            STREAMS_BOOST_PP_TUPLE_ELEM(4, 2, DATA)                                     \
                          , (STREAMS_BOOST_PP_TUPLE_ELEM(4, 3, DATA))                                   \
                        )                                                                       \
                      , STREAMS_BOOST_PP_TUPLE_ELEM(4, 1, DATA)                                         \
                    )                                                                           \
                )                                                                               \
                STREAMS_BOOST_PP_REPEAT_ ## Z(N, STREAMS_BOOST_PROTO_VARARG_AS_CHILD_, a)                       \
            )                                                                                   \
        );                                                                                      \
    }                                                                                           \
    /**/

/// \code
/// STREAMS_BOOST_PROTO_DEFINE_FUNCTION_TEMPLATE(
///     1
///   , construct
///   , streams_boost::proto::default_domain
///   , (streams_boost::proto::tag::function)
///   , ((op::construct)(typename)(int))
/// )
/// \endcode
#define STREAMS_BOOST_PROTO_DEFINE_FUNCTION_TEMPLATE(ARGCOUNT, NAME, DOMAIN, TAG, BOUNDARGS)            \
    STREAMS_BOOST_PP_REPEAT_FROM_TO(                                                                    \
        ARGCOUNT                                                                                \
      , STREAMS_BOOST_PP_INC(ARGCOUNT)                                                                  \
      , STREAMS_BOOST_PROTO_VARARG_FUN_                                                                 \
      , (NAME, TAG, BOUNDARGS, DOMAIN)                                                          \
    )\
    /**/

/// \code
/// STREAMS_BOOST_PROTO_DEFINE_VARARG_FUNCTION_TEMPLATE(
///     construct
///   , streams_boost::proto::default_domain
///   , (streams_boost::proto::tag::function)
///   , ((op::construct)(typename)(int))
/// )
/// \endcode
#define STREAMS_BOOST_PROTO_DEFINE_VARARG_FUNCTION_TEMPLATE(NAME, DOMAIN, TAG, BOUNDARGS)               \
    STREAMS_BOOST_PP_REPEAT(                                                                            \
        STREAMS_BOOST_PP_SUB(STREAMS_BOOST_PP_INC(STREAMS_BOOST_PROTO_MAX_ARITY), STREAMS_BOOST_PP_SEQ_SIZE(BOUNDARGS))         \
      , STREAMS_BOOST_PROTO_VARARG_FUN_                                                                 \
      , (NAME, TAG, BOUNDARGS, DOMAIN)                                                          \
    )                                                                                           \
    /**/

#endif
