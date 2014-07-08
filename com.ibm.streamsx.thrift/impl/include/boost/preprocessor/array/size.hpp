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
# ifndef STREAMS_BOOST_PREPROCESSOR_ARRAY_SIZE_HPP
# define STREAMS_BOOST_PREPROCESSOR_ARRAY_SIZE_HPP
#
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/tuple/elem.hpp>
#
# /* STREAMS_BOOST_PP_ARRAY_SIZE */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_ARRAY_SIZE(array) STREAMS_BOOST_PP_TUPLE_ELEM(2, 0, array)
# else
#    define STREAMS_BOOST_PP_ARRAY_SIZE(array) STREAMS_BOOST_PP_ARRAY_SIZE_I(array)
#    define STREAMS_BOOST_PP_ARRAY_SIZE_I(array) STREAMS_BOOST_PP_ARRAY_SIZE_II array
#    define STREAMS_BOOST_PP_ARRAY_SIZE_II(size, data) size
# endif
#
# endif
