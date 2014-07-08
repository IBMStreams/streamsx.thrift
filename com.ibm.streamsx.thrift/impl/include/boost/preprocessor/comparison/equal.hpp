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
# ifndef STREAMS_BOOST_PREPROCESSOR_COMPARISON_EQUAL_HPP
# define STREAMS_BOOST_PREPROCESSOR_COMPARISON_EQUAL_HPP
#
# include <streams_boost/preprocessor/comparison/not_equal.hpp>
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/logical/compl.hpp>
#
# /* STREAMS_BOOST_PP_EQUAL */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_EQUAL(x, y) STREAMS_BOOST_PP_COMPL(STREAMS_BOOST_PP_NOT_EQUAL(x, y))
# else
#    define STREAMS_BOOST_PP_EQUAL(x, y) STREAMS_BOOST_PP_EQUAL_I(x, y)
#    define STREAMS_BOOST_PP_EQUAL_I(x, y) STREAMS_BOOST_PP_COMPL(STREAMS_BOOST_PP_NOT_EQUAL(x, y))
# endif
#
# /* STREAMS_BOOST_PP_EQUAL_D */
#
# define STREAMS_BOOST_PP_EQUAL_D(d, x, y) STREAMS_BOOST_PP_EQUAL(x, y)
#
# endif
