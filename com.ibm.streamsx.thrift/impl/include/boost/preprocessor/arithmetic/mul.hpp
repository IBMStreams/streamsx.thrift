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
# ifndef STREAMS_BOOST_PREPROCESSOR_ARITHMETIC_MUL_HPP
# define STREAMS_BOOST_PREPROCESSOR_ARITHMETIC_MUL_HPP
#
# include <streams_boost/preprocessor/arithmetic/add.hpp>
# include <streams_boost/preprocessor/arithmetic/dec.hpp>
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/control/while.hpp>
# include <streams_boost/preprocessor/tuple/elem.hpp>
# include <streams_boost/preprocessor/tuple/rem.hpp>
#
# /* STREAMS_BOOST_PP_MUL */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_MUL(x, y) STREAMS_BOOST_PP_TUPLE_ELEM(3, 0, STREAMS_BOOST_PP_WHILE(STREAMS_BOOST_PP_MUL_P, STREAMS_BOOST_PP_MUL_O, (0, x, y)))
# else
#    define STREAMS_BOOST_PP_MUL(x, y) STREAMS_BOOST_PP_MUL_I(x, y)
#    define STREAMS_BOOST_PP_MUL_I(x, y) STREAMS_BOOST_PP_TUPLE_ELEM(3, 0, STREAMS_BOOST_PP_WHILE(STREAMS_BOOST_PP_MUL_P, STREAMS_BOOST_PP_MUL_O, (0, x, y)))
# endif
#
# define STREAMS_BOOST_PP_MUL_P(d, rxy) STREAMS_BOOST_PP_TUPLE_ELEM(3, 2, rxy)
#
# if STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_STRICT()
#    define STREAMS_BOOST_PP_MUL_O(d, rxy) STREAMS_BOOST_PP_MUL_O_IM(d, STREAMS_BOOST_PP_TUPLE_REM_3 rxy)
#    define STREAMS_BOOST_PP_MUL_O_IM(d, im) STREAMS_BOOST_PP_MUL_O_I(d, im)
# else
#    define STREAMS_BOOST_PP_MUL_O(d, rxy) STREAMS_BOOST_PP_MUL_O_I(d, STREAMS_BOOST_PP_TUPLE_ELEM(3, 0, rxy), STREAMS_BOOST_PP_TUPLE_ELEM(3, 1, rxy), STREAMS_BOOST_PP_TUPLE_ELEM(3, 2, rxy))
# endif
#
# define STREAMS_BOOST_PP_MUL_O_I(d, r, x, y) (STREAMS_BOOST_PP_ADD_D(d, r, x), x, STREAMS_BOOST_PP_DEC(y))
#
# /* STREAMS_BOOST_PP_MUL_D */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_MUL_D(d, x, y) STREAMS_BOOST_PP_TUPLE_ELEM(3, 0, STREAMS_BOOST_PP_WHILE_ ## d(STREAMS_BOOST_PP_MUL_P, STREAMS_BOOST_PP_MUL_O, (0, x, y)))
# else
#    define STREAMS_BOOST_PP_MUL_D(d, x, y) STREAMS_BOOST_PP_MUL_D_I(d, x, y)
#    define STREAMS_BOOST_PP_MUL_D_I(d, x, y) STREAMS_BOOST_PP_TUPLE_ELEM(3, 0, STREAMS_BOOST_PP_WHILE_ ## d(STREAMS_BOOST_PP_MUL_P, STREAMS_BOOST_PP_MUL_O, (0, x, y)))
# endif
#
# endif
