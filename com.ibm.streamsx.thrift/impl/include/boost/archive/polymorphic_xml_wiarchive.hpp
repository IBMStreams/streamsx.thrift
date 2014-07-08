#ifndef STREAMS_BOOST_ARCHIVE_POLYMORPHIC_XML_WIARCHIVE_HPP
#define STREAMS_BOOST_ARCHIVE_POLYMORPHIC_XML_WIARCHIVE_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// polymorphic_xml_wiarchive.hpp

// (C) Copyright 2002 Robert Ramey - http://www.rrsd.com . 
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org for updates, documentation, and revision history.

#include <streams_boost/config.hpp>
#ifdef STREAMS_BOOST_NO_STD_WSTREAMBUF
#error "wide char i/o not supported on this platform"
#else

#include <streams_boost/archive/xml_wiarchive.hpp>
#include <streams_boost/archive/detail/polymorphic_iarchive_route.hpp>

namespace streams_boost { 
namespace archive {

class polymorphic_xml_wiarchive : 
    public detail::polymorphic_iarchive_route<naked_xml_wiarchive>
{
public:
    polymorphic_xml_wiarchive(std::wistream & is, unsigned int flags = 0) :
        detail::polymorphic_iarchive_route<naked_xml_wiarchive>(is, flags)
    {}
    ~polymorphic_xml_wiarchive(){}
};

} // namespace archive
} // namespace streams_boost

// required by export
STREAMS_BOOST_SERIALIZATION_REGISTER_ARCHIVE(
    streams_boost::archive::polymorphic_xml_wiarchive
)

#endif // STREAMS_BOOST_NO_STD_WSTREAMBUF 
#endif // STREAMS_BOOST_ARCHIVE_POLYMORPHIC_XML_WIARCHIVE_HPP

