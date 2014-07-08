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
# ifndef STREAMS_BOOST_PREPROCESSOR_SLOT_SLOT_HPP
# define STREAMS_BOOST_PREPROCESSOR_SLOT_SLOT_HPP
#
# include <streams_boost/preprocessor/cat.hpp>
# include <streams_boost/preprocessor/slot/detail/def.hpp>
#
# /* STREAMS_BOOST_PP_ASSIGN_SLOT */
#
# define STREAMS_BOOST_PP_ASSIGN_SLOT(i) STREAMS_BOOST_PP_CAT(STREAMS_BOOST_PP_ASSIGN_SLOT_, i)
#
# define STREAMS_BOOST_PP_ASSIGN_SLOT_1 <streams_boost/preprocessor/slot/detail/slot1.hpp>
# define STREAMS_BOOST_PP_ASSIGN_SLOT_2 <streams_boost/preprocessor/slot/detail/slot2.hpp>
# define STREAMS_BOOST_PP_ASSIGN_SLOT_3 <streams_boost/preprocessor/slot/detail/slot3.hpp>
# define STREAMS_BOOST_PP_ASSIGN_SLOT_4 <streams_boost/preprocessor/slot/detail/slot4.hpp>
# define STREAMS_BOOST_PP_ASSIGN_SLOT_5 <streams_boost/preprocessor/slot/detail/slot5.hpp>
#
# /* STREAMS_BOOST_PP_SLOT */
#
# define STREAMS_BOOST_PP_SLOT(i) STREAMS_BOOST_PP_CAT(STREAMS_BOOST_PP_SLOT_, i)()
#
# endif
