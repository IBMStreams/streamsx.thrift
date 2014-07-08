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
# ifndef STREAMS_BOOST_PREPROCESSOR_PUNCTUATION_PAREN_IF_HPP
# define STREAMS_BOOST_PREPROCESSOR_PUNCTUATION_PAREN_IF_HPP
#
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/control/if.hpp>
# include <streams_boost/preprocessor/facilities/empty.hpp>
# include <streams_boost/preprocessor/punctuation/paren.hpp>
#
# /* STREAMS_BOOST_PP_LPAREN_IF */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_LPAREN_IF(cond) STREAMS_BOOST_PP_IF(cond, STREAMS_BOOST_PP_LPAREN, STREAMS_BOOST_PP_EMPTY)()
# else
#    define STREAMS_BOOST_PP_LPAREN_IF(cond) STREAMS_BOOST_PP_LPAREN_IF_I(cond)
#    define STREAMS_BOOST_PP_LPAREN_IF_I(cond) STREAMS_BOOST_PP_IF(cond, STREAMS_BOOST_PP_LPAREN, STREAMS_BOOST_PP_EMPTY)()
# endif
#
# /* STREAMS_BOOST_PP_RPAREN_IF */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_RPAREN_IF(cond) STREAMS_BOOST_PP_IF(cond, STREAMS_BOOST_PP_RPAREN, STREAMS_BOOST_PP_EMPTY)()
# else
#    define STREAMS_BOOST_PP_RPAREN_IF(cond) STREAMS_BOOST_PP_RPAREN_IF_I(cond)
#    define STREAMS_BOOST_PP_RPAREN_IF_I(cond) STREAMS_BOOST_PP_IF(cond, STREAMS_BOOST_PP_RPAREN, STREAMS_BOOST_PP_EMPTY)()
# endif
#
# endif
