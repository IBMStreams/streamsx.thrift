# /* Copyright (C) 2001
#  * Housemarque Oy
#  * http://www.housemarque.com
#  *
#  * Distributed under the Boost Software License, Version 1.0. (See
#  * accompanying file LICENSE_1_0.txt or copy at
#  * http://www.streams_boost.org/LICENSE_1_0.txt)
#  */
#
# /* Revised by Paul Mensonides (2002) */
#
# /* See http://www.streams_boost.org for most recent version. */
#
# ifndef STREAMS_BOOST_PREPROCESSOR_LIST_TRANSFORM_HPP
# define STREAMS_BOOST_PREPROCESSOR_LIST_TRANSFORM_HPP
#
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/list/fold_right.hpp>
# include <streams_boost/preprocessor/tuple/elem.hpp>
# include <streams_boost/preprocessor/tuple/rem.hpp>
#
# /* STREAMS_BOOST_PP_LIST_TRANSFORM */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_LIST_TRANSFORM(op, data, list) STREAMS_BOOST_PP_TUPLE_ELEM(3, 2, STREAMS_BOOST_PP_LIST_FOLD_RIGHT(STREAMS_BOOST_PP_LIST_TRANSFORM_O, (op, data, STREAMS_BOOST_PP_NIL), list))
# else
#    define STREAMS_BOOST_PP_LIST_TRANSFORM(op, data, list) STREAMS_BOOST_PP_LIST_TRANSFORM_I(op, data, list)
#    define STREAMS_BOOST_PP_LIST_TRANSFORM_I(op, data, list) STREAMS_BOOST_PP_TUPLE_ELEM(3, 2, STREAMS_BOOST_PP_LIST_FOLD_RIGHT(STREAMS_BOOST_PP_LIST_TRANSFORM_O, (op, data, STREAMS_BOOST_PP_NIL), list))
# endif
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_LIST_TRANSFORM_O(d, odr, elem) STREAMS_BOOST_PP_LIST_TRANSFORM_O_D(d, STREAMS_BOOST_PP_TUPLE_ELEM(3, 0, odr), STREAMS_BOOST_PP_TUPLE_ELEM(3, 1, odr), STREAMS_BOOST_PP_TUPLE_ELEM(3, 2, odr), elem)
# else
#    define STREAMS_BOOST_PP_LIST_TRANSFORM_O(d, odr, elem) STREAMS_BOOST_PP_LIST_TRANSFORM_O_I(d, STREAMS_BOOST_PP_TUPLE_REM_3 odr, elem)
#    define STREAMS_BOOST_PP_LIST_TRANSFORM_O_I(d, im, elem) STREAMS_BOOST_PP_LIST_TRANSFORM_O_D(d, im, elem)
# endif
#
# define STREAMS_BOOST_PP_LIST_TRANSFORM_O_D(d, op, data, res, elem) (op, data, (op(d, data, elem), res))
#
# /* STREAMS_BOOST_PP_LIST_TRANSFORM_D */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_LIST_TRANSFORM_D(d, op, data, list) STREAMS_BOOST_PP_TUPLE_ELEM(3, 2, STREAMS_BOOST_PP_LIST_FOLD_RIGHT_ ## d(STREAMS_BOOST_PP_LIST_TRANSFORM_O, (op, data, STREAMS_BOOST_PP_NIL), list))
# else
#    define STREAMS_BOOST_PP_LIST_TRANSFORM_D(d, op, data, list) STREAMS_BOOST_PP_LIST_TRANSFORM_D_I(d, op, data, list)
#    define STREAMS_BOOST_PP_LIST_TRANSFORM_D_I(d, op, data, list) STREAMS_BOOST_PP_TUPLE_ELEM(3, 2, STREAMS_BOOST_PP_LIST_FOLD_RIGHT_ ## d(STREAMS_BOOST_PP_LIST_TRANSFORM_O, (op, data, STREAMS_BOOST_PP_NIL), list))
# endif
#
# endif
