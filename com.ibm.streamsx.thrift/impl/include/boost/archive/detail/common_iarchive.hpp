#ifndef STREAMS_BOOST_ARCHIVE_DETAIL_COMMON_IARCHIVE_HPP
#define STREAMS_BOOST_ARCHIVE_DETAIL_COMMON_IARCHIVE_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// common_iarchive.hpp

// (C) Copyright 2002 Robert Ramey - http://www.rrsd.com . 
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org for updates, documentation, and revision history.

#include <streams_boost/config.hpp>

#include <streams_boost/archive/detail/basic_iarchive.hpp>
#include <streams_boost/archive/detail/basic_pointer_iserializer.hpp>
#include <streams_boost/archive/detail/interface_iarchive.hpp>
#include <streams_boost/archive/detail/archive_serializer_map.hpp>
#include <streams_boost/serialization/singleton.hpp>

#ifdef STREAMS_BOOST_MSVC
#  pragma warning(push)
#  pragma warning(disable : 4511 4512)
#endif

namespace streams_boost {
namespace archive {
namespace detail {

class extended_type_info;

// note: referred to as Curiously Recurring Template Patter (CRTP)
template<class Archive>
class common_iarchive : 
    public basic_iarchive,
    public interface_iarchive<Archive>
{
    friend class interface_iarchive<Archive>;
private:
    virtual void vload(version_type & t){
        * this->This() >> t; 
    }
    virtual void vload(object_id_type & t){
        * this->This() >> t;
    }
    virtual void vload(class_id_type & t){
        * this->This() >> t;
    }
    virtual void vload(class_id_optional_type & t){
        * this->This() >> t;
    }
    virtual void vload(tracking_type & t){
        * this->This() >> t;
    }
    virtual void vload(class_name_type &s){
        * this->This() >> s;
    }
protected:
    // default processing - invoke serialization library
    template<class T>
    void load_override(T & t, STREAMS_BOOST_PFTO int){
        archive::load(* this->This(), t);
    }
    // default implementations of functions which emit start/end tags for
    // archive types that require them.
    void load_start(const char * /*name*/){}
    void load_end(const char * /*name*/){}
    // default archive initialization
    common_iarchive(unsigned int flags = 0) : 
        basic_iarchive(flags),
        interface_iarchive<Archive>()
    {}
};

} // namespace detail
} // namespace archive
} // namespace streams_boost

#ifdef STREAMS_BOOST_MSVC
#pragma warning(pop)
#endif

#endif // STREAMS_BOOST_ARCHIVE_DETAIL_COMMON_IARCHIVE_HPP

