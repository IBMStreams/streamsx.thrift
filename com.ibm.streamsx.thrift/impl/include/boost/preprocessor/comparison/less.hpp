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
# ifndef STREAMS_BOOST_PREPROCESSOR_COMPARISON_LESS_HPP
# define STREAMS_BOOST_PREPROCESSOR_COMPARISON_LESS_HPP
#
# include <streams_boost/preprocessor/comparison/less_equal.hpp>
# include <streams_boost/preprocessor/comparison/not_equal.hpp>
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/control/iif.hpp>
# include <streams_boost/preprocessor/logical/bitand.hpp>
# include <streams_boost/preprocessor/tuple/eat.hpp>
#
# /* STREAMS_BOOST_PP_LESS */
#
# if STREAMS_BOOST_PP_CONFIG_FLAGS() & (STREAMS_BOOST_PP_CONFIG_MWCC() | STREAMS_BOOST_PP_CONFIG_DMC())
#    define STREAMS_BOOST_PP_LESS(x, y) STREAMS_BOOST_PP_BITAND(STREAMS_BOOST_PP_NOT_EQUAL(x, y), STREAMS_BOOST_PP_LESS_EQUAL(x, y))
# elif ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_LESS(x, y) STREAMS_BOOST_PP_IIF(STREAMS_BOOST_PP_NOT_EQUAL(x, y), STREAMS_BOOST_PP_LESS_EQUAL, 0 STREAMS_BOOST_PP_TUPLE_EAT_2)(x, y)
# else
#    define STREAMS_BOOST_PP_LESS(x, y) STREAMS_BOOST_PP_LESS_I(x, y)
#    define STREAMS_BOOST_PP_LESS_I(x, y) STREAMS_BOOST_PP_IIF(STREAMS_BOOST_PP_NOT_EQUAL(x, y), STREAMS_BOOST_PP_LESS_EQUAL, 0 STREAMS_BOOST_PP_TUPLE_EAT_2)(x, y)
# endif
#
# /* STREAMS_BOOST_PP_LESS_D */
#
# if STREAMS_BOOST_PP_CONFIG_FLAGS() & (STREAMS_BOOST_PP_CONFIG_MWCC() | STREAMS_BOOST_PP_CONFIG_DMC())
#    define STREAMS_BOOST_PP_LESS_D(d, x, y) STREAMS_BOOST_PP_BITAND(STREAMS_BOOST_PP_NOT_EQUAL(x, y), STREAMS_BOOST_PP_LESS_EQUAL_D(d, x, y))
# elif ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_LESS_D(d, x, y) STREAMS_BOOST_PP_IIF(STREAMS_BOOST_PP_NOT_EQUAL(x, y), STREAMS_BOOST_PP_LESS_EQUAL_D, 0 STREAMS_BOOST_PP_TUPLE_EAT_3)(d, x, y)
# else
#    define STREAMS_BOOST_PP_LESS_D(d, x, y) STREAMS_BOOST_PP_LESS_D_I(d, x, y)
#    define STREAMS_BOOST_PP_LESS_D_I(d, x, y) STREAMS_BOOST_PP_IIF(STREAMS_BOOST_PP_NOT_EQUAL(x, y), STREAMS_BOOST_PP_LESS_EQUAL_D, 0 STREAMS_BOOST_PP_TUPLE_EAT_3)(d, x, y)
# endif
#
# endif
