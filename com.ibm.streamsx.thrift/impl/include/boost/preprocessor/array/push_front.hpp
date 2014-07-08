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
# ifndef STREAMS_BOOST_PREPROCESSOR_ARRAY_PUSH_FRONT_HPP
# define STREAMS_BOOST_PREPROCESSOR_ARRAY_PUSH_FRONT_HPP
#
# include <streams_boost/preprocessor/arithmetic/inc.hpp>
# include <streams_boost/preprocessor/array/data.hpp>
# include <streams_boost/preprocessor/array/size.hpp>
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/punctuation/comma_if.hpp>
# include <streams_boost/preprocessor/tuple/rem.hpp>
#
# /* STREAMS_BOOST_PP_ARRAY_PUSH_FRONT */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_ARRAY_PUSH_FRONT(array, elem) STREAMS_BOOST_PP_ARRAY_PUSH_FRONT_I(STREAMS_BOOST_PP_ARRAY_SIZE(array), STREAMS_BOOST_PP_ARRAY_DATA(array), elem)
# else
#    define STREAMS_BOOST_PP_ARRAY_PUSH_FRONT(array, elem) STREAMS_BOOST_PP_ARRAY_PUSH_FRONT_D(array, elem)
#    define STREAMS_BOOST_PP_ARRAY_PUSH_FRONT_D(array, elem) STREAMS_BOOST_PP_ARRAY_PUSH_FRONT_I(STREAMS_BOOST_PP_ARRAY_SIZE(array), STREAMS_BOOST_PP_ARRAY_DATA(array), elem)
# endif
#
# define STREAMS_BOOST_PP_ARRAY_PUSH_FRONT_I(size, data, elem) (STREAMS_BOOST_PP_INC(size), (elem STREAMS_BOOST_PP_COMMA_IF(size) STREAMS_BOOST_PP_TUPLE_REM(size) data))
#
# endif
