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
# ifndef STREAMS_BOOST_PREPROCESSOR_LOGICAL_OR_HPP
# define STREAMS_BOOST_PREPROCESSOR_LOGICAL_OR_HPP
#
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/logical/bool.hpp>
# include <streams_boost/preprocessor/logical/bitor.hpp>
#
# /* STREAMS_BOOST_PP_OR */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_OR(p, q) STREAMS_BOOST_PP_BITOR(STREAMS_BOOST_PP_BOOL(p), STREAMS_BOOST_PP_BOOL(q))
# else
#    define STREAMS_BOOST_PP_OR(p, q) STREAMS_BOOST_PP_OR_I(p, q)
#    define STREAMS_BOOST_PP_OR_I(p, q) STREAMS_BOOST_PP_BITOR(STREAMS_BOOST_PP_BOOL(p), STREAMS_BOOST_PP_BOOL(q))
# endif
#
# endif
