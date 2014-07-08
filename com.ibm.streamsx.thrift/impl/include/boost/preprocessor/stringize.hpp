# /* Copyright (C) 2001
#  * Housemarque Oy
#  * http://www.housemarque.com
#  *
#  * Distributed under the Boost Software License, Version 1.0. (See
#  * accompanying file LICENSE_1_0.txt or copy at
#  * http://www.streams_boost.org/LICENSE_1_0.txt)
#  */
#
# /* Revised by Paul Mensonides (2002) */
#
# /* See http://www.streams_boost.org for most recent version. */
#
# ifndef STREAMS_BOOST_PREPROCESSOR_STRINGIZE_HPP
# define STREAMS_BOOST_PREPROCESSOR_STRINGIZE_HPP
#
# include <streams_boost/preprocessor/config/config.hpp>
#
# /* STREAMS_BOOST_PP_STRINGIZE */
#
# if STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_MSVC()
#    define STREAMS_BOOST_PP_STRINGIZE(text) STREAMS_BOOST_PP_STRINGIZE_A((text))
#    define STREAMS_BOOST_PP_STRINGIZE_A(arg) STREAMS_BOOST_PP_STRINGIZE_I arg
# elif STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_MWCC()
#    define STREAMS_BOOST_PP_STRINGIZE(text) STREAMS_BOOST_PP_STRINGIZE_OO((text))
#    define STREAMS_BOOST_PP_STRINGIZE_OO(par) STREAMS_BOOST_PP_STRINGIZE_I ## par
# else
#    define STREAMS_BOOST_PP_STRINGIZE(text) STREAMS_BOOST_PP_STRINGIZE_I(text)
# endif
#
# define STREAMS_BOOST_PP_STRINGIZE_I(text) #text
#
# endif
