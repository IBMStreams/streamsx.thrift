
#ifndef STREAMS_BOOST_MPL_INHERIT_FRONT_TO_BACK_HPP_INCLUDED
#define STREAMS_BOOST_MPL_INHERIT_FRONT_TO_BACK_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2001-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: inherit_linearly.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/fold.hpp>
#include <streams_boost/mpl/empty_base.hpp>
#include <streams_boost/mpl/aux_/na_spec.hpp>
#include <streams_boost/mpl/aux_/lambda_support.hpp>

namespace streams_boost { namespace mpl {

template<
      typename STREAMS_BOOST_MPL_AUX_NA_PARAM(Types_)
    , typename STREAMS_BOOST_MPL_AUX_NA_PARAM(Node_)
    , typename Root_ = empty_base
    >
struct inherit_linearly
    : fold<Types_,Root_,Node_>
{
    STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(3,inherit_linearly,(Types_,Node_,Root_))
};

STREAMS_BOOST_MPL_AUX_NA_SPEC(2, inherit_linearly)

}}

#endif // STREAMS_BOOST_MPL_INHERIT_FRONT_TO_BACK_HPP_INCLUDED
