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
# ifndef STREAMS_BOOST_PREPROCESSOR_SEQ_FIRST_N_HPP
# define STREAMS_BOOST_PREPROCESSOR_SEQ_FIRST_N_HPP
#
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/control/if.hpp>
# include <streams_boost/preprocessor/seq/detail/split.hpp>
# include <streams_boost/preprocessor/tuple/eat.hpp>
# include <streams_boost/preprocessor/tuple/elem.hpp>
#
# /* STREAMS_BOOST_PP_SEQ_FIRST_N */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_SEQ_FIRST_N(n, seq) STREAMS_BOOST_PP_IF(n, STREAMS_BOOST_PP_TUPLE_ELEM, STREAMS_BOOST_PP_TUPLE_EAT_3)(2, 0, STREAMS_BOOST_PP_SEQ_SPLIT(n, seq (nil)))
# else
#    define STREAMS_BOOST_PP_SEQ_FIRST_N(n, seq) STREAMS_BOOST_PP_SEQ_FIRST_N_I(n, seq)
#    define STREAMS_BOOST_PP_SEQ_FIRST_N_I(n, seq) STREAMS_BOOST_PP_IF(n, STREAMS_BOOST_PP_TUPLE_ELEM, STREAMS_BOOST_PP_TUPLE_EAT_3)(2, 0, STREAMS_BOOST_PP_SEQ_SPLIT(n, seq (nil)))
# endif
#
# endif
