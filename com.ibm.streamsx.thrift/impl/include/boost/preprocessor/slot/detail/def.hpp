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
# ifndef STREAMS_BOOST_PREPROCESSOR_SLOT_DETAIL_DEF_HPP
# define STREAMS_BOOST_PREPROCESSOR_SLOT_DETAIL_DEF_HPP
#
# /* STREAMS_BOOST_PP_SLOT_OFFSET_x */
#
# define STREAMS_BOOST_PP_SLOT_OFFSET_10(x) (x) % 1000000000UL
# define STREAMS_BOOST_PP_SLOT_OFFSET_9(x) STREAMS_BOOST_PP_SLOT_OFFSET_10(x) % 100000000UL
# define STREAMS_BOOST_PP_SLOT_OFFSET_8(x) STREAMS_BOOST_PP_SLOT_OFFSET_9(x) % 10000000UL
# define STREAMS_BOOST_PP_SLOT_OFFSET_7(x) STREAMS_BOOST_PP_SLOT_OFFSET_8(x) % 1000000UL
# define STREAMS_BOOST_PP_SLOT_OFFSET_6(x) STREAMS_BOOST_PP_SLOT_OFFSET_7(x) % 100000UL
# define STREAMS_BOOST_PP_SLOT_OFFSET_5(x) STREAMS_BOOST_PP_SLOT_OFFSET_6(x) % 10000UL
# define STREAMS_BOOST_PP_SLOT_OFFSET_4(x) STREAMS_BOOST_PP_SLOT_OFFSET_5(x) % 1000UL
# define STREAMS_BOOST_PP_SLOT_OFFSET_3(x) STREAMS_BOOST_PP_SLOT_OFFSET_4(x) % 100UL
# define STREAMS_BOOST_PP_SLOT_OFFSET_2(x) STREAMS_BOOST_PP_SLOT_OFFSET_3(x) % 10UL
#
# /* STREAMS_BOOST_PP_SLOT_CC_x */
#
# define STREAMS_BOOST_PP_SLOT_CC_2(a, b) STREAMS_BOOST_PP_SLOT_CC_2_D(a, b)
# define STREAMS_BOOST_PP_SLOT_CC_3(a, b, c) STREAMS_BOOST_PP_SLOT_CC_3_D(a, b, c)
# define STREAMS_BOOST_PP_SLOT_CC_4(a, b, c, d) STREAMS_BOOST_PP_SLOT_CC_4_D(a, b, c, d)
# define STREAMS_BOOST_PP_SLOT_CC_5(a, b, c, d, e) STREAMS_BOOST_PP_SLOT_CC_5_D(a, b, c, d, e)
# define STREAMS_BOOST_PP_SLOT_CC_6(a, b, c, d, e, f) STREAMS_BOOST_PP_SLOT_CC_6_D(a, b, c, d, e, f)
# define STREAMS_BOOST_PP_SLOT_CC_7(a, b, c, d, e, f, g) STREAMS_BOOST_PP_SLOT_CC_7_D(a, b, c, d, e, f, g)
# define STREAMS_BOOST_PP_SLOT_CC_8(a, b, c, d, e, f, g, h) STREAMS_BOOST_PP_SLOT_CC_8_D(a, b, c, d, e, f, g, h)
# define STREAMS_BOOST_PP_SLOT_CC_9(a, b, c, d, e, f, g, h, i) STREAMS_BOOST_PP_SLOT_CC_9_D(a, b, c, d, e, f, g, h, i)
# define STREAMS_BOOST_PP_SLOT_CC_10(a, b, c, d, e, f, g, h, i, j) STREAMS_BOOST_PP_SLOT_CC_10_D(a, b, c, d, e, f, g, h, i, j)
#
# define STREAMS_BOOST_PP_SLOT_CC_2_D(a, b) a ## b
# define STREAMS_BOOST_PP_SLOT_CC_3_D(a, b, c) a ## b ## c
# define STREAMS_BOOST_PP_SLOT_CC_4_D(a, b, c, d) a ## b ## c ## d
# define STREAMS_BOOST_PP_SLOT_CC_5_D(a, b, c, d, e) a ## b ## c ## d ## e
# define STREAMS_BOOST_PP_SLOT_CC_6_D(a, b, c, d, e, f) a ## b ## c ## d ## e ## f
# define STREAMS_BOOST_PP_SLOT_CC_7_D(a, b, c, d, e, f, g) a ## b ## c ## d ## e ## f ## g
# define STREAMS_BOOST_PP_SLOT_CC_8_D(a, b, c, d, e, f, g, h) a ## b ## c ## d ## e ## f ## g ## h
# define STREAMS_BOOST_PP_SLOT_CC_9_D(a, b, c, d, e, f, g, h, i) a ## b ## c ## d ## e ## f ## g ## h ## i
# define STREAMS_BOOST_PP_SLOT_CC_10_D(a, b, c, d, e, f, g, h, i, j) a ## b ## c ## d ## e ## f ## g ## h ## i ## j
#
# endif
