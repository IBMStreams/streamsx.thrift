#ifndef STREAMS_BOOST_ARCHIVE_DETAIL_DECL_HPP
#define STREAMS_BOOST_ARCHIVE_DETAIL_DECL_HPP 

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif 

/////////1/////////2///////// 3/////////4/////////5/////////6/////////7/////////8
//  decl.hpp
//
//  (c) Copyright Robert Ramey 2004
//  Use, modification, and distribution is subject to the Boost Software
//  License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt)

//  See library home page at http://www.streams_boost.org/libs/serialization

//----------------------------------------------------------------------------// 

// This header implements separate compilation features as described in
// http://www.streams_boost.org/more/separate_compilation.html

#include <streams_boost/config.hpp>
#include <streams_boost/preprocessor/facilities/empty.hpp>

#if defined(STREAMS_BOOST_HAS_DECLSPEC)
    #if (defined(STREAMS_BOOST_ALL_DYN_LINK) || defined(STREAMS_BOOST_SERIALIZATION_DYN_LINK))
        #if defined(STREAMS_BOOST_ARCHIVE_SOURCE)
            #if defined(__BORLANDC__)
            #define STREAMS_BOOST_ARCHIVE_DECL(T) T __export
            #define STREAMS_BOOST_ARCHIVE_OR_WARCHIVE_DECL(T)  T __export
            #else
            #define STREAMS_BOOST_ARCHIVE_DECL(T) __declspec(dllexport) T
            #define STREAMS_BOOST_ARCHIVE_OR_WARCHIVE_DECL(T)  __declspec(dllexport) T
            #endif
        #else
            #if defined(__BORLANDC__)
            #define STREAMS_BOOST_ARCHIVE_DECL(T) T __import
            #else
            #define STREAMS_BOOST_ARCHIVE_DECL(T) __declspec(dllimport) T
            #endif
        #endif
        #if defined(STREAMS_BOOST_WARCHIVE_SOURCE)
            #if defined(__BORLANDC__)
            #define STREAMS_BOOST_WARCHIVE_DECL(T) T __export
            #define STREAMS_BOOST_ARCHIVE_OR_WARCHIVE_DECL(T) T __export
            #else
            #define STREAMS_BOOST_WARCHIVE_DECL(T) __declspec(dllexport) T
            #define STREAMS_BOOST_ARCHIVE_OR_WARCHIVE_DECL(T) __declspec(dllexport) T
            #endif
        #else
            #if defined(__BORLANDC__)
            #define STREAMS_BOOST_WARCHIVE_DECL(T) T __import
            #else
            #define STREAMS_BOOST_WARCHIVE_DECL(T) __declspec(dllimport) T
            #endif
        #endif
        #if !defined(STREAMS_BOOST_WARCHIVE_SOURCE) && !defined(STREAMS_BOOST_ARCHIVE_SOURCE)
            #if defined(__BORLANDC__)
            #define STREAMS_BOOST_ARCHIVE_OR_WARCHIVE_DECL(T) T __import
            #else
            #define STREAMS_BOOST_ARCHIVE_OR_WARCHIVE_DECL(T) __declspec(dllimport) T
            #endif
        #endif
    #endif
#endif // STREAMS_BOOST_HAS_DECLSPEC

#if ! defined(STREAMS_BOOST_ARCHIVE_DECL)
    #define STREAMS_BOOST_ARCHIVE_DECL(T) T
#endif
#if ! defined(STREAMS_BOOST_WARCHIVE_DECL)
    #define STREAMS_BOOST_WARCHIVE_DECL(T) T
#endif
#if ! defined(STREAMS_BOOST_ARCHIVE_OR_WARCHIVE_DECL)
    #define STREAMS_BOOST_ARCHIVE_OR_WARCHIVE_DECL(T) T
#endif

#endif // STREAMS_BOOST_ARCHIVE_DETAIL_DECL_HPP
