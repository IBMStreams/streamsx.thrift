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
# ifndef STREAMS_BOOST_PREPROCESSOR_ARITHMETIC_DETAIL_DIV_BASE_HPP
# define STREAMS_BOOST_PREPROCESSOR_ARITHMETIC_DETAIL_DIV_BASE_HPP
#
# include <streams_boost/preprocessor/arithmetic/inc.hpp>
# include <streams_boost/preprocessor/arithmetic/sub.hpp>
# include <streams_boost/preprocessor/comparison/less_equal.hpp>
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/control/while.hpp>
# include <streams_boost/preprocessor/tuple/elem.hpp>
# include <streams_boost/preprocessor/tuple/rem.hpp>
#
# /* STREAMS_BOOST_PP_DIV_BASE */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_DIV_BASE(x, y) STREAMS_BOOST_PP_WHILE(STREAMS_BOOST_PP_DIV_BASE_P, STREAMS_BOOST_PP_DIV_BASE_O, (0, x, y))
# else
#    define STREAMS_BOOST_PP_DIV_BASE(x, y) STREAMS_BOOST_PP_DIV_BASE_I(x, y)
#    define STREAMS_BOOST_PP_DIV_BASE_I(x, y) STREAMS_BOOST_PP_WHILE(STREAMS_BOOST_PP_DIV_BASE_P, STREAMS_BOOST_PP_DIV_BASE_O, (0, x, y))
# endif
#
# if STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_STRICT()
#    define STREAMS_BOOST_PP_DIV_BASE_P(d, rxy) STREAMS_BOOST_PP_DIV_BASE_P_IM(d, STREAMS_BOOST_PP_TUPLE_REM_3 rxy)
#    define STREAMS_BOOST_PP_DIV_BASE_P_IM(d, im) STREAMS_BOOST_PP_DIV_BASE_P_I(d, im)
# else
#    define STREAMS_BOOST_PP_DIV_BASE_P(d, rxy) STREAMS_BOOST_PP_DIV_BASE_P_I(d, STREAMS_BOOST_PP_TUPLE_ELEM(3, 0, rxy), STREAMS_BOOST_PP_TUPLE_ELEM(3, 1, rxy), STREAMS_BOOST_PP_TUPLE_ELEM(3, 2, rxy))
# endif
#
# define STREAMS_BOOST_PP_DIV_BASE_P_I(d, r, x, y) STREAMS_BOOST_PP_LESS_EQUAL_D(d, y, x)
#
# if STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_STRICT()
#    define STREAMS_BOOST_PP_DIV_BASE_O(d, rxy) STREAMS_BOOST_PP_DIV_BASE_O_IM(d, STREAMS_BOOST_PP_TUPLE_REM_3 rxy)
#    define STREAMS_BOOST_PP_DIV_BASE_O_IM(d, im) STREAMS_BOOST_PP_DIV_BASE_O_I(d, im)
# else
#    define STREAMS_BOOST_PP_DIV_BASE_O(d, rxy) STREAMS_BOOST_PP_DIV_BASE_O_I(d, STREAMS_BOOST_PP_TUPLE_ELEM(3, 0, rxy), STREAMS_BOOST_PP_TUPLE_ELEM(3, 1, rxy), STREAMS_BOOST_PP_TUPLE_ELEM(3, 2, rxy))
# endif
#
# define STREAMS_BOOST_PP_DIV_BASE_O_I(d, r, x, y) (STREAMS_BOOST_PP_INC(r), STREAMS_BOOST_PP_SUB_D(d, x, y), y)
#
# /* STREAMS_BOOST_PP_DIV_BASE_D */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_DIV_BASE_D(d, x, y) STREAMS_BOOST_PP_WHILE_ ## d(STREAMS_BOOST_PP_DIV_BASE_P, STREAMS_BOOST_PP_DIV_BASE_O, (0, x, y))
# else
#    define STREAMS_BOOST_PP_DIV_BASE_D(d, x, y) STREAMS_BOOST_PP_DIV_BASE_D_I(d, x, y)
#    define STREAMS_BOOST_PP_DIV_BASE_D_I(d, x, y) STREAMS_BOOST_PP_WHILE_ ## d(STREAMS_BOOST_PP_DIV_BASE_P, STREAMS_BOOST_PP_DIV_BASE_O, (0, x, y))
# endif
#
# endif
