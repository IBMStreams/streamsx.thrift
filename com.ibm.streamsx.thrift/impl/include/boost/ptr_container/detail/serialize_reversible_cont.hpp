// Copyright Sebastian Ramacher, 2007.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_PTR_CONTAINER_DETAIL_SERIALIZE_REVERSIBLE_PTR_CONTAINER_HPP
#define STREAMS_BOOST_PTR_CONTAINER_DETAIL_SERIALIZE_REVERSIBLE_PTR_CONTAINER_HPP

#include <streams_boost/ptr_container/detail/reversible_ptr_container.hpp>
#include <streams_boost/ptr_container/detail/serialize_xml_names.hpp>
#include <streams_boost/serialization/split_free.hpp>

namespace streams_boost 
{

namespace ptr_container_detail
{

template<class Archive, class Config, class CloneAllocator>
void save_helper(Archive& ar, const ptr_container_detail::reversible_ptr_container<Config, CloneAllocator>& c)
{
    typedef ptr_container_detail::reversible_ptr_container<Config, CloneAllocator> container_type;
    typedef STREAMS_BOOST_DEDUCED_TYPENAME container_type::const_iterator const_iterator;
    typedef STREAMS_BOOST_DEDUCED_TYPENAME container_type::value_type value_type;

    const_iterator i = c.begin(), e = c.end();
    for(; i != e; ++i)
        ar << streams_boost::serialization::make_nvp( ptr_container_detail::item(), 
                ptr_container_detail::serialize_as_const(static_cast<value_type>(*i.base()))); 
    }

template<class Archive, class Config, class CloneAllocator>
void load_helper(Archive& ar, ptr_container_detail::reversible_ptr_container<Config, CloneAllocator>& c,
                 STREAMS_BOOST_DEDUCED_TYPENAME ptr_container_detail::reversible_ptr_container<Config, CloneAllocator>::size_type n)
{
    typedef ptr_container_detail::reversible_ptr_container<Config, CloneAllocator> container_type;
    typedef STREAMS_BOOST_DEDUCED_TYPENAME container_type::size_type size_type;
    typedef STREAMS_BOOST_DEDUCED_TYPENAME container_type::value_type value_type;

    //
    // Called after an appropriate reserve on c.
    //

    c.clear();            
    for(size_type i = 0u; i != n; ++i)
    {
        //
        // Remark: pointers are not tracked,
        // so we need not call ar.reset_object_address(v, u)
        //
        value_type ptr;
        ar >> streams_boost::serialization::make_nvp( ptr_container_detail::item(), ptr ); 
        c.insert(c.end(), ptr);
    }
}

} // namespace ptr_container_detail

namespace serialization 
{

template<class Archive, class Config, class CloneAllocator>
void save(Archive& ar, const ptr_container_detail::reversible_ptr_container<Config, CloneAllocator>& c, unsigned int /*version*/)
{   
    ar << streams_boost::serialization::make_nvp( ptr_container_detail::count(), 
                                          ptr_container_detail::serialize_as_const(c.size()) );
    ptr_container_detail::save_helper(ar, c);
}

template<class Archive, class Config, class CloneAllocator>
void load(Archive& ar, ptr_container_detail::reversible_ptr_container<Config, CloneAllocator>& c, unsigned int /*version*/)
{
    typedef ptr_container_detail::reversible_ptr_container<Config, CloneAllocator> container_type;
    typedef STREAMS_BOOST_DEDUCED_TYPENAME container_type::size_type size_type;
    
    size_type n;
    ar >> streams_boost::serialization::make_nvp( ptr_container_detail::count(), n );
    ptr_container_detail::load_helper(ar, c, n);
    
}

} // namespace serialization
} // namespace streams_boost

#endif
