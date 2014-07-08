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
# ifndef STREAMS_BOOST_PREPROCESSOR_ARRAY_POP_BACK_HPP
# define STREAMS_BOOST_PREPROCESSOR_ARRAY_POP_BACK_HPP
#
# include <streams_boost/preprocessor/arithmetic/dec.hpp>
# include <streams_boost/preprocessor/array/elem.hpp>
# include <streams_boost/preprocessor/array/size.hpp>
# include <streams_boost/preprocessor/repetition/enum.hpp>
# include <streams_boost/preprocessor/repetition/deduce_z.hpp>
#
# /* STREAMS_BOOST_PP_ARRAY_POP_BACK */
#
# define STREAMS_BOOST_PP_ARRAY_POP_BACK(array) STREAMS_BOOST_PP_ARRAY_POP_BACK_Z(STREAMS_BOOST_PP_DEDUCE_Z(), array)
#
# /* STREAMS_BOOST_PP_ARRAY_POP_BACK_Z */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_ARRAY_POP_BACK_Z(z, array) STREAMS_BOOST_PP_ARRAY_POP_BACK_I(z, STREAMS_BOOST_PP_ARRAY_SIZE(array), array)
# else
#    define STREAMS_BOOST_PP_ARRAY_POP_BACK_Z(z, array) STREAMS_BOOST_PP_ARRAY_POP_BACK_Z_D(z, array)
#    define STREAMS_BOOST_PP_ARRAY_POP_BACK_Z_D(z, array) STREAMS_BOOST_PP_ARRAY_POP_BACK_I(z, STREAMS_BOOST_PP_ARRAY_SIZE(array), array)
# endif
#
# define STREAMS_BOOST_PP_ARRAY_POP_BACK_I(z, size, array) (STREAMS_BOOST_PP_DEC(size), (STREAMS_BOOST_PP_ENUM_ ## z(STREAMS_BOOST_PP_DEC(size), STREAMS_BOOST_PP_ARRAY_POP_BACK_M, array)))
# define STREAMS_BOOST_PP_ARRAY_POP_BACK_M(z, n, data) STREAMS_BOOST_PP_ARRAY_ELEM(n, data)
#
# endif
