
#ifndef STREAMS_BOOST_MPL_RANGE_C_HPP_INCLUDED
#define STREAMS_BOOST_MPL_RANGE_C_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: range_c.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/integral_c.hpp>
#include <streams_boost/mpl/aux_/range_c/front.hpp>
#include <streams_boost/mpl/aux_/range_c/back.hpp>
#include <streams_boost/mpl/aux_/range_c/size.hpp>
#include <streams_boost/mpl/aux_/range_c/O1_size.hpp>
#include <streams_boost/mpl/aux_/range_c/empty.hpp>
#include <streams_boost/mpl/aux_/range_c/iterator.hpp>
#include <streams_boost/mpl/aux_/range_c/tag.hpp>

namespace streams_boost { namespace mpl {

template<
      typename T
    , T Start
    , T Finish
    >
struct range_c
{
    typedef aux::half_open_range_tag tag;
    typedef T value_type;
    typedef range_c type;

    typedef integral_c<T,Start> start;
    typedef integral_c<T,Finish> finish;

    typedef r_iter<start> begin;
    typedef r_iter<finish> end;
};

}}

#endif // STREAMS_BOOST_MPL_RANGE_C_HPP_INCLUDED
