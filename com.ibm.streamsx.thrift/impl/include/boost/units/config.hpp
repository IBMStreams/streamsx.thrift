// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_UNITS_CONFIG_HPP
#define STREAMS_BOOST_UNITS_CONFIG_HPP

#include <streams_boost/config.hpp>
#include <streams_boost/version.hpp>

#ifndef STREAMS_BOOST_UNITS_HAS_STREAMS_BOOST_TYPEOF
    #if (STREAMS_BOOST_VERSION >= 103400)
        ///INTERNAL ONLY
        #define STREAMS_BOOST_UNITS_HAS_STREAMS_BOOST_TYPEOF    1
    #else
        ///INTERNAL ONLY
        #define STREAMS_BOOST_UNITS_HAS_STREAMS_BOOST_TYPEOF    0
    #endif
#endif 

#if (STREAMS_BOOST_UNITS_HAS_STREAMS_BOOST_TYPEOF)
    #include <streams_boost/typeof/typeof.hpp> 
    ///INTERNAL ONLY
    #define STREAMS_BOOST_UNITS_HAS_TYPEOF          1
#else    
    #if (__GNUC__ && __cplusplus && __GNUC__ >= 3)
        ///INTERNAL ONLY
        #define STREAMS_BOOST_UNITS_HAS_TYPEOF          1
        ///INTERNAL ONLY
        #define STREAMS_BOOST_UNITS_HAS_GNU_TYPEOF      1
    #elif defined(__MWERKS__)
        ///INTERNAL ONLY
        #define STREAMS_BOOST_UNITS_HAS_TYPEOF          1
        ///INTERNAL ONLY
        #define STREAMS_BOOST_UNITS_HAS_MWERKS_TYPEOF   1
    #else
        ///INTERNAL ONLY
        #define STREAMS_BOOST_UNITS_HAS_TYPEOF          0
    #endif
#endif

// uncomment this to test without typeof support at all
//#undef STREAMS_BOOST_UNITS_HAS_TYPEOF
//#define STREAMS_BOOST_UNITS_HAS_TYPEOF          0

#ifndef STREAMS_BOOST_UNITS_NO_COMPILER_CHECK

    #ifdef STREAMS_BOOST_NO_MEMBER_TEMPLATES
        #error Boost.Units requires member template
    #endif

    #ifdef STREAMS_BOOST_NO_MEMBER_TEMPLATE_KEYWORD
        #error Boost.Units requires member template keyword
    #endif

    #ifdef STREAMS_BOOST_NO_INCLASS_MEMBER_INITIALIZATION
        #error Boost.Units requires in class member initialization
    #endif

    #ifdef STREAMS_BOOST_NO_FUNCTION_TEMPLATE_ORDERING
        #error Boost.Units requires function template partial ordering
    #endif

    #ifdef STREAMS_BOOST_NO_EXPLICIT_FUNCTION_TEMPLATE_ARGUMENTS
        #error Boost.Units requires explicit function template arguments
    #endif

    #ifdef STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
        #error Boost.Units requires partial specialization
    #endif

#endif

#ifdef STREAMS_BOOST_UNITS_REQUIRE_LAYOUT_COMPATIBILITY
    ///INTERNAL ONLY
    #define STREAMS_BOOST_UNITS_CHECK_LAYOUT_COMPATIBILITY(a, b) STREAMS_BOOST_STATIC_ASSERT((sizeof(a) == sizeof(b)))
#else
    ///INTERNAL ONLY
    #define STREAMS_BOOST_UNITS_CHECK_LAYOUT_COMPATIBILITY(a, b) ((void)0)
#endif

#ifdef STREAMS_BOOST_UNITS_DOXYGEN

/// If defined will trigger a static assertion if quantity<Unit, T>
/// is not layout compatible with T
#define STREAMS_BOOST_UNITS_REQUIRE_LAYOUT_COMPATIBILITY

/// If defined will diasable a preprocessor check that the
/// compiler is able to handle the library.
#define STREAMS_BOOST_UNITS_NO_COMPILER_CHECK

/// Enable checking to verify that a homogeneous system
/// is actually capable of representing all the dimensions
/// that it is used with.  Off by default.
#define STREAMS_BOOST_UNITS_CHECK_HOMOGENEOUS_UNITS

#endif

#endif
