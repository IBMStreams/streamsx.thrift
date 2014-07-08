# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Paul Mensonides 2002.
#  *     Distributed under the Boost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.streams_boost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.streams_boost.org for most recent version. */
#
# ifndef STREAMS_BOOST_PREPROCESSOR_SEQ_TRANSFORM_HPP
# define STREAMS_BOOST_PREPROCESSOR_SEQ_TRANSFORM_HPP
#
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/seq/fold_left.hpp>
# include <streams_boost/preprocessor/seq/seq.hpp>
# include <streams_boost/preprocessor/tuple/elem.hpp>
# include <streams_boost/preprocessor/tuple/rem.hpp>
#
# /* STREAMS_BOOST_PP_SEQ_TRANSFORM */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_SEQ_TRANSFORM(op, data, seq) STREAMS_BOOST_PP_SEQ_TAIL(STREAMS_BOOST_PP_TUPLE_ELEM(3, 2, STREAMS_BOOST_PP_SEQ_FOLD_LEFT(STREAMS_BOOST_PP_SEQ_TRANSFORM_O, (op, data, (nil)), seq)))
# else
#    define STREAMS_BOOST_PP_SEQ_TRANSFORM(op, data, seq) STREAMS_BOOST_PP_SEQ_TRANSFORM_I(op, data, seq)
#    define STREAMS_BOOST_PP_SEQ_TRANSFORM_I(op, data, seq) STREAMS_BOOST_PP_SEQ_TAIL(STREAMS_BOOST_PP_TUPLE_ELEM(3, 2, STREAMS_BOOST_PP_SEQ_FOLD_LEFT(STREAMS_BOOST_PP_SEQ_TRANSFORM_O, (op, data, (nil)), seq)))
# endif
#
# if STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_STRICT()
#    define STREAMS_BOOST_PP_SEQ_TRANSFORM_O(s, state, elem) STREAMS_BOOST_PP_SEQ_TRANSFORM_O_IM(s, STREAMS_BOOST_PP_TUPLE_REM_3 state, elem)
#    define STREAMS_BOOST_PP_SEQ_TRANSFORM_O_IM(s, im, elem) STREAMS_BOOST_PP_SEQ_TRANSFORM_O_I(s, im, elem)
# else
#    define STREAMS_BOOST_PP_SEQ_TRANSFORM_O(s, state, elem) STREAMS_BOOST_PP_SEQ_TRANSFORM_O_I(s, STREAMS_BOOST_PP_TUPLE_ELEM(3, 0, state), STREAMS_BOOST_PP_TUPLE_ELEM(3, 1, state), STREAMS_BOOST_PP_TUPLE_ELEM(3, 2, state), elem)
# endif
#
# define STREAMS_BOOST_PP_SEQ_TRANSFORM_O_I(s, op, data, res, elem) (op, data, res (op(s, data, elem)))
#
# /* STREAMS_BOOST_PP_SEQ_TRANSFORM_S */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_SEQ_TRANSFORM_S(s, op, data, seq) STREAMS_BOOST_PP_SEQ_TAIL(STREAMS_BOOST_PP_TUPLE_ELEM(3, 2, STREAMS_BOOST_PP_SEQ_FOLD_LEFT_ ## s(STREAMS_BOOST_PP_SEQ_TRANSFORM_O, (op, data, (nil)), seq)))
# else
#    define STREAMS_BOOST_PP_SEQ_TRANSFORM_S(s, op, data, seq) STREAMS_BOOST_PP_SEQ_TRANSFORM_S_I(s, op, data, seq)
#    define STREAMS_BOOST_PP_SEQ_TRANSFORM_S_I(s, op, data, seq) STREAMS_BOOST_PP_SEQ_TAIL(STREAMS_BOOST_PP_TUPLE_ELEM(3, 2, STREAMS_BOOST_PP_SEQ_FOLD_LEFT_ ## s(STREAMS_BOOST_PP_SEQ_TRANSFORM_O, (op, data, (nil)), seq)))
# endif
#
# endif
