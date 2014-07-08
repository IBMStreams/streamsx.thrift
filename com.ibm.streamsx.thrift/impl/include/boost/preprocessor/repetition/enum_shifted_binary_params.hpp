# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Paul Mensonides 2005.                                  *
#  *     Distributed under the Boost Software License, Version 1.0. (See      *
#  *     accompanying file LICENSE_1_0.txt or copy at                         *
#  *     http://www.streams_boost.org/LICENSE_1_0.txt)                                *
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.streams_boost.org for most recent version. */
#
# ifndef STREAMS_BOOST_PREPROCESSOR_REPETITION_ENUM_SHIFTED_BINARY_PARAMS_HPP
# define STREAMS_BOOST_PREPROCESSOR_REPETITION_ENUM_SHIFTED_BINARY_PARAMS_HPP
#
# include <streams_boost/preprocessor/arithmetic/dec.hpp>
# include <streams_boost/preprocessor/arithmetic/inc.hpp>
# include <streams_boost/preprocessor/cat.hpp>
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/punctuation/comma_if.hpp>
# include <streams_boost/preprocessor/repetition/repeat.hpp>
# include <streams_boost/preprocessor/tuple/elem.hpp>
# include <streams_boost/preprocessor/tuple/rem.hpp>
#
# /* STREAMS_BOOST_PP_ENUM_SHIFTED_BINARY_PARAMS */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_ENUM_SHIFTED_BINARY_PARAMS(count, p1, p2) STREAMS_BOOST_PP_REPEAT(STREAMS_BOOST_PP_DEC(count), STREAMS_BOOST_PP_ENUM_SHIFTED_BINARY_PARAMS_M, (p1, p2))
# else
#    define STREAMS_BOOST_PP_ENUM_SHIFTED_BINARY_PARAMS(count, p1, p2) STREAMS_BOOST_PP_ENUM_SHIFTED_BINARY_PARAMS_I(count, p1, p2)
#    define STREAMS_BOOST_PP_ENUM_SHIFTED_BINARY_PARAMS_I(count, p1, p2) STREAMS_BOOST_PP_REPEAT(STREAMS_BOOST_PP_DEC(count), STREAMS_BOOST_PP_ENUM_SHIFTED_BINARY_PARAMS_M, (p1, p2))
# endif
#
# if STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_STRICT()
#    define STREAMS_BOOST_PP_ENUM_SHIFTED_BINARY_PARAMS_M(z, n, pp) STREAMS_BOOST_PP_ENUM_SHIFTED_BINARY_PARAMS_M_IM(z, n, STREAMS_BOOST_PP_TUPLE_REM_2 pp)
#    define STREAMS_BOOST_PP_ENUM_SHIFTED_BINARY_PARAMS_M_IM(z, n, im) STREAMS_BOOST_PP_ENUM_SHIFTED_BINARY_PARAMS_M_I(z, n, im)
# else
#    define STREAMS_BOOST_PP_ENUM_SHIFTED_BINARY_PARAMS_M(z, n, pp) STREAMS_BOOST_PP_ENUM_SHIFTED_BINARY_PARAMS_M_I(z, n, STREAMS_BOOST_PP_TUPLE_ELEM(2, 0, pp), STREAMS_BOOST_PP_TUPLE_ELEM(2, 1, pp))
# endif
#
# define STREAMS_BOOST_PP_ENUM_SHIFTED_BINARY_PARAMS_M_I(z, n, p1, p2) STREAMS_BOOST_PP_COMMA_IF(n) STREAMS_BOOST_PP_CAT(p1, STREAMS_BOOST_PP_INC(n)) STREAMS_BOOST_PP_CAT(p2, STREAMS_BOOST_PP_INC(n))
#
# /* STREAMS_BOOST_PP_ENUM_SHIFTED_BINARY_PARAMS_Z */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_ENUM_SHIFTED_BINARY_PARAMS_Z(z, count, p1, p2) STREAMS_BOOST_PP_REPEAT_ ## z(STREAMS_BOOST_PP_DEC(count), STREAMS_BOOST_PP_ENUM_SHIFTED_BINARY_PARAMS_M, (p1, p2))
# else
#    define STREAMS_BOOST_PP_ENUM_SHIFTED_BINARY_PARAMS_Z(z, count, p1, p2) STREAMS_BOOST_PP_ENUM_SHIFTED_BINARY_PARAMS_Z_I(z, count, p1, p2)
#    define STREAMS_BOOST_PP_ENUM_SHIFTED_BINARY_PARAMS_Z_I(z, count, p1, p2) STREAMS_BOOST_PP_REPEAT_ ## z(STREAMS_BOOST_PP_DEC(count), STREAMS_BOOST_PP_ENUM_SHIFTED_BINARY_PARAMS_M, (p1, p2))
# endif
#
# endif
