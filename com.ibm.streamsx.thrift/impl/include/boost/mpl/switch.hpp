
#ifndef STREAMS_BOOST_MPL_SWITCH_HPP_INCLUDED
#define STREAMS_BOOST_MPL_SWITCH_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2003-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: switch.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/find_if.hpp>
#include <streams_boost/mpl/deref.hpp>
#include <streams_boost/mpl/lambda.hpp>
#include <streams_boost/mpl/apply.hpp>
#include <streams_boost/mpl/pair.hpp>
#include <streams_boost/mpl/aux_/na_spec.hpp>
#include <streams_boost/mpl/aux_/lambda_support.hpp>

namespace streams_boost { namespace mpl {

template< 
      typename STREAMS_BOOST_MPL_AUX_NA_PARAM(Body)
    , typename STREAMS_BOOST_MPL_AUX_NA_PARAM(T)
    >
struct switch_
{
    typedef typename find_if<
          Body
        , apply1< lambda< first<_1> >, T >
        >::type iter_;
        
    typedef typename deref<iter_>::type pair_;
    typedef typename lambda< typename second<pair_>::type >::type f_;
    typedef typename apply1<f_,T>::type type;

    STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(2,switch_,(Body,T))
};

STREAMS_BOOST_MPL_AUX_NA_SPEC(2, switch_)

}}

#endif // STREAMS_BOOST_MPL_SWITCH_HPP_INCLUDED
