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
# ifndef STREAMS_BOOST_PREPROCESSOR_DETAIL_CHECK_HPP
# define STREAMS_BOOST_PREPROCESSOR_DETAIL_CHECK_HPP
#
# include <streams_boost/preprocessor/cat.hpp>
# include <streams_boost/preprocessor/config/config.hpp>
#
# /* STREAMS_BOOST_PP_CHECK */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_MWCC()
#    define STREAMS_BOOST_PP_CHECK(x, type) STREAMS_BOOST_PP_CHECK_D(x, type)
# else
#    define STREAMS_BOOST_PP_CHECK(x, type) STREAMS_BOOST_PP_CHECK_OO((x, type))
#    define STREAMS_BOOST_PP_CHECK_OO(par) STREAMS_BOOST_PP_CHECK_D ## par
# endif
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_MSVC() && ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_DMC()
#    define STREAMS_BOOST_PP_CHECK_D(x, type) STREAMS_BOOST_PP_CHECK_1(STREAMS_BOOST_PP_CAT(STREAMS_BOOST_PP_CHECK_RESULT_, type x))
#    define STREAMS_BOOST_PP_CHECK_1(chk) STREAMS_BOOST_PP_CHECK_2(chk)
#    define STREAMS_BOOST_PP_CHECK_2(res, _) res
# elif STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_MSVC()
#    define STREAMS_BOOST_PP_CHECK_D(x, type) STREAMS_BOOST_PP_CHECK_1(type x)
#    define STREAMS_BOOST_PP_CHECK_1(chk) STREAMS_BOOST_PP_CHECK_2(chk)
#    define STREAMS_BOOST_PP_CHECK_2(chk) STREAMS_BOOST_PP_CHECK_3((STREAMS_BOOST_PP_CHECK_RESULT_ ## chk))
#    define STREAMS_BOOST_PP_CHECK_3(im) STREAMS_BOOST_PP_CHECK_5(STREAMS_BOOST_PP_CHECK_4 im)
#    define STREAMS_BOOST_PP_CHECK_4(res, _) res
#    define STREAMS_BOOST_PP_CHECK_5(res) res
# else /* DMC */
#    define STREAMS_BOOST_PP_CHECK_D(x, type) STREAMS_BOOST_PP_CHECK_OO((type x))
#    define STREAMS_BOOST_PP_CHECK_OO(par) STREAMS_BOOST_PP_CHECK_0 ## par
#    define STREAMS_BOOST_PP_CHECK_0(chk) STREAMS_BOOST_PP_CHECK_1(STREAMS_BOOST_PP_CAT(STREAMS_BOOST_PP_CHECK_RESULT_, chk))
#    define STREAMS_BOOST_PP_CHECK_1(chk) STREAMS_BOOST_PP_CHECK_2(chk)
#    define STREAMS_BOOST_PP_CHECK_2(res, _) res
# endif
#
# define STREAMS_BOOST_PP_CHECK_RESULT_1 1, STREAMS_BOOST_PP_NIL
#
# endif
