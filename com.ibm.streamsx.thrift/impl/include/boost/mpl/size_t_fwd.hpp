
#ifndef STREAMS_BOOST_MPL_SIZE_T_FWD_HPP_INCLUDED
#define STREAMS_BOOST_MPL_SIZE_T_FWD_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: size_t_fwd.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/aux_/adl_barrier.hpp>
#include <streams_boost/config.hpp> // make sure 'size_t' is placed into 'std'
#include <cstddef>

STREAMS_BOOST_MPL_AUX_ADL_BARRIER_NAMESPACE_OPEN

template< std::size_t N > struct size_t;

STREAMS_BOOST_MPL_AUX_ADL_BARRIER_NAMESPACE_CLOSE
STREAMS_BOOST_MPL_AUX_ADL_BARRIER_DECL(size_t)

#endif // STREAMS_BOOST_MPL_SIZE_T_FWD_HPP_INCLUDED