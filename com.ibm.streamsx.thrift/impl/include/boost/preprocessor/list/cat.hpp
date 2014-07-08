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
# ifndef STREAMS_BOOST_PREPROCESSOR_LIST_CAT_HPP
# define STREAMS_BOOST_PREPROCESSOR_LIST_CAT_HPP
#
# include <streams_boost/preprocessor/cat.hpp>
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/list/adt.hpp>
# include <streams_boost/preprocessor/list/fold_left.hpp>
#
# /* STREAMS_BOOST_PP_LIST_CAT */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_LIST_CAT(list) STREAMS_BOOST_PP_LIST_FOLD_LEFT(STREAMS_BOOST_PP_LIST_CAT_O, STREAMS_BOOST_PP_LIST_FIRST(list), STREAMS_BOOST_PP_LIST_REST(list))
# else
#    define STREAMS_BOOST_PP_LIST_CAT(list) STREAMS_BOOST_PP_LIST_CAT_I(list)
#    define STREAMS_BOOST_PP_LIST_CAT_I(list) STREAMS_BOOST_PP_LIST_FOLD_LEFT(STREAMS_BOOST_PP_LIST_CAT_O, STREAMS_BOOST_PP_LIST_FIRST(list), STREAMS_BOOST_PP_LIST_REST(list))
# endif
#
# define STREAMS_BOOST_PP_LIST_CAT_O(d, s, x) STREAMS_BOOST_PP_CAT(s, x)
#
# /* STREAMS_BOOST_PP_LIST_CAT_D */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_LIST_CAT_D(d, list) STREAMS_BOOST_PP_LIST_FOLD_LEFT_ ## d(STREAMS_BOOST_PP_LIST_CAT_O, STREAMS_BOOST_PP_LIST_FIRST(list), STREAMS_BOOST_PP_LIST_REST(list))
# else
#    define STREAMS_BOOST_PP_LIST_CAT_D(d, list) STREAMS_BOOST_PP_LIST_CAT_D_I(d, list)
#    define STREAMS_BOOST_PP_LIST_CAT_D_I(d, list) STREAMS_BOOST_PP_LIST_FOLD_LEFT_ ## d(STREAMS_BOOST_PP_LIST_CAT_O, STREAMS_BOOST_PP_LIST_FIRST(list), STREAMS_BOOST_PP_LIST_REST(list))
# endif
#
# endif
