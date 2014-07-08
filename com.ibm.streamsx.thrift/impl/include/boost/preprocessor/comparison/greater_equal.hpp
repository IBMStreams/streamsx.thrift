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
# ifndef STREAMS_BOOST_PREPROCESSOR_COMPARISON_GREATER_EQUAL_HPP
# define STREAMS_BOOST_PREPROCESSOR_COMPARISON_GREATER_EQUAL_HPP
#
# include <streams_boost/preprocessor/comparison/less_equal.hpp>
# include <streams_boost/preprocessor/config/config.hpp>
#
# /* STREAMS_BOOST_PP_GREATER_EQUAL */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_GREATER_EQUAL(x, y) STREAMS_BOOST_PP_LESS_EQUAL(y, x)
# else
#    define STREAMS_BOOST_PP_GREATER_EQUAL(x, y) STREAMS_BOOST_PP_GREATER_EQUAL_I(x, y)
#    define STREAMS_BOOST_PP_GREATER_EQUAL_I(x, y) STREAMS_BOOST_PP_LESS_EQUAL(y, x)
# endif
#
# /* STREAMS_BOOST_PP_GREATER_EQUAL_D */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_GREATER_EQUAL_D(d, x, y) STREAMS_BOOST_PP_LESS_EQUAL_D(d, y, x)
# else
#    define STREAMS_BOOST_PP_GREATER_EQUAL_D(d, x, y) STREAMS_BOOST_PP_GREATER_EQUAL_D_I(d, x, y)
#    define STREAMS_BOOST_PP_GREATER_EQUAL_D_I(d, x, y) STREAMS_BOOST_PP_LESS_EQUAL_D(d, y, x)
# endif
#
# endif
