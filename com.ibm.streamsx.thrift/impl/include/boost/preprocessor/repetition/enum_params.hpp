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
# ifndef STREAMS_BOOST_PREPROCESSOR_REPETITION_ENUM_PARAMS_HPP
# define STREAMS_BOOST_PREPROCESSOR_REPETITION_ENUM_PARAMS_HPP
#
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/punctuation/comma_if.hpp>
# include <streams_boost/preprocessor/repetition/repeat.hpp>
#
# /* STREAMS_BOOST_PP_ENUM_PARAMS */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_ENUM_PARAMS(count, param) STREAMS_BOOST_PP_REPEAT(count, STREAMS_BOOST_PP_ENUM_PARAMS_M, param)
# else
#    define STREAMS_BOOST_PP_ENUM_PARAMS(count, param) STREAMS_BOOST_PP_ENUM_PARAMS_I(count, param)
#    define STREAMS_BOOST_PP_ENUM_PARAMS_I(count, param) STREAMS_BOOST_PP_REPEAT(count, STREAMS_BOOST_PP_ENUM_PARAMS_M, param)
# endif
#
# define STREAMS_BOOST_PP_ENUM_PARAMS_M(z, n, param) STREAMS_BOOST_PP_COMMA_IF(n) param ## n
#
# /* STREAMS_BOOST_PP_ENUM_PARAMS_Z */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_ENUM_PARAMS_Z(z, count, param) STREAMS_BOOST_PP_REPEAT_ ## z(count, STREAMS_BOOST_PP_ENUM_PARAMS_M, param)
# else
#    define STREAMS_BOOST_PP_ENUM_PARAMS_Z(z, count, param) STREAMS_BOOST_PP_ENUM_PARAMS_Z_I(z, count, param)
#    define STREAMS_BOOST_PP_ENUM_PARAMS_Z_I(z, count, param) STREAMS_BOOST_PP_REPEAT_ ## z(count, STREAMS_BOOST_PP_ENUM_PARAMS_M, param)
# endif
#
# endif
