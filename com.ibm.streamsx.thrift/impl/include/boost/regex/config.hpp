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
  *   FILE         config.hpp
  *   VERSION      see <streams_boost/version.hpp>
  *   DESCRIPTION: regex extended config setup.
  */

#ifndef STREAMS_BOOST_REGEX_CONFIG_HPP
#define STREAMS_BOOST_REGEX_CONFIG_HPP
/*
 * Borland C++ Fix/error check
 * this has to go *before* we include any std lib headers:
 */
#if defined(__BORLANDC__)
#  include <streams_boost/regex/config/borland.hpp>
#endif

/*****************************************************************************
 *
 *  Include all the headers we need here:
 *
 ****************************************************************************/

#ifdef __cplusplus

#  ifndef STREAMS_BOOST_REGEX_USER_CONFIG
#     define STREAMS_BOOST_REGEX_USER_CONFIG <streams_boost/regex/user.hpp>
#  endif

#  include STREAMS_BOOST_REGEX_USER_CONFIG

#  include <streams_boost/config.hpp>

#else
   /*
    * C build,
    * don't include <streams_boost/config.hpp> because that may
    * do C++ specific things in future...
    */
#  include <stdlib.h>
#  include <stddef.h>
#  ifdef _MSC_VER
#     define STREAMS_BOOST_MSVC _MSC_VER
#  endif
#endif

/*****************************************************************************
 *
 *  Boilerplate regex config options:
 *
 ****************************************************************************/

/* Obsolete macro, use STREAMS_BOOST_VERSION instead: */
#define STREAMS_BOOST_RE_VERSION 320

/* fix: */
#if defined(_UNICODE) && !defined(UNICODE)
#define UNICODE
#endif

/*
 * Fix for gcc prior to 3.4: std::ctype<wchar_t> doesn't allow
 * masks to be combined, for example:
 * std::use_facet<std::ctype<wchar_t> >.is(std::ctype_base::lower|std::ctype_base::upper, L'a');
 * returns *false*.
 */
#ifdef __GLIBCPP__
#  define STREAMS_BOOST_REGEX_BUGGY_CTYPE_FACET
#endif

/*
 * Intel C++ before 8.0 ends up with unresolved externals unless we turn off
 * extern template support:
 */
#if defined(STREAMS_BOOST_INTEL) && defined(__cplusplus) && (STREAMS_BOOST_INTEL <= 800)
#  define STREAMS_BOOST_REGEX_NO_EXTERNAL_TEMPLATES
#endif
/*
 * Visual C++ doesn't support external templates with C++ extensions turned off:
 */
#if defined(_MSC_VER) && !defined(_MSC_EXTENSIONS)
#  define STREAMS_BOOST_REGEX_NO_EXTERNAL_TEMPLATES
#endif
/*
 * Shared regex lib will crash without this, frankly it looks a lot like a gcc bug:
 */
#if defined(__MINGW32__)
#  define STREAMS_BOOST_REGEX_NO_EXTERNAL_TEMPLATES
#endif

/*
 * If there isn't good enough wide character support then there will
 * be no wide character regular expressions:
 */
#if (defined(STREAMS_BOOST_NO_CWCHAR) || defined(STREAMS_BOOST_NO_CWCTYPE) || defined(STREAMS_BOOST_NO_STD_WSTRING))
#  if !defined(STREAMS_BOOST_NO_WREGEX)
#     define STREAMS_BOOST_NO_WREGEX
#  endif
#else
#  if defined(__sgi) && (defined(__SGI_STL_PORT) || defined(_STLPORT_VERSION))
      /* STLPort on IRIX is misconfigured: <cwctype> does not compile
       * as a temporary fix include <wctype.h> instead and prevent inclusion
       * of STLPort version of <cwctype> */
#     include <wctype.h>
#     define __STLPORT_CWCTYPE
#     define _STLP_CWCTYPE
#  endif

#ifdef __cplusplus
#  include <streams_boost/regex/config/cwchar.hpp>
#endif

#endif

/*
 * If Win32 support has been disabled for streams_boost in general, then
 * it is for regex in particular:
 */
#if defined(STREAMS_BOOST_DISABLE_WIN32) && !defined(STREAMS_BOOST_REGEX_NO_W32)
#  define STREAMS_BOOST_REGEX_NO_W32
#endif

/* disable our own file-iterators and mapfiles if we can't
 * support them: */
