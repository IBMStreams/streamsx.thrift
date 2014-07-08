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
# ifndef STREAMS_BOOST_PREPROCESSOR_CAT_HPP
# define STREAMS_BOOST_PREPROCESSOR_CAT_HPP
#
# include <streams_boost/preprocessor/config/config.hpp>
#
# /* STREAMS_BOOST_PP_CAT */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_MWCC()
#    define STREAMS_BOOST_PP_CAT(a, b) STREAMS_BOOST_PP_CAT_I(a, b)
# else
#    define STREAMS_BOOST_PP_CAT(a, b) STREAMS_BOOST_PP_CAT_OO((a, b))
#    define STREAMS_BOOST_PP_CAT_OO(par) STREAMS_BOOST_PP_CAT_I ## par
# endif
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_MSVC()
#    define STREAMS_BOOST_PP_CAT_I(a, b) a ## b
# else
#    define STREAMS_BOOST_PP_CAT_I(a, b) STREAMS_BOOST_PP_CAT_II(a ## b)
#    define STREAMS_BOOST_PP_CAT_II(res) res
# endif
#
# endif
