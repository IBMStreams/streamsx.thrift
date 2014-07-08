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
# ifndef STREAMS_BOOST_PREPROCESSOR_ARRAY_REVERSE_HPP
# define STREAMS_BOOST_PREPROCESSOR_ARRAY_REVERSE_HPP
#
# include <streams_boost/preprocessor/array/data.hpp>
# include <streams_boost/preprocessor/array/size.hpp>
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/tuple/reverse.hpp>
#
# /* STREAMS_BOOST_PP_ARRAY_REVERSE */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_ARRAY_REVERSE(array) (STREAMS_BOOST_PP_ARRAY_SIZE(array), STREAMS_BOOST_PP_TUPLE_REVERSE(STREAMS_BOOST_PP_ARRAY_SIZE(array), STREAMS_BOOST_PP_ARRAY_DATA(array)))
# else
#    define STREAMS_BOOST_PP_ARRAY_REVERSE(array) STREAMS_BOOST_PP_ARRAY_REVERSE_I(array)
#    define STREAMS_BOOST_PP_ARRAY_REVERSE_I(array) (STREAMS_BOOST_PP_ARRAY_SIZE(array), STREAMS_BOOST_PP_TUPLE_REVERSE(STREAMS_BOOST_PP_ARRAY_SIZE(array), STREAMS_BOOST_PP_ARRAY_DATA(array)))
# endif
#
# endif
