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

#ifndef STREAMS_BOOST_PTR_CONTAINER_SERIALIZE_PTR_CIRCULAR_BUFFER_HPP
#define STREAMS_BOOST_PTR_CONTAINER_SERIALIZE_PTR_CIRCULAR_BUFFER_HPP

#include <streams_boost/ptr_container/detail/serialize_reversible_cont.hpp>
#include <streams_boost/ptr_container/ptr_circular_buffer.hpp>

namespace streams_boost 
{

namespace serialization 
{

template<class Archive, class T, class CloneAllocator, class Allocator>
void load(Archive& ar, ptr_circular_buffer<T, CloneAllocator, Allocator>& c, unsigned int version)
{
    typedef ptr_circular_buffer<T, CloneAllocator, Allocator> container_type;
    typedef STREAMS_BOOST_DEDUCED_TYPENAME container_type::size_type size_type;
    
    size_type n;
    ar >> streams_boost::serialization::make_nvp( ptr_container_detail::count(), n );
    c.reserve(n);
    
    ptr_container_detail::load_helper(ar, c, n);
}

template<class Archive, class T, class CloneAllocator, class Allocator>
void serialize(Archive& ar, ptr_circular_buffer<T, CloneAllocator, Allocator>& c, const unsigned int version)
{
   split_free(ar, c, version);
}

} // namespace serialization
} // namespace streams_boost

#endif
