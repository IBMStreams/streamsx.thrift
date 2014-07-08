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
# ifndef STREAMS_BOOST_PREPROCESSOR_ARRAY_ELEM_HPP
# define STREAMS_BOOST_PREPROCESSOR_ARRAY_ELEM_HPP
#
# include <streams_boost/preprocessor/array/data.hpp>
# include <streams_boost/preprocessor/array/size.hpp>
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/tuple/elem.hpp>
#
# /* STREAMS_BOOST_PP_ARRAY_ELEM */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_ARRAY_ELEM(i, array) STREAMS_BOOST_PP_TUPLE_ELEM(STREAMS_BOOST_PP_ARRAY_SIZE(array), i, STREAMS_BOOST_PP_ARRAY_DATA(array))
# else
#    define STREAMS_BOOST_PP_ARRAY_ELEM(i, array) STREAMS_BOOST_PP_ARRAY_ELEM_I(i, array)
#    define STREAMS_BOOST_PP_ARRAY_ELEM_I(i, array) STREAMS_BOOST_PP_TUPLE_ELEM(STREAMS_BOOST_PP_ARRAY_SIZE(array), i, STREAMS_BOOST_PP_ARRAY_DATA(array))
# endif
#
# endif
