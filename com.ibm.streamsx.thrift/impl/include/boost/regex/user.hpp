/*
 *
 * Copyright (c) 1998-2002
 * John Maddock
 *
 * Use, modification and distribution are subject to the 
 * Boost Software License, Version 1.0. (See accompanying file 
 * LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
 *
 */
 
 /*
  *   LOCATION:    see http://www.streams_boost.org for most recent version.
  *   FILE         user.hpp
  *   VERSION      see <streams_boost/version.hpp>
  *   DESCRIPTION: User settable options.
  */

// define if you want the regex library to use the C locale
// even on Win32:
// #define STREAMS_BOOST_REGEX_USE_C_LOCALE

// define this is you want the regex library to use the C++
// locale:
// #define STREAMS_BOOST_REGEX_USE_CPP_LOCALE

// define this if the runtime library is a dll, and you
// want STREAMS_BOOST_REGEX_DYN_LINK to set up dll exports/imports
// with __declspec(dllexport)/__declspec(dllimport.)
// #define STREAMS_BOOST_REGEX_HAS_DLL_RUNTIME

// define this if you want to dynamically link to regex,
// if the runtime library is also a dll (Probably Win32 specific,
// and has no effect unless STREAMS_BOOST_REGEX_HAS_DLL_RUNTIME is set):
// #define STREAMS_BOOST_REGEX_DYN_LINK

// define this if you don't want the lib to automatically
// select its link libraries:
// #define STREAMS_BOOST_REGEX_NO_LIB

// define this if templates with switch statements cause problems:
// #define STREAMS_BOOST_REGEX_NO_TEMPLATE_SWITCH_MERGE
 
// define this to disable Win32 support when available:
// #define STREAMS_BOOST_REGEX_NO_W32

// define this if bool is not a real type:
// #define STREAMS_BOOST_REGEX_NO_BOOL

// define this if no template instances are to be placed in
// the library rather than users object files:
// #define STREAMS_BOOST_REGEX_NO_EXTERNAL_TEMPLATES

// define this if the forward declarations in regex_fwd.hpp
// cause more problems than they are worth:
// #define STREAMS_BOOST_REGEX_NO_FWD

// define this if your compiler supports MS Windows structured
// exception handling.
// #define STREAMS_BOOST_REGEX_HAS_MS_STACK_GUARD

// define this if you want to use the recursive algorithm
// even if STREAMS_BOOST_REGEX_HAS_MS_STACK_GUARD is not defined.
// #define STREAMS_BOOST_REGEX_RECURSIVE

// define this if you want to use the non-recursive
// algorithm, even if the recursive version would be the default.
// #define STREAMS_BOOST_REGEX_NON_RECURSIVE

// define this if you want to set the size of the memory blocks
// used by the non-recursive algorithm.
// #define STREAMS_BOOST_REGEX_BLOCKSIZE 4096

// define this if you want to set the maximum number of memory blocks
// used by the non-recursive algorithm.
// #define STREAMS_BOOST_REGEX_MAX_BLOCKS 1024

// define this if you want to set the maximum number of memory blocks
// cached by the non-recursive algorithm: Normally this is 16, but can be 
// higher if you have multiple threads all using streams_boost.regex, or lower 
// if you don't want streams_boost.regex to cache memory.
// #define STREAMS_BOOST_REGEX_MAX_CACHE_BLOCKS 16

// define this if you want to be able to access extended capture
// information in your sub_match's (caution this will slow things
// down quite a bit).
// #define STREAMS_BOOST_REGEX_MATCH_EXTRA

// define this if you want to enable support for Unicode via ICU.
// #define STREAMS_BOOST_HAS_ICU
