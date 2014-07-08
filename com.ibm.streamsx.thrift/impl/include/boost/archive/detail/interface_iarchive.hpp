#ifndef STREAMS_BOOST_ARCHIVE_DETAIL_INTERFACE_IARCHIVE_HPP
#define STREAMS_BOOST_ARCHIVE_DETAIL_INTERFACE_IARCHIVE_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// interface_iarchive.hpp

// (C) Copyright 2002 Robert Ramey - http://www.rrsd.com . 
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org for updates, documentation, and revision history.
#include <string>
#include <cstddef> // NULL
#include <streams_boost/cstdint.hpp>
#include <streams_boost/mpl/bool.hpp>
#include <streams_boost/archive/detail/auto_link_archive.hpp>
#include <streams_boost/archive/detail/iserializer.hpp>
#include <streams_boost/serialization/singleton.hpp>
#include <streams_boost/archive/detail/abi_prefix.hpp> // must be the last header

namespace streams_boost {
namespace archive {
namespace detail {

class STREAMS_BOOST_ARCHIVE_OR_WARCHIVE_DECL(STREAMS_BOOST_PP_EMPTY()) basic_pointer_iserializer;

template<class Archive>
class interface_iarchive 
{
protected:
    interface_iarchive(){};
public:
    /////////////////////////////////////////////////////////
    // archive public interface
    typedef mpl::bool_<true> is_loading;
    typedef mpl::bool_<false> is_saving;

    // return a pointer to the most derived class
    Archive * This(){
        return static_cast<Archive *>(this);
    }

    template<class T>
    const basic_pointer_iserializer * 
    register_type(T * = NULL){
        const basic_pointer_iserializer & bpis =
            streams_boost::serialization::singleton<
                pointer_iserializer<Archive, T> 
            >::get_const_instance();
        this->This()->register_basic_serializer(bpis.get_basic_serializer());
        return & bpis;
    }
    template<class T>
    Archive & operator>>(T & t){
        this->This()->load_override(t, 0);
        return * this->This();
    }

    // the & operator 
    template<class T>
    Archive & operator&(T & t){
        return *(this->This()) >> t;
    }
};

} // namespace detail
} // namespace archive
} // namespace streams_boost

#include <streams_boost/archive/detail/abi_suffix.hpp> // pops abi_suffix.hpp pragmas

#endif // STREAMS_BOOST_ARCHIVE_DETAIL_INTERFACE_IARCHIVE_HPP
