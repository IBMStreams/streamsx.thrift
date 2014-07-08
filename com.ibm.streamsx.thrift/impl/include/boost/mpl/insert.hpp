
#ifndef STREAMS_BOOST_MPL_INSERT_HPP_INCLUDED
#define STREAMS_BOOST_MPL_INSERT_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: insert.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/insert_fwd.hpp>
#include <streams_boost/mpl/sequence_tag.hpp>
#include <streams_boost/mpl/aux_/insert_impl.hpp>
#include <streams_boost/mpl/aux_/na_spec.hpp>
#include <streams_boost/mpl/aux_/lambda_support.hpp>

namespace streams_boost { namespace mpl {

template<
      typename STREAMS_BOOST_MPL_AUX_NA_PARAM(Sequence)
    , typename STREAMS_BOOST_MPL_AUX_NA_PARAM(Pos_or_T)
    , typename STREAMS_BOOST_MPL_AUX_NA_PARAM(T)
    >
struct insert
    : insert_impl< typename sequence_tag<Sequence>::type >
        ::template apply< Sequence,Pos_or_T,T >
{
    STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(3,insert,(Sequence,Pos_or_T,T))
};

STREAMS_BOOST_MPL_AUX_NA_SPEC(3, insert)

}}

#endif // STREAMS_BOOST_MPL_INSERT_HPP_INCLUDED
