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
# ifndef STREAMS_BOOST_PREPROCESSOR_SEQ_FILTER_HPP
# define STREAMS_BOOST_PREPROCESSOR_SEQ_FILTER_HPP
#
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/control/expr_if.hpp>
# include <streams_boost/preprocessor/facilities/empty.hpp>
# include <streams_boost/preprocessor/seq/fold_left.hpp>
# include <streams_boost/preprocessor/seq/seq.hpp>
# include <streams_boost/preprocessor/tuple/elem.hpp>
# include <streams_boost/preprocessor/tuple/rem.hpp>
#
# /* STREAMS_BOOST_PP_SEQ_FILTER */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_SEQ_FILTER(pred, data, seq) STREAMS_BOOST_PP_SEQ_TAIL(STREAMS_BOOST_PP_TUPLE_ELEM(3, 2, STREAMS_BOOST_PP_SEQ_FOLD_LEFT(STREAMS_BOOST_PP_SEQ_FILTER_O, (pred, data, (nil)), seq)))
# else
#    define STREAMS_BOOST_PP_SEQ_FILTER(pred, data, seq) STREAMS_BOOST_PP_SEQ_FILTER_I(pred, data, seq)
#    define STREAMS_BOOST_PP_SEQ_FILTER_I(pred, data, seq) STREAMS_BOOST_PP_SEQ_TAIL(STREAMS_BOOST_PP_TUPLE_ELEM(3, 2, STREAMS_BOOST_PP_SEQ_FOLD_LEFT(STREAMS_BOOST_PP_SEQ_FILTER_O, (pred, data, (nil)), seq)))
# endif
#
# if STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_STRICT()
#    define STREAMS_BOOST_PP_SEQ_FILTER_O(s, st, elem) STREAMS_BOOST_PP_SEQ_FILTER_O_IM(s, STREAMS_BOOST_PP_TUPLE_REM_3 st, elem)
#    define STREAMS_BOOST_PP_SEQ_FILTER_O_IM(s, im, elem) STREAMS_BOOST_PP_SEQ_FILTER_O_I(s, im, elem)
# else
#    define STREAMS_BOOST_PP_SEQ_FILTER_O(s, st, elem) STREAMS_BOOST_PP_SEQ_FILTER_O_I(s, STREAMS_BOOST_PP_TUPLE_ELEM(3, 0, st), STREAMS_BOOST_PP_TUPLE_ELEM(3, 1, st), STREAMS_BOOST_PP_TUPLE_ELEM(3, 2, st), elem)
# endif
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_DMC()
#   define STREAMS_BOOST_PP_SEQ_FILTER_O_I(s, pred, data, res, elem) (pred, data, res STREAMS_BOOST_PP_EXPR_IF(pred(s, data, elem), (elem)))
# else
#   define STREAMS_BOOST_PP_SEQ_FILTER_O_I(s, pred, data, res, elem) (pred, data, res STREAMS_BOOST_PP_EXPR_IF(pred##(s, data, elem), (elem)))
# endif
#
# /* STREAMS_BOOST_PP_SEQ_FILTER_S */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_SEQ_FILTER_S(s, pred, data, seq) STREAMS_BOOST_PP_SEQ_TAIL(STREAMS_BOOST_PP_TUPLE_ELEM(3, 2, STREAMS_BOOST_PP_SEQ_FOLD_LEFT_ ## s(STREAMS_BOOST_PP_SEQ_FILTER_O, (pred, data, (nil)), seq)))
# else
#    define STREAMS_BOOST_PP_SEQ_FILTER_S(s, pred, data, seq) STREAMS_BOOST_PP_SEQ_FILTER_S_I(s, pred, data, seq)
#    define STREAMS_BOOST_PP_SEQ_FILTER_S_I(s, pred, data, seq) STREAMS_BOOST_PP_SEQ_TAIL(STREAMS_BOOST_PP_TUPLE_ELEM(3, 2, STREAMS_BOOST_PP_SEQ_FOLD_LEFT_ ## s(STREAMS_BOOST_PP_SEQ_FILTER_O, (pred, data, (nil)), seq)))
# endif
#
# endif
