# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Paul Mensonides 2002.
#  *     Distributed under the Boost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.streams_boost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# ifndef STREAMS_BOOST_PREPROCESSOR_DETAIL_SPLIT_HPP
# define STREAMS_BOOST_PREPROCESSOR_DETAIL_SPLIT_HPP
#
# include <streams_boost/preprocessor/config/config.hpp>
#
# /* STREAMS_BOOST_PP_SPLIT */
#
# if STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_MWCC()
#    define STREAMS_BOOST_PP_SPLIT(n, im) STREAMS_BOOST_PP_SPLIT_I((n, im))
#    define STREAMS_BOOST_PP_SPLIT_I(par) STREAMS_BOOST_PP_SPLIT_II ## par
#    define STREAMS_BOOST_PP_SPLIT_II(n, a, b) STREAMS_BOOST_PP_SPLIT_ ## n(a, b)
# elif STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_MSVC()
#    define STREAMS_BOOST_PP_SPLIT(n, im) STREAMS_BOOST_PP_SPLIT_I(n((im)))
#    define STREAMS_BOOST_PP_SPLIT_I(n) STREAMS_BOOST_PP_SPLIT_ID(STREAMS_BOOST_PP_SPLIT_II_ ## n)
#    define STREAMS_BOOST_PP_SPLIT_II_0(s) STREAMS_BOOST_PP_SPLIT_ID(STREAMS_BOOST_PP_SPLIT_0 s)
#    define STREAMS_BOOST_PP_SPLIT_II_1(s) STREAMS_BOOST_PP_SPLIT_ID(STREAMS_BOOST_PP_SPLIT_1 s)
#    define STREAMS_BOOST_PP_SPLIT_ID(id) id
# else
#    define STREAMS_BOOST_PP_SPLIT(n, im) STREAMS_BOOST_PP_SPLIT_I(n)(im)
#    define STREAMS_BOOST_PP_SPLIT_I(n) STREAMS_BOOST_PP_SPLIT_ ## n
# endif
#
# define STREAMS_BOOST_PP_SPLIT_0(a, b) a
# define STREAMS_BOOST_PP_SPLIT_1(a, b) b
#
# endif
