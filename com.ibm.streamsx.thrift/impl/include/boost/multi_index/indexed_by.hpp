/* Copyright 2003-2008 Joaquin M Lopez Munoz.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.streams_boost.org/LICENSE_1_0.txt)
 *
 * See http://www.streams_boost.org/libs/multi_index for library home page.
 */

#ifndef STREAMS_BOOST_MULTI_INDEX_INDEXED_BY_HPP
#define STREAMS_BOOST_MULTI_INDEX_INDEXED_BY_HPP

#if defined(_MSC_VER)&&(_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/config.hpp> /* keep it first to prevent nasty warns in MSVC */
#include <streams_boost/mpl/vector.hpp>
#include <streams_boost/preprocessor/cat.hpp>
#include <streams_boost/preprocessor/control/expr_if.hpp>
#include <streams_boost/preprocessor/repetition/enum.hpp>
#include <streams_boost/preprocessor/repetition/enum_params.hpp> 

/* An alias to mpl::vector used to hide MPL from the user.
 * indexed_by contains the index specifiers for instantiation
 * of a multi_index_container.
 */

/* This user_definable macro limits the number of elements of an index list;
 * useful for shortening resulting symbol names (MSVC++ 6.0, for instance,
 * has problems coping with very long symbol names.)
 */

#if !defined(STREAMS_BOOST_MULTI_INDEX_LIMIT_INDEXED_BY_SIZE)
#if defined(STREAMS_BOOST_MSVC)&&(STREAMS_BOOST_MSVC<1300)
#define STREAMS_BOOST_MULTI_INDEX_LIMIT_INDEXED_BY_SIZE 5
#else
#define STREAMS_BOOST_MULTI_INDEX_LIMIT_INDEXED_BY_SIZE STREAMS_BOOST_MPL_LIMIT_VECTOR_SIZE
#endif
#endif

#if STREAMS_BOOST_MULTI_INDEX_LIMIT_INDEXED_BY_SIZE<STREAMS_BOOST_MPL_LIMIT_VECTOR_SIZE
#define STREAMS_BOOST_MULTI_INDEX_INDEXED_BY_SIZE \
  STREAMS_BOOST_MULTI_INDEX_LIMIT_INDEXED_BY_SIZE
#else
#define STREAMS_BOOST_MULTI_INDEX_INDEXED_BY_SIZE STREAMS_BOOST_MPL_LIMIT_VECTOR_SIZE
#endif

#define STREAMS_BOOST_MULTI_INDEX_INDEXED_BY_TEMPLATE_PARM(z,n,var) \
  typename STREAMS_BOOST_PP_CAT(var,n) STREAMS_BOOST_PP_EXPR_IF(n,=mpl::na)

namespace streams_boost{

namespace multi_index{

template<
  STREAMS_BOOST_PP_ENUM(
    STREAMS_BOOST_MULTI_INDEX_INDEXED_BY_SIZE,
    STREAMS_BOOST_MULTI_INDEX_INDEXED_BY_TEMPLATE_PARM,T)
>
struct indexed_by:
  mpl::vector<STREAMS_BOOST_PP_ENUM_PARAMS(STREAMS_BOOST_MULTI_INDEX_INDEXED_BY_SIZE,T)>
{
};

} /* namespace multi_index */

} /* namespace streams_boost */

#undef STREAMS_BOOST_MULTI_INDEX_INDEXED_BY_TEMPLATE_PARM
#undef STREAMS_BOOST_MULTI_INDEX_INDEXED_BY_SIZE

#endif
