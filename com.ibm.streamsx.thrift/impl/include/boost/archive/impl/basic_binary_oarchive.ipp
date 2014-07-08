/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// basic_binary_oarchive.ipp:

// (C) Copyright 2002 Robert Ramey - http://www.rrsd.com . 
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org for updates, documentation, and revision history.
#include <string>
#include <cassert>
#include <algorithm>
#include <cstring>

#include <streams_boost/config.hpp> // for STREAMS_BOOST_DEDUCED_TYPENAME
#if defined(STREAMS_BOOST_NO_STDC_NAMESPACE)
namespace std{ 
    using ::memcpy; 
}
#endif

#include <streams_boost/archive/basic_binary_oarchive.hpp>

namespace streams_boost {
namespace archive {

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// implementation of binary_binary_oarchive

template<class Archive>
#if !defined(__BORLANDC__)
STREAMS_BOOST_ARCHIVE_OR_WARCHIVE_DECL(void)
#else
void
#endif
basic_binary_oarchive<Archive>::init(){
    // write signature in an archive version independent manner
    const std::string file_signature(STREAMS_BOOST_ARCHIVE_SIGNATURE());
    * this->This() << file_signature;
    // write library version
    const version_type v(STREAMS_BOOST_ARCHIVE_VERSION());
    * this->This() << v;
}

} // namespace archive
} // namespace streams_boost
