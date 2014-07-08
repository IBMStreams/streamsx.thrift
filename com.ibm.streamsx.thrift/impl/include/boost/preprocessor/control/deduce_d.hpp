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
# ifndef STREAMS_BOOST_PREPROCESSOR_CONTROL_DEDUCE_D_HPP
# define STREAMS_BOOST_PREPROCESSOR_CONTROL_DEDUCE_D_HPP
#
# include <streams_boost/preprocessor/control/while.hpp>
# include <streams_boost/preprocessor/detail/auto_rec.hpp>
#
# /* STREAMS_BOOST_PP_DEDUCE_D */
#
# define STREAMS_BOOST_PP_DEDUCE_D() STREAMS_BOOST_PP_AUTO_REC(STREAMS_BOOST_PP_WHILE_P, 256)
#
# endif