#if !defined(STREAMS_BOOST_HAS_DIRENT_H) && !(defined(_WIN32) && !defined(STREAMS_BOOST_REGEX_NO_W32))
#  define STREAMS_BOOST_REGEX_NO_FILEITER
#endif

/* backwards compatibitity: */
#if defined(STREAMS_BOOST_RE_NO_LIB)
#  define STREAMS_BOOST_REGEX_NO_LIB
#endif

#if defined(__GNUC__) && (defined(_WIN32) || defined(__CYGWIN__))
/* gcc on win32 has problems if you include <windows.h>
   (sporadically generates bad code). */
#  define STREAMS_BOOST_REGEX_NO_W32
#endif
#if defined(__COMO__) && !defined(STREAMS_BOOST_REGEX_NO_W32) && !defined(_MSC_EXTENSIONS)
#  define STREAMS_BOOST_REGEX_NO_W32
#endif

/*****************************************************************************
 *
 *  Wide character workarounds:
 *
 ****************************************************************************/

/*
 * define STREAMS_BOOST_REGEX_HAS_OTHER_WCHAR_T when wchar_t is a native type, but the users
 * code may be built with wchar_t as unsigned short: basically when we're building
 * with MSVC and the /Zc:wchar_t option we place some extra unsigned short versions
 * of the non-inline functions in the library, so that users can still link to the lib,
 * irrespective of whether their own code is built with /Zc:wchar_t.
 */
#if defined(__cplusplus) && (defined(STREAMS_BOOST_MSVC) || defined(__ICL)) && !defined(STREAMS_BOOST_NO_INTRINSIC_WCHAR_T) && defined(STREAMS_BOOST_WINDOWS) && !defined(__SGI_STL_PORT) && !defined(_STLPORT_VERSION) && !defined(STREAMS_BOOST_RWSTD_VER)
#  define STREAMS_BOOST_REGEX_HAS_OTHER_WCHAR_T
#  ifdef STREAMS_BOOST_MSVC
#     pragma warning(push)
#     pragma warning(disable : 4251 4231 4660)
#  endif
#  if defined(_DLL) && defined(STREAMS_BOOST_MSVC) && (STREAMS_BOOST_MSVC < 1600)
#     include <string>
      extern template class __declspec(dllimport) std::basic_string<unsigned short>;
#  endif
#  ifdef STREAMS_BOOST_MSVC
#     pragma warning(pop)
#  endif
#endif


/*****************************************************************************
 *
 *  Set up dll import/export options:
 *
 ****************************************************************************/

#if defined(STREAMS_BOOST_HAS_DECLSPEC) && (defined(STREAMS_BOOST_REGEX_DYN_LINK) || defined(STREAMS_BOOST_ALL_DYN_LINK)) && !defined(STREAMS_BOOST_REGEX_STATIC_LINK)
#  if defined(STREAMS_BOOST_REGEX_SOURCE)
#     define STREAMS_BOOST_REGEX_DECL __declspec(dllexport)
#     define STREAMS_BOOST_REGEX_BUILD_DLL
#  else
#     define STREAMS_BOOST_REGEX_DECL __declspec(dllimport)
#  endif
#endif

#ifndef STREAMS_BOOST_REGEX_DECL
#  define STREAMS_BOOST_REGEX_DECL
#endif

#if !defined(STREAMS_BOOST_REGEX_NO_LIB) && !defined(STREAMS_BOOST_REGEX_SOURCE) && !defined(STREAMS_BOOST_ALL_NO_LIB) && defined(__cplusplus)
#  define STREAMS_BOOST_LIB_NAME streams_boost_regex
#  if defined(STREAMS_BOOST_REGEX_DYN_LINK) || defined(STREAMS_BOOST_ALL_DYN_LINK)
#     define STREAMS_BOOST_DYN_LINK
#  endif
#  ifdef STREAMS_BOOST_REGEX_DIAG
#     define STREAMS_BOOST_LIB_DIAGNOSTIC
#  endif
#  include <streams_boost/config/auto_link.hpp>
#endif

/*****************************************************************************
 *
 *  Set up function call type:
 *
 ****************************************************************************/

#if defined(STREAMS_BOOST_MSVC) && (STREAMS_BOOST_MSVC >= 1200) && defined(_MSC_EXTENSIONS)
#if defined(_DEBUG) || defined(__MSVC_RUNTIME_CHECKS) || defined(_MANAGED)
#  define STREAMS_BOOST_REGEX_CALL __cdecl
#else
#  define STREAMS_BOOST_REGEX_CALL __fastcall
#endif
#  define STREAMS_BOOST_REGEX_CCALL __cdecl
#endif

