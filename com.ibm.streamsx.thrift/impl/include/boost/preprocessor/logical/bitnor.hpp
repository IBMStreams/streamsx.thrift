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
# ifndef STREAMS_BOOST_PREPROCESSOR_LOGICAL_BITNOR_HPP
# define STREAMS_BOOST_PREPROCESSOR_LOGICAL_BITNOR_HPP
#
# include <streams_boost/preprocessor/config/config.hpp>
#
# /* STREAMS_BOOST_PP_BITNOR */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_MWCC()
#    define STREAMS_BOOST_PP_BITNOR(x, y) STREAMS_BOOST_PP_BITNOR_I(x, y)
# else
#    define STREAMS_BOOST_PP_BITNOR(x, y) STREAMS_BOOST_PP_BITNOR_OO((x, y))
#    define STREAMS_BOOST_PP_BITNOR_OO(par) STREAMS_BOOST_PP_BITNOR_I ## par
# endif
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_MSVC()
#    define STREAMS_BOOST_PP_BITNOR_I(x, y) STREAMS_BOOST_PP_BITNOR_ ## x ## y
# else
#    define STREAMS_BOOST_PP_BITNOR_I(x, y) STREAMS_BOOST_PP_BITNOR_ID(STREAMS_BOOST_PP_BITNOR_ ## x ## y)
#    define STREAMS_BOOST_PP_BITNOR_ID(id) id
# endif
#
# define STREAMS_BOOST_PP_BITNOR_00 1
# define STREAMS_BOOST_PP_BITNOR_01 0
# define STREAMS_BOOST_PP_BITNOR_10 0
# define STREAMS_BOOST_PP_BITNOR_11 0
#
# endif
