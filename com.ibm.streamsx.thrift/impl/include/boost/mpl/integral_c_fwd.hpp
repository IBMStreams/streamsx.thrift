
#ifndef STREAMS_BOOST_MPL_INTEGRAL_C_FWD_HPP_INCLUDED
#define STREAMS_BOOST_MPL_INTEGRAL_C_FWD_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2006
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: integral_c_fwd.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/aux_/config/workaround.hpp>
#include <streams_boost/mpl/aux_/adl_barrier.hpp>

STREAMS_BOOST_MPL_AUX_ADL_BARRIER_NAMESPACE_OPEN

#if STREAMS_BOOST_WORKAROUND(__HP_aCC, <= 53800)
// the type of non-type template arguments may not depend on template arguments
template< typename T, long N > struct integral_c;
#else
template< typename T, T N > struct integral_c;
#endif

STREAMS_BOOST_MPL_AUX_ADL_BARRIER_NAMESPACE_CLOSE
STREAMS_BOOST_MPL_AUX_ADL_BARRIER_DECL(integral_c)

#endif // STREAMS_BOOST_MPL_INTEGRAL_C_FWD_HPP_INCLUDED
