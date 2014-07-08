//
// Boost.Pointer Container
//
//  Copyright Thorsten Ottosen 2008. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.streams_boost.org/libs/ptr_container/
//

#ifndef STREAMS_BOOST_PTR_CONTAINER_SERIALIZE_UNORDERED_PTR_MAP_HPP
#define STREAMS_BOOST_PTR_CONTAINER_SERIALIZE_UNORDERED_PTR_MAP_HPP

#include <streams_boost/ptr_container/detail/serialize_ptr_map_adapter.hpp>
#include <streams_boost/ptr_container/ptr_unordered_map.hpp>

namespace streams_boost 
{

namespace serialization 
{

template<class Archive, class Key, class T, class Hash, class Pred, class CloneAllocator, class Allocator>
void serialize(Archive& ar, ptr_unordered_map<Key, T, Hash, Pred, CloneAllocator, Allocator>& c, const unsigned int version)
{
   split_free(ar, c, version);
}

template<class Archive, class Key, class T, class Hash, class Pred, class CloneAllocator, class Allocator>
void serialize(Archive& ar, ptr_unordered_multimap<Key, T, Hash, Pred, CloneAllocator, Allocator>& c, const unsigned int version)
{
   split_free(ar, c, version);
}

} // namespace serialization
} // namespace streams_boost

#endif
