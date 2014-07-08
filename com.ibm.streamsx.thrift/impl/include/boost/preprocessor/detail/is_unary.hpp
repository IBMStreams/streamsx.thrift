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
# ifndef STREAMS_BOOST_PREPROCESSOR_DETAIL_IS_UNARY_HPP
# define STREAMS_BOOST_PREPROCESSOR_DETAIL_IS_UNARY_HPP
#
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/detail/check.hpp>
#
# /* STREAMS_BOOST_PP_IS_UNARY */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_IS_UNARY(x) STREAMS_BOOST_PP_CHECK(x, STREAMS_BOOST_PP_IS_UNARY_CHECK)
# else
#    define STREAMS_BOOST_PP_IS_UNARY(x) STREAMS_BOOST_PP_IS_UNARY_I(x)
#    define STREAMS_BOOST_PP_IS_UNARY_I(x) STREAMS_BOOST_PP_CHECK(x, STREAMS_BOOST_PP_IS_UNARY_CHECK)
# endif
#
# define STREAMS_BOOST_PP_IS_UNARY_CHECK(a) 1
# define STREAMS_BOOST_PP_CHECK_RESULT_STREAMS_BOOST_PP_IS_UNARY_CHECK 0, STREAMS_BOOST_PP_NIL
#
# endif