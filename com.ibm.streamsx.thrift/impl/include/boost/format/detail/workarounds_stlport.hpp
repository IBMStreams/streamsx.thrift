// ----------------------------------------------------------------------------
// workarounds_stlport.hpp : workaround STLport issues
// ----------------------------------------------------------------------------

//  Copyright Samuel Krempp 2003. Use, modification, and distribution are
//  subject to the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

// see http://www.streams_boost.org/libs/format for library home page

// ----------------------------------------------------------------------------

#ifndef STREAMS_BOOST_MACROS_STLPORT_HPP
#define STREAMS_BOOST_MACROS_STLPORT_HPP

#if defined(_STLPORT_VERSION) && STREAMS_BOOST_WORKAROUND( STREAMS_BOOST_MSVC, <= 1300)
// msvc-6-stlport fails to find basic_string::append( iterator, iterator) when linking
// might affect other MSwindows compilers 
#define STREAMS_BOOST_NO_STRING_APPEND
#endif

// *** This should go to "streams_boost/config/stdlib/stlport.hpp".

// If the streams are not native and there are problems with using templates
// accross namespaces, we define some macros to enable a workaround for this.

// STLport 4.5
#if !defined(_STLP_OWN_IOSTREAMS) && defined(_STLP_USE_NAMESPACES) && defined(STREAMS_BOOST_NO_USING_TEMPLATE)
#  define STREAMS_BOOST_IO_STD 
#  define STREAMS_BOOST_IO_NEEDS_USING_DECLARATION
#endif

// STLport 4.0
#if !defined(__SGI_STL_OWN_IOSTREAMS) && defined(__STL_USE_OWN_NAMESPACE) && defined(STREAMS_BOOST_NO_USING_TEMPLATE)
#  define STREAMS_BOOST_IO_STD 
#  define STREAMS_BOOST_IO_NEEDS_USING_DECLARATION
#endif


// ----------------------------------------------------------------------------

#endif // STREAMS_BOOST_MACROS_STLPORT_HPP