#if defined(__BORLANDC__) && !defined(STREAMS_BOOST_DISABLE_WIN32)
#  define STREAMS_BOOST_REGEX_CALL __fastcall
#  define STREAMS_BOOST_REGEX_CCALL __stdcall
#endif

#ifndef STREAMS_BOOST_REGEX_CALL
#  define STREAMS_BOOST_REGEX_CALL
#endif
#ifndef STREAMS_BOOST_REGEX_CCALL
#define STREAMS_BOOST_REGEX_CCALL
#endif

/*****************************************************************************
 *
 *  Set up localisation model:
 *
 ****************************************************************************/

/* backwards compatibility: */
#ifdef STREAMS_BOOST_RE_LOCALE_C
#  define STREAMS_BOOST_REGEX_USE_C_LOCALE
#endif

#ifdef STREAMS_BOOST_RE_LOCALE_CPP
#  define STREAMS_BOOST_REGEX_USE_CPP_LOCALE
#endif

/* Win32 defaults to native Win32 locale: */
#if defined(_WIN32) && !defined(STREAMS_BOOST_REGEX_USE_WIN32_LOCALE) && !defined(STREAMS_BOOST_REGEX_USE_C_LOCALE) && !defined(STREAMS_BOOST_REGEX_USE_CPP_LOCALE) && !defined(STREAMS_BOOST_REGEX_NO_W32)
#  define STREAMS_BOOST_REGEX_USE_WIN32_LOCALE
#endif
/* otherwise use C++ locale if supported: */
#if !defined(STREAMS_BOOST_REGEX_USE_WIN32_LOCALE) && !defined(STREAMS_BOOST_REGEX_USE_C_LOCALE) && !defined(STREAMS_BOOST_REGEX_USE_CPP_LOCALE) && !defined(STREAMS_BOOST_NO_STD_LOCALE)
#  define STREAMS_BOOST_REGEX_USE_CPP_LOCALE
#endif
/* otherwise use C+ locale: */
#if !defined(STREAMS_BOOST_REGEX_USE_WIN32_LOCALE) && !defined(STREAMS_BOOST_REGEX_USE_C_LOCALE) && !defined(STREAMS_BOOST_REGEX_USE_CPP_LOCALE)
#  define STREAMS_BOOST_REGEX_USE_C_LOCALE
#endif

#ifndef STREAMS_BOOST_REGEX_MAX_STATE_COUNT
#  define STREAMS_BOOST_REGEX_MAX_STATE_COUNT 100000000
#endif


/*****************************************************************************
 *
 *  Error Handling for exception free compilers:
 *
 ****************************************************************************/

#ifdef STREAMS_BOOST_NO_EXCEPTIONS
/*
 * If there are no exceptions then we must report critical-errors
 * the only way we know how; by terminating.
 */
#include <stdexcept>
#include <string>
#include <streams_boost/throw_exception.hpp>

