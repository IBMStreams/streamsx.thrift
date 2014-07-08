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
# ifndef STREAMS_BOOST_PREPROCESSOR_ARRAY_REPLACE_HPP
# define STREAMS_BOOST_PREPROCESSOR_ARRAY_REPLACE_HPP
#
# include <streams_boost/preprocessor/arithmetic/inc.hpp>
# include <streams_boost/preprocessor/array/elem.hpp>
# include <streams_boost/preprocessor/array/push_back.hpp>
# include <streams_boost/preprocessor/comparison/not_equal.hpp>
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/control/deduce_d.hpp>
# include <streams_boost/preprocessor/control/iif.hpp>
# include <streams_boost/preprocessor/control/while.hpp>
# include <streams_boost/preprocessor/tuple/elem.hpp>
#
# /* STREAMS_BOOST_PP_ARRAY_REPLACE */
#
# define STREAMS_BOOST_PP_ARRAY_REPLACE(array, i, elem) STREAMS_BOOST_PP_ARRAY_REPLACE_I(STREAMS_BOOST_PP_DEDUCE_D(), array, i, elem)
# define STREAMS_BOOST_PP_ARRAY_REPLACE_I(d, array, i, elem) STREAMS_BOOST_PP_ARRAY_REPLACE_D(d, array, i, elem)
#
# /* STREAMS_BOOST_PP_ARRAY_REPLACE_D */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_ARRAY_REPLACE_D(d, array, i, elem) STREAMS_BOOST_PP_TUPLE_ELEM(5, 3, STREAMS_BOOST_PP_WHILE_ ## d(STREAMS_BOOST_PP_ARRAY_REPLACE_P, STREAMS_BOOST_PP_ARRAY_REPLACE_O, (0, i, elem, (0, ()), array)))
# else
#    define STREAMS_BOOST_PP_ARRAY_REPLACE_D(d, array, i, elem) STREAMS_BOOST_PP_ARRAY_REPLACE_D_I(d, array, i, elem)
#    define STREAMS_BOOST_PP_ARRAY_REPLACE_D_I(d, array, i, elem) STREAMS_BOOST_PP_TUPLE_ELEM(5, 3, STREAMS_BOOST_PP_WHILE_ ## d(STREAMS_BOOST_PP_ARRAY_REPLACE_P, STREAMS_BOOST_PP_ARRAY_REPLACE_O, (0, i, elem, (0, ()), array)))
# endif
#
# define STREAMS_BOOST_PP_ARRAY_REPLACE_P(d, state) STREAMS_BOOST_PP_NOT_EQUAL(STREAMS_BOOST_PP_TUPLE_ELEM(5, 0, state), STREAMS_BOOST_PP_ARRAY_SIZE(STREAMS_BOOST_PP_TUPLE_ELEM(5, 4, state)))
#
# if STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_STRICT()
#    define STREAMS_BOOST_PP_ARRAY_REPLACE_O(d, state) STREAMS_BOOST_PP_ARRAY_REPLACE_O_I state
# else
#    define STREAMS_BOOST_PP_ARRAY_REPLACE_O(d, state) STREAMS_BOOST_PP_ARRAY_REPLACE_O_I(STREAMS_BOOST_PP_TUPLE_ELEM(5, 0, state), STREAMS_BOOST_PP_TUPLE_ELEM(5, 1, state), STREAMS_BOOST_PP_TUPLE_ELEM(5, 2, state), STREAMS_BOOST_PP_TUPLE_ELEM(5, 3, state), STREAMS_BOOST_PP_TUPLE_ELEM(5, 4, state))
# endif
#
# define STREAMS_BOOST_PP_ARRAY_REPLACE_O_I(n, i, elem, res, arr) (STREAMS_BOOST_PP_INC(n), i, elem, STREAMS_BOOST_PP_ARRAY_PUSH_BACK(res, STREAMS_BOOST_PP_IIF(STREAMS_BOOST_PP_NOT_EQUAL(n, i), STREAMS_BOOST_PP_ARRAY_ELEM(n, arr), elem)), arr)
#
# endif
