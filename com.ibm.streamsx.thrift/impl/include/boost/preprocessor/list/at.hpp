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
# ifndef STREAMS_BOOST_PREPROCESSOR_LIST_AT_HPP
# define STREAMS_BOOST_PREPROCESSOR_LIST_AT_HPP
#
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/list/adt.hpp>
# include <streams_boost/preprocessor/list/rest_n.hpp>
#
# /* STREAMS_BOOST_PP_LIST_AT */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_LIST_AT(list, index) STREAMS_BOOST_PP_LIST_FIRST(STREAMS_BOOST_PP_LIST_REST_N(index, list))
# else
#    define STREAMS_BOOST_PP_LIST_AT(list, index) STREAMS_BOOST_PP_LIST_AT_I(list, index)
#    define STREAMS_BOOST_PP_LIST_AT_I(list, index) STREAMS_BOOST_PP_LIST_FIRST(STREAMS_BOOST_PP_LIST_REST_N(index, list))
# endif
#
# /* STREAMS_BOOST_PP_LIST_AT_D */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_LIST_AT_D(d, list, index) STREAMS_BOOST_PP_LIST_FIRST(STREAMS_BOOST_PP_LIST_REST_N_D(d, index, list))
# else
#    define STREAMS_BOOST_PP_LIST_AT_D(d, list, index) STREAMS_BOOST_PP_LIST_AT_D_I(d, list, index)
#    define STREAMS_BOOST_PP_LIST_AT_D_I(d, list, index) STREAMS_BOOST_PP_LIST_FIRST(STREAMS_BOOST_PP_LIST_REST_N_D(d, index, list))
# endif
#
# endif
