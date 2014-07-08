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
# ifndef STREAMS_BOOST_PREPROCESSOR_DEBUG_ERROR_HPP
# define STREAMS_BOOST_PREPROCESSOR_DEBUG_ERROR_HPP
#
# include <streams_boost/preprocessor/cat.hpp>
# include <streams_boost/preprocessor/config/config.hpp>
#
# /* STREAMS_BOOST_PP_ERROR */
#
# if STREAMS_BOOST_PP_CONFIG_ERRORS
#    define STREAMS_BOOST_PP_ERROR(code) STREAMS_BOOST_PP_CAT(STREAMS_BOOST_PP_ERROR_, code)
# endif
#
# define STREAMS_BOOST_PP_ERROR_0x0000 STREAMS_BOOST_PP_ERROR(0x0000, STREAMS_BOOST_PP_INDEX_OUT_OF_BOUNDS)
# define STREAMS_BOOST_PP_ERROR_0x0001 STREAMS_BOOST_PP_ERROR(0x0001, STREAMS_BOOST_PP_WHILE_OVERFLOW)
# define STREAMS_BOOST_PP_ERROR_0x0002 STREAMS_BOOST_PP_ERROR(0x0002, STREAMS_BOOST_PP_FOR_OVERFLOW)
# define STREAMS_BOOST_PP_ERROR_0x0003 STREAMS_BOOST_PP_ERROR(0x0003, STREAMS_BOOST_PP_REPEAT_OVERFLOW)
# define STREAMS_BOOST_PP_ERROR_0x0004 STREAMS_BOOST_PP_ERROR(0x0004, STREAMS_BOOST_PP_LIST_FOLD_OVERFLOW)
# define STREAMS_BOOST_PP_ERROR_0x0005 STREAMS_BOOST_PP_ERROR(0x0005, STREAMS_BOOST_PP_SEQ_FOLD_OVERFLOW)
# define STREAMS_BOOST_PP_ERROR_0x0006 STREAMS_BOOST_PP_ERROR(0x0006, STREAMS_BOOST_PP_ARITHMETIC_OVERFLOW)
# define STREAMS_BOOST_PP_ERROR_0x0007 STREAMS_BOOST_PP_ERROR(0x0007, STREAMS_BOOST_PP_DIVISION_BY_ZERO)
#
# endif
