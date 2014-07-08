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
# ifndef STREAMS_BOOST_PREPROCESSOR_LIST_SIZE_HPP
# define STREAMS_BOOST_PREPROCESSOR_LIST_SIZE_HPP
#
# include <streams_boost/preprocessor/arithmetic/inc.hpp>
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/control/while.hpp>
# include <streams_boost/preprocessor/list/adt.hpp>
# include <streams_boost/preprocessor/tuple/elem.hpp>
# include <streams_boost/preprocessor/tuple/rem.hpp>
#
# /* STREAMS_BOOST_PP_LIST_SIZE */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_LIST_SIZE(list) STREAMS_BOOST_PP_TUPLE_ELEM(2, 0, STREAMS_BOOST_PP_WHILE(STREAMS_BOOST_PP_LIST_SIZE_P, STREAMS_BOOST_PP_LIST_SIZE_O, (0, list)))
# else
#    define STREAMS_BOOST_PP_LIST_SIZE(list) STREAMS_BOOST_PP_LIST_SIZE_I(list)
#    define STREAMS_BOOST_PP_LIST_SIZE_I(list) STREAMS_BOOST_PP_TUPLE_ELEM(2, 0, STREAMS_BOOST_PP_WHILE(STREAMS_BOOST_PP_LIST_SIZE_P, STREAMS_BOOST_PP_LIST_SIZE_O, (0, list)))
# endif
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_LIST_SIZE_P(d, rl) STREAMS_BOOST_PP_LIST_IS_CONS(STREAMS_BOOST_PP_TUPLE_ELEM(2, 1, rl))
# else
#    define STREAMS_BOOST_PP_LIST_SIZE_P(d, rl) STREAMS_BOOST_PP_LIST_SIZE_P_I(STREAMS_BOOST_PP_TUPLE_REM_2 rl)
#    define STREAMS_BOOST_PP_LIST_SIZE_P_I(im) STREAMS_BOOST_PP_LIST_SIZE_P_II(im)
#    define STREAMS_BOOST_PP_LIST_SIZE_P_II(r, l) STREAMS_BOOST_PP_LIST_IS_CONS(l)
# endif
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_LIST_SIZE_O(d, rl) (STREAMS_BOOST_PP_INC(STREAMS_BOOST_PP_TUPLE_ELEM(2, 0, rl)), STREAMS_BOOST_PP_LIST_REST(STREAMS_BOOST_PP_TUPLE_ELEM(2, 1, rl)))
# else
#    define STREAMS_BOOST_PP_LIST_SIZE_O(d, rl) STREAMS_BOOST_PP_LIST_SIZE_O_I(STREAMS_BOOST_PP_TUPLE_REM_2 rl)
#    define STREAMS_BOOST_PP_LIST_SIZE_O_I(im) STREAMS_BOOST_PP_LIST_SIZE_O_II(im)
#    define STREAMS_BOOST_PP_LIST_SIZE_O_II(r, l) (STREAMS_BOOST_PP_INC(r), STREAMS_BOOST_PP_LIST_REST(l))
# endif
#
# /* STREAMS_BOOST_PP_LIST_SIZE_D */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_LIST_SIZE_D(d, list) STREAMS_BOOST_PP_TUPLE_ELEM(2, 0, STREAMS_BOOST_PP_WHILE_ ## d(STREAMS_BOOST_PP_LIST_SIZE_P, STREAMS_BOOST_PP_LIST_SIZE_O, (0, list)))
# else
#    define STREAMS_BOOST_PP_LIST_SIZE_D(d, list) STREAMS_BOOST_PP_LIST_SIZE_D_I(d, list)
#    define STREAMS_BOOST_PP_LIST_SIZE_D_I(d, list) STREAMS_BOOST_PP_TUPLE_ELEM(2, 0, STREAMS_BOOST_PP_WHILE_ ## d(STREAMS_BOOST_PP_LIST_SIZE_P, STREAMS_BOOST_PP_LIST_SIZE_O, (0, list)))
# endif
#
# endif
