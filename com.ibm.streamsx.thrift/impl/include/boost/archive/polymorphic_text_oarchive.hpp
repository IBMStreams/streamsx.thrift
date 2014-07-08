#ifndef STREAMS_BOOST_ARCHIVE_POLYMORPHIC_TEXT_OARCHIVE_HPP
#define STREAMS_BOOST_ARCHIVE_POLYMORPHIC_TEXT_OARCHIVE_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// polymorphic_text_oarchive.hpp

// (C) Copyright 2002 Robert Ramey - http://www.rrsd.com . 
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org for updates, documentation, and revision history.

#include <streams_boost/config.hpp>
#include <streams_boost/archive/text_oarchive.hpp>
#include <streams_boost/archive/detail/polymorphic_oarchive_route.hpp>

namespace streams_boost { 
namespace archive {

typedef detail::polymorphic_oarchive_route<
    text_oarchive_impl<naked_text_oarchive> 
> polymorphic_text_oarchive;

} // namespace archive
} // namespace streams_boost

// required by export
STREAMS_BOOST_SERIALIZATION_REGISTER_ARCHIVE(
    streams_boost::archive::polymorphic_text_oarchive
)

#endif // STREAMS_BOOST_ARCHIVE_POLYMORPHIC_TEXT_OARCHIVE_HPP

