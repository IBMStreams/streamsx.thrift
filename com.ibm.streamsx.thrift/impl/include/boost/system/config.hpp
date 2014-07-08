//  streams_boost/system/config.hpp  -------------------------------------------------//

//  Copyright Beman Dawes 2003, 2006

//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org/libs/system for documentation.

#ifndef STREAMS_BOOST_SYSTEM_CONFIG_HPP                  
#define STREAMS_BOOST_SYSTEM_CONFIG_HPP

#include <streams_boost/config.hpp>

//  STREAMS_BOOST_POSIX_API or STREAMS_BOOST_WINDOWS_API specify which API to use.
//  If not specified, a sensible default will be applied.

# if defined( STREAMS_BOOST_WINDOWS_API ) && defined( STREAMS_BOOST_POSIX_API )
#   error both STREAMS_BOOST_WINDOWS_API and STREAMS_BOOST_POSIX_API are defined
# elif !defined( STREAMS_BOOST_WINDOWS_API ) && !defined( STREAMS_BOOST_POSIX_API )
#   if defined(_WIN32) || defined(__WIN32__) || defined(WIN32) || defined(__CYGWIN__)
#     define STREAMS_BOOST_WINDOWS_API
#   else
#     define STREAMS_BOOST_POSIX_API 
#   endif
# endif

//  enable dynamic linking on Windows  ---------------------------------------//

//#  if (defined(STREAMS_BOOST_ALL_DYN_LINK) || defined(STREAMS_BOOST_SYSTEM_DYN_LINK)) && defined(__BORLANDC__) && defined(__WIN32__)
//#    error Dynamic linking Boost.System does not work for Borland; use static linking instead
//#  endif

#ifdef STREAMS_BOOST_HAS_DECLSPEC // defined in config system
// we need to import/export our code only if the user has specifically
// asked for it by defining either STREAMS_BOOST_ALL_DYN_LINK if they want all streams_boost
// libraries to be dynamically linked, or STREAMS_BOOST_SYSTEM_DYN_LINK
// if they want just this one to be dynamically liked:
#if defined(STREAMS_BOOST_ALL_DYN_LINK) || defined(STREAMS_BOOST_SYSTEM_DYN_LINK)
// export if this is our own source, otherwise import:
#ifdef STREAMS_BOOST_SYSTEM_SOURCE
# define STREAMS_BOOST_SYSTEM_DECL __declspec(dllexport)
#else
# define STREAMS_BOOST_SYSTEM_DECL __declspec(dllimport)
#endif  // STREAMS_BOOST_SYSTEM_SOURCE
#endif  // DYN_LINK
#endif  // STREAMS_BOOST_HAS_DECLSPEC
//
// if STREAMS_BOOST_SYSTEM_DECL isn't defined yet define it now:
#ifndef STREAMS_BOOST_SYSTEM_DECL
#define STREAMS_BOOST_SYSTEM_DECL
#endif

//  enable automatic library variant selection  ------------------------------// 

#if !defined(STREAMS_BOOST_SYSTEM_SOURCE) && !defined(STREAMS_BOOST_ALL_NO_LIB) && !defined(STREAMS_BOOST_SYSTEM_NO_LIB)
//
// Set the name of our library, this will get undef'ed by auto_link.hpp
// once it's done with it:
//
#define STREAMS_BOOST_LIB_NAME streams_boost_system
//
// If we're importing code from a dll, then tell auto_link.hpp about it:
//
#if defined(STREAMS_BOOST_ALL_DYN_LINK) || defined(STREAMS_BOOST_SYSTEM_DYN_LINK)
#  define STREAMS_BOOST_DYN_LINK
#endif
//
// And include the header that does the work:
//
#include <streams_boost/config/auto_link.hpp>
#endif  // auto-linking disabled

#endif // STREAMS_BOOST_SYSTEM_CONFIG_HPP

