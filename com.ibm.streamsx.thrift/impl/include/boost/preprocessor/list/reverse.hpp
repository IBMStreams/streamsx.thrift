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
# ifndef STREAMS_BOOST_PREPROCESSOR_LIST_REVERSE_HPP
# define STREAMS_BOOST_PREPROCESSOR_LIST_REVERSE_HPP
#
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/list/fold_left.hpp>
#
# /* STREAMS_BOOST_PP_LIST_REVERSE */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_LIST_REVERSE(list) STREAMS_BOOST_PP_LIST_FOLD_LEFT(STREAMS_BOOST_PP_LIST_REVERSE_O, STREAMS_BOOST_PP_NIL, list)
# else
#    define STREAMS_BOOST_PP_LIST_REVERSE(list) STREAMS_BOOST_PP_LIST_REVERSE_I(list)
#    define STREAMS_BOOST_PP_LIST_REVERSE_I(list) STREAMS_BOOST_PP_LIST_FOLD_LEFT(STREAMS_BOOST_PP_LIST_REVERSE_O, STREAMS_BOOST_PP_NIL, list)
# endif
#
# define STREAMS_BOOST_PP_LIST_REVERSE_O(d, s, x) (x, s)
#
# /* STREAMS_BOOST_PP_LIST_REVERSE_D */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_LIST_REVERSE_D(d, list) STREAMS_BOOST_PP_LIST_FOLD_LEFT_ ## d(STREAMS_BOOST_PP_LIST_REVERSE_O, STREAMS_BOOST_PP_NIL, list)
# else
#    define STREAMS_BOOST_PP_LIST_REVERSE_D(d, list) STREAMS_BOOST_PP_LIST_REVERSE_D_I(d, list)
#    define STREAMS_BOOST_PP_LIST_REVERSE_D_I(d, list) STREAMS_BOOST_PP_LIST_FOLD_LEFT_ ## d(STREAMS_BOOST_PP_LIST_REVERSE_O, STREAMS_BOOST_PP_NIL, list)
# endif
#
# endif
