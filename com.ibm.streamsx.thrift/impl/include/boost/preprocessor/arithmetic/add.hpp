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
# ifndef STREAMS_BOOST_PREPROCESSOR_ARITHMETIC_ADD_HPP
# define STREAMS_BOOST_PREPROCESSOR_ARITHMETIC_ADD_HPP
#
# include <streams_boost/preprocessor/arithmetic/dec.hpp>
# include <streams_boost/preprocessor/arithmetic/inc.hpp>
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/control/while.hpp>
# include <streams_boost/preprocessor/tuple/elem.hpp>
#
# /* STREAMS_BOOST_PP_ADD */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_ADD(x, y) STREAMS_BOOST_PP_TUPLE_ELEM(2, 0, STREAMS_BOOST_PP_WHILE(STREAMS_BOOST_PP_ADD_P, STREAMS_BOOST_PP_ADD_O, (x, y)))
# else
#    define STREAMS_BOOST_PP_ADD(x, y) STREAMS_BOOST_PP_ADD_I(x, y)
#    define STREAMS_BOOST_PP_ADD_I(x, y) STREAMS_BOOST_PP_TUPLE_ELEM(2, 0, STREAMS_BOOST_PP_WHILE(STREAMS_BOOST_PP_ADD_P, STREAMS_BOOST_PP_ADD_O, (x, y)))
# endif
#
# define STREAMS_BOOST_PP_ADD_P(d, xy) STREAMS_BOOST_PP_TUPLE_ELEM(2, 1, xy)
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_MWCC()
#    define STREAMS_BOOST_PP_ADD_O(d, xy) STREAMS_BOOST_PP_ADD_O_I xy
# else
#    define STREAMS_BOOST_PP_ADD_O(d, xy) STREAMS_BOOST_PP_ADD_O_I(STREAMS_BOOST_PP_TUPLE_ELEM(2, 0, xy), STREAMS_BOOST_PP_TUPLE_ELEM(2, 1, xy))
# endif
#
# define STREAMS_BOOST_PP_ADD_O_I(x, y) (STREAMS_BOOST_PP_INC(x), STREAMS_BOOST_PP_DEC(y))
#
# /* STREAMS_BOOST_PP_ADD_D */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_ADD_D(d, x, y) STREAMS_BOOST_PP_TUPLE_ELEM(2, 0, STREAMS_BOOST_PP_WHILE_ ## d(STREAMS_BOOST_PP_ADD_P, STREAMS_BOOST_PP_ADD_O, (x, y)))
# else
#    define STREAMS_BOOST_PP_ADD_D(d, x, y) STREAMS_BOOST_PP_ADD_D_I(d, x, y)
#    define STREAMS_BOOST_PP_ADD_D_I(d, x, y) STREAMS_BOOST_PP_TUPLE_ELEM(2, 0, STREAMS_BOOST_PP_WHILE_ ## d(STREAMS_BOOST_PP_ADD_P, STREAMS_BOOST_PP_ADD_O, (x, y)))
# endif
#
# endif
