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
# ifndef STREAMS_BOOST_PREPROCESSOR_LOGICAL_BITOR_HPP
# define STREAMS_BOOST_PREPROCESSOR_LOGICAL_BITOR_HPP
#
# include <streams_boost/preprocessor/config/config.hpp>
#
# /* STREAMS_BOOST_PP_BITOR */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_MWCC()
#    define STREAMS_BOOST_PP_BITOR(x, y) STREAMS_BOOST_PP_BITOR_I(x, y)
# else
#    define STREAMS_BOOST_PP_BITOR(x, y) STREAMS_BOOST_PP_BITOR_OO((x, y))
#    define STREAMS_BOOST_PP_BITOR_OO(par) STREAMS_BOOST_PP_BITOR_I ## par
# endif
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_MSVC()
#    define STREAMS_BOOST_PP_BITOR_I(x, y) STREAMS_BOOST_PP_BITOR_ ## x ## y
# else
#    define STREAMS_BOOST_PP_BITOR_I(x, y) STREAMS_BOOST_PP_BITOR_ID(STREAMS_BOOST_PP_BITOR_ ## x ## y)
#    define STREAMS_BOOST_PP_BITOR_ID(id) id
# endif
#
# define STREAMS_BOOST_PP_BITOR_00 0
# define STREAMS_BOOST_PP_BITOR_01 1
# define STREAMS_BOOST_PP_BITOR_10 1
# define STREAMS_BOOST_PP_BITOR_11 1
#
# endif
