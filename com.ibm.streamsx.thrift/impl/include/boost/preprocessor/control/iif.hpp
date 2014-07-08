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
# ifndef STREAMS_BOOST_PREPROCESSOR_CONTROL_IIF_HPP
# define STREAMS_BOOST_PREPROCESSOR_CONTROL_IIF_HPP
#
# include <streams_boost/preprocessor/config/config.hpp>
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_MWCC()
#    define STREAMS_BOOST_PP_IIF(bit, t, f) STREAMS_BOOST_PP_IIF_I(bit, t, f)
# else
#    define STREAMS_BOOST_PP_IIF(bit, t, f) STREAMS_BOOST_PP_IIF_OO((bit, t, f))
#    define STREAMS_BOOST_PP_IIF_OO(par) STREAMS_BOOST_PP_IIF_I ## par
# endif
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_MSVC()
#    define STREAMS_BOOST_PP_IIF_I(bit, t, f) STREAMS_BOOST_PP_IIF_ ## bit(t, f)
# else
#    define STREAMS_BOOST_PP_IIF_I(bit, t, f) STREAMS_BOOST_PP_IIF_II(STREAMS_BOOST_PP_IIF_ ## bit(t, f))
#    define STREAMS_BOOST_PP_IIF_II(id) id
# endif
#
# define STREAMS_BOOST_PP_IIF_0(t, f) f
# define STREAMS_BOOST_PP_IIF_1(t, f) t
#
# endif
