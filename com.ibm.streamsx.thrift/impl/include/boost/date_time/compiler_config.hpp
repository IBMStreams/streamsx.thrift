#ifndef DATE_TIME_COMPILER_CONFIG_STREAMS_HPP___
#define DATE_TIME_COMPILER_CONFIG_STREAMS_HPP___

/* Copyright (c) 2002-2004 CrystalClear Software, Inc.
 * Subject to the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE_1_0.txt or http://www.streams_boost.org/LICENSE_1_0.txt)
 * Author: Jeff Garland, Bart Garst
 * $Date: 2008-11-12 14:37:53 -0500 (Wed, 12 Nov 2008) $
 */

#include <cstdlib>
#include <streams_boost/config.hpp>
#include <streams_boost/detail/workaround.hpp>

// With streams_boost release 1.33, date_time will be using a different,
// more flexible, IO system. This new system is not compatible with
// old compilers. The original date_time IO system remains for those
// compilers. They must define this macro to use the legacy IO.
//     (defined(__BORLANDC__) && (__BORLANDC__ <= 0x0581) ) )   &&
 #if(  STREAMS_BOOST_WORKAROUND( __BORLANDC__, STREAMS_BOOST_TESTED_AT(0x581) ) \
    || STREAMS_BOOST_WORKAROUND( __GNUC__, < 3)                         \
    || (STREAMS_BOOST_WORKAROUND( _MSC_VER, <= 1300) )                  \
    )                                                           \
    && !defined(USE_DATE_TIME_PRE_1_33_FACET_IO)
# define USE_DATE_TIME_PRE_1_33_FACET_IO
#endif


// This file performs some local compiler configurations

#include <streams_boost/date_time/locale_config.hpp> //set up locale configurations

//Set up a configuration parameter for platforms that have 
//GetTimeOfDay
#if defined(STREAMS_BOOST_HAS_GETTIMEOFDAY) || defined(STREAMS_BOOST_HAS_FTIME)
#define STREAMS_BOOST_DATE_TIME_HAS_HIGH_PRECISION_CLOCK
#endif

// To Force no default constructors for date & ptime, un-comment following
//#define DATE_TIME_NO_DEFAULT_CONSTRUCTOR

// Include extensions to date_duration - comment out to remove this feature
#define STREAMS_BOOST_DATE_TIME_OPTIONAL_GREGORIAN_TYPES
// these extensions are known to cause problems with gcc295
#if defined(__GNUC__) && (__GNUC__ < 3)
#undef STREAMS_BOOST_DATE_TIME_OPTIONAL_GREGORIAN_TYPES
#endif

#if (defined(STREAMS_BOOST_NO_INCLASS_MEMBER_INITIALIZATION) || STREAMS_BOOST_WORKAROUND( __BORLANDC__,  STREAMS_BOOST_TESTED_AT(0x581) ) )
#define STREAMS_BOOST_DATE_TIME_NO_MEMBER_INIT
#endif

// include these types before we try to re-define them
#include <streams_boost/cstdint.hpp>

//Define INT64_C for compilers that don't have it
#if (!defined(INT64_C))
#define INT64_C(value)  int64_t(value)
#endif


/* Workaround for Borland iterator error. Error was "Cannot convert 'istream *' to 'wistream *' in function istream_iterator<>::istream_iterator() */
#if defined(__BORLANDC__) && defined(STREAMS_BOOST_BCB_WITH_RW_LIB)
#define STREAMS_BOOST_DATE_TIME_NO_WISTREAM_ITERATOR
#endif


// Borland v5.64 does not have the following in std namespace; v5.5.1 does
#if defined(__BORLANDC__) && defined(STREAMS_BOOST_BCB_WITH_STLPORT)
#include <locale>
namespace std {
  using stlport::tolower;
  using stlport::ctype;
  using stlport::use_facet;
}
#endif

// workaround for errors associated with output for date classes 
// modifications and input streaming for time classes. 
// Compilers affected are:
// gcc295, msvc (neither with STLPort), any borland
// 
#if (((defined(__GNUC__) && (__GNUC__ < 3)) || \
      (defined(_MSC_VER) && (_MSC_VER < 1300)) ) && \
      !defined(_STLP_OWN_IOSTREAMS) ) || \
      STREAMS_BOOST_WORKAROUND( __BORLANDC__, STREAMS_BOOST_TESTED_AT(0x581) )
