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
# ifndef STREAMS_BOOST_PREPROCESSOR_COMPARISON_LESS_EQUAL_HPP
# define STREAMS_BOOST_PREPROCESSOR_COMPARISON_LESS_EQUAL_HPP
#
# include <streams_boost/preprocessor/arithmetic/sub.hpp>
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/logical/not.hpp>
#
# /* STREAMS_BOOST_PP_LESS_EQUAL */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_LESS_EQUAL(x, y) STREAMS_BOOST_PP_NOT(STREAMS_BOOST_PP_SUB(x, y))
# else
#    define STREAMS_BOOST_PP_LESS_EQUAL(x, y) STREAMS_BOOST_PP_LESS_EQUAL_I(x, y)
#    define STREAMS_BOOST_PP_LESS_EQUAL_I(x, y) STREAMS_BOOST_PP_NOT(STREAMS_BOOST_PP_SUB(x, y))
# endif
#
# /* STREAMS_BOOST_PP_LESS_EQUAL_D */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_LESS_EQUAL_D(d, x, y) STREAMS_BOOST_PP_NOT(STREAMS_BOOST_PP_SUB_D(d, x, y))
# else
#    define STREAMS_BOOST_PP_LESS_EQUAL_D(d, x, y) STREAMS_BOOST_PP_LESS_EQUAL_D_I(d, x, y)
#    define STREAMS_BOOST_PP_LESS_EQUAL_D_I(d, x, y) STREAMS_BOOST_PP_NOT(STREAMS_BOOST_PP_SUB_D(d, x, y))
# endif
#
# endif
