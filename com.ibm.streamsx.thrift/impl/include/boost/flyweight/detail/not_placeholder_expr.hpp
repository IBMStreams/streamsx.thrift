/* Copyright 2006-2008 Joaquin M Lopez Munoz.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.streams_boost.org/LICENSE_1_0.txt)
 *
 * See http://www.streams_boost.org/libs/flyweight for library home page.
 */

#ifndef STREAMS_BOOST_FLYWEIGHT_DETAIL_NOT_PLACEHOLDER_EXPR_HPP
#define STREAMS_BOOST_FLYWEIGHT_DETAIL_NOT_PLACEHOLDER_EXPR_HPP

#if defined(_MSC_VER)&&(_MSC_VER>=1200)
#pragma once
#endif

/* STREAMS_BOOST_FLYWEIGHT_NOT_A_PLACEHOLDER_EXPRESSION can be inserted at the end
 * of a class template parameter declaration:
 *   template<
 *     typename X0,...,typename Xn
 *     STREAMS_BOOST_FLYWEIGHT_NOT_A_PLACEHOLDER_EXPRESSION  
 *   >
 *   struct foo...
 * to prevent instantiations from being treated as MPL placeholder
 * expressions in the presence of placeholder arguments; this is useful
 * to avoid masking of a metafunction class nested ::apply during
 * MPL invocation.
 */

#include <streams_boost/config.hpp> /* keep it first to prevent nasty warns in MSVC */
#include <streams_boost/detail/workaround.hpp>

#if STREAMS_BOOST_WORKAROUND(__GNUC__, <4)||\
    STREAMS_BOOST_WORKAROUND(__GNUC__,==4)&&(__GNUC_MINOR__<2)
/* The default trick on which the macro is based, namely adding a int=0
 * defaulted template parameter, does not work in GCC prior to 4.2 due to
 * an unfortunate compiler non-standard extension, as explained in
 *   http://lists.streams_boost.org/streams_boost-users/2007/07/29866.php
 * We resort to an uglier technique, adding defaulted template parameters
 * so as to exceed STREAMS_BOOST_MPL_LIMIT_METAFUNCTION_ARITY.
 */

#include <streams_boost/mpl/limits/arity.hpp>
#include <streams_boost/preprocessor/facilities/intercept.hpp>
#include <streams_boost/preprocessor/repetition/enum_trailing_params.hpp>

#define STREAMS_BOOST_FLYWEIGHT_NOT_A_PLACEHOLDER_EXPRESSION                  \
STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(                                        \
  STREAMS_BOOST_MPL_LIMIT_METAFUNCTION_ARITY,typename=int STREAMS_BOOST_PP_INTERCEPT)
#define STREAMS_BOOST_FLYWEIGHT_NOT_A_PLACEHOLDER_EXPRESSION_DEF              \
STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(                                        \
  STREAMS_BOOST_MPL_LIMIT_METAFUNCTION_ARITY,typename STREAMS_BOOST_PP_INTERCEPT)

#else
#define STREAMS_BOOST_FLYWEIGHT_NOT_A_PLACEHOLDER_EXPRESSION  ,int=0
#define STREAMS_BOOST_FLYWEIGHT_NOT_A_PLACEHOLDER_EXPRESSION_DEF  ,int
#endif

#endif
