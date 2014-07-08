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
# ifndef STREAMS_BOOST_PREPROCESSOR_SEQ_REVERSE_HPP
# define STREAMS_BOOST_PREPROCESSOR_SEQ_REVERSE_HPP
#
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/facilities/empty.hpp>
# include <streams_boost/preprocessor/seq/fold_left.hpp>
#
# /* STREAMS_BOOST_PP_SEQ_REVERSE */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_SEQ_REVERSE(seq) STREAMS_BOOST_PP_SEQ_FOLD_LEFT(STREAMS_BOOST_PP_SEQ_REVERSE_O, STREAMS_BOOST_PP_EMPTY, seq)()
# else
#    define STREAMS_BOOST_PP_SEQ_REVERSE(seq) STREAMS_BOOST_PP_SEQ_REVERSE_I(seq)
#    define STREAMS_BOOST_PP_SEQ_REVERSE_I(seq) STREAMS_BOOST_PP_SEQ_FOLD_LEFT(STREAMS_BOOST_PP_SEQ_REVERSE_O, STREAMS_BOOST_PP_EMPTY, seq)()
# endif
#
# define STREAMS_BOOST_PP_SEQ_REVERSE_O(s, state, elem) (elem) state
#
# /* STREAMS_BOOST_PP_SEQ_REVERSE_S */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_SEQ_REVERSE_S(s, seq) STREAMS_BOOST_PP_SEQ_FOLD_LEFT_ ## s(STREAMS_BOOST_PP_SEQ_REVERSE_O, STREAMS_BOOST_PP_EMPTY, seq)()
# else
#    define STREAMS_BOOST_PP_SEQ_REVERSE_S(s, seq) STREAMS_BOOST_PP_SEQ_REVERSE_S_I(s, seq)
#    define STREAMS_BOOST_PP_SEQ_REVERSE_S_I(s, seq) STREAMS_BOOST_PP_SEQ_FOLD_LEFT_ ## s(STREAMS_BOOST_PP_SEQ_REVERSE_O, STREAMS_BOOST_PP_EMPTY, seq)()
# endif
#
# endif
