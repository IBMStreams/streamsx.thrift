#ifndef STREAMS_BOOST_ARCHIVE_BINARY_IARCHIVE_HPP
#define STREAMS_BOOST_ARCHIVE_BINARY_IARCHIVE_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// binary_iarchive.hpp

// (C) Copyright 2002 Robert Ramey - http://www.rrsd.com . 
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org for updates, documentation, and revision history.

#include <istream>
#include <streams_boost/archive/binary_iarchive_impl.hpp>
#include <streams_boost/archive/detail/register_archive.hpp>

#ifdef STREAMS_BOOST_MSVC
#  pragma warning(push)
#  pragma warning(disable : 4511 4512)
#endif

namespace streams_boost { 
namespace archive {

// do not derive from the classes below.  If you want to extend this functionality
// via inhertance, derived from text_iarchive_impl instead.  This will
// preserve correct static polymorphism.

// same as binary_iarchive below - without the shared_ptr_helper
class naked_binary_iarchive : 
    public binary_iarchive_impl<
        streams_boost::archive::naked_binary_iarchive, 
        std::istream::char_type, 
        std::istream::traits_type
    >
{
public:
    naked_binary_iarchive(std::istream & is, unsigned int flags = 0) :
        binary_iarchive_impl<
            naked_binary_iarchive, std::istream::char_type, std::istream::traits_type
        >(is, flags)
    {}
    naked_binary_iarchive(std::streambuf & bsb, unsigned int flags = 0) :
        binary_iarchive_impl<
            naked_binary_iarchive, std::istream::char_type, std::istream::traits_type
        >(bsb, flags)
    {}
};

} // namespace archive
} // namespace streams_boost

// note special treatment of shared_ptr. This type needs a special
// structure associated with every archive.  We created a "mix-in"
// class to provide this functionality.  Since shared_ptr holds a
// special esteem in the streams_boost library - we included it here by default.
#include <streams_boost/archive/shared_ptr_helper.hpp>

namespace streams_boost { 
namespace archive {

// do not derive from this class.  If you want to extend this functionality
// via inhertance, derived from binary_iarchive_impl instead.  This will
// preserve correct static polymorphism.
class binary_iarchive : 
    public binary_iarchive_impl<
        streams_boost::archive::binary_iarchive, 
        std::istream::char_type, 
        std::istream::traits_type
    >,
    public detail::shared_ptr_helper
{
public:
    binary_iarchive(std::istream & is, unsigned int flags = 0) :
        binary_iarchive_impl<
            binary_iarchive, std::istream::char_type, std::istream::traits_type
        >(is, flags)
    {}
    binary_iarchive(std::streambuf & bsb, unsigned int flags = 0) :
        binary_iarchive_impl<
            binary_iarchive, std::istream::char_type, std::istream::traits_type
        >(bsb, flags)
    {}
};

} // namespace archive
} // namespace streams_boost

// required by export
STREAMS_BOOST_SERIALIZATION_REGISTER_ARCHIVE(streams_boost::archive::binary_iarchive)
STREAMS_BOOST_SERIALIZATION_USE_ARRAY_OPTIMIZATION(streams_boost::archive::binary_iarchive)

#ifdef STREAMS_BOOST_MSVC
#pragma warning(pop)
#endif

#endif // STREAMS_BOOST_ARCHIVE_BINARY_IARCHIVE_HPP
