
#ifndef STREAMS_BOOST_MPL_LAMBDA_HPP_INCLUDED
#define STREAMS_BOOST_MPL_LAMBDA_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2001-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: lambda.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/lambda_fwd.hpp>
#include <streams_boost/mpl/bind.hpp>
#include <streams_boost/mpl/aux_/config/lambda.hpp>

#if !defined(STREAMS_BOOST_MPL_CFG_NO_FULL_LAMBDA_SUPPORT)
#   include <streams_boost/mpl/aux_/full_lambda.hpp>
#else
#   include <streams_boost/mpl/aux_/lambda_no_ctps.hpp>
#   include <streams_boost/mpl/aux_/lambda_support.hpp>
#   define STREAMS_BOOST_MPL_CFG_NO_IMPLICIT_METAFUNCTIONS
#endif

#endif // STREAMS_BOOST_MPL_LAMBDA_HPP_INCLUDED
