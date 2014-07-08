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
# ifndef STREAMS_BOOST_PREPROCESSOR_LIST_ENUM_HPP
# define STREAMS_BOOST_PREPROCESSOR_LIST_ENUM_HPP
#
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/list/for_each_i.hpp>
# include <streams_boost/preprocessor/punctuation/comma_if.hpp>
#
# /* STREAMS_BOOST_PP_LIST_ENUM */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_LIST_ENUM(list) STREAMS_BOOST_PP_LIST_FOR_EACH_I(STREAMS_BOOST_PP_LIST_ENUM_O, STREAMS_BOOST_PP_NIL, list)
# else
#    define STREAMS_BOOST_PP_LIST_ENUM(list) STREAMS_BOOST_PP_LIST_ENUM_I(list)
#    define STREAMS_BOOST_PP_LIST_ENUM_I(list) STREAMS_BOOST_PP_LIST_FOR_EACH_I(STREAMS_BOOST_PP_LIST_ENUM_O, STREAMS_BOOST_PP_NIL, list)
# endif
#
# define STREAMS_BOOST_PP_LIST_ENUM_O(r, _, i, elem) STREAMS_BOOST_PP_COMMA_IF(i) elem
#
# /* STREAMS_BOOST_PP_LIST_ENUM_R */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_LIST_ENUM_R(r, list) STREAMS_BOOST_PP_LIST_FOR_EACH_I_R(r, STREAMS_BOOST_PP_LIST_ENUM_O, STREAMS_BOOST_PP_NIL, list)
# else
#    define STREAMS_BOOST_PP_LIST_ENUM_R(r, list) STREAMS_BOOST_PP_LIST_ENUM_R_I(r, list)
#    define STREAMS_BOOST_PP_LIST_ENUM_R_I(r, list) STREAMS_BOOST_PP_LIST_FOR_EACH_I_R(r, STREAMS_BOOST_PP_LIST_ENUM_O, STREAMS_BOOST_PP_NIL, list)
# endif
#
# endif
