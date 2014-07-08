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
# if !defined(STREAMS_BOOST_PP_INDIRECT_SELF)
#    error STREAMS_BOOST_PP_ERROR:  no indirect file to include
# endif
#
# define STREAMS_BOOST_PP_IS_SELFISH 1
#
# include STREAMS_BOOST_PP_INDIRECT_SELF
#
# undef STREAMS_BOOST_PP_IS_SELFISH
# undef STREAMS_BOOST_PP_INDIRECT_SELF
