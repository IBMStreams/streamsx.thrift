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
# ifndef STREAMS_BOOST_PREPROCESSOR_LIST_TO_TUPLE_HPP
# define STREAMS_BOOST_PREPROCESSOR_LIST_TO_TUPLE_HPP
#
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/list/enum.hpp>
#
# /* STREAMS_BOOST_PP_LIST_TO_TUPLE */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_LIST_TO_TUPLE(list) (STREAMS_BOOST_PP_LIST_ENUM(list))
# else
#    define STREAMS_BOOST_PP_LIST_TO_TUPLE(list) STREAMS_BOOST_PP_LIST_TO_TUPLE_I(list)
#    define STREAMS_BOOST_PP_LIST_TO_TUPLE_I(list) (STREAMS_BOOST_PP_LIST_ENUM(list))
# endif
#
# /* STREAMS_BOOST_PP_LIST_TO_TUPLE_R */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_LIST_TO_TUPLE_R(r, list) (STREAMS_BOOST_PP_LIST_ENUM_R(r, list))
# else
#    define STREAMS_BOOST_PP_LIST_TO_TUPLE_R(r, list) STREAMS_BOOST_PP_LIST_TO_TUPLE_R_I(r, list)
#    define STREAMS_BOOST_PP_LIST_TO_TUPLE_R_I(r, list) (STREAMS_BOOST_PP_LIST_ENUM_R(r, list))
# endif
#
# endif
