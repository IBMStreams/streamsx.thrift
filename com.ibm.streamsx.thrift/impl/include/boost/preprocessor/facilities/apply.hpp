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
# ifndef STREAMS_BOOST_PREPROCESSOR_FACILITIES_APPLY_HPP
# define STREAMS_BOOST_PREPROCESSOR_FACILITIES_APPLY_HPP
#
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/control/expr_iif.hpp>
# include <streams_boost/preprocessor/detail/is_unary.hpp>
# include <streams_boost/preprocessor/tuple/rem.hpp>
#
# /* STREAMS_BOOST_PP_APPLY */
#
# if STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_APPLY(x) STREAMS_BOOST_PP_APPLY_I(x)
#    define STREAMS_BOOST_PP_APPLY_I(x) STREAMS_BOOST_PP_EXPR_IIF(STREAMS_BOOST_PP_IS_UNARY(x), STREAMS_BOOST_PP_TUPLE_REM_1 x)
# elif STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_BCC()
#    define STREAMS_BOOST_PP_APPLY(x) STREAMS_BOOST_PP_APPLY_I(x)
#    define STREAMS_BOOST_PP_APPLY_I(x) STREAMS_BOOST_PP_APPLY_ ## x
#    define STREAMS_BOOST_PP_APPLY_(x) x
#    define STREAMS_BOOST_PP_APPLY_STREAMS_BOOST_PP_NIL
# else
#    define STREAMS_BOOST_PP_APPLY(x) STREAMS_BOOST_PP_EXPR_IIF(STREAMS_BOOST_PP_IS_UNARY(x), STREAMS_BOOST_PP_TUPLE_REM_1 x)
# endif
#
# endif
