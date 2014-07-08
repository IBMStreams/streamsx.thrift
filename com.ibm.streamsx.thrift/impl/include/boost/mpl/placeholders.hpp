
#if !defined(STREAMS_BOOST_PP_IS_ITERATING)

///// header body

#ifndef STREAMS_BOOST_MPL_PLACEHOLDERS_HPP_INCLUDED
#define STREAMS_BOOST_MPL_PLACEHOLDERS_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2001-2004
// Copyright Peter Dimov 2001-2003
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: placeholders.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $


#if !defined(STREAMS_BOOST_MPL_PREPROCESSING_MODE)
#   include <streams_boost/mpl/arg.hpp>
#   include <streams_boost/mpl/aux_/adl_barrier.hpp>

#   if !defined(STREAMS_BOOST_MPL_CFG_NO_ADL_BARRIER_NAMESPACE)
#       define STREAMS_BOOST_MPL_AUX_ARG_ADL_BARRIER_DECL(type) \
        using ::STREAMS_BOOST_MPL_AUX_ADL_BARRIER_NAMESPACE::type; \
        /**/
#   else
#       define STREAMS_BOOST_MPL_AUX_ARG_ADL_BARRIER_DECL(type) /**/
#   endif

#endif

#include <streams_boost/mpl/aux_/config/use_preprocessed.hpp>

#if !defined(STREAMS_BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS) \
 && !defined(STREAMS_BOOST_MPL_PREPROCESSING_MODE)

#   define STREAMS_BOOST_MPL_PREPROCESSED_HEADER placeholders.hpp
#   include <streams_boost/mpl/aux_/include_preprocessed.hpp>

#else

#   include <streams_boost/mpl/aux_/nttp_decl.hpp>
#   include <streams_boost/mpl/limits/arity.hpp>
#   include <streams_boost/preprocessor/iterate.hpp>
#   include <streams_boost/preprocessor/cat.hpp>

// watch out for GNU gettext users, who #define _(x)
#if !defined(_) || defined(STREAMS_BOOST_MPL_CFG_NO_UNNAMED_PLACEHOLDER_SUPPORT)
STREAMS_BOOST_MPL_AUX_ADL_BARRIER_NAMESPACE_OPEN
typedef arg<-1> _;
STREAMS_BOOST_MPL_AUX_ADL_BARRIER_NAMESPACE_CLOSE

namespace streams_boost { namespace mpl { 

STREAMS_BOOST_MPL_AUX_ARG_ADL_BARRIER_DECL(_)

namespace placeholders {
using STREAMS_BOOST_MPL_AUX_ADL_BARRIER_NAMESPACE::_;
}

}}
#endif

/// agurt, 17/mar/02: one more placeholder for the last 'apply#' 
/// specialization
#define STREAMS_BOOST_PP_ITERATION_PARAMS_1 \
    (3,(1, STREAMS_BOOST_MPL_LIMIT_METAFUNCTION_ARITY + 1, <streams_boost/mpl/placeholders.hpp>))
#include STREAMS_BOOST_PP_ITERATE()

#endif // STREAMS_BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#endif // STREAMS_BOOST_MPL_PLACEHOLDERS_HPP_INCLUDED

///// iteration

#else
#define i_ STREAMS_BOOST_PP_FRAME_ITERATION(1)

STREAMS_BOOST_MPL_AUX_ADL_BARRIER_NAMESPACE_OPEN

typedef arg<i_> STREAMS_BOOST_PP_CAT(_,i_);

STREAMS_BOOST_MPL_AUX_ADL_BARRIER_NAMESPACE_CLOSE

namespace streams_boost { namespace mpl { 

STREAMS_BOOST_MPL_AUX_ARG_ADL_BARRIER_DECL(STREAMS_BOOST_PP_CAT(_,i_))

namespace placeholders {
using STREAMS_BOOST_MPL_AUX_ADL_BARRIER_NAMESPACE::STREAMS_BOOST_PP_CAT(_,i_);
}

}}

#undef i_
#endif // STREAMS_BOOST_PP_IS_ITERATING
