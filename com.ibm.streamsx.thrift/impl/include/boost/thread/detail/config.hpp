// Copyright (C) 2001-2003
// William E. Kempf
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying 
//  file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_THREAD_CONFIG_WEK01032003_HPP
#define STREAMS_BOOST_THREAD_CONFIG_WEK01032003_HPP

#include <streams_boost/config.hpp>
#include <streams_boost/detail/workaround.hpp>

#if STREAMS_BOOST_WORKAROUND(__BORLANDC__, < 0x600)
#  pragma warn -8008 // Condition always true/false
#  pragma warn -8080 // Identifier declared but never used
#  pragma warn -8057 // Parameter never used
#  pragma warn -8066 // Unreachable code
#endif

#include "platform.hpp"

// compatibility with the rest of Boost's auto-linking code:
#if defined(STREAMS_BOOST_THREAD_DYN_DLL) || defined(STREAMS_BOOST_ALL_DYN_LINK)
# undef  STREAMS_BOOST_THREAD_USE_LIB
# define STREAMS_BOOST_THREAD_USE_DLL
#endif

#if defined(STREAMS_BOOST_THREAD_BUILD_DLL)   //Build dll
#elif defined(STREAMS_BOOST_THREAD_BUILD_LIB) //Build lib
#elif defined(STREAMS_BOOST_THREAD_USE_DLL)   //Use dll
#elif defined(STREAMS_BOOST_THREAD_USE_LIB)   //Use lib
#else //Use default
#   if defined(STREAMS_BOOST_THREAD_PLATFORM_WIN32)
#       if defined(STREAMS_BOOST_MSVC) || defined(STREAMS_BOOST_INTEL_WIN)
            //For compilers supporting auto-tss cleanup
            //with Boost.Threads lib, use Boost.Threads lib
#           define STREAMS_BOOST_THREAD_USE_LIB
#       else
            //For compilers not yet supporting auto-tss cleanup
            //with Boost.Threads lib, use Boost.Threads dll
#           define STREAMS_BOOST_THREAD_USE_DLL
#       endif
#   else
#       define STREAMS_BOOST_THREAD_USE_LIB
#   endif
#endif

#if defined(STREAMS_BOOST_HAS_DECLSPEC)
#   if defined(STREAMS_BOOST_THREAD_BUILD_DLL) //Build dll
#       define STREAMS_BOOST_THREAD_DECL __declspec(dllexport)
#   elif defined(STREAMS_BOOST_THREAD_USE_DLL) //Use dll
#       define STREAMS_BOOST_THREAD_DECL __declspec(dllimport)
#   else
#       define STREAMS_BOOST_THREAD_DECL
#   endif
#else
#   define STREAMS_BOOST_THREAD_DECL
#endif // STREAMS_BOOST_HAS_DECLSPEC

//
// Automatically link to the correct build variant where possible.
//
#if !defined(STREAMS_BOOST_ALL_NO_LIB) && !defined(STREAMS_BOOST_THREAD_NO_LIB) && !defined(STREAMS_BOOST_THREAD_BUILD_DLL) && !defined(STREAMS_BOOST_THREAD_BUILD_LIB)
//
// Tell the autolink to link dynamically, this will get undef'ed by auto_link.hpp
// once it's done with it: 
//
#if defined(STREAMS_BOOST_THREAD_USE_DLL)
#   define STREAMS_BOOST_DYN_LINK
#endif
//
// Set the name of our library, this will get undef'ed by auto_link.hpp
// once it's done with it:
//
#if defined(STREAMS_BOOST_THREAD_LIB_NAME)
#    define STREAMS_BOOST_LIB_NAME STREAMS_BOOST_THREAD_LIB_NAME
#else
#    define STREAMS_BOOST_LIB_NAME streams_boost_thread
#endif
//
// If we're importing code from a dll, then tell auto_link.hpp about it:
//
// And include the header that does the work:
//
#include <streams_boost/config/auto_link.hpp>
#endif  // auto-linking disabled

#endif // STREAMS_BOOST_THREAD_CONFIG_WEK1032003_HPP

// Change Log:
//   22 Jan 05 Roland Schwarz (speedsnail)
//      Usage of STREAMS_BOOST_HAS_DECLSPEC macro.
//      Default again is static lib usage.
//      STREAMS_BOOST_DYN_LINK only defined when autolink included.
