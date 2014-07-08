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
# ifndef STREAMS_BOOST_PREPROCESSOR_REPETITION_ENUM_TRAILING_PARAMS_HPP
# define STREAMS_BOOST_PREPROCESSOR_REPETITION_ENUM_TRAILING_PARAMS_HPP
#
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/repetition/repeat.hpp>
#
# /* STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(count, param) STREAMS_BOOST_PP_REPEAT(count, STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS_M, param)
# else
#    define STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(count, param) STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS_I(count, param)
#    define STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS_I(count, param) STREAMS_BOOST_PP_REPEAT(count, STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS_M, param)
# endif
#
# define STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS_M(z, n, param) , param ## n
#
# /* STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS_Z */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS_Z(z, count, param) STREAMS_BOOST_PP_REPEAT_ ## z(count, STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS_M, param)
# else
#    define STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS_Z(z, count, param) STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS_Z_I(z, count, param)
#    define STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS_Z_I(z, count, param) STREAMS_BOOST_PP_REPEAT_ ## z(count, STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS_M, param)
# endif
#
# endif
