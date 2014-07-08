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
# ifndef STREAMS_BOOST_PREPROCESSOR_ARRAY_REMOVE_HPP
# define STREAMS_BOOST_PREPROCESSOR_ARRAY_REMOVE_HPP
#
# include <streams_boost/preprocessor/arithmetic/inc.hpp>
# include <streams_boost/preprocessor/array/elem.hpp>
# include <streams_boost/preprocessor/array/push_back.hpp>
# include <streams_boost/preprocessor/array/size.hpp>
# include <streams_boost/preprocessor/comparison/not_equal.hpp>
# include <streams_boost/preprocessor/control/deduce_d.hpp>
# include <streams_boost/preprocessor/control/iif.hpp>
# include <streams_boost/preprocessor/control/while.hpp>
# include <streams_boost/preprocessor/tuple/eat.hpp>
# include <streams_boost/preprocessor/tuple/elem.hpp>
#
# /* STREAMS_BOOST_PP_ARRAY_REMOVE */
#
# define STREAMS_BOOST_PP_ARRAY_REMOVE(array, i) STREAMS_BOOST_PP_ARRAY_REMOVE_I(STREAMS_BOOST_PP_DEDUCE_D(), array, i)
# define STREAMS_BOOST_PP_ARRAY_REMOVE_I(d, array, i) STREAMS_BOOST_PP_ARRAY_REMOVE_D(d, array, i)
#
# /* STREAMS_BOOST_PP_ARRAY_REMOVE_D */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_ARRAY_REMOVE_D(d, array, i) STREAMS_BOOST_PP_TUPLE_ELEM(4, 2, STREAMS_BOOST_PP_WHILE_ ## d(STREAMS_BOOST_PP_ARRAY_REMOVE_P, STREAMS_BOOST_PP_ARRAY_REMOVE_O, (0, i, (0, ()), array)))
# else
#    define STREAMS_BOOST_PP_ARRAY_REMOVE_D(d, array, i) STREAMS_BOOST_PP_ARRAY_REMOVE_D_I(d, array, i)
#    define STREAMS_BOOST_PP_ARRAY_REMOVE_D_I(d, array, i) STREAMS_BOOST_PP_TUPLE_ELEM(4, 2, STREAMS_BOOST_PP_WHILE_ ## d(STREAMS_BOOST_PP_ARRAY_REMOVE_P, STREAMS_BOOST_PP_ARRAY_REMOVE_O, (0, i, (0, ()), array)))
# endif
#
# define STREAMS_BOOST_PP_ARRAY_REMOVE_P(d, st) STREAMS_BOOST_PP_NOT_EQUAL(STREAMS_BOOST_PP_TUPLE_ELEM(4, 0, st), STREAMS_BOOST_PP_ARRAY_SIZE(STREAMS_BOOST_PP_TUPLE_ELEM(4, 3, st)))
#
# if STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_STRICT()
#    define STREAMS_BOOST_PP_ARRAY_REMOVE_O(d, st) STREAMS_BOOST_PP_ARRAY_REMOVE_O_I st
# else
#    define STREAMS_BOOST_PP_ARRAY_REMOVE_O(d, st) STREAMS_BOOST_PP_ARRAY_REMOVE_O_I(STREAMS_BOOST_PP_TUPLE_ELEM(4, 0, st), STREAMS_BOOST_PP_TUPLE_ELEM(4, 1, st), STREAMS_BOOST_PP_TUPLE_ELEM(4, 2, st), STREAMS_BOOST_PP_TUPLE_ELEM(4, 3, st))
# endif
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_DMC()
#    define STREAMS_BOOST_PP_ARRAY_REMOVE_O_I(n, i, res, arr) (STREAMS_BOOST_PP_INC(n), i, STREAMS_BOOST_PP_IIF(STREAMS_BOOST_PP_NOT_EQUAL(n, i), STREAMS_BOOST_PP_ARRAY_PUSH_BACK, res STREAMS_BOOST_PP_TUPLE_EAT_2)(res, STREAMS_BOOST_PP_ARRAY_ELEM(n, arr)), arr)
# else
#    define STREAMS_BOOST_PP_ARRAY_REMOVE_O_I(n, i, res, arr) (STREAMS_BOOST_PP_INC(n), i, STREAMS_BOOST_PP_IIF(STREAMS_BOOST_PP_NOT_EQUAL(n, i), STREAMS_BOOST_PP_ARRAY_PUSH_BACK, STREAMS_BOOST_PP_TUPLE_ELEM_2_0)(res, STREAMS_BOOST_PP_ARRAY_ELEM(n, arr)), arr)
# endif
#
# endif
