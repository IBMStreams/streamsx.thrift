#ifndef STREAMS_BOOST_ARCHIVE_BINARY_WOARCHIVE_HPP
#define STREAMS_BOOST_ARCHIVE_BINARY_WOARCHIVE_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// binary_woarchive.hpp

// (C) Copyright 2002 Robert Ramey - http://www.rrsd.com . 
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org for updates, documentation, and revision history.

#include <streams_boost/config.hpp>
#ifdef STREAMS_BOOST_NO_STD_WSTREAMBUF
#error "wide char i/o not supported on this platform"
#else

#include <ostream>
#include <streams_boost/archive/binary_oarchive_impl.hpp>
#include <streams_boost/archive/detail/register_archive.hpp>

namespace streams_boost { 
namespace archive {

// do not derive from this class.  If you want to extend this functionality
// via inhertance, derived from binary_oarchive_impl instead.  This will
// preserve correct static polymorphism.
class binary_woarchive : 
    public binary_oarchive_impl<
            binary_woarchive, std::wostream::char_type, std::wostream::traits_type
        >
{
public:
    binary_woarchive(std::wostream & os, unsigned int flags = 0) :
        binary_oarchive_impl<
            binary_woarchive, std::wostream::char_type, std::wostream::traits_type
        >(os, flags)
    {}
    binary_woarchive(std::wstreambuf & bsb, unsigned int flags = 0) :
        binary_oarchive_impl<
            binary_woarchive, std::wostream::char_type, std::wostream::traits_type
        >(bsb, flags)
    {}
};

typedef binary_woarchive naked_binary_woarchive;

} // namespace archive
} // namespace streams_boost

// required by export
STREAMS_BOOST_SERIALIZATION_REGISTER_ARCHIVE(streams_boost::archive::binary_woarchive)

#endif // STREAMS_BOOST_NO_STD_WSTREAMBUF
#endif // STREAMS_BOOST_ARCHIVE_BINARY_WOARCHIVE_HPP
