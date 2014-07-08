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
# ifndef STREAMS_BOOST_PREPROCESSOR_SEQ_REST_N_HPP
# define STREAMS_BOOST_PREPROCESSOR_SEQ_REST_N_HPP
#
# include <streams_boost/preprocessor/arithmetic/inc.hpp>
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/facilities/empty.hpp>
# include <streams_boost/preprocessor/seq/detail/split.hpp>
# include <streams_boost/preprocessor/tuple/elem.hpp>
#
# /* STREAMS_BOOST_PP_SEQ_REST_N */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_SEQ_REST_N(n, seq) STREAMS_BOOST_PP_TUPLE_ELEM(2, 1, STREAMS_BOOST_PP_SEQ_SPLIT(STREAMS_BOOST_PP_INC(n), (nil) seq STREAMS_BOOST_PP_EMPTY))()
# else
#    define STREAMS_BOOST_PP_SEQ_REST_N(n, seq) STREAMS_BOOST_PP_SEQ_REST_N_I(n, seq)
#    define STREAMS_BOOST_PP_SEQ_REST_N_I(n, seq) STREAMS_BOOST_PP_TUPLE_ELEM(2, 1, STREAMS_BOOST_PP_SEQ_SPLIT(STREAMS_BOOST_PP_INC(n), (nil) seq STREAMS_BOOST_PP_EMPTY))()
# endif
#
# endif
