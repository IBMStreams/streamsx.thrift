# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Paul Mensonides 2002.
#  *     Distributed under the Boost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.streams_boost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.streams_boost.org for most recent version. */
#
# ifndef STREAMS_BOOST_PREPROCESSOR_CONTROL_EXPR_IIF_HPP
# define STREAMS_BOOST_PREPROCESSOR_CONTROL_EXPR_IIF_HPP
#
# include <streams_boost/preprocessor/config/config.hpp>
#
# /* STREAMS_BOOST_PP_EXPR_IIF */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_MWCC()
#    define STREAMS_BOOST_PP_EXPR_IIF(bit, expr) STREAMS_BOOST_PP_EXPR_IIF_I(bit, expr)
# else
#    define STREAMS_BOOST_PP_EXPR_IIF(bit, expr) STREAMS_BOOST_PP_EXPR_IIF_OO((bit, expr))
#    define STREAMS_BOOST_PP_EXPR_IIF_OO(par) STREAMS_BOOST_PP_EXPR_IIF_I ## par
# endif
#
# define STREAMS_BOOST_PP_EXPR_IIF_I(bit, expr) STREAMS_BOOST_PP_EXPR_IIF_ ## bit(expr)
#
# define STREAMS_BOOST_PP_EXPR_IIF_0(expr)
# define STREAMS_BOOST_PP_EXPR_IIF_1(expr) expr
#
# endif
