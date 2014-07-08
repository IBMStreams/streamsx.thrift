
#ifndef STREAMS_BOOST_MPL_AUX_RANGE_C_O1_SIZE_HPP_INCLUDED
#define STREAMS_BOOST_MPL_AUX_RANGE_C_O1_SIZE_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: O1_size.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/O1_size_fwd.hpp>
#include <streams_boost/mpl/aux_/range_c/size.hpp>
#include <streams_boost/mpl/aux_/range_c/tag.hpp>

namespace streams_boost { namespace mpl {

template<>
struct O1_size_impl< aux::half_open_range_tag >
    : size_impl< aux::half_open_range_tag >
{
};

}}

#endif // STREAMS_BOOST_MPL_AUX_RANGE_C_O1_SIZE_HPP_INCLUDED