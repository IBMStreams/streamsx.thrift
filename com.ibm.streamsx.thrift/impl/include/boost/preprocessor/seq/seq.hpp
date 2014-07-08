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
# ifndef STREAMS_BOOST_PREPROCESSOR_SEQ_SEQ_HPP
# define STREAMS_BOOST_PREPROCESSOR_SEQ_SEQ_HPP
#
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/seq/elem.hpp>
#
# /* STREAMS_BOOST_PP_SEQ_HEAD */
#
# define STREAMS_BOOST_PP_SEQ_HEAD(seq) STREAMS_BOOST_PP_SEQ_ELEM(0, seq)
#
# /* STREAMS_BOOST_PP_SEQ_TAIL */
#
# if STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_MWCC()
#    define STREAMS_BOOST_PP_SEQ_TAIL(seq) STREAMS_BOOST_PP_SEQ_TAIL_1((seq))
#    define STREAMS_BOOST_PP_SEQ_TAIL_1(par) STREAMS_BOOST_PP_SEQ_TAIL_2 ## par
#    define STREAMS_BOOST_PP_SEQ_TAIL_2(seq) STREAMS_BOOST_PP_SEQ_TAIL_I ## seq
# elif STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_MSVC()
#    define STREAMS_BOOST_PP_SEQ_TAIL(seq) STREAMS_BOOST_PP_SEQ_TAIL_ID(STREAMS_BOOST_PP_SEQ_TAIL_I seq)
#    define STREAMS_BOOST_PP_SEQ_TAIL_ID(id) id
# elif STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_SEQ_TAIL(seq) STREAMS_BOOST_PP_SEQ_TAIL_D(seq)
#    define STREAMS_BOOST_PP_SEQ_TAIL_D(seq) STREAMS_BOOST_PP_SEQ_TAIL_I seq
# else
#    define STREAMS_BOOST_PP_SEQ_TAIL(seq) STREAMS_BOOST_PP_SEQ_TAIL_I seq
# endif
#
# define STREAMS_BOOST_PP_SEQ_TAIL_I(x)
#
# /* STREAMS_BOOST_PP_SEQ_NIL */
#
# define STREAMS_BOOST_PP_SEQ_NIL(x) (x)
#
# endif
