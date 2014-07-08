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
# ifndef STREAMS_BOOST_PREPROCESSOR_ARRAY_POP_FRONT_HPP
# define STREAMS_BOOST_PREPROCESSOR_ARRAY_POP_FRONT_HPP
#
# include <streams_boost/preprocessor/arithmetic/dec.hpp>
# include <streams_boost/preprocessor/arithmetic/inc.hpp>
# include <streams_boost/preprocessor/array/elem.hpp>
# include <streams_boost/preprocessor/array/size.hpp>
# include <streams_boost/preprocessor/repetition/enum.hpp>
# include <streams_boost/preprocessor/repetition/deduce_z.hpp>
#
# /* STREAMS_BOOST_PP_ARRAY_POP_FRONT */
#
# define STREAMS_BOOST_PP_ARRAY_POP_FRONT(array) STREAMS_BOOST_PP_ARRAY_POP_FRONT_Z(STREAMS_BOOST_PP_DEDUCE_Z(), array)
#
# /* STREAMS_BOOST_PP_ARRAY_POP_FRONT_Z */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_ARRAY_POP_FRONT_Z(z, array) STREAMS_BOOST_PP_ARRAY_POP_FRONT_I(z, STREAMS_BOOST_PP_ARRAY_SIZE(array), array)
# else
#    define STREAMS_BOOST_PP_ARRAY_POP_FRONT_Z(z, array) STREAMS_BOOST_PP_ARRAY_POP_FRONT_Z_D(z, array)
#    define STREAMS_BOOST_PP_ARRAY_POP_FRONT_Z_D(z, array) STREAMS_BOOST_PP_ARRAY_POP_FRONT_I(z, STREAMS_BOOST_PP_ARRAY_SIZE(array), array)
# endif
#
# define STREAMS_BOOST_PP_ARRAY_POP_FRONT_I(z, size, array) (STREAMS_BOOST_PP_DEC(size), (STREAMS_BOOST_PP_ENUM_ ## z(STREAMS_BOOST_PP_DEC(size), STREAMS_BOOST_PP_ARRAY_POP_FRONT_M, array)))
# define STREAMS_BOOST_PP_ARRAY_POP_FRONT_M(z, n, data) STREAMS_BOOST_PP_ARRAY_ELEM(STREAMS_BOOST_PP_INC(n), data)
#
# endif
