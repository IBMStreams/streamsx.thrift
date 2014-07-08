// Copyright Daniel Wallin 2005. Use, modification and distribution is
// subject to the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_PARAMETER_FOR_EACH_051217_HPP
# define STREAMS_BOOST_PARAMETER_FOR_EACH_051217_HPP

# include <streams_boost/preprocessor/cat.hpp>
# include <streams_boost/preprocessor/detail/split.hpp>
# include <streams_boost/preprocessor/logical/not.hpp>
# include <streams_boost/preprocessor/facilities/is_empty.hpp>
# include <streams_boost/preprocessor/tuple/eat.hpp>
# include <streams_boost/preprocessor/arithmetic/inc.hpp>
# include <streams_boost/preprocessor/repeat.hpp>
# include <streams_boost/preprocessor/punctuation/comma_if.hpp>
# include <streams_boost/preprocessor/for.hpp>
# include <streams_boost/preprocessor/repetition/deduce_r.hpp>

# define STREAMS_BOOST_PARAMETER_FOR_EACH_head_aux2(x,y) (x,y), ~
# define STREAMS_BOOST_PARAMETER_FOR_EACH_head_aux3(x,y,z) (x,y,z), ~
# define STREAMS_BOOST_PARAMETER_FOR_EACH_head_aux4(x,y,z,u) (x,y,z,u), ~
# define STREAMS_BOOST_PARAMETER_FOR_EACH_head(n,x) \
    STREAMS_BOOST_PP_SPLIT(0, STREAMS_BOOST_PP_CAT(STREAMS_BOOST_PARAMETER_FOR_EACH_head_aux,n) x)

# define STREAMS_BOOST_PARAMETER_FOR_EACH_pred_aux_STREAMS_BOOST_PARAMETER_FOR_EACH_END_SENTINEL
# define STREAMS_BOOST_PARAMETER_FOR_EACH_pred_aux_check(x) \
    STREAMS_BOOST_PP_NOT(STREAMS_BOOST_PP_IS_EMPTY( \
        STREAMS_BOOST_PP_CAT(STREAMS_BOOST_PARAMETER_FOR_EACH_pred_aux_, x) \
    )), ~

# define STREAMS_BOOST_PARAMETER_FOR_EACH_pred_aux2(x,y) \
    STREAMS_BOOST_PARAMETER_FOR_EACH_pred_aux_check(x)
# define STREAMS_BOOST_PARAMETER_FOR_EACH_pred_aux3(x,y,z) \
    STREAMS_BOOST_PARAMETER_FOR_EACH_pred_aux_check(x)
# define STREAMS_BOOST_PARAMETER_FOR_EACH_pred_aux4(x,y,z,u) \
    STREAMS_BOOST_PARAMETER_FOR_EACH_pred_aux_check(x)

# define STREAMS_BOOST_PARAMETER_FOR_EACH_pred_aux0(n,x) \
    STREAMS_BOOST_PP_CAT(STREAMS_BOOST_PARAMETER_FOR_EACH_pred_aux,n) x

# if STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_MSVC()
#  define STREAMS_BOOST_PARAMETER_FOR_EACH_pred_SPLIT_FIRST(x) \
    STREAMS_BOOST_PP_SPLIT(0, x)

#  define STREAMS_BOOST_PARAMETER_FOR_EACH_pred(r, state) \
    STREAMS_BOOST_PARAMETER_FOR_EACH_pred_SPLIT_FIRST( \
        STREAMS_BOOST_PARAMETER_FOR_EACH_pred_aux0( \
            STREAMS_BOOST_PP_TUPLE_ELEM(5,3,state) \
          , STREAMS_BOOST_PP_TUPLE_ELEM(5,0,state) \
        ) \
    )
# else
#  define STREAMS_BOOST_PARAMETER_FOR_EACH_pred(r, state) \
    STREAMS_BOOST_PP_SPLIT( \
        0 \
      , STREAMS_BOOST_PARAMETER_FOR_EACH_pred_aux0( \
            STREAMS_BOOST_PP_TUPLE_ELEM(5,3,state) \
          , STREAMS_BOOST_PP_TUPLE_ELEM(5,0,state) \
        ) \
    )
# endif

# define STREAMS_BOOST_PARAMETER_FOR_EACH_op(r, state) \
    ( \
        STREAMS_BOOST_PP_TUPLE_EAT(STREAMS_BOOST_PP_TUPLE_ELEM(5,3,state)) \
          STREAMS_BOOST_PP_TUPLE_ELEM(5,0,state) \
      , STREAMS_BOOST_PP_TUPLE_ELEM(5,1,state) \
      , STREAMS_BOOST_PP_TUPLE_ELEM(5,2,state) \
      , STREAMS_BOOST_PP_TUPLE_ELEM(5,3,state) \
      , STREAMS_BOOST_PP_INC(STREAMS_BOOST_PP_TUPLE_ELEM(5,4,state)) \
    )

# define STREAMS_BOOST_PARAMETER_FOR_EACH_macro(r, state) \
    STREAMS_BOOST_PP_TUPLE_ELEM(5,2,state)( \
        r \
      , STREAMS_BOOST_PP_TUPLE_ELEM(5,4,state) \
      , STREAMS_BOOST_PARAMETER_FOR_EACH_head( \
            STREAMS_BOOST_PP_TUPLE_ELEM(5,3,state) \
          , STREAMS_BOOST_PP_TUPLE_ELEM(5,0,state) \
        ) \
      , STREAMS_BOOST_PP_TUPLE_ELEM(5,1,state) \
    )

# define STREAMS_BOOST_PARAMETER_FOR_EACH_build_end_sentinel(z,n,text) \
    STREAMS_BOOST_PP_COMMA_IF(n) STREAMS_BOOST_PARAMETER_FOR_EACH_END_SENTINEL
# define STREAMS_BOOST_PARAMETER_FOR_EACH_build_end_sentinel_tuple(arity) \
    ( \
        STREAMS_BOOST_PP_REPEAT(arity, STREAMS_BOOST_PARAMETER_FOR_EACH_build_end_sentinel, _) \
    )

# define STREAMS_BOOST_PARAMETER_FOR_EACH_R(r, arity, list, data, macro) \
    STREAMS_BOOST_PP_CAT(STREAMS_BOOST_PP_FOR_, r)( \
        (list STREAMS_BOOST_PARAMETER_FOR_EACH_build_end_sentinel_tuple(arity), data, macro, arity, 0) \
      , STREAMS_BOOST_PARAMETER_FOR_EACH_pred \
      , STREAMS_BOOST_PARAMETER_FOR_EACH_op \
      , STREAMS_BOOST_PARAMETER_FOR_EACH_macro \
    )

# define STREAMS_BOOST_PARAMETER_FOR_EACH(arity, list, data, macro) \
    STREAMS_BOOST_PARAMETER_FOR_EACH_R(STREAMS_BOOST_PP_DEDUCE_R(), arity, list, data, macro)

#endif // STREAMS_BOOST_PARAMETER_FOR_EACH_051217_HPP

