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
# ifndef STREAMS_BOOST_PREPROCESSOR_SEQ_TO_ARRAY_HPP
# define STREAMS_BOOST_PREPROCESSOR_SEQ_TO_ARRAY_HPP
#
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/seq/enum.hpp>
# include <streams_boost/preprocessor/seq/size.hpp>
#
# /* STREAMS_BOOST_PP_SEQ_TO_ARRAY */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_SEQ_TO_ARRAY(seq) (STREAMS_BOOST_PP_SEQ_SIZE(seq), (STREAMS_BOOST_PP_SEQ_ENUM(seq)))
# else
#    define STREAMS_BOOST_PP_SEQ_TO_ARRAY(seq) STREAMS_BOOST_PP_SEQ_TO_ARRAY_I(seq)
#    define STREAMS_BOOST_PP_SEQ_TO_ARRAY_I(seq) (STREAMS_BOOST_PP_SEQ_SIZE(seq), (STREAMS_BOOST_PP_SEQ_ENUM(seq)))
# endif
#
# endif
