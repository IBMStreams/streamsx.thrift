#ifndef STREAMS_BOOST_ARCHIVE_DETAIL_BASIC_CONFIG_HPP
#define STREAMS_BOOST_ARCHIVE_DETAIL_BASIC_CONFIG_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

//  basic_config.hpp  ---------------------------------------------//

//  (c) Copyright Robert Ramey 2004
//  Use, modification, and distribution is subject to the Boost Software
//  License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt)

//  See library home page at http://www.streams_boost.org/libs/serialization

//----------------------------------------------------------------------------// 

// This header implements separate compilation features as described in
// http://www.streams_boost.org/more/separate_compilation.html

#include <streams_boost/config.hpp>

#ifdef STREAMS_BOOST_HAS_DECLSPEC // defined in config system
// we need to import/export our code only if the user has specifically
// asked for it by defining either STREAMS_BOOST_ALL_DYN_LINK if they want all streams_boost
// libraries to be dynamically linked, or STREAMS_BOOST_ARCHIVE_DYN_LINK
// if they want just this one to be dynamically linked:
#if defined(STREAMS_BOOST_ALL_DYN_LINK) || defined(STREAMS_BOOST_ARCHIVE_DYN_LINK)
// export if this is our own source, otherwise import:
#ifdef STREAMS_BOOST_ARCHIVE_SOURCE
# define STREAMS_BOOST_ARCHIVE_DECL __declspec(dllexport)
#else
# define STREAMS_BOOST_ARCHIVE_DECL __declspec(dllimport)
#endif  // STREAMS_BOOST_ARCHIVE_SOURCE
#endif  // DYN_LINK
#endif  // STREAMS_BOOST_HAS_DECLSPEC
//
// if STREAMS_BOOST_ARCHIVE_DECL isn't defined yet define it now:
#ifndef STREAMS_BOOST_ARCHIVE_DECL
#define STREAMS_BOOST_ARCHIVE_DECL
#endif

#endif // STREAMS_BOOST_ARCHIVE_DETAIL_BASIC_CONFIG_HPP
