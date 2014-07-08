//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2008-2009. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/container for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef STREAMS_BOOST_CONTAINERS_DETAIL_PREPROCESSOR_HPP
#define STREAMS_BOOST_CONTAINERS_DETAIL_PREPROCESSOR_HPP

#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

#include <streams_boost/interprocess/containers/container/detail/config_begin.hpp>
#include <streams_boost/interprocess/containers/container/detail/workaround.hpp>

#ifdef STREAMS_BOOST_CONTAINERS_PERFECT_FORWARDING
#error "This file is not needed when perfect forwarding is available"
#endif

#include <streams_boost/preprocessor/iteration/local.hpp> 
#include <streams_boost/preprocessor/repetition/enum_params.hpp>
#include <streams_boost/preprocessor/cat.hpp>
#include <streams_boost/preprocessor/repetition/enum.hpp>
#include <streams_boost/preprocessor/repetition/repeat.hpp>

#define STREAMS_BOOST_CONTAINERS_MAX_CONSTRUCTOR_PARAMETERS 10

//Note:
//We define template parameters as const references to
//be able to bind temporaries. After that we will un-const them.
//This cast is ugly but it is necessary until "perfect forwarding"
//is achieved in C++0x. Meanwhile, if we want to be able to
//bind rvalues with non-const references, we have to be ugly
#ifdef STREAMS_BOOST_HAS_RVALUE_REFS
   #define STREAMS_BOOST_CONTAINERS_PP_PARAM_LIST(z, n, data) \
   STREAMS_BOOST_PP_CAT(P, n) && STREAMS_BOOST_PP_CAT(p, n) \
   //!
#else
   #define STREAMS_BOOST_CONTAINERS_PP_PARAM_LIST(z, n, data) \
   const STREAMS_BOOST_PP_CAT(P, n) & STREAMS_BOOST_PP_CAT(p, n) \
   //!
#endif

#ifdef STREAMS_BOOST_HAS_RVALUE_REFS
   #define STREAMS_BOOST_CONTAINERS_PARAM(U, u) \
   U && u \
   //!
#else
   #define STREAMS_BOOST_CONTAINERS_PARAM(U, u) \
   const U & u \
   //!
#endif

#ifdef STREAMS_BOOST_HAS_RVALUE_REFS
#define STREAMS_BOOST_CONTAINERS_AUX_PARAM_INIT(z, n, data) \
  STREAMS_BOOST_PP_CAT(m_p, n) (STREAMS_BOOST_PP_CAT(p, n))           \
//!
#else
#define STREAMS_BOOST_CONTAINERS_AUX_PARAM_INIT(z, n, data) \
  STREAMS_BOOST_PP_CAT(m_p, n) (const_cast<STREAMS_BOOST_PP_CAT(P, n) &>(STREAMS_BOOST_PP_CAT(p, n))) \
//!
#endif

#define STREAMS_BOOST_CONTAINERS_AUX_PARAM_INC(z, n, data)   \
  STREAMS_BOOST_PP_CAT(++m_p, n)                        \
//!

#ifdef STREAMS_BOOST_HAS_RVALUE_REFS
#define STREAMS_BOOST_CONTAINERS_AUX_PARAM_DEFINE(z, n, data)  \
  STREAMS_BOOST_PP_CAT(P, n) && STREAMS_BOOST_PP_CAT(m_p, n);            \
//!
#else
#define STREAMS_BOOST_CONTAINERS_AUX_PARAM_DEFINE(z, n, data)  \
  STREAMS_BOOST_PP_CAT(P, n) & STREAMS_BOOST_PP_CAT(m_p, n);             \
//!
#endif

#define STREAMS_BOOST_CONTAINERS_PP_PARAM_FORWARD(z, n, data) \
streams_boost::interprocess::forward< STREAMS_BOOST_PP_CAT(P, n) >( STREAMS_BOOST_PP_CAT(p, n) ) \
//!

#define STREAMS_BOOST_CONTAINERS_PP_MEMBER_FORWARD(z, n, data) \
streams_boost::interprocess::forward< STREAMS_BOOST_PP_CAT(P, n) >( STREAMS_BOOST_PP_CAT(m_p, n) ) \
//!

#define STREAMS_BOOST_CONTAINERS_PP_MEMBER_IT_FORWARD(z, n, data) \
STREAMS_BOOST_PP_CAT(*m_p, n) \
//!

#include <streams_boost/interprocess/containers/container/detail/config_end.hpp>

#else
#ifdef STREAMS_BOOST_CONTAINERS_PERFECT_FORWARDING
#error "This file is not needed when perfect forwarding is available"
#endif
#endif //#ifndef STREAMS_BOOST_CONTAINERS_DETAIL_PREPROCESSOR_HPP
