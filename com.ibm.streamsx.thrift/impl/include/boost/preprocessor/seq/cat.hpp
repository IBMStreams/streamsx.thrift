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
# ifndef STREAMS_BOOST_PREPROCESSOR_SEQ_CAT_HPP
# define STREAMS_BOOST_PREPROCESSOR_SEQ_CAT_HPP
#
# include <streams_boost/preprocessor/arithmetic/dec.hpp>
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/control/if.hpp>
# include <streams_boost/preprocessor/seq/fold_left.hpp>
# include <streams_boost/preprocessor/seq/seq.hpp>
# include <streams_boost/preprocessor/seq/size.hpp>
# include <streams_boost/preprocessor/tuple/eat.hpp>
#
# /* STREAMS_BOOST_PP_SEQ_CAT */
#
# define STREAMS_BOOST_PP_SEQ_CAT(seq) \
    STREAMS_BOOST_PP_IF( \
        STREAMS_BOOST_PP_DEC(STREAMS_BOOST_PP_SEQ_SIZE(seq)), \
        STREAMS_BOOST_PP_SEQ_CAT_I, \
        STREAMS_BOOST_PP_SEQ_HEAD(seq) STREAMS_BOOST_PP_TUPLE_EAT_1 \
    )(seq) \
    /**/
# define STREAMS_BOOST_PP_SEQ_CAT_I(seq) STREAMS_BOOST_PP_SEQ_FOLD_LEFT(STREAMS_BOOST_PP_SEQ_CAT_O, STREAMS_BOOST_PP_SEQ_HEAD(seq), STREAMS_BOOST_PP_SEQ_TAIL(seq))
#
# define STREAMS_BOOST_PP_SEQ_CAT_O(s, st, elem) STREAMS_BOOST_PP_SEQ_CAT_O_I(st, elem)
# define STREAMS_BOOST_PP_SEQ_CAT_O_I(a, b) a ## b
#
# /* STREAMS_BOOST_PP_SEQ_CAT_S */
#
# define STREAMS_BOOST_PP_SEQ_CAT_S(s, seq) \
    STREAMS_BOOST_PP_IF( \
        STREAMS_BOOST_PP_DEC(STREAMS_BOOST_PP_SEQ_SIZE(seq)), \
        STREAMS_BOOST_PP_SEQ_CAT_S_I, \
        STREAMS_BOOST_PP_SEQ_HEAD(seq) STREAMS_BOOST_PP_TUPLE_EAT_2 \
    )(s, seq) \
    /**/
# define STREAMS_BOOST_PP_SEQ_CAT_S_I(s, seq) STREAMS_BOOST_PP_SEQ_FOLD_LEFT_ ## s(STREAMS_BOOST_PP_SEQ_CAT_O, STREAMS_BOOST_PP_SEQ_HEAD(seq), STREAMS_BOOST_PP_SEQ_TAIL(seq))
#
# endif
