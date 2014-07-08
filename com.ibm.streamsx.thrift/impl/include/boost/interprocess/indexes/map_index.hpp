//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2005-2009. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/interprocess for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef STREAMS_BOOST_INTERPROCESS_MAP_INDEX_HPP
#define STREAMS_BOOST_INTERPROCESS_MAP_INDEX_HPP

#include <streams_boost/interprocess/detail/config_begin.hpp>
#include <streams_boost/interprocess/detail/workaround.hpp>

#include <functional>
#include <utility>
#include <streams_boost/interprocess/containers/map.hpp>
#include <streams_boost/interprocess/allocators/private_adaptive_pool.hpp>

//!\file
//!Describes index adaptor of streams_boost::map container, to use it
//!as name/shared memory index

namespace streams_boost {
namespace interprocess {
namespace detail{

//!Helper class to define typedefs from IndexTraits
template <class MapConfig>
struct map_index_aux
{
   typedef typename MapConfig::key_type            key_type;
   typedef typename MapConfig::mapped_type         mapped_type;
   typedef std::less<key_type>                     key_less;
   typedef std::pair<const key_type, mapped_type>  value_type;

   typedef private_adaptive_pool
            <value_type,
               typename MapConfig::
         segment_manager_base>                     allocator_type;

   typedef streams_boost::interprocess::map
      <key_type,  mapped_type,
       key_less, allocator_type>                   index_t;
};

}  //namespace detail {

//!Index type based in streams_boost::interprocess::map. Just derives from streams_boost::interprocess::map 
//!and defines the interface needed by managed memory segments
template <class MapConfig>
class map_index
   //Derive class from map specialization
   : public detail::map_index_aux<MapConfig>::index_t
{
   /// @cond
   typedef detail::map_index_aux<MapConfig>  index_aux;
   typedef typename index_aux::index_t       base_type;
   typedef typename MapConfig::
      segment_manager_base          segment_manager_base;
   /// @endcond

   public:
   //!Constructor. Takes a pointer to the
   //!segment manager. Can throw
   map_index(segment_manager_base *segment_mngr)
      : base_type(typename index_aux::key_less(),
                  segment_mngr){}

   //!This reserves memory to optimize the insertion of n
   //!elements in the index
   void reserve(std::size_t)
      {  /*Does nothing, map has not reserve or rehash*/  }

   //!This tries to free previously allocate
   //!unused memory.
   void shrink_to_fit()
   {  base_type::get_stored_allocator().deallocate_free_blocks(); }
};

/// @cond

//!Trait class to detect if an index is a node
//!index. This allows more efficient operations
//!when deallocating named objects.
template<class MapConfig>
struct is_node_index
   <streams_boost::interprocess::map_index<MapConfig> >
{
   enum {   value = true };
};
/// @endcond

}}   //namespace streams_boost { namespace interprocess {

#include <streams_boost/interprocess/detail/config_end.hpp>

#endif   //#ifndef STREAMS_BOOST_INTERPROCESS_MAP_INDEX_HPP
