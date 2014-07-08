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
# ifndef STREAMS_BOOST_PREPROCESSOR_ARITHMETIC_MOD_HPP
# define STREAMS_BOOST_PREPROCESSOR_ARITHMETIC_MOD_HPP
#
# include <streams_boost/preprocessor/arithmetic/detail/div_base.hpp>
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/tuple/elem.hpp>
#
# /* STREAMS_BOOST_PP_MOD */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_MOD(x, y) STREAMS_BOOST_PP_TUPLE_ELEM(3, 1, STREAMS_BOOST_PP_DIV_BASE(x, y))
# else
#    define STREAMS_BOOST_PP_MOD(x, y) STREAMS_BOOST_PP_MOD_I(x, y)
#    define STREAMS_BOOST_PP_MOD_I(x, y) STREAMS_BOOST_PP_TUPLE_ELEM(3, 1, STREAMS_BOOST_PP_DIV_BASE(x, y))
# endif
#
# /* STREAMS_BOOST_PP_MOD_D */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_MOD_D(d, x, y) STREAMS_BOOST_PP_TUPLE_ELEM(3, 1, STREAMS_BOOST_PP_DIV_BASE_D(d, x, y))
# else
#    define STREAMS_BOOST_PP_MOD_D(d, x, y) STREAMS_BOOST_PP_MOD_D_I(d, x, y)
#    define STREAMS_BOOST_PP_MOD_D_I(d, x, y) STREAMS_BOOST_PP_TUPLE_ELEM(3, 1, STREAMS_BOOST_PP_DIV_BASE_D(d, x, y))
# endif
#
# endif
