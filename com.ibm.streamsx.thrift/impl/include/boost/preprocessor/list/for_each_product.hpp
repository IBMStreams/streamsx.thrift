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
# ifndef STREAMS_BOOST_PREPROCESSOR_LIST_FOR_EACH_PRODUCT_HPP
# define STREAMS_BOOST_PREPROCESSOR_LIST_FOR_EACH_PRODUCT_HPP
#
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/control/if.hpp>
# include <streams_boost/preprocessor/list/adt.hpp>
# include <streams_boost/preprocessor/list/to_tuple.hpp>
# include <streams_boost/preprocessor/repetition/for.hpp>
# include <streams_boost/preprocessor/tuple/elem.hpp>
# include <streams_boost/preprocessor/tuple/to_list.hpp>
# include <streams_boost/preprocessor/tuple/rem.hpp>
# include <streams_boost/preprocessor/tuple/reverse.hpp>
#
# /* STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT(macro, size, tuple) STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_E(STREAMS_BOOST_PP_FOR, macro, size, STREAMS_BOOST_PP_TUPLE_TO_LIST(size, tuple))
# else
#    define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT(macro, size, tuple) STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_Q(macro, size, tuple)
#    define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_Q(macro, size, tuple) STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_E(STREAMS_BOOST_PP_FOR, macro, size, STREAMS_BOOST_PP_TUPLE_TO_LIST(size, tuple))
# endif
#
# /* STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_R */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_R(r, macro, size, tuple) STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_E(STREAMS_BOOST_PP_FOR_ ## r, macro, size, STREAMS_BOOST_PP_TUPLE_TO_LIST(size, tuple))
# else
#    define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_R(r, macro, size, tuple) STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_R_Q(r, macro, size, tuple)
#    define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_R_Q(r, macro, size, tuple) STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_E(STREAMS_BOOST_PP_FOR_ ## r, macro, size, STREAMS_BOOST_PP_TUPLE_TO_LIST(size, tuple))
# endif
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_E(impl, macro, size, lists) impl((STREAMS_BOOST_PP_LIST_FIRST(lists), STREAMS_BOOST_PP_LIST_REST(lists), STREAMS_BOOST_PP_NIL, macro, size), STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_P, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_O, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_M_0)
# else
#    define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_E(impl, macro, size, lists) STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_E_D(impl, macro, size, lists)
#    define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_E_D(impl, macro, size, lists) impl((STREAMS_BOOST_PP_LIST_FIRST(lists), STREAMS_BOOST_PP_LIST_REST(lists), STREAMS_BOOST_PP_NIL, macro, size), STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_P, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_O, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_M_0)
# endif
#
# if STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_STRICT()
#    define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_P(r, data) STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_P_I data
#    define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_P_I(a, b, res, macro, size) STREAMS_BOOST_PP_LIST_IS_CONS(a)
# else
#    define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_P(r, data) STREAMS_BOOST_PP_LIST_IS_CONS(STREAMS_BOOST_PP_TUPLE_ELEM(5, 0, data))
# endif
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_MWCC()
#    define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_O(r, data) STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_O_I data
#    define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_O_I(a, b, res, macro, size) (STREAMS_BOOST_PP_LIST_REST(a), b, res, macro, size)
# else
#    define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_O(r, data) (STREAMS_BOOST_PP_LIST_REST(STREAMS_BOOST_PP_TUPLE_ELEM(5, 0, data)), STREAMS_BOOST_PP_TUPLE_ELEM(5, 1, data), STREAMS_BOOST_PP_TUPLE_ELEM(5, 2, data), STREAMS_BOOST_PP_TUPLE_ELEM(5, 3, data), STREAMS_BOOST_PP_TUPLE_ELEM(5, 4, data))
# endif
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_I(r, data) STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_I_I(r, STREAMS_BOOST_PP_TUPLE_ELEM(5, 0, data), STREAMS_BOOST_PP_TUPLE_ELEM(5, 1, data), STREAMS_BOOST_PP_TUPLE_ELEM(5, 2, data), STREAMS_BOOST_PP_TUPLE_ELEM(5, 3, data), STREAMS_BOOST_PP_TUPLE_ELEM(5, 4, data))
# else
#    define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_I(r, data) STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_I_D(r, STREAMS_BOOST_PP_TUPLE_REM_5 data)
#    define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_I_D(r, data_e) STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_I_I(r, data_e)
# endif
#
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_I_I(r, a, b, res, macro, size) STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_I_II(r, macro, STREAMS_BOOST_PP_LIST_TO_TUPLE_R(r, (STREAMS_BOOST_PP_LIST_FIRST(a), res)), size)
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_I_II(r, macro, args, size) STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_I_III(r, macro, args, size)
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_I_III(r, macro, args, size) macro(r, STREAMS_BOOST_PP_TUPLE_REVERSE(size, args))
#
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_C(data, i) STREAMS_BOOST_PP_IF(STREAMS_BOOST_PP_LIST_IS_CONS(STREAMS_BOOST_PP_TUPLE_ELEM(5, 1, data)), STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_N_ ## i, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_I)
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_MWCC()
#    define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_H(data) STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_H_I data
# else
#    define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_H(data) STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_H_I(STREAMS_BOOST_PP_TUPLE_ELEM(5, 0, data), STREAMS_BOOST_PP_TUPLE_ELEM(5, 1, data), STREAMS_BOOST_PP_TUPLE_ELEM(5, 2, data), STREAMS_BOOST_PP_TUPLE_ELEM(5, 3, data), STREAMS_BOOST_PP_TUPLE_ELEM(5, 4, data))
# endif
#
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_H_I(a, b, res, macro, size) (STREAMS_BOOST_PP_LIST_FIRST(b), STREAMS_BOOST_PP_LIST_REST(b), (STREAMS_BOOST_PP_LIST_FIRST(a), res), macro, size)
#
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_M_0(r, data) STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_C(data, 0)(r, data)
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_M_1(r, data) STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_C(data, 1)(r, data)
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_M_2(r, data) STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_C(data, 2)(r, data)
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_M_3(r, data) STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_C(data, 3)(r, data)
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_M_4(r, data) STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_C(data, 4)(r, data)
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_M_5(r, data) STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_C(data, 5)(r, data)
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_M_6(r, data) STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_C(data, 6)(r, data)
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_M_7(r, data) STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_C(data, 7)(r, data)
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_M_8(r, data) STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_C(data, 8)(r, data)
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_M_9(r, data) STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_C(data, 9)(r, data)
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_M_10(r, data) STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_C(data, 10)(r, data)
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_M_11(r, data) STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_C(data, 11)(r, data)
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_M_12(r, data) STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_C(data, 12)(r, data)
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_M_13(r, data) STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_C(data, 13)(r, data)
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_M_14(r, data) STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_C(data, 14)(r, data)
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_M_15(r, data) STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_C(data, 15)(r, data)
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_M_16(r, data) STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_C(data, 16)(r, data)
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_M_17(r, data) STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_C(data, 17)(r, data)
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_M_18(r, data) STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_C(data, 18)(r, data)
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_M_19(r, data) STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_C(data, 19)(r, data)
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_M_20(r, data) STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_C(data, 20)(r, data)
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_M_21(r, data) STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_C(data, 21)(r, data)
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_M_22(r, data) STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_C(data, 22)(r, data)
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_M_23(r, data) STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_C(data, 23)(r, data)
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_M_24(r, data) STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_C(data, 24)(r, data)
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_M_25(r, data) STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_C(data, 25)(r, data)
#
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_N_0(r, data) STREAMS_BOOST_PP_FOR_ ## r(STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_H(data), STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_P, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_O, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_M_1)
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_N_1(r, data) STREAMS_BOOST_PP_FOR_ ## r(STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_H(data), STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_P, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_O, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_M_2)
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_N_2(r, data) STREAMS_BOOST_PP_FOR_ ## r(STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_H(data), STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_P, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_O, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_M_3)
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_N_3(r, data) STREAMS_BOOST_PP_FOR_ ## r(STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_H(data), STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_P, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_O, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_M_4)
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_N_4(r, data) STREAMS_BOOST_PP_FOR_ ## r(STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_H(data), STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_P, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_O, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_M_5)
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_N_5(r, data) STREAMS_BOOST_PP_FOR_ ## r(STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_H(data), STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_P, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_O, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_M_6)
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_N_6(r, data) STREAMS_BOOST_PP_FOR_ ## r(STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_H(data), STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_P, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_O, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_M_7)
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_N_7(r, data) STREAMS_BOOST_PP_FOR_ ## r(STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_H(data), STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_P, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_O, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_M_8)
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_N_8(r, data) STREAMS_BOOST_PP_FOR_ ## r(STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_H(data), STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_P, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_O, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_M_9)
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_N_9(r, data) STREAMS_BOOST_PP_FOR_ ## r(STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_H(data), STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_P, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_O, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_M_10)
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_N_10(r, data) STREAMS_BOOST_PP_FOR_ ## r(STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_H(data), STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_P, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_O, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_M_11)
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_N_11(r, data) STREAMS_BOOST_PP_FOR_ ## r(STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_H(data), STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_P, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_O, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_M_12)
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_N_12(r, data) STREAMS_BOOST_PP_FOR_ ## r(STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_H(data), STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_P, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_O, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_M_13)
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_N_13(r, data) STREAMS_BOOST_PP_FOR_ ## r(STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_H(data), STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_P, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_O, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_M_14)
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_N_14(r, data) STREAMS_BOOST_PP_FOR_ ## r(STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_H(data), STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_P, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_O, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_M_15)
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_N_15(r, data) STREAMS_BOOST_PP_FOR_ ## r(STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_H(data), STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_P, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_O, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_M_16)
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_N_16(r, data) STREAMS_BOOST_PP_FOR_ ## r(STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_H(data), STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_P, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_O, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_M_17)
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_N_17(r, data) STREAMS_BOOST_PP_FOR_ ## r(STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_H(data), STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_P, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_O, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_M_18)
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_N_18(r, data) STREAMS_BOOST_PP_FOR_ ## r(STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_H(data), STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_P, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_O, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_M_19)
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_N_19(r, data) STREAMS_BOOST_PP_FOR_ ## r(STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_H(data), STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_P, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_O, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_M_20)
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_N_20(r, data) STREAMS_BOOST_PP_FOR_ ## r(STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_H(data), STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_P, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_O, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_M_21)
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_N_21(r, data) STREAMS_BOOST_PP_FOR_ ## r(STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_H(data), STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_P, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_O, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_M_22)
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_N_22(r, data) STREAMS_BOOST_PP_FOR_ ## r(STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_H(data), STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_P, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_O, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_M_23)
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_N_23(r, data) STREAMS_BOOST_PP_FOR_ ## r(STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_H(data), STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_P, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_O, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_M_24)
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_N_24(r, data) STREAMS_BOOST_PP_FOR_ ## r(STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_H(data), STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_P, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_O, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_M_25)
# define STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_N_25(r, data) STREAMS_BOOST_PP_FOR_ ## r(STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_H(data), STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_P, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_O, STREAMS_BOOST_PP_LIST_FOR_EACH_PRODUCT_M_26)
#
# endif