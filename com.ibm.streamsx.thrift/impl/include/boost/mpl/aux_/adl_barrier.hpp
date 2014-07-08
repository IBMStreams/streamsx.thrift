
#ifndef STREAMS_BOOST_MPL_AUX_ADL_BARRIER_HPP_INCLUDED
#define STREAMS_BOOST_MPL_AUX_ADL_BARRIER_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2002-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: adl_barrier.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/aux_/config/adl.hpp>
#include <streams_boost/mpl/aux_/config/gcc.hpp>
#include <streams_boost/mpl/aux_/config/workaround.hpp>

#if !defined(STREAMS_BOOST_MPL_CFG_NO_ADL_BARRIER_NAMESPACE)

#   define STREAMS_BOOST_MPL_AUX_ADL_BARRIER_NAMESPACE mpl_
#   define STREAMS_BOOST_MPL_AUX_ADL_BARRIER_NAMESPACE_OPEN namespace mpl_ {
#   define STREAMS_BOOST_MPL_AUX_ADL_BARRIER_NAMESPACE_CLOSE }
#   define STREAMS_BOOST_MPL_AUX_ADL_BARRIER_DECL(type) \
    namespace streams_boost { namespace mpl { \
    using ::STREAMS_BOOST_MPL_AUX_ADL_BARRIER_NAMESPACE::type; \
    } } \
/**/

#if !defined(STREAMS_BOOST_MPL_PREPROCESSING_MODE)
namespace STREAMS_BOOST_MPL_AUX_ADL_BARRIER_NAMESPACE { namespace aux {} }
namespace streams_boost { namespace mpl { using namespace STREAMS_BOOST_MPL_AUX_ADL_BARRIER_NAMESPACE; 
namespace aux { using namespace STREAMS_BOOST_MPL_AUX_ADL_BARRIER_NAMESPACE::aux; }
}}
#endif

#else // STREAMS_BOOST_MPL_CFG_NO_ADL_BARRIER_NAMESPACE

#   define STREAMS_BOOST_MPL_AUX_ADL_BARRIER_NAMESPACE streams_boost::mpl
#   define STREAMS_BOOST_MPL_AUX_ADL_BARRIER_NAMESPACE_OPEN namespace streams_boost { namespace mpl {
#   define STREAMS_BOOST_MPL_AUX_ADL_BARRIER_NAMESPACE_CLOSE }}
#   define STREAMS_BOOST_MPL_AUX_ADL_BARRIER_DECL(type) /**/

#endif

#endif // STREAMS_BOOST_MPL_AUX_ADL_BARRIER_HPP_INCLUDED
