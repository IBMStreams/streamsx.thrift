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
# ifndef STREAMS_BOOST_PREPROCESSOR_REPETITION_REPEAT_FROM_TO_HPP
# define STREAMS_BOOST_PREPROCESSOR_REPETITION_REPEAT_FROM_TO_HPP
#
# include <streams_boost/preprocessor/arithmetic/add.hpp>
# include <streams_boost/preprocessor/arithmetic/sub.hpp>
# include <streams_boost/preprocessor/cat.hpp>
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/control/while.hpp>
# include <streams_boost/preprocessor/debug/error.hpp>
# include <streams_boost/preprocessor/detail/auto_rec.hpp>
# include <streams_boost/preprocessor/repetition/repeat.hpp>
# include <streams_boost/preprocessor/tuple/elem.hpp>
# include <streams_boost/preprocessor/tuple/rem.hpp>
#
# /* STREAMS_BOOST_PP_REPEAT_FROM_TO */
#
# if 0
#    define STREAMS_BOOST_PP_REPEAT_FROM_TO(first, last, macro, data)
# endif
#
# define STREAMS_BOOST_PP_REPEAT_FROM_TO STREAMS_BOOST_PP_CAT(STREAMS_BOOST_PP_REPEAT_FROM_TO_, STREAMS_BOOST_PP_AUTO_REC(STREAMS_BOOST_PP_REPEAT_P, 4))
#
# define STREAMS_BOOST_PP_REPEAT_FROM_TO_1(f, l, m, dt) STREAMS_BOOST_PP_REPEAT_FROM_TO_D_1(STREAMS_BOOST_PP_AUTO_REC(STREAMS_BOOST_PP_WHILE_P, 256), f, l, m, dt)
# define STREAMS_BOOST_PP_REPEAT_FROM_TO_2(f, l, m, dt) STREAMS_BOOST_PP_REPEAT_FROM_TO_D_2(STREAMS_BOOST_PP_AUTO_REC(STREAMS_BOOST_PP_WHILE_P, 256), f, l, m, dt)
# define STREAMS_BOOST_PP_REPEAT_FROM_TO_3(f, l, m, dt) STREAMS_BOOST_PP_REPEAT_FROM_TO_D_3(STREAMS_BOOST_PP_AUTO_REC(STREAMS_BOOST_PP_WHILE_P, 256), f, l, m, dt)
# define STREAMS_BOOST_PP_REPEAT_FROM_TO_4(f, l, m, dt) STREAMS_BOOST_PP_ERROR(0x0003)
#
# define STREAMS_BOOST_PP_REPEAT_FROM_TO_1ST STREAMS_BOOST_PP_REPEAT_FROM_TO_1
# define STREAMS_BOOST_PP_REPEAT_FROM_TO_2ND STREAMS_BOOST_PP_REPEAT_FROM_TO_2
# define STREAMS_BOOST_PP_REPEAT_FROM_TO_3RD STREAMS_BOOST_PP_REPEAT_FROM_TO_3
#
# /* STREAMS_BOOST_PP_REPEAT_FROM_TO_D */
#
# if 0
#    define STREAMS_BOOST_PP_REPEAT_FROM_TO_D(d, first, last, macro, data)
# endif
#
# define STREAMS_BOOST_PP_REPEAT_FROM_TO_D STREAMS_BOOST_PP_CAT(STREAMS_BOOST_PP_REPEAT_FROM_TO_D_, STREAMS_BOOST_PP_AUTO_REC(STREAMS_BOOST_PP_REPEAT_P, 4))
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_REPEAT_FROM_TO_D_1(d, f, l, m, dt) STREAMS_BOOST_PP_REPEAT_1(STREAMS_BOOST_PP_SUB_D(d, l, f), STREAMS_BOOST_PP_REPEAT_FROM_TO_M_1, (d, f, m, dt))
#    define STREAMS_BOOST_PP_REPEAT_FROM_TO_D_2(d, f, l, m, dt) STREAMS_BOOST_PP_REPEAT_2(STREAMS_BOOST_PP_SUB_D(d, l, f), STREAMS_BOOST_PP_REPEAT_FROM_TO_M_2, (d, f, m, dt))
#    define STREAMS_BOOST_PP_REPEAT_FROM_TO_D_3(d, f, l, m, dt) STREAMS_BOOST_PP_REPEAT_3(STREAMS_BOOST_PP_SUB_D(d, l, f), STREAMS_BOOST_PP_REPEAT_FROM_TO_M_3, (d, f, m, dt))
# else
#    define STREAMS_BOOST_PP_REPEAT_FROM_TO_D_1(d, f, l, m, dt) STREAMS_BOOST_PP_REPEAT_FROM_TO_D_1_I(d, f, l, m, dt)
#    define STREAMS_BOOST_PP_REPEAT_FROM_TO_D_2(d, f, l, m, dt) STREAMS_BOOST_PP_REPEAT_FROM_TO_D_2_I(d, f, l, m, dt)
#    define STREAMS_BOOST_PP_REPEAT_FROM_TO_D_3(d, f, l, m, dt) STREAMS_BOOST_PP_REPEAT_FROM_TO_D_3_I(d, f, l, m, dt)
#    define STREAMS_BOOST_PP_REPEAT_FROM_TO_D_1_I(d, f, l, m, dt) STREAMS_BOOST_PP_REPEAT_1(STREAMS_BOOST_PP_SUB_D(d, l, f), STREAMS_BOOST_PP_REPEAT_FROM_TO_M_1, (d, f, m, dt))
#    define STREAMS_BOOST_PP_REPEAT_FROM_TO_D_2_I(d, f, l, m, dt) STREAMS_BOOST_PP_REPEAT_2(STREAMS_BOOST_PP_SUB_D(d, l, f), STREAMS_BOOST_PP_REPEAT_FROM_TO_M_2, (d, f, m, dt))
#    define STREAMS_BOOST_PP_REPEAT_FROM_TO_D_3_I(d, f, l, m, dt) STREAMS_BOOST_PP_REPEAT_3(STREAMS_BOOST_PP_SUB_D(d, l, f), STREAMS_BOOST_PP_REPEAT_FROM_TO_M_3, (d, f, m, dt))
# endif
#
# if STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_STRICT()
#    define STREAMS_BOOST_PP_REPEAT_FROM_TO_M_1(z, n, dfmd) STREAMS_BOOST_PP_REPEAT_FROM_TO_M_1_IM(z, n, STREAMS_BOOST_PP_TUPLE_REM_4 dfmd)
#    define STREAMS_BOOST_PP_REPEAT_FROM_TO_M_2(z, n, dfmd) STREAMS_BOOST_PP_REPEAT_FROM_TO_M_2_IM(z, n, STREAMS_BOOST_PP_TUPLE_REM_4 dfmd)
#    define STREAMS_BOOST_PP_REPEAT_FROM_TO_M_3(z, n, dfmd) STREAMS_BOOST_PP_REPEAT_FROM_TO_M_3_IM(z, n, STREAMS_BOOST_PP_TUPLE_REM_4 dfmd)
#    define STREAMS_BOOST_PP_REPEAT_FROM_TO_M_1_IM(z, n, im) STREAMS_BOOST_PP_REPEAT_FROM_TO_M_1_I(z, n, im)
#    define STREAMS_BOOST_PP_REPEAT_FROM_TO_M_2_IM(z, n, im) STREAMS_BOOST_PP_REPEAT_FROM_TO_M_2_I(z, n, im)
#    define STREAMS_BOOST_PP_REPEAT_FROM_TO_M_3_IM(z, n, im) STREAMS_BOOST_PP_REPEAT_FROM_TO_M_3_I(z, n, im)
# else
#    define STREAMS_BOOST_PP_REPEAT_FROM_TO_M_1(z, n, dfmd) STREAMS_BOOST_PP_REPEAT_FROM_TO_M_1_I(z, n, STREAMS_BOOST_PP_TUPLE_ELEM(4, 0, dfmd), STREAMS_BOOST_PP_TUPLE_ELEM(4, 1, dfmd), STREAMS_BOOST_PP_TUPLE_ELEM(4, 2, dfmd), STREAMS_BOOST_PP_TUPLE_ELEM(4, 3, dfmd))
#    define STREAMS_BOOST_PP_REPEAT_FROM_TO_M_2(z, n, dfmd) STREAMS_BOOST_PP_REPEAT_FROM_TO_M_2_I(z, n, STREAMS_BOOST_PP_TUPLE_ELEM(4, 0, dfmd), STREAMS_BOOST_PP_TUPLE_ELEM(4, 1, dfmd), STREAMS_BOOST_PP_TUPLE_ELEM(4, 2, dfmd), STREAMS_BOOST_PP_TUPLE_ELEM(4, 3, dfmd))
#    define STREAMS_BOOST_PP_REPEAT_FROM_TO_M_3(z, n, dfmd) STREAMS_BOOST_PP_REPEAT_FROM_TO_M_3_I(z, n, STREAMS_BOOST_PP_TUPLE_ELEM(4, 0, dfmd), STREAMS_BOOST_PP_TUPLE_ELEM(4, 1, dfmd), STREAMS_BOOST_PP_TUPLE_ELEM(4, 2, dfmd), STREAMS_BOOST_PP_TUPLE_ELEM(4, 3, dfmd))
# endif
#
# define STREAMS_BOOST_PP_REPEAT_FROM_TO_M_1_I(z, n, d, f, m, dt) STREAMS_BOOST_PP_REPEAT_FROM_TO_M_1_II(z, STREAMS_BOOST_PP_ADD_D(d, n, f), m, dt)
# define STREAMS_BOOST_PP_REPEAT_FROM_TO_M_2_I(z, n, d, f, m, dt) STREAMS_BOOST_PP_REPEAT_FROM_TO_M_2_II(z, STREAMS_BOOST_PP_ADD_D(d, n, f), m, dt)
# define STREAMS_BOOST_PP_REPEAT_FROM_TO_M_3_I(z, n, d, f, m, dt) STREAMS_BOOST_PP_REPEAT_FROM_TO_M_3_II(z, STREAMS_BOOST_PP_ADD_D(d, n, f), m, dt)
#
# define STREAMS_BOOST_PP_REPEAT_FROM_TO_M_1_II(z, n, m, dt) m(z, n, dt)
# define STREAMS_BOOST_PP_REPEAT_FROM_TO_M_2_II(z, n, m, dt) m(z, n, dt)
# define STREAMS_BOOST_PP_REPEAT_FROM_TO_M_3_II(z, n, m, dt) m(z, n, dt)
#
# endif
