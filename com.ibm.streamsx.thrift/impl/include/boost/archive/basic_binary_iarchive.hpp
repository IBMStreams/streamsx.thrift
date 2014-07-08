#ifndef STREAMS_BOOST_ARCHIVE_BASIC_BINARY_IARCHIVE_HPP
#define STREAMS_BOOST_ARCHIVE_BASIC_BINARY_IARCHIVE_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// basic_binary_iarchive.hpp
//
// archives stored as native binary - this should be the fastest way
// to archive the state of a group of obects.  It makes no attempt to
// convert to any canonical form.

// IN GENERAL, ARCHIVES CREATED WITH THIS CLASS WILL NOT BE READABLE
// ON PLATFORM APART FROM THE ONE THEY ARE CREATED ON

// (C) Copyright 2002 Robert Ramey - http://www.rrsd.com . 
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org for updates, documentation, and revision history.

#include <streams_boost/config.hpp>
#include <streams_boost/detail/workaround.hpp>
#include <streams_boost/serialization/pfto.hpp>

#include <streams_boost/archive/detail/common_iarchive.hpp>
#include <streams_boost/serialization/collection_size_type.hpp>
#include <streams_boost/serialization/string.hpp>

#ifdef STREAMS_BOOST_MSVC
#  pragma warning(push)
#  pragma warning(disable : 4511 4512)
#endif

#include <streams_boost/archive/detail/abi_prefix.hpp> // must be the last header

namespace streams_boost { 
namespace archive {

/////////////////////////////////////////////////////////////////////////
// class basic_binary_iarchive - read serialized objects from a input binary stream
template<class Archive>
class basic_binary_iarchive : 
    public detail::common_iarchive<Archive>
{
protected:
#if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, <= 1300)
public:
#elif defined(STREAMS_BOOST_MSVC)
    // for some inexplicable reason insertion of "class" generates compile erro
    // on msvc 7.1
    friend detail::interface_iarchive<Archive>;
#else
    friend class detail::interface_iarchive<Archive>;
#endif
    // intermediate level to support override of operators
    // fot templates in the absence of partial function 
    // template ordering. If we get here pass to base class
    // note extra nonsense to sneak it pass the borland compiers
    typedef detail::common_iarchive<Archive> detail_common_iarchive;
    template<class T>
    void load_override(T & t, STREAMS_BOOST_PFTO int version){
      this->detail_common_iarchive::load_override(t, static_cast<int>(version));
    }
    // binary files don't include the optional information 
    void load_override(class_id_optional_type & /* t */, int){}

    // the following have been overridden to provide specific sizes
    // for these pseudo prmitive types.
    void load_override(version_type & t, int){ 
        // upto 255 versions
        unsigned char x=0;
        * this->This() >> x;
        t = version_type(x);
    }
    void load_override(class_id_type & t, int){
        // upto 32K classes
        int_least16_t x=0;
        * this->This() >> x;
        t = class_id_type(x);
    }
    void load_override(class_id_reference_type & t, int){
        // upto 32K classes
        int_least16_t x=0;
        * this->This() >> x;
        t = class_id_reference_type(x);
    }
    void load_override(object_id_type & t, int){
        // upto 2G objects
        uint_least32_t x=0;
        * this->This() >> x;
        t = object_id_type(x);
    }
    void load_override(object_reference_type & t, int){
        // upto 2G objects
        uint_least32_t x=0;
        * this->This() >> x;
        t = object_reference_type(x);
    }
    void load_override(tracking_type & t, int){
        char x=0;
        * this->This() >> x;
        t = (0 != x);
    }
    void load_override(serialization::collection_size_type & t, int){
      if (this->get_library_version() < 6) {
        unsigned int x=0;
        * this->This() >> x;
        t = serialization::collection_size_type(x);
      } 
      else {
        std::size_t x=0;
        * this->This() >> x;
        t = serialization::collection_size_type(x);
      }
    }

    STREAMS_BOOST_ARCHIVE_OR_WARCHIVE_DECL(void)
    load_override(class_name_type & t, int);
    STREAMS_BOOST_ARCHIVE_OR_WARCHIVE_DECL(void)
    init();
   
    basic_binary_iarchive(unsigned int flags) :
        detail::common_iarchive<Archive>(flags)
    {}
};

} // namespace archive
} // namespace streams_boost

#ifdef STREAMS_BOOST_MSVC
#pragma warning(pop)
#endif

#include <streams_boost/archive/detail/abi_suffix.hpp> // pops abi_suffix.hpp pragmas

#endif // STREAMS_BOOST_ARCHIVE_BASIC_BINARY_IARCHIVE_HPP