#define STREAMS_BOOST_DATE_TIME_INCLUDE_LIMITED_HEADERS
#endif

// The macro marks up places where compiler complains for missing return statement or
// uninitialized variables after calling to streams_boost::throw_exception.
// STREAMS_BOOST_UNREACHABLE_RETURN doesn't work since even compilers that support
// unreachable statements detection emit such warnings.
#if defined(_MSC_VER)
// Use special MSVC extension to markup unreachable code
#  define STREAMS_BOOST_DATE_TIME_UNREACHABLE_EXPRESSION(x) __assume(false)
#elif !defined(STREAMS_BOOST_NO_UNREACHABLE_RETURN_DETECTION)
// Call to a non-returning function should suppress the warning
#  if defined(STREAMS_BOOST_NO_STDC_NAMESPACE)
namespace std {
    using ::abort;
}
#  endif // defined(STREAMS_BOOST_NO_STDC_NAMESPACE)
#  define STREAMS_BOOST_DATE_TIME_UNREACHABLE_EXPRESSION(x) std::abort()
#else
// For other poor compilers the specified expression is compiled. Usually, this would be a return statement.
#  define STREAMS_BOOST_DATE_TIME_UNREACHABLE_EXPRESSION(x) x
#endif

/* The following handles the definition of the necessary macros
 * for dll building on Win32 platforms.
 * 
 * For code that will be placed in the date_time .dll, 
 * it must be properly prefixed with STREAMS_BOOST_DATE_TIME_DECL.
 * The corresponding .cpp file must have STREAMS_BOOST_DATE_TIME_SOURCE
 * defined before including its header. For examples see:
 * greg_month.hpp & greg_month.cpp
 * 
 */

#ifdef STREAMS_BOOST_HAS_DECLSPEC // defined in config system
   // we need to import/export our code only if the user has specifically
   // asked for it by defining either STREAMS_BOOST_ALL_DYN_LINK if they want all streams_boost
   // libraries to be dynamically linked, or STREAMS_BOOST_DATE_TIME_DYN_LINK
   // if they want just this one to be dynamically liked:
#  if defined(STREAMS_BOOST_ALL_DYN_LINK) || defined(STREAMS_BOOST_DATE_TIME_DYN_LINK)
      // export if this is our own source, otherwise import:
#     ifdef STREAMS_BOOST_DATE_TIME_SOURCE
#       define STREAMS_BOOST_DATE_TIME_DECL __declspec(dllexport)
#     else
#       define STREAMS_BOOST_DATE_TIME_DECL __declspec(dllimport)
#     endif  // STREAMS_BOOST_DATE_TIME_SOURCE
#  endif  // DYN_LINK
#endif  // STREAMS_BOOST_HAS_DECLSPEC
//
// if STREAMS_BOOST_WHATEVER_DECL isn't defined yet define it now:
#ifndef STREAMS_BOOST_DATE_TIME_DECL
#  define STREAMS_BOOST_DATE_TIME_DECL
#endif

//
// Automatically link to the correct build variant where possible. 
// 
#if !defined(STREAMS_BOOST_ALL_NO_LIB) && !defined(STREAMS_BOOST_DATE_TIME_NO_LIB) && !defined(STREAMS_BOOST_DATE_TIME_SOURCE)
//
// Set the name of our library, this will get undef'ed by auto_link.hpp
// once it's done with it:
//
#define STREAMS_BOOST_LIB_NAME streams_boost_date_time
//
// If we're importing code from a dll, then tell auto_link.hpp about it:
//
#if defined(STREAMS_BOOST_ALL_DYN_LINK) || defined(STREAMS_BOOST_DATE_TIME_DYN_LINK)
#  define STREAMS_BOOST_DYN_LINK
#endif
//
// And include the header that does the work:
//
#include <streams_boost/config/auto_link.hpp>
#endif  // auto-linking disabled

#if defined(STREAMS_BOOST_HAS_THREADS) 
#  if defined(_MSC_VER) || defined(__MWERKS__) || defined(__MINGW32__) ||  defined(__BORLANDC__)
     //no reentrant posix functions (eg: localtime_r)
#  elif (!defined(__hpux) || (defined(__hpux) && defined(_REENTRANT)))
#   define STREAMS_BOOST_DATE_TIME_HAS_REENTRANT_STD_FUNCTIONS
#  endif
#endif


#endif
