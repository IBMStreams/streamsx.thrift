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
# ifndef STREAMS_BOOST_PREPROCESSOR_REPETITION_DEDUCE_R_HPP
# define STREAMS_BOOST_PREPROCESSOR_REPETITION_DEDUCE_R_HPP
#
# include <streams_boost/preprocessor/detail/auto_rec.hpp>
# include <streams_boost/preprocessor/repetition/for.hpp>
#
# /* STREAMS_BOOST_PP_DEDUCE_R */
#
# define STREAMS_BOOST_PP_DEDUCE_R() STREAMS_BOOST_PP_AUTO_REC(STREAMS_BOOST_PP_FOR_P, 256)
#
# endif
