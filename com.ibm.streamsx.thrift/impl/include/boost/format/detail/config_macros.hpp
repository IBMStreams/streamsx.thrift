// -*- C++ -*-
// ----------------------------------------------------------------------------
// config_macros.hpp : configuration macros for the format library
// only STREAMS_BOOST_IO_STD is absolutely needed (it should be 'std::' in general)
// others are compiler-specific workaround macros used in #ifdef switches
// ----------------------------------------------------------------------------

//  Copyright Samuel Krempp 2003. Use, modification, and distribution are
//  subject to the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

// see http://www.streams_boost.org/libs/format for library home page


// ----------------------------------------------------------------------------

#ifndef STREAMS_BOOST_FORMAT_CONFIG_MACROS_HPP
#define STREAMS_BOOST_FORMAT_CONFIG_MACROS_HPP

#include <streams_boost/config.hpp>
#include <streams_boost/detail/workaround.hpp>

// make sure our local macros wont override something :
#if defined(STREAMS_BOOST_NO_LOCALE_ISDIGIT) || defined(STREAMS_BOOST_OVERLOAD_FOR_NON_CONST) \
  || defined(STREAMS_BOOST_IO_STD) || defined( STREAMS_BOOST_IO_NEEDS_USING_DECLARATION ) \
    || defined(STREAMS_BOOST_NO_TEMPLATE_STD_STREAM) \
    || defined(STREAMS_BOOST_FORMAT_STREAMBUF_DEFINED) || defined(STREAMS_BOOST_FORMAT_OSTREAM_DEFINED)
#error "streams_boost::format uses a local macro that is already defined."
#endif

// specific workarounds. each header can define BOOS_IO_STD if it 
// needs. (e.g. because of IO_NEEDS_USING_DECLARATION)
#include <streams_boost/format/detail/workarounds_gcc-2_95.hpp>
#include <streams_boost/format/detail/workarounds_stlport.hpp>

#ifndef STREAMS_BOOST_IO_STD
#  define STREAMS_BOOST_IO_STD ::std::
#endif

#if defined(STREAMS_BOOST_NO_STD_LOCALE) || \
 ( STREAMS_BOOST_WORKAROUND(__BORLANDC__, <= 0x564) \
   || STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT( 0x570 ) )  )
// some future __BORLANDC__ >0x564  versions might not need this
// 0x570 is Borland's kylix branch
#define STREAMS_BOOST_NO_LOCALE_ISDIGIT
#endif

#if  STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x570) ) || STREAMS_BOOST_WORKAROUND( STREAMS_BOOST_MSVC, STREAMS_BOOST_TESTED_AT(1300))
#define STREAMS_BOOST_NO_OVERLOAD_FOR_NON_CONST
#endif

// gcc-2.95's native stringstream is not usable
#if STREAMS_BOOST_WORKAROUND(__GNUC__, < 3) && !defined(__SGI_STL_PORT) && !defined(_STLPORT_VERSION)
#define STREAMS_BOOST_FORMAT_IGNORE_STRINGSTREAM  
#endif


// **** Workaround for io streams, stlport and msvc.
#ifdef STREAMS_BOOST_IO_NEEDS_USING_DECLARATION
namespace streams_boost {
  using std::char_traits;
  using std::basic_ostream;
  namespace io {
    using std::basic_ostream;
    namespace detail {
      using std::basic_ios;
      using std::basic_ostream;
    }
  }
#if ! defined(STREAMS_BOOST_NO_STD_LOCALE)
    using std::locale;
    namespace io {
        using std::locale;
        namespace detail {
            using std::locale;
        }
    }
#endif // locale
}
  // -end N.S. streams_boost
#endif // needs_using_declaration


// ***  hide std::locale if it doesnt exist. 
// this typedef is either std::locale or int, avoids placing ifdefs everywhere
namespace streams_boost { namespace io { namespace detail {
#if ! defined(STREAMS_BOOST_NO_STD_LOCALE)
    typedef STREAMS_BOOST_IO_STD locale locale_t;
#else 
    typedef int          locale_t;
#endif
} } }


// ----------------------------------------------------------------------------

#endif // STREAMS_BOOST_FORMAT_MACROS_DEFAULT_HPP
