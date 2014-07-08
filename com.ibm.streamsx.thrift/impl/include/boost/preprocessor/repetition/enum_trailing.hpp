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
# ifndef STREAMS_BOOST_PREPROCESSOR_REPETITION_ENUM_TRAILING_HPP
# define STREAMS_BOOST_PREPROCESSOR_REPETITION_ENUM_TRAILING_HPP
#
# include <streams_boost/preprocessor/cat.hpp>
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/debug/error.hpp>
# include <streams_boost/preprocessor/detail/auto_rec.hpp>
# include <streams_boost/preprocessor/repetition/repeat.hpp>
# include <streams_boost/preprocessor/tuple/elem.hpp>
# include <streams_boost/preprocessor/tuple/rem.hpp>
#
# /* STREAMS_BOOST_PP_ENUM_TRAILING */
#
# if 0
#    define STREAMS_BOOST_PP_ENUM_TRAILING(count, macro, data)
# endif
#
# define STREAMS_BOOST_PP_ENUM_TRAILING STREAMS_BOOST_PP_CAT(STREAMS_BOOST_PP_ENUM_TRAILING_, STREAMS_BOOST_PP_AUTO_REC(STREAMS_BOOST_PP_REPEAT_P, 4))
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_ENUM_TRAILING_1(c, m, d) STREAMS_BOOST_PP_REPEAT_1(c, STREAMS_BOOST_PP_ENUM_TRAILING_M_1, (m, d))
#    define STREAMS_BOOST_PP_ENUM_TRAILING_2(c, m, d) STREAMS_BOOST_PP_REPEAT_2(c, STREAMS_BOOST_PP_ENUM_TRAILING_M_2, (m, d))
#    define STREAMS_BOOST_PP_ENUM_TRAILING_3(c, m, d) STREAMS_BOOST_PP_REPEAT_3(c, STREAMS_BOOST_PP_ENUM_TRAILING_M_3, (m, d))
# else
#    define STREAMS_BOOST_PP_ENUM_TRAILING_1(c, m, d) STREAMS_BOOST_PP_ENUM_TRAILING_1_I(c, m, d)
#    define STREAMS_BOOST_PP_ENUM_TRAILING_2(c, m, d) STREAMS_BOOST_PP_ENUM_TRAILING_2_I(c, m, d)
#    define STREAMS_BOOST_PP_ENUM_TRAILING_3(c, m, d) STREAMS_BOOST_PP_ENUM_TRAILING_3_I(c, m, d)
#    define STREAMS_BOOST_PP_ENUM_TRAILING_1_I(c, m, d) STREAMS_BOOST_PP_REPEAT_1(c, STREAMS_BOOST_PP_ENUM_TRAILING_M_1, (m, d))
#    define STREAMS_BOOST_PP_ENUM_TRAILING_2_I(c, m, d) STREAMS_BOOST_PP_REPEAT_2(c, STREAMS_BOOST_PP_ENUM_TRAILING_M_2, (m, d))
#    define STREAMS_BOOST_PP_ENUM_TRAILING_3_I(c, m, d) STREAMS_BOOST_PP_REPEAT_3(c, STREAMS_BOOST_PP_ENUM_TRAILING_M_3, (m, d))
# endif
#
# define STREAMS_BOOST_PP_ENUM_TRAILING_4(c, m, d) STREAMS_BOOST_PP_ERROR(0x0003)
#
# if STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_STRICT()
#    define STREAMS_BOOST_PP_ENUM_TRAILING_M_1(z, n, md) STREAMS_BOOST_PP_ENUM_TRAILING_M_1_IM(z, n, STREAMS_BOOST_PP_TUPLE_REM_2 md)
#    define STREAMS_BOOST_PP_ENUM_TRAILING_M_2(z, n, md) STREAMS_BOOST_PP_ENUM_TRAILING_M_2_IM(z, n, STREAMS_BOOST_PP_TUPLE_REM_2 md)
#    define STREAMS_BOOST_PP_ENUM_TRAILING_M_3(z, n, md) STREAMS_BOOST_PP_ENUM_TRAILING_M_3_IM(z, n, STREAMS_BOOST_PP_TUPLE_REM_2 md)
#    define STREAMS_BOOST_PP_ENUM_TRAILING_M_1_IM(z, n, im) STREAMS_BOOST_PP_ENUM_TRAILING_M_1_I(z, n, im)
#    define STREAMS_BOOST_PP_ENUM_TRAILING_M_2_IM(z, n, im) STREAMS_BOOST_PP_ENUM_TRAILING_M_2_I(z, n, im)
#    define STREAMS_BOOST_PP_ENUM_TRAILING_M_3_IM(z, n, im) STREAMS_BOOST_PP_ENUM_TRAILING_M_3_I(z, n, im)
# else
#    define STREAMS_BOOST_PP_ENUM_TRAILING_M_1(z, n, md) STREAMS_BOOST_PP_ENUM_TRAILING_M_1_I(z, n, STREAMS_BOOST_PP_TUPLE_ELEM(2, 0, md), STREAMS_BOOST_PP_TUPLE_ELEM(2, 1, md))
#    define STREAMS_BOOST_PP_ENUM_TRAILING_M_2(z, n, md) STREAMS_BOOST_PP_ENUM_TRAILING_M_2_I(z, n, STREAMS_BOOST_PP_TUPLE_ELEM(2, 0, md), STREAMS_BOOST_PP_TUPLE_ELEM(2, 1, md))
#    define STREAMS_BOOST_PP_ENUM_TRAILING_M_3(z, n, md) STREAMS_BOOST_PP_ENUM_TRAILING_M_3_I(z, n, STREAMS_BOOST_PP_TUPLE_ELEM(2, 0, md), STREAMS_BOOST_PP_TUPLE_ELEM(2, 1, md))
# endif
#
# define STREAMS_BOOST_PP_ENUM_TRAILING_M_1_I(z, n, m, d) , m(z, n, d)
# define STREAMS_BOOST_PP_ENUM_TRAILING_M_2_I(z, n, m, d) , m(z, n, d)
# define STREAMS_BOOST_PP_ENUM_TRAILING_M_3_I(z, n, m, d) , m(z, n, d)
#
# endif
