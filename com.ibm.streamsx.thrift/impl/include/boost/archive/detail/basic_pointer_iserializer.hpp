#ifndef STREAMS_BOOST_ARCHIVE_BASIC_POINTER_ISERIALIZER_HPP
#define STREAMS_BOOST_ARCHIVE_BASIC_POINTER_ISERIALIZER_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// basic_pointer_oserializer.hpp: extenstion of type_info required for 
// serialization.

// (C) Copyright 2002 Robert Ramey - http://www.rrsd.com . 
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org for updates, documentation, and revision history.
#include <streams_boost/config.hpp>
#include <streams_boost/noncopyable.hpp>
#include <streams_boost/archive/detail/auto_link_archive.hpp>
#include <streams_boost/archive/detail/basic_serializer.hpp>

#include <streams_boost/archive/detail/abi_prefix.hpp> // must be the last header

#ifdef STREAMS_BOOST_MSVC
#  pragma warning(push)
#  pragma warning(disable : 4511 4512)
#endif

namespace streams_boost {
namespace serialization {
    class extended_type_info;
} // namespace serialization

// forward declarations
namespace archive {
namespace detail {

class STREAMS_BOOST_ARCHIVE_DECL(STREAMS_BOOST_PP_EMPTY()) basic_iarchive;
class STREAMS_BOOST_ARCHIVE_DECL(STREAMS_BOOST_PP_EMPTY()) basic_iserializer;

class STREAMS_BOOST_ARCHIVE_DECL(STREAMS_BOOST_PP_EMPTY()) basic_pointer_iserializer 
    : public basic_serializer {
protected:
    explicit basic_pointer_iserializer(
        const streams_boost::serialization::extended_type_info & type_
    );
    // account for bogus gcc warning
    #if defined(__GNUC__)
    virtual
    #endif
    ~basic_pointer_iserializer();
public:
    virtual const basic_iserializer & get_basic_serializer() const = 0;
    virtual void load_object_ptr(
        basic_iarchive & ar, 
        void * & x,
        const unsigned int file_version
    ) const = 0;
};

} // namespace detail
} // namespace archive
} // namespace streams_boost

#ifdef STREAMS_BOOST_MSVC
#pragma warning(pop)
#endif

#include <streams_boost/archive/detail/abi_suffix.hpp> // pops abi_suffix.hpp pragmas

#endif // STREAMS_BOOST_ARCHIVE_BASIC_POINTER_ISERIALIZER_HPP
