
#ifndef STREAMS_BOOST_MPL_VECTOR_AUX_BACK_HPP_INCLUDED
#define STREAMS_BOOST_MPL_VECTOR_AUX_BACK_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: back.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/back_fwd.hpp>
#include <streams_boost/mpl/next_prior.hpp>
#include <streams_boost/mpl/vector/aux_/at.hpp>
#include <streams_boost/mpl/vector/aux_/tag.hpp>
#include <streams_boost/mpl/aux_/config/typeof.hpp>
#include <streams_boost/mpl/aux_/config/ctps.hpp>

namespace streams_boost { namespace mpl {

#if defined(STREAMS_BOOST_MPL_CFG_TYPEOF_BASED_SEQUENCES)

template<>
struct back_impl< aux::vector_tag >
{
    template< typename Vector > struct apply
        : v_at<
              Vector
            , prior<typename Vector::size>::type::value
            >
    {
    };
};

#else

#if !defined(STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)

template< long n_ >
struct back_impl< aux::vector_tag<n_> >
{
    template< typename Vector > struct apply
    {
        typedef typename Vector::back type;
    };
};

#endif // STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

#endif // STREAMS_BOOST_MPL_CFG_TYPEOF_BASED_SEQUENCES

}}

#endif // STREAMS_BOOST_MPL_VECTOR_AUX_BACK_HPP_INCLUDED
