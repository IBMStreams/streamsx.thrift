//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2005-2009. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/interprocess for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef STREAMS_BOOST_INTERPROCESS_DETAIL_NODE_POOL_HPP
#define STREAMS_BOOST_INTERPROCESS_DETAIL_NODE_POOL_HPP

#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

#include <streams_boost/interprocess/detail/config_begin.hpp>
#include <streams_boost/interprocess/detail/workaround.hpp>

#include <streams_boost/intrusive/slist.hpp>
#include <streams_boost/math/common_factor_ct.hpp>
#include <streams_boost/pointer_to_other.hpp>

#include <streams_boost/interprocess/detail/utilities.hpp>
#include <streams_boost/interprocess/allocators/detail/allocator_common.hpp>
#include <streams_boost/interprocess/containers/container/detail/node_pool_impl.hpp>
#include <cstddef>


//!\file
//!Describes the real adaptive pool shared by many Interprocess adaptive pool allocators

namespace streams_boost {
namespace interprocess {
namespace detail {



//!Pooled shared memory allocator using single segregated storage. Includes
//!a reference count but the class does not delete itself, this is  
//!responsibility of user classes. Node size (NodeSize) and the number of
//!nodes allocated per block (NodesPerBlock) are known at compile time
template< class SegmentManager, std::size_t NodeSize, std::size_t NodesPerBlock >
class private_node_pool
   //Inherit from the implementation to avoid template bloat
   :  public streams_boost::container::containers_detail::
         private_node_pool_impl<typename SegmentManager::segment_manager_base_type>
{
   typedef streams_boost::container::containers_detail::private_node_pool_impl
      <typename SegmentManager::segment_manager_base_type> base_t;
   //Non-copyable
   private_node_pool();
   private_node_pool(const private_node_pool &);
   private_node_pool &operator=(const private_node_pool &);

   public:
   typedef SegmentManager segment_manager;

   static const std::size_t nodes_per_block = NodesPerBlock;
   //Deprecated, use nodes_per_block
   static const std::size_t nodes_per_chunk = NodesPerBlock;

   //!Constructor from a segment manager. Never throws
   private_node_pool(segment_manager *segment_mngr)
      :  base_t(segment_mngr, NodeSize, NodesPerBlock)
   {}

   //!Returns the segment manager. Never throws
   segment_manager* get_segment_manager() const
   {  return static_cast<segment_manager*>(base_t::get_segment_manager_base()); }
};


//!Pooled shared memory allocator using single segregated storage. Includes
//!a reference count but the class does not delete itself, this is  
//!responsibility of user classes. Node size (NodeSize) and the number of
//!nodes allocated per block (NodesPerBlock) are known at compile time
//!Pooled shared memory allocator using adaptive pool. Includes
//!a reference count but the class does not delete itself, this is  
//!responsibility of user classes. Node size (NodeSize) and the number of
//!nodes allocated per block (NodesPerBlock) are known at compile time
template< class SegmentManager
        , std::size_t NodeSize
        , std::size_t NodesPerBlock
        >
class shared_node_pool 
   :  public detail::shared_pool_impl
      < private_node_pool
         <SegmentManager, NodeSize, NodesPerBlock>
      >
{
   typedef detail::shared_pool_impl
      < private_node_pool
         <SegmentManager, NodeSize, NodesPerBlock>
      > base_t;
   public:
   shared_node_pool(SegmentManager *segment_mgnr)
      : base_t(segment_mgnr)
   {}
};

}  //namespace detail {
}  //namespace interprocess {
}  //namespace streams_boost {

#include <streams_boost/interprocess/detail/config_end.hpp>

#endif   //#ifndef STREAMS_BOOST_INTERPROCESS_DETAIL_NODE_POOL_HPP