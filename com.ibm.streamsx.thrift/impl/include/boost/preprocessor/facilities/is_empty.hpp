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
# ifndef STREAMS_BOOST_PREPROCESSOR_FACILITIES_IS_EMPTY_HPP
# define STREAMS_BOOST_PREPROCESSOR_FACILITIES_IS_EMPTY_HPP
#
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/cat.hpp>
# include <streams_boost/preprocessor/tuple/elem.hpp>
# include <streams_boost/preprocessor/facilities/empty.hpp>
# include <streams_boost/preprocessor/detail/split.hpp>
#
# /* STREAMS_BOOST_PP_IS_EMPTY */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_MSVC() && ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_MWCC()
#    define STREAMS_BOOST_PP_IS_EMPTY(x) STREAMS_BOOST_PP_IS_EMPTY_I(x STREAMS_BOOST_PP_IS_EMPTY_HELPER)
#    define STREAMS_BOOST_PP_IS_EMPTY_I(contents) STREAMS_BOOST_PP_TUPLE_ELEM(2, 1, (STREAMS_BOOST_PP_IS_EMPTY_DEF_ ## contents()))
#    define STREAMS_BOOST_PP_IS_EMPTY_DEF_STREAMS_BOOST_PP_IS_EMPTY_HELPER 1, 1 STREAMS_BOOST_PP_EMPTY
#    define STREAMS_BOOST_PP_IS_EMPTY_HELPER() , 0
# else
#    if STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_MSVC()
#        define STREAMS_BOOST_PP_IS_EMPTY(x) STREAMS_BOOST_PP_IS_EMPTY_I(STREAMS_BOOST_PP_IS_EMPTY_HELPER x ())
#        define STREAMS_BOOST_PP_IS_EMPTY_I(test) STREAMS_BOOST_PP_IS_EMPTY_II(STREAMS_BOOST_PP_SPLIT(0, STREAMS_BOOST_PP_CAT(STREAMS_BOOST_PP_IS_EMPTY_DEF_, test)))
#        define STREAMS_BOOST_PP_IS_EMPTY_II(id) id
#    else
#        define STREAMS_BOOST_PP_IS_EMPTY(x) STREAMS_BOOST_PP_IS_EMPTY_I((STREAMS_BOOST_PP_IS_EMPTY_HELPER x ()))
#        define STREAMS_BOOST_PP_IS_EMPTY_I(par) STREAMS_BOOST_PP_IS_EMPTY_II ## par
#        define STREAMS_BOOST_PP_IS_EMPTY_II(test) STREAMS_BOOST_PP_SPLIT(0, STREAMS_BOOST_PP_CAT(STREAMS_BOOST_PP_IS_EMPTY_DEF_, test))
#    endif
#    define STREAMS_BOOST_PP_IS_EMPTY_HELPER() 1
#    define STREAMS_BOOST_PP_IS_EMPTY_DEF_1 1, STREAMS_BOOST_PP_NIL
#    define STREAMS_BOOST_PP_IS_EMPTY_DEF_STREAMS_BOOST_PP_IS_EMPTY_HELPER 0, STREAMS_BOOST_PP_NIL
# endif
#
# endif
