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
# ifndef STREAMS_BOOST_PREPROCESSOR_TUPLE_ELEM_HPP
# define STREAMS_BOOST_PREPROCESSOR_TUPLE_ELEM_HPP
#
# include <streams_boost/preprocessor/config/config.hpp>
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_MWCC()
#    define STREAMS_BOOST_PP_TUPLE_ELEM(size, index, tuple) STREAMS_BOOST_PP_TUPLE_ELEM_I(size, index, tuple)
# else
#    define STREAMS_BOOST_PP_TUPLE_ELEM(size, index, tuple) STREAMS_BOOST_PP_TUPLE_ELEM_OO((size, index, tuple))
#    define STREAMS_BOOST_PP_TUPLE_ELEM_OO(par) STREAMS_BOOST_PP_TUPLE_ELEM_I ## par
# endif
#
# if STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_MWCC()
#    define STREAMS_BOOST_PP_TUPLE_ELEM_I(s, i, t) STREAMS_BOOST_PP_TUPLE_ELEM_ ## s ## _ ## i ## t
# elif STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_MSVC()
#    define STREAMS_BOOST_PP_TUPLE_ELEM_I(s, i, t) STREAMS_BOOST_PP_TUPLE_ELEM_II(STREAMS_BOOST_PP_TUPLE_ELEM_ ## s ## _ ## i t)
#    define STREAMS_BOOST_PP_TUPLE_ELEM_II(res) res
# else
#    define STREAMS_BOOST_PP_TUPLE_ELEM_I(s, i, t) STREAMS_BOOST_PP_TUPLE_ELEM_ ## s ## _ ## i t
# endif
#
# define STREAMS_BOOST_PP_TUPLE_ELEM_1_0(a) a
#
# define STREAMS_BOOST_PP_TUPLE_ELEM_2_0(a, b) a
# define STREAMS_BOOST_PP_TUPLE_ELEM_2_1(a, b) b
#
# define STREAMS_BOOST_PP_TUPLE_ELEM_3_0(a, b, c) a
# define STREAMS_BOOST_PP_TUPLE_ELEM_3_1(a, b, c) b
# define STREAMS_BOOST_PP_TUPLE_ELEM_3_2(a, b, c) c
#
# define STREAMS_BOOST_PP_TUPLE_ELEM_4_0(a, b, c, d) a
# define STREAMS_BOOST_PP_TUPLE_ELEM_4_1(a, b, c, d) b
# define STREAMS_BOOST_PP_TUPLE_ELEM_4_2(a, b, c, d) c
# define STREAMS_BOOST_PP_TUPLE_ELEM_4_3(a, b, c, d) d
#
# define STREAMS_BOOST_PP_TUPLE_ELEM_5_0(a, b, c, d, e) a
# define STREAMS_BOOST_PP_TUPLE_ELEM_5_1(a, b, c, d, e) b
# define STREAMS_BOOST_PP_TUPLE_ELEM_5_2(a, b, c, d, e) c
# define STREAMS_BOOST_PP_TUPLE_ELEM_5_3(a, b, c, d, e) d
# define STREAMS_BOOST_PP_TUPLE_ELEM_5_4(a, b, c, d, e) e
#
# define STREAMS_BOOST_PP_TUPLE_ELEM_6_0(a, b, c, d, e, f) a
# define STREAMS_BOOST_PP_TUPLE_ELEM_6_1(a, b, c, d, e, f) b
# define STREAMS_BOOST_PP_TUPLE_ELEM_6_2(a, b, c, d, e, f) c
# define STREAMS_BOOST_PP_TUPLE_ELEM_6_3(a, b, c, d, e, f) d
# define STREAMS_BOOST_PP_TUPLE_ELEM_6_4(a, b, c, d, e, f) e
# define STREAMS_BOOST_PP_TUPLE_ELEM_6_5(a, b, c, d, e, f) f
#
# define STREAMS_BOOST_PP_TUPLE_ELEM_7_0(a, b, c, d, e, f, g) a
# define STREAMS_BOOST_PP_TUPLE_ELEM_7_1(a, b, c, d, e, f, g) b
# define STREAMS_BOOST_PP_TUPLE_ELEM_7_2(a, b, c, d, e, f, g) c
# define STREAMS_BOOST_PP_TUPLE_ELEM_7_3(a, b, c, d, e, f, g) d
# define STREAMS_BOOST_PP_TUPLE_ELEM_7_4(a, b, c, d, e, f, g) e
# define STREAMS_BOOST_PP_TUPLE_ELEM_7_5(a, b, c, d, e, f, g) f
# define STREAMS_BOOST_PP_TUPLE_ELEM_7_6(a, b, c, d, e, f, g) g
#
# define STREAMS_BOOST_PP_TUPLE_ELEM_8_0(a, b, c, d, e, f, g, h) a
# define STREAMS_BOOST_PP_TUPLE_ELEM_8_1(a, b, c, d, e, f, g, h) b
# define STREAMS_BOOST_PP_TUPLE_ELEM_8_2(a, b, c, d, e, f, g, h) c
# define STREAMS_BOOST_PP_TUPLE_ELEM_8_3(a, b, c, d, e, f, g, h) d
# define STREAMS_BOOST_PP_TUPLE_ELEM_8_4(a, b, c, d, e, f, g, h) e
# define STREAMS_BOOST_PP_TUPLE_ELEM_8_5(a, b, c, d, e, f, g, h) f
# define STREAMS_BOOST_PP_TUPLE_ELEM_8_6(a, b, c, d, e, f, g, h) g
# define STREAMS_BOOST_PP_TUPLE_ELEM_8_7(a, b, c, d, e, f, g, h) h
#
# define STREAMS_BOOST_PP_TUPLE_ELEM_9_0(a, b, c, d, e, f, g, h, i) a
# define STREAMS_BOOST_PP_TUPLE_ELEM_9_1(a, b, c, d, e, f, g, h, i) b
# define STREAMS_BOOST_PP_TUPLE_ELEM_9_2(a, b, c, d, e, f, g, h, i) c
# define STREAMS_BOOST_PP_TUPLE_ELEM_9_3(a, b, c, d, e, f, g, h, i) d
# define STREAMS_BOOST_PP_TUPLE_ELEM_9_4(a, b, c, d, e, f, g, h, i) e
# define STREAMS_BOOST_PP_TUPLE_ELEM_9_5(a, b, c, d, e, f, g, h, i) f
# define STREAMS_BOOST_PP_TUPLE_ELEM_9_6(a, b, c, d, e, f, g, h, i) g
# define STREAMS_BOOST_PP_TUPLE_ELEM_9_7(a, b, c, d, e, f, g, h, i) h
# define STREAMS_BOOST_PP_TUPLE_ELEM_9_8(a, b, c, d, e, f, g, h, i) i
#
# define STREAMS_BOOST_PP_TUPLE_ELEM_10_0(a, b, c, d, e, f, g, h, i, j) a
# define STREAMS_BOOST_PP_TUPLE_ELEM_10_1(a, b, c, d, e, f, g, h, i, j) b
# define STREAMS_BOOST_PP_TUPLE_ELEM_10_2(a, b, c, d, e, f, g, h, i, j) c
# define STREAMS_BOOST_PP_TUPLE_ELEM_10_3(a, b, c, d, e, f, g, h, i, j) d
# define STREAMS_BOOST_PP_TUPLE_ELEM_10_4(a, b, c, d, e, f, g, h, i, j) e
# define STREAMS_BOOST_PP_TUPLE_ELEM_10_5(a, b, c, d, e, f, g, h, i, j) f
# define STREAMS_BOOST_PP_TUPLE_ELEM_10_6(a, b, c, d, e, f, g, h, i, j) g
# define STREAMS_BOOST_PP_TUPLE_ELEM_10_7(a, b, c, d, e, f, g, h, i, j) h
# define STREAMS_BOOST_PP_TUPLE_ELEM_10_8(a, b, c, d, e, f, g, h, i, j) i
# define STREAMS_BOOST_PP_TUPLE_ELEM_10_9(a, b, c, d, e, f, g, h, i, j) j
#
# define STREAMS_BOOST_PP_TUPLE_ELEM_11_0(a, b, c, d, e, f, g, h, i, j, k) a
# define STREAMS_BOOST_PP_TUPLE_ELEM_11_1(a, b, c, d, e, f, g, h, i, j, k) b
# define STREAMS_BOOST_PP_TUPLE_ELEM_11_2(a, b, c, d, e, f, g, h, i, j, k) c
# define STREAMS_BOOST_PP_TUPLE_ELEM_11_3(a, b, c, d, e, f, g, h, i, j, k) d
# define STREAMS_BOOST_PP_TUPLE_ELEM_11_4(a, b, c, d, e, f, g, h, i, j, k) e
# define STREAMS_BOOST_PP_TUPLE_ELEM_11_5(a, b, c, d, e, f, g, h, i, j, k) f
# define STREAMS_BOOST_PP_TUPLE_ELEM_11_6(a, b, c, d, e, f, g, h, i, j, k) g
# define STREAMS_BOOST_PP_TUPLE_ELEM_11_7(a, b, c, d, e, f, g, h, i, j, k) h
# define STREAMS_BOOST_PP_TUPLE_ELEM_11_8(a, b, c, d, e, f, g, h, i, j, k) i
# define STREAMS_BOOST_PP_TUPLE_ELEM_11_9(a, b, c, d, e, f, g, h, i, j, k) j
# define STREAMS_BOOST_PP_TUPLE_ELEM_11_10(a, b, c, d, e, f, g, h, i, j, k) k
#
# define STREAMS_BOOST_PP_TUPLE_ELEM_12_0(a, b, c, d, e, f, g, h, i, j, k, l) a
# define STREAMS_BOOST_PP_TUPLE_ELEM_12_1(a, b, c, d, e, f, g, h, i, j, k, l) b
# define STREAMS_BOOST_PP_TUPLE_ELEM_12_2(a, b, c, d, e, f, g, h, i, j, k, l) c
# define STREAMS_BOOST_PP_TUPLE_ELEM_12_3(a, b, c, d, e, f, g, h, i, j, k, l) d
# define STREAMS_BOOST_PP_TUPLE_ELEM_12_4(a, b, c, d, e, f, g, h, i, j, k, l) e
# define STREAMS_BOOST_PP_TUPLE_ELEM_12_5(a, b, c, d, e, f, g, h, i, j, k, l) f
# define STREAMS_BOOST_PP_TUPLE_ELEM_12_6(a, b, c, d, e, f, g, h, i, j, k, l) g
# define STREAMS_BOOST_PP_TUPLE_ELEM_12_7(a, b, c, d, e, f, g, h, i, j, k, l) h
# define STREAMS_BOOST_PP_TUPLE_ELEM_12_8(a, b, c, d, e, f, g, h, i, j, k, l) i
# define STREAMS_BOOST_PP_TUPLE_ELEM_12_9(a, b, c, d, e, f, g, h, i, j, k, l) j
# define STREAMS_BOOST_PP_TUPLE_ELEM_12_10(a, b, c, d, e, f, g, h, i, j, k, l) k
# define STREAMS_BOOST_PP_TUPLE_ELEM_12_11(a, b, c, d, e, f, g, h, i, j, k, l) l
#
# define STREAMS_BOOST_PP_TUPLE_ELEM_13_0(a, b, c, d, e, f, g, h, i, j, k, l, m) a
# define STREAMS_BOOST_PP_TUPLE_ELEM_13_1(a, b, c, d, e, f, g, h, i, j, k, l, m) b
# define STREAMS_BOOST_PP_TUPLE_ELEM_13_2(a, b, c, d, e, f, g, h, i, j, k, l, m) c
# define STREAMS_BOOST_PP_TUPLE_ELEM_13_3(a, b, c, d, e, f, g, h, i, j, k, l, m) d
# define STREAMS_BOOST_PP_TUPLE_ELEM_13_4(a, b, c, d, e, f, g, h, i, j, k, l, m) e
# define STREAMS_BOOST_PP_TUPLE_ELEM_13_5(a, b, c, d, e, f, g, h, i, j, k, l, m) f
# define STREAMS_BOOST_PP_TUPLE_ELEM_13_6(a, b, c, d, e, f, g, h, i, j, k, l, m) g
# define STREAMS_BOOST_PP_TUPLE_ELEM_13_7(a, b, c, d, e, f, g, h, i, j, k, l, m) h
# define STREAMS_BOOST_PP_TUPLE_ELEM_13_8(a, b, c, d, e, f, g, h, i, j, k, l, m) i
# define STREAMS_BOOST_PP_TUPLE_ELEM_13_9(a, b, c, d, e, f, g, h, i, j, k, l, m) j
# define STREAMS_BOOST_PP_TUPLE_ELEM_13_10(a, b, c, d, e, f, g, h, i, j, k, l, m) k
# define STREAMS_BOOST_PP_TUPLE_ELEM_13_11(a, b, c, d, e, f, g, h, i, j, k, l, m) l
# define STREAMS_BOOST_PP_TUPLE_ELEM_13_12(a, b, c, d, e, f, g, h, i, j, k, l, m) m
#
# define STREAMS_BOOST_PP_TUPLE_ELEM_14_0(a, b, c, d, e, f, g, h, i, j, k, l, m, n) a
# define STREAMS_BOOST_PP_TUPLE_ELEM_14_1(a, b, c, d, e, f, g, h, i, j, k, l, m, n) b
# define STREAMS_BOOST_PP_TUPLE_ELEM_14_2(a, b, c, d, e, f, g, h, i, j, k, l, m, n) c
# define STREAMS_BOOST_PP_TUPLE_ELEM_14_3(a, b, c, d, e, f, g, h, i, j, k, l, m, n) d
# define STREAMS_BOOST_PP_TUPLE_ELEM_14_4(a, b, c, d, e, f, g, h, i, j, k, l, m, n) e
# define STREAMS_BOOST_PP_TUPLE_ELEM_14_5(a, b, c, d, e, f, g, h, i, j, k, l, m, n) f
# define STREAMS_BOOST_PP_TUPLE_ELEM_14_6(a, b, c, d, e, f, g, h, i, j, k, l, m, n) g
# define STREAMS_BOOST_PP_TUPLE_ELEM_14_7(a, b, c, d, e, f, g, h, i, j, k, l, m, n) h
# define STREAMS_BOOST_PP_TUPLE_ELEM_14_8(a, b, c, d, e, f, g, h, i, j, k, l, m, n) i
# define STREAMS_BOOST_PP_TUPLE_ELEM_14_9(a, b, c, d, e, f, g, h, i, j, k, l, m, n) j
# define STREAMS_BOOST_PP_TUPLE_ELEM_14_10(a, b, c, d, e, f, g, h, i, j, k, l, m, n) k
# define STREAMS_BOOST_PP_TUPLE_ELEM_14_11(a, b, c, d, e, f, g, h, i, j, k, l, m, n) l
# define STREAMS_BOOST_PP_TUPLE_ELEM_14_12(a, b, c, d, e, f, g, h, i, j, k, l, m, n) m
# define STREAMS_BOOST_PP_TUPLE_ELEM_14_13(a, b, c, d, e, f, g, h, i, j, k, l, m, n) n
#
# define STREAMS_BOOST_PP_TUPLE_ELEM_15_0(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o) a
# define STREAMS_BOOST_PP_TUPLE_ELEM_15_1(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o) b
# define STREAMS_BOOST_PP_TUPLE_ELEM_15_2(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o) c
# define STREAMS_BOOST_PP_TUPLE_ELEM_15_3(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o) d
# define STREAMS_BOOST_PP_TUPLE_ELEM_15_4(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o) e
# define STREAMS_BOOST_PP_TUPLE_ELEM_15_5(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o) f
# define STREAMS_BOOST_PP_TUPLE_ELEM_15_6(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o) g
# define STREAMS_BOOST_PP_TUPLE_ELEM_15_7(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o) h
# define STREAMS_BOOST_PP_TUPLE_ELEM_15_8(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o) i
# define STREAMS_BOOST_PP_TUPLE_ELEM_15_9(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o) j
# define STREAMS_BOOST_PP_TUPLE_ELEM_15_10(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o) k
# define STREAMS_BOOST_PP_TUPLE_ELEM_15_11(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o) l
# define STREAMS_BOOST_PP_TUPLE_ELEM_15_12(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o) m
# define STREAMS_BOOST_PP_TUPLE_ELEM_15_13(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o) n
# define STREAMS_BOOST_PP_TUPLE_ELEM_15_14(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o) o
#
# define STREAMS_BOOST_PP_TUPLE_ELEM_16_0(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) a
# define STREAMS_BOOST_PP_TUPLE_ELEM_16_1(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) b
# define STREAMS_BOOST_PP_TUPLE_ELEM_16_2(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) c
# define STREAMS_BOOST_PP_TUPLE_ELEM_16_3(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) d
# define STREAMS_BOOST_PP_TUPLE_ELEM_16_4(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) e
# define STREAMS_BOOST_PP_TUPLE_ELEM_16_5(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) f
# define STREAMS_BOOST_PP_TUPLE_ELEM_16_6(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) g
# define STREAMS_BOOST_PP_TUPLE_ELEM_16_7(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) h
# define STREAMS_BOOST_PP_TUPLE_ELEM_16_8(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) i
# define STREAMS_BOOST_PP_TUPLE_ELEM_16_9(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) j
# define STREAMS_BOOST_PP_TUPLE_ELEM_16_10(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) k
# define STREAMS_BOOST_PP_TUPLE_ELEM_16_11(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) l
# define STREAMS_BOOST_PP_TUPLE_ELEM_16_12(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) m
# define STREAMS_BOOST_PP_TUPLE_ELEM_16_13(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) n
# define STREAMS_BOOST_PP_TUPLE_ELEM_16_14(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) o
# define STREAMS_BOOST_PP_TUPLE_ELEM_16_15(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) p
#
# define STREAMS_BOOST_PP_TUPLE_ELEM_17_0(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q) a
# define STREAMS_BOOST_PP_TUPLE_ELEM_17_1(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q) b
# define STREAMS_BOOST_PP_TUPLE_ELEM_17_2(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q) c
# define STREAMS_BOOST_PP_TUPLE_ELEM_17_3(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q) d
# define STREAMS_BOOST_PP_TUPLE_ELEM_17_4(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q) e
# define STREAMS_BOOST_PP_TUPLE_ELEM_17_5(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q) f
# define STREAMS_BOOST_PP_TUPLE_ELEM_17_6(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q) g
# define STREAMS_BOOST_PP_TUPLE_ELEM_17_7(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q) h
# define STREAMS_BOOST_PP_TUPLE_ELEM_17_8(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q) i
# define STREAMS_BOOST_PP_TUPLE_ELEM_17_9(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q) j
# define STREAMS_BOOST_PP_TUPLE_ELEM_17_10(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q) k
# define STREAMS_BOOST_PP_TUPLE_ELEM_17_11(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q) l
# define STREAMS_BOOST_PP_TUPLE_ELEM_17_12(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q) m
# define STREAMS_BOOST_PP_TUPLE_ELEM_17_13(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q) n
# define STREAMS_BOOST_PP_TUPLE_ELEM_17_14(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q) o
# define STREAMS_BOOST_PP_TUPLE_ELEM_17_15(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q) p
# define STREAMS_BOOST_PP_TUPLE_ELEM_17_16(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q) q
#
# define STREAMS_BOOST_PP_TUPLE_ELEM_18_0(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) a
# define STREAMS_BOOST_PP_TUPLE_ELEM_18_1(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) b
# define STREAMS_BOOST_PP_TUPLE_ELEM_18_2(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) c
# define STREAMS_BOOST_PP_TUPLE_ELEM_18_3(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) d
# define STREAMS_BOOST_PP_TUPLE_ELEM_18_4(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) e
# define STREAMS_BOOST_PP_TUPLE_ELEM_18_5(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) f
# define STREAMS_BOOST_PP_TUPLE_ELEM_18_6(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) g
# define STREAMS_BOOST_PP_TUPLE_ELEM_18_7(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) h
# define STREAMS_BOOST_PP_TUPLE_ELEM_18_8(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) i
# define STREAMS_BOOST_PP_TUPLE_ELEM_18_9(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) j
# define STREAMS_BOOST_PP_TUPLE_ELEM_18_10(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) k
# define STREAMS_BOOST_PP_TUPLE_ELEM_18_11(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) l
# define STREAMS_BOOST_PP_TUPLE_ELEM_18_12(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) m
# define STREAMS_BOOST_PP_TUPLE_ELEM_18_13(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) n
# define STREAMS_BOOST_PP_TUPLE_ELEM_18_14(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) o
# define STREAMS_BOOST_PP_TUPLE_ELEM_18_15(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) p
# define STREAMS_BOOST_PP_TUPLE_ELEM_18_16(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) q
# define STREAMS_BOOST_PP_TUPLE_ELEM_18_17(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) r
#
# define STREAMS_BOOST_PP_TUPLE_ELEM_19_0(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) a
# define STREAMS_BOOST_PP_TUPLE_ELEM_19_1(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) b
# define STREAMS_BOOST_PP_TUPLE_ELEM_19_2(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) c
# define STREAMS_BOOST_PP_TUPLE_ELEM_19_3(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) d
# define STREAMS_BOOST_PP_TUPLE_ELEM_19_4(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) e
# define STREAMS_BOOST_PP_TUPLE_ELEM_19_5(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) f
# define STREAMS_BOOST_PP_TUPLE_ELEM_19_6(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) g
# define STREAMS_BOOST_PP_TUPLE_ELEM_19_7(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) h
# define STREAMS_BOOST_PP_TUPLE_ELEM_19_8(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) i
# define STREAMS_BOOST_PP_TUPLE_ELEM_19_9(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) j
# define STREAMS_BOOST_PP_TUPLE_ELEM_19_10(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) k
# define STREAMS_BOOST_PP_TUPLE_ELEM_19_11(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) l
# define STREAMS_BOOST_PP_TUPLE_ELEM_19_12(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) m
# define STREAMS_BOOST_PP_TUPLE_ELEM_19_13(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) n
# define STREAMS_BOOST_PP_TUPLE_ELEM_19_14(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) o
# define STREAMS_BOOST_PP_TUPLE_ELEM_19_15(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) p
# define STREAMS_BOOST_PP_TUPLE_ELEM_19_16(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) q
# define STREAMS_BOOST_PP_TUPLE_ELEM_19_17(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) r
# define STREAMS_BOOST_PP_TUPLE_ELEM_19_18(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) s
#
# define STREAMS_BOOST_PP_TUPLE_ELEM_20_0(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) a
# define STREAMS_BOOST_PP_TUPLE_ELEM_20_1(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) b
# define STREAMS_BOOST_PP_TUPLE_ELEM_20_2(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) c
# define STREAMS_BOOST_PP_TUPLE_ELEM_20_3(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) d
# define STREAMS_BOOST_PP_TUPLE_ELEM_20_4(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) e
# define STREAMS_BOOST_PP_TUPLE_ELEM_20_5(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) f
# define STREAMS_BOOST_PP_TUPLE_ELEM_20_6(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) g
# define STREAMS_BOOST_PP_TUPLE_ELEM_20_7(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) h
# define STREAMS_BOOST_PP_TUPLE_ELEM_20_8(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) i
# define STREAMS_BOOST_PP_TUPLE_ELEM_20_9(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) j
# define STREAMS_BOOST_PP_TUPLE_ELEM_20_10(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) k
# define STREAMS_BOOST_PP_TUPLE_ELEM_20_11(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) l
# define STREAMS_BOOST_PP_TUPLE_ELEM_20_12(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) m
# define STREAMS_BOOST_PP_TUPLE_ELEM_20_13(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) n
# define STREAMS_BOOST_PP_TUPLE_ELEM_20_14(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) o
# define STREAMS_BOOST_PP_TUPLE_ELEM_20_15(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) p
# define STREAMS_BOOST_PP_TUPLE_ELEM_20_16(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) q
# define STREAMS_BOOST_PP_TUPLE_ELEM_20_17(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) r
# define STREAMS_BOOST_PP_TUPLE_ELEM_20_18(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) s
# define STREAMS_BOOST_PP_TUPLE_ELEM_20_19(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) t
#
# define STREAMS_BOOST_PP_TUPLE_ELEM_21_0(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) a
# define STREAMS_BOOST_PP_TUPLE_ELEM_21_1(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) b
# define STREAMS_BOOST_PP_TUPLE_ELEM_21_2(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) c
# define STREAMS_BOOST_PP_TUPLE_ELEM_21_3(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) d
# define STREAMS_BOOST_PP_TUPLE_ELEM_21_4(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) e
# define STREAMS_BOOST_PP_TUPLE_ELEM_21_5(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) f
# define STREAMS_BOOST_PP_TUPLE_ELEM_21_6(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) g
# define STREAMS_BOOST_PP_TUPLE_ELEM_21_7(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) h
# define STREAMS_BOOST_PP_TUPLE_ELEM_21_8(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) i
# define STREAMS_BOOST_PP_TUPLE_ELEM_21_9(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) j
# define STREAMS_BOOST_PP_TUPLE_ELEM_21_10(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) k
# define STREAMS_BOOST_PP_TUPLE_ELEM_21_11(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) l
# define STREAMS_BOOST_PP_TUPLE_ELEM_21_12(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) m
# define STREAMS_BOOST_PP_TUPLE_ELEM_21_13(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) n
# define STREAMS_BOOST_PP_TUPLE_ELEM_21_14(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) o
# define STREAMS_BOOST_PP_TUPLE_ELEM_21_15(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) p
# define STREAMS_BOOST_PP_TUPLE_ELEM_21_16(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) q
# define STREAMS_BOOST_PP_TUPLE_ELEM_21_17(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) r
# define STREAMS_BOOST_PP_TUPLE_ELEM_21_18(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) s
# define STREAMS_BOOST_PP_TUPLE_ELEM_21_19(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) t
# define STREAMS_BOOST_PP_TUPLE_ELEM_21_20(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) u
#
# define STREAMS_BOOST_PP_TUPLE_ELEM_22_0(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) a
# define STREAMS_BOOST_PP_TUPLE_ELEM_22_1(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) b
# define STREAMS_BOOST_PP_TUPLE_ELEM_22_2(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) c
# define STREAMS_BOOST_PP_TUPLE_ELEM_22_3(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) d
# define STREAMS_BOOST_PP_TUPLE_ELEM_22_4(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) e
# define STREAMS_BOOST_PP_TUPLE_ELEM_22_5(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) f
# define STREAMS_BOOST_PP_TUPLE_ELEM_22_6(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) g
# define STREAMS_BOOST_PP_TUPLE_ELEM_22_7(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) h
# define STREAMS_BOOST_PP_TUPLE_ELEM_22_8(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) i
# define STREAMS_BOOST_PP_TUPLE_ELEM_22_9(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) j
# define STREAMS_BOOST_PP_TUPLE_ELEM_22_10(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) k
# define STREAMS_BOOST_PP_TUPLE_ELEM_22_11(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) l
# define STREAMS_BOOST_PP_TUPLE_ELEM_22_12(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) m
# define STREAMS_BOOST_PP_TUPLE_ELEM_22_13(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) n
# define STREAMS_BOOST_PP_TUPLE_ELEM_22_14(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) o
# define STREAMS_BOOST_PP_TUPLE_ELEM_22_15(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) p
# define STREAMS_BOOST_PP_TUPLE_ELEM_22_16(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) q
# define STREAMS_BOOST_PP_TUPLE_ELEM_22_17(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) r
# define STREAMS_BOOST_PP_TUPLE_ELEM_22_18(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) s
# define STREAMS_BOOST_PP_TUPLE_ELEM_22_19(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) t
# define STREAMS_BOOST_PP_TUPLE_ELEM_22_20(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) u
# define STREAMS_BOOST_PP_TUPLE_ELEM_22_21(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) v
#
# define STREAMS_BOOST_PP_TUPLE_ELEM_23_0(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) a
# define STREAMS_BOOST_PP_TUPLE_ELEM_23_1(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) b
# define STREAMS_BOOST_PP_TUPLE_ELEM_23_2(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) c
# define STREAMS_BOOST_PP_TUPLE_ELEM_23_3(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) d
# define STREAMS_BOOST_PP_TUPLE_ELEM_23_4(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) e
# define STREAMS_BOOST_PP_TUPLE_ELEM_23_5(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) f
# define STREAMS_BOOST_PP_TUPLE_ELEM_23_6(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) g
# define STREAMS_BOOST_PP_TUPLE_ELEM_23_7(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) h
# define STREAMS_BOOST_PP_TUPLE_ELEM_23_8(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) i
# define STREAMS_BOOST_PP_TUPLE_ELEM_23_9(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) j
# define STREAMS_BOOST_PP_TUPLE_ELEM_23_10(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) k
# define STREAMS_BOOST_PP_TUPLE_ELEM_23_11(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) l
# define STREAMS_BOOST_PP_TUPLE_ELEM_23_12(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) m
# define STREAMS_BOOST_PP_TUPLE_ELEM_23_13(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) n
# define STREAMS_BOOST_PP_TUPLE_ELEM_23_14(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) o
# define STREAMS_BOOST_PP_TUPLE_ELEM_23_15(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) p
# define STREAMS_BOOST_PP_TUPLE_ELEM_23_16(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) q
# define STREAMS_BOOST_PP_TUPLE_ELEM_23_17(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) r
# define STREAMS_BOOST_PP_TUPLE_ELEM_23_18(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) s
# define STREAMS_BOOST_PP_TUPLE_ELEM_23_19(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) t
# define STREAMS_BOOST_PP_TUPLE_ELEM_23_20(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) u
# define STREAMS_BOOST_PP_TUPLE_ELEM_23_21(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) v
# define STREAMS_BOOST_PP_TUPLE_ELEM_23_22(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) w
#
# define STREAMS_BOOST_PP_TUPLE_ELEM_24_0(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) a
# define STREAMS_BOOST_PP_TUPLE_ELEM_24_1(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) b
# define STREAMS_BOOST_PP_TUPLE_ELEM_24_2(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) c
# define STREAMS_BOOST_PP_TUPLE_ELEM_24_3(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) d
# define STREAMS_BOOST_PP_TUPLE_ELEM_24_4(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) e
# define STREAMS_BOOST_PP_TUPLE_ELEM_24_5(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) f
# define STREAMS_BOOST_PP_TUPLE_ELEM_24_6(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) g
# define STREAMS_BOOST_PP_TUPLE_ELEM_24_7(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) h
# define STREAMS_BOOST_PP_TUPLE_ELEM_24_8(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) i
# define STREAMS_BOOST_PP_TUPLE_ELEM_24_9(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) j
# define STREAMS_BOOST_PP_TUPLE_ELEM_24_10(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) k
# define STREAMS_BOOST_PP_TUPLE_ELEM_24_11(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) l
# define STREAMS_BOOST_PP_TUPLE_ELEM_24_12(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) m
# define STREAMS_BOOST_PP_TUPLE_ELEM_24_13(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) n
# define STREAMS_BOOST_PP_TUPLE_ELEM_24_14(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) o
# define STREAMS_BOOST_PP_TUPLE_ELEM_24_15(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) p
# define STREAMS_BOOST_PP_TUPLE_ELEM_24_16(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) q
# define STREAMS_BOOST_PP_TUPLE_ELEM_24_17(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) r
# define STREAMS_BOOST_PP_TUPLE_ELEM_24_18(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) s
# define STREAMS_BOOST_PP_TUPLE_ELEM_24_19(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) t
# define STREAMS_BOOST_PP_TUPLE_ELEM_24_20(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) u
# define STREAMS_BOOST_PP_TUPLE_ELEM_24_21(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) v
# define STREAMS_BOOST_PP_TUPLE_ELEM_24_22(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) w
# define STREAMS_BOOST_PP_TUPLE_ELEM_24_23(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) x
#
# define STREAMS_BOOST_PP_TUPLE_ELEM_25_0(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) a
# define STREAMS_BOOST_PP_TUPLE_ELEM_25_1(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) b
# define STREAMS_BOOST_PP_TUPLE_ELEM_25_2(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) c
# define STREAMS_BOOST_PP_TUPLE_ELEM_25_3(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) d
# define STREAMS_BOOST_PP_TUPLE_ELEM_25_4(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) e
# define STREAMS_BOOST_PP_TUPLE_ELEM_25_5(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) f
# define STREAMS_BOOST_PP_TUPLE_ELEM_25_6(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) g
# define STREAMS_BOOST_PP_TUPLE_ELEM_25_7(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) h
# define STREAMS_BOOST_PP_TUPLE_ELEM_25_8(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) i
# define STREAMS_BOOST_PP_TUPLE_ELEM_25_9(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) j
# define STREAMS_BOOST_PP_TUPLE_ELEM_25_10(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) k
# define STREAMS_BOOST_PP_TUPLE_ELEM_25_11(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) l
# define STREAMS_BOOST_PP_TUPLE_ELEM_25_12(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) m
# define STREAMS_BOOST_PP_TUPLE_ELEM_25_13(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) n
# define STREAMS_BOOST_PP_TUPLE_ELEM_25_14(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) o
# define STREAMS_BOOST_PP_TUPLE_ELEM_25_15(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) p
# define STREAMS_BOOST_PP_TUPLE_ELEM_25_16(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) q
# define STREAMS_BOOST_PP_TUPLE_ELEM_25_17(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) r
# define STREAMS_BOOST_PP_TUPLE_ELEM_25_18(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) s
# define STREAMS_BOOST_PP_TUPLE_ELEM_25_19(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) t
# define STREAMS_BOOST_PP_TUPLE_ELEM_25_20(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) u
# define STREAMS_BOOST_PP_TUPLE_ELEM_25_21(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) v
# define STREAMS_BOOST_PP_TUPLE_ELEM_25_22(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) w
# define STREAMS_BOOST_PP_TUPLE_ELEM_25_23(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) x
# define STREAMS_BOOST_PP_TUPLE_ELEM_25_24(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) y
#
# endif
