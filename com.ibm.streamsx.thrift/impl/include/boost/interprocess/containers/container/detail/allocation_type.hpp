///////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2005-2009. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/container for documentation.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef STREAMS_BOOST_CONTAINERS_ALLOCATION_TYPE_HPP
#define STREAMS_BOOST_CONTAINERS_ALLOCATION_TYPE_HPP

#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

#include <streams_boost/interprocess/containers/container/detail/config_begin.hpp>
#include <streams_boost/interprocess/containers/container/detail/workaround.hpp>

namespace streams_boost {
namespace container {

/// @cond
enum allocation_type_v
{   
   // constants for allocation commands
   allocate_new_v   = 0x01,
   expand_fwd_v     = 0x02,
   expand_bwd_v     = 0x04,
//   expand_both    = expand_fwd | expand_bwd,
//   expand_or_new  = allocate_new | expand_both,
   shrink_in_place_v = 0x08,
   nothrow_allocation_v = 0x10,
   zero_memory_v = 0x20,
   try_shrink_in_place_v = 0x40
};

typedef int allocation_type;
/// @endcond
static const allocation_type allocate_new       = (allocation_type)allocate_new_v;
static const allocation_type expand_fwd         = (allocation_type)expand_fwd_v;
static const allocation_type expand_bwd         = (allocation_type)expand_bwd_v;
static const allocation_type shrink_in_place    = (allocation_type)shrink_in_place_v;
static const allocation_type try_shrink_in_place= (allocation_type)try_shrink_in_place_v;
static const allocation_type nothrow_allocation = (allocation_type)nothrow_allocation_v;
static const allocation_type zero_memory        = (allocation_type)zero_memory_v;

}  //namespace container {
}  //namespace streams_boost {

#include <streams_boost/interprocess/containers/container/detail/config_end.hpp>

#endif   //STREAMS_BOOST_CONTAINERS_ALLOCATION_TYPE_HPP
