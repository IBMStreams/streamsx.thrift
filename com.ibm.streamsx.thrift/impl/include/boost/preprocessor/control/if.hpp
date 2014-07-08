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
# ifndef STREAMS_BOOST_PREPROCESSOR_CONTROL_IF_HPP
# define STREAMS_BOOST_PREPROCESSOR_CONTROL_IF_HPP
#
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/control/iif.hpp>
# include <streams_boost/preprocessor/logical/bool.hpp>
#
# /* STREAMS_BOOST_PP_IF */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_IF(cond, t, f) STREAMS_BOOST_PP_IIF(STREAMS_BOOST_PP_BOOL(cond), t, f)
# else
#    define STREAMS_BOOST_PP_IF(cond, t, f) STREAMS_BOOST_PP_IF_I(cond, t, f)
#    define STREAMS_BOOST_PP_IF_I(cond, t, f) STREAMS_BOOST_PP_IIF(STREAMS_BOOST_PP_BOOL(cond), t, f)
# endif
#
# endif
