//  streams_boost/filesystem/config.hpp  ---------------------------------------------//

//  Copyright Beman Dawes 2003

//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

//  See library home page at http://www.streams_boost.org/libs/filesystem

//----------------------------------------------------------------------------// 

#ifndef STREAMS_BOOST_FILESYSTEM_CONFIG_HPP
#define STREAMS_BOOST_FILESYSTEM_CONFIG_HPP

#define STREAMS_BOOST_FILESYSTEM_I18N  // aid users wishing to compile several versions

//  ability to change namespace aids path_table.cpp  ------------------------// 
#ifndef STREAMS_BOOST_FILESYSTEM_NAMESPACE
# define STREAMS_BOOST_FILESYSTEM_NAMESPACE filesystem
#endif

// This header implements separate compilation features as described in
// http://www.streams_boost.org/more/separate_compilation.html

#include <streams_boost/config.hpp>
#include <streams_boost/detail/workaround.hpp> 

//  determine platform  ------------------------------------------------------//

//  STREAMS_BOOST_CYGWIN_PATH implies STREAMS_BOOST_WINDOWS_PATH and STREAMS_BOOST_POSIX_API

# if defined(STREAMS_BOOST_CYGWIN_PATH)
#   if defined(STREAMS_BOOST_POSIX_PATH)
#     error STREAMS_BOOST_POSIX_PATH is invalid when STREAMS_BOOST_CYGWIN_PATH is defined
#   endif
#   if defined(STREAMS_BOOST_WINDOWS_API)
#     error STREAMS_BOOST_WINDOWS_API is invalid when STREAMS_BOOST_CYGWIN_PATH is defined
#   endif
#   define STREAMS_BOOST_WINDOWS_PATH
#   define STREAMS_BOOST_POSIX_API
# endif

//  STREAMS_BOOST_POSIX_API or STREAMS_BOOST_WINDOWS_API specify which API to use

# if defined( STREAMS_BOOST_WINDOWS_API ) && defined( STREAMS_BOOST_POSIX_API )
#   error both STREAMS_BOOST_WINDOWS_API and STREAMS_BOOST_POSIX_API are defined
# elif !defined( STREAMS_BOOST_WINDOWS_API ) && !defined( STREAMS_BOOST_POSIX_API )
#   if defined(_WIN32) || defined(__WIN32__) || defined(WIN32) || defined(__CYGWIN__)
#     define STREAMS_BOOST_WINDOWS_API
#   else
#     define STREAMS_BOOST_POSIX_API 
#   endif
# endif

//  STREAMS_BOOST_WINDOWS_PATH enables Windows path syntax recognition

# if !defined(STREAMS_BOOST_POSIX_PATH) && (defined(_WIN32) || defined(__WIN32__) || defined(WIN32) || defined(__CYGWIN__))
#   define STREAMS_BOOST_WINDOWS_PATH
# endif

//  narrow support only for badly broken compilers or libraries  -------------//

# if defined(STREAMS_BOOST_NO_STD_WSTRING) || defined(STREAMS_BOOST_NO_SFINAE) || defined(STREAMS_BOOST_NO_STD_LOCALE) || STREAMS_BOOST_WORKAROUND(__BORLANDC__, <0x610)
#   define STREAMS_BOOST_FILESYSTEM_NARROW_ONLY
# endif

//  enable dynamic linking on Windows  ---------------------------------------//

#  if (defined(STREAMS_BOOST_ALL_DYN_LINK) || defined(STREAMS_BOOST_FILESYSTEM_DYN_LINK)) &&  STREAMS_BOOST_WORKAROUND(__BORLANDC__, <0x610) && defined(__WIN32__)
#    error Dynamic linking Boost.Filesystem does not work for Borland; use static linking instead
#  endif

#ifdef STREAMS_BOOST_HAS_DECLSPEC // defined in config system
// we need to import/export our code only if the user has specifically
// asked for it by defining either STREAMS_BOOST_ALL_DYN_LINK if they want all streams_boost
// libraries to be dynamically linked, or STREAMS_BOOST_FILESYSTEM_DYN_LINK
// if they want just this one to be dynamically liked:
#if defined(STREAMS_BOOST_ALL_DYN_LINK) || defined(STREAMS_BOOST_FILESYSTEM_DYN_LINK)
// export if this is our own source, otherwise import:
#ifdef STREAMS_BOOST_FILESYSTEM_SOURCE
# define STREAMS_BOOST_FILESYSTEM_DECL __declspec(dllexport)
#else
# define STREAMS_BOOST_FILESYSTEM_DECL __declspec(dllimport)
#endif  // STREAMS_BOOST_FILESYSTEM_SOURCE
#endif  // DYN_LINK
#endif  // STREAMS_BOOST_HAS_DECLSPEC
//
// if STREAMS_BOOST_FILESYSTEM_DECL isn't defined yet define it now:
#ifndef STREAMS_BOOST_FILESYSTEM_DECL
#define STREAMS_BOOST_FILESYSTEM_DECL
#endif

//  enable automatic library variant selection  ------------------------------// 

#if !defined(STREAMS_BOOST_FILESYSTEM_SOURCE) && !defined(STREAMS_BOOST_ALL_NO_LIB) && !defined(STREAMS_BOOST_FILESYSTEM_NO_LIB)
//
// Set the name of our library, this will get undef'ed by auto_link.hpp
// once it's done with it:
//
#define STREAMS_BOOST_LIB_NAME streams_boost_filesystem
//
// If we're importing code from a dll, then tell auto_link.hpp about it:
//
#if defined(STREAMS_BOOST_ALL_DYN_LINK) || defined(STREAMS_BOOST_FILESYSTEM_DYN_LINK)
#  define STREAMS_BOOST_DYN_LINK
#endif
//
// And include the header that does the work:
//
#include <streams_boost/config/auto_link.hpp>
#endif  // auto-linking disabled

#endif // STREAMS_BOOST_FILESYSTEM_CONFIG_HPP
