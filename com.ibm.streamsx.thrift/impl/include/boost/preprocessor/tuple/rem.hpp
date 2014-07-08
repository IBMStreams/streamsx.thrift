# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Paul Mensonides 2002.
#  *     Distributed under the Boost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.streams_boost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.streams_boost.org for most recent version. */
#
# ifndef STREAMS_BOOST_PREPROCESSOR_TUPLE_REM_HPP
# define STREAMS_BOOST_PREPROCESSOR_TUPLE_REM_HPP
#
# include <streams_boost/preprocessor/config/config.hpp>
#
# /* STREAMS_BOOST_PP_TUPLE_REM */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_MWCC()
#    define STREAMS_BOOST_PP_TUPLE_REM(size) STREAMS_BOOST_PP_TUPLE_REM_I(size)
# else
#    define STREAMS_BOOST_PP_TUPLE_REM(size) STREAMS_BOOST_PP_TUPLE_REM_OO((size))
#    define STREAMS_BOOST_PP_TUPLE_REM_OO(par) STREAMS_BOOST_PP_TUPLE_REM_I ## par
# endif
#
# define STREAMS_BOOST_PP_TUPLE_REM_I(size) STREAMS_BOOST_PP_TUPLE_REM_ ## size
#
# define STREAMS_BOOST_PP_TUPLE_REM_0()
# define STREAMS_BOOST_PP_TUPLE_REM_1(a) a
# define STREAMS_BOOST_PP_TUPLE_REM_2(a, b) a, b
# define STREAMS_BOOST_PP_TUPLE_REM_3(a, b, c) a, b, c
# define STREAMS_BOOST_PP_TUPLE_REM_4(a, b, c, d) a, b, c, d
# define STREAMS_BOOST_PP_TUPLE_REM_5(a, b, c, d, e) a, b, c, d, e
# define STREAMS_BOOST_PP_TUPLE_REM_6(a, b, c, d, e, f) a, b, c, d, e, f
# define STREAMS_BOOST_PP_TUPLE_REM_7(a, b, c, d, e, f, g) a, b, c, d, e, f, g
# define STREAMS_BOOST_PP_TUPLE_REM_8(a, b, c, d, e, f, g, h) a, b, c, d, e, f, g, h
# define STREAMS_BOOST_PP_TUPLE_REM_9(a, b, c, d, e, f, g, h, i) a, b, c, d, e, f, g, h, i
# define STREAMS_BOOST_PP_TUPLE_REM_10(a, b, c, d, e, f, g, h, i, j) a, b, c, d, e, f, g, h, i, j
# define STREAMS_BOOST_PP_TUPLE_REM_11(a, b, c, d, e, f, g, h, i, j, k) a, b, c, d, e, f, g, h, i, j, k
# define STREAMS_BOOST_PP_TUPLE_REM_12(a, b, c, d, e, f, g, h, i, j, k, l) a, b, c, d, e, f, g, h, i, j, k, l
# define STREAMS_BOOST_PP_TUPLE_REM_13(a, b, c, d, e, f, g, h, i, j, k, l, m) a, b, c, d, e, f, g, h, i, j, k, l, m
# define STREAMS_BOOST_PP_TUPLE_REM_14(a, b, c, d, e, f, g, h, i, j, k, l, m, n) a, b, c, d, e, f, g, h, i, j, k, l, m, n
# define STREAMS_BOOST_PP_TUPLE_REM_15(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o) a, b, c, d, e, f, g, h, i, j, k, l, m, n, o
# define STREAMS_BOOST_PP_TUPLE_REM_16(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p
# define STREAMS_BOOST_PP_TUPLE_REM_17(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q) a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q
# define STREAMS_BOOST_PP_TUPLE_REM_18(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r
# define STREAMS_BOOST_PP_TUPLE_REM_19(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s
# define STREAMS_BOOST_PP_TUPLE_REM_20(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t
# define STREAMS_BOOST_PP_TUPLE_REM_21(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u
# define STREAMS_BOOST_PP_TUPLE_REM_22(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v
# define STREAMS_BOOST_PP_TUPLE_REM_23(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w
# define STREAMS_BOOST_PP_TUPLE_REM_24(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x
# define STREAMS_BOOST_PP_TUPLE_REM_25(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y
#
# /* STREAMS_BOOST_PP_TUPLE_REM_CTOR */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_TUPLE_REM_CTOR(size, tuple) STREAMS_BOOST_PP_TUPLE_REM_CTOR_I(STREAMS_BOOST_PP_TUPLE_REM(size), tuple)
# else
#    define STREAMS_BOOST_PP_TUPLE_REM_CTOR(size, tuple) STREAMS_BOOST_PP_TUPLE_REM_CTOR_D(size, tuple)
#    define STREAMS_BOOST_PP_TUPLE_REM_CTOR_D(size, tuple) STREAMS_BOOST_PP_TUPLE_REM_CTOR_I(STREAMS_BOOST_PP_TUPLE_REM(size), tuple)
# endif
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_MWCC()
#    define STREAMS_BOOST_PP_TUPLE_REM_CTOR_I(ext, tuple) ext tuple
# else
#    define STREAMS_BOOST_PP_TUPLE_REM_CTOR_I(ext, tuple) STREAMS_BOOST_PP_TUPLE_REM_CTOR_OO((ext, tuple))
#    define STREAMS_BOOST_PP_TUPLE_REM_CTOR_OO(par) STREAMS_BOOST_PP_TUPLE_REM_CTOR_II ## par
#    define STREAMS_BOOST_PP_TUPLE_REM_CTOR_II(ext, tuple) ext ## tuple
# endif
#
# endif
