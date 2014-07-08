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
# ifndef STREAMS_BOOST_PREPROCESSOR_LOGICAL_AND_HPP
# define STREAMS_BOOST_PREPROCESSOR_LOGICAL_AND_HPP
#
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/logical/bool.hpp>
# include <streams_boost/preprocessor/logical/bitand.hpp>
#
# /* STREAMS_BOOST_PP_AND */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_AND(p, q) STREAMS_BOOST_PP_BITAND(STREAMS_BOOST_PP_BOOL(p), STREAMS_BOOST_PP_BOOL(q))
# else
#    define STREAMS_BOOST_PP_AND(p, q) STREAMS_BOOST_PP_AND_I(p, q)
#    define STREAMS_BOOST_PP_AND_I(p, q) STREAMS_BOOST_PP_BITAND(STREAMS_BOOST_PP_BOOL(p), STREAMS_BOOST_PP_BOOL(q))
# endif
#
# endif
