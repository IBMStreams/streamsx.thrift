//  (C) Copyright David Abrahams 2000.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
//  The author gratefully acknowleges the support of Dragon Systems, Inc., in
//  producing this work.

//  Revision History:
//  04 Mar 01  Some fixes so it will compile with Intel C++ (Dave Abrahams)

#ifndef CONFIG_DWA052200_H_
# define CONFIG_DWA052200_H_

# include <streams_boost/config.hpp>
# include <streams_boost/detail/workaround.hpp>

# ifdef STREAMS_BOOST_NO_OPERATORS_IN_NAMESPACE
   // A gcc bug forces some symbols into the global namespace
#  define STREAMS_BOOST_PYTHON_BEGIN_CONVERSION_NAMESPACE
#  define STREAMS_BOOST_PYTHON_END_CONVERSION_NAMESPACE
#  define STREAMS_BOOST_PYTHON_CONVERSION
#  define STREAMS_BOOST_PYTHON_IMPORT_CONVERSION(x) using ::x
# else
#  define STREAMS_BOOST_PYTHON_BEGIN_CONVERSION_NAMESPACE namespace streams_boost { namespace python {
#  define STREAMS_BOOST_PYTHON_END_CONVERSION_NAMESPACE }} // namespace streams_boost::python
#  define STREAMS_BOOST_PYTHON_CONVERSION streams_boost::python
#  define STREAMS_BOOST_PYTHON_IMPORT_CONVERSION(x) void never_defined() // so we can follow the macro with a ';'
# endif

# if defined(STREAMS_BOOST_MSVC)
#  if _MSC_VER < 1300
#   define STREAMS_BOOST_MSVC6_OR_EARLIER 1
#  endif

#  pragma warning (disable : 4786) // disable truncated debug symbols
#  pragma warning (disable : 4251) // disable exported dll function
#  pragma warning (disable : 4800) //'int' : forcing value to bool 'true' or 'false'
#  pragma warning (disable : 4275) // non dll-interface class

# elif defined(__ICL) && __ICL < 600 // Intel C++ 5

#  pragma warning(disable: 985) // identifier was truncated in debug information

# endif

// The STLport puts all of the standard 'C' library names in std (as far as the
// user is concerned), but without it you need a fix if you're using MSVC or
// Intel C++
# if defined(STREAMS_BOOST_NO_STDC_NAMESPACE)
#  define STREAMS_BOOST_CSTD_
# else
#  define STREAMS_BOOST_CSTD_ std
# endif

/*****************************************************************************
 *
 *  Set up dll import/export options:
 *
 ****************************************************************************/

// backwards compatibility:
#ifdef STREAMS_BOOST_PYTHON_STATIC_LIB
#  define STREAMS_BOOST_PYTHON_STATIC_LINK
# elif !defined(STREAMS_BOOST_PYTHON_DYNAMIC_LIB)
#  define STREAMS_BOOST_PYTHON_DYNAMIC_LIB
#endif

#if defined(STREAMS_BOOST_PYTHON_DYNAMIC_LIB)

#  if !defined(_WIN32) && !defined(__CYGWIN__)                                  \
    && !defined(STREAMS_BOOST_PYTHON_USE_GCC_SYMBOL_VISIBILITY)                         \
    && STREAMS_BOOST_WORKAROUND(__GNUC__, >= 3) && (__GNUC_MINOR__ >=5 || __GNUC__ > 3)
#    define STREAMS_BOOST_PYTHON_USE_GCC_SYMBOL_VISIBILITY 1
#  endif 

#  if STREAMS_BOOST_PYTHON_USE_GCC_SYMBOL_VISIBILITY
#     if defined(STREAMS_BOOST_PYTHON_SOURCE)
#        define STREAMS_BOOST_PYTHON_DECL __attribute__ ((visibility("default")))
#        define STREAMS_BOOST_PYTHON_BUILD_DLL
#     else
#        define STREAMS_BOOST_PYTHON_DECL
#     endif
#     define STREAMS_BOOST_PYTHON_DECL_FORWARD
#     define STREAMS_BOOST_PYTHON_DECL_EXCEPTION __attribute__ ((visibility("default")))
#  elif (defined(_WIN32) || defined(__CYGWIN__))
#     if defined(STREAMS_BOOST_PYTHON_SOURCE)
#        define STREAMS_BOOST_PYTHON_DECL __declspec(dllexport)
#        define STREAMS_BOOST_PYTHON_BUILD_DLL
#     else
#        define STREAMS_BOOST_PYTHON_DECL __declspec(dllimport)
#     endif
#  endif

#endif

#ifndef STREAMS_BOOST_PYTHON_DECL
#  define STREAMS_BOOST_PYTHON_DECL
#endif

#ifndef STREAMS_BOOST_PYTHON_DECL_FORWARD
#  define STREAMS_BOOST_PYTHON_DECL_FORWARD STREAMS_BOOST_PYTHON_DECL
#endif

#ifndef STREAMS_BOOST_PYTHON_DECL_EXCEPTION
#  define STREAMS_BOOST_PYTHON_DECL_EXCEPTION STREAMS_BOOST_PYTHON_DECL
#endif

#if STREAMS_BOOST_WORKAROUND(__DECCXX_VER, STREAMS_BOOST_TESTED_AT(60590042))
// Replace broken Tru64/cxx offsetof macro
# define STREAMS_BOOST_PYTHON_OFFSETOF(s_name, s_member) \
        ((size_t)__INTADDR__(&(((s_name *)0)->s_member)))
#else
# define STREAMS_BOOST_PYTHON_OFFSETOF offsetof
#endif

//  enable automatic library variant selection  ------------------------------// 

#if !defined(STREAMS_BOOST_PYTHON_SOURCE) && !defined(STREAMS_BOOST_ALL_NO_LIB) && !defined(STREAMS_BOOST_PYTHON_NO_LIB)
//
// Set the name of our library, this will get undef'ed by auto_link.hpp
// once it's done with it:
//
#define STREAMS_BOOST_LIB_NAME streams_boost_python
//
// If we're importing code from a dll, then tell auto_link.hpp about it:
//
#ifdef STREAMS_BOOST_PYTHON_DYNAMIC_LIB
#  define STREAMS_BOOST_DYN_LINK
#endif
//
// And include the header that does the work:
//
#include <streams_boost/config/auto_link.hpp>
#endif  // auto-linking disabled

#ifndef STREAMS_BOOST_PYTHON_NO_PY_SIGNATURES
#define STREAMS_BOOST_PYTHON_SUPPORTS_PY_SIGNATURES // enables smooth transition
#endif

#endif // CONFIG_DWA052200_H_
