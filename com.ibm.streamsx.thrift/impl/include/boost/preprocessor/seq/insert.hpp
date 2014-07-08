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
# ifndef STREAMS_BOOST_PREPROCESSOR_SEQ_INSERT_HPP
# define STREAMS_BOOST_PREPROCESSOR_SEQ_INSERT_HPP
#
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/seq/first_n.hpp>
# include <streams_boost/preprocessor/seq/rest_n.hpp>
#
# /* STREAMS_BOOST_PP_SEQ_INSERT */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_SEQ_INSERT(seq, i, elem) STREAMS_BOOST_PP_SEQ_FIRST_N(i, seq) (elem) STREAMS_BOOST_PP_SEQ_REST_N(i, seq)
# else
#    define STREAMS_BOOST_PP_SEQ_INSERT(seq, i, elem) STREAMS_BOOST_PP_SEQ_INSERT_I(seq, i, elem)
#    define STREAMS_BOOST_PP_SEQ_INSERT_I(seq, i, elem) STREAMS_BOOST_PP_SEQ_FIRST_N(i, seq) (elem) STREAMS_BOOST_PP_SEQ_REST_N(i, seq)
# endif
#
# endif
