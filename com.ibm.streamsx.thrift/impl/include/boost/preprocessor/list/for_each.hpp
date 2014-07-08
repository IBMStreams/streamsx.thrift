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
# ifndef STREAMS_BOOST_PREPROCESSOR_LIST_FOR_EACH_HPP
# define STREAMS_BOOST_PREPROCESSOR_LIST_FOR_EACH_HPP
#
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/list/for_each_i.hpp>
# include <streams_boost/preprocessor/tuple/elem.hpp>
# include <streams_boost/preprocessor/tuple/rem.hpp>
#
# /* STREAMS_BOOST_PP_LIST_FOR_EACH */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_LIST_FOR_EACH(macro, data, list) STREAMS_BOOST_PP_LIST_FOR_EACH_I(STREAMS_BOOST_PP_LIST_FOR_EACH_O, (macro, data), list)
# else
#    define STREAMS_BOOST_PP_LIST_FOR_EACH(macro, data, list) STREAMS_BOOST_PP_LIST_FOR_EACH_X(macro, data, list)
#    define STREAMS_BOOST_PP_LIST_FOR_EACH_X(macro, data, list) STREAMS_BOOST_PP_LIST_FOR_EACH_I(STREAMS_BOOST_PP_LIST_FOR_EACH_O, (macro, data), list)
# endif
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_LIST_FOR_EACH_O(r, md, i, elem) STREAMS_BOOST_PP_LIST_FOR_EACH_O_D(r, STREAMS_BOOST_PP_TUPLE_ELEM(2, 0, md), STREAMS_BOOST_PP_TUPLE_ELEM(2, 1, md), elem)
# else
#    define STREAMS_BOOST_PP_LIST_FOR_EACH_O(r, md, i, elem) STREAMS_BOOST_PP_LIST_FOR_EACH_O_I(r, STREAMS_BOOST_PP_TUPLE_REM_2 md, elem)
#    define STREAMS_BOOST_PP_LIST_FOR_EACH_O_I(r, im, elem) STREAMS_BOOST_PP_LIST_FOR_EACH_O_D(r, im, elem)
# endif
#
# define STREAMS_BOOST_PP_LIST_FOR_EACH_O_D(r, m, d, elem) m(r, d, elem)
#
# /* STREAMS_BOOST_PP_LIST_FOR_EACH_R */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_LIST_FOR_EACH_R(r, macro, data, list) STREAMS_BOOST_PP_LIST_FOR_EACH_I_R(r, STREAMS_BOOST_PP_LIST_FOR_EACH_O, (macro, data), list)
# else
#    define STREAMS_BOOST_PP_LIST_FOR_EACH_R(r, macro, data, list) STREAMS_BOOST_PP_LIST_FOR_EACH_R_X(r, macro, data, list)
#    define STREAMS_BOOST_PP_LIST_FOR_EACH_R_X(r, macro, data, list) STREAMS_BOOST_PP_LIST_FOR_EACH_I_R(r, STREAMS_BOOST_PP_LIST_FOR_EACH_O, (macro, data), list)
# endif
#
# endif
