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
# ifndef STREAMS_BOOST_PREPROCESSOR_WSTRINGIZE_HPP
# define STREAMS_BOOST_PREPROCESSOR_WSTRINGIZE_HPP
#
# include <streams_boost/preprocessor/config/config.hpp>
#
# /* STREAMS_BOOST_PP_WSTRINGIZE */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_MWCC()
#    define STREAMS_BOOST_PP_WSTRINGIZE(text) STREAMS_BOOST_PP_WSTRINGIZE_I(text)
# else
#    define STREAMS_BOOST_PP_WSTRINGIZE(text) STREAMS_BOOST_PP_WSTRINGIZE_OO((text))
#    define STREAMS_BOOST_PP_WSTRINGIZE_OO(par) STREAMS_BOOST_PP_WSTRINGIZE_I ## par
# endif
#
# define STREAMS_BOOST_PP_WSTRINGIZE_I(text) STREAMS_BOOST_PP_WSTRINGIZE_II(#text)
# define STREAMS_BOOST_PP_WSTRINGIZE_II(str) L ## str
#
# endif
