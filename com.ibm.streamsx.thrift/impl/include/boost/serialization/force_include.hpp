#ifndef STREAMS_BOOST_SERIALIZATION_FORCE_INCLUDE_HPP
#define STREAMS_BOOST_SERIALIZATION_FORCE_INCLUDE_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// force_include.hpp:

// (C) Copyright 2002 Robert Ramey - http://www.rrsd.com . 
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org for updates, documentation, and revision history.

#include <streams_boost/config.hpp>

// the following help macro is to guarentee that certain coded
// is not removed by over-eager linker optimiser.  In certain cases
// we create static objects must be created but are actually never
// referenced - creation has a side-effect such as global registration
// which is important to us. We make an effort to refer these objects
// so that a smart linker won't remove them as being unreferenced.
// In microsoft compilers, inlining the code that does the referring
// means the code gets lost and the static object is not included
// in the library and hence never registered.  This manifests itself
// in an ungraceful crash at runtime when (and only when) built in
// release mode.

#if defined(STREAMS_BOOST_HAS_DECLSPEC) && !defined(__COMO__)
#   if defined(__BORLANDC__)
#       define STREAMS_BOOST_DLLEXPORT __export
#   else
#       define STREAMS_BOOST_DLLEXPORT __declspec(dllexport)
#   endif
#elif ! defined(_WIN32) && ! defined(_WIN64)
#   if defined(__MWERKS__)
#       define STREAMS_BOOST_DLLEXPORT __declspec(dllexport)
#   elif defined(__GNUC__) && (__GNUC__ >= 3)
#       define STREAMS_BOOST_USED __attribute__ ((used))
#   elif defined(__INTEL_COMPILER) && (STREAMS_BOOST_INTEL_CXX_VERSION >= 800)
#       define STREAMS_BOOST_USED __attribute__ ((used))
#   endif
#endif

#ifndef STREAMS_BOOST_USED
#    define STREAMS_BOOST_USED
#endif

#ifndef STREAMS_BOOST_DLLEXPORT
#    define STREAMS_BOOST_DLLEXPORT
#endif

#endif // STREAMS_BOOST_SERIALIZATION_FORCE_INCLUDE_HPP
