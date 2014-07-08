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
# ifndef STREAMS_BOOST_PREPROCESSOR_SELECTION_MAX_HPP
# define STREAMS_BOOST_PREPROCESSOR_SELECTION_MAX_HPP
#
# include <streams_boost/preprocessor/comparison/less_equal.hpp>
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/control/iif.hpp>
#
# /* STREAMS_BOOST_PP_MAX */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_MAX(x, y) STREAMS_BOOST_PP_IIF(STREAMS_BOOST_PP_LESS_EQUAL(x, y), y, x)
# else
#    define STREAMS_BOOST_PP_MAX(x, y) STREAMS_BOOST_PP_MAX_I(x, y)
#    define STREAMS_BOOST_PP_MAX_I(x, y) STREAMS_BOOST_PP_IIF(STREAMS_BOOST_PP_LESS_EQUAL(x, y), y, x)
# endif
#
# /* STREAMS_BOOST_PP_MAX_D */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_MAX_D(d, x, y) STREAMS_BOOST_PP_IIF(STREAMS_BOOST_PP_LESS_EQUAL_D(d, x, y), y, x)
# else
#    define STREAMS_BOOST_PP_MAX_D(d, x, y) STREAMS_BOOST_PP_MAX_D_I(d, x, y)
#    define STREAMS_BOOST_PP_MAX_D_I(d, x, y) STREAMS_BOOST_PP_IIF(STREAMS_BOOST_PP_LESS_EQUAL_D(d, x, y), y, x)
# endif
#
# endif
