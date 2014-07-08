# /* Copyright (C) 2001
#  * Housemarque Oy
#  * http://www.housemarque.com
#  *
#  * Distributed under the Boost Software License, Version 1.0. (See
#  * accompanying file LICENSE_1_0.txt or copy at
#  * http://www.streams_boost.org/LICENSE_1_0.txt)
#  *
#  * See http://www.streams_boost.org for most recent version.
#  */
#
# /* Revised by Paul Mensonides (2002) */
#
# ifndef STREAMS_BOOST_PREPROCESSOR_LIST_ADT_HPP
# define STREAMS_BOOST_PREPROCESSOR_LIST_ADT_HPP
#
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/detail/is_binary.hpp>
# include <streams_boost/preprocessor/logical/compl.hpp>
# include <streams_boost/preprocessor/tuple/eat.hpp>
#
# /* STREAMS_BOOST_PP_LIST_CONS */
#
# define STREAMS_BOOST_PP_LIST_CONS(head, tail) (head, tail)
#
# /* STREAMS_BOOST_PP_LIST_NIL */
#
# define STREAMS_BOOST_PP_LIST_NIL STREAMS_BOOST_PP_NIL
#
# /* STREAMS_BOOST_PP_LIST_FIRST */
#
# define STREAMS_BOOST_PP_LIST_FIRST(list) STREAMS_BOOST_PP_LIST_FIRST_D(list)
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_MWCC()
#    define STREAMS_BOOST_PP_LIST_FIRST_D(list) STREAMS_BOOST_PP_LIST_FIRST_I list
# else
#    define STREAMS_BOOST_PP_LIST_FIRST_D(list) STREAMS_BOOST_PP_LIST_FIRST_I ## list
# endif
#
# define STREAMS_BOOST_PP_LIST_FIRST_I(head, tail) head
#
# /* STREAMS_BOOST_PP_LIST_REST */
#
# define STREAMS_BOOST_PP_LIST_REST(list) STREAMS_BOOST_PP_LIST_REST_D(list)
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_MWCC()
#    define STREAMS_BOOST_PP_LIST_REST_D(list) STREAMS_BOOST_PP_LIST_REST_I list
# else
#    define STREAMS_BOOST_PP_LIST_REST_D(list) STREAMS_BOOST_PP_LIST_REST_I ## list
# endif
#
# define STREAMS_BOOST_PP_LIST_REST_I(head, tail) tail
#
# /* STREAMS_BOOST_PP_LIST_IS_CONS */
#
# if STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_BCC()
#    define STREAMS_BOOST_PP_LIST_IS_CONS(list) STREAMS_BOOST_PP_LIST_IS_CONS_D(list)
#    define STREAMS_BOOST_PP_LIST_IS_CONS_D(list) STREAMS_BOOST_PP_LIST_IS_CONS_ ## list
#    define STREAMS_BOOST_PP_LIST_IS_CONS_(head, tail) 1
#    define STREAMS_BOOST_PP_LIST_IS_CONS_STREAMS_BOOST_PP_NIL 0
# else
#    define STREAMS_BOOST_PP_LIST_IS_CONS(list) STREAMS_BOOST_PP_IS_BINARY(list)
# endif
#
# /* STREAMS_BOOST_PP_LIST_IS_NIL */
#
# if ~STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_BCC()
#    define STREAMS_BOOST_PP_LIST_IS_NIL(list) STREAMS_BOOST_PP_COMPL(STREAMS_BOOST_PP_IS_BINARY(list))
# else
#    define STREAMS_BOOST_PP_LIST_IS_NIL(list) STREAMS_BOOST_PP_COMPL(STREAMS_BOOST_PP_LIST_IS_CONS(list))
# endif
#
# endif
