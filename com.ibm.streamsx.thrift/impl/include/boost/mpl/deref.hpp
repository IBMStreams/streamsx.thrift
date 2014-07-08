
#ifndef STREAMS_BOOST_MPL_DEREF_HPP_INCLUDED
#define STREAMS_BOOST_MPL_DEREF_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2002-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: deref.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/aux_/msvc_type.hpp>
#include <streams_boost/mpl/aux_/na_spec.hpp>
#include <streams_boost/mpl/aux_/lambda_support.hpp>
#include <streams_boost/mpl/aux_/config/eti.hpp>

namespace streams_boost { namespace mpl {

template<
      typename STREAMS_BOOST_MPL_AUX_NA_PARAM(Iterator)
    >
struct deref
{
#if !defined(STREAMS_BOOST_MPL_CFG_MSVC_70_ETI_BUG)
    typedef typename Iterator::type type;
#else
    typedef typename aux::msvc_type<Iterator>::type type;
#endif
    STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(1,deref,(Iterator))
};

STREAMS_BOOST_MPL_AUX_NA_SPEC(1, deref)

}}

#endif // STREAMS_BOOST_MPL_DEREF_HPP_INCLUDED
