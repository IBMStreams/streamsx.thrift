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
# ifndef STREAMS_BOOST_PREPROCESSOR_TUPLE_TO_LIST_HPP
# define STREAMS_BOOST_PREPROCESSOR_TUPLE_TO_LIST_HPP
#
# include <streams_boost/preprocessor/config/config.hpp>
#
# /* STREAMS_BOOST_PP_TUPLE_TO_LIST */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_MWCC()
#    define STREAMS_BOOST_PP_TUPLE_TO_LIST(size, tuple) STREAMS_BOOST_PP_TUPLE_TO_LIST_I(size, tuple)
#    if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_MSVC()
#        define STREAMS_BOOST_PP_TUPLE_TO_LIST_I(s, t) STREAMS_BOOST_PP_TUPLE_TO_LIST_ ## s t
#    else
#        define STREAMS_BOOST_PP_TUPLE_TO_LIST_I(s, t) STREAMS_BOOST_PP_TUPLE_TO_LIST_II(STREAMS_BOOST_PP_TUPLE_TO_LIST_ ## s t)
#        define STREAMS_BOOST_PP_TUPLE_TO_LIST_II(res) res
#    endif
# else
#    define STREAMS_BOOST_PP_TUPLE_TO_LIST(size, tuple) STREAMS_BOOST_PP_TUPLE_TO_LIST_OO((size, tuple))
#    define STREAMS_BOOST_PP_TUPLE_TO_LIST_OO(par) STREAMS_BOOST_PP_TUPLE_TO_LIST_I ## par
#    define STREAMS_BOOST_PP_TUPLE_TO_LIST_I(s, t) STREAMS_BOOST_PP_TUPLE_TO_LIST_ ## s ## t
# endif
#
# define STREAMS_BOOST_PP_TUPLE_TO_LIST_0() STREAMS_BOOST_PP_NIL
# define STREAMS_BOOST_PP_TUPLE_TO_LIST_1(a) (a, STREAMS_BOOST_PP_NIL)
# define STREAMS_BOOST_PP_TUPLE_TO_LIST_2(a, b) (a, (b, STREAMS_BOOST_PP_NIL))
# define STREAMS_BOOST_PP_TUPLE_TO_LIST_3(a, b, c) (a, (b, (c, STREAMS_BOOST_PP_NIL)))
# define STREAMS_BOOST_PP_TUPLE_TO_LIST_4(a, b, c, d) (a, (b, (c, (d, STREAMS_BOOST_PP_NIL))))
# define STREAMS_BOOST_PP_TUPLE_TO_LIST_5(a, b, c, d, e) (a, (b, (c, (d, (e, STREAMS_BOOST_PP_NIL)))))
# define STREAMS_BOOST_PP_TUPLE_TO_LIST_6(a, b, c, d, e, f) (a, (b, (c, (d, (e, (f, STREAMS_BOOST_PP_NIL))))))
# define STREAMS_BOOST_PP_TUPLE_TO_LIST_7(a, b, c, d, e, f, g) (a, (b, (c, (d, (e, (f, (g, STREAMS_BOOST_PP_NIL)))))))
# define STREAMS_BOOST_PP_TUPLE_TO_LIST_8(a, b, c, d, e, f, g, h) (a, (b, (c, (d, (e, (f, (g, (h, STREAMS_BOOST_PP_NIL))))))))
# define STREAMS_BOOST_PP_TUPLE_TO_LIST_9(a, b, c, d, e, f, g, h, i) (a, (b, (c, (d, (e, (f, (g, (h, (i, STREAMS_BOOST_PP_NIL)))))))))
# define STREAMS_BOOST_PP_TUPLE_TO_LIST_10(a, b, c, d, e, f, g, h, i, j) (a, (b, (c, (d, (e, (f, (g, (h, (i, (j, STREAMS_BOOST_PP_NIL))))))))))
# define STREAMS_BOOST_PP_TUPLE_TO_LIST_11(a, b, c, d, e, f, g, h, i, j, k) (a, (b, (c, (d, (e, (f, (g, (h, (i, (j, (k, STREAMS_BOOST_PP_NIL)))))))))))
# define STREAMS_BOOST_PP_TUPLE_TO_LIST_12(a, b, c, d, e, f, g, h, i, j, k, l) (a, (b, (c, (d, (e, (f, (g, (h, (i, (j, (k, (l, STREAMS_BOOST_PP_NIL))))))))))))
# define STREAMS_BOOST_PP_TUPLE_TO_LIST_13(a, b, c, d, e, f, g, h, i, j, k, l, m) (a, (b, (c, (d, (e, (f, (g, (h, (i, (j, (k, (l, (m, STREAMS_BOOST_PP_NIL)))))))))))))
# define STREAMS_BOOST_PP_TUPLE_TO_LIST_14(a, b, c, d, e, f, g, h, i, j, k, l, m, n) (a, (b, (c, (d, (e, (f, (g, (h, (i, (j, (k, (l, (m, (n, STREAMS_BOOST_PP_NIL))))))))))))))
# define STREAMS_BOOST_PP_TUPLE_TO_LIST_15(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o) (a, (b, (c, (d, (e, (f, (g, (h, (i, (j, (k, (l, (m, (n, (o, STREAMS_BOOST_PP_NIL)))))))))))))))
# define STREAMS_BOOST_PP_TUPLE_TO_LIST_16(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) (a, (b, (c, (d, (e, (f, (g, (h, (i, (j, (k, (l, (m, (n, (o, (p, STREAMS_BOOST_PP_NIL))))))))))))))))
# define STREAMS_BOOST_PP_TUPLE_TO_LIST_17(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q) (a, (b, (c, (d, (e, (f, (g, (h, (i, (j, (k, (l, (m, (n, (o, (p, (q, STREAMS_BOOST_PP_NIL)))))))))))))))))
# define STREAMS_BOOST_PP_TUPLE_TO_LIST_18(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) (a, (b, (c, (d, (e, (f, (g, (h, (i, (j, (k, (l, (m, (n, (o, (p, (q, (r, STREAMS_BOOST_PP_NIL))))))))))))))))))
# define STREAMS_BOOST_PP_TUPLE_TO_LIST_19(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) (a, (b, (c, (d, (e, (f, (g, (h, (i, (j, (k, (l, (m, (n, (o, (p, (q, (r, (s, STREAMS_BOOST_PP_NIL)))))))))))))))))))
# define STREAMS_BOOST_PP_TUPLE_TO_LIST_20(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) (a, (b, (c, (d, (e, (f, (g, (h, (i, (j, (k, (l, (m, (n, (o, (p, (q, (r, (s, (t, STREAMS_BOOST_PP_NIL))))))))))))))))))))
# define STREAMS_BOOST_PP_TUPLE_TO_LIST_21(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) (a, (b, (c, (d, (e, (f, (g, (h, (i, (j, (k, (l, (m, (n, (o, (p, (q, (r, (s, (t, (u, STREAMS_BOOST_PP_NIL)))))))))))))))))))))
# define STREAMS_BOOST_PP_TUPLE_TO_LIST_22(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) (a, (b, (c, (d, (e, (f, (g, (h, (i, (j, (k, (l, (m, (n, (o, (p, (q, (r, (s, (t, (u, (v, STREAMS_BOOST_PP_NIL))))))))))))))))))))))
# define STREAMS_BOOST_PP_TUPLE_TO_LIST_23(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) (a, (b, (c, (d, (e, (f, (g, (h, (i, (j, (k, (l, (m, (n, (o, (p, (q, (r, (s, (t, (u, (v, (w, STREAMS_BOOST_PP_NIL)))))))))))))))))))))))
# define STREAMS_BOOST_PP_TUPLE_TO_LIST_24(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) (a, (b, (c, (d, (e, (f, (g, (h, (i, (j, (k, (l, (m, (n, (o, (p, (q, (r, (s, (t, (u, (v, (w, (x, STREAMS_BOOST_PP_NIL))))))))))))))))))))))))
# define STREAMS_BOOST_PP_TUPLE_TO_LIST_25(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) (a, (b, (c, (d, (e, (f, (g, (h, (i, (j, (k, (l, (m, (n, (o, (p, (q, (r, (s, (t, (u, (v, (w, (x, (y, STREAMS_BOOST_PP_NIL)))))))))))))))))))))))))
#
# endif
