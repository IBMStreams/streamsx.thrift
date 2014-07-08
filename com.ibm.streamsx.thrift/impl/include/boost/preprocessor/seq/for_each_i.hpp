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
# ifndef STREAMS_BOOST_PREPROCESSOR_SEQ_FOR_EACH_I_HPP
# define STREAMS_BOOST_PREPROCESSOR_SEQ_FOR_EACH_I_HPP
#
# include <streams_boost/preprocessor/arithmetic/dec.hpp>
# include <streams_boost/preprocessor/arithmetic/inc.hpp>
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/repetition/for.hpp>
# include <streams_boost/preprocessor/seq/seq.hpp>
# include <streams_boost/preprocessor/seq/size.hpp>
# include <streams_boost/preprocessor/tuple/elem.hpp>
# include <streams_boost/preprocessor/tuple/rem.hpp>
#
# /* STREAMS_BOOST_PP_SEQ_FOR_EACH_I */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_SEQ_FOR_EACH_I(macro, data, seq) STREAMS_BOOST_PP_FOR((macro, data, seq (nil), 0), STREAMS_BOOST_PP_SEQ_FOR_EACH_I_P, STREAMS_BOOST_PP_SEQ_FOR_EACH_I_O, STREAMS_BOOST_PP_SEQ_FOR_EACH_I_M)
# else
#    define STREAMS_BOOST_PP_SEQ_FOR_EACH_I(macro, data, seq) STREAMS_BOOST_PP_SEQ_FOR_EACH_I_I(macro, data, seq)
#    define STREAMS_BOOST_PP_SEQ_FOR_EACH_I_I(macro, data, seq) STREAMS_BOOST_PP_FOR((macro, data, seq (nil), 0), STREAMS_BOOST_PP_SEQ_FOR_EACH_I_P, STREAMS_BOOST_PP_SEQ_FOR_EACH_I_O, STREAMS_BOOST_PP_SEQ_FOR_EACH_I_M)
# endif
#
# define STREAMS_BOOST_PP_SEQ_FOR_EACH_I_P(r, x) STREAMS_BOOST_PP_DEC(STREAMS_BOOST_PP_SEQ_SIZE(STREAMS_BOOST_PP_TUPLE_ELEM(4, 2, x)))
#
# if STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_STRICT()
#    define STREAMS_BOOST_PP_SEQ_FOR_EACH_I_O(r, x) STREAMS_BOOST_PP_SEQ_FOR_EACH_I_O_I x
# else
#    define STREAMS_BOOST_PP_SEQ_FOR_EACH_I_O(r, x) STREAMS_BOOST_PP_SEQ_FOR_EACH_I_O_I(STREAMS_BOOST_PP_TUPLE_ELEM(4, 0, x), STREAMS_BOOST_PP_TUPLE_ELEM(4, 1, x), STREAMS_BOOST_PP_TUPLE_ELEM(4, 2, x), STREAMS_BOOST_PP_TUPLE_ELEM(4, 3, x))
# endif
#
# define STREAMS_BOOST_PP_SEQ_FOR_EACH_I_O_I(macro, data, seq, i) (macro, data, STREAMS_BOOST_PP_SEQ_TAIL(seq), STREAMS_BOOST_PP_INC(i))
#
# if STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_STRICT()
#    define STREAMS_BOOST_PP_SEQ_FOR_EACH_I_M(r, x) STREAMS_BOOST_PP_SEQ_FOR_EACH_I_M_IM(r, STREAMS_BOOST_PP_TUPLE_REM_4 x)
#    define STREAMS_BOOST_PP_SEQ_FOR_EACH_I_M_IM(r, im) STREAMS_BOOST_PP_SEQ_FOR_EACH_I_M_I(r, im)
# else
#    define STREAMS_BOOST_PP_SEQ_FOR_EACH_I_M(r, x) STREAMS_BOOST_PP_SEQ_FOR_EACH_I_M_I(r, STREAMS_BOOST_PP_TUPLE_ELEM(4, 0, x), STREAMS_BOOST_PP_TUPLE_ELEM(4, 1, x), STREAMS_BOOST_PP_TUPLE_ELEM(4, 2, x), STREAMS_BOOST_PP_TUPLE_ELEM(4, 3, x))
# endif
#
# define STREAMS_BOOST_PP_SEQ_FOR_EACH_I_M_I(r, macro, data, seq, i) macro(r, data, i, STREAMS_BOOST_PP_SEQ_HEAD(seq))
#
# /* STREAMS_BOOST_PP_SEQ_FOR_EACH_I_R */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_SEQ_FOR_EACH_I_R(r, macro, data, seq) STREAMS_BOOST_PP_FOR_ ## r((macro, data, seq (nil), 0), STREAMS_BOOST_PP_SEQ_FOR_EACH_I_P, STREAMS_BOOST_PP_SEQ_FOR_EACH_I_O, STREAMS_BOOST_PP_SEQ_FOR_EACH_I_M)
# else
#    define STREAMS_BOOST_PP_SEQ_FOR_EACH_I_R(r, macro, data, seq) STREAMS_BOOST_PP_SEQ_FOR_EACH_I_R_I(r, macro, data, seq)
#    define STREAMS_BOOST_PP_SEQ_FOR_EACH_I_R_I(r, macro, data, seq) STREAMS_BOOST_PP_FOR_ ## r((macro, data, seq (nil), 0), STREAMS_BOOST_PP_SEQ_FOR_EACH_I_P, STREAMS_BOOST_PP_SEQ_FOR_EACH_I_O, STREAMS_BOOST_PP_SEQ_FOR_EACH_I_M)
# endif
#
# endif
