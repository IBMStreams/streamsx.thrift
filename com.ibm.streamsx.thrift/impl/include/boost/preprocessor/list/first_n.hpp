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
# ifndef STREAMS_BOOST_PREPROCESSOR_LIST_FIRST_N_HPP
# define STREAMS_BOOST_PREPROCESSOR_LIST_FIRST_N_HPP
#
# include <streams_boost/preprocessor/arithmetic/dec.hpp>
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/control/while.hpp>
# include <streams_boost/preprocessor/list/adt.hpp>
# include <streams_boost/preprocessor/list/reverse.hpp>
# include <streams_boost/preprocessor/tuple/elem.hpp>
# include <streams_boost/preprocessor/tuple/rem.hpp>
#
# /* STREAMS_BOOST_PP_LIST_FIRST_N */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_LIST_FIRST_N(count, list) STREAMS_BOOST_PP_LIST_REVERSE(STREAMS_BOOST_PP_TUPLE_ELEM(3, 2, STREAMS_BOOST_PP_WHILE(STREAMS_BOOST_PP_LIST_FIRST_N_P, STREAMS_BOOST_PP_LIST_FIRST_N_O, (count, list, STREAMS_BOOST_PP_NIL))))
# else
#    define STREAMS_BOOST_PP_LIST_FIRST_N(count, list) STREAMS_BOOST_PP_LIST_FIRST_N_I(count, list)
#    define STREAMS_BOOST_PP_LIST_FIRST_N_I(count, list) STREAMS_BOOST_PP_LIST_REVERSE(STREAMS_BOOST_PP_TUPLE_ELEM(3, 2, STREAMS_BOOST_PP_WHILE(STREAMS_BOOST_PP_LIST_FIRST_N_P, STREAMS_BOOST_PP_LIST_FIRST_N_O, (count, list, STREAMS_BOOST_PP_NIL))))
# endif
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_LIST_FIRST_N_P(d, data) STREAMS_BOOST_PP_TUPLE_ELEM(3, 0, data)
# else
#    define STREAMS_BOOST_PP_LIST_FIRST_N_P(d, data) STREAMS_BOOST_PP_LIST_FIRST_N_P_I data
#    define STREAMS_BOOST_PP_LIST_FIRST_N_P_I(c, l, nl) c
# endif
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_MWCC()
#    define STREAMS_BOOST_PP_LIST_FIRST_N_O(d, data) STREAMS_BOOST_PP_LIST_FIRST_N_O_D data
# else
#    define STREAMS_BOOST_PP_LIST_FIRST_N_O(d, data) STREAMS_BOOST_PP_LIST_FIRST_N_O_D(STREAMS_BOOST_PP_TUPLE_ELEM(3, 0, data), STREAMS_BOOST_PP_TUPLE_ELEM(3, 1, data), STREAMS_BOOST_PP_TUPLE_ELEM(3, 2, data))
# endif
#
# define STREAMS_BOOST_PP_LIST_FIRST_N_O_D(c, l, nl) (STREAMS_BOOST_PP_DEC(c), STREAMS_BOOST_PP_LIST_REST(l), (STREAMS_BOOST_PP_LIST_FIRST(l), nl))
#
# /* STREAMS_BOOST_PP_LIST_FIRST_N_D */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_LIST_FIRST_N_D(d, count, list) STREAMS_BOOST_PP_LIST_REVERSE_D(d, STREAMS_BOOST_PP_TUPLE_ELEM(3, 2, STREAMS_BOOST_PP_WHILE_ ## d(STREAMS_BOOST_PP_LIST_FIRST_N_P, STREAMS_BOOST_PP_LIST_FIRST_N_O, (count, list, STREAMS_BOOST_PP_NIL))))
# else
#    define STREAMS_BOOST_PP_LIST_FIRST_N_D(d, count, list) STREAMS_BOOST_PP_LIST_FIRST_N_D_I(d, count, list)
#    define STREAMS_BOOST_PP_LIST_FIRST_N_D_I(d, count, list) STREAMS_BOOST_PP_LIST_REVERSE_D(d, STREAMS_BOOST_PP_TUPLE_ELEM(3, 2, STREAMS_BOOST_PP_WHILE_ ## d(STREAMS_BOOST_PP_LIST_FIRST_N_P, STREAMS_BOOST_PP_LIST_FIRST_N_O, (count, list, STREAMS_BOOST_PP_NIL))))
# endif
#
# endif
