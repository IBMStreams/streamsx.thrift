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
# ifndef STREAMS_BOOST_PREPROCESSOR_REPETITION_ENUM_PARAMS_WITH_A_DEFAULT_HPP
# define STREAMS_BOOST_PREPROCESSOR_REPETITION_ENUM_PARAMS_WITH_A_DEFAULT_HPP
#
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/facilities/intercept.hpp>
# include <streams_boost/preprocessor/repetition/enum_binary_params.hpp>
#
# /* STREAMS_BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT */
#
# define STREAMS_BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(count, param, def) STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(count, param, = def STREAMS_BOOST_PP_INTERCEPT)
#
# endif
