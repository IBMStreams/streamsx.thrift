// Copyright Sebastian Ramacher, 2007.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_PTR_CONTAINER_SERIALIZE_PTR_LIST_HPP
#define STREAMS_BOOST_PTR_CONTAINER_SERIALIZE_PTR_LIST_HPP

#include <streams_boost/ptr_container/detail/serialize_reversible_cont.hpp>
#include <streams_boost/ptr_container/ptr_list.hpp>

namespace streams_boost 
{

namespace serialization 
{

template<class Archive, class T, class CloneAllocator, class Allocator>
void serialize(Archive& ar, ptr_list<T, CloneAllocator, Allocator>& c, const unsigned int version)
{
   split_free(ar, c, version);
}

} // namespace serialization
} // namespace streams_boost

#endif
