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
# ifndef STREAMS_BOOST_PREPROCESSOR_LIST_REST_N_HPP
# define STREAMS_BOOST_PREPROCESSOR_LIST_REST_N_HPP
#
# include <streams_boost/preprocessor/arithmetic/dec.hpp>
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/control/while.hpp>
# include <streams_boost/preprocessor/list/adt.hpp>
# include <streams_boost/preprocessor/tuple/elem.hpp>
#
# /* STREAMS_BOOST_PP_LIST_REST_N */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_LIST_REST_N(count, list) STREAMS_BOOST_PP_TUPLE_ELEM(2, 0, STREAMS_BOOST_PP_WHILE(STREAMS_BOOST_PP_LIST_REST_N_P, STREAMS_BOOST_PP_LIST_REST_N_O, (list, count)))
# else
#    define STREAMS_BOOST_PP_LIST_REST_N(count, list) STREAMS_BOOST_PP_LIST_REST_N_I(count, list)
#    define STREAMS_BOOST_PP_LIST_REST_N_I(count, list) STREAMS_BOOST_PP_TUPLE_ELEM(2, 0, STREAMS_BOOST_PP_WHILE(STREAMS_BOOST_PP_LIST_REST_N_P, STREAMS_BOOST_PP_LIST_REST_N_O, (list, count)))
# endif
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_LIST_REST_N_P(d, lc) STREAMS_BOOST_PP_TUPLE_ELEM(2, 1, lc)
# else
#    define STREAMS_BOOST_PP_LIST_REST_N_P(d, lc) STREAMS_BOOST_PP_LIST_REST_N_P_I lc
#    define STREAMS_BOOST_PP_LIST_REST_N_P_I(list, count) count
# endif
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_LIST_REST_N_O(d, lc) (STREAMS_BOOST_PP_LIST_REST(STREAMS_BOOST_PP_TUPLE_ELEM(2, 0, lc)), STREAMS_BOOST_PP_DEC(STREAMS_BOOST_PP_TUPLE_ELEM(2, 1, lc)))
# else
#    define STREAMS_BOOST_PP_LIST_REST_N_O(d, lc) STREAMS_BOOST_PP_LIST_REST_N_O_I lc
#    define STREAMS_BOOST_PP_LIST_REST_N_O_I(list, count) (STREAMS_BOOST_PP_LIST_REST(list), STREAMS_BOOST_PP_DEC(count))
# endif
#
# /* STREAMS_BOOST_PP_LIST_REST_N_D */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_LIST_REST_N_D(d, count, list) STREAMS_BOOST_PP_TUPLE_ELEM(2, 0, STREAMS_BOOST_PP_WHILE_ ## d(STREAMS_BOOST_PP_LIST_REST_N_P, STREAMS_BOOST_PP_LIST_REST_N_O, (list, count)))
# else
#    define STREAMS_BOOST_PP_LIST_REST_N_D(d, count, list) STREAMS_BOOST_PP_LIST_REST_N_D_I(d, count, list)
#    define STREAMS_BOOST_PP_LIST_REST_N_D_I(d, count, list) STREAMS_BOOST_PP_TUPLE_ELEM(2, 0, STREAMS_BOOST_PP_WHILE_ ## d(STREAMS_BOOST_PP_LIST_REST_N_P, STREAMS_BOOST_PP_LIST_REST_N_O, (list, count)))
# endif
#
# endif
