// Copyright Sebastian Ramacher, 2007.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_PTR_CONTAINER_DETAIL_SERIALIZE_PTR_MAP_ADAPTER_HPP
#define STREAMS_BOOST_PTR_CONTAINER_DETAIL_SERIALIZE_PTR_MAP_ADAPTER_HPP

#include <streams_boost/ptr_container/ptr_map_adapter.hpp>
#include <streams_boost/ptr_container/detail/serialize_xml_names.hpp>
#include <streams_boost/serialization/split_free.hpp>

namespace streams_boost 
{

namespace serialization 
{

template<class Archive, class T, class VoidPtrMap, class CloneAllocator, bool Ordered>
void save(Archive& ar, const ptr_container_detail::ptr_map_adapter_base<T, VoidPtrMap, CloneAllocator,Ordered>& c, unsigned int /*version*/)
{
    typedef ptr_container_detail::ptr_map_adapter_base<T, VoidPtrMap, CloneAllocator,Ordered> container;
    typedef STREAMS_BOOST_DEDUCED_TYPENAME container::const_iterator const_iterator;

    ar << streams_boost::serialization::make_nvp( ptr_container_detail::count(), 
                                          ptr_container_detail::serialize_as_const(c.size()) );

    const_iterator i = c.begin(), e = c.end();
    for(; i != e; ++i)
    {
        ar << streams_boost::serialization::make_nvp( ptr_container_detail::first(), i->first );
        ar << streams_boost::serialization::make_nvp( ptr_container_detail::second(),
                                              ptr_container_detail::serialize_as_const(i->second) );
    }
}

template<class Archive, class T, class VoidPtrMap, class CloneAllocator, bool Ordered>
void load(Archive& ar, ptr_map_adapter<T, VoidPtrMap, CloneAllocator,Ordered>& c, unsigned int /*version*/)
{
    typedef ptr_map_adapter<T, VoidPtrMap, CloneAllocator,Ordered> container;
    typedef STREAMS_BOOST_DEDUCED_TYPENAME container::key_type key_type;
    typedef STREAMS_BOOST_DEDUCED_TYPENAME container::size_type size_type;
    typedef STREAMS_BOOST_DEDUCED_TYPENAME container::iterator iterator;

    c.clear();
    size_type n;
    ar >> streams_boost::serialization::make_nvp( ptr_container_detail::count(), n );

    for(size_type i = 0u; i != n; ++i)
    {
        key_type key;
        T* value;
        ar >> streams_boost::serialization::make_nvp( ptr_container_detail::first(), key );
        ar >> streams_boost::serialization::make_nvp( ptr_container_detail::second(), value );
        std::pair<iterator, bool> p = c.insert(key, value);
        ar.reset_object_address(&p.first->first, &key); 
    }
}

template<class Archive, class T, class VoidPtrMap, class CloneAllocator, bool Ordered>
void load(Archive& ar, ptr_multimap_adapter<T, VoidPtrMap, CloneAllocator,Ordered>& c, unsigned int /*version*/)
{
    typedef ptr_multimap_adapter<T, VoidPtrMap, CloneAllocator,Ordered> container;
    typedef STREAMS_BOOST_DEDUCED_TYPENAME container::key_type key_type;
    typedef STREAMS_BOOST_DEDUCED_TYPENAME container::size_type size_type;
    typedef STREAMS_BOOST_DEDUCED_TYPENAME container::iterator iterator;

    c.clear();
    size_type n;
    ar >> streams_boost::serialization::make_nvp( ptr_container_detail::count(), n );

    for(size_type i = 0u; i != n; ++i)
    {
        key_type key;
        T* value;
        ar >> streams_boost::serialization::make_nvp( ptr_container_detail::first(), key );
        ar >> streams_boost::serialization::make_nvp( ptr_container_detail::second(), value );
        iterator p = c.insert(key, value);
        ar.reset_object_address(&p->first, &key);
    }
}

} // namespace serialization
} // namespace streams_boost

#endif