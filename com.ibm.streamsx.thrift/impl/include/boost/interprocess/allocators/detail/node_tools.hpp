//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2007-2009. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/interprocess for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef STREAMS_BOOST_INTERPROCESS_DETAIL_NODE_TOOLS_HPP
#define STREAMS_BOOST_INTERPROCESS_DETAIL_NODE_TOOLS_HPP

#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

#include <streams_boost/interprocess/detail/config_begin.hpp>
#include <streams_boost/interprocess/detail/workaround.hpp>

#include <streams_boost/intrusive/slist.hpp>

namespace streams_boost {
namespace interprocess {
namespace detail {


template<class VoidPointer>
struct node_slist
{
   //This hook will be used to chain the individual nodes
    typedef typename bi::make_slist_base_hook
      <bi::void_pointer<VoidPointer>, bi::link_mode<bi::normal_link> >::type slist_hook_t;

   //A node object will hold node_t when it's not allocated
   struct node_t
      :  public slist_hook_t
   {};

   typedef typename bi::make_slist
      <node_t, bi::linear<true>, bi::base_hook<slist_hook_t> >::type node_slist_t;
};

}  //namespace detail {
}  //namespace interprocess {
}  //namespace streams_boost {

#include <streams_boost/interprocess/detail/config_end.hpp>

#endif   //#ifndef STREAMS_BOOST_INTERPROCESS_DETAIL_NODE_TOOLS_HPP
