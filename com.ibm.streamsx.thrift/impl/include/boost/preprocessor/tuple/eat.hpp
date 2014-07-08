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
# ifndef STREAMS_BOOST_PREPROCESSOR_TUPLE_EAT_HPP
# define STREAMS_BOOST_PREPROCESSOR_TUPLE_EAT_HPP
#
# include <streams_boost/preprocessor/config/config.hpp>
#
# /* STREAMS_BOOST_PP_TUPLE_EAT */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_MWCC()
#    define STREAMS_BOOST_PP_TUPLE_EAT(size) STREAMS_BOOST_PP_TUPLE_EAT_I(size)
# else
#    define STREAMS_BOOST_PP_TUPLE_EAT(size) STREAMS_BOOST_PP_TUPLE_EAT_OO((size))
#    define STREAMS_BOOST_PP_TUPLE_EAT_OO(par) STREAMS_BOOST_PP_TUPLE_EAT_I ## par
# endif
#
# define STREAMS_BOOST_PP_TUPLE_EAT_I(size) STREAMS_BOOST_PP_TUPLE_EAT_ ## size
#
# define STREAMS_BOOST_PP_TUPLE_EAT_0()
# define STREAMS_BOOST_PP_TUPLE_EAT_1(a)
# define STREAMS_BOOST_PP_TUPLE_EAT_2(a, b)
# define STREAMS_BOOST_PP_TUPLE_EAT_3(a, b, c)
# define STREAMS_BOOST_PP_TUPLE_EAT_4(a, b, c, d)
# define STREAMS_BOOST_PP_TUPLE_EAT_5(a, b, c, d, e)
# define STREAMS_BOOST_PP_TUPLE_EAT_6(a, b, c, d, e, f)
# define STREAMS_BOOST_PP_TUPLE_EAT_7(a, b, c, d, e, f, g)
# define STREAMS_BOOST_PP_TUPLE_EAT_8(a, b, c, d, e, f, g, h)
# define STREAMS_BOOST_PP_TUPLE_EAT_9(a, b, c, d, e, f, g, h, i)
# define STREAMS_BOOST_PP_TUPLE_EAT_10(a, b, c, d, e, f, g, h, i, j)
# define STREAMS_BOOST_PP_TUPLE_EAT_11(a, b, c, d, e, f, g, h, i, j, k)
# define STREAMS_BOOST_PP_TUPLE_EAT_12(a, b, c, d, e, f, g, h, i, j, k, l)
# define STREAMS_BOOST_PP_TUPLE_EAT_13(a, b, c, d, e, f, g, h, i, j, k, l, m)
# define STREAMS_BOOST_PP_TUPLE_EAT_14(a, b, c, d, e, f, g, h, i, j, k, l, m, n)
# define STREAMS_BOOST_PP_TUPLE_EAT_15(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o)
# define STREAMS_BOOST_PP_TUPLE_EAT_16(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p)
# define STREAMS_BOOST_PP_TUPLE_EAT_17(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q)
# define STREAMS_BOOST_PP_TUPLE_EAT_18(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r)
# define STREAMS_BOOST_PP_TUPLE_EAT_19(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s)
# define STREAMS_BOOST_PP_TUPLE_EAT_20(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t)
# define STREAMS_BOOST_PP_TUPLE_EAT_21(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u)
# define STREAMS_BOOST_PP_TUPLE_EAT_22(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v)
# define STREAMS_BOOST_PP_TUPLE_EAT_23(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w)
# define STREAMS_BOOST_PP_TUPLE_EAT_24(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x)
# define STREAMS_BOOST_PP_TUPLE_EAT_25(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y)
#
# endif
