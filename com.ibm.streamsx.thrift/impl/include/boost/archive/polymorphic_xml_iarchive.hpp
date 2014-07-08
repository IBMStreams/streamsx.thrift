#ifndef STREAMS_BOOST_ARCHIVE_POLYMORPHIC_XML_IARCHIVE_HPP
#define STREAMS_BOOST_ARCHIVE_POLYMORPHIC_XML_IARCHIVE_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// polymorphic_xml_iarchive.hpp

// (C) Copyright 2002 Robert Ramey - http://www.rrsd.com . 
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org for updates, documentation, and revision history.

#include <streams_boost/config.hpp>
#include <streams_boost/archive/xml_iarchive.hpp>
#include <streams_boost/archive/detail/polymorphic_iarchive_route.hpp>

#ifdef STREAMS_BOOST_MSVC
#  pragma warning(push)
#  pragma warning(disable : 4511 4512)
#endif

namespace streams_boost { 
namespace archive {

class polymorphic_xml_iarchive : 
    public detail::polymorphic_iarchive_route<naked_xml_iarchive>
{
public:
    polymorphic_xml_iarchive(std::istream & is, unsigned int flags = 0) :
        detail::polymorphic_iarchive_route<naked_xml_iarchive>(is, flags)
    {}
    ~polymorphic_xml_iarchive(){}
};

} // namespace archive
} // namespace streams_boost

#ifdef STREAMS_BOOST_MSVC
#pragma warning(pop)
#endif

// required by export
STREAMS_BOOST_SERIALIZATION_REGISTER_ARCHIVE(
    streams_boost::archive::polymorphic_xml_iarchive
)

#endif // STREAMS_BOOST_ARCHIVE_POLYMORPHIC_XML_IARCHIVE_HPP

