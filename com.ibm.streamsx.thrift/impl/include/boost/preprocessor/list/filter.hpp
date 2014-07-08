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
# ifndef STREAMS_BOOST_PREPROCESSOR_LIST_FILTER_HPP
# define STREAMS_BOOST_PREPROCESSOR_LIST_FILTER_HPP
#
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/control/if.hpp>
# include <streams_boost/preprocessor/list/fold_right.hpp>
# include <streams_boost/preprocessor/tuple/elem.hpp>
# include <streams_boost/preprocessor/tuple/rem.hpp>
#
# /* STREAMS_BOOST_PP_LIST_FILTER */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_LIST_FILTER(pred, data, list) STREAMS_BOOST_PP_TUPLE_ELEM(3, 2, STREAMS_BOOST_PP_LIST_FOLD_RIGHT(STREAMS_BOOST_PP_LIST_FILTER_O, (pred, data, STREAMS_BOOST_PP_NIL), list))
# else
#    define STREAMS_BOOST_PP_LIST_FILTER(pred, data, list) STREAMS_BOOST_PP_LIST_FILTER_I(pred, data, list)
#    define STREAMS_BOOST_PP_LIST_FILTER_I(pred, data, list) STREAMS_BOOST_PP_TUPLE_ELEM(3, 2, STREAMS_BOOST_PP_LIST_FOLD_RIGHT(STREAMS_BOOST_PP_LIST_FILTER_O, (pred, data, STREAMS_BOOST_PP_NIL), list))
# endif
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_LIST_FILTER_O(d, pdr, elem) STREAMS_BOOST_PP_LIST_FILTER_O_D(d, STREAMS_BOOST_PP_TUPLE_ELEM(3, 0, pdr), STREAMS_BOOST_PP_TUPLE_ELEM(3, 1, pdr), STREAMS_BOOST_PP_TUPLE_ELEM(3, 2, pdr), elem)
# else
#    define STREAMS_BOOST_PP_LIST_FILTER_O(d, pdr, elem) STREAMS_BOOST_PP_LIST_FILTER_O_I(d, STREAMS_BOOST_PP_TUPLE_REM_3 pdr, elem)
#    define STREAMS_BOOST_PP_LIST_FILTER_O_I(d, im, elem) STREAMS_BOOST_PP_LIST_FILTER_O_D(d, im, elem)
# endif
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_DMC()
#    define STREAMS_BOOST_PP_LIST_FILTER_O_D(d, pred, data, res, elem) (pred, data, STREAMS_BOOST_PP_IF(pred(d, data, elem), (elem, res), res))
# else
#    define STREAMS_BOOST_PP_LIST_FILTER_O_D(d, pred, data, res, elem) (pred, data, STREAMS_BOOST_PP_IF(pred##(d, data, elem), (elem, res), res))
# endif
#
# /* STREAMS_BOOST_PP_LIST_FILTER_D */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_LIST_FILTER_D(d, pred, data, list) STREAMS_BOOST_PP_TUPLE_ELEM(3, 2, STREAMS_BOOST_PP_LIST_FOLD_RIGHT_ ## d(STREAMS_BOOST_PP_LIST_FILTER_O, (pred, data, STREAMS_BOOST_PP_NIL), list))
# else
#    define STREAMS_BOOST_PP_LIST_FILTER_D(d, pred, data, list) STREAMS_BOOST_PP_LIST_FILTER_D_I(d, pred, data, list)
#    define STREAMS_BOOST_PP_LIST_FILTER_D_I(d, pred, data, list) STREAMS_BOOST_PP_TUPLE_ELEM(3, 2, STREAMS_BOOST_PP_LIST_FOLD_RIGHT_ ## d(STREAMS_BOOST_PP_LIST_FILTER_O, (pred, data, STREAMS_BOOST_PP_NIL), list))
# endif
#
# endif
