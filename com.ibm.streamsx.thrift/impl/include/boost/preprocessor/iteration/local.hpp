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
# ifndef STREAMS_BOOST_PREPROCESSOR_ITERATION_LOCAL_HPP
# define STREAMS_BOOST_PREPROCESSOR_ITERATION_LOCAL_HPP
#
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/slot/slot.hpp>
# include <streams_boost/preprocessor/tuple/elem.hpp>
#
# /* STREAMS_BOOST_PP_LOCAL_ITERATE */
#
# define STREAMS_BOOST_PP_LOCAL_ITERATE() <streams_boost/preprocessor/iteration/detail/local.hpp>
#
# define STREAMS_BOOST_PP_LOCAL_C(n) (STREAMS_BOOST_PP_LOCAL_S) <= n && (STREAMS_BOOST_PP_LOCAL_F) >= n
# define STREAMS_BOOST_PP_LOCAL_R(n) (STREAMS_BOOST_PP_LOCAL_F) <= n && (STREAMS_BOOST_PP_LOCAL_S) >= n
#
# endif
