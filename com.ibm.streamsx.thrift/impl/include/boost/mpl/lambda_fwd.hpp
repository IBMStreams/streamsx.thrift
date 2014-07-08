
#ifndef STREAMS_BOOST_MPL_LAMBDA_FWD_HPP_INCLUDED
#define STREAMS_BOOST_MPL_LAMBDA_FWD_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2001-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: lambda_fwd.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/void_fwd.hpp>
#include <streams_boost/mpl/aux_/na.hpp>
#include <streams_boost/mpl/aux_/config/lambda.hpp>

#if !defined(STREAMS_BOOST_MPL_CFG_NO_FULL_LAMBDA_SUPPORT)

#   include <streams_boost/mpl/int.hpp>
#   include <streams_boost/mpl/aux_/lambda_arity_param.hpp>
#   include <streams_boost/mpl/aux_/template_arity_fwd.hpp>

namespace streams_boost { namespace mpl {

template< 
      typename T = na
    , typename Tag = void_
    STREAMS_BOOST_MPL_AUX_LAMBDA_ARITY_PARAM(
          typename Arity = int_< aux::template_arity<T>::value >
        )
    >
struct lambda;

}}

#else // STREAMS_BOOST_MPL_CFG_NO_FULL_LAMBDA_SUPPORT

#   include <streams_boost/mpl/bool.hpp>

namespace streams_boost { namespace mpl {

template< 
      typename T = na
    , typename Tag = void_
    , typename Protect = true_
    > 
struct lambda;

}}

#endif

#endif // STREAMS_BOOST_MPL_LAMBDA_FWD_HPP_INCLUDED
