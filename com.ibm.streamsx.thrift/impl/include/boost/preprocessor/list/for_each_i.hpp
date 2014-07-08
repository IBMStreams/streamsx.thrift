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
# ifndef STREAMS_BOOST_PREPROCESSOR_LIST_LIST_FOR_EACH_I_HPP
# define STREAMS_BOOST_PREPROCESSOR_LIST_LIST_FOR_EACH_I_HPP
#
# include <streams_boost/preprocessor/arithmetic/inc.hpp>
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/list/adt.hpp>
# include <streams_boost/preprocessor/repetition/for.hpp>
# include <streams_boost/preprocessor/tuple/elem.hpp>
# include <streams_boost/preprocessor/tuple/rem.hpp>
#
# /* STREAMS_BOOST_PP_LIST_FOR_EACH_I */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG() && ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_MSVC()
#    define STREAMS_BOOST_PP_LIST_FOR_EACH_I(macro, data, list) STREAMS_BOOST_PP_FOR((macro, data, list, 0), STREAMS_BOOST_PP_LIST_FOR_EACH_I_P, STREAMS_BOOST_PP_LIST_FOR_EACH_I_O, STREAMS_BOOST_PP_LIST_FOR_EACH_I_M)
# else
#    define STREAMS_BOOST_PP_LIST_FOR_EACH_I(macro, data, list) STREAMS_BOOST_PP_LIST_FOR_EACH_I_I(macro, data, list)
#    define STREAMS_BOOST_PP_LIST_FOR_EACH_I_I(macro, data, list) STREAMS_BOOST_PP_FOR((macro, data, list, 0), STREAMS_BOOST_PP_LIST_FOR_EACH_I_P, STREAMS_BOOST_PP_LIST_FOR_EACH_I_O, STREAMS_BOOST_PP_LIST_FOR_EACH_I_M)
# endif
#
# if STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_STRICT()
#    define STREAMS_BOOST_PP_LIST_FOR_EACH_I_P(r, x) STREAMS_BOOST_PP_LIST_FOR_EACH_I_P_D x
#    define STREAMS_BOOST_PP_LIST_FOR_EACH_I_P_D(m, d, l, i) STREAMS_BOOST_PP_LIST_IS_CONS(l)
# else
#    define STREAMS_BOOST_PP_LIST_FOR_EACH_I_P(r, x) STREAMS_BOOST_PP_LIST_IS_CONS(STREAMS_BOOST_PP_TUPLE_ELEM(4, 2, x))
# endif
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_MWCC()
#    define STREAMS_BOOST_PP_LIST_FOR_EACH_I_O(r, x) STREAMS_BOOST_PP_LIST_FOR_EACH_I_O_D x
#    define STREAMS_BOOST_PP_LIST_FOR_EACH_I_O_D(m, d, l, i) (m, d, STREAMS_BOOST_PP_LIST_REST(l), STREAMS_BOOST_PP_INC(i))
# else
#    define STREAMS_BOOST_PP_LIST_FOR_EACH_I_O(r, x) (STREAMS_BOOST_PP_TUPLE_ELEM(4, 0, x), STREAMS_BOOST_PP_TUPLE_ELEM(4, 1, x), STREAMS_BOOST_PP_LIST_REST(STREAMS_BOOST_PP_TUPLE_ELEM(4, 2, x)), STREAMS_BOOST_PP_INC(STREAMS_BOOST_PP_TUPLE_ELEM(4, 3, x)))
# endif
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_LIST_FOR_EACH_I_M(r, x) STREAMS_BOOST_PP_LIST_FOR_EACH_I_M_D(r, STREAMS_BOOST_PP_TUPLE_ELEM(4, 0, x), STREAMS_BOOST_PP_TUPLE_ELEM(4, 1, x), STREAMS_BOOST_PP_TUPLE_ELEM(4, 2, x), STREAMS_BOOST_PP_TUPLE_ELEM(4, 3, x))
# else
#    define STREAMS_BOOST_PP_LIST_FOR_EACH_I_M(r, x) STREAMS_BOOST_PP_LIST_FOR_EACH_I_M_I(r, STREAMS_BOOST_PP_TUPLE_REM_4 x)
#    define STREAMS_BOOST_PP_LIST_FOR_EACH_I_M_I(r, x_e) STREAMS_BOOST_PP_LIST_FOR_EACH_I_M_D(r, x_e)
# endif
#
# define STREAMS_BOOST_PP_LIST_FOR_EACH_I_M_D(r, m, d, l, i) m(r, d, i, STREAMS_BOOST_PP_LIST_FIRST(l))
#
# /* STREAMS_BOOST_PP_LIST_FOR_EACH_I_R */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_LIST_FOR_EACH_I_R(r, macro, data, list) STREAMS_BOOST_PP_FOR_ ## r((macro, data, list, 0), STREAMS_BOOST_PP_LIST_FOR_EACH_I_P, STREAMS_BOOST_PP_LIST_FOR_EACH_I_O, STREAMS_BOOST_PP_LIST_FOR_EACH_I_M)
# else
#    define STREAMS_BOOST_PP_LIST_FOR_EACH_I_R(r, macro, data, list) STREAMS_BOOST_PP_LIST_FOR_EACH_I_R_I(r, macro, data, list)
#    define STREAMS_BOOST_PP_LIST_FOR_EACH_I_R_I(r, macro, data, list) STREAMS_BOOST_PP_FOR_ ## r((macro, data, list, 0), STREAMS_BOOST_PP_LIST_FOR_EACH_I_P, STREAMS_BOOST_PP_LIST_FOR_EACH_I_O, STREAMS_BOOST_PP_LIST_FOR_EACH_I_M)
# endif
#
# endif
