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
# ifndef STREAMS_BOOST_PREPROCESSOR_FACILITIES_EXPAND_HPP
# define STREAMS_BOOST_PREPROCESSOR_FACILITIES_EXPAND_HPP
#
# include <streams_boost/preprocessor/config/config.hpp>
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_MWCC() && ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_DMC()
#    define STREAMS_BOOST_PP_EXPAND(x) STREAMS_BOOST_PP_EXPAND_I(x)
# else
#    define STREAMS_BOOST_PP_EXPAND(x) STREAMS_BOOST_PP_EXPAND_OO((x))
#    define STREAMS_BOOST_PP_EXPAND_OO(par) STREAMS_BOOST_PP_EXPAND_I ## par
# endif
#
# define STREAMS_BOOST_PP_EXPAND_I(x) x
#
# endif
