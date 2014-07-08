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
# ifndef STREAMS_BOOST_PREPROCESSOR_DEBUG_ASSERT_HPP
# define STREAMS_BOOST_PREPROCESSOR_DEBUG_ASSERT_HPP
#
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/control/expr_iif.hpp>
# include <streams_boost/preprocessor/control/iif.hpp>
# include <streams_boost/preprocessor/logical/not.hpp>
# include <streams_boost/preprocessor/tuple/eat.hpp>
#
# /* STREAMS_BOOST_PP_ASSERT */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_ASSERT STREAMS_BOOST_PP_ASSERT_D
# else
#    define STREAMS_BOOST_PP_ASSERT(cond) STREAMS_BOOST_PP_ASSERT_D(cond)
# endif
#
# define STREAMS_BOOST_PP_ASSERT_D(cond) STREAMS_BOOST_PP_IIF(STREAMS_BOOST_PP_NOT(cond), STREAMS_BOOST_PP_ASSERT_ERROR, STREAMS_BOOST_PP_TUPLE_EAT_1)(...)
# define STREAMS_BOOST_PP_ASSERT_ERROR(x, y, z)
#
# /* STREAMS_BOOST_PP_ASSERT_MSG */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_ASSERT_MSG STREAMS_BOOST_PP_ASSERT_MSG_D
# else
#    define STREAMS_BOOST_PP_ASSERT_MSG(cond, msg) STREAMS_BOOST_PP_ASSERT_MSG_D(cond, msg)
# endif
#
# define STREAMS_BOOST_PP_ASSERT_MSG_D(cond, msg) STREAMS_BOOST_PP_EXPR_IIF(STREAMS_BOOST_PP_NOT(cond), msg)
#
# endif
