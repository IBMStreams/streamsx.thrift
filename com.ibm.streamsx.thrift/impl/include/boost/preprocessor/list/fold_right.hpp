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
# ifndef STREAMS_BOOST_PREPROCESSOR_LIST_FOLD_RIGHT_HPP
# define STREAMS_BOOST_PREPROCESSOR_LIST_FOLD_RIGHT_HPP
#
# include <streams_boost/preprocessor/cat.hpp>
# include <streams_boost/preprocessor/control/while.hpp>
# include <streams_boost/preprocessor/debug/error.hpp>
# include <streams_boost/preprocessor/detail/auto_rec.hpp>
#
# if 0
#    define STREAMS_BOOST_PP_LIST_FOLD_RIGHT(op, state, list)
# endif
#
# define STREAMS_BOOST_PP_LIST_FOLD_RIGHT STREAMS_BOOST_PP_CAT(STREAMS_BOOST_PP_LIST_FOLD_RIGHT_, STREAMS_BOOST_PP_AUTO_REC(STREAMS_BOOST_PP_WHILE_P, 256))
#
# define STREAMS_BOOST_PP_LIST_FOLD_RIGHT_257(o, s, l) STREAMS_BOOST_PP_ERROR(0x0004)
#
# define STREAMS_BOOST_PP_LIST_FOLD_RIGHT_D(d, o, s, l) STREAMS_BOOST_PP_LIST_FOLD_RIGHT_ ## d(o, s, l)
# define STREAMS_BOOST_PP_LIST_FOLD_RIGHT_2ND STREAMS_BOOST_PP_LIST_FOLD_RIGHT
# define STREAMS_BOOST_PP_LIST_FOLD_RIGHT_2ND_D STREAMS_BOOST_PP_LIST_FOLD_RIGHT_D
#
# if STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    include <streams_boost/preprocessor/list/detail/edg/fold_right.hpp>
# else
#    include <streams_boost/preprocessor/list/detail/fold_right.hpp>
# endif
#
# endif
