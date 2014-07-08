
#ifndef STREAMS_BOOST_MPL_AUX_NUMERIC_CAST_HPP_INCLUDED
#define STREAMS_BOOST_MPL_AUX_NUMERIC_CAST_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2003-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: numeric_cast_utils.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/numeric_cast.hpp>
#include <streams_boost/mpl/apply_wrap.hpp>
#include <streams_boost/mpl/aux_/config/forwarding.hpp>

namespace streams_boost { namespace mpl { namespace aux {

template<
      typename F
    , typename Tag1
    , typename Tag2
    >
struct cast1st_impl
{
    template< typename N1, typename N2 > struct apply
#if !defined(STREAMS_BOOST_MPL_CFG_NO_NESTED_FORWARDING)
        : apply_wrap2< 
              F
            , typename apply_wrap1< STREAMS_BOOST_MPL_AUX_NUMERIC_CAST<Tag1,Tag2>,N1 >::type
            , N2
            >
    {
#else
    {
    typedef typename apply_wrap2< 
              F
            , typename apply_wrap1< STREAMS_BOOST_MPL_AUX_NUMERIC_CAST<Tag1,Tag2>,N1 >::type
            , N2
            >::type type;
#endif
    };
};

template<
      typename F
    , typename Tag1
    , typename Tag2
    >
struct cast2nd_impl
{
    template< typename N1, typename N2 > struct apply
#if !defined(STREAMS_BOOST_MPL_CFG_NO_NESTED_FORWARDING)
        : apply_wrap2< 
              F
            , N1
            , typename apply_wrap1< STREAMS_BOOST_MPL_AUX_NUMERIC_CAST<Tag2,Tag1>,N2 >::type
            >
    {
#else
    {
        typedef typename apply_wrap2< 
              F
            , N1
            , typename apply_wrap1< STREAMS_BOOST_MPL_AUX_NUMERIC_CAST<Tag2,Tag1>,N2 >::type
            >::type type;
#endif
    };
};

}}}

#endif // STREAMS_BOOST_MPL_AUX_NUMERIC_CAST_HPP_INCLUDED
