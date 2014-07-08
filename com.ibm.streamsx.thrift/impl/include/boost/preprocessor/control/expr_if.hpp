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
# ifndef STREAMS_BOOST_PREPROCESSOR_CONTROL_EXPR_IF_HPP
# define STREAMS_BOOST_PREPROCESSOR_CONTROL_EXPR_IF_HPP
#
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/control/expr_iif.hpp>
# include <streams_boost/preprocessor/logical/bool.hpp>
#
# /* STREAMS_BOOST_PP_EXPR_IF */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_EXPR_IF(cond, expr) STREAMS_BOOST_PP_EXPR_IIF(STREAMS_BOOST_PP_BOOL(cond), expr)
# else
#    define STREAMS_BOOST_PP_EXPR_IF(cond, expr) STREAMS_BOOST_PP_EXPR_IF_I(cond, expr)
#    define STREAMS_BOOST_PP_EXPR_IF_I(cond, expr) STREAMS_BOOST_PP_EXPR_IIF(STREAMS_BOOST_PP_BOOL(cond), expr)
# endif
#
# endif
