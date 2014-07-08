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
# ifndef STREAMS_BOOST_PREPROCESSOR_SEQ_FOR_EACH_HPP
# define STREAMS_BOOST_PREPROCESSOR_SEQ_FOR_EACH_HPP
#
# include <streams_boost/preprocessor/arithmetic/dec.hpp>
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/repetition/for.hpp>
# include <streams_boost/preprocessor/seq/seq.hpp>
# include <streams_boost/preprocessor/seq/size.hpp>
# include <streams_boost/preprocessor/tuple/elem.hpp>
# include <streams_boost/preprocessor/tuple/rem.hpp>
#
# /* STREAMS_BOOST_PP_SEQ_FOR_EACH */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_SEQ_FOR_EACH(macro, data, seq) STREAMS_BOOST_PP_FOR((macro, data, seq (nil)), STREAMS_BOOST_PP_SEQ_FOR_EACH_P, STREAMS_BOOST_PP_SEQ_FOR_EACH_O, STREAMS_BOOST_PP_SEQ_FOR_EACH_M)
# else
#    define STREAMS_BOOST_PP_SEQ_FOR_EACH(macro, data, seq) STREAMS_BOOST_PP_SEQ_FOR_EACH_D(macro, data, seq)
#    define STREAMS_BOOST_PP_SEQ_FOR_EACH_D(macro, data, seq) STREAMS_BOOST_PP_FOR((macro, data, seq (nil)), STREAMS_BOOST_PP_SEQ_FOR_EACH_P, STREAMS_BOOST_PP_SEQ_FOR_EACH_O, STREAMS_BOOST_PP_SEQ_FOR_EACH_M)
# endif
#
# define STREAMS_BOOST_PP_SEQ_FOR_EACH_P(r, x) STREAMS_BOOST_PP_DEC(STREAMS_BOOST_PP_SEQ_SIZE(STREAMS_BOOST_PP_TUPLE_ELEM(3, 2, x)))
#
# if STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_STRICT()
#    define STREAMS_BOOST_PP_SEQ_FOR_EACH_O(r, x) STREAMS_BOOST_PP_SEQ_FOR_EACH_O_I x
# else
#    define STREAMS_BOOST_PP_SEQ_FOR_EACH_O(r, x) STREAMS_BOOST_PP_SEQ_FOR_EACH_O_I(STREAMS_BOOST_PP_TUPLE_ELEM(3, 0, x), STREAMS_BOOST_PP_TUPLE_ELEM(3, 1, x), STREAMS_BOOST_PP_TUPLE_ELEM(3, 2, x))
# endif
#
# define STREAMS_BOOST_PP_SEQ_FOR_EACH_O_I(macro, data, seq) (macro, data, STREAMS_BOOST_PP_SEQ_TAIL(seq))
#
# if STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_STRICT()
#    define STREAMS_BOOST_PP_SEQ_FOR_EACH_M(r, x) STREAMS_BOOST_PP_SEQ_FOR_EACH_M_IM(r, STREAMS_BOOST_PP_TUPLE_REM_3 x)
#    define STREAMS_BOOST_PP_SEQ_FOR_EACH_M_IM(r, im) STREAMS_BOOST_PP_SEQ_FOR_EACH_M_I(r, im)
# else
#    define STREAMS_BOOST_PP_SEQ_FOR_EACH_M(r, x) STREAMS_BOOST_PP_SEQ_FOR_EACH_M_I(r, STREAMS_BOOST_PP_TUPLE_ELEM(3, 0, x), STREAMS_BOOST_PP_TUPLE_ELEM(3, 1, x), STREAMS_BOOST_PP_TUPLE_ELEM(3, 2, x))
# endif
#
# define STREAMS_BOOST_PP_SEQ_FOR_EACH_M_I(r, macro, data, seq) macro(r, data, STREAMS_BOOST_PP_SEQ_HEAD(seq))
#
# /* STREAMS_BOOST_PP_SEQ_FOR_EACH_R */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_SEQ_FOR_EACH_R(r, macro, data, seq) STREAMS_BOOST_PP_FOR_ ## r((macro, data, seq (nil)), STREAMS_BOOST_PP_SEQ_FOR_EACH_P, STREAMS_BOOST_PP_SEQ_FOR_EACH_O, STREAMS_BOOST_PP_SEQ_FOR_EACH_M)
# else
#    define STREAMS_BOOST_PP_SEQ_FOR_EACH_R(r, macro, data, seq) STREAMS_BOOST_PP_SEQ_FOR_EACH_R_I(r, macro, data, seq)
#    define STREAMS_BOOST_PP_SEQ_FOR_EACH_R_I(r, macro, data, seq) STREAMS_BOOST_PP_FOR_ ## r((macro, data, seq (nil)), STREAMS_BOOST_PP_SEQ_FOR_EACH_P, STREAMS_BOOST_PP_SEQ_FOR_EACH_O, STREAMS_BOOST_PP_SEQ_FOR_EACH_M)
# endif
#
# endif