#  define STREAMS_BOOST_REGEX_NOEH_ASSERT(x)\
if(0 == (x))\
{\
   std::string s("Error: critical regex++ failure in: ");\
   s.append(#x);\
   std::runtime_error e(s);\
   streams_boost::throw_exception(e);\
}
#else
/*
 * With exceptions then error handling is taken care of and
 * there is no need for these checks:
 */
#  define STREAMS_BOOST_REGEX_NOEH_ASSERT(x)
#endif


/*****************************************************************************
 *
 *  Stack protection under MS Windows:
 *
 ****************************************************************************/

#if !defined(STREAMS_BOOST_REGEX_NO_W32) && !defined(STREAMS_BOOST_REGEX_V3)
#  if(defined(_WIN32) || defined(_WIN64) || defined(_WINCE)) \
        && !defined(__GNUC__) \
        && !(defined(__BORLANDC__) && (__BORLANDC__ >= 0x600)) \
        && !(defined(__MWERKS__) && (__MWERKS__ <= 0x3003))
#     define STREAMS_BOOST_REGEX_HAS_MS_STACK_GUARD
#  endif
#elif defined(STREAMS_BOOST_REGEX_HAS_MS_STACK_GUARD)
#  undef STREAMS_BOOST_REGEX_HAS_MS_STACK_GUARD
#endif

#if defined(__cplusplus) && defined(STREAMS_BOOST_REGEX_HAS_MS_STACK_GUARD)

namespace streams_boost{
namespace re_detail{

STREAMS_BOOST_REGEX_DECL void STREAMS_BOOST_REGEX_CALL reset_stack_guard_page();

}
}

#endif


/*****************************************************************************
 *
 *  Algorithm selection and configuration:
 *
 ****************************************************************************/

#if !defined(STREAMS_BOOST_REGEX_RECURSIVE) && !defined(STREAMS_BOOST_REGEX_NON_RECURSIVE)
#  if defined(STREAMS_BOOST_REGEX_HAS_MS_STACK_GUARD) && !defined(_STLP_DEBUG) && !defined(__STL_DEBUG) && !(defined(STREAMS_BOOST_MSVC) && (STREAMS_BOOST_MSVC >= 1400))
#     define STREAMS_BOOST_REGEX_RECURSIVE
#  else
#     define STREAMS_BOOST_REGEX_NON_RECURSIVE
#  endif
#endif

#ifdef STREAMS_BOOST_REGEX_NON_RECURSIVE
#  ifdef STREAMS_BOOST_REGEX_RECURSIVE
#     error "Can't set both STREAMS_BOOST_REGEX_RECURSIVE and STREAMS_BOOST_REGEX_NON_RECURSIVE"
#  endif
#  ifndef STREAMS_BOOST_REGEX_BLOCKSIZE
#     define STREAMS_BOOST_REGEX_BLOCKSIZE 4096
#  endif
#  if STREAMS_BOOST_REGEX_BLOCKSIZE < 512
#     error "STREAMS_BOOST_REGEX_BLOCKSIZE must be at least 512"
#  endif
#  ifndef STREAMS_BOOST_REGEX_MAX_BLOCKS
#     define STREAMS_BOOST_REGEX_MAX_BLOCKS 1024
#  endif
#  ifdef STREAMS_BOOST_REGEX_HAS_MS_STACK_GUARD
#     undef STREAMS_BOOST_REGEX_HAS_MS_STACK_GUARD
#  endif
#  ifndef STREAMS_BOOST_REGEX_MAX_CACHE_BLOCKS
#     define STREAMS_BOOST_REGEX_MAX_CACHE_BLOCKS 16
#  endif
#endif


/*****************************************************************************
 *
 *  helper memory allocation functions:
 *
 ****************************************************************************/

#if defined(__cplusplus) && defined(STREAMS_BOOST_REGEX_NON_RECURSIVE)
namespace streams_boost{ namespace re_detail{

STREAMS_BOOST_REGEX_DECL void* STREAMS_BOOST_REGEX_CALL get_mem_block();
STREAMS_BOOST_REGEX_DECL void STREAMS_BOOST_REGEX_CALL put_mem_block(void*);

}} /* namespaces */
#endif

/*****************************************************************************
 *
 *  Diagnostics:
 *
 ****************************************************************************/

#ifdef STREAMS_BOOST_REGEX_CONFIG_INFO
STREAMS_BOOST_REGEX_DECL void STREAMS_BOOST_REGEX_CALL print_regex_library_info();
#endif

#if defined(STREAMS_BOOST_REGEX_DIAG)
#  pragma message ("STREAMS_BOOST_REGEX_DECL" STREAMS_BOOST_STRINGIZE(=STREAMS_BOOST_REGEX_DECL))
#  pragma message ("STREAMS_BOOST_REGEX_CALL" STREAMS_BOOST_STRINGIZE(=STREAMS_BOOST_REGEX_CALL))
#  pragma message ("STREAMS_BOOST_REGEX_CCALL" STREAMS_BOOST_STRINGIZE(=STREAMS_BOOST_REGEX_CCALL))
#ifdef STREAMS_BOOST_REGEX_USE_C_LOCALE
#  pragma message ("Using C locale in regex traits class")
#elif STREAMS_BOOST_REGEX_USE_CPP_LOCALE
#  pragma message ("Using C++ locale in regex traits class")
#else
#  pragma message ("Using Win32 locale in regex traits class")
#endif
#if defined(STREAMS_BOOST_REGEX_DYN_LINK) || defined(STREAMS_BOOST_ALL_DYN_LINK)
#  pragma message ("Dynamic linking enabled")
#endif
#if defined(STREAMS_BOOST_REGEX_NO_LIB) || defined(STREAMS_BOOST_ALL_NO_LIB)
#  pragma message ("Auto-linking disabled")
#endif
#ifdef STREAMS_BOOST_REGEX_NO_EXTERNAL_TEMPLATES
#  pragma message ("Extern templates disabled")
#endif

#endif

#endif




