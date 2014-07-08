
#ifndef STREAMS_BOOST_MPL_BEGIN_END_HPP_INCLUDED
#define STREAMS_BOOST_MPL_BEGIN_END_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: begin_end.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/begin_end_fwd.hpp>
#include <streams_boost/mpl/aux_/begin_end_impl.hpp>
#include <streams_boost/mpl/sequence_tag.hpp>
#include <streams_boost/mpl/aux_/na_spec.hpp>
#include <streams_boost/mpl/aux_/lambda_support.hpp>

namespace streams_boost { namespace mpl {

// agurt, 13/sep/02: switched from inheritance to typedef; MSVC is more
// happy this way (less ETI-related errors), and it doesn't affect 
// anything else
template<
      typename STREAMS_BOOST_MPL_AUX_NA_PARAM(Sequence)
    >
struct begin
{
    typedef typename sequence_tag<Sequence>::type tag_;
    typedef typename begin_impl< tag_ >
        ::template apply< Sequence >::type type;

    STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(1,begin,(Sequence))
};

template<
      typename STREAMS_BOOST_MPL_AUX_NA_PARAM(Sequence)
    >
struct end
{
    typedef typename sequence_tag<Sequence>::type tag_;
    typedef typename end_impl< tag_ >
        ::template apply< Sequence >::type type;

    STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(1,end,(Sequence))
};

STREAMS_BOOST_MPL_AUX_NA_SPEC(1, begin)
STREAMS_BOOST_MPL_AUX_NA_SPEC(1, end)

}}

#endif // STREAMS_BOOST_MPL_BEGIN_END_HPP_INCLUDED
