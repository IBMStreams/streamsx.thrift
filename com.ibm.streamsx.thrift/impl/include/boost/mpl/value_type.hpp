
#ifndef STREAMS_BOOST_MPL_VALUE_TYPE_HPP_INCLUDED
#define STREAMS_BOOST_MPL_VALUE_TYPE_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2003-2004
// Copyright David Abrahams 2003-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: value_type.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/value_type_fwd.hpp>
#include <streams_boost/mpl/sequence_tag.hpp>
#include <streams_boost/mpl/apply_wrap.hpp>
#include <streams_boost/mpl/aux_/na_spec.hpp>
#include <streams_boost/mpl/aux_/lambda_support.hpp>

namespace streams_boost { namespace mpl {

template<
      typename STREAMS_BOOST_MPL_AUX_NA_PARAM(AssociativeSequence)
    , typename STREAMS_BOOST_MPL_AUX_NA_PARAM(T)
    >
struct value_type
    : apply_wrap2<
          value_type_impl< typename sequence_tag<AssociativeSequence>::type >
        , AssociativeSequence, T >
{
    STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(2,value_type,(AssociativeSequence,T))
};

STREAMS_BOOST_MPL_AUX_NA_SPEC(2, value_type)
    
}}

#endif // STREAMS_BOOST_MPL_VALUE_TYPE_HPP_INCLUDED
