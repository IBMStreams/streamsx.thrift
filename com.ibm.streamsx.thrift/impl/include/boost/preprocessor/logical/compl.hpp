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
# ifndef STREAMS_BOOST_PREPROCESSOR_LOGICAL_COMPL_HPP
# define STREAMS_BOOST_PREPROCESSOR_LOGICAL_COMPL_HPP
#
# include <streams_boost/preprocessor/config/config.hpp>
#
# /* STREAMS_BOOST_PP_COMPL */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_MWCC()
#    define STREAMS_BOOST_PP_COMPL(x) STREAMS_BOOST_PP_COMPL_I(x)
# else
#    define STREAMS_BOOST_PP_COMPL(x) STREAMS_BOOST_PP_COMPL_OO((x))
#    define STREAMS_BOOST_PP_COMPL_OO(par) STREAMS_BOOST_PP_COMPL_I ## par
# endif
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_MSVC()
#    define STREAMS_BOOST_PP_COMPL_I(x) STREAMS_BOOST_PP_COMPL_ ## x
# else
#    define STREAMS_BOOST_PP_COMPL_I(x) STREAMS_BOOST_PP_COMPL_ID(STREAMS_BOOST_PP_COMPL_ ## x)
#    define STREAMS_BOOST_PP_COMPL_ID(id) id
# endif
#
# define STREAMS_BOOST_PP_COMPL_0 1
# define STREAMS_BOOST_PP_COMPL_1 0
#
# endif
