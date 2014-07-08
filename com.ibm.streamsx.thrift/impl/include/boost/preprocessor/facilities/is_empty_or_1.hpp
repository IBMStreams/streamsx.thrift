# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Paul Mensonides 2003.
#  *     Distributed under the Boost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.streams_boost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.streams_boost.org for most recent version. */
#
# ifndef STREAMS_BOOST_PREPROCESSOR_FACILITIES_IS_EMPTY_OR_1_HPP
# define STREAMS_BOOST_PREPROCESSOR_FACILITIES_IS_EMPTY_OR_1_HPP
#
# include <streams_boost/preprocessor/control/iif.hpp>
# include <streams_boost/preprocessor/facilities/empty.hpp>
# include <streams_boost/preprocessor/facilities/is_1.hpp>
# include <streams_boost/preprocessor/facilities/is_empty.hpp>
#
# /* STREAMS_BOOST_PP_IS_EMPTY_OR_1 */
#
# define STREAMS_BOOST_PP_IS_EMPTY_OR_1(x) \
    STREAMS_BOOST_PP_IIF( \
        STREAMS_BOOST_PP_IS_EMPTY(x STREAMS_BOOST_PP_EMPTY()), \
        1 STREAMS_BOOST_PP_EMPTY, \
        STREAMS_BOOST_PP_IS_1 \
    )(x) \
    /**/
#
# endif
