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
# ifndef STREAMS_BOOST_PREPROCESSOR_LIST_APPEND_HPP
# define STREAMS_BOOST_PREPROCESSOR_LIST_APPEND_HPP
#
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/list/fold_right.hpp>
#
# /* STREAMS_BOOST_PP_LIST_APPEND */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_LIST_APPEND(a, b) STREAMS_BOOST_PP_LIST_FOLD_RIGHT(STREAMS_BOOST_PP_LIST_APPEND_O, b, a)
# else
#    define STREAMS_BOOST_PP_LIST_APPEND(a, b) STREAMS_BOOST_PP_LIST_APPEND_I(a, b)
#    define STREAMS_BOOST_PP_LIST_APPEND_I(a, b) STREAMS_BOOST_PP_LIST_FOLD_RIGHT(STREAMS_BOOST_PP_LIST_APPEND_O, b, a)
# endif
#
# define STREAMS_BOOST_PP_LIST_APPEND_O(d, s, x) (x, s)
#
# /* STREAMS_BOOST_PP_LIST_APPEND_D */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_LIST_APPEND_D(d, a, b) STREAMS_BOOST_PP_LIST_FOLD_RIGHT_ ## d(STREAMS_BOOST_PP_LIST_APPEND_O, b, a)
# else
#    define STREAMS_BOOST_PP_LIST_APPEND_D(d, a, b) STREAMS_BOOST_PP_LIST_APPEND_D_I(d, a, b)
#    define STREAMS_BOOST_PP_LIST_APPEND_D_I(d, a, b) STREAMS_BOOST_PP_LIST_FOLD_RIGHT_ ## d(STREAMS_BOOST_PP_LIST_APPEND_O, b, a)
# endif
#
# endif
