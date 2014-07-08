
#ifndef STREAMS_BOOST_MPL_LIST_LIST0_HPP_INCLUDED
#define STREAMS_BOOST_MPL_LIST_LIST0_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: list0.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/long.hpp>
#include <streams_boost/mpl/aux_/na.hpp>
#include <streams_boost/mpl/list/aux_/push_front.hpp>
#include <streams_boost/mpl/list/aux_/pop_front.hpp>
#include <streams_boost/mpl/list/aux_/push_back.hpp>
#include <streams_boost/mpl/list/aux_/front.hpp>
#include <streams_boost/mpl/list/aux_/clear.hpp>
#include <streams_boost/mpl/list/aux_/O1_size.hpp>
#include <streams_boost/mpl/list/aux_/size.hpp>
#include <streams_boost/mpl/list/aux_/empty.hpp>
#include <streams_boost/mpl/list/aux_/begin_end.hpp>
#include <streams_boost/mpl/list/aux_/item.hpp>

namespace streams_boost { namespace mpl {

template< typename Dummy = na > struct list0;

template<> struct list0<na>
    : l_end
{
    typedef l_end type;
};

}}

#endif // STREAMS_BOOST_MPL_LIST_LIST0_HPP_INCLUDED
