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
# ifndef STREAMS_BOOST_PREPROCESSOR_DEBUG_LINE_HPP
# define STREAMS_BOOST_PREPROCESSOR_DEBUG_LINE_HPP
#
# include <streams_boost/preprocessor/cat.hpp>
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/iteration/iterate.hpp>
# include <streams_boost/preprocessor/stringize.hpp>
#
# /* STREAMS_BOOST_PP_LINE */
#
# if STREAMS_BOOST_PP_CONFIG_EXTENDED_LINE_INFO
#    define STREAMS_BOOST_PP_LINE(line, file) line STREAMS_BOOST_PP_CAT(STREAMS_BOOST_PP_LINE_, STREAMS_BOOST_PP_IS_ITERATING)(file)
#    define STREAMS_BOOST_PP_LINE_STREAMS_BOOST_PP_IS_ITERATING(file) #file
#    define STREAMS_BOOST_PP_LINE_1(file) STREAMS_BOOST_PP_STRINGIZE(file STREAMS_BOOST_PP_CAT(STREAMS_BOOST_PP_LINE_I_, STREAMS_BOOST_PP_ITERATION_DEPTH())())
#    define STREAMS_BOOST_PP_LINE_I_1() [STREAMS_BOOST_PP_FRAME_ITERATION(1)]
#    define STREAMS_BOOST_PP_LINE_I_2() STREAMS_BOOST_PP_LINE_I_1()[STREAMS_BOOST_PP_FRAME_ITERATION(2)]
#    define STREAMS_BOOST_PP_LINE_I_3() STREAMS_BOOST_PP_LINE_I_2()[STREAMS_BOOST_PP_FRAME_ITERATION(3)]
#    define STREAMS_BOOST_PP_LINE_I_4() STREAMS_BOOST_PP_LINE_I_3()[STREAMS_BOOST_PP_FRAME_ITERATION(4)]
#    define STREAMS_BOOST_PP_LINE_I_5() STREAMS_BOOST_PP_LINE_I_4()[STREAMS_BOOST_PP_FRAME_ITERATION(5)]
# else
#    define STREAMS_BOOST_PP_LINE(line, file) line __FILE__
# endif
#
# endif
