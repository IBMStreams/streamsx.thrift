// note lack of include guards.  This is intentional

//  config.hpp  ---------------------------------------------//

//  (c) Copyright Robert Ramey 2004
//  Use, modification, and distribution is subject to the Boost Software
//  License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt)

//  See library home page at http://www.streams_boost.org/libs/serialization

//----------------------------------------------------------------------------// 

// This header implements separate compilation features as described in
// http://www.streams_boost.org/more/separate_compilation.html

#include <streams_boost/config.hpp>
#include <streams_boost/detail/workaround.hpp>
#include <streams_boost/preprocessor/facilities/empty.hpp>

// note: this version incorporates the related code into the the 
// the same library as STREAMS_BOOST_ARCHIVE.  This could change some day in the
// future

// if STREAMS_BOOST_SERIALIZATION_DECL is defined undefine it now:
#ifdef STREAMS_BOOST_SERIALIZATION_DECL
    #undef STREAMS_BOOST_SERIALIZATION_DECL
#endif

#ifdef STREAMS_BOOST_HAS_DECLSPEC // defined in config system
// we need to import/export our code only if the user has specifically
// asked for it by defining either STREAMS_BOOST_ALL_DYN_LINK if they want all streams_boost
// libraries to be dynamically linked, or STREAMS_BOOST_SERIALIZATION_DYN_LINK
// if they want just this one to be dynamically liked:
#if defined(STREAMS_BOOST_ALL_DYN_LINK) || defined(STREAMS_BOOST_SERIALIZATION_DYN_LINK)
    #if !defined(STREAMS_BOOST_DYN_LINK)
        #define STREAMS_BOOST_DYN_LINK
    #endif
    // export if this is our own source, otherwise import:
    #if defined(STREAMS_BOOST_SERIALIZATION_SOURCE)
        #if defined(__BORLANDC__)
            #define STREAMS_BOOST_SERIALIZATION_DECL(T) T __export
        #else
            #define STREAMS_BOOST_SERIALIZATION_DECL(T) __declspec(dllexport) T
        #endif
    #else
        #if defined(__BORLANDC__)
            #define STREAMS_BOOST_SERIALIZATION_DECL(T) T __import
        #else
            #define STREAMS_BOOST_SERIALIZATION_DECL(T) __declspec(dllimport) T
        #endif
    #endif // defined(STREAMS_BOOST_SERIALIZATION_SOURCE)
#endif // defined(STREAMS_BOOST_ALL_DYN_LINK) || defined(STREAMS_BOOST_SERIALIZATION_DYN_LINK)
#endif // STREAMS_BOOST_HAS_DECLSPEC

// if STREAMS_BOOST_SERIALIZATION_DECL isn't defined yet define it now:
#ifndef STREAMS_BOOST_SERIALIZATION_DECL
    #define STREAMS_BOOST_SERIALIZATION_DECL(T) T
#endif

//  enable automatic library variant selection  ------------------------------// 

#if !defined(STREAMS_BOOST_ALL_NO_LIB) && !defined(STREAMS_BOOST_SERIALIZATION_NO_LIB) \
&&  !defined(STREAMS_BOOST_ARCHIVE_SOURCE) && !defined(STREAMS_BOOST_WARCHIVE_SOURCE)  \
&&  !defined(STREAMS_BOOST_SERIALIZATION_SOURCE)
    //
    // Set the name of our library, this will get undef'ed by auto_link.hpp
    // once it's done with it:
    //
    #define STREAMS_BOOST_LIB_NAME streams_boost_serialization
    //
    // If we're importing code from a dll, then tell auto_link.hpp about it:
    //
    #if defined(STREAMS_BOOST_ALL_DYN_LINK) || defined(STREAMS_BOOST_SERIALIZATION_DYN_LINK)
    #  define STREAMS_BOOST_DYN_LINK
    #endif
    //
    // And include the header that does the work:
    //
    #include <streams_boost/config/auto_link.hpp>

#endif  
